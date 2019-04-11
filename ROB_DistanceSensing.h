#ifndef ROB_DISTANCESENSING_H
#define ROB_DISTANCESENSING_H

#include <arduino.h>
#include <Encoder.h>
#include "DT_DistanceSensor.h"
#include "ROB_WiringConstants.h"

class ROB_DistanceSensing 
{
  private:
  // laser sensor
  DT_DistanceSensor * forward_sensor, * left_sensor, * right_sensor;
  
  // encoders
  Encoder * left_motor_encoder, * right_motor_encoder;
  
  public:
  ROB_DistanceSensing();
  ~ROB_DistanceSensing();


  void init_sensors();
  
  int read_forward();
  int read_left();
  int read_right();

  int read_left_encoder();
  int read_right_encoder();

  void write_left_encoder(int pos);
  void write_right_encoder(int pos);
};

#endif
