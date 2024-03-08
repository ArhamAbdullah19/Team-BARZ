// Define the pin connected to the LED
const int ledPin = LED_BUILTIN; // You can change this pin based on your hardware setup

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initially, turn off the LED
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Check if there is data available in the Serial Monitor
  if (Serial.available() > 0) {
    // Read the incoming character
    char incomingChar = Serial.read();

    // Check the received character and control the LED accordingly
    if (incomingChar == 'A') {
      digitalWrite(ledPin, LOW); // Turn on the LED
      Serial.println("LED is ON");
    } else if (incomingChar == 'M') {
      digitalWrite(ledPin, HIGH); // Turn off the LED
      Serial.println("LED is OFF");
    }
  }
}
