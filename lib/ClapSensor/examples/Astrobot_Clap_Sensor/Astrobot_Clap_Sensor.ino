// Including Library
#include <ClapSensor.h>

// Defining Clap Sensor Pin
#define ClapSensorPin 3

// Creating Clap Sensor object
ClapSensor ClapSensor(ClapSensorPin);

void setup() {
  // Initializing Serial
  Serial.begin(9600);
}


void loop() {
  if (ClapSensor.Clap()) {
      Serial.println("Clap");
    }
}
 