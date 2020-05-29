/*

   This code is for Retreving data from Thingspeak.com

   Connect Node MCU to USB and to your computer


*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <dht.h>

#define dht11 D2
LiquidCrystal_I2C lcd(0x27, 16, 2);
//dht DHT;
const int Field1 = 1, Field2 = 2;

const char* ssid = "Ravi shah";   //Wi-Fi Name
const char* password = "Ravishah12";// Wi-Fi Passcode

WiFiClient client;
unsigned long myChannelNumber = 694357;         // Write your Channel ID



void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  //lcd.print("WEL-Come");
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
  lcd.print("welcome to hubli");
  delay(1000);
  lcd.clear();
}
void loop()
{

  //DHT.read11(dht11);
  // This will read Tempereture from Thingspeak.com
  int Tempereture = ThingSpeak.readLongField(myChannelNumber, Field1);

  // This will display Tempereture on Serial Monitor
  //Serial.print("Tempereture = ");
  //Serial.print(Tempereture);

  lcd.setCursor(1, 0);
  lcd.print("Temp = ");
  lcd.print(Tempereture);
  lcd.print("C ");
  delay(6000);
  // This will read Humidity from Thingspeak.com
  int Humidity = ThingSpeak.readLongField(myChannelNumber, Field2);

  // This will display Humidity on Serial Monitor
  //Serial.print("\t\tHumidity = ");
  //Serial.println(Humidity);

  lcd.setCursor(1, 7);
  lcd.print("humidity = ");
  lcd.print(Humidity);
  lcd.print("%  ");
  delay(6000);
}
