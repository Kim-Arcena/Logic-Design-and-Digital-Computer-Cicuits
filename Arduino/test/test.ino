int myVoltPin = A2;
int readVal;
float V2;
int delayT = 250;
int pin = 9;
long blink_interval = 0;           //1 second interval between blinks


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(myVoltPin, INPUT);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(myVoltPin);
  V2 = (5./1023.) * readVal;
  Serial.println("Volt count is");
  Serial.println(V2);

  if(V2 > 2.0){
    blink(V2);
  }
  else{
    digitalWrite(pin, LOW);
  }
  delay(delayT);
}

void blink(float V2){
 V2 = int(V2);
  for(int i = 1; i <= V2; i++){
    long blink_interval = (-1 * V2 + 6) * 1000;
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(blink_interval);
    Serial.println("Blinking Interval");
    Serial.println(blink_interval);
  }
}




