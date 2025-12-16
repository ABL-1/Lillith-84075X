#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "AutonMain.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "PID.h"
#include "main.h"

int SkillsPath = 0;
bool singleSkills = true;

void SkAuton(int val){   //shows what was selected for autonomous
  SkillsPath = val;


  if (SkillsPath == 1 && singleSkills == true){
    pros::c::screen_erase();
    pros::c::delay(5);
    pros::c::screen_set_pen(pros::c::COLOR_GREEN);
    pros::c::screen_fill_circle(180, 120, 120);
    pros::c::screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(360, 0, 480, 240);
    pros::c::screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 120, "Skills");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    // brain.Screen.clearScreen();
    // wait(5, msec);
    // brain.Screen.drawCircle(180, 120, 120, pros::Color::green);
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(5, 120, "Skills");
    // brain.Screen.printAt(365, 120, "Exit");
    // Controller1.Screen.print("Skills                ");
  } 

  if (SkillsPath == 2 && singleSkills == true){
    singleSkills = false;
    SkillsPath = 0;
    pros::c::delay(1);
    startScreen();
    return;
  }

}

void SkillsSelected() {                                     //selection code for autonomous
  // int x = status.x;
  // int y = status.y;

  if(x>=0 && x<=360 && y>=0 && y<=240){SkAuton(1);}
  if(x>=360 && x <= 480 && y>=0 && y<=240){SkAuton(2);}
  
}

void SkillsAuton(){

    if (SkillsPath == 1){  
      // PIDcontroll = true;
      // Insert the code for the auton skills here
      
      
      // wait(1,sec);
      // parker.set(true);
      // brain.Screen.newLine();
      // brain.Screen.print("Drive 1 Ran");
      // wait(5, msec);

      // PIDcontroll = false;      
    }

    if (SkillsPath == 0){
        return;
    }
}