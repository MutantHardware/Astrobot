// Including Library
#include <UltrasonicSensor.h>

// Defining UltrasonicSensor pinout
#define EchoPin    12  // GPIO12
#define TriggerPin 13 // GPIO13

// Creating UltrasonicSensor object
UltrasonicSensor UltrasonicSensor(EchoPin,TriggerPin);

void setup() {
     // Initializing Serial
     Serial.begin(9600);
}
 
void loop() {
    Serial.println(UltrasonicSensor.Distance());
    delay(100);
}