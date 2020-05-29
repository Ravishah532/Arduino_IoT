/*
   This code is used to Intercommunicate with Thingspeak.com cloud

   Connect VCC of 2 Channel Relay module with Vin pin of Node MCU
   Connect GND of Relay module with GND of Node MCU
   Connect IN1 and IN2 of relay module with D0 and D1 of Node MCU

   Connect VCC of IR sensor Module with Vin Pin of Node MCU
   Connect GND pin of IR Sensor with GND of Node MCU
   Connect Out pin of IR Sensor with D2 pin of Node MCU


*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

#define Relay1 D0
#define Relay2 D1
#define IRpin D2

const int Field = 1;

const char* ssid = "My_SSID";   //Wi-Fi Name
const char* password = "My_Password";// Wi-Fi Passcode

WiFiClient client;
unsigned long myChannelNumber = XXXXXX;         // Write your Channel ID
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXX";// Write your Write API Key
unsigned long othersChannelNumber = YYYYYY;     // Write other team channel ID

void setup()
{
  pinMode(IRpin, INPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);

  // This will start intercommunication from Cloud

  Serial.println("ESP is Communicating with Thingspeak.com");
}

void loop()
{
  bool IRdata = digitalRead(IRpin);
  ThingSpeak.writeField(myChannelNumber, 1, IRdata, myWriteAPIKey);
  Serial.println("Data Updated to cloud and waiting 20 Sec...");
  delay(20000);
  
  bool Data = ThingSpeak.readLongField(othersChannelNumber, Field);
  if (Data == LOW)
  {
    digitalWrite(Relay1, LOW);
    digitalWrite(Relay2, LOW);
  }
  else
  {
    digitalWrite(Relay1, HIGH);
    digitalWrite(Relay2, HIGH);
  }
  Serial.println(" Data received from thingspeak.com cloud\n waiting for  sec...");
  delay(5000);
  
}
