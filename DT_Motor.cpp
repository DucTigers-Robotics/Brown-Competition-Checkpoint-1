#include "DT_Motor.h"

DT_Motor::DT_Motor(byte a, byte b, byte pwm, byte encoder_pin_a, byte encoder_pin_b)
: pin_a(a), pin_b(b), pin_pwm(pwm), encoder(Encoder(encoder_pin_a, encoder_pin_b))
{
  //encoder = Encoder();
}

void DT_Motor::setup()
{
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}

void DT_Motor::forward(byte spd)
{
  if (spd < 1)
   { digitalWrite(pin_a, LOW);}
  else
  {
   digitalWrite(pin_a, HIGH);
  }
  digitalWrite(pin_b, LOW);
  analogWrite(pin_pwm, spd);
 
}

void DT_Motor::backward(byte spd)
{
   digitalWrite(pin_a, LOW);
   if (spd < 1)
   {
  digitalWrite(pin_b, LOW);
   }
   else
   {
    digitalWrite(pin_b, HIGH);
    
   }
  analogWrite(pin_pwm, spd);
}

int DT_Motor::read_encoder()
{
  return encoder.read();
}

void DT_Motor::set_encoder(int pos)
{
  encoder.write(pos);
}

