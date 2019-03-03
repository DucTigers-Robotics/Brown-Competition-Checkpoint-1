#ifndef ROB_DISTANCESENSING_H
#define ROB_DISTANCESENSING_H

#include <arduino.h>
#include "DT_DistanceSensor.h"
#include "ROB_WiringConstants.h"

class ROB_DistanceSensing 
{
  private:
  DT_DistanceSensor * forward_sensor, * left_sensor, * right_sensor;
  
  public:
  ROB_DistanceSensing();
  ~ROB_DistanceSensing();


  void init_sensors();
  
  int read_forward();
  int read_left();
  int read_right();
};

#endif
