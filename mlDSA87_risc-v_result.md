# ML-DSA-87 Benchmark Results - RP2350 RISC-V


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
| Algorithm | ML-DSA-87 |
| Security Level | NIST Level 5 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | RISC-V Hardware Cycle Counter (mcycle) |


## Functional Validation

The ML-DSA-87 implementation was first validated by performing a complete signature generation and verification operation.

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Validation | PASS |


## Benchmark Results

Benchmark performed over 10,000 iterations after 100 warmup executions.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 56844 | 56.844 | 8526646 | 55919 | 57627 | 250.38 |
| Signing | 144832 | 144.832 | 21724575 | 76806 | 751704 | 78011.13 |
| Verification | 58047 | 58.047 | 8707175 | 58015 | 58520 | 10.87 |
| Total Sign | 258712 | 258.712 | 38806814 | 190942 | 894846 | 78607.77 |


## ML-DSA Signing Variability Analysis

The ML-DSA-87 signing operation exhibits higher execution-time variation compared to key generation and verification.

This behavior is expected due to the rejection sampling mechanism used during ML-DSA signature generation.

During signing, ML-DSA repeatedly generates candidate signature values and evaluates them against security constraints. If a generated candidate violates the required bounds, the candidate is rejected and a new signing attempt is performed.

Therefore, some signing operations complete after fewer rejection sampling rounds, while others require additional attempts. This results in increased maximum execution time and standard deviation.

Observed signing variability:

| Parameter | Value |
|-----------|-------|
| Mean Signing Time | 144.832 ms |
| Minimum Signing Time | 76.806 ms |
| Maximum Signing Time | 751.704 ms |
| Standard Deviation | 78.011 ms |


The PQClean ML-DSA-87 clean implementation was benchmarked without modification. The observed timing variation represents the natural execution behaviour of the ML-DSA signature generation algorithm.


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- ML-DSA-87 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution-time variation across benchmark iterations.
- ML-DSA signing exhibits higher variance due to probabilistic rejection sampling during signature generation.
- No private keys, signatures, or cryptographic material are recorded during benchmarking.
