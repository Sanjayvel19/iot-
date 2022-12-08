#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

const int buzzer = 8;
const int light = 7;
const int light1 = 6;
const int light2 = 5; 


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  Serial.println("Temperature & Humidity Reading Program");
  Serial.println(F("DHT11 test!"));
  dht.begin();
}

void loop() {
  digitalWrite(light,LOW);
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT Sensor!"));
    digitalWrite(light,HIGH);
    return;
  }
  
  float hif = dht.computeHeatIndex(f,h);
  float hic = dht.computeHeatIndex(t,h,false);

  Serial.print(F("Humidity:"));
  Serial.print(h);
  Serial.print(F("%Temperature:"));
  Serial.print(t);
  Serial.print(F("C"));
  Serial.print(f);
  Serial.print(F("F Heat index:"));
  Serial.print(hic);
  Serial.print(F("c"));
  Serial.print(hif);
  Serial.println(F("F"));

  if(t>29){
    tone(buzzer,1000);
    delay(1000);
    digitalWrite(light1,HIGH);
    digitalWrite(light2,LOW);
    tone(buzzer,500);
    noTone(buzzer);
    Serial.println("Alert:HIGH Temperature");
  }
  else{
    Serial.println("Alert:LOW Temperature");
    digitalWrite(light2,HIGH); 
  }
  delay(2000);
  digitalWrite(light1,LOW);
}
