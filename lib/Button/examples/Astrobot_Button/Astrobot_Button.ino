// Including Library
#include <Button.h>

// Defining IR Sensor Pin
#define ForwardButtonPin
#define RightButtonPin
#define LeftButtonPin 
#define PlayButtonPin
#define FunctionButtonPin

// Creating Button object
Button Button(ForwardButtonPin,RightButtonPin,LeftButtonPin,PlayButtonPin,FunctionButtonPin);

void setup() {
  // Initializing Serial
  Serial.begin(9600);
}

void loop() {
  if (Button.Forward()) {
      Serial.println("Forward Button Pressed!");
  }
  if (Button.Right()) {
      Serial.println("Right Button Pressed!");
  }
  if (Button.Left()) {
      Serial.println("Left Button Pressed!");
  }
  if (Button.Play()) {
      Serial.println("Play Button Pressed!");
  }
  if (Button.Function()) {
      Serial.println("Function Button Pressed!");
  }
}
 
