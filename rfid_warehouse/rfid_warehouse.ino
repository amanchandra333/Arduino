#include <SoftwareSerial.h>
String a="";
String s="";
String c1="29003359BBF8";
String c2="29003358A0E2";
String c3="2900336893E1";
String c4="340011E323E5";
String c5="340011CD739B";
String temp="";
void setup()
{
   Serial.begin(9600);
   Serial1.begin(9600);
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
    Serial.println(s+" p1");
    temp=s;        
  }
  else if(s.equalsIgnoreCase(c2))
  {
    Serial.println(s+" p2");
    temp=s;
  }
  else if(s.equalsIgnoreCase(c3))
  {
    Serial.println(s+" p3");
    temp=s;
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

