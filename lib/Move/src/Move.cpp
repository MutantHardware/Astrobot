#include "Arduino.h"
#include "Move.h"

Move::Move(int Pin_AIN1,int Pin_AIN2,int Pin_PWMA,int Pin_BIN1,int Pin_BIN2,int Pin_PWMB){
   // Assign Global Pins
   AIN1 = Pin_AIN1;
   AIN2 = Pin_AIN2;
   PWMA = Pin_PWMA;
   BIN1 = Pin_BIN1;
   BIN2 = Pin_BIN2;
   PWMB = Pin_PWMB;

   // Set Pins as OUTPUT
   pinMode(Pin_AIN1, OUTPUT);
   pinMode(Pin_AIN2, OUTPUT);
   pinMode(Pin_BIN1, OUTPUT);
   pinMode(Pin_BIN2, OUTPUT);

   ledcSetup(PWM_CA, PWM_F, PWM_R);
   ledcSetup(PWM_CB, PWM_F, PWM_R);
   ledcAttachPin(PWMA, PWM_CA);
   ledcAttachPin(PWMB, PWM_CB); 
}

void Move::forward(int DutyCycleA,int DutyCycleB){
        // Right Motor Forward
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);

        // Left Motor Forward
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);

        // PWM Configuration
        ledcWrite(PWM_CA, DutyCycleA);
        ledcWrite(PWM_CB, DutyCycleB);
}

void Move::backward(int DutyCycleA,int DutyCycleB){
        // Right Motor Backward
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);

        // Left Motor Backward
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);

        // PWM Configuration
        ledcWrite(PWM_CA, DutyCycleA);
        ledcWrite(PWM_CB, DutyCycleB);
}

void Move::right(int DutyCycleA,int DutyCycleB){
        // Right Motor Backward
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);

        // Left Motor Forward
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);

        // PWM Configuration
        ledcWrite(PWM_CA, DutyCycleA);
        ledcWrite(PWM_CB, DutyCycleB);
}

void Move::left(int DutyCycleA,int DutyCycleB){
        // Right Motor Forward
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);

        // Left Motor Backward
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);

        // PWM Configuration
        ledcWrite(PWM_CA, DutyCycleA);
        ledcWrite(PWM_CB, DutyCycleB);
}

void Move::stop(){
        // Right Motor OFF
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, LOW);

        // Left Motor OFF
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, LOW);

        // PWM Configuration
        ledcWrite(PWM_CA, 0);
        ledcWrite(PWM_CB, 0);
}