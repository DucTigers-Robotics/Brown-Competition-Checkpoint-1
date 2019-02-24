#include "ROB_Movement.h"


ROB_Movement::ROB_Movement()
{
  left_motor = new DT_Motor(LEFT_MOTOR_PIN_A,
                                 LEFT_MOTOR_PIN_B, 
                                 LEFT_MOTOR_PIN_PWM);

  right_motor = new DT_Motor(RIGHT_MOTOR_PIN_A,
                                  RIGHT_MOTOR_PIN_B, 
                                  RIGHT_MOTOR_PIN_PWM);
}

ROB_Movement::~ROB_Movement()
{
  delete left_motor;
  delete right_motor;
}

void ROB_Movement::move_forward(int spd)
{
   left_motor->forward(spd);
}

void ROB_Movement::move_backward(int spd)
{
  left_motor->backward(spd);
}

void ROB_Movement::stop()
{
  left_motor->stop();
  right_motor->stop();
}


void ROB_Movement::move(int op_code)
{
  // ideally want a switch case for each fundamental function

  switch(op_code)
  {
    case MOVE_FORWARD:
      move_forward(255);
      break;
    case MOVE_FORWARD_SLOW:
      move_forward(127);
      break;
    case MOVE_BACKWARD:
      move_backward(255);
      break;
    case MOVE_STOP:
      stop();
      break;
    default:
      break;
  }  
}
