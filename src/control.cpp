#include "vex.h"
#include <iostream>
using namespace vex;
extern controller Controller1;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Conveyor;
extern motor TowerLift;
extern motor TowerIntakeFront;
extern motor TowerIntakeBack;


void conveyor() {
  if (Conveyor.isSpinning()) {
    Conveyor.stop();
  } else {
    Conveyor.spin(fwd);
  }
}

void setupConveyorMotor(controller::button Button) {
  Conveyor.stop();
  Button.pressed(conveyor);
}

bool frontLatchClosed = false;
bool backLatchClosed = false;

void frontLatch() {
  if (TowerIntakeFront.isSpinning()) {
    return;
  }

  if (frontLatchClosed) {
    TowerIntakeFront.spinFor(directionType::fwd, 100, timeUnits::msec);
  } else {
    TowerIntakeFront.spinFor(directionType::rev, 100, timeUnits::msec);
  }
  frontLatchClosed = ! frontLatchClosed;
}

void backLatch() {
  if (TowerIntakeBack.isSpinning()) {
    return;
  }

  if (backLatchClosed) {
    TowerIntakeBack.spinFor(directionType::fwd, 100, timeUnits::msec);
  } else {
    TowerIntakeBack.spinFor(directionType::rev, 100, timeUnits::msec);
  }

  backLatchClosed = ! backLatchClosed;
}

void setupLatchMotors(controller::button FrontButton, controller::button BackButton) {
  TowerIntakeFront.setVelocity(200, velocityUnits::pct);
  TowerIntakeBack.setVelocity(200, velocityUnits::pct);
  TowerIntakeFront.stop();
  TowerIntakeBack.stop();
  FrontButton.pressed(frontLatch);
  BackButton.pressed(backLatch);
}

double minArmRotation = 0;
double maxArmRotation = 60;



void setupTowerMotors() {
  TowerLift.rotateTo(minArmRotation, deg);
}

void updateTowerMotors(controller::axis Axis) {
  if (Axis.value() > 20) {
    TowerLift.spin(directionType::fwd);
  } else if (Axis.value() < 20) {
    TowerLift.spin(directionType::rev);
  }

  if (TowerLift.rotation(deg) > minArmRotation) {
    TowerLift.rotateTo(minArmRotation, deg);
  } else if (TowerLift.rotation(deg) > maxArmRotation) {
    TowerLift.rotateTo(maxArmRotation, deg);
  }
}
