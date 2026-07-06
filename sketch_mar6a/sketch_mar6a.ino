#include <LiquidCrystal.h>
#include <Servo.h>
#define trigger 2
#define echo 3
//int MAINRED = 6;
int MAINGREEN = 5;
Servo servo;
const int sw = 13;
int joyval;
int tim = 100;
int x, y;
int xcoord = 0, ycoord = 1;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int brightness = 80;
float duration=0,distance=0,distinches=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(MAINGREEN, OUTPUT);
  //pinMode(MAINRED, OUTPUT);
  pinMode(sw, INPUT);
  servo.attach(4);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(0,1);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.println(analogRead(ycoord));
}

void loop() {
  x = analogRead(xcoord);
  y = analogRead(ycoord);
  if(y == 517){//517 is the center position for y coordinate of the joystick.
    analogWrite(MAINGREEN, 127);
  } else if (y > 517){
    analogWrite(MAINGREEN, 0);
  } else if(y < 517){
    analogWrite(MAINGREEN, 255);
  }
  joyval = analogRead(xcoord);
  joyval = map(joyval, 0, 1023, 0, 180);
  servo.write(joyval);
  
}
