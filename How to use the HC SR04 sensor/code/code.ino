/*This code shows how to use HC SR04 sensor with Arduino
* 
* Components
* ----------
* Arduino uno, HC-SR04, breadboard and some jumper cables.
* 
**********************************************************************************************************************************************/
const int trigPin = 9;  // Declaring pins
const int echoPin = 10;

long duration;  // Creating variables
int distance;

void setup() {

    pinMode(trigPin, OUTPUT); // Declares trigPin as an output
    pinMode(echoPin, INPUT); // Declares echoPin as an input

    Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, HIGH);  // Turns on the trigPin for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds

  distance = duration * 0.0343 / 2;  // Calculating the distance
                                                                                                                                                        
}
