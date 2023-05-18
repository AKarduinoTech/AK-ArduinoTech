/*This sketch shows you how to make a joystick controlled car using Arduino.
 * 
 * Components
 * ----------
 * Arduino uno, L298N, joystick, chassis, wheels, 2 Motors, 2 9V batteries, battery connectors and jumper  
 * wires
 *
 * This sketch is created by Anuj Karnik.
 **********************************************************************************************************************/

 
int x = A0;
int y = A1;

int motor1back = 4;
int motor1forward = 5;
int motor2forward = 6;
int motor2back = 7;

void setup() {
  pinMode(motor1forward, OUTPUT);
  pinMode(motor1back, OUTPUT);
  pinMode(motor2forward, OUTPUT);
  pinMode(motor2back, OUTPUT);

  pinMode(x, INPUT);
  pinMode(y, INPUT);
}

void loop() {
  int yValue = analogRead(y);
  int xValue = analogRead(x);

  if (yValue == 0) {
    digitalWrite(motor1back, HIGH); // right turn
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1forward, LOW);
    digitalWrite(motor2forward, HIGH );
  }
  else if (yValue == 1023) {
    digitalWrite(motor1forward, HIGH); // left turn
    digitalWrite(motor2forward, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2back, HIGH);
  }
  else if (xValue == 0) {
    digitalWrite(motor1back, LOW); // go forward
    digitalWrite(motor2forward, HIGH);
    digitalWrite(motor1forward, HIGH);
    digitalWrite(motor2back, LOW);
  }
  else if (xValue == 1023) {
    digitalWrite(motor1forward, LOW); // go back
    digitalWrite(motor2back, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2forward, LOW);
  }
  else {
    digitalWrite(motor1forward, LOW); //stop
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2forward, LOW);
  }
}
