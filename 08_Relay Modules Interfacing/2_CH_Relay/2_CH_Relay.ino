/*
 * This code is for interfacing 2 Channel Relay module with Arduino
 * 
 * Connect VCC of relay module to 5V pin on Arduino
 * Connect GND of relay module to GND pin on Arduino
 * Connect IN1 and IN2 of relay module to D2 and D3 pin on Arduino, not to D0 and D1 because they are Rx and Tx pin's.
 * 
 * 
 * Now upload the code here and check the relay modules switchings.
 * 
 */

#define Relay1 2 // D2 pin on Arduino
#define Relay2 3 // D3 pin on Arduino

void setup()                // This function exicutes only one time, on RESET or Power ON
{
  // Pin configuration for GPIO setting to OUTPUT
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
}

void loop()                   // This function exicutes again and again
{
  // Relay actuation code section
  digitalWrite(Relay1, LOW);    // Relay works on invert logic, i.e LOW = ON and HIGH = OFF
  delay(500);                   // Delay for visualizing the switching, it should be more than 100
  digitalWrite(Relay1, HIGH);
  delay(500);
  digitalWrite(Relay2, LOW);
  delay(500);
  digitalWrite(Relay2, HIGH);
  delay(500);
}
