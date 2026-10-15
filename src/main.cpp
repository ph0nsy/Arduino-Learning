// LED binary counter
#include <Arduino.h>
#include<LED.h>
#define LED_COUNT 4

// Fucntion declarations:
void flash_LED(LED, int, int = 0);

// Global variable declarations:
int count = 0;
LED units[LED_COUNT] = { {11}, {10}, {9}, {8} };


// Runs once, before anything else
void setup() {
  Serial.begin(9000);
  for(int i = 0; i < LED_COUNT; i++) { pinMode(units[i].m_pin, OUTPUT); }
}

// Runs repeatedly
void loop() {
  // Add and clamp
  count++;
  count = count <= 0 ? 0 : count >= 1 << LED_COUNT ? 0 : count;

  for(int i = 0; i < LED_COUNT; i++) {
    units[i].m_state = count & (1 << i);  // Parse into bit
    digitalWrite(units[i].m_pin, units[i].m_state);
  }

  delay(1000);
}

// Function definitions:
void flash_LED(LED _pin, int _duration, int _downtime) {
  digitalWrite(_pin.m_pin, HIGH);
  delay(_duration);

  digitalWrite(_pin.m_pin, LOW);
  delay(_downtime > 0 ? _downtime : _duration);
}