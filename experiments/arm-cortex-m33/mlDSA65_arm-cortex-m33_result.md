# ML-DSA-65 Benchmark Results - RP2350 ARM Cortex-M33


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
| Algorithm | ML-DSA-65 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 100 |
| Benchmark Iterations | 10000 |
| Measurement Method | ARM Cortex-M33 DWT CYCCNT Hardware Cycle Counter |


## Functional Validation

The ML-DSA-65 implementation was first validated by performing a complete digital signature operation:

| Operation | Result |
|-----------|--------|
| Key Generation | Successful |
| Signature Generation | Successful |
| Signature Verification | Successful |
| Signature Verification Check | PASS |


## Benchmark Results

Benchmark performed over **10,000 iterations** after **100 warmup executions**.

| Operation | Mean (µs) | Mean (ms) | Cycles | Min (µs) | Max (µs) | Std Dev |
|-----------|-----------|-----------|--------|----------|----------|---------|
| Key Generation | 30979 | 30.979 | 4646880 | 30966 | 31307 | 5.66 |
| Signature Gen | 90758 | 90.758 | 13613725 | 40762 | 527558 | 54813.94 |
| Verification | 30647 | 30.647 | 4597170 | 30637 | 30964 | 4.39 |
| Total Sign | 151907 | 151.907 | 22786099 | 102442 | 600057 | 54595.88 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-DSA-65 implementation is based on the PQClean Clean implementation.
- CPU cycle measurements were obtained directly from the ARM Cortex-M33 DWT CYCCNT hardware counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 10,000 benchmark iterations after 100 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- Signature generation shows higher variance due to the probabilistic rejection sampling behavior of ML-DSA.
- No private keys, public keys, signatures, or messages are recorded during benchmarking.
