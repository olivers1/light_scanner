#include "LightScanner.h"
#include "ServoMotor.h"

LightScanner::LightScanner(unsigned int posXStepIncrement, unsigned int posYStepIncrement, unsigned int numSamples, unsigned int sampleCycleTime)
{
  posXStepIncrement_ = posXStepIncrement;
  posYStepIncrement_ = posYStepIncrement;
  numSamples_ = numSamples;
  sampleCycleTime_ = sampleCycleTime;
}

void LightScanner::scanLight()
{
  // reset servo motor to initial/starting position angle 
  
  //servo.
}