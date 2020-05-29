/*
   This code is for interfacing L293D motor driver with Arduino/Node MCU

   Connect 12V pin of Driver PCB to +ve pin of Power Supply (12V Output)
   Connect GND pin of Driver module to -ve pin of Power Supply (Black Wire/GND)
   Connect Motors to L293D driver modules as per Motor1 and Motor2 indication
   Connect GND/-ve Pin of Power Supply to GND pin on Ardino/Node MCU
   Connect IN1, IN2, IN3 and IN4 pin of driver module to D2, D3, D4 and D5 pin on Arduino/Node MCU



   Upload the following code and test the output.
*/

//Un-Comment this section, if you are using Arduino
/*
  #define M1p 2
  #define M1n 3
  #define M2p 4
  #define M2n 5
*/

//Un-Comment this section, if you are using Node MCU
/*
  #define M1p D2
  #define M1n D3
  #define M2p D4
  #define M2n D5
*/

void setup()
{
  pinMode(M1p, OUTPUT);
  pinMode(M1n, OUTPUT);
  pinMode(M2p, OUTPUT);
  pinMode(M2n, OUTPUT);
}

void loop()
{
  //Controlling Motor 1
  digitalWrite(M1p, HIGH);
  digitalWrite(M1n, LOW);
  delay(5000);
  digitalWrite(M1p, LOW);
  digitalWrite(M1n, LOW);
  delay(100);

  //Controlling Motor 2
  digitalWrite(M2p, HIGH);
  digitalWrite(M2n, LOW);
  delay(5000);
  digitalWrite(M2p, LOW);
  digitalWrite(M2n, LOW);
  delay(100);
}

