#include "LightScanner.h"

LightScanner::LightScanner(int posXMin, int posXMax, unsigned int posXStepIncrement, int posYmin, int posYmax, unsigned int posYStepIncrement, unsigned int numSamples, unsigned int sampleCycleTime)
{
  posXStepIncrement_ = posXStepIncrement;
  posYStepIncrement_ = posYStepIncrement;
  numSamples_ = numSamples;
  sampleCycleTime_ = sampleCycleTime;
  servoMotorX_ = std::make_shared<ServoMotor>(9, posXMin, posXMax);   // initialize pointer to servo motor object for horizontal (X-axis) movement
  //servoMotorY_ = std::make_shared<ServoMotor>(??, posYMin, posYMax);  // initialize pointer to servo motor object for vertical (Y-axis) movement
  lightSensor_ = std::make_shared<LightSensor>();   // initialize pointer to light sensor object
}

void LightScanner::scanLight()
{
  servoMotorX_->initialize();   // reset servo motor to initial/starting position angle
  Serial.print("pos: ");  Serial.println(servoMotorX_->getServoPos());

  lightSensor_->initialize();   // initialize light sensor
  lightSensor_->readLight();  // read light value
  Serial.print("light: ");  Serial.println(lightSensor_->getLightValueLux());  

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