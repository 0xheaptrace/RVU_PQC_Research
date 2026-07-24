#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#include "pico/stdlib.h"

#include "benchmark.h"
#include "api.h"


#define ITERATIONS 100
#define WARMUP 3



static uint8_t public_key[
    PQCLEAN_FALCON512_CLEAN_CRYPTO_PUBLICKEYBYTES
];


static uint8_t secret_key[
    PQCLEAN_FALCON512_CLEAN_CRYPTO_SECRETKEYBYTES
];


static uint8_t signature[
    PQCLEAN_FALCON512_CLEAN_CRYPTO_BYTES
];


static uint8_t message[32] =
{
    0x01,0x02,0x03,0x04,
    0x05,0x06,0x07,0x08,
    0x09,0x0A,0x0B,0x0C,
    0x0D,0x0E,0x0F,0x10,
    0x11,0x12,0x13,0x14,
    0x15,0x16,0x17,0x18,
    0x19,0x1A,0x1B,0x1C,
    0x1D,0x1E,0x1F,0x20
};



typedef struct
{
    uint64_t total_time;

    uint64_t total_cycles;

    uint32_t min_time;

    uint32_t max_time;

    double variance;

} benchmark_result_t;




/*
 * Enable RISC-V Hardware Cycle Counter
 */

static inline void enable_cycle_counter()
{

    uint32_t value = 0;


    asm volatile(
        "csrw mcountinhibit, %0"
        :
        : "r"(value)
    );

}




/*
 * Read 64-bit RISC-V mcycle counter
 */

static inline uint64_t read_cycle_counter()
{

    uint32_t hi1;
    uint32_t hi2;
    uint32_t lo;


    do
    {

        asm volatile(
            "csrr %0, mcycleh"
            : "=r"(hi1)
        );


        asm volatile(
            "csrr %0, mcycle"
            : "=r"(lo)
        );


        asm volatile(
            "csrr %0, mcycleh"
            : "=r"(hi2)
        );


    }while(hi1 != hi2);



    return ((uint64_t)hi1 << 32) | lo;

}





void print_processor_info(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("                 Processor Information\n");
    printf("============================================================\n");


#if defined(__riscv)

    printf("Architecture : RISC-V\n");


#ifdef __riscv_xlen
    printf("XLEN         : %d-bit\n",
           __riscv_xlen);
#endif


#ifdef __riscv_mul
    printf("Extension    : M (Multiply)\n");
#endif


#ifdef __riscv_atomic
    printf("Extension    : A (Atomic)\n");
#endif


#ifdef __riscv_compressed
    printf("Extension    : C (Compressed)\n");
#endif


#ifdef __riscv_zicsr
    printf("Extension    : Zicsr\n");
#endif


#ifdef __riscv_zifencei
    printf("Extension    : Zifencei\n");
#endif


    printf("Core         : Hazard3 (RP2350)\n");


#else

    printf("Architecture : ARM\n");

#endif


    printf("Compiler     : %s\n",
           __VERSION__);


    printf("============================================================\n\n");

}





static double calculate_stddev(
        benchmark_result_t *result)
{

    return sqrt(
        result->variance / ITERATIONS
    );

}





static void print_result(
        const char *name,
        benchmark_result_t *result)
{

    uint64_t mean_time =
        result->total_time / ITERATIONS;


    uint64_t mean_cycles =
        result->total_cycles / ITERATIONS;



    printf(
    "| %-14s | %11" PRIu64 " | %11.3f | %11" PRIu64 " | %11u | %11u | %10.2f |\n",

    name,

    mean_time,

    mean_time / 1000.0,

    mean_cycles,

    result->min_time,

    result->max_time,

    calculate_stddev(result)

    );

}





