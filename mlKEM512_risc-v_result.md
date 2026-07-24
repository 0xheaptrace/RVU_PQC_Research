# ML-KEM-512 Benchmark Results - RP2350 RISC-V


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
| Algorithm | ML-KEM-512 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |


## Functional Validation

The ML-KEM-512 implementation was first validated by performing a complete KEM operation:

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Encapsulation | Successful |
| Decapsulation | Successful |
| Shared Secret Verification | PASS |


## Benchmark Results

Benchmark performed over **10,000 iterations** after **100 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 5166 | 5.166 | 774948 | 5151 | 5513 | 23.21 |
| Encapsulation | 5839 | 5.839 | 875846 | 5832 | 6254 | 4.78 |
| Decapsulation | 7092 | 7.092 | 1063929 | 7089 | 7541 | 4.84 |
| Total KEM | 18148 | 18.148 | 2722192 | 18112 | 18866 | 67.41 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- ML-KEM-512 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
