#include "LedsUI.h"
LedsUI leds(3);

void setup()
{
}

void loop()
{
  leds.dot();
  leds.dash();
  leds.dot();
  leds.dash();
  leds.dot();
  leds.dot();
  leds.dot();
  delay(3000);
}
