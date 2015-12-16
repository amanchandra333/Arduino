char gpstr[10];
void getlatilongi()
{
  while(Serial.available()==0);
  char a=Serial.read();
} 

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available()==0);
  char a=Serial.read();
  Serial.print(a);
}
