// ESP32 Back EMF Detector
const int EMF_PIN = 35;
const int THRESHOLD = 100;

void setup() {
  Serial.begin(115200);
  pinMode(EMF_PIN, INPUT);
}

void loop() {
  int emfValue = analogRead(EMF_PIN);
  
  if (emfValue > THRESHOLD) {
    Serial.print("Back EMF: ");
    Serial.println(emfValue);
  }
  
  delay(100);
}
