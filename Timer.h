//code to run the timer 
//1. analogRead the resistor value and convert to time
//2. set a timer to refresh display on digital, keep track of time
//3. set alarm off on buzzer 

#ifndef Timer_h
#define Timer_h

#include "SevSeg.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Timer
{
    public: 
        Timer();
        void begin( int buzzer, byte digitPins[], byte segmentPins[],  bool resistorsOnSegments, bool updateWithDelaysIn, byte hardwareConfig);
        int calc(int timegiven);//outputs time is mmss format to use for the display
        void countdown(int duration); //countdown from predefined duration, refresh display
        void setOnBuzzer(); //create a multivibrator function
        int giverealTime(int seconds); //give real time in good format mm:ss
        int durationset(int timegiven); //outputs the duration in seconds according to potentiometer analogRead() value
        
        int buzzerPin;
        SevSeg disp;
};
#endif
