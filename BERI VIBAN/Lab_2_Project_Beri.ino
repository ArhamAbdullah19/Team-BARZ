//This programme On and Off the LED light with the characters B or b and I or i

// Define the pin number for the LED
const int ledPin = LED_BUILTIN;

void setup() {  
  // Initialize the Serial Monitor
  Serial.begin(230400);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Check for incoming Serial data
    if (Serial.available() > 0) {
    // Read the incoming data
    char data = Serial.read();

    // If the data is 'B' or 'b', turn the LED on
      if (data == 'B' || data == 'b') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }

    // If the data is 'I' or 'i', turn the LED off
      if (data == 'I' || data == 'i') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}
