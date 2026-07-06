#include <LiquidCrystal.h>
#define trigger 12
#define echo 7
const int in1 = 16;
const int in2 = 17;
const int in3 = 18;
const int in4 = 19;
const char tab1[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09};
const char tab2[] = {0x01, 0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03};
int mainred = 3;
int sidered = 9;
int sideyellow = 10;
int mainyellow = 5;
bool moved = false;
int maingreen = 6;
int sidegreen = 11;
int currentPosSteps=0;
int movectr = 0;
const int rs = 4, en = 2, d4 = 13, d5 = 14, d6 = 15, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float duration = 0, distance = 0;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // put your setup code here, to run once:
  pinMode(mainred, OUTPUT);
  pinMode(sidered, OUTPUT);
  pinMode(mainyellow, OUTPUT);
  pinMode(sideyellow, OUTPUT);
  pinMode(maingreen, OUTPUT);
  pinMode(sidegreen, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distance in cm: ");
  lcd.setCursor(0,1);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)*0.0343;//measured in cm
  if(distance >= 30){
    analogWrite(mainred, 0);
    analogWrite(sidered, 0);
    analogWrite(mainyellow, 0);
    analogWrite(sideyellow, 0);
    analogWrite(maingreen, 255);
    analogWrite(sidegreen, 255);
    //if (currentPosSteps != 0) {
    //  ctlStepMotor(-currentPosSteps, 5); // move back to zero
    //  currentPosSteps = 0;
    //}
    StepMotorStop();
  } else if(distance < 30 && distance >= 25){
    analogWrite(mainred, 0);
    analogWrite(sidered, 0);
    analogWrite(maingreen, 0);
    analogWrite(sidegreen, 0);
    analogWrite(mainyellow, 127);
    analogWrite(sideyellow, 127);
    delay(1000);
    analogWrite(mainyellow, 0);
    analogWrite(sideyellow, 0);
    delay(500);
    //if (currentPosSteps != 0) {
    //  ctlStepMotor(-currentPosSteps, 5); // move back to zero
     // currentPosSteps = 0;
    //}
    StepMotorStop();
    moved = false;
  } else if(distance < 25 && distance >= 20){
    analogWrite(mainred, 0);
    analogWrite(sidered, 0);
    analogWrite(maingreen, 0);
    analogWrite(sidegreen, 0);
    analogWrite(mainyellow, 255);
    analogWrite(sideyellow, 255);
    //if (currentPosSteps != 0) {
   //   ctlStepMotor(-currentPosSteps, 5); // move back to zero
   //   currentPosSteps = 0;
   // }
    StepMotorStop();
    moved = false;
  } else if(distance < 20 && distance >= 10){
    analogWrite(maingreen, 0);
    analogWrite(sidegreen, 0);
    analogWrite(mainyellow, 0);
    analogWrite(sideyellow, 0);
    analogWrite(mainred, 127);
    analogWrite(sidered, 127);
    delay(1000);
    analogWrite(mainred, 0);
    analogWrite(sidered, 0);
    delay(500);
   // if (currentPosSteps != 0) {
  //    ctlStepMotor(-currentPosSteps, 5); // move back to zero
  //    currentPosSteps = 0;
    //}
    StepMotorStop();
    moved = false;
  } else {
    analogWrite(maingreen, 0);
    analogWrite(sidegreen, 0);
    analogWrite(mainyellow, 0);
    analogWrite(sideyellow, 0);
    analogWrite(mainred, 255);
    analogWrite(sidered, 255);
    
  }
  
  if(!moved && distance < 10){
      ctlStepMotor(17, 5); // ~30°
      delay(500);
      ctlStepMotor(17, 5); // another ~30°
      //StepMotorStop();
      currentPosSteps += 34; // track position
      
      StepMotorStop();
      moved = true;
  }  
  if(distance >= 10 && moved && currentPosSteps != 0) {
    moved = false;
    ctlStepMotor(-17, 5); // ~30° backward
    //delay(500);
    //StepMotorStop();
    delay(500);
    ctlStepMotor(-17, 5); // another ~30° backward
    currentPosSteps -= 34; // track position
    StepMotorStop();
    //moved = false; // reset so next entry triggers forward again
    //movectr = 0;
  }
  lcd.setCursor(0,1);
  lcd.print("                ");//clears the LCD.
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
}
void ctlStepMotor(int angle, char speeds){
  for(int j = 0; j<abs(angle); j++){
    if(angle>0){
      for(int i =0; i<8;i++){
        digitalWrite(in1, ((tab1[i] & 0x01) == 0x01 ? true: false));
        digitalWrite(in2, ((tab1[i] & 0x02) == 0x02 ? true: false));
        digitalWrite(in3, ((tab1[i] & 0x04) == 0x04 ? true: false));
        digitalWrite(in4, ((tab1[i] & 0x08) == 0x08 ? true: false));
        delay(speeds);
      }
    } else {
      for(int i = 0; i < 8; i++){
        digitalWrite(in1, ((tab2[i] & 0x01) == 0x01 ? true: false));
        digitalWrite(in2, ((tab2[i] & 0x02) == 0x02 ? true: false));
        digitalWrite(in3, ((tab2[i] & 0x04) == 0x04 ? true: false));
        digitalWrite(in4, ((tab2[i] & 0x08) == 0x08 ? true: false));
        delay(speeds);
      }
    }
  }
}
void StepMotorStop(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
