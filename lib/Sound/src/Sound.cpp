// Reference:  This library was adapted from the libray located here:
//             https://github.com/GypsyRobot/CuteBuzzerSounds

#include "Arduino.h"
#include "Sound.h"

Sound::Sound(int Buzzer) {
   buzzerPin = Buzzer;
  #if defined(ESP32)
      ledcSetup(PWM_CC,PWM_F,PWM_R); 
      ledcAttachPin(buzzerPin,PWM_CC);
  #endif
}

void Sound::_tone (float noteFrequency, long noteDuration, int silentDuration){
  if(silentDuration==0) {silentDuration=1;}

    #if defined(ESP32)
        ledcWriteTone(PWM_CC,noteFrequency);
        delay(noteDuration);     // milliseconds
        ledcWrite(PWM_CC,0);     // notone
    #else
        tone(buzzerPin, noteFrequency, noteDuration);
        delay(noteDuration);     // milliseconds
    #endif

  delay(silentDuration);
}

void Sound::bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration){

  //Examples:
  //  bendTones (880, 2093, 1.02, 18, 1);
  //  bendTones (note_A5, note_C7, 1.02, 18, 0);

  if(silentDuration==0) {silentDuration=1;}

  if(initFrequency < finalFrequency)
  {
    for (int i=initFrequency; i<finalFrequency; i=i*prop) {
      _tone(i, noteDuration, silentDuration);
    }

  } else{

    for (int i=initFrequency; i>finalFrequency; i=i/prop) {
      _tone(i, noteDuration, silentDuration);
    }
  }
}

void Sound::connected(){
    _tone(NOTE_E5,50,30);
    _tone(NOTE_E6,55,25);
    _tone(NOTE_A6,60,10);
}

void Sound::disconnected(){
    _tone(NOTE_E5,50,30);
    _tone(NOTE_A6,55,25);
    _tone(NOTE_E6,50,60);
}

void Sound::pressed(){
    bendTones (NOTE_E6, NOTE_G6, 1.03, 20, 2);
    delay(30);
    bendTones (NOTE_E6, NOTE_D7, 1.04, 10, 2);
}

void Sound::surprised(){
    bendTones(800, 2150, 1.02, 10, 1);
    bendTones(2149, 800, 1.03, 7, 1);
}

void Sound::happy(){
    bendTones(1500, 2500, 1.05, 20, 8);
    bendTones(2499, 1500, 1.05, 25, 8);
}

void Sound::sad(){
   bendTones(880, 669, 1.02, 20, 200);
}

void Sound::confused(){
    bendTones(1000, 1700, 1.03, 8, 2);
    bendTones(1699, 500, 1.04, 8, 3);
    bendTones(1000, 1700, 1.05, 9, 10);
}

void Sound::fart(){
    bendTones(1600, 4000, 1.02, 2, 20);
    bendTones(4000, 3000, 1.02, 2, 20);
}

void Sound::forward(){
    _tone(NOTE_C4,500,1);
}

void Sound::backward(){
    _tone(NOTE_E4,500,1);
}

void Sound::right(){
   _tone(NOTE_E4,500,1);
}

void Sound::left(){
  _tone(NOTE_D4,500,1);
}