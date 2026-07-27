# SPHINCS+-SHA2-256s-simple Benchmark Results

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
| Benchmark Iterations | 1 |
| Cycle Counter | RISC-V mcycle |

---

## Performance Results

| Operation | Mean (us) | Mean (ms) | Cycles | Min (us) | Max (us) | Std Dev |
|---|---:|---:|---:|---:|---:|---:|
| Key Generation | 19663569 | 19663.569 | 2949534978 | 19663569 | 19663569 | 0.00 |
| Signing | 994794361 | 994794.361 | 149219153819 | 994794361 | 994794361 | 0.00 |
| Verification | 1173813 | 1173.813 | 176071639 | 1173813 | 1173813 | 0.00 |
| Total Sign | 1015624115 | 1015624.115 | 152343617058 | 1015624115 | 1015624115 | 0.00 |

---

## Observations

- SPHINCS+-SHA2-256s-simple represents the highest NIST security category among the tested SPHINCS+ SHA2 small variants.
- Signature generation remains the dominant operation, requiring approximately **995 seconds (~16.6 minutes)** on the RP2350 platform.
- Verification requires approximately **1.17 seconds**, while key generation completes in approximately **19.7 seconds**.
- Due to the computational cost of SPHINCS+-SHA2-256s-simple, benchmarking was performed using a single iteration.
- The results demonstrate the significant computational overhead of hash-based signatures at higher security levels on constrained IoT devices.

