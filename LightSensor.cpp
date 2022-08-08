#include "LightSensor.h"

LightSensor::LightSensor()
{
  lightSensor_ptr_ = std::make_shared<Adafruit_TSL2591>(2591);  // class object initialization on the heap, pointer has address to LightSensor object. number 2591 is used for sensor identifier
  lightValueLux_ = 0;

}

void LightSensor::initialize()
{
  Serial.println("initializing [light sensor]");
  
  if (lightSensor_ptr_->begin()) 
  {
    Serial.println(F("found a TSL2591 sensor"));
  } 
  else 
  {
    Serial.println(F("no sensor found.. check your wiring?"));
    while (1);
  }
    
  displaySensorDetails();   // display some basic information on this sensor
  configureSensor();  // configure the sensor
}

void LightSensor::readLight()
{
  unifiedSensorAPIRead();
}

unsigned int LightSensor::getLightValueLux()
{
  return lightValueLux_;
}

void LightSensor::displaySensorDetails(void)
{
  sensor_t sensor;
  lightSensor_ptr_->getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" lux"));
  Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" lux"));
  Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution, 4); Serial.println(F(" lux"));  
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));
  delay(500);
}

void LightSensor::configureSensor(void)
{
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  lightSensor_ptr_->setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
  //lightSensor_ptr_->setGain(TSL2591_GAIN_MED);      // 25x gain
  //lightSensor_ptr_->setGain(TSL2591_GAIN_HIGH);   // 428x gain
  
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  //lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
  lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_200MS);
  //lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_300MS);
  // lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_400MS);
  // lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_500MS);
  // lightSensor_ptr_->setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)

  /* Display the gain and integration time for reference sake */  
  Serial.println(F("------------------------------------"));
  Serial.print  (F("Gain:         "));
  tsl2591Gain_t gain = lightSensor_ptr_->getGain();
  switch(gain)
  {
    case TSL2591_GAIN_LOW:
      Serial.println(F("1x (Low)"));
      break;
    case TSL2591_GAIN_MED:
      Serial.println(F("25x (Medium)"));
      break;
    case TSL2591_GAIN_HIGH:
      Serial.println(F("428x (High)"));
      break;
    case TSL2591_GAIN_MAX:
      Serial.println(F("9876x (Max)"));
      break;
  }
  Serial.print  (F("Timing:       "));
  Serial.print((lightSensor_ptr_->getTiming() + 1) * 100, DEC); 
  Serial.println(F(" ms"));
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));
}

void LightSensor::unifiedSensorAPIRead(void)
{
  /* Get a new sensor event */ 
  sensors_event_t event;
  lightSensor_ptr_->getEvent(&event);
 
  /* Display the results (light is measured in lux) */
  Serial.print(F("[ ")); Serial.print(event.timestamp); Serial.print(F(" ms ] "));
  if ((event.light == 0) |
      (event.light > 4294966000.0) | 
      (event.light <-4294966000.0))
  {
    /* If event.light = 0 lux the sensor is probably saturated */
    /* and no reliable data could be generated! */
    /* if event.light is +/- 4294967040 there was a float over/underflow */
    Serial.println(F("Invalid data (adjust gain or timing)"));
  }
  else
  {
    lightValueLux_ = event.light;
    Serial.print(lightValueLux_/*event.light*/); Serial.println(F(" lux"));
  }
}