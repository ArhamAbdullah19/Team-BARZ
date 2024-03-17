
#include <ESP8266WiFi.h>
//WiFi network parameters 
const char* ssid    =  "Vilibe";
const char* password  = "15071999";
//host to connect to and WiFi client parameters 
const char* host = "postman-echo.com";
WiFiClient client;
const int httpPort = 80;

void setup() {
  //start serial
  Serial.begin(115200);
  //a small delay is added to initialize the serial port
  delay(10);

  //connecting to WiFi network
  Serial.println();
  Serial.println();
  Serial.println("conneting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status () != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address");
  Serial.println(WiFi.localIP());
}

void loop() {
  //a 5 sec delay is added for WiFi initialization and avoid continuous loop requests
  delay(5000);
  Serial.print("connecting to ");
  Serial.println(host);

  // a connection to thewebsite is opened
  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return;
  }

  //the specific URL is indicated and the connection request is sent 
  String url = "/postman-echo.com/get";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + "HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  //We wait 5 sec for the server response 
  unsigned long timeout = millis();
  while (client.available() == 0 ){
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  while(client.available()){// thee server response is processed
      String line = client.readStringUntil('\r');
      Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}