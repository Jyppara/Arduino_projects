// Author: Jyri Määttä
// PROJECTS BOOK, Project 09: Motorized Pinwheel
// Description: Get the Arduino to spin a colourful pinwheel using a motor.

const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup()
{
    pinMode(switchPin, INPUT);
    pinMode(motorPin, OUTPUT);
}

void loop()
{
    switchState = digitalRead(switchPin);
    if (switchState == HIGH)
    {
        digitalWrite(motorPin, HIGH);
    }
    else
    {
        digitalWrite(motorPin, LOW);
    }
}