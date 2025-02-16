// Include Arduino standard library to access standard functions
#include <Arduino.h>

#define encoderPinA 2

// Pin connection
// 5 V -> 5 V
// GND -> GND 
// D0 -> 2 

volatile byte pulses = 0;

void counterUpdate()
{
    pulses++;
}

void encoderSetup(){
  // Set encoder pins as input with pull-up resistors
  pinMode(encoderPinA, INPUT); 

  // Attach interrupts to the encoder pins
  attachInterrupt(digitalPinToInterrupt(encoderPinA), counterUpdate, RISING);
}

// This equation is slightly different from what can be obtained online.
const float wheelCircumference = 0.05 * PI * 0.0325 * 100;

float getMovingDistance(){
    noInterrupts();

    // TIPS: ((pulsesLeft + pulsesRight) / 2) * wheelCircumference seems ok to use it
    float distance = pulses * wheelCircumference;

    //Restart the interrupt processing
    interrupts();

    return distance;
}

void resetDistance(){
    pulses = 0;
}

// How to use?
// encoderSetup(); in setup

// Serial.println(String(getMovingDistance())); to access the distance travel
// resetDistance(); once you want to reset the distance counter