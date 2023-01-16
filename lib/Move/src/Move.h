#ifndef Move_h
#define Move_h
#include <Arduino.h>
#include <driver/ledc.h>

class Move{
    private:
            // Global Variables
            int AIN1;
            int AIN2;
            int PWMA;
            int BIN1;
            int BIN2;
            int PWMB;

            // PWM Settings
           const int PWM_CA = 0;  // PWM Channel A
           const int PWM_CB = 3;  // PWM Channel B
           const int PWM_F = 500; // PWM Frequency
           const int PWM_R = 8;   // PWM Resolution

    public:
            Move(int Pin_AIN1,int Pin_AIN2,int Pin_PWMA,int Pin_BIN1,int Pin_BIN2,int Pin_PWMB);
            void forward(int DutyCycleA,int DutyCycleB);
            void backward(int DutyCycleA,int DutyCycleB);
            void left(int DutyCycleA,int DutyCycleB);
            void right(int DutyCycleA,int DutyCycleB);
            void stop();
};

#endif