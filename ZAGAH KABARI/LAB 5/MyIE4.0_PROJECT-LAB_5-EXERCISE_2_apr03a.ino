/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/54cf36e0-38d2-4cd5-83c9-d55c11da475e 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int flameSensor;
  bool buzzer;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "pitches.h"

// Define the pins
const int BuzzerPin = D2;
const int FlameSensorPin = D1; // The flame sensor is also connected to D1
const int LedPin = LED_BUILTIN;

// Define the melody notes and duration
int melody[] = {
 NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int duration = 500; // Duration of each note (in milliseconds)

// Define the threshold value for flame detection
#define FLAME_THRESHOLD 300   // Threshold according to sensor and environment


void setup() {
  
  // Initialize digital pins as outputs
 pinMode(BuzzerPin, OUTPUT);
 pinMode(LedPin, OUTPUT);
 
 // Initialize the flame sensor pin as an input
 pinMode(FlameSensorPin, INPUT);
 Serial.begin(9600); // Initialize serial and wait for port to open:

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()  { // Read the Analog value from flame sensor
  
  flameSensor = analogRead(FlameSensorPin); //read the sensor digital output

 // Process the data and determine if flame is detected
 
 int Flame = flameSensor > FLAME_THRESHOLD;

  // Activate the buzzer if a flame is detected
 if (Flame) {
   buzzer=true;
   digitalWrite(LedPin, LOW);
   Serial.println("FIRE IN THE ENGINE ROOM!!!!!!!!");
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      tone(BuzzerPin, melody[thisNote], duration);
      delay(1000);
    }
    
 } else {
    // Turn off the buzzer and Led
    digitalWrite(LedPin, HIGH);
    noTone(BuzzerPin);
    Serial.println("NO FIRE");
    buzzer=false;
 }

  ArduinoCloud.update();
  // Delay before next reading
 delay(2000);
  
}







