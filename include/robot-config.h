using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDrive;
extern motor RightDrive;
extern motor RingIntake;
extern motor Conveyor;
extern motor TowerLift;
extern motor TowerIntakeFront;
extern motor TowerIntakeBack;

extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
