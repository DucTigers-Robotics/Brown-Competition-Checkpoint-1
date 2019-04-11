#include "ROB_DistanceSensing.h"

ROB_DistanceSensing::ROB_DistanceSensing()
{
  forward_sensor = new DT_DistanceSensor(FORWARD_DISTANCE_SENSOR_PIN, FORWARD_DISTANCE_SENSOR_ADDRESS);
  left_sensor = new DT_DistanceSensor(LEFT_DISTANCE_SENSOR_PIN, LEFT_DISTANCE_SENSOR_ADDRESS);
  right_sensor = new DT_DistanceSensor(RIGHT_DISTANCE_SENSOR_PIN, RIGHT_DISTANCE_SENSOR_ADDRESS);

  left_motor_encoder = new Encoder(LEFT_MOTOR_ENCODER_PIN_INTERCEPT, LEFT_MOTOR_ENCODER_PIN_NORMAL);
  right_motor_encoder = new Encoder(RIGHT_MOTOR_ENCODER_PIN_INTERCEPT, RIGHT_MOTOR_ENCODER_PIN_NORMAL);
}

ROB_DistanceSensing::~ROB_DistanceSensing()
{
  delete forward_sensor;
  delete left_sensor;
  delete right_sensor;

  delete left_motor_encoder;
  delete right_motor_encoder;
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

  //write_left_encoder(0);
  //write_right_encoder(0);

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

int ROB_DistanceSensing::read_left_encoder()
{
  return left_motor_encoder->read();
}

int ROB_DistanceSensing::read_right_encoder()
{
  return right_motor_encoder->read();
}

void ROB_DistanceSensing::write_left_encoder(int pos)
{
  left_motor_encoder->write(pos);
}

void ROB_DistanceSensing::write_right_encoder(int pos)
{
  right_motor_encoder->write(pos);
}



