#include<SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

char r;

int motor1back = 4;
int motor1forward = 5;
int motor2forward = 6;
int motor2back = 7;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);


  pinMode(motor1forward, OUTPUT);
  pinMode(motor1back, OUTPUT);
  pinMode(motor2forward, OUTPUT);
  pinMode(motor2back, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    r  = bluetooth.read();
    Serial.println(r);

  }

  if (r == 'F') {
    digitalWrite(motor1back, LOW); // go forward
    digitalWrite(motor2forward, HIGH);
    digitalWrite(motor1forward, HIGH);
    digitalWrite(motor2back, LOW);
  }

  else if (r == 'B') {
    digitalWrite(motor1forward, LOW); // go back
    digitalWrite(motor2back, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2forward, LOW);

  }

  else if (r == 'R') {
    digitalWrite(motor1forward, HIGH); // right turn
    digitalWrite(motor2forward, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2back, HIGH);
  }

  else if (r == 'L') {


    digitalWrite(motor1back, HIGH); // left turn
    digitalWrite(motor2back, LOW);

    digitalWrite(motor1forward, LOW);
    digitalWrite(motor2forward, HIGH );
  }

  else {
    digitalWrite(motor1forward, LOW); //stop
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2forward, LOW);
  }
}
