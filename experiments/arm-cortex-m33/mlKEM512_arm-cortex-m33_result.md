# ML-KEM-512 Benchmark Results - RP2350 ARM Cortex-M33


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
| Algorithm | ML-KEM-512 |
| Implementation | PQClean Clean |
| Platform | Raspberry Pi Pico 2 W (RP2350) |
| Build Type | Release |
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Measurement Method | ARM Cortex-M33 Hardware Cycle Counter (`DWT CYCCNT`) |


## Functional Validation

The ML-KEM-512 implementation was first validated by performing a complete KEM operation:

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
| Key Generation | 4843 | 4.843 | 726507 | 4830 | 5158 | 37.52 |
| Encapsulation | 5587 | 5.587 | 838161 | 5577 | 5814 | 23.30 |
| Decapsulation | 6768 | 6.768 | 1015207 | 6761 | 7028 | 27.09 |
| Total KEM | 17249 | 17.249 | 2587444 | 17223 | 17602 | 59.00 |


## Notes

- Benchmark executed on Raspberry Pi Pico 2 W using the RP2350 ARM Cortex-M33 processor.
- ML-KEM-512 implementation is based on the PQClean Clean implementation.
- Cycle measurements were obtained directly using the ARM Cortex-M33 DWT CYCCNT hardware cycle counter.
- Execution time measurements were collected using the RP2350 system timer.
- Results represent 100 benchmark iterations after 3 warmup iterations.
- Standard deviation represents execution time variation across benchmark iterations.
- No cryptographic keys, ciphertexts, or shared secrets are recorded during benchmarking.
