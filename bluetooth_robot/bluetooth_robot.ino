#include<SoftwareSerial.h>

SoftwareSerial bluee(2,3); //rx,tx

#define horn 4

#define mot1 5 
#define mot2 6
#define mot3 9
#define mot4 10

#define fr_light 7
#define bk_light 8
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluee.begin(9600);

  pinMode(horn,OUTPUT);
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  pinMode(fr_light,OUTPUT);
  pinMode(bk_light,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bluee.available()>0){
    char data=bluee.read();
    Serial.println("\n recieved data from app "+(String) data);

    switch(data){
      case 'F' : forward(); break;

      case 'B' : backward(); break;

      case 'R' : right(); break;

      case 'L' : left(); break;

      case 'H' : digitalWrite(fr_light,HIGH); break;
      case 'h' : digitalWrite(fr_light,LOW); break;

      case 'G' : digitalWrite(bk_light,HIGH); break;
      case 'g' : digitalWrite(bk_light,LOW); break;

      case 'Y' : digitalWrite(horn,HIGH); break;
      case 'y' : digitalWrite(horn,LOW); break;
    }
  }
}

void forward(){
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,HIGH);
  digitalWrite(mot3,HIGH);
  digitalWrite(mot4,HIGH);
}
void backward(){
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,LOW);
  digitalWrite(mot3,LOW);
  digitalWrite(mot4,LOW);
}
void right(){
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,HIGH);
  digitalWrite(mot3,LOW);
  digitalWrite(mot4,HIGH);
}
void left(){
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
  digitalWrite(mot3,HIGH);
  digitalWrite(mot4,LOW);
}
