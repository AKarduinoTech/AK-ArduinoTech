/*This is the code for the receiver of Arduino remote controlled car.
 * 
 * Components
 * ----------
 * Arduino uno, L298N, nRF24L01, chassis, wheels, 2 Motors, 2 9V batteries, battery connectors and jumper wires
 * 
 * This sketch is created by Anuj Karnik.
 ********************************************************************************************************************/
 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "12345";
int value[3];

int x = A0;
int y = A1;

int motor1back = 4;
int motor1forward = 5;
int motor2forward = 6;
int motor2back = 7;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(motor1forward, OUTPUT);
  pinMode(motor1back, OUTPUT);
  pinMode(motor2forward, OUTPUT);
  pinMode(motor2back, OUTPUT);

  pinMode(x, INPUT);
  pinMode(y, INPUT);
}

void loop() {
  if (radio.available())
  {
    char text[32] = "";
    radio.read(&value, sizeof(value));
    Serial.print("X: ");
    Serial.println(value[0]);
    Serial.print("Y:");
    Serial.println(value[1]);
  }

   if (value[1] == 0) {
    digitalWrite(motor1back, HIGH); // right turn
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1forward, LOW);
    digitalWrite(motor2forward, HIGH );
  }
  else if (value[1] == 1023) {
    digitalWrite(motor1forward, HIGH); // left turn
    digitalWrite(motor2forward, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2back, HIGH);
  }
  else if (value[0] == 0) {
    digitalWrite(motor1back, LOW); // go forward
    digitalWrite(motor2forward, HIGH);
    digitalWrite(motor1forward, HIGH);
    digitalWrite(motor2back, LOW);
  }
  else if (value[0] == 1023) {
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
