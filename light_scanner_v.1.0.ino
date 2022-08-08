#include "LightSensorConfig.h"
#include "ServoMotor.h"
#include "LightScanner.h"
#include "LightSampleHandler.h"
#include "LightSensor.h"
#include <ArxSmartPtr.h>

//ServoMotor servo(9, 0, 180);
//std::shared_ptr<ServoMotor> test = std::make_shared<ServoMotor>(9, 0, 180);

void setup() {
  // put your setup code here, to run once:
  // serial monitor communication speed
  Serial.begin(9600);

  // hardware setup
  //lightSensorConfig();
  
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello world");

  /*
  LightSensor lightSensor;
  lightSensor.initialize();
  for(int i=0; i < 10; i++)
  {
    lightSensor.readLight();
    delay(500);
  }
  */

  LightScanner lightScanner(0, 180, 5, 0, 90, 5, 5, 2000);  // posXMin, posXMax, posXStepIncrement, posYmin, posYmax, posYStepIncrement, numSamples, sampleCycleTime;
  lightScanner.scanLight();
  delay(1000);
  
}



