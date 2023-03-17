/*This code shows how to use a potentiometer using Arduino
* 
* Components
* ----------
* Arduino uno, potentiometer, breadboard and some jumper cables
* 
**********************************************************************************************************************************************/


int pot = A0;   //declaring the pin to which the potentiometer is connected

void setup() {
pinMode(pot, INPUT);    //declaring the potentiometer as INPUT

Serial.begin(9600);     //setting the baud rate of serial monitor at 9600 
}

void loop() {
int sensor_value = analogRead(pot);     //Reading the value from the potentiometer

Serial.print("Sensor value: ");          //Printing the value from the potentiometer on the serial monitor
Serial.println(sensor_value);
delay(500);
}
