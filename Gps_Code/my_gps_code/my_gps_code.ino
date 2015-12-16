#include <string.h>
char lati[9],longi[10];
double LATI,LONGI;
char gpstr[5],b;
int j;
void getlatilongi(void)
{
int flag=0;
while(flag==0)
{
  while(b!='$')
  {
     while(Serial.available()==0);
     b=Serial.read();
  }
  while(Serial.available()==0);
  for(b=Serial.read(),j=0;b!=',';j++)
  {
     gpstr[j]=b; 
     while(Serial.available()==0);
     b=Serial.read();
  }
  if (strcmp(gpstr,"GPGGA")==0)
  {
     flag=1;
     while(Serial.available()==0);
     for(b=Serial.read();b!=',';)
     {
      while(Serial.available()==0);
      b=Serial.read();
     }
     while(Serial.available()==0);
     for(b=Serial.read(),j=0;b!=',';j++)
     {
       lati[j]=b; 
       while(Serial.available()==0);
       b=Serial.read();
     }
     while(Serial.available()==0);
     for(b=Serial.read();b!=',';)
     {
      while(Serial.available()==0);
      b=Serial.read();
     }
     while(Serial.available()==0);
     for(b=Serial.read(),j=0;b!=',';j++)
     {
       longi[j]=b; 
       while(Serial.available()==0);
       b=Serial.read();
     }
  }
}
}
void setup()
{
Serial.begin(9600);
for(int i=0;i<9;i++)
{
  lati[i]='0';
  longi[i]='0';
}
b='a';  
}
void loop()
{
  getlatilongi();
  for(int i=0;i<9;i++)
  {
    Serial.print(lati[i]);
  }
  Serial.print("              ");
  for(int i=0;i<10;i++)
  {
    Serial.print(longi[i]);
  }
  Serial.println(';');
  delay(200);
}
