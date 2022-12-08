const int ledPin = 13;
const int soundPin =A2;
const int threshold = 100;

void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(soundPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(soundPin);
  Serial.println(value);
  if(value>=threshold){
    digitalWrite(ledPin,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(ledPin,LOW);
    delay(500);
  }
}
