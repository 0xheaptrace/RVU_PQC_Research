# ML-KEM-768 Benchmark Results - RP2350 RISC-V


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
| Algorithm | ML-KEM-768 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | RISC-V Hardware Cycle Counter (`mcycle`) |


## Functional Validation

The ML-KEM-768 implementation was first validated by performing a complete KEM operation:

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
| Key Generation | 8454 | 8.454 | 1268228 | 8438 | 8847 | 32.89 |
| Encapsulation | 9536 | 9.536 | 1430482 | 9529 | 9947 | 4.75 |
| Decapsulation | 11225 | 11.225 | 1683846 | 11218 | 11670 | 5.15 |
| Total KEM | 29269 | 29.269 | 4390244 | 29214 | 29977 | 99.75 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 Hazard3 RISC-V processor.
- ML-KEM-768 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the RISC-V `mcycle` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
