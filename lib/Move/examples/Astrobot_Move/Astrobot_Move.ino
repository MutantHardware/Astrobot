// Including Library
#include <Move.h>

// Right pins definition
const int AIN1 = 18;   // GPIO18
const int AIN2 = 05;   // GPIO05
const int PWMA = 16;   // GPIO16

// Left pins definition
const int BIN1 = 19;   // GPIO19
const int BIN2 = 23;   // GPIO23
const int PWMB = 17;   // GPIO17

// Creating Move object
Move Move(AIN1,AIN2,PWMA,BIN1,BIN2,PWMB);

// Velocity Definition
int DutyCycleA = 100;
int DutyCycleB = 100;

void setup() {

}

// Move robot
void loop() {
  Move.stop();
  Move.forward(DutyCycleA,DutyCycleB);
  delay(1500);
  Move.stop();
  Move.backward(DutyCycleA,DutyCycleB);
  delay(1500);
  Move.stop();
  Move.left(DutyCycleA,DutyCycleB);
  delay(1500);
  Move.stop();
  Move.right(DutyCycleA,DutyCycleB);
  delay(1500);
}
