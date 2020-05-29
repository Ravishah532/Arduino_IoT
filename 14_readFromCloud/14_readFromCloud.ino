/*
 * 
 * This code is for Retreving data from Thingspeak.com 
 * 
 * Connect Node MCU to USB and to your computer
 * 
 * 
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const int Field1 = 1, Field2 = 2;

const char* ssid = "My_SSID";   //Wi-Fi Name
const char* password = "My_Password";// Wi-Fi Passcode

WiFiClient client;
unsigned long myChannelNumber = XXXXXX;         // Write your Channel ID


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
  Serial.println("\nWiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);

  // This will start display of data from cloud on Serial Monitor

  Serial.println("Device Start Reading Data From Cloud");
}
void loop()
{
  // This will read Tempereture from Thingspeak.com
  int Tempereture = ThingSpeak.readLongField(myChannelNumber, Field1);

  // This will display Tempereture on Serial Monitor
  Serial.print("Tempereture = ");
  Serial.print(Tempereture);
  delay(5000);

  // This will read Humidity from Thingspeak.com
  int Humidity = ThingSpeak.readLongField(myChannelNumber, Field2);

  // This will display Humidity on Serial Monitor
  Serial.print("\t\tHumidity = ");
  Serial.println(Humidity);
  delay(5000);
}
