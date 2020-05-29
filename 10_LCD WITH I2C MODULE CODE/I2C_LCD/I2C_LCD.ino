/*
   This code is to interfacing of I2C LCD module with Arduino/Node MCU


   Connect VCC of I2C LCD to Vin/5V pin of Arduino/Node MCU
   Connect GND of I2C LCD to GND pin of Arduino/Node MCU
   Connect SDA pin of I2C LCD to A4/D1 pin of Arduino/Node MCU respectively
   Connect SCL pin of I2C LCU to A5/D2 pin of Arduino/Node MCU respectively


   Upload this code check for Output, adjust the contrast by pot knob given on LCD module.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("   WELCOME To   ");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("   UTD - Hubli  ");
  delay(3000);
  lcd.clear();
}

void loop()
{
  lcd.print("     I2C LCD    ");
  lcd.setCursor(0, 1);
  lcd.print("   Interfacing  ");
}

