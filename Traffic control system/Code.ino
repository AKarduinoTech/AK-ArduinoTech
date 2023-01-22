#include <Servo.h>

int red1 = 5;
int red2 = 2;
int yellow1 = 6;
int yellow2 = 3;
int green1 = 7;
int green2 = 4;

Servo myservo1;  // creating servo objects to control the servos
Servo myservo2;

void setup() {
pinMode(red1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(green2, OUTPUT);

myservo1.attach(10);  // attaching the servo on pin 3 to the servo object
myservo2.attach(11);  // attaching the servo on pin 5 to the servo object
}

void loop() {
digitalWrite(red1, HIGH);
digitalWrite(red2, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green1, LOW);
digitalWrite(green2, HIGH);
myservo2.write(90);
myservo1.write(0);

delay(5000);

digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
myservo2.write(90);
myservo1.write(90);


delay(5000);

digitalWrite(red1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green1, HIGH);
digitalWrite(green2, LOW);
myservo2.write(0);
myservo1.write(90);

delay(5000);

digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
myservo2.write(90);
myservo1.write(90);

delay(5000);

}
