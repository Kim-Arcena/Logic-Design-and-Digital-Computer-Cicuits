// constants won't change
const int button_pin = 7;       // Connect the Button to pin 7 
const int LED_pin    = 3;       // Connect the LED to pin 3 
const long longPress = 5000; 
const long blink_interval = 1000; 

// variables will change:
int LED_state = HIGH;                           // tracks the current state of LED
int blinking_State;                             // tracks the current state of LED
int button_state;                               // the current state of button
int lastButton_state = LOW;                     // the previous state of button

unsigned long previousMillis = 0;         
unsigned long lastDebounceTime = 50; 
unsigned long debounceDelay = 0; 

void setup() { //Setup input and output pins using pinMode 
    Serial.begin(9600);                         //Start the serial communication
	
    pinMode(button_pin, INPUT);                 //set button_pin to be an input
    pinMode(LED_pin, OUTPUT);                   //set LED_pin to be an output
    digitalWrite(LED_pin, LED_state);           //initialize LED state
    
}
  
void loop() {                                                           
  int currentButton_State = digitalRead(button_pin);                          //read the current state of the button              
  blinking_State = -1;                                                        //initialize blinking      
  
//   if (currentButton_State != lastButton_state) {                               //if the button state has changed
//     lastDebounceTime = millis();                                               //update the lastDebounceTime 
//   }

  if((millis() - lastDebounceTime) > longPress && button_state == HIGH){       //if the button is pressed for more than longPress (5 seconds)

    while(true) {                                                              
      int currentState = digitalRead(button_pin);                              //read the state of the button
      unsigned long currentMillis = millis();                                  //initialize the currentMillis     

      if(currentState == HIGH && blinking_State == LOW ) {                     //if the button is pressed and the blinking state is LOW
        LED_state = HIGH;                                                      //set the LED state to HIGH
        digitalWrite(LED_pin, LED_state);                                      //write the LED state to the LED pin 
        lastDebounceTime = millis();                                           //update the lastDebounceTime

        while(true){
          int currentState = digitalRead(button_pin);                          //read the state of the button

          if(currentState == LOW){                                             //break, if the button is turned off
            break;
          }
        }
        break;
      }

      else if (currentMillis - previousMillis >= blink_interval){              //if the button is pressed for more than blink_interval (1 second)
        previousMillis = currentMillis;                                        //update the previousMillis     

        if(LED_state == LOW) {                                                 //if the LED state is LOW, set the LED state to HIGH
          LED_state = HIGH;                                                    
        }
        else {                                                                  //else the LED state is HIGH, set the LED state to LOW
          LED_state = LOW;
        
        }
        // control LED arccoding to the toggled state
        digitalWrite(LED_pin, LED_state);  //turns the LED on or off based on the variable
      }
      blinking_State  = currentState;                                           // save the last state
    }
  }

  else if((millis() - lastDebounceTime) > debounceDelay){                       //if the button is pressed for less than debounceDelay (50 milliseconds)

    if(currentButton_State != button_state){                                    //if the button state has changed
      button_state = currentButton_State;                                       //update the button_state    

      if(button_state == HIGH){                                                 //if the button is pressed
        LED_state = !LED_state;                                                 //toggle the LED state
      }
    }
  }

  digitalWrite(LED_pin, LED_state);                                              //write the LED state to the LED pin       
  lastButton_state = currentButton_State;                                        //save the last button state

}