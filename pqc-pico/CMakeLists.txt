cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pqc_pico C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()



add_executable(pqc_pico

    src/main.c
    src/randombytes.c
    src/benchmark.c


    # =====================================================
    # SPHINCS+-SHA2-256s-simple Clean Implementation
    # =====================================================

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/address.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/context_sha2.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/fors.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/hash_sha2.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/merkle.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/sign.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/thash_sha2_simple.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/utils.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/utilsx1.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/wots.c

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean/wotsx1.c



    # =====================================================
    # PQClean Common
    # =====================================================

    ../PQClean/common/fips202.c

    ../PQClean/common/sha2.c

)





target_include_directories(pqc_pico PRIVATE

    src

    ../PQClean/common

    ../PQClean/crypto_sign/sphincs-sha2-256s-simple/clean

)





target_link_libraries(pqc_pico

    pico_stdlib

    pico_rand

    m

)





pico_enable_stdio_usb(pqc_pico 1)

pico_enable_stdio_uart(pqc_pico 0)





pico_add_extra_outputs(pqc_pico)
