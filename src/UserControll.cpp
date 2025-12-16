#include "main.h"
#include "Devices.h"
#include "AutonFunction.h"

// using namespace vex;
// using signature = vision::signature;
// using code = vision::code;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
void rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // // calculate the drivetrain motor velocities from the controller joystick axies
      // // left = Axis3
      // // right = Axis2
      // int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      // int drivetrainRightSideSpeed = Controller1.Axis2.position();
      
      // // check if the value is inside of the deadband range
      // if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
      //   // check if the left motor has already been stopped
      //   if (DrivetrainLNeedsToBeStopped_Controller1) {
      //     // stop the left drive motor
      //     LeftDriveSmart.stop();
      //     // tell the code that the left motor has been stopped
      //     DrivetrainLNeedsToBeStopped_Controller1 = false;
      //   }
      // } else {
      //   // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
      //   DrivetrainLNeedsToBeStopped_Controller1 = true;
      // }
      // // check if the value is inside of the deadband range
      // if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
      //   // check if the right motor has already been stopped
      //   if (DrivetrainRNeedsToBeStopped_Controller1) {
      //     // stop the right drive motor
      //     RightDriveSmart.stop();
      //     // tell the code that the right motor has been stopped
      //     DrivetrainRNeedsToBeStopped_Controller1 = false;
      //   }
      // } else {
      //   // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
      //   DrivetrainRNeedsToBeStopped_Controller1 = true;
      // }
      
      // // only tell the left drive motor to spin if the values are not in the deadband range
      // if (DrivetrainLNeedsToBeStopped_Controller1) {
      //   LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed);
      //   LeftDriveSmart.spin(forward);                                                           
      // }
      // // only tell the right drive motor to spin if the values are not in the deadband range
      // if (DrivetrainRNeedsToBeStopped_Controller1) {
      //   RightDriveSmart.setVelocity(drivetrainRightSideSpeed);
      //   RightDriveSmart.spin(forward);
      // }
              // Read the joystick values
      int left_joystick_value = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
      int right_joystick_value = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // Optional: Implement a deadzone check to prevent the robot from drifting
      const int DEADZONE = 5; 

      if (std::abs(left_joystick_value) > DEADZONE) {
          LeftDriveSmart.move_velocity(left_joystick_value);
       } else {
          LeftDriveSmart.move_velocity(0); // Stop motors if joystick is near center
      }

      if (std::abs(right_joystick_value) > DEADZONE) {
          RightDriveSmart.move_velocity(right_joystick_value);
      } else {
          RightDriveSmart.move_velocity(0); // Stop motors if joystick is near center
      }


      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // Scores the blocks on the low goals
        Intake1.move_velocity(100);
        Intake2.move_velocity(-100);
        Intake3.move_velocity(100);
      }


      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ // Scores the blocks on the medium goals
        Intake3.move_velocity(-100);
        Intake1.move_velocity(-100);
        Intake2.move_velocity(-100);
      }

      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ // Scores the blocks on the high goals
        Intake3.move_velocity(100);
        Intake1.move_velocity(-100);
        Intake2.move_velocity(-100);
      }

      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){ // Store the blocks
        Intake1.move_velocity(100);
        Intake2.move_velocity(-100);
      }


      if (!Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        Intake1.move_velocity(0);
        Intake2.move_velocity(0);
        Intake3.move_velocity(0);
      }

      if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){ // Lowers the loader reloader
        // scooper.write(true);
        scooper.set_value(true);
        // pros::c::adi_digital_write(scooper, true);
      }

      if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){ // Raises the Loader reloader
        // scooper.write(false);
        scooper.set_value(false);
        // pros::c::adi_digital_write(scooper, false);
      }

      if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_A)){ // Extend the parking mech
        // parker.write(true);
        parker.set_value(true);
        // pros::c::adi_digital_write(parker, true);
      }

      if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_X)){ // Retract the parking mech
        // parker.write(false);
        parker.set_value(false);
        // pros::c::adi_digital_write(parker, false);
      }

      if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        // pummeler.write(true); 
        pummeler.set_value(true);
        // pros::c::adi_digital_write(pummeler, true);
      }

      if(!Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        // pummeler.write(false);
        pummeler.set_value(false);
        // pros::c::adi_digital_write(pummeler, false);
      }

    // wait before repeating the process
    pros::c::delay(20);
  }

}
}
