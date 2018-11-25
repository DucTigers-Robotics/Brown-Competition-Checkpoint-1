#ifndef DT_MOTOR_HEADER
#define DT_MOTOR_HEADER

#include <arduino.h>

class DT_Motor
{
  private:
  byte pin_a, pin_b, pin_pwm;
  
  public:
  DT_Motor(byte a, byte b, byte pwd);
  ~DT_Motor(){};

  void setup();
  void forward(byte spd);
  void backward(byte spd);
};

#endif
