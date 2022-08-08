#ifndef LIGHTSCANNER_H
#define LIGHTSCANNER_H

#include "ServoMotor.h"
#include "LightSensor.h"
#include <ArxSmartPtr.h>

class LightScanner
{
  public:
    LightScanner(int posXMin, int posXMax, unsigned int posXStepIncrement, int posYmin, int posYmax, unsigned int posYStepIncrement, unsigned int numSamples, unsigned int sampleCycleTime);
    void scanLight();
  private:
    unsigned int posXStepIncrement_;   // angle increment of position at each step when scanning for light
    unsigned int posYStepIncrement_;  // amount angle increment posY each position change
    unsigned int numSamples_;    // to be passed on to LightSampleHandler object
    unsigned int sampleCycleTime_;   // to be passed on to LightSampleHandler object
    std::shared_ptr<ServoMotor> servoMotorX_;   // pointer to servo motor object for horizontal (X-axis) movement
    std::shared_ptr<ServoMotor> servoMotorY_;   // pointer to servo motor object for vertical (Y-axis) movement
    std::shared_ptr<LightSensor> lightSensor_;  // pointer to light sensor object
};

#endif