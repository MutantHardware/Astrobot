// Including Library
#include <IRSensor.h>

// Defining IR Sensor Pin
#define IRSensorPin 4

// Creating IR Sensor object
IRSensor IRSensor(IRSensorPin);

void setup() {
  // Initializing Serial
  Serial.begin(9600);
}


void loop() {
  if (IRSensor.Reflect()) {
      Serial.println("Reflected");
    }
}
 