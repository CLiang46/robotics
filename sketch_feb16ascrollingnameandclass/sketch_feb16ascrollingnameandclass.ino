//kpin = ground
//apin = positive
//d7=12
//d6=11
//d5=10
//d4=9
//epin=8
//rw=ground
//rs=7
//vo=middle of potentiometer
//potleft = positive
//potright = ground
//vdd=positive
//vss=negative
//5volt = positive rail
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
const int scrollSpeed = 1000;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Craig Liang");
  lcd.setCursor(0,1);
  lcd.print("CIS-033 Robotics and Embedded Systems");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(scrollSpeed);
}

