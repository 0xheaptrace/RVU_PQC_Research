# SPHINCS+-SHA2-192s-simple Benchmark Results - RP2350 ARM Cortex-M33

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
| Algorithm | SPHINCS+-SHA2-192s-simple |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Architecture | ARM Cortex-M33 |
| Build Type | Release |
| Warmup Iterations | 1 |
| Benchmark Iterations | 10 |
| Measurement Method | ARM Cortex-M33 DWT CYCCNT + System Timer |

---

## Functional Validation

The SPHINCS+-SHA2-192s-simple implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |

---

## Benchmark Results

Benchmark performed over 10 iterations after 1 warmup execution.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 17642875 | 17642.875 | 2646431206 | 17642320 | 17643703 | 396.57 |
| Signature Generation | 610079499 | 610079.499 | 1317611386 | 610074757 | 610085001 | 3412.57 |
| Verification | 628252 | 628.252 | 94237819 | 628171 | 628396 | 66.33 |
| Total Sign | 628346681 | 628346.681 | 4057688772 | 628340845 | 628352702 | 3386.01 |

---

## SPHINCS+-SHA2-192s Performance Analysis

SPHINCS+-SHA2-192s-simple exhibited significantly higher execution time compared to lattice-based signature schemes such as ML-DSA. This behavior is expected due to the hash-based construction of SPHINCS+, which requires multiple layers of Merkle tree computation, WOTS+ signatures, and FORS operations.

The dominant computational cost was observed during signature generation, requiring approximately **610 seconds** on the RP2350 ARM Cortex-M33 platform. This is primarily caused by repeated hash evaluations and tree traversal operations involved in generating the stateless hash-based signature.

Key generation required approximately **17.64 seconds**, while verification remained comparatively efficient at approximately **628 milliseconds** due to the deterministic nature of the verification process.

The low standard deviation across all operations indicates stable execution behavior despite the high computational requirements.

---

## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- SPHINCS+-SHA2-192s-simple implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained using the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10 benchmark iterations after 1 warmup iteration.
- The benchmark iteration count was reduced due to the extremely high computational cost of SPHINCS+ on constrained embedded hardware.
- No private keys, signatures, or cryptographic material were recorded during benchmarking.
