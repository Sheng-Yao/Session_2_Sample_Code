// Include Arduino standard library to access standard functions
#include <Arduino.h>

// Pin connection
// VCC -> 5 V
// GND -> GND 
// TRIG -> 8
// ECHO -> 9

// Front ultrasonic sensor
#define frontTrig 8
#define frontEcho 9

// Ultrasonic part setup code
void ultrasonicSetup(){
    pinMode(frontEcho, INPUT);
    pinMode(frontTrig, OUTPUT);
}

// Return distance in cm
float getDistance(){
    digitalWrite(frontTrig,LOW);
    delay(2);
    digitalWrite(frontTrig,HIGH);
    delay(10);
    digitalWrite(frontTrig,LOW);
    return (pulseIn(frontEcho,HIGH) * 0.034613 / 2.00);
}