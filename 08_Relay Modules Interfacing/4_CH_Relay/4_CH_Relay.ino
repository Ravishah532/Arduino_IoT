/*
 * This code is for interfacing 4 Channel Relay module with Arduino/Node MCU
 * 
 * Connect VCC of relay module to 5V pin on Arduino/Node MCU
 * Connect GND of relay module to GND pin on Arduino/Node MCU
 * Connect IN1, IN2, IN3 and IN4 of relay module to D2, D3, D4 and D5 pin on Arduino/Node MCU, not to D0 and D1 because they are Rx and Tx pin's.
 * 
 * Note: In Node MCU pin D7 and D8 are Rx and Tx.
 * 
 * 
 * Now upload the code here and check the relay modules switchings.
 * 
 */

/*
 * If you are working with Arduino, then use this by Un-Commenting it.
 */
/* 
#define Relay1 2
#define Relay2 3
#define Relay3 4
#define Relay4 5
*/

/*
 * If you are working with Node MCU, then use this section by Un-Commenting it.
 */
/*
#define Relay1 D0   
#define Relay2 D1
#define Relay3 D2
#define Relay4 D3
*/

void setup()              // This function exicutes only one time, on RESET or Power ON
{
  // Pin configuration for GPIO setting to OUTPUT
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
}

void loop()                // This function exicutes again and again
{
  // Relay actuation code section
  digitalWrite(Relay1, LOW);   // Relay works on invert logic, i.e LOW = ON and HIGH = OFF
  delay(500);                  // Delay for visualizing the switching, it should be more than 100
  digitalWrite(Relay1, HIGH);
  delay(500);
  digitalWrite(Relay2, LOW);
  delay(500);
  digitalWrite(Relay2, HIGH);
  delay(500);
  digitalWrite(Relay3, LOW);
  delay(500);
  digitalWrite(Relay3, HIGH);
  delay(500);
  digitalWrite(Relay4, LOW);
  delay(500);
  digitalWrite(Relay4, HIGH);
  delay(500);
}
