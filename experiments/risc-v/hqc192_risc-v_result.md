# HQC-192 Benchmark Results

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
| Key Generation | 795470 | 795.470 | 119320475 | 795460 | 795813 | 36.32 |
| Encapsulation | 1602830 | 1602.830 | 240424345 | 1602811 | 1603301 | 48.92 |
| Decapsulation | 2434655 | 2434.655 | 365198157 | 2434622 | 2435091 | 46.44 |
| Total KEM | 4833232 | 4833.232 | 724984680 | 4833179 | 4833721 | 53.54 |

---

## Observations

- HQC-192 demonstrates the expected increase in computational cost compared with HQC-128 due to the higher security parameter set.
- Decapsulation remains the most expensive individual operation.
- Total KEM execution requires approximately **4.83 seconds** on the RP2350 platform.
- The implementation remains practical for constrained IoT-class hardware despite increased security requirements.
