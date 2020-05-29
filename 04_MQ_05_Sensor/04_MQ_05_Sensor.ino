/*

   This program is for Interfacing MQ-05 sensor with Arduino/Node MCU

   Connect VCC of sensor to Vin/5V on Arduino/Node MCU
   Connect GND of sensor to GND on Arduino/Node MCU
   Connect A0 of sensor to A0 of Arduino/Node MCU


   Upload this code and test the output
*/

#define MQpin A0

float sensorData = 0;

void setup()
{
  pinMode(MQpin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorData = (analogRead(MQpin) * (5.00 / 1023)); // Reading and converting sensorData into 0 - 5V Voltage levels
  Serial.print("MQ - 05 Sensor Value = ");
  Serial.println(sensorData);
  delay(1000);
}






