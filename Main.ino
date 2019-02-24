#include <Wire.h>
#include <VL6180X.h>

#include "ROB_Movement.h"
#include "DT_Motor.h"
#include "ROB_WiringConstants.h"

ROB_Movement * robot_movement_module;
//DT_Motor * motor;

void setup() {
  robot_movement_module = new ROB_Movement();
}

void loop() {


    robot_movement_module->move(ROB_Movement::MOVE_BACKWARD);
  delay(2000);


    robot_movement_module->move(ROB_Movement::MOVE_FORWARD_SLOW);
  delay(2000);

  
  robot_movement_module->move(ROB_Movement::MOVE_STOP);
  delay(1000);
}
