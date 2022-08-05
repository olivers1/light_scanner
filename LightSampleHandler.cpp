#include "LightSampleHandler.h"

LightSampleHandler::LightSampleHandler(unsigned int numSamples, unsigned int sampleCycleTime)
{
  numSamples_ = numSamples;
  sampleCycleTime_ = sampleCycleTime;
  RunningMedian samples_ = RunningMedian(10);   // instanciate object to hold light value samples. max number of samples = 10
  lightSample_ptr_ = std::make_shared<LightSample>();   // class object initialization on the heap, pointer has address to object
}

void LightSampleHandler::getMedianLight()
{

}

void LightSampleHandler::storeLightSample()
{

}