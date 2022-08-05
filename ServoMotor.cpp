#include "ServoMotor.h"
#include <arduino.h>

ServoMotor::ServoMotor(unsigned int pin, int posMin, int posMax)
{
  pin_ = pin;
  posMin_ = posMin;
  posMax_ = posMax;

  servo_ptr_ = std::make_shared<Servo>();  // class object initialization on the heap, pointer has address to Servo object
}

void ServoMotor::servoInit()
{
  servo_ptr_->attach(pin_);   // servo motor signal pin
  servo_ptr_->write(posMin_);  // reset servo motor angle to initial/starting position
  delay(1000);   // wait number of ms for the servo to reach the position
}

void ServoMotor::servoMove(int angle)
{
  servo_ptr_->write(angle);  // move servo motor to an angle given by argument
}

int ServoMotor::getServoPos()
{
  return servo_ptr_->read();
}