#include "main.h"

// Roller and Intake Initialize
bool RI_on = false;

// Driver Control Functions
void set_RI_motors() {
    
    // Intake Toggle - only if R1 is not held
    if ((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == true) && (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == false)) RI_on = !RI_on;

    if (RI_on) { 
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            roller_intake.move_velocity(-600); // If intake is on and L2 is held, outtake
        } else {
            roller_intake.move_velocity(600); // If intake is on and L2 is not held, intake
        }
    } else {
        roller_intake.move_velocity(0);
    }

    // Roller Hold - only if RI_on = false
    if (RI_on = false) {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            roller_intake.move_velocity(600);
        } else {
            roller_intake.move_velocity(0);
        }
    }
}
