#define FORCE_SENSOR_PIN A0


void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  Serial.print("Force sensor reading=");
  Serial.print(analogReading);
  if(analogReading<10)
    Serial.print("-> No pressure");
  else if(analogReading<200)
    Serial.print("-> light touch");
  else if(analogReading<500)
    Serial.print("-> light pressure");
  else if(analogReading<800)
    Serial.print("-> medium pressure");
  else
    Serial.print("-> high pressure");

  delay(1000);
}
