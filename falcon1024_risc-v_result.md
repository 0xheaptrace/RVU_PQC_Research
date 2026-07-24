# Falcon-1024 Benchmark Results - RP2350 RISC-V

## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | RISC-V |
| Core | Hazard3 |
| ISA | RV32IMAC |
| XLEN | 32-bit |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.0 |

---

## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | Falcon-1024 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |

---

## Functional Validation

The Falcon-1024 implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |

---

## Benchmark Results

Benchmark performed over **100 iterations** after **3 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 3800369 | 3800.369 | 570055202 | 2249225 | 11026541 | 1614146.57 |
| Signing | 869131 | 869.131 | 130369500 | 867396 | 871228 | 883.76 |
| Verification | 1651 | 1.651 | 247767 | 1648 | 1937 | 28.66 |
| Total Sign | 4372319 | 4372.319 | 655847701 | 3128199 | 9957952 | 1325394.33 |

---

## Falcon-1024 Performance Analysis

The Falcon-1024 benchmark demonstrates the computational cost of a higher-security lattice-based signature scheme on a constrained RISC-V microcontroller.

Key generation exhibits the highest execution time and variability due to the intensive operations involved in generating the Falcon private key, including FFT-based polynomial sampling and NTRU lattice computations.

Signature generation shows comparatively stable execution time despite being computationally expensive. The low standard deviation indicates consistent signing behaviour across benchmark iterations.

Verification is significantly faster than key generation and signing, completing in approximately **1.65 ms**, making Falcon-1024 verification practical for constrained-device authentication scenarios.

The observed execution characteristics represent the natural behaviour of the PQClean Clean implementation running without optimization modifications.

---

## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- Falcon-1024 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly using the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No private keys, signatures, or cryptographic material were recorded during benchmarking.
