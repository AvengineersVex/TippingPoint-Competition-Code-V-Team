#include "vex.h"
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
  TowerIntakeFront.spin(fwd);
  if (TowerIntakeFront.isDone()) {
    if (frontLatchClosed) {
      TowerIntakeFront.spinFor(directionType::fwd, 500, timeUnits::msec);
    } else {
      TowerIntakeFront.spinFor(directionType::rev, 500, timeUnits::msec);
    }
    frontLatchClosed = ! frontLatchClosed;
  }
}

void backLatch() {
  TowerIntakeBack.spin(fwd);
  if (TowerIntakeBack.isDone()) {   
    if (backLatchClosed) {
      TowerIntakeBack.spinFor(directionType::fwd, 50, timeUnits::msec);
    } else {
      TowerIntakeBack.spinFor(directionType::rev, 50, timeUnits::msec);
    }

    backLatchClosed = ! backLatchClosed;
    }
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
double maxArmRotation = 155;



void setupTowerMotors() {
  TowerLift.setVelocity(30, pct);
  TowerLift.rotateTo(minArmRotation, deg);
  TowerLift.resetRotation();
}

void updateTowerMotors(controller::axis Axis) {
  if (Axis.position() > 20) {
    TowerLift.startRotateTo(maxArmRotation, deg);
  } else if (Axis.position() < -20) {
    TowerLift.startRotateTo(minArmRotation, deg);
  } else {
    TowerLift.stop();
  }
}
