# ML-KEM-512 Benchmark Results - RP2350 ARM Cortex-M33


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
| Algorithm | ML-KEM-512 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | ARM Cortex-M33 DWT CYCCNT Hardware Cycle Counter |


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
| Key Generation | 4840 | 4.840 | 726008 | 4828 | 5067 | 20.75 |
| Encapsulation | 5586 | 5.586 | 837953 | 5575 | 5783 | 3.30 |
| Decapsulation | 6767 | 6.767 | 1015027 | 6762 | 7009 | 2.99 |
| Total KEM | 17256 | 17.256 | 2588532 | 17215 | 17932 | 62.29 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-KEM-512 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No private keys, ciphertexts, or shared secrets are recorded during benchmarking.
