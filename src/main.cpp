#include <Arduino.h>
#define rainAnalog A0
#define rainDigital D1

void setup() {
 Serial.begin(9600);
  pinMode(rainDigital,INPUT);
}
}

void loop() {
int rainAnalogVal = analogRead(rainAnalog);
  boolean bIsRaining = !(digitalRead(rainDigital));

  Serial.println(rainAnalogVal);
  delay(200);
}
