#include "Devices.h"
//#include "lemlib.api.hpp"
#include "main.h"


// void Drive(double driveDistance){  //driveDistance is in centimeters

//     LeftDriveSmart.resetPosition();
//     wait(5, msec);
//     RightDriveSmart.resetPosition();
//     wait(5, msec);

//     TurndesiredValue = 0;

//     double distancePerRevolution = 19.72; // this is in cm, and it is the distance that the 3.25 in omni wheels go in one rotation on our drivetrain setup

//     DrivedesiredValue = (driveDistance / distancePerRevolution) * 360; //This is in degrees

//     waitUntil(DriveComplete == true);

//     wait(5, msec);
// }

//  void Turn(double turnDegrees){

//     double TurnValue = turnDegrees;

//     LeftDriveSmart.resetPosition();
//     wait(5, msec);
//     RightDriveSmart.resetPosition();
//     wait(5, msec);

//     double CirclePercent = (TurnValue); //the 360 degrees cancel out

//     DrivedesiredValue = 0;

//     double driveDistance = (CirclePercent * 93); //drive circumfrence

//     double rotations = (driveDistance / 19.72); // this is in cm, and it is the distance that the 3.25 in omni wheels go in one rotation

//     TurndesiredValue = rotations;
    

//     waitUntil(TurnComplete == true);

//     wait(1, msec);
// }

// void Curve(double DriveDistance, double TurnValue){

//     LeftDriveSmart.resetPosition();
//     wait(1, msec);
//     RightDriveSmart.resetPosition();
//     wait(1, msec);

//     double distancePerRevolution = 21.944024311; // this is in cm, and it is the distance that the 2.75 in omni wheels go in one rotation

//     double CirclePercent = (TurnValue);

//     double driveDistance = (CirclePercent * 82.5); //drive circumfrence

//     double rotations = (driveDistance / distancePerRevolution) * 2; // this is in cm, and it is the distance that the 2.75 in omni wheels go in one rotation

//     TurndesiredValue = rotations;

//     DrivedesiredValue = (DriveDistance / distancePerRevolution) * 360; //This is in degrees

//     waitUntil(TurnComplete == true && DriveComplete == true);

// }

void Devour(){
    Intake1.move_voltage(12000);
    Intake2.move_voltage(-8000);
    // Intake1.spin(reverse);
    // Intake2.spin(forward);
}

void Halt_Intake(){
    Intake1.move_voltage(0);
    Intake2.move_voltage(0);
    Intake3.move_voltage(0);
}

void ScoreBottom(){
    Intake1.move_voltage(12000);
    Intake2.move_voltage(-8000);
    // Intake1.spin(forward);
    // Intake2.spin(reverse);
    Intake3.move_voltage(8000);
    // Intake3.spin(forward);
}

void ScoreMiddle(){
    Intake3.move_voltage(-8000);
    // Intake3.spin(reverse);
    Intake1.move_voltage(-12000);
    Intake2.move_voltage(-8000);
//     Intake1.spin(reverse);
//     Intake2.spin(reverse);
}

void ScoreTop(){
    Intake3.move_voltage(8000);
    // Intake3.spin(forward);
    Intake1.move_voltage(-12000);
    Intake2.move_voltage(-8000);
    // Intake1.spin(reverse);
    // Intake2.spin(reverse);
}