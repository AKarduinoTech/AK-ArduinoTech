/*This code shows how to make an automatic plant watering system using Arduino
* 
* Components
* ----------
* Arduino uno, soil moisture sensor, submersible pum, breadboard, relay, RGB led, 4 AA cells,9 Volt battery and some jumper cables
* 
**********************************************************************************************************************************************/


int sensor = A0;                  
int relay = 2;                    

int red_led = 6;                      
int green_led = 7;                    

void setup() {

  pinMode(sensor, INPUT);         
  pinMode(relay, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);

  Serial.begin(9600);

}

void  loop() {
      

  int sensor_value = analogRead(sensor);
  Serial.println(sensor_value);
  
  if (sensor_value < 600) {
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(relay, HIGH);
    }

 
  else{
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(relay, LOW);
  }

  delay(250);
}
