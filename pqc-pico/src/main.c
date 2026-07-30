#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "pico/stdlib.h"

#include "api.h"
#include "benchmark.h"


#define MESSAGE "PQC ML-DSA-87 Benchmark Test"


uint8_t public_key[
    PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES
];


uint8_t secret_key[
    PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES
];


uint8_t signature[
    PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES
];


uint8_t message[] = MESSAGE;



void functional_validation(void)
{

    size_t siglen;


    printf("\n");
    printf("============================================================\n");
    printf("             ML-DSA-87 Functional Validation\n");
    printf("             Raspberry Pi Pico 2 W (RP2350)\n");
    printf("             PQClean Clean Implementation\n");
    printf("============================================================\n\n");



    printf("[1/4] Generating ML-DSA-87 Key Pair...\n\n");



    int result =
    PQCLEAN_MLDSA87_CLEAN_crypto_sign_keypair(
        public_key,
        secret_key
    );


    if(result != 0)
    {
        printf("ERROR: Key generation failed\n");
        return;
    }


    printf("SUCCESS: Key pair generated successfully.\n\n");



    printf("[2/4] Generating Signature...\n\n");



    result =
    PQCLEAN_MLDSA87_CLEAN_crypto_sign_signature(
        signature,
        &siglen,
        message,
        sizeof(message),
        secret_key
    );


    if(result != 0)
    {
        printf("ERROR: Signature generation failed\n");
        return;
    }


    printf("SUCCESS: Signature generated successfully.\n\n");



    printf("[3/4] Verifying Signature...\n\n");



    result =
    PQCLEAN_MLDSA87_CLEAN_crypto_sign_verify(
        signature,
        siglen,
        message,
        sizeof(message),
        public_key
    );



    if(result != 0)
    {
        printf("ERROR: Signature verification failed\n");
        return;
    }


    printf("SUCCESS: Signature verified successfully.\n\n");



    printf("[4/4] Verification Result...\n\n");


    printf("=============================================\n");
    printf("           VERIFICATION RESULT\n");
    printf("=============================================\n");

    printf("PASS: Signature is valid.\n");
    printf("ML-DSA-87 functional validation successful.\n");

    printf("=============================================\n\n");


}





int main()
{

    stdio_init_all();


    sleep_ms(3000);



    functional_validation();



    print_processor_info();



    run_benchmark();



    while(1)
    {

        tight_loop_contents();

    }


    return 0;

}
