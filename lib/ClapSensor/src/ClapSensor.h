#ifndef ClapSensor_h
#define ClapSensor_h
#include "Arduino.h"

class ClapSensor{
  private:
    int ClapPin;
  public:
    ClapSensor(int ClapSensorPin);
    bool Clap();
};

#endif