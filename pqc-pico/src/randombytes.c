#include <stddef.h>
#include <stdint.h>

#include "pico/rand.h"
#include "randombytes.h"

int PQCLEAN_randombytes(uint8_t *output, size_t n) {
    size_t i = 0;

    while (i + 4 <= n) {
        uint32_t r = get_rand_32();

        output[i++] = (uint8_t)(r);
        output[i++] = (uint8_t)(r >> 8);
        output[i++] = (uint8_t)(r >> 16);
        output[i++] = (uint8_t)(r >> 24);
    }

    if (i < n) {
        uint32_t r = get_rand_32();

        while (i < n) {
            output[i++] = (uint8_t)r;
            r >>= 8;
        }
    }

    return 0;
}
