/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board

byte incomingChar = 0;

void setup() {
  //Initialize Serial communication
  Serial.begin(9600);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) //Check if data is available from Serial Monitor
  {
    //Read the incoming character
    incomingChar = Serial.read();
    
  // Check the received character
    if (incomingChar == 'Z') {
      // Turn on the LED
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED turned on");
    } else if (incomingChar == 'H') {
      // Turn off the LED
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED turned off");
    }
  }
}
