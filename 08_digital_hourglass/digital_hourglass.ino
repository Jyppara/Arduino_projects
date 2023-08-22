// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 08: Digital Hourglass
// Description: Building a digital hourglass that turns an LED every ten minutes. Resets by tilting the hourglass.

const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 600000; // 10 minutes

void setup()
{
    for (int x = 2; x < 8; x++)
    {
        pinMode(x, OUTPUT);
    }

    pinMode(switchPin, INPUT);
}

void loop()
{

    unsigned long currentTime = millis();
    if (currentTime - previousTime > interval)
    {
        previousTime = currentTime;
        digitalWrite(led, HIGH);
        led++;
        switchState = digitalRead(switchPin);
        if (switchState != prevSwitchState)
        {
            for (int x = 2; x < 8; x++)
            {
                digitalWrite(x, LOW);
            }

            led = 2;
            previousTime = currentTime;
        }
        prevSwitchState = switchState;
    }
}