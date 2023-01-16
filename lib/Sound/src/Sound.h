// Reference:  This library was adapted from the libray located here:
//             https://github.com/GypsyRobot/CuteBuzzerSounds

#ifndef Sound_h
#define Sound_h
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "Sounds.h"

#define debug true

class Sound {
public:
    Sound(int Buzzer);
    void _tone (float noteFrequency, long noteDuration, int silentDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void connected();
    void disconnected();
    void pressed();
    void surprised();
    void happy();
    void sad();
    void confused();
    void fart();
    void forward();
    void backward();
    void right();
    void left();
private:
    int buzzerPin;

    // PWM Settings
    const int PWM_CC = 5;   // PWM Channel C
    const int PWM_F = 2000; // PWM Frequency
    const int PWM_R = 8;    // PWM Resolution

};

#endif
