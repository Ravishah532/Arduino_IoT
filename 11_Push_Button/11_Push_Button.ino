/*
 * 
 * This code is to interface 2/4 legs Push Button to Arduino/Node MCU
 * 
 * Connect 1K - 10K resistor to Vin/5V pin on Arduino/Node MCU
 * Connect Push Buttons one leg to resistor just connected to 5V/Vin
 * Connect Push Buttons same leg to D2 pin of Arduino/Node MCU
 * Connect other leg of Push Button to GND on Arduino/Node MCU
 * 
 * 
 * Upload the following code and test the output
 */

#define buttonPin 2  //Change to D2 for Node MCU
bool buttonState = 0;
unsigned int Counter = 0;

void setup()
{
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW)
  {
    Serial.println("Button Pressed");
    Serial.println(Counter++);
  }
  delay(100);
}
