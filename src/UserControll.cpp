#include "main.h"
#include "Devices.h"
#include "AutonFunction.h"
#include "UI.h"


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

        ////////////////////////////////////////////////////////////////////
        //     Joystick controlls
        ////////////////////////////////////////////////////////////////////

              // Read the joystick values
      int left_joystick_value = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) / 127 * 12000;
      int right_joystick_value = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) / 127 * 12000;

        // Optional: Implement a deadzone check to prevent the robot from drifting
      const int DEADZONE = 5; 

      if (std::abs(left_joystick_value) > DEADZONE) {
          LeftDriveSmart.move_voltage(-1 * left_joystick_value);
       } else {
          LeftDriveSmart.move_voltage(0); // Stop motors if joystick is near center
      }

      if (std::abs(right_joystick_value) > DEADZONE) {
          RightDriveSmart.move_voltage(-1 * right_joystick_value);
      } else {
          RightDriveSmart.move_voltage(0); // Stop motors if joystick is near center
      }

      /////////////////////////////////////////////////////////////////////
      ///////////////////   UI   //////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////////

      static uint32_t last_ui_update = 0; 
      uint32_t now = pros::millis();

      if (now - last_ui_update > 500) {
        if (diag_menu != nullptr && !lv_obj_has_flag(diag_menu, LV_OBJ_FLAG_HIDDEN)) {
              for (int i = 0; i < 9; i++) {
                  char buf[64];
                  snprintf(buf, sizeof(buf), "%s\n%.0fC | %.0f RPM", 
                          robot_motors[i].name, 
                          robot_motors[i].motor->get_temperature(), 
                          robot_motors[i].motor->get_actual_velocity());
                  lv_label_set_text(motor_labels[i], buf);
              }
          }
        last_ui_update = now;
      }


        ///////////////////////////////////////////////////////////////////////////////////////////
        // Button Controlls
        //////////////////////////////////////////////////////////////////////////////////////


      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // Scores the blocks on the low goals
        Intake1.move_voltage(-12000);
        Intake2.move_voltage(8000);
        Intake3.move_voltage(8000);
      }


      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ // Scores the blocks on the medium goals
        Intake3.move_voltage(8000);
        Intake1.move_voltage(12000);
        Intake2.move_voltage(8000);
      }

      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ // Scores the blocks on the high goals
        Intake3.move_voltage(-8000);
        Intake1.move_voltage(12000);
        Intake2.move_voltage(8000);
      }

      if (Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){ // Store the blocks
        Intake1.move_voltage(12000);
        Intake2.move_voltage(-8000);
      }


      if (!Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        Intake1.move_voltage(0);
        Intake2.move_voltage(0);
        Intake3.move_voltage(0);
      }

      if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){ // Lowers the loader reloader
        // scooper.write(true);
        scooper.set_value(1);
        // pros::c::adi_digital_write(scooper, true);
      }

      if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){ // Raises the Loader reloader
        // scooper.write(false);
        scooper.set_value(0);
        // pros::c::adi_digital_write(scooper, false);
      }

      if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){ // Extend the parking mech
        // parker.write(true);
        parker.set_value(1);
        // pros::c::adi_digital_write(parker, true);
      }

      if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){ // Retract the parking mech
        // parker.write(false);
        parker.set_value(0);
        // pros::c::adi_digital_write(parker, false);
      }

      if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
        // pummeler.write(true); 
        pummeler.set_value(1);
        // pros::c::adi_digital_write(pummeler, true);
      }

      if(!Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        // pummeler.write(false);
        pummeler.set_value(0);
        // pros::c::adi_digital_write(pummeler, false);
      }



    // wait before repeating the process
    pros::c::delay(20);
  }

}
}
