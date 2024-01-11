#include "main.h"

// Helper Functions
void set_drive_tank(int left, int right) {
    drive_left = left;
    drive_right = right;
}

void set_drive_arcade(int power, int direction) {
    int maximum = std::max(abs(power), abs(direction));
    int total = power + direction;
    int difference = power - direction;
    // int difference = direction - power; // Reversed to fix joysticks

    if (power >= 0) // Forward
    {
        if (direction >= 0) // NE direction
        {
            drive_left = maximum;
            drive_right = difference;
        } else // NW direction
        {
            drive_left = total;
            drive_right = maximum;
        }
    } else // Reverse
    {
        if (direction >= 0) // SE direction
        {
            drive_left = total;
            drive_right = -maximum;
        } else // SW direction
        {
            drive_left = -maximum;
            drive_right = difference;
        }
    }

}

// Driver Control Functions
void set_drive_motors() {
    // Tank Drive Joysticks
    // int left_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    // int right_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // // Tank Drive Deadzone
    // if (abs(left_joystick) < 5) {
    //     left_joystick = 0;
    // }
    // if (abs(right_joystick) < 5) {
    //     right_joystick = 0;
    // }

    // Arcade Drive Joysticks
    int power_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int direction_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    // // Arcade Drive Deadzone
    if (abs(power_joystick) < 5) {
        power_joystick = 0;
    }
    if (abs(direction_joystick) < 5) {
        direction_joystick = 0;
    }
    
    // Tank Drive
    // set_drive_tank(left_joystick, right_joystick);

    // Arcade Drive
    set_drive_arcade(power_joystick, direction_joystick);
}