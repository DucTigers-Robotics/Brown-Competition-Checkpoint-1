#include "DT_DistanceSensor.h"

DT_DistanceSensor::DT_DistanceSensor()
{
}

void DT_DistanceSensor::setup()
{
  init();
  configureDefault();
  // Reduce range max convergence time and ALS integration
  // time to 30 ms and 50 ms, respectively, to allow 10 Hz
  // operation (as suggested by Table 6 ("Interleaved mode
  // limits (10 Hz operation)") in the datasheet).
  writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
  writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
  setTimeout(500);
   // stop continuous mode if already active
  stopContinuous();
  // in case stopContinuous() triggered a single-shot
  // measurement, wait for it to complete
  delay(300);
  // start interleaved continuous mode with period of 100 ms
  startInterleavedContinuous(100);
}
