#include <Wire.h>
#include <VL6180X.h>

#include "DT_Motor.h"
#include "DT_DistanceSensor.h"

// NEED TO CHANGE LAST TO ARGUMENTS TO FIT ACTUAL WIRING
DT_Motor motor_left(8, 7, 6, 2, 5);
DT_Motor motor_right(5, 12, 9, 3, 11);

DT_DistanceSensor distance_sensor;

void setup() {
   Serial.begin(9600);
  Wire.begin();
  
  // put your setup code here, to run once:
  distance_sensor.setup();

  motor_left.setup();
  motor_right.setup();

//  motor_left.set_encoder(0);
//  motor_right.set_encoder(0);
}
void forward(int spd) {
  // NOTE: One needs to move forward while the other moves backwards because of orientation
  motor_left.forward(spd);
  motor_right.forward(spd);
}

void backward(int spd) {
  // NOTE: same issue as forward()
  motor_left.backward(spd);
  motor_right.forward(spd);
}
byte r = 0;
void loop() {
  delay(1000);
  motor_right.forward(160);
  motor_left.forward( 160);
  r = distance_sensor.readRangeContinuousMillimeters();
  Serial.print("Range: ");
  Serial.print(r);
  Serial.println();
  if (r> 30)
  {
    motor_right.forward(160);
    motor_left.forward(160);
  }
  else
  {
    motor_left.forward(0);
    motor_right.forward(0);
    
  }
  
  // put your main code here, to run repeatedly:
  //forward(100);
  //
  
  
//  Serial.print("Ambient: ");
//  Serial.print(distance_sensor.readAmbientContinuous());
//      
//  if (distance_sensor.timeoutOccurred()) 
//    Serial.print(" TIMEOUT");
//    
//  Serial.print("\tRange: ");
//  Serial.print(distance_sensor.readRangeContinuousMillimeters());
//  
//  if (distance_sensor.timeoutOccurred())
//    Serial.print(" TIMEOUT"); 
//  
//  Serial.println();
///  OUTPUT ENCODER READINGS FOR TESTING
  Serial.print("ENCODER LEFT READING: ");
  Serial.print(motor_left.read_encoder());
  Serial.println();

  Serial.print("ENCODER RIGHT READING: ");
  Serial.print(motor_right.read_encoder());
  Serial.println();
//  
//  
//  delay(1000);
//
}
