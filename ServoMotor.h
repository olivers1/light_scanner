#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>
#include <ArxSmartPtr.h>

class ServoMotor
{
  public:
    ServoMotor(unsigned int pin, int posMin, int posMax);
    void servoInit();
    void servoMove(int posNew);
    int getServoPos();
    //~ServoMotor();
  private:
    int posMin_;
    int posMax_;
    int posLatest_;
    unsigned int pin_;
    std::shared_ptr<Servo> servo_ptr_;  // smart pointer to Servo object
};

#endif