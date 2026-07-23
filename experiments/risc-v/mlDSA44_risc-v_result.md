# ML-DSA-44 Benchmark Results - RP2350 RISC-V


## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | RISC-V |
| Core | Hazard3 |
| ISA | RV32IMAC |
| XLEN | 32-bit |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.0 |


## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | ML-DSA-44 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |


## Functional Validation

The ML-DSA-44 implementation was first validated by performing a complete signature generation and verification operation:

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |


## Benchmark Results

Benchmark performed over **10,000 iterations** after **100 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 19288 | 19.288 | 2893317 | 18725 | 19801 | 184.05 |
| Signing | 69313 | 69.313 | 10396744 | 30795 | 456757 | 43804.41 |
| Verification | 20437 | 20.437 | 3065648 | 20428 | 20946 | 6.12 |
| Total Sign | 109210 | 109.210 | 16381556 | 70009 | 472668 | 43962.76 |


## ML-DSA Signing Variability Analysis

The ML-DSA-44 signing operation exhibits higher execution-time variation compared to key generation and verification.

This behaviour is expected due to the **rejection sampling mechanism** used during ML-DSA signature generation. During signing, the algorithm repeatedly generates candidate values and evaluates security constraints. If a generated candidate does not satisfy the required bounds, it is discarded and a new candidate is generated.

As a result, some signing operations complete after fewer iterations, while others require additional rejection sampling rounds, causing increased maximum execution time and standard deviation.

The observed signing variability:

| Parameter | Value |
|-----------|-------|
| Mean Signing Time | 69.313 ms |
| Minimum Signing Time | 30.795 ms |
| Maximum Signing Time | 456.757 ms |
| Standard Deviation | 43.804 ms |

The PQClean ML-DSA-44 clean implementation was benchmarked without modification. The observed variation represents the natural execution behaviour of the ML-DSA signature generation algorithm.


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- ML-DSA-44 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- ML-DSA signing exhibits higher variance due to probabilistic rejection sampling during signature generation.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
