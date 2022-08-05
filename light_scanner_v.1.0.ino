#include "LightSensorConfig.h"
#include "ServoMotor.h"
#include "LightScanner.h"
#include "LightSampleHandler.h"
#include <ArxSmartPtr.h>

//ServoMotor servo(9, 0, 180);
std::shared_ptr<ServoMotor> test = std::make_shared<ServoMotor>(9, 0, 180);

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

  
  
  test->servoInit();
  Serial.println(test->getServoPos());
  delay(1000);
  test->servoMove(90);
  Serial.println(test->getServoPos());
  //servo.servoInit();
  //servo.servoInit(32);
  delay(2000);
  /*
  servo_ptr_ = std::make_shared<Servo>();  // class object initialization on the heap, pointer has address to object
  servo_ptr_->attach(pin);   // servo motor signal pin
  servo_ptr_->write(posMin_);  // reset servo motor angle to initial/starting position
  delay(500);   // wait number of ms for the servo to reach the position
  std::shared_ptr<Servo> servo_ptr_;  // smart pointer to Servo object
  */
}



