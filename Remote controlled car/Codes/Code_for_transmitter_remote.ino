/*This is the code for the transmitter of Arduino remote controlled car.
 * 
 * Components
 * ----------
 * Arduino uno, nRF24L01, joystick, 9V battery, battery connector and jumper wires
 * 
 * This sketch is created by Anuj Karnik.
 ********************************************************************************************************************/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "12345";
int xval = A0;
int yval = A1;
int value[3];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); 
  radio.stopListening();
  pinMode(xval, INPUT);
  pinMode(yval, INPUT);
  
}

void loop() {
  value[0] = analogRead(xval);
  value[1] = analogRead(yval);
  
  radio.write(&value, sizeof(value));
  
}
