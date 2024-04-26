
int Led = LED_BUILTIN;
//define LED pin
int sensorDO = D1; //define sensor digital output 
int val; //define digital variable val

// Define the threshold value for flame detection
#define FLAME_THRESHOLD 300   // Adjust this threshold according to your sensor and environment


void setup()
{
pinMode(Led, OUTPUT);//define the LED pin as an output pin 
pinMode(sensorDO, INPUT);//define the sensor DO as an input pin
Serial.begin(9600);      // Initialize serial communication
}
void loop()// Read analog value from the flame sensor
{
  val=analogRead(sensorDO);//read the sensor digital output
  
  // Process the data and determine if flame is detected
  if(val >  FLAME_THRESHOLD)//when the digital output detects a flame, the LED is turned on
  {
    digitalWrite(Led, LOW);
     Serial.println("FIRE IN THE ENGINE ROOM!!!!!!!!");
  }
  else
  {
    digitalWrite(Led, HIGH);
    Serial.println("NO FIRE");
  }
  // Delay before next reading
  delay(2000);
}
