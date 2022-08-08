#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include <arduino.h>
#include <ArxSmartPtr.h>

  // connecting light sensor
  // -----------------------
  // connect SCL to I2C Clock
  // connect SDA to I2C Data
  // connect Vin to 3.3-5V DC
  // connect GROUND to common ground

class LightSensor
{
  public:
    LightSensor();
    void initialize();
    void readLight();
    unsigned int getLightValueLux();
  private:
    std::shared_ptr<Adafruit_TSL2591> lightSensor_ptr_;  // smart pointer to LightSensor object
    unsigned int lightValueLux_;
    void displaySensorDetails(void);
    void configureSensor(void);
    void unifiedSensorAPIRead(void);
};



#endif