//
#include <PulseSensorPlayground.h>

#include <LiquidCrystal.h>

#include <CircularBuffer.h>
#include <MAX30100.h>
#include <MAX30100_BeatDetector.h>
#include <MAX30100_Filters.h>
#include <MAX30100_PulseOximeter.h>
#include <MAX30100_Registers.h>
#include <MAX30100_SpO2Calculator.h>

//intialization
const int rs=7,en=6,d4=5,d5=4,d6=3,d7=2;

const int ir_bed=8;
const int led_pin=9;
const int buzz_pin=11;

const int temp_pin=A0;
const int pulse_pin=1;//connected to analog pin 1 through given library
const int threshold_temp=99;
const int threshold_pulse=550;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
PulseSensorPlayground pulsesensor;
PulseOximeter pox;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Smart Health Moni");
  lcd.setCursor(0,1);
  lcd.print("toring System");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp:");
  lcd.setCursor(11,0);
  lcd.print("*c");
  
  lcd.setCursor(0,1);
  lcd.print("BPM:");
  lcd.setCursor(6,1);
  lcd.print("spO2");
  lcd.setCursor(15,1);
  lcd.print("%");

  pinMode(ir_bed,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(buzz_pin,OUTPUT);

  pulsesensor.analogInput(pulse_pin);
  pulsesensor.setThreshold(threshold_pulse);

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int ir_bed_val=digitalRead(ir_bed);
  if(ir_bed_val==HIGH){
    digitalWrite(led_pin,1);
   
    int val_temp=analogRead(temp_pin);
    float totaltemp=(val_temp/1024.0)*5000;
    float cel=totaltemp/10;
    Serial.print("temp");
    Serial.println(cel);

    lcd.setCursor(5,0);
    lcd.print(cel);

    int bpm=pulsesensor.getBeatsPerMinute();
    Serial.print("BPM:");
    Serial.println(bpm);

    lcd.setCursor(4,1);
    lcd.print(bpm);
    
    if(cel>=threshold_temp && bpm>=threshold_pulse){
      digitalWrite(buzz_pin,true);
      digitalWrite(led_pin,true);
      delay(1000);
      digitalWrite(led_pin,false);
      delay(1000);
    }
    else{digitalWrite(buzz_pin,false);}

    int spo2=pox.getspo2();

    Serial.print("spO2");
    Serial.println(spo2);
    
    lcd.setCursor(10,1);
    lcd.print(spo2);
    
  }
  else{
    digitalWrite(led_pin,0);
  }

  
}
