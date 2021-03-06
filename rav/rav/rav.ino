#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <dht.h>
#include<ESP8266WiFi.h>
#include "ThingSpeak.h"

char ssid[] = "Ravi shah";
char pass[] = "Ravishah12";
WiFiClient client;
unsigned long MyChannelId = 686134;
const char * myWriteAPIKey = "2I06MQ051TOAO14K";
int count = 0;
dht DHT;
int Temperature = 0, Humidity = 0;
int Field1 = 1;
int Field2 = 2;
int Field3 = 3;

#define LED D0  
#define IRpin D3 
#define dhtPin D2

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(IRpin, INPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid, pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\n Connected....!");
  ThingSpeak.begin(client);
}

void loop()
{
  bool IRData = digitalRead(IRpin);
  if (IRData == LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Object Detected infront of IR Sensor");
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  //  delay(100);
  ThingSpeak.writeField(MyChannelId, Field3, IRData, myWriteAPIKey);
  Serial.println("data updated to field3 ");
  delay(15000);
  
  DHT.read11(dhtPin);
  Humidity = DHT.humidity;
  Temperature = DHT.temperature;
 
  ThingSpeak.writeField(MyChannelId, Field1, Temperature, myWriteAPIKey);
  Serial.println("data updated to field1 ");
  delay(15000); 
  
  ThingSpeak.writeField(MyChannelId, Field2, Humidity, myWriteAPIKey);
  Serial.println("data updated to field2 ");
  delay(15000);

}
