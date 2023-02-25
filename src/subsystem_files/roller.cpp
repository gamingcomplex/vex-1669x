#include "main.h"

// Roller Initialize
void roller_initialize() {
    roller_on = false;
}

// Helper Functions
void set_roller(int power) {
    roller = power;
}

// Driver Control Functions
void set_roller_motors() {
    bool l1_press = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1);

    if (l1_press = true) {
        if (roller_on = false) {
            set_roller(127);
            roller_on = true;
        } else {
            set_roller(0);
            roller_on = false;
        }
    }
}