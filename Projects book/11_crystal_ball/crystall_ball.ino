// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 11: Crystal Ball
// Description: Create a crystall ball to tell your future by using an LCD-screen and a tilt switch.

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup()
{
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop()
{
  switchState = digitalRead(switchPin);
  if (switchState != digitalRead(switchPin))
  {
    if (switchState == LOW)
    {
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The Ball Says:");
      lcd.setCursor(0, 1);

      switch (reply)
      {
      case 0:
        lcd.print("Yes");
        break;
      case 1:
        lcd.print("Most likely");
        break;
      case 2:
        lcd.print("Certainly");
        break;
      case 3:
        lcd.print("Outlook good");
        break;
      case 4:
        lcd.print("Unsure");
        break;
      case 5:
        lcd.print("Ask again");
        break;
      case 6:
        lcd.print("Doubtful");
        break;
      case 7:
        lcd.print("No");
        break;
      }
    }
  }
}
