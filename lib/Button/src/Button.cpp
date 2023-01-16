#include "Button.h"
#include "Arduino.h"

Button::Button(int ForwardButtonPin, int RightButtonPin, int LeftButtonPin, int PlayButtonPin, int FunctionButtonPin){
  // Pin Mode 
  pinMode(ForwardButtonPin, INPUT);
  pinMode(RightButtonPin, INPUT);
  pinMode(LeftButtonPin, INPUT);
  pinMode(PlayButtonPin, INPUT);
  pinMode(FunctionButtonPin, INPUT);
  
  // Global Variables
  ForwardButton = ForwardButtonPin;
  RightButton = RightButtonPin;
  LeftButton = LeftButtonPin;
  PlayButton = PlayButtonPin;
  FunctionButton = FunctionButtonPin;
}

bool Button::Forward(){
return !digitalRead(ForwardButton);
}

bool Button::Right(){
return !digitalRead(RightButton);
}

bool Button::Left(){
return !digitalRead(LeftButton);
}

bool Button::Play(){
return !digitalRead(PlayButton);
}

bool Button::Function(){
return !digitalRead(FunctionButton);
}