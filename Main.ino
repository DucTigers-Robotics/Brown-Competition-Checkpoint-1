#include <Wire.h>
#include <VL6180X.h>

#include "ROB_Movement.h"

ROB_Movement robot_movement_module;

void setup() {
  robot_movement_module = ROB_Movement();
  robot_movement_module.init();
}

void loop() {

  robot_movement_module.move(ROB_Movement::MOVE_FORWARD_2_SECONDS);
  robot_movement_module.move(ROB_Movement::MOVE_BACKWARD_2_SECONDS);
}
