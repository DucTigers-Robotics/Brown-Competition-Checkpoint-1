#ifndef DT_DISTANCE_SENSOR_HEADER
#define DT_DISTANCE_SENSOR_HEADER

#include <arduino.h>
#include <VL6180X.h>

class DT_DistanceSensor : public VL6180X
{
  private:
  public:
  DT_DistanceSensor();
  ~DT_DistanceSensor(){};

  void setup();
};

#endif
