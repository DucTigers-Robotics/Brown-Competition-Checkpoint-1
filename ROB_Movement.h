#ifndef ROB_MOVEMENT_H
#define ROB_MOVEMENT_H

#include <arduino.h>
#include "ROB_WiringConstants.h"
#include "DT_Motor.h"

class ROB_Movement
{
  private:
  DT_Motor * left_motor, * right_motor;
  
  void move_forward(int spd);
  void move_backward(int spd);
  void turn_left(int deg);
  void turn_right(int deg);
  void stop();

  
  public:
  ROB_Movement();
  ~ROB_Movement();

  // move the robot based on the opcode. first byte is instruction, second is arg
  void move(int op_code);
  void adjust(int spd, int left_minus_right);

  // some testing opcodes
  const static int MOVE_FORWARD = 1;
  const static int MOVE_FORWARD_SLOW = 5;
  const static int MOVE_FORWARD_ULTRA_SLOW = 10;
  const static int MOVE_BACKWARD = 2;
  const static int TURN_LEFT = 3;
  const static int TURN_RIGHT = 4;
  const static int MOVE_STOP = 6;
  
};

#endif
