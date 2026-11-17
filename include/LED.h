#pragma once
#include <Arduino.h>
#include <rgb.h>

#define LED_GROWTH 5

#define MORSE_DOT 100
#define MORSE_LINE 500
#define WORD_DELAY 400

struct LED {
private:
  int m_state = 0; // [0,1] or [0, 255] <=> [0V, 5V]
  // On an interesting note, if hooked on an osciloscope,
  // alalogWrite() seems that the average LED circuit 
  // tries to give, rather the exact value from 0 to 255, 
  // the average voltage output using the minimum and 
  // maximum possible (however, we won't be able to see it).
  //
  // For example, for 127:
  //  - Half the time it will be the maximum
  //  - Half the time it will be minimum
  //
  // Or, for 64:
  //  - A quarter of the time it will be the maximum
  //  - Three quarters it will be the minimum

public:
  LED (int _initialState = 0)
  : m_state(_initialState) 
  {}

  int getState_Analog() { return m_state; }
  int getState_Digital() { return m_state > 1 ? 1 : m_state < 0 ? 0 : m_state; }
  void setLED(int _state) { m_state = _state > 255 ? 255 : _state < 0 ? 0 : _state; }
  void toggleLED() { m_state = m_state > 0 ? 0 : 1; }
};

struct LED_RGB {

  LED_RGB (RGB _initialColor) 
  : m_color (_initialColor)
  {}
  
  void setColorChannel(eColorChannel _chnl, int _val) 
  { 
    switch (_chnl)
    {
      case eColorChannel::RED:
        m_color.r = _val; 
        break;
      case eColorChannel::GREEN:
        m_color.g = _val;
        break;
      
      default:
        m_color.b = _val;
        break;
    }
  }
  void toggleLED(eColorChannel _chnl) {   
    switch (_chnl)
    {
      case eColorChannel::RED:
        m_color.r = m_color.r > 0 ? 0 : 1; 
        break;
      case eColorChannel::GREEN:
        m_color.g = m_color.g > 0 ? 0 : 1;
        break;
      
      default:
        m_color.b = m_color.b > 0 ? 0 : 1;
        break;
    }
  }
  
  RGB getColor() { return m_color; }
  int getChannel(eColorChannel _chnl, bool bReadAnalog = true) { 
    int channel = _chnl == eColorChannel::RED 
    ? m_color.r : _chnl == eColorChannel::GREEN 
    ? m_color.g : m_color.b;
    int threshold = bReadAnalog ? 255 : 1;
    return channel > threshold ? threshold : channel < 0 ? 0 : channel; 
  }

private:
  RGB m_color;
};

void flash_LED(LED, int, int = 0);

void flash_LED(int _pin, int _duration, int _downtime) {
  digitalWrite(_pin, HIGH);
  delay(_duration);

  digitalWrite(_pin, LOW);
  delay(_downtime > 0 ? _downtime : _duration);
}