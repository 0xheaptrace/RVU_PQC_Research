# ML-DSA-65 Benchmark Results - RP2350 RISC-V


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
| Algorithm | ML-DSA-65 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |


## Functional Validation

The ML-DSA-65 implementation was first validated by performing a complete signature generation and verification operation:

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
| Key Generation | 33827 | 33.827 | 5074103 | 33791 | 34225 | 11.26 |
| Signing | 116308 | 116.308 | 17446044 | 48483 | 680505 | 74146.97 |
| Verification | 34392 | 34.392 | 5158924 | 34364 | 34829 | 9.96 |
| Total Sign | 184696 | 184.696 | 27704416 | 116683 | 858918 | 75250.30 |


## ML-DSA Signing Variability Analysis

The ML-DSA-65 signing operation exhibits significantly higher execution-time variation compared to key generation and verification.

This behaviour is expected due to the rejection sampling mechanism used during ML-DSA signature generation. During signing, the algorithm repeatedly generates candidate values and evaluates multiple security constraints. If a generated candidate does not satisfy the required norm bounds, the candidate is rejected and the signing process repeats with fresh randomness.

The number of rejection sampling rounds is probabilistic and can vary between executions. Therefore, some signatures complete after fewer sampling attempts, while others require additional iterations before producing an acceptable signature.

The observed signing variability:

| Parameter | Value |
|-----------|-------|
| Mean Signing Time | 116.308 ms |
| Minimum Signing Time | 48.483 ms |
| Maximum Signing Time | 680.505 ms |
| Standard Deviation | 74.147 ms |


The PQClean ML-DSA-65 clean implementation was benchmarked without modification. No changes were made to the signing procedure, rejection sampling process, or cryptographic implementation. The observed timing variation represents the natural execution behaviour of ML-DSA signature generation.


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- ML-DSA-65 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- ML-DSA signing exhibits higher variance due to probabilistic rejection sampling during signature generation.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.

