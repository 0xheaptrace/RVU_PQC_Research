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


    # Falcon-1024 PQClean Clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/codec.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/common.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/fft.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/fpr.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/keygen.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/pqclean.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/rng.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/sign.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean/vrfy.c

    # PQClean common sources
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/fips202.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/aes.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sha2.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/nistseedexpander.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sp800-185.c
)



target_include_directories(
    pqc_pico
    PRIVATE


    ${CMAKE_CURRENT_LIST_DIR}/src


    # Falcon-1024 headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/falcon-1024/clean


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
