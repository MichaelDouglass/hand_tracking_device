#include "LedsUI.h"
#include "Hand.h"

#include <SD.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

LedsUI leds(3);

Hand hand(2.0);

float thresh;

int x;
int y;
int z;

File myFile;

void setup()
{
  // Say Hi!
  leds.dot(); leds.dot(); leds.dot(); leds.dot();
  delay(500);
  leds.dot(); leds.dot();
  Serial.begin(9600);
  if(!bno.begin())
  {
    while(1){ leds.dash(); };
  }

  pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
   while(1){ leds.dash(); };
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  thresh = thresh_tester();
  hand.set_thresh(thresh);
}

void loop()
{
  if ( hand.get_state() == 0 )
  {
    myFile = SD.open("bend.txt", FILE_WRITE);
    sensors_event_t event;
    bno.getEvent(&event);
    x = int(event.orientation.x);
    y = int(event.orientation.y);
    z = int(event.orientation.z);
    if (myFile)
    {
      myFile.print(x);
      myFile.print("\t");
      myFile.print(y);
      myFile.print("\t");
      myFile.print(z);
      myFile.print("\t");
      myFile.println(millis());
      myFile.close();
    }
    else
    {
      leds.dot(); leds.dot(); leds.dot();
      leds.dot(); leds.dot(); leds.dot();
    }
  }
  else
  {
    delay(500);
  }
}

float thresh_tester()
{
  leds.dash(); leds.dot(); leds.dot(); leds.dash();
  float run_avg = 0;
  float count = 0;
  for (int i = 0; i<20; i++)
  {
    run_avg = run_avg + hand.get_Vb1();
    count = count + 1;
    delay(500);
  }
  float final_avg = run_avg / count;
  leds.dot(); leds.dot();
  return final_avg - 0.1;
}
