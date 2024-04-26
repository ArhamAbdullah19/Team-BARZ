#include "pitches.h"
byte incomingChar = 0;
const int buzzerPin = D1;

// Define the melody notes and duration
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int duration = 500; // Duration of each note (in milliseconds)

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  // Initialize digital pin buzzerPin as an output
  pinMode(buzzerPin, OUTPUT);
}
void loop() {
  
  if (Serial.available() > 0) {
    incomingChar = Serial.read(); // Read the input character from serial
 // Check the received character
    if (incomingChar == 'Z') {
      // Turn on the Buzzer
      // pin D1 controls the sound, emitting each note every "duration' milliseconds
      Serial.println("Fire In the Engine Room");
      for (int thisNote = 0; thisNote < 8; thisNote++) {
     // Check for serial input
      tone(D1,melody[thisNote], duration);
      // Output the voice after several minutes
      // restart after two seconds
            delay(1000);
 }
  
   } else if (incomingChar == 'H') {
     // Turn off the buzzer
    noTone(buzzerPin);
    Serial.println("No Fire");
          delay(1000);
    }
  }
  }
