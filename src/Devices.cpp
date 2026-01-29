#include "main.h"
#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "api.h"
#include "lemlib/api.hpp"

pros::Motor leftfrontmotor (13, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor leftmiddlemotor (-14, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor leftbackmotor (-15, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);   

pros::Motor rightfrontmotor (-18, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor rigtmiddlemotor (17, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor rightbackmotor (16, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Imu inertialsensor (2);

pros::MotorGroup LeftDriveSmart({13, -14, -15}, pros::v5::MotorGears::blue);
pros::MotorGroup RightDriveSmart({-18, 17, 16}, pros::v5::MotorGears::blue);

pros::Motor Intake1 (10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor Intake2 (-9, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor Intake3 (-8, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);

pros::Controller Controller1 (CONTROLLER_MASTER);

pros::adi::DigitalOut scooper ('A');
pros::adi::DigitalOut gate ('B');
pros::adi::DigitalOut unloader ('c');

// PID and LemLib Definitions

// Drivetrain settings
lemlib::Drivetrain drivetrain(&LeftDriveSmart, &RightDriveSmart, 11, lemlib::Omniwheel::NEW_325, 450, 2);

// Lateral PID settings
lemlib::ControllerSettings lateral_controller(10, 0, 3, 3, 1, 100, 3, 500, 20);
                                             //kP, kI, kD
// Angular PID settings
lemlib::ControllerSettings angular_controller(1.6, 0, 10, 3, 1, 100, 3, 500, 0);
                                             //kP, kI, kD
// Sensors for odometry
lemlib::OdomSensors sensors(nullptr, nullptr, nullptr, nullptr, &inertialsensor);

// Create the chassis
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);
