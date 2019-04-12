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
   right_motor->forward(spd);
}

void ROB_Movement::move_backward(int spd)
{
  left_motor->backward(spd);
  right_motor->backward(spd);
}

void ROB_Movement::turn_left(int deg)
{
  left_motor->forward(0);
  right_motor->forward(100);
  delay(1000);
  /*
  for(int i = 0; i < deg * 229; i++) {
    left_motor->backward(50);
    right_motor->forward(50);
  }
  for(int i = 0; i < deg * 229; i++) {
    left_motor->backward(50);
    right_motor->forward(50);
  }
  */
}

void ROB_Movement::turn_right(int deg)
{
  for(int i = 0; i < deg * 229; i++) {
    left_motor->forward(50);
    right_motor->backward(50);
  }
  for(int i = 0; i < deg * 229; i++) {
    left_motor->forward(50);
    right_motor->backward(50);
  }
}

void ROB_Movement::adjust(int spd, int left_minus_right)
{
  int diff = 0;
  int sign = abs(left_minus_right) / left_minus_right;
  
  if (abs(left_minus_right) > 100) {
    diff = 100 * sign;
  } else if (abs(left_minus_right) > 20) {
    diff = 20 * sign;
  } else if (abs(left_minus_right) > 5) {
    diff = 5 * sign;
  } else {
    diff = 0;
  }
  left_motor->forward(spd - abs(diff) - diff);
  right_motor->forward(spd - abs(diff) + diff);
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
    case MOVE_FORWARD_ULTRA_SLOW:
      move_forward(30);
      break;
    case MOVE_BACKWARD:
      move_backward(255);
      break;
    case TURN_LEFT:
      turn_left(90);
      break;
    case TURN_RIGHT:
      turn_right(90);
      break;
    case MOVE_STOP:
      stop();
      break;
    default:
      break;
  }  
}
