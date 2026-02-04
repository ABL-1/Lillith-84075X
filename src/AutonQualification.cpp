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
    
      pros::c::delay(50);

      chassis.setPose(0, 0, 0);

      scooper.set_value(0);
      scooper_state = false;

      unloader.set_value(1);
      unloader_state = true;

      pros::c::delay(50);

      chassis.moveToPoint(0, 7, 2000);

      Devour();
      
      chassis.moveToPoint(19, 31, 2000, {.maxSpeed = 32});  //voltage units from 0 to 127  this collects the three on the field

      pros::c::delay(2500);

      chassis.turnToHeading(-45, 1000);

      chassis.moveToPoint(3, 30.5, 2000);

      chassis.turnToHeading(-45, 1000);

      ScoreBottom();

      pros::c::delay(3000);

      Halt_Intake();

      chassis.moveToPoint(39, 2, 3200, {.forwards = false}); //move to loader

      pros::c::delay(1000);

      chassis.turnToHeading(180, 1000);

      scooper.set_value(1);
      scooper_state = true;

      Devour();

      chassis.moveToPoint(39, -14, 1000); //hits the loader

      pros::c::delay(1400);

      Halt_Intake();

      pros::c::delay(15);

      chassis.moveToPoint(41, 15, 2000, {.forwards = false});  

      chassis.turnToHeading(180, 1000);

      pros::c::delay(800);

      ScoreTop();

      pros::c::delay(3000);

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(Path_selected == 1 || Path_selected == 3){
      //This is where the code for the Left side auton red and blue go

      pros::c::delay(50);

      chassis.setPose(0, 0, 0);

      pros::c::delay(50);

      scooper.set_value(0);
      scooper_state = false;

      unloader.set_value(1);
      unloader_state = true;

      chassis.moveToPoint(0, 7, 2000);

      Devour();
      
      chassis.moveToPoint(-23, 35, 3000, {.maxSpeed = 28});  //voltage units from 0 to 127  this collects the three on the field

      pros::c::delay(3000);

      // chassis.turnToHeading(-135, 1000);

      // chassis.moveToPoint(-3, 30.5, 2000, {.forwards = false});

      // chassis.turnToHeading(-135, 1000);

      // ScoreMiddle();

      // pros::c::delay(2000);

      Halt_Intake();

      chassis.moveToPoint(-41, 2, 3200, {.forwards = false}); //move to loader

      pros::c::delay(1000);

      chassis.turnToHeading(180, 1000);

      scooper.set_value(1);
      scooper_state = true;

      Devour();

      chassis.moveToPoint(-41, -14, 1000); //hits the loader

      pros::c::delay(1800);

      Halt_Intake();

      pros::c::delay(15);

      chassis.moveToPoint(-43, 16, 2000, {.forwards = false});  

      chassis.moveToPoint(-43, 18, 1000, {.forwards = false});

      pros::c::delay(800);

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