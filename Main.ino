#include <Wire.h>
#include <VL6180X.h>

#include "ROB_Movement.h"
#include "ROB_DistanceSensing.h"
#include "ROB_WiringConstants.h"

//ROB_Movement * robot_movement_module;
ROB_DistanceSensing * robot_distance_sensing;
//DT_Motor * motor;

void setup() {
Serial.begin(9600);
  Wire.begin();
  Serial.print("writing");
  
  robot_distance_sensing = new ROB_DistanceSensing();
  robot_distance_sensing->init_sensors();
  //robot_movement_module = new ROB_Movement();
  Serial.println();
}

void loop() {


Serial.print("\tforward: ");
Serial.print(robot_distance_sensing->read_forward());
Serial.print("\tleft: ");
Serial.print(robot_distance_sensing->read_left());
Serial.print("\tright: ");
Serial.print(robot_distance_sensing->read_right());
Serial.println();
  
}
