#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into D1 on the ESP8266
#define ONE_WIRE_BUS D1

// A OneWire instance is created to communicate with the sensor
OneWire oneWire(ONE_WIRE_BUS);

// We connect the OneWire bus with the temperature sensor.
DallasTemperature sensors(&oneWire);

void setup(void)
{
Serial.begin(9600);
Serial.println("Starting to measure temperature...");
sensors.begin();
// Initialize the LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Initially, turn OFF the LED
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop(void)
{
delay(3000);
Serial.print("Requesting temperature...");
sensors.requestTemperatures(); // Send the command to get the temperature Serial.println("DONE");
Serial.print("Temperaturel is: ");
Serial.println(sensors.getTempCByIndex(0));
 // Check if the temperature is higher than 25 or not
    if (sensors.getTempCByIndex(0) <= 25) {
      digitalWrite(LED_BUILTIN, HIGH); // Turn off the LED
      Serial.println("temperature is within limits");
    } else if (sensors.getTempCByIndex(0) > 25) {
      digitalWrite(LED_BUILTIN, LOW); // Turn on the LED
      Serial.println("temperature is above limits");
    }
}
