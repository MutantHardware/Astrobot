// Including Libraries
#include <Wire.h>
#include <PID.h>
#include <Move.h>
#include <BoardSensor.h>

// Right motor pins definition
const int AIN1 = 18;   // GPIO18
const int AIN2 = 05;   // GPIO05
const int PWMA = 16;   // GPIO16

// Left motor pins definition
const int BIN1 = 19;   // GPIO19
const int BIN2 = 23;   // GPIO23
const int PWMB = 17;   // GPIO17

// General constants Definition
long timer = 0;
int defaultPWM  = 150; // Default PWM
int maxRate = 10;      // Max rate that PWM changes
float TargetAngle;     // Target Angle
float AngleY;          // Y angle
int RightMotorPWM;     // RightMotorPWM
int LeftMotorPWM;      // LeftMotorPWM

// PID Constants definition
const int Kp = 3;      // Kp
const int Ki = 2;      // Ki
const int Kd = 2;      // Kd

// Creating PID object
PID PID(Kp,Ki,Kd);

// Creating Move object
Move Move(AIN1,AIN2,PWMA,BIN1,BIN2,PWMB);

// Creating Sensor Object
BoardSensor Sensor(Wire);

void setup() {
      // Initializing Sensor
      Serial.begin(9600);
      Wire.begin();
      byte status = Sensor.begin();
  
      // Stay in the loop if sensor don't work
      while(status!=0) {

      } 
      
      // Calculate Target Y angle
      TargetAngle = Sensor.AngleY();
}

// Move robot with PID correction
void loop() {
        // Measure angle
        Sensor.update();
        AngleY = Sensor.AngleY();
        
        // Calculate PWM PID
        PID.CalculatePWM(AngleY,TargetAngle,defaultPWM,maxRate,&RightMotorPWM,&LeftMotorPWM);
        
        // Move Robot forward
        Move.forward(RightMotorPWM,LeftMotorPWM);
}
