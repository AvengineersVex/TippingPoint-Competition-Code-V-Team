#include "vex.h"
#include "control.h"
using namespace vex;
extern controller Controller1;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Conveyor;
extern motor TowerIntakeFront;



int twoJoystickDrive() {
  RightDrive.spin(fwd);
  LeftDrive.spin(fwd);
  while (true) {
    while (abs(Controller1.Axis1.value()) > 20) { // rotating
      RightDrive.setVelocity(-Controller1.Axis1.value() + 27, velocityUnits::pct);
      LeftDrive.setVelocity(Controller1.Axis1.value() + 27, velocityUnits::pct);
    }
  RightDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct); // going forward and back
  LeftDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct);
  wait(20, msec);
  }
  return 0;
}

int mainDrive() { // one joystick
  RightDrive.setVelocity(0, velocityUnits::pct);
  LeftDrive.setVelocity(0, velocityUnits::pct);
  Conveyor.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(fwd);
  LeftDrive.spin(fwd);
  // set up various motors
  setupConveyorMotor(Controller1.ButtonR1);
  setupLatchMotors(Controller1.ButtonLeft, Controller1.ButtonRight);
  setupTowerMotors();
  while (true) { // loop forever
    if (abs(Controller1.Axis3.value()) < 20) { // rotating on the spot
      RightDrive.setVelocity(-Controller1.Axis4.position(), velocityUnits::pct); // right motor is negated because it needs to go in the opposite direction to turn on the spot
      LeftDrive.setVelocity(Controller1.Axis4.position(), velocityUnits::pct);
    }
    else { // moving forward or back
      RightDrive.setVelocity(Controller1.Axis3.position(), velocityUnits::pct); // left and right motor go in the same direction
      LeftDrive.setVelocity(Controller1.Axis3.position(), velocityUnits::pct); 
    }

    updateTowerMotors(Controller1.Axis2);
    wait(20, msec); // some delay to prevent wasted resources
  }
  return 0;
}

// autonomous drive controls:

double inchesToDegrees(double inches) {
  return
   (inches / // for the ratio thing
    (4 * 3.14)) * // cirmcuerfence
    360; // convert to degres
}

void goForward() {
  RightDrive.setVelocity(100, velocityUnits::pct);
  LeftDrive.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(directionType::fwd);
  LeftDrive.spin(directionType::rev);
}

void goBackward() {
  RightDrive.setVelocity(100, velocityUnits::pct);
  LeftDrive.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(directionType::rev);
  LeftDrive.spin(directionType::fwd);
}

void turnLeft() {
  RightDrive.setVelocity(100, velocityUnits::pct);
  LeftDrive.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(directionType::fwd);
  LeftDrive.spin(directionType::fwd);
}

void turnRight() {
  RightDrive.setVelocity(100, velocityUnits::pct);
  LeftDrive.setVelocity(100, velocityUnits::pct);
  RightDrive.spin(directionType::rev);
  LeftDrive.spin(directionType::rev);
}

void stop() {
  LeftDrive.stop();
  RightDrive.stop();
}

void forwardInches(double inches) {
  LeftDrive.startRotateTo(inchesToDegrees(inches), rotationUnits::deg);
  RightDrive.startRotateTo(inchesToDegrees(inches), rotationUnits::deg);
}

void backwardInches(double inches) {
  LeftDrive.startRotateTo(-1 * inchesToDegrees(inches), rotationUnits::deg);
  RightDrive.startRotateTo(-1 * inchesToDegrees(inches), rotationUnits::deg);
} 