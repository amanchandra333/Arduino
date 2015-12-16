#include <SoftwareSerial.h>
String a = "";
String s = "";
String c1 = "29003359BBF8";
String c2 = "29003358A0E2";
String c3 = "2900336893E1";
String c4 = "340011E323E5";
String c5 = "340011CD739B";
String temp = "";
int apf = A4;
int apwx = A2;
int apwy = A3;
int af = 0;
int awx = 0;
int awy = 0;
int winput1 = 48;
int winput2 = 46;
int wenable1 = 12;
int wenable2 = 11;
int winput3 = 52;
int winput4 = 50;
int fenable2 = 10;
int finput3 = 38;
int finput4 = 36;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  // put your setup code here, to run once:
  pinMode(winput1, OUTPUT);
  pinMode(winput2, OUTPUT);
  pinMode(winput3, OUTPUT);
  pinMode(winput4, OUTPUT);
  pinMode(finput3, OUTPUT);
  pinMode(finput4, OUTPUT);
  //pinMode(wenable1,OUTPUT);
  //pinMode(wenable2,OUTPUT);
  //pinMode(fenable2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  accelerogiri();
  //rfidgiri();
}

void rfidgiri()
{
  if (Serial1.available())
    a = a + (char)Serial1.read();
  s = a;
  if (temp.equals(s))
  {
    a = "";
  }
  else if (s.equalsIgnoreCase(c1))
  {
    Serial.println(s + " p1");
    temp = s;
  }
  else if (s.equalsIgnoreCase(c2))
  {
    Serial.println(s + " p2");
    temp = s;
  }
  else if (s.equalsIgnoreCase(c3))
  {
    Serial.println(s + " p3");
    temp = s;
  }
    else if(s.equalsIgnoreCase(c4))
  {
    Serial.println(s+" p4");
    temp=s;
  }
  else if(s.equalsIgnoreCase(c5))
  {
    Serial.println(s+" p5");
    temp=s;
  }
}

void accelerogiri()
{
  af = analogRead(apf);
  awx = analogRead(apwx);
  awy = analogRead(apwy);
  delay(5);
  Serial.print("forklift : ");
  Serial.print(af);
  Serial.print(" motion : ");
  Serial.print(awx);
  Serial.print(" , ");
  Serial.print(awy);
  //forklift
  if (af >= 430)
  {
    //forklift up
    //digitalWrite(finput3, LOW);
    //digitalWrite(finput4, HIGH);
    //analogWrite(fenable2, 255);
    Serial.print(" forklift up ");
  }
  else if (af <= 335)
  {
    //forklift down
    //digitalWrite(finput3, HIGH);
    //digitalWrite(finput4, LOW);
    //analogWrite(fenable2, 255);
    Serial.print(" forklift down ");
  }
  else
  {
    //analogWrite(fenable2, 0);
    Serial.print(" forklift stable ");
  }
  //motion
  if(awx<=330 && awy<410 && awy>340)
  {
    //forward
    //digitalWrite(winput1, HIGH);
    //digitalWrite(winput2, LOW);
    //digitalWrite(winput3, LOW);
    //digitalWrite(winput4, HIGH);
    //analogWrite(wenable1, 255);
    //analogWrite(wenable2, 255);
    Serial.println(" forward");
  }
  else if(awx>=420 && awy<410 && awy>340)
  {
    //back
    //digitalWrite(winput1, LOW);
    //digitalWrite(winput2, HIGH);
    //digitalWrite(winput3, HIGH);
    //digitalWrite(winput4, LOW);
    //analogWrite(wenable1, 255);
    //analogWrite(wenable2, 255);
    Serial.println(" back");
  }
  else if(awx>340 && awx<410 && awy>=420)
  {
    //left
    //digitalWrite(winput1, LOW);
    //digitalWrite(winput2, HIGH);
    //digitalWrite(winput3, LOW);
    //digitalWrite(winput4, HIGH);
    //analogWrite(wenable1, 255);
    //analogWrite(wenable2, 255);
    Serial.println(" left");
  }
  else if(awx>340 && awx<410 && awy<=330)
  {
    //right
    //digitalWrite(winput1, HIGH);
    //digitalWrite(winput2, LOW);
    //digitalWrite(winput3, HIGH);
    //digitalWrite(winput4, LOW);
    //analogWrite(wenable1, 255);
    //analogWrite(wenable2, 255);
    Serial.println(" right");
  }
  else
  {
    //free run
    //analogWrite(wenable1, 0);
    //analogWrite(wenable2, 0);
    Serial.println(" free run");
  }
}

