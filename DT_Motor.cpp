#include "DT_Motor.h"

DT_Motor::DT_Motor(byte a, byte b, byte pwm)
: pin_a(a), pin_b(b), pin_pwm(pwm)
{
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}

void DT_Motor::forward(byte spd)
{
  digitalWrite(pin_a, HIGH);
  digitalWrite(pin_b, LOW);
  
  analogWrite(pin_pwm, spd);
 
}

void DT_Motor::backward(byte spd)
{
  digitalWrite(pin_a, LOW);
  digitalWrite(pin_b, HIGH);
    
  analogWrite(pin_pwm, spd);
}

void DT_Motor::stop()
{
  // code to stop
  digitalWrite(pin_a, LOW);
  digitalWrite(pin_b, LOW);
}

