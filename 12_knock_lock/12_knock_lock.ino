// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 12: Knock Lock
// Description: Create a knock lock to open a lock by using a piezo sensor and a servo motor.

#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

boolean checkForKnock(int value)
{
    if (value > quietKnock && value < loudKnock)
    {
        digitalWrite(yellowLed, HIGH);
        delay(50);
        digitalWrite(yellowLed, LOW);
        Serial.println("Valid knock of value");
        Serial.println(value);
        return true;
    }
    else
    {
        Serial.println("Bad knock value");
        Serial.println(value);
        return false;
    }
}

void setup()
{
    myServo.attach(9);
    pinMode(switchPin, INPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    Serial.begin(9600);
    Serial.println("The lock is unlocked.");
}

void loop()
{
    if (locked == false)
    {
        switchVal = digitalRead(switchPin);
        if (switchVal == HIGH)
        {
            locked = true;
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
            myServo.write(90);
            Serial.println("The lock is locked.");
            delay(1000);
        }
    }
    if (locked == true)
        knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0)
    {
        if (checkForKnock(knockVal) == true)
        {
            numberOfKnocks++;
        }
        Serial.print(3 - numberOfKnocks);
        Serial.println(" more knocks to go");
    }
    if (numberOfKnocks >= 3)
    {
        locked = false;
        myServo.write(0);
        delay(2000);
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        Serial.println("The lock is unlocked.");
        numberOfKnocks = 0;
    }
}
