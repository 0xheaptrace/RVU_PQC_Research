#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "api.h"
#include "benchmark.h"



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



static void print_banner(void)
{

    printf("\n");
    printf("============================================================\n");
    printf("         Falcon-512 Functional Validation\n");
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




    printf("[1/4] Generating Falcon-512 Key Pair...\n\n");


    if(PQCLEAN_FALCON512_CLEAN_crypto_sign_keypair(
            public_key,
            secret_key) != 0)
    {

        printf("ERROR: Key generation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Key pair generated successfully.\n\n");





    printf("[2/4] Signing Message...\n\n");


    size_t siglen;


    if(PQCLEAN_FALCON512_CLEAN_crypto_sign_signature(
            signature,
            &siglen,
            message,
            sizeof(message),
            secret_key) != 0)
    {

        printf("ERROR: Signature generation failed\n");


        while(1)
            tight_loop_contents();

    }


    printf("SUCCESS: Message signed successfully.\n\n");






    printf("[3/4] Verifying Signature...\n\n");


    if(PQCLEAN_FALCON512_CLEAN_crypto_sign_verify(
            signature,
            siglen,
            message,
            sizeof(message),
            public_key) != 0)
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



    if(PQCLEAN_FALCON512_CLEAN_crypto_sign_verify(
            signature,
            siglen,
            message,
            sizeof(message),
            public_key) == 0)
    {

        printf("PASS: Signature is valid.\n");
        printf("Falcon-512 functional validation successful.\n");

    }

    else
    {

        printf("FAIL: Signature is invalid.\n");
        printf("Falcon-512 functional validation failed.\n");

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
