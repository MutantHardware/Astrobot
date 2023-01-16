#ifndef IRSensor_h
#define IRSensor_h
#include "Arduino.h"

class IRSensor{
  private:
    int IRPin;
  public:
    IRSensor(int IRSensorPin);
    bool Reflect();
};

#endif