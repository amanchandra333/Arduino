int pin2=31;
int pin3=33;
int pin4=49;
int pin5=45;
int pin6=41;
int pin7=43;
int pin8=47;
int pin9=53;

void setup() {               
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

void loop() {
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
}
