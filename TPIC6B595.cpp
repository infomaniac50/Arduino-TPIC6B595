/*
  Seg7.h - A library to control the TPIC6B595 Serial to Parallel Shift Register
  Created by Derek Chafin, October 8, 2011
  Released into the public domain.
*/

#include "TPIC6B595.h"
#define GATE_DELAY 20

TPIC6B595::TPIC6B595(int dataPin, int clockPin, int latchPin, int clearPin)
{
  _dataPin = dataPin;
  _clockPin = clockPin;
  _latchPin = latchPin;
  _clearPin = clearPin;
}

void TPIC6B595::init(int registers)
{
  
}

void TPIC6B595::sendByte(int number)
{
  switch(digits)
  {
    case 4:
      shiftOut(_dataPin, _clockPin, LSBFIRST, _bin4[getDigit(number, 3)]);
    case 3:
      shiftOut(_dataPin, _clockPin, LSBFIRST, _bin3[getDigit(number, 2)]);
    case 2:
      shiftOut(_dataPin, _clockPin, LSBFIRST, _bin2[getDigit(number, 1)]);
    case 1:
      shiftOut(_dataPin, _clockPin, LSBFIRST, _bin1[getDigit(number, 0)]);
  }
  
  pulsePin(_latchPin, HIGH);  
}

void TPIC6B595::clear()
{
  pulsePin(_clearPin, LOW);
  pulsePin(_latchPin, HIGH);
}

void TPIC6B595::pulsePin(int pin, int active)
{
  if (active == HIGH)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(GATE_DELAY);
    digitalWrite(pin, LOW);
  }
  else
  {
    digitalWrite(pin, LOW);
    delayMicroseconds(GATE_DELAY);
    digitalWrite(pin, HIGH);
  }
}
