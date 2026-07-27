cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pqc_pico C CXX ASM)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()



add_executable(pqc_pico

    src/main.c
    src/benchmark.c
    src/randombytes.c



    # =====================================================
    # HQC-256 Clean Implementation
    # =====================================================

    ../PQClean/crypto_kem/hqc-256/clean/kem.c

    ../PQClean/crypto_kem/hqc-256/clean/hqc.c

    ../PQClean/crypto_kem/hqc-256/clean/code.c

    ../PQClean/crypto_kem/hqc-256/clean/fft.c

    ../PQClean/crypto_kem/hqc-256/clean/gf.c

    ../PQClean/crypto_kem/hqc-256/clean/gf2x.c

    ../PQClean/crypto_kem/hqc-256/clean/parsing.c

    ../PQClean/crypto_kem/hqc-256/clean/reed_muller.c

    ../PQClean/crypto_kem/hqc-256/clean/reed_solomon.c

    ../PQClean/crypto_kem/hqc-256/clean/vector.c

    ../PQClean/crypto_kem/hqc-256/clean/shake_ds.c

    ../PQClean/crypto_kem/hqc-256/clean/shake_prng.c



    # =====================================================
    # PQClean Common
    # =====================================================

    ../PQClean/common/fips202.c

    ../PQClean/common/sha2.c

    ../PQClean/common/aes.c

)





target_include_directories(pqc_pico PRIVATE

    src

    ../PQClean/common

    ../PQClean/crypto_kem/hqc-256/clean

)





target_link_libraries(pqc_pico

    pico_stdlib

    pico_rand

    m

)





# USB Serial Output

pico_enable_stdio_usb(pqc_pico 1)

pico_enable_stdio_uart(pqc_pico 0)





pico_add_extra_outputs(pqc_pico)
