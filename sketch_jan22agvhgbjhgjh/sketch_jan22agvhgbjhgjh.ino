#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h> // dht11 sensor library
#define dht11 D0 // for Node MCU change this to D2
#define trigPin D7  // Change to D2, for Node MCU
#define echoPin D8  // Change to D3, for Node MCU
#define Relay1 D6
#define Relay2 D3
#define Relay3 D4
#define Relay4 D5

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("   WELCOME To   ");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("   UTD - Hubli  ");
  delay(3000);
  lcd.clear();
  lcd.print("DHT11 Sensor");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("and temprature");
  delay(3000);
  lcd.clear();
}
void loop()
{
  // This will read the data from sensor
  long duration, distance;
  DHT.read11(dht11);

  // Printing sensor values on serial monitor
  lcd.print("hum = ");
  lcd.print(DHT.humidity);
  lcd.print("%  ");
  lcd.setCursor(0, 1);
  //delay(1000);
  lcd.print("Temp = ");
  lcd.print(DHT.temperature);
  lcd.print(" C ");
  delay(1000);  // 1 Second delay for next data access
  lcd.clear();

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  //lcd.clear();
  lcd.print("obj Distanc  =");
  lcd.print(distance);
  if (distance <= 10)
  {
    digitalWrite(Relay1, LOW);  // Relay works on invert logic, i.e LOW = ON and HIGH = OF
    digitalWrite(Relay3, HIGH);
    digitalWrite(Relay2, HIGH);
    digitalWrite(Relay4, HIGH);
  }
  else if (distance <= 20)
  {
    digitalWrite(Relay1, HIGH);
    digitalWrite(Relay2, LOW);
    digitalWrite(Relay3, HIGH);
    digitalWrite(Relay4, HIGH);
  }
  else if (distance <= 30)
  {
    digitalWrite(Relay1, HIGH);  // Relay works on invert logic, i.e LOW = ON and HIGH = OF
    digitalWrite(Relay2, HIGH);
    digitalWrite(Relay3, LOW);
    digitalWrite(Relay4, HIGH);
  }
  else
  {
    digitalWrite(Relay1, HIGH);
    digitalWrite(Relay3, HIGH);
    digitalWrite(Relay2, HIGH);
    digitalWrite(Relay4, HIGH);
  }
  delay(1500);
  lcd.clear();

}
