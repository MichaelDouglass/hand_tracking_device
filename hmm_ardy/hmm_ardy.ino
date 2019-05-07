#include "LedsUI.h"
#include "Hand.h"

LedsUI leds(3);

Hand hand(2.0);

int hand_state;

void setup()
{
  // Say Hi!
  leds.dot(); leds.dot(); leds.dot(); leds.dot();
  delay(500);
  leds.dot(); leds.dot();
  Serial.begin(9600);
}

// For Testing the LED cpp and h
/*
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
*/

// For Testing the Hand cpp and h
/*
void loop()
{
  float run_avg = 0;
  int count = 0;
  for (int i; i++; i<20)
  {
    run_avg = run_avg + hand.get_Vb1();
    Serial.print(hand.get_Vb1());
    Serial.print(" / ");
    Serial.print(hand.get_thresh());
    Serial.print(" || ");
    Serial.println(hand.get_state());
    count = count + 1;
    delay(500);
  }
float final_avg = run_avg / count;
Serial.print("The Average Voltage is: ");
Serial.println(final_avg);
delay(3000);
}
*/

// For Testing the Hand cpp and h
/*
void loop()
{
  Serial.print(hand.get_Vb1());
  Serial.print(" / ");
  Serial.print(hand.get_thresh());
  Serial.print(" || ");
  Serial.println(hand.get_state());
  delay(200);
}
*/
