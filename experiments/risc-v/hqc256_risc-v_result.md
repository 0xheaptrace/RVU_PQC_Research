# HQC-256 Benchmark Results

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
| Key Generation | 1455466 | 1455.466 | 218319880 | 1455444 | 1455854 | 41.76 |
| Encapsulation | 2931730 | 2931.730 | 439759495 | 2931704 | 2932269 | 56.70 |
| Decapsulation | 4475285 | 4475.285 | 671292583 | 4475240 | 4475783 | 53.14 |
| Total KEM | 8862752 | 8862.752 | 1329412728 | 8862678 | 8863203 | 51.95 |

---

## Observations

- HQC-256 represents the highest NIST security category among the evaluated HQC parameter sets.
- Decapsulation is the most computationally expensive operation, requiring approximately **4.48 seconds** on the RP2350 platform.
- The complete KEM operation (Key Generation + Encapsulation + Decapsulation) requires approximately **8.86 seconds**.
- Compared with HQC-128, HQC-256 introduces increased computational cost due to larger security parameters while remaining executable on constrained IoT hardware.
