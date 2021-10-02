#include <LiquidCrystal.h>

#include <Servo.h>

const int rs=7,en=6,d4=5,d5=4,d6=3,d7=2;


LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

Servo myservo_entry;
Servo myservo_exit;

const int ir_entry=8;
const int ir_exit=10;

const int led_entry=12;
const int led_exit=13;

const int slot1_ir=22 ,slot1_led=23;
const int slot2_ir=24 ,slot2_led=25;
const int slot3_ir=26 ,slot3_led=27;
const int slot4_ir=28 ,slot4_led=29;
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(4,0);
    lcd.print("Smart Car");
  lcd.setCursor(1,1);
    lcd.print("Parking System");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("ENT:");
  lcd.setCursor(0,1);
    lcd.print("EXT:");

  lcd.setCursor(6,0);
    lcd.print("SL1:");
  lcd.setCursor(11,0);
    lcd.print("SR2:");
  lcd.setCursor(6,1);
    lcd.print("SL3:");
  lcd.setCursor(11,1);
    lcd.print("SL4:");


  myservo_entry.attach(9);
  myservo_exit.attach(11);

  pinMode(ir_entry,INPUT);
  pinMode(ir_exit,INPUT);
  pinMode(led_entry,OUTPUT);
  pinMode(led_exit,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir_entry_val=digitalRead(ir_entry);
  int ir_exit_val=digitalRead(ir_exit);

  if(ir_entry_val==HIGH){
      myservo_entry.write(90);
      digitalWrite(led_entry,1);

      lcd.setCursor(4,0);
      lcd.print("on");
      delay(1000);
      myservo_entry.write(0);
      digitalWrite(led_entry,0);
      
      
  }
  else{
    myservo_entry.write(0);
    lcd.setCursor(4,0);
      lcd.print("of");
  }
  if(ir_exit_val==HIGH){
      myservo_exit.write(90);
      digitalWrite(led_exit,1);

      lcd.setCursor(4,1);
      lcd.print("on");
      delay(1000);
      myservo_exit.write(0);
      digitalWrite(led_exit,0);
      
  }
  else{
    myservo_exit.write(0);
    lcd.setCursor(4,1);
    lcd.print("of");
  }

  int slot1_ir_val=digitalRead(slot1_ir);
  int slot2_ir_val=digitalRead(slot2_ir);
  int slot3_ir_val=digitalRead(slot3_ir);
  int slot4_ir_val=digitalRead(slot4_ir);
  
   if(slot1_ir_val==HIGH){
      digitalWrite(slot1_led,1);
      lcd.setCursor(10,0);
      lcd.print("O");
     
  }
  else{
    digitalWrite(slot1_led,0);
    lcd.setCursor(10,0);
    lcd.print("V");
  }

  if(slot2_ir_val==HIGH){
      digitalWrite(slot2_led,1);
      lcd.setCursor(15,0);
      lcd.print("O");
     
  }
  else{
    digitalWrite(slot2_led,0);
    lcd.setCursor(15,0);
    lcd.print("V");
  }

  if(slot3_ir_val==HIGH){
      digitalWrite(slot3_led,1);
      lcd.setCursor(10,1);
      lcd.print("O");
     
  }
  else{
    digitalWrite(slot3_led,0);
    lcd.setCursor(10,1);
    lcd.print("V");
  }

  if(slot4_ir_val==HIGH){
      digitalWrite(slot4_led,1);
      lcd.setCursor(15,1);
      lcd.print("O");
     
  }
  else{
    digitalWrite(slot4_led,0);
    lcd.setCursor(15,1);
    lcd.print("V");
  }
}
