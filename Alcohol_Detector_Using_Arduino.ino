#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
int MQ3Sensor = A0;
int relay = 4;
int sensorThres = 400;

void setup()
{
lcd.begin(16,2);                

  pinMode(MQ3Sensor, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
lcd.clear();
int analogSensor = analogRead(MQ3Sensor);

Serial.println(analogSensor);

lcd.clear();
    lcd.setCursor(0,0);
lcd.print("ALCOHOL DETECTOR");
lcd.setCursor(0,1);
  if (analogSensor > sensorThres)
  {  
lcd.print("YOU DRUNK.......");
digitalWrite(relay,LOW);

  }
  else
  {
    
lcd.print("NORMAL LEVEL....");
digitalWrite(relay,HIGH);
  }
  delay(100);

}
