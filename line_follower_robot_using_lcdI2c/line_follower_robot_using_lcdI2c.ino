#include <LiquidCrystal_I2C.h>

//intailize motors and enable pin
#define mt1 11
#define mt2 10
#define en1 9

#define en2 6
#define mt3 5
#define mt4 3

//intialize ir sensors
#define ir_left 2
#define ir_right 12

LiquidCrystal_I2C lcd(0x20,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.print(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("LINE FOLLOWER");
  lcd.setCursor(5,1);
  lcd.print("ROBOT");
  delay(1000);
  lcd.clear();

  pinMode(mt1,OUTPUT);
  pinMode(mt2,OUTPUT);
  pinMode(en1,OUTPUT);
  
  pinMode(en2,OUTPUT);
  pinMode(mt3,OUTPUT);
  pinMode(mt4,OUTPUT);
  
  pinMode(ir_left,INPUT);
  pinMode(ir_right,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir_left_val= digitalRead(ir_left);
  int ir_right_val= digitalRead(ir_right);
  lcd.clear();
  if(ir_left_val==1 && ir_right_val==1){
    Serial.print("moving forward");
    lcd.setCursor(5,0);
    lcd.print("moving");
    lcd.setCursor(4,1);
    lcd.print("forward");
    forward();
  }
  else if(ir_left_val==0 && ir_right_val==1){
    Serial.print("turning right");
    lcd.setCursor(5,0);
    lcd.print("turning");
    lcd.setCursor(4,1);
    lcd.print("right");
    right();
  }

  else if(ir_left_val==1 && ir_right_val==0){
    Serial.print("turning left");
    lcd.setCursor(5,0);
    lcd.print("turning");
    lcd.setCursor(4,1);
    lcd.print("left");
    left();
  }

  else{
    Serial.print("moving backward");
    lcd.setCursor(5,0);
    lcd.print("moving");
    lcd.setCursor(4,1);
    lcd.print("backward");
    backward();
  }
  
  
}
void forward(){
  digitalWrite(mt1,HIGH);
  digitalWrite(mt2,LOW);
  digitalWrite(mt3,HIGH);
  digitalWrite(mt4,LOW);
  
}
void backward(){
  digitalWrite(mt1,LOW);
  digitalWrite(mt2,HIGH);
  digitalWrite(mt3,LOW);
  digitalWrite(mt4,HIGH);
}
void right(){
  digitalWrite(mt1,LOW);
  digitalWrite(mt2,HIGH);
  digitalWrite(mt3,HIGH);
  digitalWrite(mt4,LOW);
}
void left(){
  digitalWrite(mt1,HIGH);
  digitalWrite(mt2,LOW);
  digitalWrite(mt3,LOW);
  digitalWrite(mt4,HIGH);
}
