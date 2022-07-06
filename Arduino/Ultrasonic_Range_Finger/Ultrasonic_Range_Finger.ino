#include<dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int trigPin = 10;
const int echoPin = 13;
const int DHT11_Pin = 7;
LiquidCrystal_I2C lcd(0x27,16,2); 

dht DHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  lcd.begin();                                                  //initialize the lcd
  lcd.backlight();  
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance, speed; 
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  speed = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity);
  distance = (duration / 2) * (speed / 10000);
  
  Serial.print("Distance = ");
  lcd.print("Distance=");
  if(distance >= 10000 || distance <= 1){  
    Serial.println("Out of range"); 
    lcd.print("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    lcd.print(distance);
    lcd.println("cm ");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
