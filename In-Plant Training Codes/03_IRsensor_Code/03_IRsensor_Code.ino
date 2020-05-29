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

#define LED 13  //Change this to D0 for Node MCU
#define IRpin 2 //Change this to D2 for Node MCU

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(IRpin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(IR_sensor) == LOW)
  {
    digitalWrite(LED,HIGH);
    Serial.println("Object Detected infront of IR Sensor");
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  delay(100);
}
