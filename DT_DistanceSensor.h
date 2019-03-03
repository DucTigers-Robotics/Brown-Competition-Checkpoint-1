#ifndef DT_DISTANCE_SENSOR_HEADER
#define DT_DISTANCE_SENSOR_HEADER

#include <arduino.h>
#include <VL6180X.h>

#define RANGE 1

class DT_DistanceSensor : public VL6180X
{
  private:
  int pin;
  byte address;
  
  public:
  DT_DistanceSensor(int pin, byte address);
  ~DT_DistanceSensor(){};

  void setup();
  int read_distance();
};

#endif
