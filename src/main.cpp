#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

int count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello" + String(count));
  count++;
}
