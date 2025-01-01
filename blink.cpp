/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 2;
const uint MOT_IND = 10;

int main() 
{
    //stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(MOT_IND);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(MOT_IND, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        gpio_put(MOT_IND, 0);
        sleep_ms(300);
   
        printf("LED on\n");
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        gpio_put(MOT_IND, 1);
        sleep_ms(250);
 
        printf("LED off\n");
        sleep_ms(250);
    }
    return 0;
}
