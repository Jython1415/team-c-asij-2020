#include "vex.h"
#include "motors.h"

using namespace vex;

// drive selection
bool chassis_tank_drive = true;

// speed multiplier
double chassis_speed_multiplier = 0.8;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  while (true)
  {
    // speed multiplier control
    chassis_speed_multiplier = ctlr1.ButtonUp.pressing() ? 0.8 : ctlr1.ButtonDown.pressing() ? 0.4 : 1.0;

    // chassis control
    if (chassis_tank_drive)
    {
      // basic tank drive
      chassisL_set(ctlr1.Axis3.value() * chassis_speed_multiplier);
      chassisR_set(ctlr1.Axis2.value() * chassis_speed_multiplier);
    }
    else
    {
      // basic arcade control
      int axis2 = ctlr1.Axis2.value();
      int axis1 = ctlr1.Axis1.value();
      chassisL_set((axis2 + axis1) * chassis_speed_multiplier);
      chassisR_set((axis2 - axis1) * chassis_speed_multiplier);
    }
    // intake control
    if (ctlr1.ButtonL1.pressing())
    {
      intake_set(100);
    }
    else if (ctlr1.ButtonL2.pressing())
    {
      intake_set(-100);
    }
    else
    {
      intake_set(0);
    }

    // roller control
    if (ctlr1.ButtonR1.pressing())
    {
      roller_set(100);
    }
    else if (ctlr1.ButtonR2.pressing())
    {
      roller_set(-100);
    }
    else
    {
      roller_set(0);
    }

    task::sleep(20);
  }
}
