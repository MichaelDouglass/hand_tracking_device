#ifndef Hand_h
#define Hand_h

#include "Arduino.h"

class Hand
{
public:
  Hand(float thresh);
  int get_state();
  float get_thresh();
  void set_thresh(float thresh);
  float get_Vb1();
  float get_Vb2();
  float get_Vb3();
private:
  int _state;
  float _thresh;
  float _Vb1;
  float _Vb2;
  float _Vb3;
};

#endif
