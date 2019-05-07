#ifndef LEDS_H
#define LEDS_H

#include "states.h"

class LEDS
{
  private:
    int pin1;
    int pin2;
    int pin3;

    bool ctl = OFF;

    int delay1;
    int delay2;
    int delay3;

  public:
    LEDS()
    {
      this->pin1 = 3;
      this->delay1 = 100;
      pinMode(this->pin1, OUTPUT);
    };

    ~LEDS() { };

    void blink_LED()
    {
      if (this->ctl == OFF)
        return;

      for ( int i=1; i++; i<10)
      {
        digitalWrite(this->pin1, HIGH);
        delay(this->delay1);
        digitalWrite(this->pin1, LOW);
        delay(this->delay1);
      };
      return;
    };

    void ctl_LED()
    {
      if ( this->ctl == OFF )
      {
        digitalWrite(this->pin1, LOW);
        return;
      }
      blink_LED();
    };

    void set_state( int new_ctl )
    {
      this->ctl = new_ctl;
      return;
    };

    int get_state()
    {
      return this->ctl;
    };

};

#endif
