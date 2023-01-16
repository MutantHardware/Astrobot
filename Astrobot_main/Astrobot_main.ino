// Including Libraries
#include <Move.h>
#include <Wire.h>
#include <Sound.h>
#include <BoardSensor.h>

// General constants Definition
bool state; // State of Robot
bool played; // Variable to know if Buzzer has been played  

// Right motor pinout
#define AIN1 18    // GPIO18
#define AIN2 05    // GPIO05
#define PWMA 16    // GPIO16

// Left motor pinout
#define BIN1 19    // GPIO19
#define BIN2 23    // GPIO23
#define PWMB 17    // GPIO17

// Buzzer pinout
#define Buzzer 25  // GPIO25  

// Clap Sensor Pinout
#define ClapSensor 12 // GPIO12

// Creating Move object
Move Move(AIN1,AIN2,PWMA,BIN1,BIN2,PWMB);

// Creating Sensor Object
BoardSensor Sensor(Wire);

// Creating Sound object
Sound sound(Buzzer);

void setup() {
  // Initializing Serial and Sensor
  pinMode(ClapSensor, INPUT);
  Serial.begin(9600);
  Wire.begin();
  byte status = Sensor.begin();
  
  // Stay in the loop if sensor don't work
  while(status!=0){

  } 
  
  // Calculate Offsets
  delay(1000);
  Sensor.calcOffsets(true,true); 
      
  // Connected Sound
  sound.connected();
}

void loop() {
  // Update Sensor Readings
  Sensor.update();

  if (RobotStatus()){
     Serial.println("Robot Incapacitated.");
     Move.stop(); 
     RandomSound(played);
     played = false;
  }
  else {
     // Put button code here
  }
}

// Robot Status Function
bool RobotStatus(){
     if((abs(Sensor.AngleX()) > 30) || (abs(Sensor.AngleY()) > 30)
     ||(Sensor.Temperature() > 60)||(Sensor.Temperature() < -10)){
        state = true;
     }
     else {
       state = false;
     }
     return state;
}

// Random Sound Function
void RandomSound(bool played){
     if (played) {
        switch (random(1,7)){
            case 1:
              sound.surprised();
              break;
            case 2:
              sound.happy();
              break;
            case 3:
              sound.sad();
              break;
            case 4:
              sound.confused();
              break;
            case 5:    
              sound.fart();
              break;
            case 6:
              sound.pressed();
              break;
        }
     }
}
