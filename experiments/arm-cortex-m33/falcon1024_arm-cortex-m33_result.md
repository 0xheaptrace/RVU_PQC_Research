# Falcon-1024 Benchmark Results - RP2350 ARM Cortex-M33

## Processor Information

| Parameter | Value |
|---|---|
| Architecture | ARM Cortex-M33 |
| Core | RP2350 Cortex-M33 |
| ISA | ARMv8-M |
| Cycle Counter | ARM Cortex-M33 DWT CYCCNT |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.1 |

---

# Benchmark Configuration

| Parameter | Value |
|---|---|
| Algorithm | Falcon-1024 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Processor | ARM Cortex-M33 |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | ARM Cortex-M33 DWT Cycle Counter |
| Time Measurement | RP2350 System Timer |

---

# Functional Validation

The Falcon-1024 implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|---|---|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |

---

# Benchmark Results

Benchmark performed over **100 iterations** after **3 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|---|---:|---:|---:|---:|---:|---:|
| Key Generation | 3,871,762 | 3871.762 | 580,764,167 | 2,250,713 | 8,164,240 | 1,465,476.79 |
| Signing | 888,928 | 888.928 | 133,338,944 | 886,233 | 891,392 | 969.90 |
| Verification | 10,971 | 10.971 | 1,645,702 | 10,948 | 11,590 | 62.94 |
| Total Sign | 4,847,768 | 4847.768 | 727,164,992 | 3,150,127 | 11,023,999 | 1,616,634.76 |

---

# Falcon-1024 Performance Analysis

Falcon-1024 demonstrates a significant increase in computational cost compared to Falcon-512, primarily due to the larger NTRU lattice dimension and increased complexity of the underlying lattice operations.

The key generation phase exhibits the highest execution-time variation. Falcon key generation requires solving an NTRU lattice basis using recursive Fast Fourier Transform (FFT) operations combined with randomized Gaussian sampling. These probabilistic operations introduce variability between different key generation attempts.

The observed variation is reflected by the large difference between minimum and maximum key generation times. Some executions complete significantly faster, while others require additional iterations during lattice basis generation, resulting in a higher standard deviation.

In contrast, Falcon-1024 signing operates using an already generated private key. The Gaussian sampling stage remains probabilistic but avoids the expensive lattice basis generation step, resulting in significantly lower execution-time variation compared to key generation.

Signature verification remains deterministic and shows the lowest execution-time variance, as it only performs public-key based polynomial computations and signature validity checks.

---

# Key Generation Variability Analysis

| Parameter | Value |
|---|---:|
| Mean Key Generation Time | 3871.762 ms |
| Minimum Key Generation Time | 2250.713 ms |
| Maximum Key Generation Time | 8164.240 ms |
| Standard Deviation | 1465.477 ms |

---

# Implementation Notes

- The PQClean Falcon-1024 clean implementation was benchmarked without modification.
- Execution-time variation reflects the inherent probabilistic behavior of Falcon key generation rather than implementation-specific effects.
- CPU cycle measurements were obtained directly using the ARM Cortex-M33 DWT CYCCNT hardware cycle counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- The benchmark iteration count was reduced compared to ML-KEM and ML-DSA experiments due to the significantly higher computational cost of Falcon-1024 on constrained embedded hardware.
- Standard deviation represents execution-time variation across benchmark iterations.
- Falcon key generation exhibits high variance due to probabilistic NTRU lattice solving and Gaussian sampling, while signing and verification remain comparatively stable.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
