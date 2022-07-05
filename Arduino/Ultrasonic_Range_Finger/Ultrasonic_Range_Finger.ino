const int trigPin = 10;
const int echoPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;       // (time in d = s x t)multiplied by the speed of sound converted 
                                            // from meters per second to centimeters per µs (0.0344 cm/µs)
  Serial.print("Distance = ");
  if(distance >= 400 || distance <= 2){  
    Serial.println("Out of range"); 
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
}
