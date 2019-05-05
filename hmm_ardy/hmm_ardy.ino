#include "states.h"
#include "leds.h"
#include "hand.h"
#include "button.h"

LEDS leds;
Button button;
Hand hand;

bool open_close;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  open_close = hand.read_oc();
  Serial.println(open_close);
  leds.set_ctl(ON);
  leds.ctl_LED();
  delay(10000);
  leds.set_ctl(OFF);
  leds.ctl_LED();
  delay(10000);
}
