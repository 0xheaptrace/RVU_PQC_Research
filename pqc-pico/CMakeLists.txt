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


    # Falcon-512 PQClean Clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/sign.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/keygen.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/fft.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/fpr.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/codec.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/common.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/rng.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/vrfy.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean/pqclean.c


    # PQClean common

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/fips202.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sha2.c

)





target_include_directories(
    pqc_pico

    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-512/clean

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
