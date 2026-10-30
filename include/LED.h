#define MORSE_DOT 100
#define MORSE_LINE 500
#define WORD_DELAY 400

struct LED {
  int m_pin = 0;
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


  LED(int _pin, int _initialState = 0) {
    m_pin = _pin;
    m_state = _initialState;
  }

  int getState_Analog() { return m_state > 255 ? 255 : m_state < 0 ? 0 : m_state; }
  int getState_Digital() { return m_state > 1 ? 1 : m_state < 0 ? 0 : m_state; }
  void setLED(int _state) { m_state = _state; }
  void toggleLED() { m_state = !m_state; }
};
