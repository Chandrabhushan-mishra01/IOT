#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
int ledPin=3;
int IRPin=2;
int IRremote=0;
int ledState=0;

void setup(){
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("IR Sensor");
  delay(1000);
  lcd.clear();
}

void loop() {
  IRremote =digitalRead(2);
  Serial.println(IRremote);
  delay(50);
  
  if(IRremote==LOW){
    
    if( ledState==0){
    digitalWrite(3, HIGH);
    
    lcd.setCursor(4,0);
    lcd.print("LED HIGH");
    
      ledState=1;
  }
  
    else{
    digitalWrite(3,LOW);
    
    lcd.setCursor(4,0);
    lcd.print("LED LOW ");
    
      ledState=0;
  }
 }
}