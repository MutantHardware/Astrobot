#ifndef PID_h
#define PID_h
#include "Arduino.h"

class PID{
  private:
    float Kp, Ki, Kd;
    float Error, Integral, Derivative, LastError;
    float Pid;
    float PID_PWM;
  public:
    PID(float kp, float ki, float kd);
    void CalculatePWM(float input, float target, int defaultPWM, int maxRate, int* RightMotorPWM, int* LeftMotorPWM);
}; 

#endif


