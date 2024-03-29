#include "vex.h"
#include "control.h"
#include "drive.h"
using namespace vex;
extern controller Controller1;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Conveyor;
extern motor TowerIntakeFront;
extern motor RingIntakeRight;
extern motor RingIntakeLeft;
extern motor Platform;

const double circum = 12.5663706144;

void rightAuton() {
  // RightDrive.rotateFor(directionType::fwd, ((double)48 / circum), rotationUnits::rev);
  // LeftDrive.rotateFor(directionType::fwd, ((double)48 / circum), rotationUnits::rev);
  
  RightDrive.setVelocity(100, percentUnits::pct);
  LeftDrive.setVelocity(100, percentUnits::pct);

  backwardInches(48);
  TowerIntakeFront.spinFor(directionType::rev, 400, timeUnits::msec);
  turnDegrees(180);
  forwardInches(48);
  frontLatch();
  turnDegrees(120);
  backwardInches(15);
  frontLatch();
  forwardInches(10);
  Conveyor.spin(directionType::fwd);
  while (true) {
    wait(200, msec);
  }
  // RightDrive.spin(fwd);
  // LeftDrive.spin(fwd);
  // RightDrive.startSpinFor(fwd, inchesToDegrees(48), deg);
  // LeftDrive.startSpinFor(fwd, inchesToDegrees(48), deg);
  // while (RightDrive.isSpinning() | LeftDrive.isSpinning()) {
  //   // pass
  // }
  // RightDrive.startSpinFor(directionType::rev, inchesToDegrees(48), deg);
  // LeftDrive.startSpinFor(directionType::rev, inchesToDegrees(48), deg);
  // while (RightDrive.isSpinning() | LeftDrive.isSpinning()) {
  //   // pass
  // }
  // return; 
}

void leftAuton() {
  RightDrive.setVelocity(100, percentUnits::pct);
  LeftDrive.setVelocity(100, percentUnits::pct);
  backwardInches(48);
  turnDegrees(45);
  backwardInches(8);
  frontLatch();
  forwardInches(30);
  turnDegrees(30);
  forwardInches(36);
  frontLatch();
  turnDegrees(90);
  backwardInches(24);
  frontLatch();
  Conveyor.spin(directionType::fwd);
  forwardInches(10);
}