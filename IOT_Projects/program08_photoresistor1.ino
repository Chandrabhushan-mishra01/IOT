// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(A5);
  if(reading<300){
  	digitalWrite(2, HIGH);
  }else{
  	digitalWrite(2, LOW);
  }
}