//code to run the timer 
//1. analogRead the resistor value and convert to time
//2. set a timer to refresh display on digital, keep track of time
//3. set alarm off on buzzer 
#include "SevSeg.h"
#include "Timer.h"

        Timer::Timer()
        {
          buzzerPin = 0;
        }
        void Timer::begin(int buzzer, byte digitPins[], byte segmentPins[],  bool resistorsOnSegments, bool updateWithDelaysIn, byte hardwareConfig ){
        buzzerPin = buzzer;
        disp.begin(hardwareConfig, 4, digitPins, segmentPins, resistorsOnSegments);
        disp.setBrightness(90);
        }

        int Timer::calc(int timegiven){
        //max analog value = 1023 on 5V voltage
        //interval of 50 on signal value so 1023/50 = 200 checkpoints
        // so the max amount of seconds is 15 * 200 = 3000 s = 50 min
        float rawtime = (timegiven*3000.0)/1023;
        int minutes = 0;
        int seconds = 0;
        minutes = int(rawtime)/60;
        seconds = int(rawtime)%60;
        if((0<=seconds) && (15>seconds)){
            seconds = 0;
        }
        else if((15<=seconds) && (30>seconds)){
            seconds = 15;
        }
        else if((30<=seconds) && (45>seconds)){
            seconds = 30;
        }
        else if((45<=seconds) && (59>seconds)){
            seconds = 45;
        }
        return 100*minutes + seconds;
    }
    
    int Timer::durationset(int timegiven){
       float rawtime = (timegiven*3000.0)/1023;
        int minutes = 0;
        int seconds = 0;
        minutes = int(rawtime)/60;
        seconds = int(rawtime)%60;
        if((0<=seconds) && (15>seconds)){
            seconds = 0;
        }
        else if((15<=seconds) && (30>seconds)){
            seconds = 15;
        }
        else if((30<=seconds) && (45>seconds)){
            seconds = 30;
        }
        else if((45<=seconds) && (59>seconds)){
            seconds = 45;
        }
        return minutes*60+seconds;
      }

    int Timer::giverealTime(int seconds){
      int minutes = seconds/60;
      int sec_left = seconds%60;
      return 100*minutes+sec_left;
      }
    
    void Timer::countdown(int duration){ //duration given in seconds
      long toshow = 0;
        for(int i = duration; i>0; i--){
       toshow = giverealTime(i);
        for(int timing = 4905; timing>0; timing--){
            disp.setNumber(toshow,4);
            disp.refreshDisplay();
        }
        //setOnBuzzer();
    }
    }
    
     void Timer::setOnBuzzer(){ //create a multivibrator function
        //int timing = 20; //(time to keep the buzzer on)*2
         for(int i = 10; i>0; i--){
             analogWrite(buzzerPin, 255);
             delay(500);
             analogWrite(buzzerPin, 0);
             delay(500);
    }
    }
