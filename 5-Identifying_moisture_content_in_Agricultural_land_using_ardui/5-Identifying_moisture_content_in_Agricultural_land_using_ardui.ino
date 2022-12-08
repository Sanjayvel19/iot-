#include<Wire.h>

const int buzzer = 11;
const int light = 13;
const int light1 = 10;
const int light2 = 12;

int moisture;

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(9,OUTPUT); 
  Serial.println("soil Moisture Program");
}

void loop() {
  int SensorValue = analogRead(A0);
  moisture = (100-((SensorValue/1023.00)*100));
  Serial.print(moisture);
  Serial.println("%");
  Serial.println("-----");
  if(SensorValue<1000 && SensorValue>=600){
    digitalWrite(9,LOW);
    Serial.println("DRY  SOIL");
    digitalWrite(light,HIGH);
    tone(buzzer,1000);
    delay(1000);
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    tone(buzzer,500);
    noTone(buzzer);
  }
  if(SensorValue<600 && SensorValue>=370){
    digitalWrite(9,HIGH);
    Serial.println("HUMID  SOIL");
    digitalWrite(light1,HIGH);
    digitalWrite(light2,LOW);
    digitalWrite(light,LOW);
    delay(1000);
  }
  if(SensorValue<370){
    digitalWrite(9,HIGH);
    Serial.println("WATER  SOIL");
    digitalWrite(light2,HIGH);
    digitalWrite(light,LOW);
    digitalWrite(light1,LOW);
    delay(1000);
  }
}
