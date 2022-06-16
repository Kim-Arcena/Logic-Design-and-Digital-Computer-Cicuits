//constant variables
const int potPin = A2;              //connect the potentiomenter to A2         
const int ledPin = 9;               //connect the LED to pin 9
const int delayTime = 250;          //delay time for serial monitor in milliseconds    

int readVal;                        //variable to hold the value read from the potentiometer
float volts;                        //variable to hold the voltage value
long blink_interval = 0;            //1 second interval between blinks

String sensorVal, voltOutput, blinkInt, interval;

void setup() {
  Serial.begin(9600);               //begin serial monitor at 9600 baud
  sensorVal = String();             //initialize string variables for string additon
  voltOutput = String();
  interval = String();
  pinMode(potPin, INPUT);           //set the potentiometer pin as input
  pinMode(ledPin, OUTPUT);          //set the LED pin as output
}

void loop() {
  readVal = analogRead(potPin);                 //read the value from the potentiometer
  volts = (5.0/1023.0) * readVal;               //convert the value to voltage
  sensorVal = "Sensor value: ";
  voltOutput = sensorVal + volts;
  Serial.println(voltOutput);                   ///print the volts to the serial monitor         

  if(volts > 2.0){                              //if the voltage is greater than 2.0    
    blink(volts);                               //call the blink function
  }
  else{                                                     
    digitalWrite(ledPin, LOW);                  //else, turn the LED off
  }
  delay(delayTime);                             //delay for the serial monitor
}

void blink(float volts){
  volts = int(volts);                                 //convert the voltage to an integer
                      
  long blink_interval = (-1 * volts + 6) * 1000;      //calculate the interval between blinks using the linear sequence formula 
  digitalWrite(ledPin, HIGH);                         //turn the LED on
  delay(1000);                                        //delay for 1 second to simulate the blink
  digitalWrite(ledPin, LOW);                          //turn the LED off
  delay(blink_interval);                              //delay for the interval between blinks
  blinkInt = "Blinking Interval: ";
  interval = blinkInt + blink_interval;
  Serial.println(interval);                           //print the interval between blinks        
}


