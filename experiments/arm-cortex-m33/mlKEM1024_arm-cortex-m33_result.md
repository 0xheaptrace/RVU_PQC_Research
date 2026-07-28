# ML-KEM-1024 Benchmark Results - RP2350 ARM Cortex-M33


## Processor Information

| Parameter | Value |
|-----------|-------|
| Architecture | ARM Cortex-M33 |
| Core | RP2350 Cortex-M33 |
| CPU Clock | 150 MHz |
| Compiler | GCC 15.2.1 |
| Cycle Counter | ARM Cortex-M33 DWT CYCCNT |


## Benchmark Configuration

| Parameter | Value |
|-----------|-------|
| Algorithm | ML-KEM-1024 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | ARM Cortex-M33 Hardware Cycle Counter (`DWT CYCCNT`) |


## Functional Validation

The ML-KEM-1024 implementation was first validated by performing a complete KEM operation:

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
| Key Generation | 12462 | 12.462 | 1869424 | 12436 | 12720 | 46.57 |
| Encapsulation | 13778 | 13.778 | 2066792 | 13770 | 14059 | 28.78 |
| Decapsulation | 15838 | 15.838 | 2375777 | 15831 | 16111 | 28.94 |
| Total KEM | 42193 | 42.193 | 6329015 | 42095 | 42830 | 177.74 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-KEM-1024 implementation is based on the PQClean Clean implementation.
- Cycle measurements were obtained directly using the ARM Cortex-M33 DWT CYCCNT hardware cycle counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
