#include <Arduino.h>
#include <Memory.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  memoryReset();
  memoryWrite("Maze Competition");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(String(memoryRead()));
  delay(10000);
}
