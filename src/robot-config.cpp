#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
motor LeftDrive = motor(PORT1, ratio18_1, false);
motor RightDrive = motor(PORT2, ratio18_1, true);
motor Conveyor = motor(PORT5, ratio6_1, false);
motor TowerIntakeFront = motor(PORT6, ratio18_1, false);
motor RingIntakeRight = motor(PORT8, ratio18_1, true);
motor RingIntakeLeft = motor(PORT9, ratio18_1, false);
motor Platform = motor(PORT10, ratio36_1, false);

controller Controller1 = controller(primary);


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}