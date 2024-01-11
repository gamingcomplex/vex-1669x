#define PI 3.14159265358979323846
#include "main.h"

void lower_cata() {
    pros::Task lower_cata{[=]  {
        pros::Mutex cata_mutex;
        cata_mutex.take(TIMEOUT_MAX);
        while (!ls.get_value()) {
            cata.move_velocity(100);
        }
        cata_mutex.give();
    }};
    pros::delay(10);
}

void move_inch (int inch) {
    drive_left.move_absolute(inch * (540/(13*PI)), 600);
    drive_right.move_absolute(inch * (540/(13*PI)), 600);
}