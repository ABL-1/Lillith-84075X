#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "main.h"
#include "lemlib/api.hpp"


void SkillsAuton(){
  if(Elimination_selected == false && Qualification_selected == false){

    if(Path_selected == 5){
      //this is where the skills path goes

      Devour();
     
      chassis.setPose(0, 0, 0);

     
      chassis.moveToPoint(30, 0, 500);

      pros::c::delay(3000);
  
    }

    if(Path_selected < 5){
      return;
    }

  } else {
    return;
  }
}