# ML-KEM-768 Benchmark Results - RP2350 ARM Cortex-M33


## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | ARM Cortex-M33 |
| Core | RP2350 Cortex-M33 |
| ISA | ARMv8-M |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.1 |


## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | ML-KEM-768 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | ARM Cortex-M33 DWT CYCCNT Hardware Cycle Counter |


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
| Key Generation | 7912 | 7.912 | 1186824 | 7895 | 8244 | 31.00 |
| Encapsulation | 9082 | 9.082 | 1362336 | 9073 | 9311 | 3.52 |
| Decapsulation | 10670 | 10.670 | 1600446 | 10665 | 10977 | 3.56 |
| Total KEM | 27752 | 27.752 | 4162902 | 27692 | 28426 | 92.20 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-KEM-768 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No private keys, ciphertexts, or shared secrets are recorded during benchmarking.
