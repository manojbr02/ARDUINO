#include <SoftwareSerial.h>
// for the bluetooth module 
SoftwareSerial blue(2,3);//rx,tx

#define r1_hall 11
#define r2_bed 10
#define r3_fan 9


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blue.begin(9600);
  pinMode(r1_hall,OUTPUT);
  pinMode(r2_bed,OUTPUT);
  pinMode(r3_fan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(blue.available());{
    char data=blue.read();
    Serial.println("recieved data from app"+(String) data);
    // I used a app called bluettoth switches where ,it has so many switches we can implement through that, so i used only three of them
    switch(data){
      case 'A' : digitalWrite(r1_hall,HIGH); break;

      case 'a' : digitalWrite(r1_hall,LOW); break;
      
      case 'B' : digitalWrite(r2_bed,HIGH); break;
      
      case 'b' : digitalWrite(r2_bed,LOW); break;
      
      case 'C' : digitalWrite(r3_fan,HIGH); break;
      
      case 'c' : digitalWrite(r3_fan,LOW); break;

      default : break;
    }
   }
}
