#include<Wire.h>
int input1=12;
int input2=13;
int enable1=8;
int enable2=11;
int input3=10;
int input4=9;
const int MPU=0x68;  // I2C address of the MPU-6050
int16_t acc_x,acc_y,acc_z,Tmp,GyX,GyY,GyZ;
#define x_min -16000
#define x_max 17000
#define y_min -18000
#define y_max 17000
#define base_x 7000
#define base_y -1000
#define threshold_x 6000
#define threshold_y 5000

void setup()
{
      pinMode(input1,OUTPUT);
      pinMode(input2,OUTPUT);
      pinMode(input3,OUTPUT);
      pinMode(input4,OUTPUT);
      pinMode(enable1,OUTPUT);
      pinMode(enable2,OUTPUT);
      Wire.begin();
      Wire.beginTransmission(MPU);
      Wire.write(0x6B);  // PWR_MGMT_1 register
      Wire.write(0);     // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);
      Serial.begin(9600);
}
void motion (int acc_x, int acc_y, int acc_z) 
{
      if((acc_x >= (base_x+threshold_x)) && (acc_y <= (base_y+threshold_y)) && (acc_y >= (base_y-threshold_y)))
      {
            float feeder = acc_x;
            digitalWrite(input2, HIGH);
            digitalWrite(input4, HIGH);
            digitalWrite(input1, LOW);
            digitalWrite(input3, LOW);
            feeder=map(feeder, base_x+threshold_x, x_max, 0, 255);
            analogWrite(enable1,feeder);
            analogWrite(enable2,feeder);
            Serial.print(" | reverse");
            //reverse
      }
      else if((acc_x <= (base_x-threshold_x)) && (acc_y <= (base_y+threshold_y)) && (acc_y >= (base_y-threshold_y)))
      {
            float feeder = acc_x;
            digitalWrite(input1, HIGH);
            digitalWrite(input3, HIGH);
            digitalWrite(input2, LOW);
            digitalWrite(input4, LOW);
            feeder=map(feeder, x_min, base_x-threshold_x, 255, 0);
            analogWrite(enable1,feeder);
            analogWrite(enable2,feeder);
            Serial.print(" | forward");
            //forward
      }
      else if((acc_y >= (base_y+threshold_y)) && (acc_x <= (base_x+threshold_x)) && (acc_x >= (base_x-threshold_x)))
      {
            float feeder = acc_y;
            digitalWrite(input1, HIGH);
            digitalWrite(input4, HIGH);
            digitalWrite(input2, LOW);
            digitalWrite(input3, LOW);
            feeder=map(feeder, base_y+threshold_y, y_max, 0, 255);
            analogWrite(enable1,feeder);
            analogWrite(enable2,feeder);
            Serial.print(" | right");
            //right
      }
      else if((acc_y <= (base_y-threshold_y)) && (acc_x <= (base_x+threshold_x)) && (acc_x >= (base_x-threshold_x)))
      {
            float feeder = acc_y;
            digitalWrite(input2, HIGH);
            digitalWrite(input3, HIGH);
            digitalWrite(input1, LOW);
            digitalWrite(input4, LOW);
            feeder=map(feeder, y_min, base_y-threshold_y, 255, 0);
            analogWrite(enable1,feeder);
            analogWrite(enable2,feeder);
            Serial.print(" | left");
            //left
      }
      else
      {
            digitalWrite(input2, HIGH);
            digitalWrite(input3, HIGH);
            digitalWrite(input1, HIGH);
            digitalWrite(input4, HIGH);
            analogWrite(enable1,255);
            analogWrite(enable2,255);
      }
      /*
      else if((acc_x >= (base_x+threshold_x)) && (acc_y >= (base_y+threshold_y)))
      {
            float feeder1 = acc_x;
            float feeder2 = acc_y;
            digitalWrite(input1, HIGH);
            digitalWrite(input4, LOW);
            digitalWrite(input2, LOW);
            digitalWrite(input3, LOW);
            map(feeder1, base_x+threshold_x, x_max, 0, 255);
            map(feeder2, base_y+threshold_y, y_max, 0, 255);
            analogWrite(enable1,feeder1);
            analogWrite(enable2,feeder2);
            //forward right
      }
      else if((acc_x >= (base_x+threshold_x)) && (acc_y <= (base_y-threshold_y)))
      {
            float feeder1 = acc_x;
            float feeder2 = acc_y;
            digitalWrite(input1, LOW);
            digitalWrite(input3, HIGH);
            digitalWrite(input2, LOW);
            digitalWrite(input4, LOW);
            map(feeder1, base_x+threshold_x, x_max, 0, 255);
            map(feeder2, y_min, base_y-threshold_y, 255, 0);
            analogWrite(enable1,feeder1);
            analogWrite(enable2,feeder2);
            //forward left
      }
      else if((acc_x <= (base_x-threshold_x)) && (acc_y >= (base_y+threshold_y)))
      {
            float feeder1 = acc_x;
            float feeder2 = acc_y;
            digitalWrite(input2, HIGH);
            digitalWrite(input4, LOW);
            digitalWrite(input1, LOW);
            digitalWrite(input3, LOW);
            map(feeder1, x_min, base_x-threshold_x, 255, 0);
            map(feeder2, base_y+threshold_y, y_max, 0, 255);
            analogWrite(enable1,feeder1);
            analogWrite(enable2,feeder2);
            //backward right
      }
      else if((acc_x <= (base_x-threshold_x)) && (acc_y <= (base_y-threshold_y)))
      {
            float feeder1 = acc_x;
            float feeder2 = acc_y;
            digitalWrite(input2, LOW);
            digitalWrite(input4, HIGH);
            digitalWrite(input1, LOW);
            digitalWrite(input3, LOW);
            map(feeder1, x_min, base_x-threshold_x, 255, 0);
            map(feeder2, y_min, base_y-threshold_y, 255, 0);
            analogWrite(enable1,feeder1);
            analogWrite(enable2,feeder2);
            //backward left
      }
      */
}
void loop()
{
      Wire.beginTransmission(MPU);
      Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
      Wire.endTransmission(false);
      Wire.requestFrom(MPU,14,true);  // request a total of 14 registers
      acc_x=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
      acc_y=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      acc_z=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
      Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
      GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
      GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
      GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
      Serial.print("AcX = "); Serial.print(acc_x);
      Serial.print(" | AcY = "); Serial.println(acc_y);
      //Serial.print(" | AcZ = "); Serial.print(acc_z);
      //Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
      //Serial.print(" | GyX = "); Serial.print(GyX);
      //Serial.print(" | GyY = "); Serial.print(GyY);
      //Serial.print(" | GyZ = "); Serial.println(GyZ);
      motion(acc_x, acc_y, acc_z);
      delay(300);
}
