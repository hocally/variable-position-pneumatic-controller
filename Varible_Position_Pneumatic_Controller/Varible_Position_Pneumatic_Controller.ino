#include <PID_v1.h>

int inSol = 2;
int outSol = 3;
int topSwitch = 4;
int botSwitch = 5;
double freq = 15;
double currentPos;
double targetPos;
double setVal;
boolean atTop;
boolean atBot;
double Kp = 1;
double Ki = 0;
double Kd = 0;
PID myPID(&currentPos, &setVal, &targetPos, Kp, Ki, Kd, DIRECT);

void setup() {
  // put your setup code here, to run once:
  pinMode(inSol, OUTPUT); digitalWrite(inSol, LOW);
  pinMode(outSol, OUTPUT); digitalWrite(outSol, LOW);
  pinMode(topSwitch, INPUT);
  pinMode(botSwitch, INPUT);
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(20);
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  myPID.Compute();
  actuateVariable(setVal);
}

void updateData() {
  currentPos = map(analogRead(A0), 0, 1023, 0, 10);
  if(digitalRead(topSwitch) == HIGH){
    atTop = true;
  }else{
    atTop = false;
  }
  if(digitalRead(botSwitch) == HIGH){
    atBot = true;
  }else{
    atBot = false;
  }
  if(Serial.available() == true)
  {
    targetPos = Serial.read();
  }
}

void actuateBoolean(boolean b) {
  if(b) {
  digitalWrite(inSol, HIGH);
  delay(30);
  digitalWrite(inSol, LOW);
  }
  else{
  digitalWrite(outSol, HIGH);
  delay(30);
  digitalWrite(outSol, LOW);    
  }
}

void actuateVariable(double d) {
    digitalWrite(inSol, HIGH);
    digitalWrite(outSol, LOW);
    delay((1/freq)*d);
    digitalWrite(inSol, LOW);
    digitalWrite(outSol, HIGH);
    delay((1/freq)-(1/freq)*d);
}


