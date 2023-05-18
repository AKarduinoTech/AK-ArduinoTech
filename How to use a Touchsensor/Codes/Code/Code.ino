/*This code shows how to use a touchsensor with Arduino
* 
* Components
* ----------
* Arduino uno, breadboard, touchsensor and jumper wires
* 
* This sketch is created by Anuj Karnik.
********************************************************************************************************************/
 
int touchsensor = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(touchsensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int input = digitalRead(touchsensor);
  if (input == 0) {
    Serial.println("You have not touched the sensor");
    delay(100);
  }

  else if (input == 1) {
    Serial.println("You have touched the sensor");
    delay(100);
  }
}
