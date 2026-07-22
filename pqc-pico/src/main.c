#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "api.h"
#include "benchmark.h"



static uint8_t public_key[
    PQCLEAN_MLKEM1024_CLEAN_CRYPTO_PUBLICKEYBYTES
];


static uint8_t secret_key[
    PQCLEAN_MLKEM1024_CLEAN_CRYPTO_SECRETKEYBYTES
];


static uint8_t ciphertext[
    PQCLEAN_MLKEM1024_CLEAN_CRYPTO_CIPHERTEXTBYTES
];


static uint8_t shared_secret_enc[
    PQCLEAN_MLKEM1024_CLEAN_CRYPTO_BYTES
];


static uint8_t shared_secret_dec[
    PQCLEAN_MLKEM1024_CLEAN_CRYPTO_BYTES
];





static void print_banner(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("            ML-KEM-1024 Functional Validation\n");
    printf("         Raspberry Pi Pico 2 W (RP2350)\n");
    printf("         PQClean Clean Implementation\n");
    printf("============================================================\n\n");

}





int main(void)
{

    stdio_init_all();


    while(!stdio_usb_connected())
    {
        sleep_ms(100);
    }


    sleep_ms(1000);



    print_banner();



    printf("[1/4] Generating ML-KEM-1024 Key Pair...\n\n");


    if(PQCLEAN_MLKEM1024_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key) != 0)
    {

        printf("ERROR: Key generation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Key pair generated successfully.\n\n");






    printf("[2/4] Performing Encapsulation...\n\n");


    if(PQCLEAN_MLKEM1024_CLEAN_crypto_kem_enc(
            ciphertext,
            shared_secret_enc,
            public_key) != 0)
    {

        printf("ERROR: Encapsulation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Encapsulation completed successfully.\n\n");








    printf("[3/4] Performing Decapsulation...\n\n");


    if(PQCLEAN_MLKEM1024_CLEAN_crypto_kem_dec(
            shared_secret_dec,
            ciphertext,
            secret_key) != 0)
    {

        printf("ERROR: Decapsulation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Decapsulation completed successfully.\n\n");









    printf("[4/4] Verifying Shared Secrets...\n\n");



    printf("=============================================\n");
    printf("           VERIFICATION RESULT\n");
    printf("=============================================\n");



    if(memcmp(
        shared_secret_enc,
        shared_secret_dec,
        PQCLEAN_MLKEM1024_CLEAN_CRYPTO_BYTES) == 0)
    {

        printf("PASS: Shared secrets are identical.\n");
        printf("ML-KEM-1024 functional validation successful.\n");

    }

    else
    {

        printf("FAIL: Shared secrets do not match.\n");
        printf("ML-KEM-1024 functional validation failed.\n");

    }


    printf("=============================================\n\n");






    /*
        Print hardware information
        and run benchmark
    */


    print_processor_info();


    run_benchmark();





    while(1)
    {

        tight_loop_contents();

    }


    return 0;

}
