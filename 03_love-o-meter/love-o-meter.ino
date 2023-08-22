// Author: JYRI MÄÄTTÄ
// PROJECTS BOOK, Project 03: Love-O-Meter
// Description: Using an analog input you're going to make a love-o-meter and see how hot-blooded you are.

const int sensorPin = A0;        // select the input pin for the potentiometer
const float baselineTemp = 20.0; // room temperature in Celsius
void setup()
{
    Serial.begin(9600); // use the serial port
    for (int pinNumber = 2; pinNumber < 5; pinNumber++)
    {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop()
{
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);
    // convert the ADC reading to voltage
    float voltage = (sensorVal / 1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);
    // convert the voltage to temperature in degrees C
    float temperature = (voltage - .5) * 100;
    Serial.print(", degrees C: ");
    Serial.println(temperature);
    if (temperature < baselineTemp + 2)
    {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 6)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(1); // delay in between reads for stability
} // end of loop