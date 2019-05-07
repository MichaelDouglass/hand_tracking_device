#include "Arduino.h"
#include "LedsUI.h"

LedsUI::LedsUI(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LedsUI::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void LedsUI::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}
