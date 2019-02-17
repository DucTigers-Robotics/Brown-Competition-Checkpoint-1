#ifndef ROB_MOVEMENT_H
#define ROB_MOVEMENT_H

#include <arduino.h>
#include "ROB_WiringConstants.h"

class ROB_Movement
{
  private:
  DT_Motor left_motor, right_motor;
  
  void move_forward(int spd);
  void move_backward(int spd);

  
  public:
  ROB_Movement(){};
  ~ROB_Movement(){};

  void init();

  // move the robot based on the opcode. first byte is instruction, second is arg
  void move(int op_code);

  // some testing opcodes
  const static MOVE_FORWARD_2_SECONDS = 1;
  const static MOVE_BACKWARD_2_SECONDS = 2;
  
};

#endif
