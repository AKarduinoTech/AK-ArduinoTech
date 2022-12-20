/*This code shows how to use a touchsensor with Arduino and a LED
* 
* Components
* ----------
* Arduino uno, breadboard, touchsensor, LED and jumper wires
* 
********************************************************************************************************************/
 
int touchsensor = 8;
int led = 13;
void setup() {
  pinMode(touchsensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int input = digitalRead(touchsensor);
  if (input == 0) {
    digitalWrite(led, LOW);
    delay(100);
  }

  else if (input == 1) {
    digitalWrite(led, HIGH);
    delay(100);
  }
}
