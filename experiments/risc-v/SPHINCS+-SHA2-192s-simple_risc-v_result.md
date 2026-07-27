# SPHINCS+-SHA2-192s-simple Benchmark Results

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
| Warmup Iterations | 1 |
| Benchmark Iterations | 10 |
| Cycle Counter | RISC-V mcycle |

---

## Performance Results

| Operation | Mean (us) | Mean (ms) | Cycles | Min (us) | Max (us) | Std Dev |
|---|---:|---:|---:|---:|---:|---:|
| Key Generation | 27630985 | 27630.985 | 4144647670 | 27630255 | 27631995 | 655.79 |
| Signing | 840294741 | 840294.741 | 126044211095 | 840287033 | 840304662 | 5298.81 |
| Verification | 851555 | 851.555 | 127733133 | 851377 | 851738 | 98.89 |
| Total Sign | 868772451 | 868772.451 | 130315867603 | 868763902 | 868783076 | 7267.38 |

---

## Observations

- SPHINCS+-SHA2-192s-simple shows a significant increase in computational cost compared to SPHINCS+-SHA2-128s-simple due to the higher security level.
- Signature generation remains the dominant operation, requiring approximately **840 seconds (~14 minutes)** on the RP2350 platform.
- Verification cost increases to approximately **851 ms**, making it considerably heavier than the Level 1 variant.
- Key generation requires approximately **27.6 seconds**.
- The benchmark was executed with reduced iterations due to the high computational overhead of SPHINCS+ on constrained hardware.
