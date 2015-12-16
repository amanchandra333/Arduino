int ap1 = A4; 
int sv1 = 0;        
int ov1 = 0;
int winput1=48;
int winput2=46;
int winput3=52;
int winput4=50;
int finput3=38;
int finput4=36;

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
void loop() {
  sv1 = analogRead(ap1);            
  delay(5);
  Serial.println(sv1);
  
  if(sv1>420)
  {
    //forklift up
    digitalWrite(finput3, LOW);
    digitalWrite(finput4, HIGH);
    Serial.print(" up");
  }
  else if(sv1<330)
  {
    //forklift down
    digitalWrite(finput3, HIGH);
    digitalWrite(finput4, LOW);
    Serial.print(" down");
  }
  else
  {
    digitalWrite(finput3, LOW);
    digitalWrite(finput4, LOW);
  }
}
