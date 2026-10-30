// Pulse Width Modulation
#include <Arduino.h>
#include<LED.h>
#define NORM2VOLTAGE 5.f/1023.f
#define POT2LED 255.f/1023.f
#define BAUD_RATE 9600
#define DELAY 500
#define READ_THRESHOLD 4.0f

struct Pin {
  uint16_t number;
  uint8_t mode;
  bool bAnalog;

  Pin(uint16_t _num, uint8_t _mod, bool _bA = false){
    number = _num;
    mode = _mod;
    bAnalog = _bA;
  }
};

// Fucntion declarations:
void flash_LED(LED, int, int = 0);

// Global variable declarations:
Pin pins[] = { Pin(A2, INPUT, true), Pin(6, OUTPUT, true) };

// Runs once, before anything else
void setup() {
  // Set up serial port 
  Serial.begin(BAUD_RATE); // Baud Rate (bits/sec)
  for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
    pinMode(pins[i].number, pins[i].mode);
  } 
}

// Runs repeatedly
void loop() {
  Serial.println("-------------------------------------");
  float Pot_val = analogRead(pins[0].number);
  float LED_val = POT2LED * Pot_val;
  analogWrite(pins[1].number, LED_val);

  Serial.println(Pot_val);
  Serial.println(LED_val);

  /*
  for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
    if(pins[i].bAnalog) {
      Serial.print("Analog read: ");
      Serial.println(analogRead(pins[i].number));
    }
    else {
      Serial.print("Digital read: ");
      Serial.println(digitalRead(pins[i].number));
    }
  } 
  */

  /* 
  digitalWrite(
    pins[1].number, 
    potentiometer >= READ_THRESHOLD ? HIGH : LOW
  );
  */

  delay(DELAY);
}

// Function definitions:
void flash_LED(LED _pin, int _duration, int _downtime) {
  digitalWrite(_pin.m_pin, HIGH);
  delay(_duration);

  digitalWrite(_pin.m_pin, LOW);
  delay(_downtime > 0 ? _downtime : _duration);
}

