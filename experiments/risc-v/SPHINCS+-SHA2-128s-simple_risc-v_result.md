# SPHINCS+-SHA2-128s-simple Benchmark Results

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
| Key Generation | 10961131 | 10961.131 | 1644169540 | 10960294 | 10962287 | 600.16 |
| Signing | 83396622 | 83396.622 | 12509493335 | 83394263 | 83398083 | 1156.77 |
| Verification | 79830 | 79.830 | 11974352 | 79685 | 80609 | 261.05 |
| Total Sign | 94439228 | 94439.228 | 14165884133 | 94434874 | 94442968 | 2241.80 |

---

## Observations

- SPHINCS+-SHA2-128s demonstrates significantly higher signing latency compared to lattice-based signature schemes such as ML-DSA and Falcon due to its hash-based construction.
- Signature generation is the dominant operation, taking approximately **83.4 seconds** on the RP2350 platform.
- Verification is comparatively faster, completing in approximately **79.8 ms**.
- The benchmark was performed with reduced iterations due to the computational cost of SPHINCS+ operations on constrained hardware.
