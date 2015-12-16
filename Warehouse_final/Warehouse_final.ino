#include <SoftwareSerial.h>
String a = "";
String s = "";
String c1 = "29003359BBF8"; //5
String c2 = "29003358A0E2"; //3
String c3 = "2900336893E1"; //1
String c4 = "340011E323E5"; //4
String c5 = "340011CD739B"; //2
int pin2=31;
int pin3=33;
int pin4=49;
int pin5=45;
int pin6=41;
int pin7=43;
int pin8=47;
int pin9=53;
String temp = "";
int apf=A4; 
int apwx=A2;
int apwy=A3;
int af=0;
int awx=0;
int awy=0;
int winput1=48;
int winput2=46;
int winput3=52;
int winput4=50;
int finput3=38;
int finput4=36;
int en_right=11;
int en_left=10;
int f_upper= 380;
int f_lower= 300;
int wx_middle_upper= 400;
int wx_middle_lower= 345;
int wx_upper= 360;
int wx_lower= 310;
int wy_middle_upper= 415;
int wy_middle_lower= 355;
int wy_upper= 370;
int wy_lower= 320;

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
  pinMode(pin2, OUTPUT);  
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  digitalWrite(9, 0);  // start with the "dot" off
}

void loop() {
  // put your main code here, to run repeatedly:
  accelerogiri();
  rfidgiri();
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
  else if(s.equalsIgnoreCase(c1))
  {
    Serial.println(s+" p5");
    digitalWrite(pin2, 1);
    digitalWrite(pin3, 0);
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 1);
    digitalWrite(pin8, 1);
    temp=s;        
  }
  else if(s.equalsIgnoreCase(c2))
  {
    Serial.println(s+" p2");
    digitalWrite(pin2, 1);
    digitalWrite(pin3, 1);
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 0);
    digitalWrite(pin8, 1);
    temp=s;
  }
  else if(s.equalsIgnoreCase(c3))
  {
    Serial.println(s+" p3");
    digitalWrite(pin2, 1);
    digitalWrite(pin3, 1);
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 0);
    digitalWrite(pin8, 1);
    temp=s;
  }
  else if(s.equalsIgnoreCase(c4))
  {
    Serial.println(s+" p4");
    digitalWrite(pin2, 0);
    digitalWrite(pin3, 1);
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 0);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 1);
    digitalWrite(pin8, 1);
    temp=s;
  }
  else if(s.equalsIgnoreCase(c5))
  {
    Serial.println(s+" p1");
    digitalWrite(pin2, 1);
    digitalWrite(pin3, 1);
    digitalWrite(pin4, 0);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 1);
    digitalWrite(pin7, 0);
    digitalWrite(pin8, 1);
    temp=s;
  }
}

void accelerogiri()
{
  af = analogRead(apf);
  awx = analogRead(apwx);
  awy = analogRead(apwy);
  
  /*
  Serial.print(af);
  Serial.print(" ");
  Serial.print(awx);
  Serial.print(" ");
  Serial.print(awy);
  */
  
  //forklift
  if(af>=f_upper)
  {
    //forklift up
    digitalWrite(finput3, LOW);
    digitalWrite(finput4, HIGH);
    //Serial.print(" forklift up ");
  }
  else if(af<=f_lower)
  {
    //forklift down
    digitalWrite(finput3, HIGH);
    digitalWrite(finput4, LOW);
    //Serial.print(" forklift down ");
  }
  else
  {
    digitalWrite(finput3, LOW);
    digitalWrite(finput4, LOW);
  }
  
  //motion
  if(awx<=wx_lower)// && awy<wy_middle_upper && awy>wy_middle_lower)
  {
    //forward
    analogWrite(en_right, 255);
    analogWrite(en_left, 200);
    digitalWrite(winput1, HIGH);
    digitalWrite(winput2, LOW);
    digitalWrite(winput3, LOW);
    digitalWrite(winput4, HIGH);
    //Serial.println(" forward");
  }
  else if(awx>=wx_upper)// && awy<wy_middle_upper && awy>wy_middle_lower)
  {
    //back
    analogWrite(en_right, 255);
    analogWrite(en_left, 255);
    digitalWrite(winput1, LOW);
    digitalWrite(winput2, HIGH);
    digitalWrite(winput3, HIGH);
    digitalWrite(winput4, LOW); 
    //Serial.println(" back");
  }
  else if(awy>=wy_upper)// && awx>wx_middle_lower && awx<wx_middle_upper)
  {
    //left
    analogWrite(en_right, 255);
    analogWrite(en_left, 255);
    digitalWrite(winput1, LOW);
    digitalWrite(winput2, HIGH);
    digitalWrite(winput3, LOW);
    digitalWrite(winput4, HIGH);
    //Serial.println(" left");
  }
  else if(awy<=wy_lower) // && awx>wx_middle_lower && awx<wx_middle_upper)
  {
    //right
    analogWrite(en_right, 255);
    analogWrite(en_left, 255);
    digitalWrite(winput1, HIGH);
    digitalWrite(winput2, LOW);
    digitalWrite(winput3, HIGH);
    digitalWrite(winput4, LOW);
    //Serial.println(" right");
  }
  else
  {
    //free run
    analogWrite(en_right, 0);
    analogWrite(en_left, 0);
    digitalWrite(winput1, LOW);
    digitalWrite(winput2, LOW);
    digitalWrite(winput3, LOW);
    digitalWrite(winput4, LOW);
    //Serial.println(" free run");
  }
}
