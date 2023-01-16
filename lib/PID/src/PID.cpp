#include "PID.h"
#include "Arduino.h"

PID::PID(float kp, float ki, float kd){
  Kp = kp;
  Ki = ki;
  Kd = kd;
  Error = 0;
  Integral = 0;
  Derivative = 0;
  LastError = 0;
  Pid = 0;
}

void PID::CalculatePWM(float input, float target, int defaultPWM, int maxRate, int* RightMotorPWM, int* LeftMotorPWM){
      // Calculate PID
      Error = target - input;
      Integral += Error;
      Derivative = Error - LastError;
      Pid = Kp * Error + Ki * Integral + Kd * Derivative;
      
      // Transform angle PID to PWM
      if (Pid < 0) {
         PID_PWM = map(Pid, 0, -360, 0, 200);
         if(PID_PWM >= maxRate){
            PID_PWM = maxRate;
      } 

      // Assign PWM values to Right and Left motor
      *RightMotorPWM = defaultPWM + PID_PWM;
      *LeftMotorPWM = defaultPWM - PID_PWM;
      }
      else {
        PID_PWM = map(Pid, 0, 360, 0, 200);
        if(PID_PWM >= maxRate){
           PID_PWM = maxRate;
        } 
        
      // Assign PWM values to Right and Left motor
      *RightMotorPWM = defaultPWM - PID_PWM;
      *LeftMotorPWM = defaultPWM + PID_PWM;
      }
      
      // Save Last Error
      LastError = Error;
}