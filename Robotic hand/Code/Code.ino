/*This code shows how to make a robotic hand using Arduino
 * 
 * Components
 * ----------
 * Arduino uno, 4 servo motors, Wooden sticks, , 4 AA cells, battery holder, battery connectors and jumper wires
 * 
 ********************************************************************************************************************/

#include <Servo.h>

Servo myservo1;  // creating servo object to control servo 1
Servo myservo2;  
Servo myservo3;  
Servo myservo4;  


int potpin1 = A0;  // declaring the analog pins used to connect the potentiometers
int potpin2 = A1;
int potpin3 = A2;
int potpin4 = A3;

int val1;    // creating variables to read the value from the analog pins
int val2;    
int val3;    
int val4;    


void setup() {
  myservo1.attach(3);  // attaching the servo on pin 3 to the servo object
  myservo2.attach(5);  // attaching the servo on pin 5 to the servo object
  myservo3.attach(6);  // attaching the servo on pin 6 to the servo object
  myservo4.attach(9);  // attaching the servo on pin 9 to the servo object

}

void loop() {
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  delay(15);                             
  
  val2 = analogRead(potpin2);            
  val2 = map(val2, 0, 1023, 0, 180);     
  myservo2.write(val2);                  
  delay(15);  
  
  val3 = analogRead(potpin3);            
  val3 = map(val3, 0, 1023, 0, 180);     
  myservo3.write(val3);                  
  delay(15);  
    
  val4 = analogRead(potpin4);            
  val4 = map(val4, 0, 1023, 0, 180);     
  myservo4.write(val4);                  
  delay(15);  
}
