
#include "Timer.h"
Timer timing;
//change this according to your connections
int buzzerPin = A2;
int poten = A1;
int button = A0;
int buttonvalue = 0;
int timeset = 0;


void setup(){
  //initialize everything 
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5}; // digit pins
  byte segmentPins[] = {13, 12, 11, 10, 9, 8, 7, 6}; //segment pins, do not use pin 0 and 1 they did not work for me
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  pinMode(buzzerPin, OUTPUT);
  pinMode(poten, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  Serial.println("Timing duration");
  //initialize the timer
  timing.begin(buzzerPin, digitPins, segmentPins, resistorsOnSegments, updateWithDelaysIn, hardwareConfig);
}

void loop(){
  //check if button is pressed to launch the sequence
  if(digitalRead(button) == 0){
//set up time through potentiometer
   timeset = analogRead(poten);
   timing.disp.setNumber(timing.calc(timeset));
   timing.disp.refreshDisplay();
   }
  else{
      //launch timer if the button is pressed
   int timese = analogRead(poten);
   timing.countdown(timing.durationset(timese));
   timing.setOnBuzzer();
   }
}
