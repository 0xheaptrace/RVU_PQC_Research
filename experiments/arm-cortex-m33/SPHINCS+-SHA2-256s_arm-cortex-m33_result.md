# SPHINCS+-SHA2-256s-simple Benchmark Results - RP2350 ARM Cortex-M33

## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | ARM Cortex-M33 |
| Core | RP2350 Cortex-M33 |
| Cycle Counter | ARM Cortex-M33 DWT CYCCNT |
| Compiler | GCC 15.2.1 (20251203) |

---

## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | SPHINCS+-SHA2-256s-simple |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Architecture | ARM Cortex-M33 |
| Build Type | Release |
| Warmup Iterations | 1 |
| Benchmark Iterations | 1 |
| Measurement Method | ARM Cortex-M33 DWT CYCCNT + System Timer |

---

## Functional Validation

The SPHINCS+-SHA2-256s-simple implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |

---

## Benchmark Results

Benchmark performed over 1 iteration after 1 warmup execution.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 13151344 | 13151.344 | 1972701626 | 13151344 | 13151344 | 0.00 |
| Signature Generation | 734199726 | 734199.726 | 2755776494 | 734199726 | 734199726 | 0.00 |
| Verification | 876303 | 876.303 | 131445504 | 876303 | 876303 | 0.00 |
| Total Sign | 748238739 | 748238.739 | 566661164 | 748238739 | 748238739 | 0.00 |

---

## SPHINCS+-SHA2-256s Performance Analysis

SPHINCS+-SHA2-256s-simple demonstrated the highest computational cost among
the evaluated post-quantum signature algorithms. The increased execution time
is expected due to the hash-based signature construction that requires
extensive Merkle tree generation, WOTS+ operations, and FORS computations.

Signature generation was the dominant operation, requiring approximately
**734 seconds** on the RP2350 ARM Cortex-M33 platform. The high computational
cost results from repeated SHA-256 hash evaluations and large tree traversal
operations required during stateless signature generation.

Key generation required approximately **13.15 seconds**, while verification
required approximately **876 milliseconds**. Verification remained significantly
faster because it only performs hash computations required to reconstruct and
validate the authentication paths.

The benchmark was limited to a single iteration due to the extremely high
execution time of SPHINCS+-SHA2-256s-simple on constrained embedded hardware.
Consequently, the standard deviation is zero because only one measurement was
recorded.

---

## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- SPHINCS+-SHA2-256s-simple implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained using the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 1 benchmark iteration after 1 warmup iteration.
- Benchmark iterations were reduced due to the extremely high computational cost of SPHINCS+-SHA2-256s-simple.
- No private keys, signatures, or cryptographic material were recorded during benchmarking.
