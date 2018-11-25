#include <Wire.h>
#include <Encoder.h>
#include <VL6180X.h>

#include "DT_Motor.h"
#include "DT_DistanceSensor.h"

DT_Motor motor_left(8, 7, 6);
DT_Motor motor_right(5, 12, 9);

DT_DistanceSensor distance_sensor;

void setup() {
   Serial.begin(9600);
  Wire.begin();
  
  // put your setup code here, to run once:
  distance_sensor.setup();

  motor_left.setup();
  motor_right.setup();
}
void forward(int spd) {
  // NOTE: One needs to move forward while the other moves backwards because of orientation
  motor_left.forward(spd);
  motor_right.backward(spd);
}

void backward(int spd) {
  // NOTE: same issue as forward()
  motor_left.backward(spd);
  motor_right.forward(spd);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(100);
  
  Serial.print("Ambient: ");
  Serial.print(distance_sensor.readAmbientContinuous());
      
  if (distance_sensor.timeoutOccurred()) 
    Serial.print(" TIMEOUT");
    
  Serial.print("\tRange: ");
  Serial.print(distance_sensor.readRangeContinuousMillimeters());
  
  if (distance_sensor.timeoutOccurred())
    Serial.print(" TIMEOUT"); 
  
  Serial.println();
  
  delay(1000);
}
