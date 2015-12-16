#include<Wire.h>
int winput1=48;
int winput2=46;
int wenable1=12;
int wenable2=11;
int winput3=52;
int winput4=50;
int fenable2=10;
int finput3=38;
int finput4=36;
int c=0;
void setup()
{
      pinMode(winput1,OUTPUT);
      pinMode(winput2,OUTPUT);
      pinMode(winput3,OUTPUT);
      pinMode(winput4,OUTPUT);
      pinMode(finput3,OUTPUT);
      pinMode(finput4,OUTPUT);
      pinMode(wenable1,OUTPUT);
      pinMode(wenable2,OUTPUT);
      pinMode(fenable2,OUTPUT);
}
void loop()
{
      //forward
      digitalWrite(winput2, LOW);
      digitalWrite(winput4, HIGH);
      digitalWrite(winput1, HIGH);
      digitalWrite(winput3, LOW);
      analogWrite(wenable1, 255);
      analogWrite(wenable2, 255);
      delay(3000);
      //stopping
      analogWrite(wenable1, 0);
      analogWrite(wenable2, 0);
      //forklift up
      digitalWrite(finput3, LOW);
      digitalWrite(finput4, HIGH);
      analogWrite(fenable2, 255);
      delay(5000);
      analogWrite(fenable2, 0);
      //forward
      digitalWrite(winput2, LOW);
      digitalWrite(winput4, HIGH);
      digitalWrite(winput1, HIGH);
      digitalWrite(winput3, LOW);
      analogWrite(wenable1, 255);
      analogWrite(wenable2, 255);
      delay(2000);
      //stopping
      analogWrite(wenable1, 0);
      analogWrite(wenable2, 0);
      //forklift down
      digitalWrite(finput3, HIGH);
      digitalWrite(finput4, LOW);
      analogWrite(fenable2, 255);
      delay(5500);
      analogWrite(fenable2, 0);
      //backward
      digitalWrite(winput4, LOW);
      digitalWrite(winput2, HIGH);
      digitalWrite(winput3, HIGH);
      digitalWrite(winput1, LOW);
      analogWrite(wenable1, 255);
      analogWrite(wenable2, 255);     
      delay(2000);
      //stopping
      analogWrite(wenable1, 0);
      analogWrite(wenable2, 0);
}
