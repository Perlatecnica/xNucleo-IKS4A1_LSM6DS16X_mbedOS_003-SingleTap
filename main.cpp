/*
MIT License

Copyright (c) [2024] 
Organization: Perlatecnica APS ETS
Author: Mauro D'Angelo
Example to use the LSM6DSV16X Single Tap Detection

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "mbed.h"
#include "LSM6DSV16X.h"

LSM6DSV16X AccGyr(I2C_SDA, I2C_SCL); 
Serial pc(USBTX, USBRX);
DigitalOut led(LED1);

//Interrupts.
volatile int mems_event = 0;

char report[256];

void INT1Event_cb();

InterruptIn intPin(D5);

// main() runs in its own thread in the OS
int main()
{
    // Initialize serial for output.
    pc.baud(115200);
    
    //Interrupts.
    intPin.rise(&INT1Event_cb);

    AccGyr.begin();
    AccGyr.Enable_X();
    AccGyr.Enable_Single_Tap_Detection(LSM6DSV16X_INT1_PIN);

    while (true) {
        if (mems_event)
        {
            mems_event=0;
            LSM6DSV16X_Event_Status_t status;
            AccGyr.Get_X_Event_Status(&status);
            if (status.TapStatus)
            {
            // Output data.
            pc.printf("Single Tap Detected!\r\n");

            // Led blinking.
            led = 1;
            thread_sleep_for(100);
            led = 0;
            }
        }
    }
}

void INT1Event_cb()
{
  mems_event = 1;
}

