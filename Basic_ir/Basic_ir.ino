int A=A3;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(analogRead(A));
  delay(200);
}
