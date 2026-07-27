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



    # HQC-128 PQClean clean implementation

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/kem.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/hqc.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/code.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/fft.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/gf.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/gf2x.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/parsing.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/reed_muller.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/reed_solomon.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/vector.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/shake_ds.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean/shake_prng.c



    # PQClean common crypto

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/fips202.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/sha2.c
    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common/aes.c

)





# Force C linker

set_target_properties(
    pqc_pico
    PROPERTIES
    LINKER_LANGUAGE C
)







target_include_directories(
    pqc_pico
    PRIVATE


    ${CMAKE_CURRENT_LIST_DIR}/src



    # HQC-128 headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/crypto_kem/hqc-128/clean



    # PQClean common headers

    ${CMAKE_CURRENT_LIST_DIR}/../PQClean/common



    # ARM Cortex-M33 PMU headers

    ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Core/Include

    ${PICO_SDK_PATH}/src/rp2_common/cmsis/stub/CMSIS/Core/Include/m-profile


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
