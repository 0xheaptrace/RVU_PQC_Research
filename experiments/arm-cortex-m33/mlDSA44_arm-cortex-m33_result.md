# ML-DSA-44 Benchmark Results - RP2350 ARM Cortex-M33


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
| Algorithm | ML-DSA-44 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | ARM Cortex-M33 Hardware Cycle Counter (`DWT CYCCNT`) |


## Functional Validation

The ML-DSA-44 implementation was first validated by performing a complete digital signature workflow:

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
| Key Generation | 17680 | 17.680 | 2652066 | 17122 | 18165 | 182.29 |
| Signature Generation | 55693 | 55.693 | 8353992 | 25763 | 339048 | 34117.87 |
| Verification | 18126 | 18.126 | 2718928 | 18117 | 18466 | 5.44 |
| Total Sign | 91495 | 91.495 | 13724310 | 61074 | 350785 | 33990.55 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-DSA-44 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT `CYCCNT` hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- Signature generation shows higher variance due to the rejection sampling mechanism used in ML-DSA.
- No private keys, signatures, or message data are recorded during benchmarking.
