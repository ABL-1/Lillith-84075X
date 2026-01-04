#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "main.h"



void QualificationAutonLogic() {                

  if(Elimination_selected == false && Qualification_selected == true){

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