#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"

#include "benchmark.h"
#include "api.h"


#define ITERATIONS 10000
#define WARMUP 100


static uint8_t public_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_PUBLICKEYBYTES];

static uint8_t secret_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_SECRETKEYBYTES];

static uint8_t ciphertext[PQCLEAN_MLKEM512_CLEAN_CRYPTO_CIPHERTEXTBYTES];

static uint8_t shared_secret1[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];

static uint8_t shared_secret2[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];


typedef struct
{
    uint64_t total_time;
    uint64_t total_cycles;

    double sum_squared_diff;

    uint32_t min_time;
    uint32_t max_time;

} benchmark_result_t;



static uint32_t get_time_us()
{
    return time_us_32();
}



static uint64_t calculate_cycles(uint32_t time_us)
{
    uint64_t clock_mhz;

    clock_mhz = clock_get_hz(clk_sys) / 1000000;

    return ((uint64_t)time_us * clock_mhz);
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
    printf("XLEN         : %d-bit\n", __riscv_xlen);
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


#else

    printf("Architecture : ARM\n");

#endif



    printf("CPU Clock    : %lu MHz\n",
           clock_get_hz(clk_sys) / 1000000);



    printf("Compiler     : %s\n",
           __VERSION__);



    printf("============================================================\n\n");

}





static double calculate_stddev(benchmark_result_t result)
{

    double variance =
        result.sum_squared_diff / ITERATIONS;


    return sqrt(variance);

}






static void print_result(
        const char *name,
        benchmark_result_t result)
{

    uint64_t mean_time =
        result.total_time / ITERATIONS;


    uint64_t mean_cycles =
        result.total_cycles / ITERATIONS;


    double stddev =
        calculate_stddev(result);



    printf("| %-14s | %11llu | %11.3f | %11llu | %11lu | %11lu | %10.2f |\n",
           name,
           mean_time,
           mean_time / 1000.0,
           mean_cycles,
           result.min_time,
           result.max_time,
           stddev);

}







static void benchmark_operation(
        const char *name,
        int operation)
{

    benchmark_result_t result = {0};


    result.min_time = 0xffffffff;



    for(int i = 0; i < ITERATIONS; i++)
    {

        uint32_t start_time =
            get_time_us();



        if(operation == 0)
        {

            PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
                public_key,
                secret_key);

        }


        else if(operation == 1)
        {

            PQCLEAN_MLKEM512_CLEAN_crypto_kem_enc(
                ciphertext,
                shared_secret1,
                public_key);

        }


        else if(operation == 2)
        {

            PQCLEAN_MLKEM512_CLEAN_crypto_kem_dec(
                shared_secret2,
                ciphertext,
                secret_key);

        }



        uint32_t elapsed =
            get_time_us() - start_time;



        uint64_t cycles =
            calculate_cycles(elapsed);



        result.total_time += elapsed;

        result.total_cycles += cycles;



        double diff =
            elapsed -
            ((double)result.total_time / (i + 1));


        result.sum_squared_diff +=
            diff * diff;



        if(elapsed < result.min_time)
            result.min_time = elapsed;



        if(elapsed > result.max_time)
            result.max_time = elapsed;

    }



    print_result(name,result);

}









static void benchmark_total_kem()
{

    benchmark_result_t result = {0};


    result.min_time = 0xffffffff;



    for(int i = 0; i < ITERATIONS; i++)
    {

        uint32_t start_time =
            get_time_us();



        PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key);



        PQCLEAN_MLKEM512_CLEAN_crypto_kem_enc(
            ciphertext,
            shared_secret1,
            public_key);



        PQCLEAN_MLKEM512_CLEAN_crypto_kem_dec(
            shared_secret2,
            ciphertext,
            secret_key);




        uint32_t elapsed =
            get_time_us() - start_time;



        uint64_t cycles =
            calculate_cycles(elapsed);



        result.total_time += elapsed;

        result.total_cycles += cycles;



        double diff =
            elapsed -
            ((double)result.total_time / (i + 1));


        result.sum_squared_diff +=
            diff * diff;



        if(elapsed < result.min_time)
            result.min_time = elapsed;



        if(elapsed > result.max_time)
            result.max_time = elapsed;

    }



    print_result("Total KEM",result);

}







void run_benchmark(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("              ML-KEM-512 Benchmark Results\n");
    printf("============================================================\n\n");



    printf("Warmup iterations: %d\n",WARMUP);



    for(int i=0;i<WARMUP;i++)
    {

        PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key);

    }



    printf("Warmup complete\n\n");



    printf("Running benchmark: %d iterations\n\n",
           ITERATIONS);





    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");

    printf("| Operation      | Mean (us)   | Mean (ms)   | Cycles      | Min (us)    | Max (us)    | Std Dev    |\n");

    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");



    benchmark_operation(
        "Key Generation",
        0);



    benchmark_operation(
        "Encapsulation",
        1);



    benchmark_operation(
        "Decapsulation",
        2);



    benchmark_total_kem();



    printf("+----------------+-------------+-------------+-------------+-------------+-------------+------------+\n");



    printf("\nBenchmark completed.\n");

}
