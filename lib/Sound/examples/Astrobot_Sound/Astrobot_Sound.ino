// Including Library
#include <Sound.h>

// Defining Buzzer Pin
#define Buzzer 25

// Creating sound object
Sound sound(Buzzer);

void setup() {

}

// Available sounds
void loop() {
  sound.connected();
  delay(1500);
  sound.disconnected();
  delay(1500);
  sound.pressed();
  delay(1500);
  sound.surprised();
  delay(1500);
  sound.happy();
  delay(1500);
  sound.sad();
  delay(1500);
  sound.confused();
  delay(1500);
  sound.fart();
  delay(1500);
  sound.forward();
  delay(1500);
  sound.backward();
  delay(1500);
  sound.right();
  delay(1500);
  sound.left();
  delay(1500);
}