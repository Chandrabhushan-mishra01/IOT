// C++ code
//

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

int triggerPin = 7;
int echoPin = 8;
int ledPin = 2;
int buzzerPin = 4;

float distance = 0;
float speed = 0.0347;
int threshold = 50;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init(); 
  lcd.backlight(); 
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop()
{
  
  lcd.setCursor(0, 1);
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  //Serial.println("trigger low");
  
  distance = speed*pulseIn(echoPin, HIGH)/2;
  
  lcd.print(distance);
  
  if(distance<threshold){
  	digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 500, 100);
  }else{
  	digitalWrite(ledPin, LOW);
  }
}