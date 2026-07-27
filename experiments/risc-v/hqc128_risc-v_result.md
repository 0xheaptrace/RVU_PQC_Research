# HQC-128 Benchmark Results

## Platform Information

| Parameter | Value |
|---|---|
| Device | Raspberry Pi Pico 2 W |
| MCU | RP2350 |
| Core | Hazard3 |
| Architecture | RISC-V |
| XLEN | 32-bit |
| Compiler | GCC 15.2.0 |
| Implementation | PQClean Clean Implementation |

---

## Benchmark Configuration

| Parameter | Value |
|---|---|
| Warmup Iterations | 3 |
| Benchmark Iterations | 100 |
| Cycle Counter | RISC-V mcycle |

---

## Performance Results

| Operation | Mean (us) | Mean (ms) | Cycles | Min (us) | Max (us) | Std Dev |
|---|---:|---:|---:|---:|---:|---:|
| Key Generation | 260459 | 260.459 | 39068978 | 260448 | 260852 | 41.13 |
| Encapsulation | 527726 | 527.726 | 79158753 | 527702 | 528218 | 51.01 |
| Decapsulation | 817452 | 817.452 | 122617614 | 817410 | 817995 | 56.61 |
| Total KEM | 1605926 | 1605.926 | 240888725 | 1605876 | 1606523 | 63.07 |
