cmake_minimum_required(VERSION 3.13)


# ============================================================
# RP2350 Hazard3 RISC-V Configuration
# ============================================================

set(PICO_BOARD pico2_w)
set(PICO_PLATFORM rp2350-riscv)
set(PICO_COMPILER pico_riscv_gcc)



include(pico_sdk_import.cmake)



project(pqc_pico C CXX ASM)



set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)



pico_sdk_init()



# ============================================================
# Memory Configuration
# ============================================================

add_compile_definitions(PICO_STACK_SIZE=0x8000)
add_compile_definitions(PICO_HEAP_SIZE=0x4000)



# ============================================================
# Executable
# ============================================================

add_executable(pqc_pico


    src/main.c

    src/randombytes.c

    src/benchmark.c



    # ========================================================
    # PQClean ML-KEM-1024 Clean Implementation
    # ========================================================


    ../PQClean/crypto_kem/ml-kem-1024/clean/cbd.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/indcpa.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/kem.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/ntt.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/poly.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/polyvec.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/reduce.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/symmetric-shake.c

    ../PQClean/crypto_kem/ml-kem-1024/clean/verify.c



    # PQClean common

    ../PQClean/common/fips202.c

)



# ============================================================
# Include Directories
# ============================================================

target_include_directories(pqc_pico PRIVATE


    src


    ../PQClean/common


    ../PQClean/crypto_kem/ml-kem-1024/clean

)



# ============================================================
# Libraries
# ============================================================

target_link_libraries(pqc_pico


    pico_stdlib

    pico_rand

    m

)



# ============================================================
# USB Serial
# ============================================================

pico_enable_stdio_usb(pqc_pico 1)

pico_enable_stdio_uart(pqc_pico 0)



# ============================================================
# RP2350 Memory Layout
# ============================================================

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



# Generate UF2 / ELF / BIN

pico_add_extra_outputs(pqc_pico)
