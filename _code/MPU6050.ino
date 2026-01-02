#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Adafruit_MPU6050.h>
#include "ADXL335.h"
#include "ADXL362.h"

// Constants
#define ADXL362_CS_PIN 7
#define ANALOG_SENSOR_PIN A3
#define BAUD_RATE 9600

// Instances
ADXL335 adxl335;
Adafruit_ADXL345_Unified adxl345 = Adafruit_ADXL345_Unified(12345);
ADXL362 adxl362(ADXL362_CS_PIN);
Adafruit_MPU6050 mpu;

// Functions

// Sensor 1: ADXL335
void initADXL335() {
  adxl335.begin();
}

// Sensor 2: ADXL362
void initADXL362() {
  adxl362.init();
  adxl362.activateMeasure();
}

// Sensor 3: ADXL345
void initADXL345() {
  adxl345.begin();
  adxl345.setRange(ADXL345_RANGE_2_G);
}

// Sensor 4: MPU6050
void initMPU6050() {
  mpu.begin();
}

// Sensor 5: ADXL1002
float getSmoothedReading(int pin, int samples = 10) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
  }
  return total / float(samples);
}

// Arduino setup & loop
void setup() {
  Serial.begin(BAUD_RATE);
  while (!Serial);

  initADXL335();
  initADXL362();
  initADXL345();
  initMPU6050();
}

void loop() {
  // variables for sensors
  float ax1, ay1, az1;  // ADXL335
  float ax3, ay3, az3;  // ADXL362
  float ax2, ay2, az2;  // ADXL345
  float ax5, ay5, az5;  // MPU6050
  float analogAccel;    // ADXL1002
 
  // Read ADXL335
  adxl335.getAcceleration(&ax1, &ay1, &az1);
  ax1 *= 9.81; ay1 *= 9.81; az1 *= 9.81;

  // Read ADXL362
  MeasurementInMg xyz3 = adxl362.getXYZ(ad_range_2G);
  ax3 = (xyz3.x / 1000.0) * 9.80665;
  ay3 = (xyz3.y / 1000.0) * 9.80665;
  az3 = (xyz3.z / 1000.0) * 9.80665;

  // Read ADXL345
  sensors_event_t event2;
  adxl345.getEvent(&event2);
  ax2 = event2.acceleration.x;
  ay2 = event2.acceleration.y;
  az2 = event2.acceleration.z;

  // Read MPU6050
  sensors_event_t a5, g5, temp5;
  mpu.getEvent(&a5, &g5, &temp5);
  ax5 = a5.acceleration.x;
  ay5 = a5.acceleration.y;
  az5 = a5.acceleration.z;

  // Read ADXL1002
  float vRef = 5.0;
  float sensitivity = 0.04;
  float zeroG = 2.5367;
  float g_to_ms2 = 9.80665;
  float raw = getSmoothedReading(ANALOG_SENSOR_PIN);
  float voltage = raw * vRef / 1023.0;
  float accel_g = (voltage - zeroG) / sensitivity;
  analogAccel = accel_g * g_to_ms2;

  // print values
  // ADXL335
  Serial.print(ax1, 2); Serial.print("  ");
  Serial.print(ay1, 2); Serial.print("  ");
  Serial.print(az1, 2); Serial.print("        ");

  // ADXL362
  Serial.print(ax3, 2); Serial.print("  ");
  Serial.print(ay3, 2); Serial.print("  ");
  Serial.print(az3, 2); Serial.print("        ");

  // ADXL345
  Serial.print(ax2, 2); Serial.print("  ");
  Serial.print(ay2, 2); Serial.print("  ");
  Serial.print(az2, 2); Serial.print("        ");

  // MPU6050
  Serial.print(ax5, 2); Serial.print("  ");
  Serial.print(ay5, 2); Serial.print("  ");
  Serial.print(az5, 2); Serial.print("        ");

  // ADXL1002
  Serial.println(analogAccel, 2);
}


