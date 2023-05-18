/*This code shows how to use a potentiometer to control the brightness of a led
* 
* Components
* ----------
* Arduino uno, potentiometer, led, 220 ohm resistor, breadboard and some jumper cables
* 
* This sketch is created by Anuj Karnik.
**********************************************************************************************************************************************/


int pot = A0;   //declaring the pin to which the potentiometer is connected
int led = 3;    //declaring the pin to which the led is connected

void setup() {
pinMode(pot, INPUT);    //declaring the potentiometer as INPUT
pinMode(led, OUTPUT);   //declaring the led as OUTPUT
}

void loop() {
int sensor_value = analogRead(pot);     //Reading the value from the potentiometer
int mapped_value = map(sensor_value, 0, 1023, 0, 255);    //Mapping the value from the potentiometer

analogWrite(led, mapped_value);     //Setting the brightness of the led
}
