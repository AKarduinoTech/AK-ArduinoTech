/*This sketch shows you how to make an automatic light using Arduino, which turns on when the room lights are switched
 * off.
 * 
 * Components
 * ----------
 * Arduino uno, Breadboard, Photoresistor, 9V battery, 2 leds, 2 220 ohm resistors, 7 1K ohm resistors, Jumper wires.
 * 
 * To learn more about voltage divider, have a look at- https://en.wikipedia.org/wiki/Voltage_divider
 
 **********************************************************************************************************************/


int photoresistor = A0;

int led1 = 2;
int led2 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(photoresistor, INPUT);
}

void loop() {
  int sensorValue = (analogRead(photoresistor));
  Serial.println(sensorValue);

  if (sensorValue > 900) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }

  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
