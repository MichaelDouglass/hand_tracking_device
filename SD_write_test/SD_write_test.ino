#include <SD.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

File myFile;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
   pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }

  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

}

void loop()
{
  myFile = SD.open("gyro.txt", FILE_WRITE);
  sensors_event_t event;
  bno.getEvent(&event);

  int x = int(event.orientation.x);
  int y = int(event.orientation.y);
  int z = int(event.orientation.z);
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tZ: ");
  Serial.print(z);
  Serial.println("");

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to gyro.txt...");
    myFile.print(x);
    myFile.print("\t");
    myFile.print(y);
    myFile.print("\t");
    myFile.print(z);
    myFile.print("\t");
    myFile.println(millis());
  // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening gyro.txt");
  }
  delay(750);
}
