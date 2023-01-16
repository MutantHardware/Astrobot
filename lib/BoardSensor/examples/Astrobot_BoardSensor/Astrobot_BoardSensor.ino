// Including BoardSensor Library
#include "Wire.h"
#include <BoardSensor.h>

// Creating Sensor Object
BoardSensor Sensor(Wire);

// Pinout Definition
#define TouchPin 04
#define ModPin 36

// Variables and Constants
long timer = 0;
int R_board = 10000;

void setup() {
  // Initializing Serial and Sensor
  Serial.begin(9600);
  Wire.begin();
  byte status = Sensor.begin();
  Serial.print(F("BoardSensor status: "));
  Serial.println(status);
  
  // Stay in the loop if sensor don't work
  while(status!=0){

  } 
  
  // Calculate Offsets
  Serial.println(F("Calculating offsets, do not move BoardSensor"));
  delay(1000);
  Sensor.calcOffsets(true,true); 
  Serial.println("Done!\n");
  
}

void loop() {
  // Update Sensor 
  Sensor.update();
  
  // Print Data Every Second
  if(millis() - timer > 1000) { 

    // Print Sensor Results
    Serial.print(F("Temperature: "));
    Serial.println(Sensor.Temperature());

    Serial.print(F("Accelero X: "));
    Serial.print(Sensor.AccX());
    Serial.print("\tY: ");
    Serial.print(Sensor.AccY());
    Serial.print("\tZ: ");
    Serial.println(Sensor.AccZ());
  
    Serial.print(F("Gyro X: "));
    Serial.print(Sensor.GyroX());
    Serial.print("\tY: ");
    Serial.print(Sensor.GyroY());
    Serial.print("\tZ: ");
    Serial.println(Sensor.GyroZ());
  
    Serial.print(F("Acc Angle X: "));
    Serial.print(Sensor.AccAngleX());
    Serial.print("\tY: ");
    Serial.println(Sensor.AccAngleY());
    
    Serial.print(F("Angle X: "));
    Serial.print(Sensor.AngleX());
    Serial.print("\tY: ");
    Serial.print(Sensor.AngleY());
    Serial.print("\tZ: ");
    Serial.println(Sensor.AngleZ());
    
    Serial.print(F("Hall Sensor: "));
    Serial.println(Sensor.Hall());

    Serial.print(F("Touch Sensor: "));
    Serial.println(Sensor.Touch(TouchPin));

    Serial.print(F("Resistance Sensor: "));
    Serial.println(Sensor.Resistance(ModPin,R_board));
 
    // Restart Millis
    timer = millis();
  }

}