static void benchmark_operation(
        const char *name,
        int operation)
{

    benchmark_result_t result = {0};


    result.min_time = 0xffffffff;


    double mean = 0;



    for(int i = 0; i < ITERATIONS; i++)
    {

        uint32_t start_time =
            time_us_32();


        uint64_t start_cycles =
            read_cycle_counter();



        if(operation == 0)
        {

            PQCLEAN_FALCON512_CLEAN_crypto_sign_keypair(
                public_key,
                secret_key
            );

        }


        else if(operation == 1)
        {

            size_t siglen;


            PQCLEAN_FALCON512_CLEAN_crypto_sign_signature(
                signature,
                &siglen,
                message,
                sizeof(message),
                secret_key
            );

        }


        else
        {

            size_t siglen =
                PQCLEAN_FALCON512_CLEAN_CRYPTO_BYTES;


            PQCLEAN_FALCON512_CLEAN_crypto_sign_verify(
                signature,
                siglen,
                message,
                sizeof(message),
                public_key
            );

        }



        uint64_t end_cycles =
            read_cycle_counter();



        uint32_t elapsed_time =
            time_us_32() - start_time;



        uint64_t elapsed_cycles =
            end_cycles - start_cycles;



        result.total_time += elapsed_time;

        result.total_cycles += elapsed_cycles;



        if(elapsed_time < result.min_time)
            result.min_time = elapsed_time;


        if(elapsed_time > result.max_time)
            result.max_time = elapsed_time;




        double delta =
            elapsed_time - mean;


        mean += delta/(i+1);


        result.variance +=
            delta*(elapsed_time-mean);


    }



    print_result(
        name,
        &result
    );

}





static void benchmark_total_sign()
{

    benchmark_result_t result={0};


    result.min_time = 0xffffffff;


    double mean = 0;



    for(int i = 0; i < ITERATIONS; i++)
    {

        uint32_t start_time =
            time_us_32();


        uint64_t start_cycles =
            read_cycle_counter();



        PQCLEAN_FALCON512_CLEAN_crypto_sign_keypair(
            public_key,
            secret_key
        );


        size_t siglen;


        PQCLEAN_FALCON512_CLEAN_crypto_sign_signature(
            signature,
            &siglen,
            message,
            sizeof(message),
            secret_key
        );


        PQCLEAN_FALCON512_CLEAN_crypto_sign_verify(
            signature,
            siglen,
            message,
            sizeof(message),
            public_key
        );



        uint64_t end_cycles =
            read_cycle_counter();



        uint32_t elapsed_time =
            time_us_32() - start_time;



        uint64_t elapsed_cycles =
            end_cycles - start_cycles;



        result.total_time += elapsed_time;

        result.total_cycles += elapsed_cycles;



        if(elapsed_time < result.min_time)
            result.min_time = elapsed_time;


        if(elapsed_time > result.max_time)
            result.max_time = elapsed_time;




        double delta =
            elapsed_time - mean;


        mean += delta/(i+1);


        result.variance +=
            delta*(elapsed_time-mean);


    }



    print_result(
        "Total Sign",
        &result
    );

}





void run_benchmark(void)
{

    enable_cycle_counter();



    printf("\n");
    printf("============================================================\n");
    printf("              Falcon-512 Benchmark Results\n");
    printf("============================================================\n\n");



    printf("Warmup iterations: %d\n",
           WARMUP);



    for(int i=0;i<WARMUP;i++)
    {

        PQCLEAN_FALCON512_CLEAN_crypto_sign_keypair(
            public_key,
            secret_key
        );

    }



    printf("Warmup complete\n\n");



    printf("Running benchmark: %d iterations\n\n",
           ITERATIONS);




    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");

    printf("| Operation      | Mean (us)   | Mean (ms)   | Cycles      | Min (us)    | Max (us)    | Std Dev    |\n");

    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");



    benchmark_operation(
        "Key Generation",
        0
    );


    benchmark_operation(
        "Signing",
        1
    );


    benchmark_operation(
        "Verification",
        2
    );


    benchmark_total_sign();



    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");


    printf("\nBenchmark completed.\n");

}
