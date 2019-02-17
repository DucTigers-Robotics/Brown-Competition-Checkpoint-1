#include "ROB_Movement.h"

void ROB_Movement::move_forward(int spd)
{
  // code to move forward
}

void ROB_Movement::move_backward(int spd)
{
  // code to move backward
}

void ROB_Movement::stop()
{
  this.left_motor.stop();
  this.right_motor.stop();
}

void ROB_Movement::init()
{
  this.left_motor = new DT_Motor(LEFT_MOTOR_PIN_A,
                                 LEFT_MOTOR_PIN_B, 
                                 LEFT_MOTOR_PIN_PWM);

  this.right_motor = new DT_Motor(RIGHT_MOTOR_PIN_A,
                                  RIGHT_MOTOR_PIN_B, 
                                  RIGHT_MOTOR_PIN_PWM);
  
}

void ROB_Movement::move(int op_code)
{
  // ideally want a switch case for each fundamental function
  if (op_code == this.MOVE_FORWARD_2_SECONDS)
  {

    int t = millis();
    while((millis() - t) < 2000)
    {
      this.move_forward(128);
    }

    this.stop();
    return;
  }

  if (op_code == this.MOVE_BACKWARD_2_SECONDS)
  {
    int t = millis();
    while((millis() - t) < 2000)
    {
      this.move_backward(128);
    }
    
    return;
  }
}
