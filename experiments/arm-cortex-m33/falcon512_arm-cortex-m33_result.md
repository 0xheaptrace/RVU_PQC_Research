# Falcon-512 Benchmark Results - RP2350 ARM Cortex-M33

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
| Algorithm | Falcon-512 |
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

The Falcon-512 implementation was first validated by performing a complete signature generation and verification operation.

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
| Key Generation | 1,658,903 | 1658.903 | 248,835,393 | 882,650 | 4,428,752 | 760,385.55 |
| Signing | 406,661 | 406.661 | 60,999,104 | 404,751 | 409,104 | 732.93 |
| Verification | 5,466 | 5.466 | 819,906 | 5,451 | 5,982 | 52.33 |
| Total Sign | 2,051,102 | 2051.102 | 307,665,258 | 1,294,186 | 4,293,462 | 706,928.41 |

---

# Falcon-512 Performance Analysis

Falcon-512 exhibits significant execution-time variation during key generation, while signing and verification operations remain comparatively stable.

Falcon key generation requires solving an NTRU lattice basis using recursive Fast Fourier Transform (FFT) computations together with randomized Gaussian sampling. The probabilistic nature of these operations introduces execution-time variation between successive key generation attempts.

As a result, some key generation executions complete significantly faster than others, producing a large difference between minimum and maximum execution times and a high standard deviation.

In contrast, Falcon signing performs Gaussian sampling using an already generated private key. Since the expensive NTRU lattice basis generation step is avoided, signing exhibits substantially lower execution-time variability.

Verification is fully deterministic and consists primarily of polynomial computations and signature validation checks. Therefore, it demonstrates the lowest execution-time variance among all Falcon operations.

---

# Key Generation Variability Analysis

| Parameter | Value |
|---|---:|
| Mean Key Generation Time | 1658.903 ms |
| Minimum Key Generation Time | 882.650 ms |
| Maximum Key Generation Time | 4428.752 ms |
| Standard Deviation | 760.386 ms |

---

# Implementation Notes

- The PQClean Falcon-512 clean implementation was benchmarked without modification.
- Execution-time variation reflects the inherent probabilistic behavior of Falcon key generation rather than implementation-specific effects.
- CPU cycle measurements were obtained directly using the ARM Cortex-M33 DWT CYCCNT hardware cycle counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- The benchmark iteration count was reduced compared to ML-KEM and ML-DSA experiments due to the significantly higher computational cost of Falcon-512 on constrained embedded hardware.
- Standard deviation represents execution-time variation across benchmark iterations.
- Falcon key generation exhibits high variance due to probabilistic NTRU lattice solving and Gaussian sampling, while signing and verification remain comparatively stable.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
