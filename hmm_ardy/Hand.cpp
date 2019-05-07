#include "Arduino.h"
#include "Hand.h"

Hand::Hand(float thresh)
{
  _thresh = thresh;
}

int Hand::get_state()
{
  _Vb1 = analogRead(A0) * 5.0 / 1023;
  if (_Vb1 > _thresh) { _state = 0; }
  else { _state = 1; }
  delay(10);
  return _state;
}

float Hand::get_thresh()
{
  return _thresh;
}

void Hand::set_thresh(float thresh)
{
  _thresh = thresh;
}

float Hand::get_Vb1()
{
  _Vb1 =  analogRead(A0) * 5.0 / 1023;
  return _Vb1;
}
