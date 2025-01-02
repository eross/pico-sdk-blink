/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 2;
const uint MOT_IND = 10;
const uint MOTION_IN = 16;

int main() 
{
    uint motion = 0;
    //stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(MOT_IND);
    gpio_init(MOTION_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(MOT_IND, GPIO_OUT);
    gpio_set_dir(MOTION_IN, GPIO_IN);

    while (true) {
        gpio_put(LED_PIN, 1);
   
        motion = gpio_get(MOTION_IN);
        gpio_put(MOT_IND, motion);
   
        sleep_ms(300);
   
        printf("LED on\n");
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
 
        printf("LED off\n");
        sleep_ms(250);
    }
    return 0;
}
