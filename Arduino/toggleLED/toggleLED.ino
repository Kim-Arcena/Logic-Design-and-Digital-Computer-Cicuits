int led = 13;    // This is the LED output pin
int button = 12;  //This is the buttons read pin

int ledState = HIGH;      //Variable for current LED state
int buttonCurrent;          //Variable for current button reading
int buttonPrevious = LOW;   //Variable for last know button reading

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop() {
  //read the button pin, if pressed will be high, if not pressed will be low
  buttonCurrent = digitalRead(button);
  

  if (buttonCurrent == HIGH && buttonPrevious == LOW)  {
    if(ledState == HIGH){
      ledState = LOW;
    }
    else{
      ledState = HIGH;
    }
  }
  
  digitalWrite(led, ledState);
  
  buttonPrevious = buttonCurrent;

}