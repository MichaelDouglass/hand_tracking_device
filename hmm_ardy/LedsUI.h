#ifndef LedsUI_h
#define LedsUI_h

#include "Arduino.h"

class LedsUI
{
public:
  LedsUI(int pin);
  void dot();
  void dash();
private:
  int _pin;
};

#endif
