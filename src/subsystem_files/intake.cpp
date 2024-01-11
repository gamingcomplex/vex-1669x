#include "main.h"

// Roller and Intake Initialize
bool RI_on = false;

// Driver Control Functions
void set_intake_motors() {
    if (INTAKE_SWITCH) {
            roller_intake.move_velocity(600);
    } else {
        roller_intake.move_velocity(0);
    }
}
