#ifndef Button_h
#define Button_h
#include "Arduino.h"

class Button{
  private:
   int ForwardButton,RightButton,LeftButton,PlayButton,FunctionButton;
  public:
    Button(int ForwardButtonPin, int RightButtonPin, int LeftButtonPin, int PlayButtonPin, int FunctionButtonPin);
    bool Forward();
    bool Right();
    bool Left();
    bool Play();
    bool Function();
};

