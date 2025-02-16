// Include Arduino standard library to access standard functions
#include <Arduino.h>

// Speed control pins
#define motor1Speed 11

// Direction control pins
#define motor1A 5
#define motor1B 4

// Pin connection
// 5 V -> 5 V
// GND -> GND 
// ENA -> 11 
// IN1 -> 5
// IN2 -> 4 

// Speed control const
const byte equilibriumSpeed = 95; //rough estimate of PWM at the speed pin of the stronger motor, while driving straight // 155

// Current speed holder
int leftSpeedVal;

// Stop motor
void resetMotor1(){
    digitalWrite(motor1A,LOW);
    digitalWrite(motor1B,LOW);
}

// Motor moving forward
void goForwardMotor1(){
    digitalWrite(motor1A,HIGH);
    digitalWrite(motor1B,LOW);
}

// Motor part setup code
void motorSetup(){
    pinMode(motor1Speed, OUTPUT);
    pinMode(motor1A, OUTPUT);
    pinMode(motor1B, OUTPUT);
    leftSpeedVal = equilibriumSpeed;
    analogWrite(motor1Speed,leftSpeedVal);
    resetMotor1();
}