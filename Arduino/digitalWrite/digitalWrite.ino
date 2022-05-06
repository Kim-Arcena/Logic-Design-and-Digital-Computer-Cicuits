int ledPin = 13;                 // LED connected to digital pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(5000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(5000);                  // waits for a second
}
