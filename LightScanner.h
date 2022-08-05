#ifndef LIGHTSCANNER_H
#define LIGHTSCANNER_H

class LightScanner
{
  public:
    LightScanner(unsigned int posXStepIncrement, unsigned int posYStepIncrement, unsigned int numSamples, unsigned int sampleCycleTime);
    void scanLight();
  private:
    unsigned int posXStepIncrement_;   // amount angle increment posX each position change
    unsigned int posYStepIncrement_;   // amount angle increment posY each position change
    unsigned int numSamples_;    // to be passed on to LightSampleHandler object
    unsigned int sampleCycleTime_;   // to be passed on to LightSampleHandler object
};

#endif