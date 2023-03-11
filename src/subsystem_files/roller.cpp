#include "main.h"

// Roller Initialize
bool roller_on = false;

// Driver Control Functions
void set_roller_motors() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) roller_on = !roller_on;

    if(roller_on) {
        roller = 127;
    } else {
        roller = 0;
    }
}