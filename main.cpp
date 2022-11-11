/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PinNames.h"
#include "ThisThread.h"
#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut led(PA_15);
float duty_cycle = 0.05f;
int direction = 1;

int main()
{
    
    // specify period first
    led.period(0.02f);      // 4 second period
    //led = 0.5f;          // shorthand for led.write()
    //led.pulsewidth(2);   // alternative to led.write, set duty cycle time in seconds
    while (1)
    {
        if (duty_cycle > 2.5f/20.0f || duty_cycle < 0.5f/20.0f) direction *= -1;
        duty_cycle += 0.0002f * direction;
        led.write(duty_cycle);      // 50% duty cycle, relative to period
        // ThisThread::sleep_for(10);
        printf("%d\n", (int)(duty_cycle * 1000));
    }
}
