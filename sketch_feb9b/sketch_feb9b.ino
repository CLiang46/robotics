int MAINGREEN = 4;
int SIDEGREEN = 6;
int MAINYELLOW = 3;
int SIDEYELLOW = 7;
int MAINRED = 5;
int SIDERED = 8;
int DELAYMAINGREEN = 5000;
int DELAYMAINYELLOW = 1000;
int DELAYMAINRED = 3000;
int DELAYSIDEGREEN = 3000;
void setup() {
  // put your setup code here, to run once:
  pinMode(MAINGREEN, OUTPUT);
  pinMode(MAINRED, OUTPUT);
  pinMode(MAINYELLOW, OUTPUT);
  pinMode(SIDEGREEN, OUTPUT);
  pinMode(SIDEYELLOW, OUTPUT);
  pinMode(SIDERED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(SIDERED, HIGH);
    digitalWrite(MAINGREEN, HIGH);
    delay(DELAYMAINGREEN);
    digitalWrite(MAINGREEN, LOW);
    digitalWrite(MAINYELLOW, HIGH);
    delay(DELAYMAINYELLOW);
    digitalWrite(MAINYELLOW, LOW);
    digitalWrite(SIDERED, LOW);
    digitalWrite(SIDEYELLOW, HIGH);
    delay(2000);
    digitalWrite(SIDEYELLOW, LOW);
    digitalWrite(SIDEGREEN, HIGH);
    digitalWrite(MAINRED, HIGH);
    delay(DELAYMAINRED);
    digitalWrite(MAINRED, LOW);
    digitalWrite(SIDEGREEN, LOW);

}
