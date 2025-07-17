const int potPin = 12;

void setup() {
  Serial.begin(115200);  // 'Serial' must be capitalized
}

void loop() {
  int potValue = analogRead(potPin);  // Reads analog value from pin 12

  Serial.print("Potentiometer Value: ");  // 'Serial' must be capitalized
  Serial.println(potValue);
  delay(200);  // Wait 200 milliseconds before reading again
}