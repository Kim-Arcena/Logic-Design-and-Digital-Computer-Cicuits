//constant variables
const int ledPin[] = {5, 6, 7, 8, 9, 10, 11, 12};                           // LED Pins connection
const int buttonPin = 2;                                                    // Button Pin connection
//push button events
const long longPress = 5000;                                                // 5 seconds Long press time 
const long interval = 1000;                                                 // 1 second interval
const long twoSeconds = 2000;                                               // 2 seconds flash

int prevButtonState = LOW;                                                  // Previous state of the button
int currentButtonState = LOW; 
int on, off, hold, counter;   
unsigned long previousMillis;                                               // will store last time LED was updated  


void setup() {
  Serial.begin(9600);                                                       // Start serial communication
  for(int i = 0; i<  8; i++){                                               // Set all the LED pins as output using for loop      
    pinMode(ledPin[i], OUTPUT);                                           
  }
  pinMode(buttonPin, INPUT);                                                // Set button pin as input          
}

void loop() {     
  int currentButtonState = digitalRead(buttonPin);                          // Read the state of the button

  if(currentButtonState != prevButtonState){                                // Check if the button state has changed - for debouncing
    previousMillis = millis();  
  }

  if(currentButtonState == LOW && prevButtonState == HIGH){                // Check if the button is pressed
    Serial.println("Flash for two seconds");                               // Print message on serial monitor
    previousMillis = millis();                                             // Reset the timer
    while((millis() - previousMillis) <= twoSeconds){                      // Flash the LED for two seconds
      binaryCounter(255);                                                   // Flash ALL the LED
    }
    binaryCounter(0);                                                       // Turn OFF the LED
  }

  if((millis() - previousMillis) > longPress && currentButtonState == HIGH){              // Check if the button is pressed for more than 5 seconds
    OnCurrentState();                                                                    //call the function to turn on the LED
    previousMillis = millis();                                                            // Reset the timer  

    buttonRelease();

    currentButtonState = LOW;                                                             // Reset the current and previous button state  
    prevButtonState = LOW;                                                                
  }
  prevButtonState = currentButtonState;                                                   // Update the previous button state
}

void binaryCounter(byte num){                                                             // Function to turn on the LED
  for (int i=0; i<8; i++) {                                                               // Loop through all the LED      
    if (num%2)                                                                            // Check if the bit is 1  
      digitalWrite(ledPin[i], HIGH);                                                      // Turn on the LED      
    else                                                                                  // Check if the bit is 0
      digitalWrite(ledPin[i], LOW);                                                       // Turn off the LED        
    num/=2;                                                                               // Shift the bit to the right      
  } 
}

void  OnCurrentState(){                                                                   // function if the current state of the circuit is on
  previousMillis = millis();                                                              // Reset the timer
  Serial.println("Turned on 8 bit counter");                                              // Print message on serial monitor
  counter = 0;                                                                            //initialize counter to 0  

  while(true){                                                                                  
    buttonHolder();                                                                          //call buttonHolder()
    int currentButtonState = digitalRead(buttonPin);                                      // Read the state of the button

    if((millis() - previousMillis) >= interval && currentButtonState == HIGH){            // Check if the button is pressed for more than 1 second
      while(true){                                                                                    
        currentButtonState = digitalRead(buttonPin);                                      // Read the state of the button       

        if((millis() - previousMillis) >= longPress && currentButtonState == HIGH){       // Check if the button is pressed for more than 5 seconds
          turnOff();                                                                      //turn to off state      
          off = 1;
          previousMillis = millis();                                                      // Reset the timer
          break;
        }
        else if((millis() - previousMillis) < longPress && currentButtonState == LOW){    // Check if the button is pressed for less than 5 seconds
          break;
        }
        if(currentButtonState != prevButtonState){                                        // Check if the button state has changed - for debouncing
          Serial.println("Click");
        }
        prevButtonState = currentButtonState;                                             // Update the previous button state
      }
    }  
      if(off == 1){                                                                       //check if the circuit is in off state
        hold = 0;                                                                         //turn of everything
        on = 0;
        off = 0;
        break;
      }
    	counterSec();                                                                       //controls the counter         
      if(currentButtonState != prevButtonState){                                          // Check if the button state has changed - for debouncing
        on = 1;                                                                           //turn on everything
        Serial.println("Click");                                                            
        previousMillis = millis();                                                        // Reset the timer     
      }
    prevButtonState = currentButtonState;                                                 // Update the previous button state
  }
}

void buttonRelease(){
  while(true){                                                                          // button release
    int currentButtonState = digitalRead(buttonPin);                                      
    if(currentButtonState == LOW){                                                      //terminate when button is released
      break;                                                                              
    }
  }
}

void buttonHolder(){                                                                      //function to hold the button
  while(true && hold == 0){                                                               //hold the button
    int currentButtonState = digitalRead(buttonPin);                                      // Read the state of the button
    if(currentButtonState == LOW){                                                        //terminate when button is released
      hold = 1;                                                                           
      break;                                                                              
    }
  }
}

void turnOff(){                                                                           //function to turn off the circuit
  Serial.println("Turned off");                                                           // Print message on serial monitor
  binaryCounter(0);                                                                       // Turn OFF ALL the LED

  buttonRelease();                                                                        //button release
  
}

void counterSec(){                                                                        //function to count the binary decimal output
  if(currentButtonState == LOW && prevButtonState == HIGH && on == 1){                    //check if the button is pressed    
    counter = 0;                                                                          //initialize counter for the binary     
  }
  if(counter == 255 + 1){                                                                 //check if the counter reaches the maximum
    counter = 0;                                                                          //reset the counter
  }
  
  if((millis() - previousMillis) >= interval){                                            //check if the time interval is reached
    previousMillis = millis();                                                            //reset the timer
    binaryCounter(counter);                                                               //call the binaryCounter()
    counter++;                                                                            //increment the counter    
  }
}



