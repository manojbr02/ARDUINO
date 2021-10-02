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

  lcd.begin(20,4);
  lcd.clear();
  lcd.setCursor(5,1);
    lcd.print("Smart Car");
  lcd.setCursor(3,2);
    lcd.print("Parking System");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1,0);
    lcd.print("ENTRY:");
  lcd.setCursor(11,0);
    lcd.print("EXIT:");

  lcd.setCursor(1,2);
    lcd.print("SLOT1:");
  lcd.setCursor(11,2);
    lcd.print("SLOT2:");
  lcd.setCursor(1,4);
    lcd.print("SLOT3:");
  lcd.setCursor(11,4);
    lcd.print("SLOT4:");


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

      lcd.setCursor(7,0);
      lcd.print("ONN");
      delay(1000);
      myservo_entry.write(0);
      digitalWrite(led_entry,0);
      
      
  }
  else{
    myservo_entry.write(0);
    lcd.setCursor(7,0);
      lcd.print("OFF");
  }
  if(ir_exit_val==HIGH){
      myservo_exit.write(90);
      digitalWrite(led_exit,1);

      lcd.setCursor(16,0);
      lcd.print("ONN");
      delay(1000);
      myservo_exit.write(0);
      digitalWrite(led_exit,0);
      
  }
  else{
    myservo_exit.write(0);
    lcd.setCursor(16,0);
    lcd.print("OFF");
  }

  int slot1_ir_val=digitalRead(slot1_ir);
  int slot2_ir_val=digitalRead(slot2_ir);
  int slot3_ir_val=digitalRead(slot3_ir);
  int slot4_ir_val=digitalRead(slot4_ir);
  
   if(slot1_ir_val==HIGH){
      digitalWrite(slot1_led,1);
      lcd.setCursor(7,2);
      lcd.print("OCC");
     
  }
  else{
    digitalWrite(slot1_led,0);
    lcd.setCursor(7,2);
    lcd.print("VAC");
  }

  if(slot2_ir_val==HIGH){
      digitalWrite(slot2_led,1);
      lcd.setCursor(17,2);
      lcd.print("OCC");
     
  }
  else{
    digitalWrite(slot2_led,0);
    lcd.setCursor(17,2);
    lcd.print("VAC");
  }

  if(slot3_ir_val==HIGH){
      digitalWrite(slot3_led,1);
      lcd.setCursor(7,3);
      lcd.print("OCC");
     
  }
  else{
    digitalWrite(slot3_led,0);
    lcd.setCursor(7,3);
    lcd.print("VAC");
  }

  if(slot4_ir_val==HIGH){
      digitalWrite(slot4_led,1);
      lcd.setCursor(17,3);
      lcd.print("OCC");
     
  }
  else{
    digitalWrite(slot4_led,0);
    lcd.setCursor(17,3);
    lcd.print("VAC");
  }
}
