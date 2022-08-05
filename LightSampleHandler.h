#ifndef LIGHTSAMPLEHANDLER_H
#define LIGHTSAMPLEHANDLER_H

#include <RunningMedian.h>
#include <ArxContainer.h>
#include <ArxSmartPtr.h>

struct LightSample
{
  unsigned int posTableValue_;   // posX range: -180 - +180 => 0 - 360 x 100, posY range: 0 - +90 => 0 - 90 x 1
  int posX_;
  int posY_;
  unsigned long int timestamp_;
  float lightMedianValue_;
};

class LightSampleHandler
{
  public:
    LightSampleHandler(unsigned int numSamples, unsigned int sampleCycleTime);
    void storeLightSample();
    void getMedianLight();
    ~LightSampleHandler();
  private:
    unsigned int numSamples_;   // number of samples to take at each position
    unsigned int sampleCycleTime_;  // time delay between each sample
    //LightSample lightSample_;   // instance of Sample struct
    std::shared_ptr<LightSample> lightSample_ptr_;  // smart pointer to LightSample object
    arx::map<unsigned int, std::shared_ptr<LightSample>> sampleSeries_;   // map with posTableValue as key : smart pointer to LightSample as value
};

#endif