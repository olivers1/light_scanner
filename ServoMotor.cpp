#include "ServoMotor.h"
#include <arduino.h>

ServoMotor::ServoMotor(unsigned int pin, int posMin, int posMax)
{
  pin_ = pin;
  posMin_ = posMin;
  posMax_ = posMax;
  posLatest_ = 0;
  servo_ptr_ = std::make_shared<Servo>();  // class object initialization on the heap, pointer has address to Servo object
}

void ServoMotor::servoInit()
{
  Serial.println("initializing..");
  servo_ptr_->attach(pin_);   // servo motor signal pin
  // calibrate servo motor position
  servo_ptr_->write(180);   // reset servo motor angle to initial/starting position
  delay(2000);   // wait number of ms for the servo to reach the position
  servo_ptr_->write(0);   // reset servo motor angle to initial/starting position
  delay(2000);   // wait number of ms for the servo to reach the position
  // move servo motor to initial/start position
  servo_ptr_->write(posMin_);  // reset servo motor angle to initial/starting position
  delay(2000);   // wait number of ms for the servo to reach the position
  posLatest_ = servo_ptr_->read();
}

void ServoMotor::servoMove(int posNew)
{
  Serial.print("move to position..");
  Serial.println(posNew);
  servo_ptr_->write(posNew);  // move servo motor to an angle given by argument
  delay(1500);
  /*
  unsigned int timeDelay;
  if(abs(posNew-posLatest_) <= 50)
  {
    timeDelay = 800;
  }
  else if(abs(posNew-posLatest_) > 50 && abs(posNew-posLatest_) <= 90)
  {
    timeDelay = 1000;
  }
  else
  {
    timeDelay = 1500;
  }
  delay(timeDelay);
  */
  posLatest_ = servo_ptr_->read();  
}

int ServoMotor::getServoPos()
{
  return servo_ptr_->read();
}