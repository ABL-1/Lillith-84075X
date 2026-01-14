#include "main.h"
#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "lemlib/api.hpp"


void EliminationAutonLogic() {                // Different aoutonomous paths, this is where the actual auton code goes.
  if(Elimination_selected == true && Qualification_selected == false){

    if(Path_selected == 1 || Path_selected == 3){
      //This is where the code for the Right side auton red and blue go
    }

    if(Path_selected == 2 || Path_selected == 4){
      //This is where the code for the Left side auton red and blue go
    }

    if(Path_selected == 5){
      return;
    }
  } else {
    return;
  }
}