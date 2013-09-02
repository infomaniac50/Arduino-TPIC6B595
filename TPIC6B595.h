
#ifndef TPIC6B595_h
#define TPIC6B595_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class TPIC6B595
{
  public:
    TPIC6B595(int dataPin,int clockPin, int latchPin, int clearPin);
    void write(byte bits);
    
    void clear();
  private:
    int _dataPin;
    int _clockPin;
    int _latchPin;
    int _clearPin;  
    void pulsePin(int pin, int active);    
};
#endif
