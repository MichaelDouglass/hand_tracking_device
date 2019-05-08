#include "LedsUI.h"
#include "Hand.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

LedsUI leds(3);

Hand hand(2.0);

int hand_state;
float thresh;

void setup()
{
  // Say Hi!
  leds.dot(); leds.dot(); leds.dot(); leds.dot();
  delay(500);
  leds.dot(); leds.dot();
  Serial.begin(9600);
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1){ leds.dash(); };
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  thresh = thresh_tester();
  hand.set_thresh(thresh);
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
float thresh_tester()
{
  leds.dash(); leds.dot(); leds.dot();
  float run_avg = 0;
  float count = 0;
  for (int i = 0; i<20; i++)
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
  leds.dot(); leds.dot();
  return final_avg - 0.1;
}

void loop()
{
  if ( hand.get_state() == 0 )
  {
    Serial.print(hand.get_Vb1());
    Serial.print(" | ");
    Serial.print(hand.get_Vb2());
    Serial.print(" | ");
    Serial.print(hand.get_Vb3());
    Serial.print(" / ");
    Serial.print(hand.get_thresh());
    Serial.print(" || ");
    Serial.print(hand.get_state());
    Serial.print(" ::: ");

    sensors_event_t event;
    bno.getEvent(&event);

    Serial.print("X: ");
    Serial.print(int(event.orientation.x));
    Serial.print("\tY: ");
    Serial.print(int(event.orientation.y));
    Serial.print("\tZ: ");
    Serial.print(int(event.orientation.z));
    Serial.print(" || ");
    Serial.println(millis());
  }
  else
  {
    delay(500);
  }
}

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

// Test the x, y, z Orientation
/*
void loop()
{
  sensors_event_t event;
  bno.getEvent(&event);

  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");

  delay(100);
}
*/
