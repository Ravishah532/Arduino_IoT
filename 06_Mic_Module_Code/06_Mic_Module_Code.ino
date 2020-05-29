/*
   This code is for interfacing Mic Module sensor with Arduino/Node MCU

   Connect VCC of Mic sensor to Vin/5V of Arduino/Node MCU
   Connect GND of Mic senosr to GND of Arduino/Node MCU
   Connect OUT of Mic sensor to D2 of Arduino/Node MCU



   Upload the following code and check output.
*/

#define MicPin  2     //Change this to D2 for Node MCU

void setup()
{
  pinMode(MicPin, INPUT);
  Serial.begin (9600);
}

void loop ()
{
  bool sensorData = digitalRead(sensorPin);
  if (sensorData == HIGH)  
  {
    Serial.println("Sound Detected");
  }
}
