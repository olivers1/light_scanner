#include "LightScanner.h"
#include "ServoMotor.h"

LightScanner::LightScanner(int posXMin, int posXMax, unsigned int posXStepIncrement, int posYmin, int posYmax, unsigned int posYStepIncrement, unsigned int numSamples, unsigned int sampleCycleTime)
{
  posXStepIncrement_ = posXStepIncrement;
  posYStepIncrement_ = posYStepIncrement;
  numSamples_ = numSamples;
  sampleCycleTime_ = sampleCycleTime;
  servoMotorX_ = std::make_shared<ServoMotor>(9, posXMin, posXMax);   // pointer to servo motor object for horizontal (X-axis) movement
  //servoMotorY_ = std::make_shared<ServoMotor>(??, posYMin, posYMax);  // pointer to servo motor object for vertical (Y-axis) movement
}

void LightScanner::scanLight()
{
  servoMotorX_->servoInit();  // reset servo motor to initial/starting position angle
  Serial.println(servoMotorX_->getServoPos());
  // for loop to increment position step until posMax is reached
  // for loop to take number of measurement samples that is specified
  // 
  servoMotorX_->servoMove(180);
  Serial.println(servoMotorX_->getServoPos());
  delay(500);
  
  servoMotorX_->servoMove(90);
  Serial.println(servoMotorX_->getServoPos());
  delay(500);
}