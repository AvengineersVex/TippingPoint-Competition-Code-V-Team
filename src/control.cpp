#include "vex.h"
using namespace vex;
extern controller Controller1;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Conveyor;
extern motor TowerLift;
extern motor TowerIntakeFront;
extern motor TowerIntakeBack;
extern motor Platform;


bool frontLatchClosed;
bool backLatchClosed;

void frontLatch() {
  TowerIntakeFront.spin(fwd);
  if (TowerIntakeFront.isDone()) {
    if (frontLatchClosed) {
      TowerIntakeFront.spinFor(directionType::fwd, 400, timeUnits::msec);
    } else {
      TowerIntakeFront.spinFor(directionType::rev, 400, timeUnits::msec);
    }
    frontLatchClosed = ! frontLatchClosed;
  }
}

void setupLatchMotors(controller::button Button) {
  frontLatchClosed = true;
  TowerIntakeFront.setVelocity(30, velocityUnits::pct);
  TowerIntakeFront.stop();
  Button.pressed(frontLatch);
}


bool platformDown;

void platform() {
  if (platformDown) {
    Platform.spin(directionType::fwd);
    Platform.setVelocity(100, pct);
    Platform.rotateTo(225, rotationUnits::deg);
    Platform.setVelocity(0, pct);
  } else {
    Platform.spin(directionType::rev);
    Platform.setVelocity(100, pct);
    Platform.rotateTo(225, rotationUnits::deg);
    Platform.setVelocity(0, pct);
  }
  platformDown = ! platformDown;
}

void setupPlatform(controller::button Button) {
  platformDown = false;
  Platform.stop();
  Button.pressed(platform);
}