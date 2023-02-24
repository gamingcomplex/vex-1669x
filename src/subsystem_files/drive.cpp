#include "main.h"

// Helper Functions
void set_drive_tank(int left, int right) {
    drive_left_front = left;
    drive_left_back = left;
    drive_right_front = right;
    drive_right_back = right;
}

void set_drive_arcade(int rotate, int drive) {
    int maximum = std::max(abs(drive), abs(rotate));
    int total = drive + rotate;
    int difference = drive - rotate;

    if (drive >= 0) // Forward
    {
        if (rotate >= 0) // NE direction
        {
            drive_left_front = maximum;
            drive_left_back = maximum;
            drive_right_front = difference;
            drive_right_back = difference;
        } else // NW direction
        {
            drive_left_front = total;
            drive_left_back = total;
            drive_right_front = maximum;
            drive_right_back = maximum;
        }
    } else // Reverse
    {
        if (drive >= 0) // SE direction
        {
            drive_left_front = total;
            drive_left_back = total;
            drive_right_front = -maximum;
            drive_right_back = -maximum;
        } else // SW direction
        {
            drive_left_front = -maximum;
            drive_left_back = -maximum;
            drive_right_front = difference;
            drive_right_back = difference;
        }
    }

}

// Driver Control Functions
void set_drive_motors() {
    int left_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right_joystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // Deadzone
    if (abs(left_joystick) < 5) {
        left_joystick = 0;
    }
    if (abs(right_joystick) < 5) {
        right_joystick = 0;
    }
    
    // Tank Drive
    // set_drive_tank(left_joystick, right_joystick);

    // Arcade Drive
    set_drive_arcade(left_joystick, right_joystick);
}