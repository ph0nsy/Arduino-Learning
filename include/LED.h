#define MORSE_DOT 100
#define MORSE_LINE 500
#define WORD_DELAY 400

struct LED {
  int m_pin = 0;
  bool m_state = false; // off by default
  
  LED(int _pin, bool _initialState = false) {
    m_pin = _pin;
    m_state = _initialState;
  }

  void setLED(bool _state) { m_state = _state; }
  void toggleLED() { m_state = !m_state; }
};
