#ifndef SERVOMOTORCONFIG_H
#define SERVOMOTORCONFIG_H

#include <Servo.h>

// class object initialization
Servo servo;

void servoMotorConfig()
{
  // servo motor signal pin
  servo.attach(9);
}

#endif