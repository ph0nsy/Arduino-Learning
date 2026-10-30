// Pulse Width Modulation
#include <Arduino.h>
#include <LED.h>
#include <Pin.h>

#define NORM2VOLTAGE 5.f/1023.f
#define POT2LED 255.f/1023.f

#define BAUD_RATE 9600  // Baud Rate (bits/sec)
#define DELAY 500

struct RGB {
  int r = 0, g = 0, b = 0;
};

// Function declarations:
void flash_LED(LED, int, int = 0);

// Global variable declarations:
Pin pins[] = { Pin(11, OUTPUT, true), Pin(10, OUTPUT, true), Pin(9, OUTPUT, true) };
String msg[] = { "Red: ", "Green: ", "Blue: " };
RGB color;
int readInt = 0;
float readFloat = 0.0f;
String readStr = "";

// Runs once, before anything else
void setup() {
  Serial.begin(BAUD_RATE); 
  for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
    pinMode(pins[i].number, pins[i].mode);
  } 
}

// Runs repeatedly
void loop() {

  Serial.println(msg[0]);
  while (Serial.available() == 0) { }
  color.r = Serial.parseInt();
  Serial.println(color.r);
  analogWrite(pins[0].number, color.r);
  
  Serial.println(msg[1]);
  while (Serial.available() == 0) { }
  color.g = Serial.parseInt();
  Serial.println(color.g);
  analogWrite(pins[1].number, color.g);
  
  Serial.println(msg[2]);
  while (Serial.available() == 0) { }
  color.b = Serial.parseInt();
  Serial.println(color.b);
  analogWrite(pins[2].number, color.b);

  /*
  for (size_t i = 0; i < readInt; i++)
  {
    digitalWrite(pins[i].number, HIGH);
    delay(DELAY);
    digitalWrite(pins[i].number, LOW);
    delay(DELAY);
  }
  Serial.println(msg[0]);
  while (Serial.available() == 0) { }
  readInt = Serial.parseInt();
  Serial.println("Look at the LED");
  for (size_t i = 0; i < readInt; i++)
  {
    digitalWrite(pin.number, HIGH);
    delay(DELAY);
    digitalWrite(pin.number, LOW);
    delay(DELAY);
  }
  
  Serial.println(msg[1]);
  while (Serial.available() == 0) { }
  readStr = Serial.readString();
  Serial.println(readStr);
  
  Serial.println(msg[2]);
  while (Serial.available() == 0) { }
  readStr = Serial.readStringUntil('\n');
  Serial.println(readStr);

  Serial.println(msg[3]);
  while (Serial.available() == 0) { }
  readFloat = Serial.parseFloat();
  Serial.println(readFloat*readFloat*3.14f);*/
}

// Function definitions:
void flash_LED(LED _pin, int _duration, int _downtime) {
  digitalWrite(_pin.m_pin, HIGH);
  delay(_duration);

  digitalWrite(_pin.m_pin, LOW);
  delay(_downtime > 0 ? _downtime : _duration);
}

