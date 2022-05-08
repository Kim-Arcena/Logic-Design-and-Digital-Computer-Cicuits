const int buttonPin = 12;  //This is the buttons read pin
const int ledPin = 13;    // This is the LED output pin

int ledState = HIGH;      //Variable for current LED state
int buttonCurrent;          //Variable for current button reading
int buttonPrevious = LOW;//Variable for last know button reading

unsigned long lastDebounceTime = 0; //last time the pin was toggled, used to keep track of time
unsigned long debounceDelay = 50;   //the debounce time which user sets prior to run

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  //read the button pin, if pressed will be high, if not pressed will be low
  buttonCurrent = digitalRead(buttonPin);
  

  if (buttonCurrent == HIGH && buttonPrevious == LOW)  {
    if(ledState == HIGH){
      ledState = Low;
    }
    else{
      ledState = HIGH;
    }
  }
  
  digitalWrite(led, ledState);
  buttonPrevious = buttonCurrent;

}