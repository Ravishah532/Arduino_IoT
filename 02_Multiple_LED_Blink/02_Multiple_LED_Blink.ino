/*
   This program is to blink more than 2 LED's connected to Arduino/Node MCU

    Connect LED1 to D2 of Arduino/Node MCU
    Connect LED2 to D3 of Arduino/Node MCU
    Connect LED3 to D4 of Arduino/Node MCU


    Upload the following code and see the output

*/

#define LED1 2     // Change to D2 for Node MCU
#define LED2 3     // Change to D3 for Node MCU
#define LED3 4     // Change to D4 for Node MCU

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(1000);
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(1000);
}

