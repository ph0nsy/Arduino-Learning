#define MAX_ANALOG 255

struct Pin {
  int m_number;
  int m_mode;

  Pin(int _num, int _mod)
  : m_number(_num), m_mode(_mod)
  {}
};