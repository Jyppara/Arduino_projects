#include <Servo.h>
Servo myServo; 

int const potPin = A0; // potentiometer pin
int potVal; // potentiometer value
int angle; // servo angle

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  potVal = analogRead(potPin); // reads the value of the potentiometer (value between 0 and 1023)
  angle = map(potVal, 0, 1023, 0, 179); // scale it to use it with the servo (value between 0 and 180)
  myServo.write(angle); // sets the servo position according to the scaled value
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print(" angle: ");
  Serial.println(angle);
  myServo.write(angle); // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
}