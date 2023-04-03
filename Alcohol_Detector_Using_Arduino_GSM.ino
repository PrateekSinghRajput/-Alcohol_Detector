#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define rxPin 3
#define txPin 2

SoftwareSerial sim800(rxPin, txPin);
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int MQ3Sensor = A0;
int relay = 4;
int buzzer = 6;
int sensorThres = 400;

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
  sim800.println("AT");
  lcd.begin(16, 2);
  pinMode(MQ3Sensor, INPUT);
  pinMode(relay, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
  lcd.clear();
  int analogSensor = analogRead(MQ3Sensor);

  Serial.println(analogSensor);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALCOHOL L:- ");
  lcd.setCursor(12, 0);
  lcd.print(analogSensor);
  lcd.setCursor(0, 1);
  if (analogSensor > sensorThres) {
    lcd.print("YOU DRUNK.......");
    digitalWrite(relay, LOW);
     digitalWrite(buzzer, HIGH);

  } else {

    lcd.print("NORMAL LEVEL....");
    digitalWrite(relay, HIGH);
     digitalWrite(buzzer, LOW);
  }
  delay(100);
}

void SendMessage() {
  Serial.println("Alcohal");
  sim800.println("AT+CMGF=1");
  delay(1000);
  sim800.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  sim800.println("Alcohal Detected I Then This Person Is Drunk ");
  delay(100);
  sim800.println((char)26);
  delay(1000);
}
