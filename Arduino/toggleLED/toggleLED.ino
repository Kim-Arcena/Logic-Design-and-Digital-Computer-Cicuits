// constants won't change
const int buttonPin = 7;       // Connect the Button to pin 7 
const int ledPin    = 3;       // Connect the LED to pin 3 
// variables will change:
// int buttonState;
int ledState = HIGH;                           // tracks the current state of LED
int btnState;                       // the current state of button
int lastBtnState = LOW;                     // the previous state of button
int prevState;

unsigned long previousMillis = 0; 
unsigned long lastDebounceTime = 50; 
unsigned long debounceDelay = 0; 
const long longPress = 5000; 
const long interval = 1000; 

void setup() { //Setup input and output pins using pinMode 
	pinMode(buttonPin, INPUT); 
	pinMode(ledPin, OUTPUT); 
	digitalWrite(ledPin, ledState); //initialize LED state 
	Serial.begin(9600); 			//IntetaLtze Serial monitor 
	Serial.println("Normal Mode"); 
}
  
void loop() {
  int reading = digitalRead(buttonPin);
  prevState = -1;
  

  if (reading != lastBtnState) {
    
    lastDebounceTime = millis();
  }


  if(((millis() - lastDebounceTime) > longPress) && (reading == HIGH)){

    while(true) {
      int currentState = digitalRead(buttonPin);
      unsigned long currentMillis = millis();

      
      if(currentState == HIGH && prevState == LOW ) {
        ledState = HIGH;
        digitalWrite(ledPin, ledState);

        Serial.println("Normal Mode");
        lastDebounceTime = millis();

        
        
        while(true){
          int currentState = digitalRead(buttonPin);

          if(currentState = LOW){
            break;
          }
        }
        break;
      }


      else if (currentMillis - previousMillis >= interval){
        previousMillis = currentMillis;

        if(ledState == LOW) {
          ledState = HIGH;  
        }
        else {
          ledState = LOW;
        
        }
    
        // control LED arccoding to the toggled state
        digitalWrite(ledPin, ledState);  //turns the LED on or off based on the variable
      }
      prevState  = currentState;                // save the last state
    }
  }

  else if((millis() - lastDebounceTime) > debounceDelay){

    if(reading != btnState){
      btnState = reading;


      if(btnState == HIGH){
        ledState = !ledState;
        Serial.println("Clicked");
      }
    }
  }

  digitalWrite(ledPin, ledState);


  lastBtnState = reading;

}