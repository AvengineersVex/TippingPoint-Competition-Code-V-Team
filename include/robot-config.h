using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDrive;
extern motor RightDrive;
extern motor Conveyor;
extern motor TowerIntakeFront;
extern motor RingIntakeRight;
extern motor RingIntakeLeft;
extern motor Platform;

extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
