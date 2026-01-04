#include "main.h"
#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "api.h"

pros::Motor leftfrontmotor (-6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor leftmiddlemotor (5, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor leftbackmotor (4, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);   

pros::Motor rightfrontmotor (3, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor rigtmiddlemotor (-2, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees); 
pros::Motor rightbackmotor (-1, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Imu inertialsensor (12);

pros::MotorGroup LeftDriveSmart (std::vector<int8_t>{-6, 5, 4});//({leftfrontmotor, leftmiddlemotor, leftbackmotor});
pros::MotorGroup RightDriveSmart (std::vector<int8_t>{3, -2, -1});//({rightfrontmotor, rigtmiddlemotor, rightbackmotor});

pros::Motor Intake1 (20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor Intake2 (-19, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor Intake3 (-18, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);

pros::Controller Controller1 (CONTROLLER_MASTER);

pros::adi::DigitalOut scooper ('G');
pros::adi::DigitalOut parker ('H');
pros::adi::DigitalOut pummeler ('F');
