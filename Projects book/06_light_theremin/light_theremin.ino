// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 06: Light Theremin
// Description: Using a phototransistor and a piezo element, you can make a simple light-based theremin.

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    while (millis() < 5000)
    {
        sensorValue = analogRead(A0);
        if (sensorValue > sensorHigh)
        {
            sensorHigh = sensorValue;
        }
        if (sensorValue < sensorLow)
        {
            sensorLow = sensorValue;
        }
    }
    digitalWrite(ledPin, LOW);
}

void loop()
{
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);
    delay(10);
}
