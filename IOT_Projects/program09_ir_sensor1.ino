// C++ code
//
  
#include <IRremote.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

IRrecv irrecv(2);
decode_results results;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.init(); 
  //lcd.backlight(); 
  Serial.begin(9600);
  
  irrecv.enableIRIn(); 
}

void loop()
{
  
  if (IrReceiver.decode()) {
   Serial.println(IrReceiver.decodedIRData.command);
   	switch(IrReceiver.decodedIRData.command) {        
        case 17://Button 2
      		lcd.clear();
 	 		lcd.setCursor(0, 0);
  			lcd.print("OFF");
      		lcd.noBacklight();
          	break;
        case 16://Button 1
      		lcd.clear();
 	 		lcd.setCursor(0, 0);
      		lcd.backlight();
  			lcd.print("ON");
			break;
        default: Serial.println(IrReceiver.decodedIRData.command);     
    }     
    IrReceiver.resume();
  }  
}