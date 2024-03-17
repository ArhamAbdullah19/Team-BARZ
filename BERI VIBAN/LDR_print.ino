int sensorPin = A0; // analog input pin
int ledPin = LED_BUILTIN; //pin of the onboard LED
int sensorValue = 0; // varialbe that stores the LDR sensor value

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  if (sensorValue > 900)
  {
    digitalWrite(ledPin, LOW);
    Serial.println("The smoke is too dark. Check Engine Combustion parameters!");
  }
  else
  {
    digitalWrite(ledPin, HIGH);
  }
  Serial.println(sensorValue, DEC);
}