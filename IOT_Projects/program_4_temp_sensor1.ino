// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float temp = analogRead(A4)*5.0/1024.0;
  temp=(temp-0.5)*100.0;
  float moisture=analogRead(A0);
  moisture = moisture/1023*100;
  Serial.print("Humidity: ");
  Serial.println(moisture);
  if(temp>45){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }else if(temp>=35){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }else if(temp>=30){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }else{
   	digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
}