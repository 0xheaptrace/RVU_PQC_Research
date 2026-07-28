cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico2_w)

include(pico_sdk_import.cmake)


project(pqc_pico C CXX ASM)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()



add_executable(pqc_pico

    src/main.c
    src/benchmark.c
    src/randombytes.c


    # ML-KEM-1024 PQClean Clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/kem.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/indcpa.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/poly.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/polyvec.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/ntt.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/reduce.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/cbd.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/symmetric-shake.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean/verify.c


    # PQClean common crypto

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/fips202.c

)





target_include_directories(
    pqc_pico
    PRIVATE


    ${CMAKE_CURRENT_LIST_DIR}/src


    # ML-KEM-1024 headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/ml-kem-1024/clean


    # PQClean common headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common

)





target_link_libraries(
    pqc_pico

    pico_stdlib
    pico_rand

    hardware_clocks

)





pico_enable_stdio_usb(
    pqc_pico
    1
)


pico_enable_stdio_uart(
    pqc_pico
    0
)



pico_add_extra_outputs(
    pqc_pico
)
