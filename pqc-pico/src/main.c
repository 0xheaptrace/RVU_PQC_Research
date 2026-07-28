#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "api.h"
#include "benchmark.h"





static uint8_t public_key[
    PQCLEAN_MLDSA44_CLEAN_CRYPTO_PUBLICKEYBYTES
];



static uint8_t secret_key[
    PQCLEAN_MLDSA44_CLEAN_CRYPTO_SECRETKEYBYTES
];



static uint8_t signature[
    PQCLEAN_MLDSA44_CLEAN_CRYPTO_BYTES
];



static uint8_t message[] =
{
    "ML-DSA-44 Functional Validation Message"
};



static size_t signature_length;









static void print_banner(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("             ML-DSA-44 Functional Validation\n");
    printf("             Raspberry Pi Pico 2 W (RP2350)\n");
    printf("             PQClean Clean Implementation\n");
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







    printf("[1/4] Generating ML-DSA-44 Key Pair...\n\n");



    if(
        PQCLEAN_MLDSA44_CLEAN_crypto_sign_keypair(
            public_key,
            secret_key
        ) != 0
    )
    {

        printf("ERROR: Key generation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Key pair generated successfully.\n\n");









    printf("[2/4] Generating Signature...\n\n");



    if(
        PQCLEAN_MLDSA44_CLEAN_crypto_sign_signature(
            signature,
            &signature_length,
            message,
            sizeof(message),
            secret_key
        ) != 0
    )
    {

        printf("ERROR: Signature generation failed\n");


        while(1)
            tight_loop_contents();

    }



    printf("SUCCESS: Signature generated successfully.\n\n");









    printf("[3/4] Verifying Signature...\n\n");



    if(
        PQCLEAN_MLDSA44_CLEAN_crypto_sign_verify(
            signature,
            signature_length,
            message,
            sizeof(message),
            public_key
        ) != 0
    )
    {

        printf("ERROR: Signature verification failed\n");


        while(1)
            tight_loop_contents();

    }



    printf("SUCCESS: Signature verified successfully.\n\n");









    printf("[4/4] Verification Result...\n\n");





    printf("=============================================\n");
    printf("           VERIFICATION RESULT\n");
    printf("=============================================\n");







    if(
        PQCLEAN_MLDSA44_CLEAN_crypto_sign_verify(
            signature,
            signature_length,
            message,
            sizeof(message),
            public_key
        ) == 0
    )
    {

        printf("PASS: Signature is valid.\n");
        printf("ML-DSA-44 functional validation successful.\n");

    }

    else
    {

        printf("FAIL: Signature is invalid.\n");
        printf("ML-DSA-44 functional validation failed.\n");

    }



    printf("=============================================\n\n");









    print_processor_info();



    run_benchmark();









    while(1)
    {

        tight_loop_contents();

    }







    return 0;

}
