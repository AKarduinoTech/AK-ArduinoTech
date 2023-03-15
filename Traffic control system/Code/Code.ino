/*This code shows how to make a traffic control system using Arduino
* 
* Components
* ----------
* Arduino uno, 2 servo motors, 2 traffic signal modules, breadboard and some jumper cables
* 
**********************************************************************************************************************************************/


#include <Servo.h>

int red1 = 5;      //declaring the pins to which the leds of the traffic signal modules are connected
int red2 = 2;
int yellow1 = 6;
int yellow2 = 3;
int green1 = 7;
int green2 = 4;

Servo myservo1;  // creating servo objects to control the servos
Servo myservo2;

void setup() {
pinMode(red1, OUTPUT);     //declaring the pins of the traffic signal modules as output devices
pinMode(red2, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(green2, OUTPUT);

myservo1.attach(10);  // attaching the servos to the servo object
myservo2.attach(11);  
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

delay(7000);

digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
myservo2.write(90);
myservo1.write(90);


delay(4000);

digitalWrite(red1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(yellow1, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green1, HIGH);
digitalWrite(green2, LOW);
myservo2.write(0);
myservo1.write(90);

delay(7000);

digitalWrite(red1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(green1, LOW);
digitalWrite(green2, LOW);
myservo2.write(90);
myservo1.write(90);

delay(4000);

}
