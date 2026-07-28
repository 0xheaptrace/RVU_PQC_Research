cmake_minimum_required(VERSION 3.13)


set(PICO_BOARD pico2_w)


include(pico_sdk_import.cmake)



project(pqc_pico C CXX ASM)



set(CMAKE_C_STANDARD 11)



pico_sdk_init()





add_executable(pqc_pico


    src/main.c

    src/benchmark.c

    src/randombytes.c



    # HQC-256 PQClean clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/kem.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/hqc.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/code.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/fft.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/gf.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/gf2x.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/parsing.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/reed_muller.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/reed_solomon.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/vector.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/shake_ds.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean/shake_prng.c



    # PQClean common crypto

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/fips202.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sha2.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/aes.c

)





set_target_properties(
    pqc_pico
    PROPERTIES
    LINKER_LANGUAGE C
)







target_include_directories(
    pqc_pico
    PRIVATE


    ${CMAKE_CURRENT_LIST_DIR}/src



    # HQC-256 headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-256/clean



    # PQClean common headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common

)







target_link_libraries(
    pqc_pico

    pico_stdlib

    hardware_clocks

    pico_rand

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
