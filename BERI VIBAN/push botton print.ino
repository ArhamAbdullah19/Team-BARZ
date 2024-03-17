int Led = LED_BUILTIN; //define LED pin
int Button = D1; //define push button pin
int val; //define digital variable val 
void setup()
{
  pinMode(Led, OUTPUT); //set the LED pin as an output pin
  pinMode(Button, INPUT); //set the button pin as an input pin
  Serial.begin(9600);
}
void loop()
{ val = digitalRead(Button);//we read the state of the button
 if (val == LOW) //if the button is pressed, we turn on the LED
 {
   digitalWrite(Led, HIGH);
   Serial.println("ALARM ACKNOWLEDGED!");
 }
 else 
 {
   digitalWrite(Led, LOW);
 }
}