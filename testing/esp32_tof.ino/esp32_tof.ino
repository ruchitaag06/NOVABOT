
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!sensor.begin()) {
    Serial.println("ERROR");
    while (1) delay(10);
  }

  Serial.println("TOF_READY");
}

void loop() {
  VL53L0X_RangingMeasurementData_t m;

  sensor.rangingTest(&m, false);

  if (m.RangeStatus != 4) {
    Serial.print("Distance: ");
    Serial.print(m.RangeMilliMeter);
    Serial.println(" mm");
  } else {
    Serial.println("Out of range");
  }

  delay(150);
}
