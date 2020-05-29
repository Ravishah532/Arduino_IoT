/*
   This program is for interfacing DHT11 Sensor with Arduino/Node MCU

   Connect VCC pin of sensor to Vin/5V on Arduino/Node MCU
   Connect GND pin of sensor to GND pin on Arduino/Node MCU
   Connect OUT pin of sensor to D2 pin on Arduino/Node MCU

   Upload the following code and check the output

*/


#include <dht.h> // dht11 sensor library
#define dht11 2  // for Node MCU change this to D2

dht DHT;

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
}

void loop()
{
  // This will read the data from sensor
  DHT.read11(dht11);

  // Printing sensor values on serial monitor
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C  "); 
  delay(1000);  // 1 Second delay for next data access
}

