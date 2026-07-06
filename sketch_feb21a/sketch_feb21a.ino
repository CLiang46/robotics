#include <LiquidCrystal.h>
#define trigger 2
#define echo 3
int MAINRED = 6;
int MAINGREEN = 5;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float duration=0,distance=0;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  pinMode(MAINGREEN, OUTPUT);
  pinMode(MAINRED, OUTPUT);

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(0,1);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(MAINGREEN, HIGH);
  //digitalWrite(MAINRED, HIGH);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)*0.0343;//measured in cm
  if(distance <20) {
    digitalWrite(MAINGREEN,LOW);
    digitalWrite(MAINRED,HIGH);
    delay(1000);
    digitalWrite(MAINRED,LOW);
  } else if(distance >= 20){
    digitalWrite(MAINRED,LOW);
    digitalWrite(MAINGREEN, HIGH);
  }
  lcd.setCursor(0,1);
  lcd.print("                ");//clears the LCD.
  lcd.setCursor(0,1);
  lcd.print(distance);
  
  
  delay(1000);
}
