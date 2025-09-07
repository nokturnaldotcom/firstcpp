/**
 * ESP32 Back EMF Detector
 * Detects back electromotive force from inductive loads
 * Analog pin connected to voltage divider for protection
 */

// Constants
const int EMF_PIN = 35;           // Analog pin connected to voltage divider
const int THRESHOLD = 100;        // Minimum value to avoid noise detection
const int SAMPLING_DELAY = 100;   // Delay between readings in milliseconds
const int BAUD_RATE = 115200;     // Serial communication speed

void setup() {
  // Initialize serial communication
  Serial.begin(BAUD_RATE);
  
  // Configure analog pin
  pinMode(EMF_PIN, INPUT);
  
  // Print startup message
  Serial.println("=== ESP32 Back EMF Detector ===");
  Serial.println("Initialization complete");
  Serial.println("Monitoring for back EMF events...");
  Serial.println();
}

void loop() {
  // Read analog value from EMF sensor
  int emfValue = analogRead(EMF_PIN);
  
  // Check if back EMF is detected above threshold
  if (emfValue > THRESHOLD) {
    // Log detection event with timestamp
    Serial.print("Back EMF detected! Value: ");
    Serial.print(emfValue);
    Serial.print(" | Raw ADC: 0x");
    Serial.println(emfValue, HEX);
  }
  
  // Wait before next reading
  delay(SAMPLING_DELAY);
}
