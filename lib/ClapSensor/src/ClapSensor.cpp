#include "ClapSensor.h"
#include "Arduino.h"

ClapSensor::ClapSensor(int ClapSensorPin){
  pinMode(ClapSensorPin, INPUT);
  ClapPin = ClapSensorPin;
}

bool ClapSensor::Clap(){
   return !digitalRead(ClapPin);
}