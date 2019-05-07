#ifndef HAND_H
#define HAND_H

#include "states.h"

class Hand
{
  private:
    int bend1;
    int bend2;
    int bend3;

    int SCL_gyro;
    int SDA_gyro;

    float thresh;

  public:
    Hand()
    {
      this->bend1 = A0;
      this->bend2 = A1;
      this->bend3 = A2;

      this->thresh = 2.0;
    };

    ~Hand() { };

    float get_thresh() { return this->thresh; };

    void set_thresh( float new_thresh)
    {
      this->thresh = new_thresh;
    };

    bool read_oc()
    {
      float V_b1 = analogRead(this->bend1) * 5.0 / 1023;
      float V_b2 = analogRead(this->bend2) * 5.0 / 1023;
      float V_b3 = analogRead(this->bend3) * 5.0 / 1023;
      bool oc = OPEN;
      if (V_b1 > this->thresh) { oc = CLOSE; }
      else if (V_b2 > this->thresh) { oc = CLOSE; }
      else if (V_b3 > this->thresh) { oc = CLOSE; }
      return oc;
    };

    float read_ang()
    {
      // This needs to be filled out and tested.

    };


};

#endif
