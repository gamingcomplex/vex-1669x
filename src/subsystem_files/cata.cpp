#include "main.h"

// Driver Control Functions

void set_cata_motors() {
    if (!ls.get_value()) {
        cata.move_velocity(100); // Lower cata if limit switch unpressed
    } else {
        cata.move_velocity(0); // Halt motor if limit switch pressed
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        while (ls.get_value()) {
            cata.move_velocity(100); // Fire until limit switch unpressed
        }
    } 
}