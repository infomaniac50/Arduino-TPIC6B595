
#include "config.h"
#include "TPIC6B595.h"

#define GATE_DELAY 20

#if USE_HARD_SPI
#include <SPI.h>
#endif

TPIC6B595::TPIC6B595(int dataPin, int clockPin, int latchPin, int clearPin)
{
  _dataPin = dataPin;
  _clockPin = clockPin;
  _latchPin = latchPin;
  _clearPin = clearPin;
}

void TPIC6B595::begin()
{
#if USE_HARD_SPI
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.setBitOrder(LSBFIRST);
#else  
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin,OUTPUT);
#endif

  pinMode(_latchPin,OUTPUT);
  pinMode(_clearPin,OUTPUT);
}

void TPIC6B595::write(byte bits)
{
#if USE_HARD_SPI
  SPI.transfer(bits);
#else
  shiftOut(_dataPin, _clockPin, LSBFIRST, bits);
#endif
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
