#include "UltrasonicSensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int EchoPin, int TriggerPin){
  echoPin = EchoPin;
  triggerPin = TriggerPin;
  pinMode(EchoPin, INPUT);
  pinMode(TriggerPin, OUTPUT); 
}

float UltrasonicSensor::Distance(){
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  distance = pulseIn(echoPin, HIGH) * 0.034/2;
  return distance;
}