// constants won't change
const int button_pin = 7;                      // Connect the Button to pin 7 
const int LED_pin    = 3;                       // Connect the LED to pin 3 
const long longPress = 5000;                    // longpress duration
const long interval = 1000;                     // 1 second interval for the blinking

// variables will change:
int button_state;                               // the current state of button
int prevButton_state = LOW;                     // the previous state of button
int LED_state = HIGH;                           // tracks the current state of LED
int prevState;                                

unsigned long previousMillis = 0;               //prevMillis is the previous time the loop ran
unsigned long lastDebounceTime = 50;            //lastDebounceTime is the last time the button was toggled
unsigned long debounceDelay = 0;                //debounceDelay is the debounce time

void setup() {                                  //Setup input and output pins using pinMode 
	pinMode(button_pin, INPUT);                 //set button_pin to be an input
	pinMode(LED_pin, OUTPUT);                   //set LED_pin to be an output    
	digitalWrite(LED_pin, LED_state);           //initialize LED state 
	Serial.begin(9600); 		                //Start the serial communication
	
}
  
void loop() {
  int reading = digitalRead(button_pin);        //read the state of the button
  prevState = -1;                               //            
  

  if (reading != prevButton_state) {            //if the button state has changed
    lastDebounceTime = millis();                //update the lastDebounceTime            
  }

  if((millis() - lastDebounceTime) > debounceDelay){                        //if the button is not pressed for more than debounceDelay (50 milliseconds)           

    if(reading != button_state){                                                 //if the button state has changed   
      button_state = reading;                                                    //update the button_state           

      if(button_state == HIGH){                                                  //if the button is pressed   
        LED_state = !LED_state;                                                  //toggle the LED state                                                      
      }
    }
  }

  else if((millis() - lastDebounceTime) > longPress && button_state == HIGH){        //if the button is pressed for more than longPress (5 seconds)

    while(true) {                                                               //while true
      int currentState = digitalRead(button_pin);                               //read the state of the button
      unsigned long currentMillis = millis();                                   //initialize the currentMillis    

      
      if(currentState == HIGH && prevState == LOW ) {                           //if the button is pressed and the previous state is LOW
        LED_state = HIGH;                                                       //set the LED state to HIGH    
        digitalWrite(LED_pin, LED_state);                                       //write the LED state to the LED pin        

        Serial.println("Normal Mode");
        lastDebounceTime = millis();
        
        while(true){                                                            
          int currentState = digitalRead(button_pin);                           //read the state of the button        

          if(currentState == LOW){                                              //if the button is pressed            
            break;                                                              
          }
        }
        break;
      }


      else if (currentMillis - previousMillis >= interval){                     //if the currentMillis - previousMillis is greater than or equal to interval (1 second)
        previousMillis = currentMillis;                                         //update the previousMillis    

        if(LED_state == LOW) {                                                  //if the LED state is LOW, set the LED state to HIGH
          LED_state = HIGH;                                                     
        }
        else {
          LED_state = LOW;                                                       //else, set the LED state to LOW           
        
        }
    
        digitalWrite(LED_pin, LED_state);                                       
      }
      prevState  = currentState;                                                 //update the prevState
    }
  }

  digitalWrite(LED_pin, LED_state);                                              //write the LED state to the LED pin
  prevButton_state = reading;                                                    //       

}