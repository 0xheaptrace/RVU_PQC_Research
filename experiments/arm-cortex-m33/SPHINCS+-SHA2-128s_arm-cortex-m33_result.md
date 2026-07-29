# SPHINCS+-SHA2-128s-simple Benchmark Results - RP2350 ARM Cortex-M33

## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | ARM Cortex-M33 |
| Core | RP2350 Cortex-M33 |
| Cycle Counter | ARM Cortex-M33 DWT CYCCNT |
| Compiler | GCC 15.2.1 |
| CPU Clock | RP2350 Default Clock |

---

# Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | SPHINCS+-SHA2-128s-simple |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 1 |
| Benchmark Iterations | 10 |
| Measurement Method | ARM Cortex-M33 DWT Cycle Counter |
| Time Measurement | RP2350 System Timer |

---

# Functional Validation

The SPHINCS+-SHA2-128s-simple implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |

---

# Benchmark Results

Benchmark performed over **10 iterations after 1 warmup execution**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 6882993 | 6882.993 | 1032449044 | 6882789 | 6883228 | 147.04 |
| Signature Generation | 52226440 | 52226.440 | 3538998671 | 52225190 | 52228049 | 707.66 |
| Verification | 52513 | 52.513 | 7877042 | 52455 | 52816 | 102.03 |
| Total Sign | 59160700 | 59160.700 | 284170466 | 59156793 | 59164012 | 2249.65 |

---

# SPHINCS+-SHA2-128s-simple Performance Analysis

SPHINCS+-SHA2-128s-simple demonstrates significantly higher execution latency compared to lattice-based signature schemes such as ML-DSA due to its hash-based construction.

The implementation relies entirely on hash computations, including:

- WOTS+ one-time signatures
- FORS few-time signatures
- Merkle tree authentication paths
- SHA2-based tweakable hash operations

Signature generation dominates the execution time because it requires constructing multiple authentication paths and generating a large number of hash operations across the hypertree structure.

The measured performance characteristics are summarized below.

| Parameter | Value |
|-----------|-------|
| Mean Key Generation Time | 6882.993 ms |
| Mean Signature Generation Time | 52226.440 ms |
| Mean Verification Time | 52.513 ms |
| Total Signing Operation | 59160.700 ms |

---

# Execution-Time Characteristics

Unlike Falcon, SPHINCS+-SHA2-128s-simple shows very low execution-time variance.

The measured standard deviation remains small because:

- SHA2 operations execute deterministically.
- Merkle tree traversal follows a fixed computation path.
- No probabilistic Gaussian sampling is involved.
- No rejection sampling is performed.

The observed stability indicates predictable timing behavior, which is expected from hash-based signature schemes.

---

# Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- SPHINCS+-SHA2-128s-simple implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained using the ARM Cortex-M33 DWT CYCCNT hardware cycle counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10 benchmark iterations after 1 warmup iteration.
- Benchmark iteration count was reduced due to the extremely high computational cost of SPHINCS+ on constrained embedded hardware.
- Standard deviation represents execution-time variation across benchmark iterations.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
