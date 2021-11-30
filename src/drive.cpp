#include "vex.h"

using namespace vex;
extern controller Controller1;
extern motor RightDrive;
extern motor LeftDrive;

int mainDrive() {
  RightDrive.spin(fwd);
  LeftDrive.spin(fwd);
  while (true) {
    while (abs(Controller1.Axis1.value()) > 20) {
      RightDrive.setVelocity(-Controller1.Axis1.value() + 27, velocityUnits::pct);
      LeftDrive.setVelocity(Controller1.Axis1.value() + 27, velocityUnits::pct);
    }
  RightDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct);
  LeftDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct);
  wait(20, msec);
  }
  return 0;
}

int oneJoystickDrive() {
  RightDrive.spin(fwd);
  LeftDrive.spin(fwd);
  while (true) {
    while (abs(Controller1.Axis3.value()) < 20) {
      RightDrive.setVelocity(-Controller1.Axis4.value() + 27, velocityUnits::pct);
      LeftDrive.setVelocity(Controller1.Axis4.value() + 27, velocityUnits::pct);
    }
    while (Controller1.Axis4.value() > 0) {
      RightDrive.setVelocity((Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
      LeftDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct);
    }
    while (Controller1.Axis4.value() < 0) {
      RightDrive.setVelocity(Controller1.Axis3.value(), velocityUnits::pct);
      LeftDrive.setVelocity((Controller1.Axis3.value() - Controller1.Axis4.value()), velocityUnits::pct);
    } 
    wait(20, msec);
  }
  return 0;
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

double inchesToDegrees(double inches) {
  return
   (inches / // for the ratio thing
    (4 * 3.14)) * // cirmcuerfence
    360; // convert to degres
}

void forwardInches(double inches) {
  LeftDrive.startRotateTo(inchesToDegrees(inches), rotationUnits::deg);
  RightDrive.startRotateTo(inchesToDegrees(inches), rotationUnits::deg);
}

void backwardInches(double inches) {
  LeftDrive.startRotateTo(-1 * inchesToDegrees(inches), rotationUnits::deg);
  RightDrive.startRotateTo(-1 * inchesToDegrees(inches), rotationUnits::deg);
}