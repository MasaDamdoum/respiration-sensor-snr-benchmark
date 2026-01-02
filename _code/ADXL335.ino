#include "ADXL335.h"

ADXL335 accelerometer;
void setup() {
    Serial.begin(9600);
    accelerometer.begin();
}
void loop() {
    int x, y, z;
    // accelerometer.getXYZ(&x, &y, &z);
    // Serial.print("value of X: ");
    // Serial.println(x);
    // Serial.print("value of Y: ");
    // Serial.println(y);
    // Serial.print("value of Z: ");
    // Serial.println(z);
    float ax, ay, az;
    accelerometer.getAcceleration(&ax, &ay, &az);
//Convert acceleration from g to m/s²
    ax = ax * 9.81;  
    ay = ay * 9.81;  
    az = az * 9.81;  
    Serial.print(ax);
    Serial.print(" m/s²");
    Serial.print("   ");
    Serial.print(ay);
    Serial.print(" m/s²");
    Serial.print("   ");
    Serial.print(az);
    Serial.println(" m/s²");
    delay(500);
}
