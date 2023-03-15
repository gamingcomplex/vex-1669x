#include "main.h"

// Motors
pros::Motor drive_left_1(13, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drive_left_2(15, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drive_left_3(16, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor_Group drive_left({drive_left_1, drive_left_2, drive_left_3});

pros::Motor drive_right_1(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drive_right_2(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drive_right_3(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor_Group drive_right({drive_right_1, drive_right_2, drive_right_3});

pros::Motor roller_intake(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// Limit Switch
pros::ADIDigitalIn ls('H');

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);