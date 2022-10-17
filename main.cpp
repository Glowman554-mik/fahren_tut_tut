/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define FULL_CIRCLE 360
#define TIME_FOR_360 1450

DigitalOut bl(PC_0);
DigitalOut br(PC_6);
DigitalOut fl(PC_1);
DigitalOut fr(PC_7);

void rotate(float deg) {
	fl = true;
	br = true;

	float tmp = (deg / FULL_CIRCLE) * TIME_FOR_360;
	ThisThread::sleep_for((int) tmp);

	fl = false;
	br = false;
}

DigitalOut led(LED1);

int main() {
	rotate(360);
	// fr = true;
    while (true) {
        ThisThread::sleep_for(200ms);
        led = !led;
    }
}
