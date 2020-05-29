/*
   This program is for Interfacing RGB LED with Arduino/Node MCU

   Connect Long lenght leg of LED to GND pin of Arduino/Node MCU
   Connect Rpin of LED to D2 of Arduino/Node MCU through 560Ohms resistor
   Connect Gpin of LED to D3 of Arduino/Node MCU through 560Ohms resistor
   Connect Bpin of LED to D4 of Arduino/Node MCU through 560Ohms resistor


   Upload the following code and test the output
*/




#define Rpin 2  //Change to D2, if you are using Node MCU
#define Gpin 3  //Change to D3, if you are using Node MCU
#define Bpin 4  //Change to D4, if you are using Node MCU

void setup()
{
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
}

void loop()
{
  //Red colour LED ON and OFF
  digitalWrite(Rpin, HIGH);
  delay(1000);
  digitalWrite(Rpin, LOW);

  //Green colour LED ON and OFF
  digitalWrite(Gpin, HIGH);
  delay(1000);
  digitalWrite(Gpin, LOW);

  //Blue colour LED ON and OFF
  digitalWrite(Bpin, HIGH);
  delay(1000);
  digitalWrite(Bpin, LOW);
}
