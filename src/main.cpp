/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Avengineers                                               */
/*    Created:      Tue Oct 05 2021                                           */
/*    Description:  Avengineers V Team Tipping Point Competition Code Main    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// LeftDrive            motor         1               
// RightDrive           motor         2               
// Conveyor             motor         5             
// TowerIntakeFront     motor         6             
// RingIntakeRight      motor         8             
// RingIntakeLeft       motor         9             
// Platform             motor         10
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "control.h"
#include "auton.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

void autonomous(void) {
  rightAuton();
}

void usercontrol(void) {
  while (1) {
    setupLatchMotors(Controller1.ButtonL1);
    setupPlatform(Controller1.ButtonR1);
    mainDrive();
    wait(20, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  // Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}