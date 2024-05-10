// Code by Zagah Kabari
//A code that activates a Buzzer when an open flame is detected in the engine room

#include "thingProperties.h"
#include "pitches.h"


// Define the pins
const int BuzzerPin = D2;
const int FlameSensorPin = D1; // The flame sensor is also connected to D1
const int LedPin = LED_BUILTIN;

// Define fire alarm and duration
int FireAlarmMelody[] = {
  NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_C5
};
int AlarmDuration = 500; // Duration of each note (in milliseconds)

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
    for (int thisNote = 0; thisNote < 10; thisNote++) {
      tone(BuzzerPin, FireAlarmMelody[thisNote], AlarmDuration);
      delay(AlarmDuration); // Play each note for the specified duration
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
  delay(1000);
  
}
