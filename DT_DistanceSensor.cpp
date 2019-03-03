#include "DT_DistanceSensor.h"

// Testing editing a file.
DT_DistanceSensor::DT_DistanceSensor(int pin, byte address)
: pin(pin), address(address)
{
}

void DT_DistanceSensor::setup()
{
  digitalWrite(pin, HIGH);
  delay(50);
  init();
  configureDefault();
  setAddress(address);
  writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
  writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
  setTimeout(500);
  stopContinuous();
  setScaling(RANGE);
  delay(300);
  startInterleavedContinuous(100);
  delay(100);
}

int DT_DistanceSensor::read_distance()
{
  return readRangeContinuousMillimeters();
}

