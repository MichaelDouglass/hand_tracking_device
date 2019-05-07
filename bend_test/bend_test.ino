float thresh = 2.0;

void setup()
{
  // Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop()
{
  float V_b1 = analogRead(A0) * 5.0 / 1023;
  // float V_b2 = analogRead(this->bend2) * 5.0 / 1023;
  // float V_b3 = analogRead(this->bend3) * 5.0 / 1023;
  bool oc = 1;
  if (V_b1 > thresh) { oc = 0; }
  // else if (V_b2 > this->thresh) { oc = 0; }
  // else if (V_b3 > this->thresh) { oc = 0; }
  // Serial.print(V_b1);
  // Serial.print(" || ");

  if ( oc == 1)
  {
    // Serial.println("Open!");
    digitalWrite(3, LOW);
  }
  else
  {
    // Serial.println("Closed!");
    digitalWrite(3, HIGH);
  }

  delay(200);

}
