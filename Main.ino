#include <Wire.h>
#include <VL6180X.h>

#include "ROB_Movement.h"
#include "ROB_DistanceSensing.h"
#include "ROB_WiringConstants.h"

ROB_Movement * robot_movement_module;
ROB_DistanceSensing * robot_distance_sensing;
//DT_Motor * motor;

int left;
int right;
int front;
int leftMinusRight;

void setup() {
Serial.begin(9600);
  Wire.begin();
  Serial.print("writing");
  
  robot_distance_sensing = new ROB_DistanceSensing();
  robot_distance_sensing->init_sensors();
  robot_movement_module = new ROB_Movement();
  Serial.println();
}

void loop() {

Serial.print("\tforward: ");
front = robot_distance_sensing->read_forward();
Serial.print(front);
Serial.print("\tleft: ");
left = robot_distance_sensing->read_left();
Serial.print(left);
Serial.print("\tright: ");
right = robot_distance_sensing->read_right();
Serial.print(right);
Serial.println();

robot_movement_module->move(1);
robot_movement_module->adjust(255, left - right);

// make left
if (left == 255 && right != 255) {
  robot_movement_module->move(5);
  delay(20);
  robot_movement_module->move(3);
}

/*
if(left - right > 5) {
  robot_movement_module->move(3);
} else if (left - right < -5) {
  robot_movement_module->move(4);
}
*/

//dont fall off edge
while (left == 255 && right == 255) {
  robot_movement_module->move(6);
  left = robot_distance_sensing->read_left();
  right = robot_distance_sensing->read_right();
}



/*
if(left - right > leftMinusRight) {
  robot_movement_module->move(3);
} else {
  robot_movement_module->move(4);
}
leftMinusRight = left - right;
*/

/*robot_movement_module->move(3);
robot_movement_module->move(4);
robot_movement_module->move(10);
delay(1000);
robot_movement_module->move(6);
delay(1000);*/

}
