/*
 * This program is for Interfacing IR sensor to Arduino/Node MCU
 * 
 * Connect VCC pin of sensor to Vin/5V pin on Arduino/Node MCU
 * Connect GND pin of sensor to GND pin on Arduino/Node MCU
 * Connect OUT pin on sensor to D2 pin on Arduino/Node MCU
 * 
 * 
 * Upload this code and check output
 */
#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
char ssid[] = "Hello";
char pass[] = "99999999";
WiFiClient client;
unsigned long MyChannelId = 686008;
const char * myWriteAPIKey = "RDXYR389NUU1NW9Y";
int count=0;
int Field = 1;

#define LED D0  //Change this to D0 for Node MCU
#define IRpin D2 //Change this to D2 for Node MCU

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
   if(IRData == LOW)
  {
    digitalWrite(LED,HIGH);
    Serial.println("Object Detected infront of IR Sensor");
  }
  else
  {
    digitalWrite(LED,LOW);
  }
//  delay(100);
ThingSpeak.writeField(MyChannelId,Field,IRData,myWriteAPIKey);
Serial.println("data updated to field ");
delay(15000);
  
}
