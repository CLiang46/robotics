#include <LiquidCrystal.h>
#define trigger 2
#define echo 3
int MAINRED = 6;
int MAINGREEN = 5;
int tim = 100;
int x, y;
int xcoord = 0, ycoord = 1;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float duration=0,distance=0,distinches=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  distinches = distance/2.54;
  x=analogRead(xcoord);
  y=analogRead(ycoord);
  if(distance <10) {
    digitalWrite(MAINGREEN,HIGH);
    digitalWrite(MAINRED,HIGH);
    //delay(1000);
    //digitalWrite(MAINRED,LOW);
  } else if(distance >= 10){
    digitalWrite(MAINRED,LOW);
    digitalWrite(MAINGREEN, LOW);
    if(x >= 900 || x <= 100){
      digitalWrite(MAINRED, HIGH);
      delay(100);
      digitalWrite(MAINRED, LOW);
      delay(50);
    } else if(x >= 700 || x <= 300) {
      digitalWrite(MAINRED, HIGH);
      delay(500);
      digitalWrite(MAINRED, LOW);
      delay(500);
    }
    if(y>= 900 || y <= 100){
      digitalWrite(MAINGREEN, HIGH);
      delay(100);
      digitalWrite(MAINGREEN, LOW);
      delay(50);
    } else if(y >= 700 || y <= 300){
      digitalWrite(MAINGREEN, HIGH);
      delay(500);
      digitalWrite(MAINGREEN, LOW);
      delay(500);
    }
  }
  
  lcd.setCursor(0,0);
  lcd.print("Distance: ");//clears the LCD.
  //lcd.print(distance);
  //lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm ");
  lcd.print(distinches);
  lcd.print(" in");
  Serial.print("X and Y: ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.println("Distance: ");
  Serial.print(distance);
  Serial.print(" cm ");
  Serial.print(distinches);
  Serial.print(" in");
  //Serial.print(" in");
  delay(1000);
}
