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
  // RightDrive.rotateFor(directionType::fwd, 3.8197186342, rotationUnits::rev);
  // LeftDrive.rotateFor(directionType::fwd, 3.8197186342, rotationUnits::rev);
  backwardInches(48);
  frontLatch();
  turnDegrees(180);
}

void leftAuton() {
}