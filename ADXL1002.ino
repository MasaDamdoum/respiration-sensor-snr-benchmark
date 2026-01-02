// ADXL1002 connection to Arduino (Analog Output)

const int accelPin = A0;      // ADXL1002 output connected to A0
const float vRef = 5.0;       // Arduino reference voltage (5V)
const int adcResolution = 1023;

// ADXL1002 typical sensitivity and zero-g bias (adjust if needed)
const float sensitivity = 0.02; // V/g (20 mV/g)
const float zeroGBias = 2.5;    // V at 0 g

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(accelPin);
  float voltage = (adcValue * vRef) / adcResolution;
  float acceleration_g = (voltage - zeroGBias) / sensitivity;

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Acceleration: ");
  Serial.print(acceleration_g);
  Serial.println(" g");

  delay(100);
}

