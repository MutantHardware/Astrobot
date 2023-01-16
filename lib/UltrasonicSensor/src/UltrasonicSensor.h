#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h
#include "Arduino.h"

class UltrasonicSensor{
  private:
    int echoPin, triggerPin;
    float distance;
  public:
    UltrasonicSensor(int EchoPin, int TriggerPin);
    float Distance();
};

#endif