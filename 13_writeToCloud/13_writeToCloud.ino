`/*
 * This code is for interfacing DHT 11 sensor with Node MCU and updating to cloud
 * 
 * Connect VCC of DHT11 sensor to Vin pin NODE MCU
 * Connect GND of DHT11 sensor to GND pin of Node MCU
 * Connect OUT pin of DHT11 sensor to D2 pin of Node MCU
 * 
 */


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <dht.h>

#define dhtPin D2

const char* ssid = "mfjkd";   //Wi-Fi Name
const char* password = "12345678sf";// Wi-Fi Passcode

WiFiClient client;
unsigned long myChannelNumber = 747443;         // Write your Channel ID
const char * myWriteAPIKey = "8NJM2UTQ5YB9YQCV";// Write your Write API Key

int Temperature = 0, Humidity = 0;

dht DHT;

void setup()
{
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

  //Serial monitor display information for sensor
  Serial.println("DHT11 Sensor Interfacing with Node MCU");
  
}

void loop()
{
  //Reading sensor values from DHT11 sensor
  
  DHT.read11(dhtPin);
  Humidity = DHT.humidity;
  Temperature = DHT.temperature;

  // Pushing Tempereture value to the Thingspeak.com Cloud
  ThingSpeak.writeField(myChannelNumber, 1, Temperature, myWriteAPIKey);
  // ThingSpeak will only accept updates every 15 seconds.
  delay(20000);   // Delay for every data interval

 // Pushing Humidity value to the Thingspeak.com Cloud
  ThingSpeak.writeField(myChannelNumber, 2, Humidity, myWriteAPIKey);
  delay(20000);  // Delay for every data interval
}


,.
