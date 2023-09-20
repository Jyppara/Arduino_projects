// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 13: Touchy-Feely Lamp
// Description: Create a lamp that turns on when you touch a piece of conductive material.

#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

int threshold = 1000;
const int ledPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  delay(150);
}