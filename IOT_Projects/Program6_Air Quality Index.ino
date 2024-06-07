  // C++ code

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
  }

  void loop()
  {
    float answer = analogRead(A0);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Air Quality");
    lcd.setCursor(0, 1);

    answer = map(answer,85,370,0,500);
    lcd.print(answer);
    if(answer<50){
      digitalWrite(2, HIGH); 
      digitalWrite(3, LOW); 
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      noTone(7);
    }else if(answer<100){
      digitalWrite(2, LOW); 
      digitalWrite(3, HIGH); 
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      noTone(7);
    }else if(answer<150){
      digitalWrite(2, LOW); 
      digitalWrite(3, LOW); 
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      noTone(7);
    }else{
      digitalWrite(2, LOW); 
      digitalWrite(3, LOW); 
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      tone(7,500);
    }

    delay(100);

  }