#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller ctlr1;

// main bot
motor chassisLF  = motor(PORT1, true);
motor chassisLB  = motor(PORT9, false);
motor chassisRF = motor(PORT5, false);
motor chassisRB = motor(PORT8, true);

motor intakeL = motor(PORT20, false);
motor intakeR = motor(PORT7, true);

motor rollerT = motor(PORT11, false);
motor rollerB = motor(PORT16, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
