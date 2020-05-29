/*
 * 
 * This program is for interfacing Ultrasonic Sensor module with Arduino/Node MCU
 * 
 * Connect VCC of Sensor to 5V/Vin on Arduino/Node MCU
 * Connect GND of sensor to GND of Arduino/Node MCU
 * Connect Trig pin of sensor to D2 of Arduino/Node MCU
 * Connect Echo pin of sensor to D3 of Arduino/Node MCU
 * 
 * 
 * Upload the follwing code and check the output
 */

#define trigPin 2  // Change to D2, for Node MCU
#define echoPin 3  // Change to D3, for Node MCU

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Object Distance  =");
  Serial.println(distance); 
  delay(500);
}


