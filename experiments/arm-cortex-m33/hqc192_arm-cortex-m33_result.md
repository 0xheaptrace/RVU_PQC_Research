# HQC-192 Benchmark Results - RP2350 ARM Cortex-M33


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
| Algorithm | HQC-192 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | ARM Cortex-M33 Hardware Cycle Counter (`DWT CYCCNT`) |


## Functional Validation

The HQC-192 implementation was first validated by performing a complete KEM operation:

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
| Key Generation | 835330 | 835.330 | 125299577 | 835313 | 835617 | 30.56 |
| Encapsulation | 1680444 | 1680.444 | 252066714 | 1680426 | 1680755 | 32.74 |
| Decapsulation | 2550865 | 2550.865 | 382629489 | 2550822 | 2551305 | 46.74 |
| Total KEM | 5066754 | 5066.754 | 760013095 | 5066705 | 5067180 | 48.61 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- HQC-192 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
