# Falcon-512 Benchmark Results - RP2350 RISC-V

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
| Algorithm | Falcon-512 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |

---

## Functional Validation

The Falcon-512 implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | **PASS** |

---

## Benchmark Results

Benchmark performed over **100 iterations** after **3 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|----------:|----------:|-------:|---------:|---------:|---------:|
| Key Generation | 1459267 | 1459.267 | 218889932 | 871031 | 4536974 | 638510.44 |
| Signing | 397949 | 397.949 | 59692176 | 395505 | 399702 | 734.22 |
| Verification | 775 | 0.775 | 116290 | 773 | 956 | 18.17 |
| Total Sign | 1888824 | 1888.824 | 283323530 | 1274323 | 5229366 | 679150.34 |

---

## Falcon-512 Performance Analysis

Unlike ML-DSA, Falcon-512 exhibits the largest execution-time variation during **key generation**, while the signing and verification operations remain comparatively stable.

Falcon key generation requires solving an NTRU lattice basis using recursive Fast Fourier Transform (FFT) computations together with randomized Gaussian sampling. The probabilistic nature of these operations results in variable execution times between successive key generation attempts. Consequently, some executions complete much sooner than others, producing a large spread between the minimum and maximum observed execution times and a correspondingly high standard deviation.

In contrast, Falcon signing performs Gaussian sampling using an already generated private key and therefore exhibits substantially lower execution-time variability. Verification is entirely deterministic and consequently shows the smallest execution-time variance.

The observed key generation variability is summarized below.

| Parameter | Value |
|-----------|------:|
| Mean Key Generation Time | 1459.267 ms |
| Minimum Key Generation Time | 871.031 ms |
| Maximum Key Generation Time | 4536.974 ms |
| Standard Deviation | 638.510 ms |

The PQClean Falcon-512 clean implementation was benchmarked without modification. The observed execution-time variation reflects the inherent probabilistic behavior of the Falcon key generation algorithm rather than implementation-specific effects.

---

## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- Falcon-512 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent **100 benchmark iterations** after **3 warmup iterations**.
- The benchmark iteration count was reduced compared to the ML-KEM and ML-DSA experiments due to the significantly higher computational cost of Falcon-512 on constrained embedded hardware.
- Standard deviation represents execution-time variation across benchmark iterations.
- Falcon key generation exhibits high variance due to probabilistic NTRU lattice solving and Gaussian sampling, while signing and verification remain comparatively stable.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
