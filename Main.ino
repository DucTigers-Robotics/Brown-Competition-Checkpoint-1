#include <Wire.h>
#include <VL6180X.h>

#include "ROB_Movement.h"
#include "ROB_DistanceSensing.h"
#include "ROB_WiringConstants.h"

ROB_Movement * robot_movement_module;
ROB_DistanceSensing * robot_distance_sensing;
//DT_Motor * motor;

int timer = 0;

void setup() {
Serial.begin(9600);
  Wire.begin();
  Serial.print("writing");
  
  robot_distance_sensing = new ROB_DistanceSensing();
  robot_distance_sensing->init_sensors();
  robot_movement_module = new ROB_Movement();
  Serial.println();

  //robot_movement_module->move(ROB_Movement::MOVE_FORWARD);
}

void loop() {
  Serial.println(robot_distance_sensing->read_left_encoder());
  //Serial.println(robot_distance_sensing->read_right_encoder());
  Serial.println();

  if (timer <= 5000)
  {
    robot_movement_module->move(ROB_Movement::MOVE_FORWARD);
  }
  else
  {
    robot_movement_module->move(ROB_Movement::MOVE_BACKWARD);
  }
  
  delay(50);
  timer += 50;
  Serial.println(robot_distance_sensing->read_left_encoder());
}
