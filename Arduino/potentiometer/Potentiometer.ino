int ledPin = 3;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPin)/ 4;
  analogWrite(ledPin, potValue);
}
