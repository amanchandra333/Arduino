/*Motor Driver 1
 * enable2=blue 5v
 * 12v red
 * i3 black 38
 * o3 crimson
 * o4 black
 * i4 red next to blue 36
 * 5v red next to i4
 
 Motor Driver 2 for wheels
 * enable1=blue 5v
 * i1 = orange 48
 * o1 = baige
 * o2 = black
 * i2 = red next to blue 46
 * 12v =blue 12v
 * enable2= dark blue 5v
 * i3 = orange 52
 * o3 = red
 * o4 = baige
 * i4 = green 50
 * 5v = white 5v**/

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
     
void setup()
{
  Serial.begin(9600);
  pinMode(winput1,OUTPUT);
  pinMode(winput2,OUTPUT);
  pinMode(winput3,OUTPUT);
  pinMode(winput4,OUTPUT);
  pinMode(finput3,OUTPUT);
  pinMode(finput4,OUTPUT);
}
void loop()
{
  af = analogRead(apf);
  awx = analogRead(apwx);
  awy = analogRead(apwy);
  delay(5);
  
  delay(200);
  Serial.print(af);
  Serial.print(" ");
  Serial.print(awx);
  Serial.print(" ");
  Serial.print(awy);
  
  //forklift
  if(af>=f_upper)
  {
    //forklift up
    //digitalWrite(finput3, LOW);
    //digitalWrite(finput4, HIGH);
    Serial.print(" forklift up ");
  }
  else if(af<=f_lower)
  {
    //forklift down
    //digitalWrite(finput3, HIGH);
    //digitalWrite(finput4, LOW);
    Serial.print(" forklift down ");
  }
  else
  {
    Serial.print(" forklift stable ");
  }
  
  //motion
  if(awx<=wx_lower)// && awy<wy_middle_upper && awy>wy_middle_lower)
  {
    //forward
    //digitalWrite(winput1, HIGH);
    //digitalWrite(winput2, LOW);
    //digitalWrite(winput3, LOW);
    //digitalWrite(winput4, HIGH);
    Serial.println(" forward");
  }
  else if(awx>=wx_upper)// && awy<wy_middle_upper && awy>wy_middle_lower)
  {
    //back
    //digitalWrite(winput1, LOW);
    //digitalWrite(winput2, HIGH);
    //digitalWrite(winput3, HIGH);
    //digitalWrite(winput4, LOW);
    Serial.println(" back");
  }
  else if(awy>=wy_upper)// && awx>wx_middle_lower && awx<wx_middle_upper)
  {
    //left
    //digitalWrite(winput1, LOW);
    //digitalWrite(winput2, HIGH);
    //digitalWrite(winput3, LOW);
    //digitalWrite(winput4, HIGH);
    Serial.println(" left");
  }
  else if(awy<=wy_lower) // && awx>wx_middle_lower && awx<wx_middle_upper)
  {
    //right
    //digitalWrite(winput1, HIGH);
    //digitalWrite(winput2, LOW);
    //digitalWrite(winput3, HIGH);
    //digitalWrite(winput4, LOW);
    Serial.println(" right");
  }
  else
  {
    //free run
    Serial.println(" free run");
  }
}
