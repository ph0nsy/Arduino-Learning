struct Pin {
  int number;
  int mode;
  bool bAnalog;

  Pin(int _num, int _mod, bool _bA = false){
    number = _num;
    mode = _mod;
    bAnalog = _bA;
  }
};