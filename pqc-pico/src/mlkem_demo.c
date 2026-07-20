#include "mlkem_demo.h"

#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

#include "api.h"


/* --------------------------------------------------------------------------
 * Static Buffers
 * -------------------------------------------------------------------------- */

static uint8_t public_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_PUBLICKEYBYTES];

static uint8_t secret_key[PQCLEAN_MLKEM512_CLEAN_CRYPTO_SECRETKEYBYTES];

static uint8_t ciphertext[PQCLEAN_MLKEM512_CLEAN_CRYPTO_CIPHERTEXTBYTES];

static uint8_t shared_secret_enc[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];

static uint8_t shared_secret_dec[PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES];



/* --------------------------------------------------------------------------
 * Helper Functions
 * -------------------------------------------------------------------------- */

static void print_separator(void)
{
    printf("------------------------------------------------------------\n");
}



static void print_hex(const char *title,
                      const uint8_t *buffer,
                      size_t length)
{
    printf("%s (%u bytes)\n",
           title,
           (unsigned int)length);

    print_separator();


    for(size_t i = 0; i < length; i++)
    {
        printf("%02x", buffer[i]);

        if((i + 1) % 32 == 0)
        {
            printf("\n");
        }
    }

    if(length % 32 != 0)
    {
        printf("\n");
    }

    printf("\n");
}



/* --------------------------------------------------------------------------
 * ML-KEM Functional Validation
 * -------------------------------------------------------------------------- */

void mlkem_demo(void)
{

    printf("\n");

    printf("============================================================\n");
    printf("            ML-KEM-512 Functional Validation\n");
    printf("         Raspberry Pi Pico 2 W (RP2350)\n");
    printf("         PQClean Clean Implementation\n");
    printf("============================================================\n\n");



    printf("[1/4] Generating ML-KEM-512 Key Pair...\n\n");


    if(PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(
            public_key,
            secret_key) != 0)
    {
        printf("ERROR: Key generation failed\n");

        while(true)
            tight_loop_contents();
    }


    printf("SUCCESS: Key pair generated successfully.\n\n");


    print_hex(
        "Public Key",
        public_key,
        PQCLEAN_MLKEM512_CLEAN_CRYPTO_PUBLICKEYBYTES
    );


    print_hex(
        "Secret Key",
        secret_key,
        PQCLEAN_MLKEM512_CLEAN_CRYPTO_SECRETKEYBYTES
    );



    printf("[2/4] Performing Encapsulation...\n\n");


    if(PQCLEAN_MLKEM512_CLEAN_crypto_kem_enc(
            ciphertext,
            shared_secret_enc,
            public_key) != 0)
    {
        printf("ERROR: Encapsulation failed\n");

        while(true)
            tight_loop_contents();
    }


    printf("SUCCESS: Encapsulation completed successfully.\n\n");


    print_hex(
        "Ciphertext",
        ciphertext,
        PQCLEAN_MLKEM512_CLEAN_CRYPTO_CIPHERTEXTBYTES
    );


    print_hex(
        "Shared Secret (Encapsulation)",
        shared_secret_enc,
        PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES
    );



    printf("[3/4] Performing Decapsulation...\n\n");


    if(PQCLEAN_MLKEM512_CLEAN_crypto_kem_dec(
            shared_secret_dec,
            ciphertext,
            secret_key) != 0)
    {
        printf("ERROR: Decapsulation failed\n");

        while(true)
            tight_loop_contents();
    }


    printf("SUCCESS: Decapsulation completed successfully.\n\n");


    print_hex(
        "Shared Secret (Decapsulation)",
        shared_secret_dec,
        PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES
    );



    printf("[4/4] Verifying Shared Secrets...\n\n");


    printf("=============================================\n");
    printf("           VERIFICATION RESULT\n");
    printf("=============================================\n");


    if(memcmp(shared_secret_enc,
              shared_secret_dec,
              PQCLEAN_MLKEM512_CLEAN_CRYPTO_BYTES) == 0)
    {
        printf("PASS: Shared secrets are identical.\n");
        printf("ML-KEM-512 functional validation successful.\n");
    }
    else
    {
        printf("FAIL: Shared secrets do not match.\n");
        printf("ML-KEM-512 functional validation failed.\n");
    }


    printf("=============================================\n");

}

