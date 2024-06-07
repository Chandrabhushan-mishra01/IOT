// C++ code
//
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  lcd.init(); 
  lcd.backlight(); 
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
}

void loop()
{
  float moisture=analogRead(A0);
  lcd.setCursor(0, 1);
  lcd.print(moisture);
  if(moisture<150){
  	digitalWrite(5, HIGH);  
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    tone(2, 500, 100);
  }else if(moisture<500){
  	digitalWrite(5, LOW);  
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }else{
  	digitalWrite(5, LOW);  
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  }
  Serial.println(moisture);
}