#include "IRSensor.h"
#include "Arduino.h"

IRSensor::IRSensor(int IRSensorPin){
  pinMode(IRSensorPin, INPUT);
  IRPin = IRSensorPin;
}

bool IRSensor::Reflect(){
   if (digitalRead(IRPin) == LOW){
       return true;
   }
   else {
      return false;
   }
}