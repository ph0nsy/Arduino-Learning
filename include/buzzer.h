#pragma once
#include <Arduino.h>

#define MIN_BUZZ 60.f
#define MAX_BUZZ 10000.f

void buzz_Active(int, int);

void buzz_Active(int _pin, int _downtime) {
  digitalWrite(_pin, HIGH);
  delayMicroseconds(_downtime);
  
  digitalWrite(_pin, LOW);
  delayMicroseconds(_downtime);
}