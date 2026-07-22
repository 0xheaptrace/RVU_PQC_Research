cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pqc_pico C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()


add_compile_definitions(PICO_STACK_SIZE=0x8000)
add_compile_definitions(PICO_HEAP_SIZE=0x4000)



add_executable(pqc_pico

    src/main.c
    src/randombytes.c
    src/benchmark.c


    # PQClean ML-KEM-768 Clean Implementation
    ../PQClean/crypto_kem/ml-kem-768/clean/cbd.c
    ../PQClean/crypto_kem/ml-kem-768/clean/indcpa.c
    ../PQClean/crypto_kem/ml-kem-768/clean/kem.c
    ../PQClean/crypto_kem/ml-kem-768/clean/ntt.c
    ../PQClean/crypto_kem/ml-kem-768/clean/poly.c
    ../PQClean/crypto_kem/ml-kem-768/clean/polyvec.c
    ../PQClean/crypto_kem/ml-kem-768/clean/reduce.c
    ../PQClean/crypto_kem/ml-kem-768/clean/symmetric-shake.c
    ../PQClean/crypto_kem/ml-kem-768/clean/verify.c


    # PQClean common
    ../PQClean/common/fips202.c

)



target_include_directories(pqc_pico PRIVATE

    src

    ../PQClean/common

    ../PQClean/crypto_kem/ml-kem-768/clean

)



target_link_libraries(pqc_pico

    pico_stdlib
    pico_rand
    m

)



pico_enable_stdio_usb(pqc_pico 1)
pico_enable_stdio_uart(pqc_pico 0)



pico_set_linker_script_var(
    pqc_pico
    RAM_LENGTH
    448k
)


pico_set_linker_script_var(
    pqc_pico
    SCRATCH_Y_ORIGIN
    0x20070000
)


pico_set_linker_script_var(
    pqc_pico
    SCRATCH_Y_LENGTH
    64k
)



pico_add_extra_outputs(pqc_pico)
