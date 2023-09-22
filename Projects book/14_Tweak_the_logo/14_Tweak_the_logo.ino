// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 14: Tweak the Logo
// Description: Using serial communication, you'll use your Arduino to control a program on your computer.

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.write(analogRead(A0) / 4);
    delay(100);
}