/*
   This program is to blink Built-In 13 pin LED on Arduino/Node MCU


   Upload the code directly and check output, No external circuit for this

*/

#define LED 13    // Change to D2 for Node MCU

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}

