#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "mlkem_demo.h"
#include "benchmark.h"


int main(void)
{
    stdio_init_all();

    while (!stdio_usb_connected())
    {
        sleep_ms(100);
    }

    sleep_ms(1000);

    mlkem_demo();

    run_mlkem512_benchmark();

    while (true)
    {
        tight_loop_contents();
    }
}
