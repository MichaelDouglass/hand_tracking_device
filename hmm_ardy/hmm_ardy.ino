float read;
float volts;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  read = analogRead(A0);
  volts = read * 5.0 / 1023;
  Serial.print("Voltage: ");
  Serial.print(volts);
  Serial.print(" || ");
  if (volts > 1.1)
  {
    Serial.println("Open!");
  }
  else
  {
    Serial.println("Closed!");
  }
  delay(100);
}
