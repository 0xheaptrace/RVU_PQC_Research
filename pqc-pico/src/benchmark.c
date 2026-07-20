#include "benchmark.h"

#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

#include "api.h"


#define WARMUP_ITERATIONS 10
#define BENCHMARK_ITERATIONS 1000

#define CPU_FREQ_MHZ 150


static uint8_t public_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_PUBLICKEYBYTES];

static uint8_t secret_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_SECRETKEYBYTES];

static uint8_t ciphertext[PQCLEAN_MLKEM512_CLEAN_CRYPTO_CIPHERTEXTBYTES];

static uint8_t shared_secret_enc[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];

static uint8_t shared_secret_dec[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];


static uint64_t keygen_times[BENCHMARK_ITERATIONS];

static uint64_t enc_times[BENCHMARK_ITERATIONS];

static uint64_t dec_times[BENCHMARK_ITERATIONS];

static uint64_t total_times[BENCHMARK_ITERATIONS];



static uint64_t convert_cycles(uint64_t microseconds)
{
    return microseconds * CPU_FREQ_MHZ;
}



static void calculate_statistics(uint64_t *data,
                                 uint64_t *mean,
                                 uint64_t *minimum,
                                 uint64_t *maximum)
{
    uint64_t sum = 0;

    *minimum = data[0];
    *maximum = data[0];


    for(int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {
        if(data[i] < *minimum)
            *minimum = data[i];

        if(data[i] > *maximum)
            *maximum = data[i];

        sum += data[i];
    }


    *mean = sum / BENCHMARK_ITERATIONS;
}



static void print_benchmark_table(void)
{
    uint64_t key_mean;
    uint64_t key_min;
    uint64_t key_max;

    uint64_t enc_mean;
    uint64_t enc_min;
    uint64_t enc_max;

    uint64_t dec_mean;
    uint64_t dec_min;
    uint64_t dec_max;

    uint64_t total_mean;
    uint64_t total_min;
    uint64_t total_max;



    calculate_statistics(
        keygen_times,
        &key_mean,
        &key_min,
        &key_max
    );


    calculate_statistics(
        enc_times,
        &enc_mean,
        &enc_min,
        &enc_max
    );


    calculate_statistics(
        dec_times,
        &dec_mean,
        &dec_min,
        &dec_max
    );


    calculate_statistics(
        total_times,
        &total_mean,
        &total_min,
        &total_max
    );



    printf("\n");
    printf("============================================================\n");
    printf("              ML-KEM-512 Benchmark Results\n");
    printf("              Raspberry Pi Pico 2 W (RP2350)\n");
    printf("              ARM Cortex-M33 @ 150 MHz\n");
    printf("============================================================\n\n");


    printf("Iterations: %d\n\n", BENCHMARK_ITERATIONS);



    printf("+----------------+-------------+-------------+-------------+-------------+-------------+\n");
    printf("| Operation      | Mean (us)   | Mean (ms)   | Cycles      | Min (us)    | Max (us)    |\n");
    printf("+----------------+-------------+-------------+-------------+-------------+-------------+\n");


    printf("| Key Generation | %-11llu | %-11.3f | %-11llu | %-11llu | %-11llu |\n",
           key_mean,
           key_mean / 1000.0,
           convert_cycles(key_mean),
           key_min,
           key_max);


    printf("| Encapsulation  | %-11llu | %-11.3f | %-11llu | %-11llu | %-11llu |\n",
           enc_mean,
           enc_mean / 1000.0,
           convert_cycles(enc_mean),
           enc_min,
           enc_max);


    printf("| Decapsulation  | %-11llu | %-11.3f | %-11llu | %-11llu | %-11llu |\n",
           dec_mean,
           dec_mean / 1000.0,
           convert_cycles(dec_mean),
           dec_min,
           dec_max);


    printf("| Total KEM      | %-11llu | %-11.3f | %-11llu | %-11llu | %-11llu |\n",
           total_mean,
           total_mean / 1000.0,
           convert_cycles(total_mean),
           total_min,
           total_max);


    printf("+----------------+-------------+-------------+-------------+-------------+-------------+\n");

}



void run_mlkem512_benchmark(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("              ML-KEM-512 Benchmark\n");
    printf("        Raspberry Pi Pico 2 W (RP2350)\n");
    printf("============================================================\n");



    printf("\nWarmup iterations: %d\n", WARMUP_ITERATIONS);



    for(int i = 0; i < WARMUP_ITERATIONS; i++)
    {

        PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key
        );


        PQCLEAN_MLKEM512_CLEAN_crypto_kem_enc(
            ciphertext,
            shared_secret_enc,
            public_key
        );


        PQCLEAN_MLKEM512_CLEAN_crypto_kem_dec(
            shared_secret_dec,
            ciphertext,
            secret_key
        );

    }



    printf("Warmup complete\n");


    printf("\nRunning benchmark: %d iterations\n",
           BENCHMARK_ITERATIONS);



    for(int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {

        uint64_t total_start = time_us_64();


        uint64_t start = time_us_64();


        PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key
        );


        keygen_times[i] = time_us_64() - start;



        start = time_us_64();


        PQCLEAN_MLKEM512_CLEAN_crypto_kem_enc(
            ciphertext,
            shared_secret_enc,
            public_key
        );


        enc_times[i] = time_us_64() - start;



        start = time_us_64();


        PQCLEAN_MLKEM512_CLEAN_crypto_kem_dec(
            shared_secret_dec,
            ciphertext,
            secret_key
        );


        dec_times[i] = time_us_64() - start;



        total_times[i] = time_us_64() - total_start;



        if(memcmp(shared_secret_enc,
                  shared_secret_dec,
                  PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES) != 0)
        {

            printf("KEM verification failed at iteration %d\n", i);

            return;
        }

    }



    print_benchmark_table();


    printf("\nBenchmark completed.\n");

}
