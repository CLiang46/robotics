int MAINGREEN = 4;
int MAINYELLOW = 3;
int MAINRED = 5;
int DELAYRED = 5000;
int DELAYYELLOW = 2000;
int DELAYGREEN = 5000;
int SIDEGREEN = 6;
int SIDEYELLOW = 7;
int SIDERED = 8;
void setup() {
  // put your setup code here, to run once
  pinMode(MAINGREEN, OUTPUT);
  pinMode(MAINYELLOW, OUTPUT);
  pinMode(MAINRED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  green_light();
  delay(DELAYGREEN);
  yellow_light();
  delay(DELAYYELLOW);
  red_light();
  delay(DELAYRED);
}

void green_light() {
  digitalWrite(MAINGREEN, HIGH);
  digitalWrite(MAINYELLOW, LOW);
  digitalWrite(MAINRED, LOW);
  digitalWrite(SIDEGREEN, HIGH);
  digitalWrite(SIDEYELLOW, LOW);
  digitalWrite(SIDERED, LOW);
}

void yellow_light(){
  digitalWrite(MAINYELLOW, HIGH);
  digitalWrite(MAINGREEN, LOW);
  digitalWrite(MAINRED, LOW);
  digitalWrite(SIDEYELLOW, HIGH);
  digitalWrite(SIDEGREEN, LOW);
  digitalWrite(SIDERED, LOW);
}

void red_light(){
  digitalWrite(MAINRED, HIGH);
  digitalWrite(MAINGREEN, LOW);
  digitalWrite(MAINYELLOW, LOW);
  digitalWrite(SIDERED, HIGH);
  digitalWrite(SIDEGREEN, LOW);
  digitalWrite(SIDEYELLOW, LOW);
}
