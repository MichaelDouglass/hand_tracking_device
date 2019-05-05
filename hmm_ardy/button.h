#ifndef BUTTON_H
#define BUTTON_H

#include "states.h"

class Button
{
  private:
    int pin;

  public:
    Button()
    {
      this->pin = 1;
    };

    ~Button() { };

};

#endif
