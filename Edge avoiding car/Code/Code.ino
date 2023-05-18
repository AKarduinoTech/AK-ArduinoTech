/*This sketch shows you how to make an edge avoiding car using Arduino.
 * 
 * Components
 * ----------
 * Arduino uno, L298N, Ultrasonic sensor, chassis, wheels, 2 Motors, 2 9V batteries, battery connectors and jumper wires
 *
 * This sketch is created by Anuj Karnik.
 **********************************************************************************************************************/

 
int motor1forward = 4;
int motor1back = 5;
int motor2back = 6;
int motor2forward = 7;

int trigPin = 13;
int echoPin = 12;
void setup() {
  pinMode(motor1back, OUTPUT);
  pinMode(motor1forward, OUTPUT);
  pinMode(motor2back, OUTPUT);
  pinMode(motor2forward, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  long distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 10) {
    digitalWrite(motor1forward, LOW); // go back
    digitalWrite(motor2back, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2forward, LOW);
    delay(200);
    
    digitalWrite(motor1forward, LOW); // right turn
    digitalWrite(motor2forward, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2back, LOW );
    delay(150);
  }

  else if (distance <= 10) {
    digitalWrite(motor1forward, HIGH); // go forward
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2forward, HIGH);
  }

}
