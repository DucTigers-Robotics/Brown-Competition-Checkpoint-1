#ifndef DT_MOTOR_HEADER
#define DT_MOTOR_HEADER

#include <arduino.h>
#include <Encoder.h>

class DT_Motor
{
  private:
  byte pin_a, pin_b, pin_pwm;
  Encoder encoder;
  
  public:
  DT_Motor(byte a, byte b, byte pwd, byte encoder_pin_a, byte encoder_pin_b);
  ~DT_Motor(){};

  void setup();
  
  void forward(byte spd);
  void backward(byte spd);
  
  int read_encoder();
  void set_encoder(int pos);
};

#endif
