#include "ROB_DistanceSensing.h"

ROB_DistanceSensing::ROB_DistanceSensing()
{
  forward_sensor = new DT_DistanceSensor(FORWARD_DISTANCE_SENSOR_PIN, FORWARD_DISTANCE_SENSOR_ADDRESS);
  left_sensor = new DT_DistanceSensor(LEFT_DISTANCE_SENSOR_PIN, LEFT_DISTANCE_SENSOR_ADDRESS);
  right_sensor = new DT_DistanceSensor(RIGHT_DISTANCE_SENSOR_PIN, RIGHT_DISTANCE_SENSOR_ADDRESS);
  
}

ROB_DistanceSensing::~ROB_DistanceSensing()
{
  delete forward_sensor;
  delete left_sensor;
  delete right_sensor;
}

void ROB_DistanceSensing::init_sensors()
{
  pinMode(FORWARD_DISTANCE_SENSOR_PIN,OUTPUT);
  pinMode(LEFT_DISTANCE_SENSOR_PIN,OUTPUT);
  pinMode(RIGHT_DISTANCE_SENSOR_PIN,OUTPUT);

  digitalWrite(FORWARD_DISTANCE_SENSOR_PIN, LOW);
  digitalWrite(LEFT_DISTANCE_SENSOR_PIN, LOW);
  digitalWrite(RIGHT_DISTANCE_SENSOR_PIN, LOW);

  delay(1000);

  forward_sensor->setup();
  left_sensor->setup();
  right_sensor->setup();

}

int ROB_DistanceSensing::read_forward()
{
  return forward_sensor->read_distance();
}

int ROB_DistanceSensing::read_left()
{
  return left_sensor->read_distance();
}

int ROB_DistanceSensing::read_right()
{
  return right_sensor->read_distance();
}



