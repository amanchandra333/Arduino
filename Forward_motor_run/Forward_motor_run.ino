#include<Wire.h>
int input1=12;
int input2=13;
int enable1=5;
int enable2=11;
int input3=10;
int input4=6;
int c=0;
void setup()
{
      pinMode(input1,OUTPUT);
      pinMode(input2,OUTPUT);
      pinMode(input3,OUTPUT);
      pinMode(input4,OUTPUT);
      digitalWrite(input1, HIGH);
      digitalWrite(input3, HIGH);
      digitalWrite(input2, LOW);
      digitalWrite(input4, LOW);
}
void loop()
{
      delay(100);
      c++;
      if(c>50)
      {
        digitalWrite(input2, HIGH);
        digitalWrite(input4, HIGH);
        digitalWrite(input1, LOW);
        digitalWrite(input3, LOW);
        
      }
}
