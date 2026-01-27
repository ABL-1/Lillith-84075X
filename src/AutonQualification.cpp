#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "main.h"
#include "lemlib/api.hpp"


void QualificationAutonLogic() {   

  if(Elimination_selected == false && Qualification_selected == true){

    if(Path_selected == 0 || Path_selected == 2){
      //This is where the code for the Right side auton red and blue go
    
      pros::c::delay(200);

      chassis.setPose(0, 0, 0);

      pros::c::delay(200);

      chassis.moveToPoint(0, 7, 2000);

      Devour();
      
      chassis.moveToPoint(23, 36, 2000, {.maxSpeed = 33});  //voltage units from 0 to 127

      pros::c::delay(2000);

      chassis.turnToHeading(-45, 1000);

      chassis.moveToPoint(3, 30.5, 2000);

      chassis.turnToHeading(-45, 1000);

      ScoreBottom();

      pros::c::delay(2000);

      Halt_Intake();

      chassis.moveToPoint(35, 0, 3200, {.forwards = false}); //move to loader

      chassis.turnToHeading(180, 1000);

      scooper.set_value(1);

      Devour();

      chassis.moveToPoint(37, -20, 1000); //hits the loader

      pros::c::delay(350);

      chassis.moveToPoint(37, -7, 2000, {.forwards = false});  // revert y value to zero when we swap to odometry

      chassis.turnToHeading(180, 1500);

      scooper.set_value(0);

      pros::c::delay(1000);

      chassis.moveToPoint(38, 13, 1500); //approaches the loader

      chassis.turnToHeading(15, 1500);

      ScoreTop();

      pros::c::delay(3000);

    }

    if(Path_selected == 1 || Path_selected == 3){
      //This is where the code for the Left side auton red and blue go

      pros::c::delay(200);

      chassis.setPose(0, 0, 0);

      pros::c::delay(200);

      chassis.moveToPoint(0, 5, 2000);

      chassis.turnToHeading(-45, 1000);

      Devour();
      
      chassis.moveToPoint(-18, 29, 2000, {.maxSpeed = 27});  //voltage units from 0 to 127

      pros::c::delay(2000);

      // chassis.turnToHeading(45, 1000);

      // chassis.moveToPoint(-5, 31, 1000);

      // chassis.turnToHeading(45, 1000);

      // ScoreMiddle();

      // pros::c::delay(2000);

      // Halt_Intake();

      chassis.moveToPoint(-38, 0, 3200, {.forwards = false}); //move to loader

      chassis.turnToHeading(180, 1000);

      scooper.set_value(1);

      // Devour();

      chassis.moveToPoint(-42, -20, 1000); //hits the loader

      pros::c::delay(200);

      chassis.moveToPoint(-42, -7, 2000, {.forwards = false});  // revert y value to zero when we swap to odometry

      chassis.turnToHeading(180, 1500);

      pros::c::delay(1000);

      scooper.set_value(0);

      chassis.moveToPoint(-42, 9, 1500); //approaches the loader

      ScoreTop();

      pros::c::delay(3000);

    }

    if(Path_selected == 5){
      pros::c::delay(60);
      Controller1.print(0, 14, "Fail", 0);
      pros::c::delay(2000);
      return;
    }
  } else {
    return;
  }
}