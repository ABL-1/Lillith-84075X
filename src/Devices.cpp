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

pros::Motor leftfrontmotor (6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor leftmiddlemotor (-5, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor leftbackmotor (-4, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);   

pros::Motor rightfrontmotor (-3, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor rigtmiddlemotor (2, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor rightbackmotor (1, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Imu inertialsensor (11);

pros::MotorGroup LeftDriveSmart({6, -5, -4}, pros::v5::MotorGears::blue);
pros::MotorGroup RightDriveSmart({-3, 2, 1}, pros::v5::MotorGears::blue);

pros::Motor Intake1 (20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor Intake2 (-19, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor Intake3 (-18, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);

pros::Controller Controller1 (CONTROLLER_MASTER);

pros::adi::DigitalOut scooper ('G');
pros::adi::DigitalOut parker ('H');
pros::adi::DigitalOut pummeler ('F');

// PID and LemLib Definitions

// Drivetrain settings
lemlib::Drivetrain drivetrain(&LeftDriveSmart, &RightDriveSmart, 12.5, lemlib::Omniwheel::NEW_325, 450, 2);

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
