# HQC-256 Benchmark Results - RP2350 ARM Cortex-M33


## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | ARM Cortex-M33 |
| Core | ARM Cortex-M33 |
| ISA | ARMv8-M |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.1 |


## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | HQC-256 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | ARM Cortex-M33 Hardware Cycle Counter (`DWT CYCCNT`) |


## Functional Validation

The HQC-256 implementation was first validated by performing a complete KEM operation:

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Encapsulation | Successful |
| Decapsulation | Successful |
| Shared Secret Verification | PASS |


## Benchmark Results

Benchmark performed over **100 iterations** after **3 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 1528135 | 1528.135 | 229220243 | 1528116 | 1528386 | 26.72 |
| Encapsulation | 3073375 | 3073.375 | 461006103 | 3073349 | 3073757 | 40.29 |
| Decapsulation | 4685379 | 4685.379 | 702806664 | 4685321 | 4685732 | 40.37 |
| Total KEM | 9286975 | 9286.975 | 1393046196 | 9286879 | 9287519 | 88.88 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- HQC-256 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
