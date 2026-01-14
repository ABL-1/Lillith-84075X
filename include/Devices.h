#include "lemlib/api.hpp"
#include "main.h" 
extern pros::Controller Controller1;
extern pros::Motor leftfrontmotor;
extern pros::Motor leftmiddlemotor;
extern pros::Motor rigtmiddlemotor;
extern pros::Motor rightfrontmotor;
extern pros::Motor rightbackmotor;
extern pros::Motor leftbackmotor;
extern pros::MotorGroup LeftDriveSmart;
extern pros::MotorGroup RightDriveSmart;
extern pros::Imu inertialsensor;
extern pros::Motor Intake1;
extern pros::Motor Intake2;
extern pros::Motor Intake3;
extern pros::adi::DigitalOut scooper;
extern pros::adi::DigitalOut parker; 
extern pros::adi::DigitalOut pummeler;

extern lemlib::Chassis chassis;