int switchState = 0;

void setup()
{
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(2, INPUT);
}

void loop()
{
    switchCase = digitalRead(2);
    if (switchState == LOW)
    {
        // the button is not pressed
        digitalWrite(3, HIGH); // green LED
        digitalWrite(4, LOW);  // red LED
        digitalWrite(5, LOW);  // red LED
    }
    else
    { // the button is pressed
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(250); // wait for a quarter second
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(250); // wait for a quarter second
    }
}       // end of loop