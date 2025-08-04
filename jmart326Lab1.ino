/*
Jesse Martinez, 658653608, jmart326
Lab 1 - Three Blinking Lights
Description - This code demonstrates the blinking of three LED lights. The first light to turn on would be
the onboard led of the arduino, second comes the red LED, and lastly the green one. It is set
in a continuous loop. I created 2 helper functions that contain switch statements to handle 
different cases to turn the LEDs on and off. 
Assumtions: Taking a first look at the arduino kit was intimidating because there are so many 
electrical components, however I was able to figure out how to connect the wiring from the class notes
References - lecture notes(Lecture 3) arduino 
*/

//global variables
int pinOnBoard = 13;
int pinRed = 12;
int pinGreen = 11; 
unsigned long prev = 0;
int interval = 1000;
int on = 0;
int currLED = 0;

//set to make all of the LED outputs
void setup() {
pinMode(pinOnBoard, OUTPUT); //TURN ONBOARD LED ON
pinMode(pinRed, OUTPUT);     //TURN RED LED ON
pinMode(pinGreen, OUTPUT);     //TURN GREEN LED ON
}
//turns off the current LED in the loop
void turnOffLED(){
  switch(currLED){
    case 0: //onboard LED
      digitalWrite(pinOnBoard, LOW);
      break;
    case 1: //red LED
      digitalWrite(pinRed, LOW);
      break;
    case 2: //green LED
      digitalWrite(pinGreen, LOW);
      break;
  }
}
//turns on the LED in the loop
void turnOnLED(){
  switch(currLED){
    case 0: //onboard LED
      digitalWrite(pinOnBoard, HIGH);
      break;
    case 1: //red LED
      digitalWrite(pinRed, HIGH);
      break;
    case 2: //green LED
      digitalWrite(pinGreen, HIGH);
      break;
  }
}

void loop() {
  unsigned long curr = millis();
  if (curr - prev >= interval) {
    prev = curr;
    
    turnOffLED(); //calls function to turn off the the current LED light(initially set to 0 for cases)

    currLED = (currLED + 1) % 3; //makes sure it loops around based on the 3 cases

    turnOnLED(); //function call to turn on LED
  }

}