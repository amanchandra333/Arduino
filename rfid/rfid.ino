#include <SoftwareSerial.h>
String a="";
String s="";
String c1="29003359BBF8";
String c2="29003358A0E2";
String c3="2900336893E1";
String temp="";
void setup()
{
   Serial.begin(9600);
   Serial1.begin(9600);
}
void loop()
{
  if(Serial1.available())
  {
    a=a+(char)Serial1.read();
    Serial.println(a);
  }
}

