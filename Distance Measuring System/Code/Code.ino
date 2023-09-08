/*This code shows how to make a distance measuring system using Arduino
* 
* Components
* ----------
* Arduino uno, HC-SR04, LCD screen, breadboard, i2c adaptor,9 Volt battery, battery connector and some jumper 
* cables
* 
**********************************************************************************************************************************************/

#include <Wire.h>
#include <hd44780.h>                      
#include <hd44780ioClass/hd44780_I2Cexp.h> 

hd44780_I2Cexp lcd; // Declaring lcd object

const int columns = 16;  // Declare number of rows and columns on LCD screen
const int rows = 2;

const int trigPin = 9;  // Declaring pins
const int echoPin = 10;
long duration;  // Creating variables
int distance;

void setup() {
  {
    int status;

    pinMode(trigPin, OUTPUT); // Declares trigPin as an output
    pinMode(echoPin, INPUT); // Declares echoPin as an input

    Serial.begin(9600);

    status = lcd.begin(columns, rows);
    if (status) // non zero status means it was unsuccesful
    {
      hd44780::fatalError(status);
    }
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);  // Turns on the trigPin for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds

  distance = duration * 0.0343 / 2;  // Calculating the distance

  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(9, 0);
  lcd.print(distance);
  lcd.setCursor(14, 0);
  lcd.print("cm");

  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.setCursor(9, 1);
  lcd.print(distance * 0.0328084);
  lcd.setCursor(14, 1);
  lcd.print("ft");
  delay(1000);
  lcd.clear();

  Serial.println(distance);
}
