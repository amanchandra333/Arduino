#include <SoftwareSerial.h>
String a="";
String s="";
String c5="340011CD739B"; //1
String c1="29003359BBF8"; //5
String c2="29003358A0E2"; //2
String c3="2900336893E1"; //3
String c4="340011E323E5"; //4
int pin2=31;
int pin3=33;
int pin4=49;
int pin5=45;
int pin6=41;
int pin7=43;
int pin8=47;
int pin9=53;
String temp="";
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
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
void loop()
{
  if(Serial1.available())
  a=a+(char)Serial1.read();
  s=a;
  if(temp.equals(s))
  {
    a="";
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
    digitalWrite(pin4, 0);
    digitalWrite(pin5, 1);
    digitalWrite(pin6, 1);
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
    digitalWrite(pin2, 0);
    digitalWrite(pin3, 1);
    digitalWrite(pin4, 1);
    digitalWrite(pin5, 0);
    digitalWrite(pin6, 0);
    digitalWrite(pin7, 0);
    digitalWrite(pin8, 0);
    temp=s;
  }
}

/*
 // write '9'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 0);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '8'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 1);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '7'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 0);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 0);
 digitalWrite(pin8, 0);
 delay(1000);
 // write '6'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 0);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 1);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '5'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 0);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '4'
 digitalWrite(pin2, 0);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 0);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '3'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 0);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '2'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 0);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 1);
 digitalWrite(pin7, 0);
 digitalWrite(pin8, 1);
 delay(1000);
 // write '1'
 digitalWrite(pin2, 0);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 0);
 digitalWrite(pin6, 0);
 digitalWrite(pin7, 0);
 digitalWrite(pin8, 0);
 delay(1000);
 // write '0'
 digitalWrite(pin2, 1);
 digitalWrite(pin3, 1);
 digitalWrite(pin4, 1);
 digitalWrite(pin5, 1);
 digitalWrite(pin6, 1);
 digitalWrite(pin7, 1);
 digitalWrite(pin8, 0);
 delay(1000);

 */

