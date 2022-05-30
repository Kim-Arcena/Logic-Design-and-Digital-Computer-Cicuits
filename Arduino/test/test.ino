//constant variables
int potPin = A2;                    //connect the potentiomenter to A2         
int ledPin = 9;                     //connect the LED to pin 9
int delayTime = 250;                //delay time for serial monitor in milliseconds    

int readVal;                        //variable to hold the value read from the potentiometer
float volts;                        //variable to hold the voltage value
long blink_interval = 0;            //1 second interval between blinks


void setup() {
  Serial.begin(9600);               //begin serial monitor at 9600 baud
  pinMode(potPin, INPUT);           //set the potentiometer pin as input
  pinMode(ledPin, OUTPUT);          //set the LED pin as output
}

void loop() {
  readVal = analogRead(potPin);                 //read the value from the potentiometer
  volts = (5./1023.) * readVal;                 //convert the value to voltage
  Serial.println("Volt count is");              //print the voltage count
  Serial.println(volts);                            

  if(volts > 2.0){                              //if the voltage is greater than 2.0    
    blink(volts);                               //call the blink function
  }
  else{                                                     
    digitalWrite(ledPin, LOW);                  //else, turn the LED off
  }
  delay(delayTime);                             //delay for the serial monitor
}

void blink(float volts){
 volts = int(volts);                                    //convert the voltage to an integer
                      
  long blink_interval = (-1 * volts + 6) * 1000;      //calculate the interval between blinks using the linear sequence formula 
  digitalWrite(ledPin, HIGH);                         //turn the LED on
  delay(1000);                                        //delay for 1 second to simulate the blink
  digitalWrite(ledPin, LOW);                          //turn the LED off
  delay(blink_interval);                              //delay for the interval between blinks
  Serial.println("Blinking Interval");                //print the interval between blinks        
  Serial.println(blink_interval);

}