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


    # SPHINCS+-SHA2-192s-simple PQClean Clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/address.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/context_sha2.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/fors.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/hash_sha2.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/merkle.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/sign.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/thash_sha2_simple.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/utils.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/utilsx1.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/wots.c

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean/wotsx1.c



    # PQClean common SHA implementations

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sha2.c

)



target_include_directories(

    pqc_pico

    PRIVATE


    ${CMAKE_CURRENT_LIST_DIR}/src


    # SPHINCS+-SHA2-192s-simple headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_sign/sphincs-sha2-192s-simple/clean


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
