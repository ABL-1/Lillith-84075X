#include "main.h"
#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "AutonMain.h"
#include "AutonFunction.h"
#include "AutonElimination.h"




bool singleElimination = true;

int EliminationPath = 0;

void EliminationAuton(int val){   //shows what was selected for autonomous
  EliminationPath = val;

  if (EliminationPath == 0){EliminationPath = 2;}

  if (EliminationPath == 1 && singleElimination == true){
    pros::c::screen_erase();
    pros::c::delay(5);
    screen_set_pen(pros::c::COLOR_RED);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Elimination");
    // pros::screen::set_pen(COLOR_RED);
    // pros::screen::fill_rect(5,5,240,200);
    // brain.Screen.drawRectangle(0, 0, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
  } 

  if (EliminationPath == 2 && singleElimination == true){
    pros::c::screen_erase();
    pros::c::delay(5);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    screen_set_pen(pros::c::COLOR_BLUE);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Elimination");
    // brain.Screen.drawRectangle(0, 0, 180, 120);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
  }  

  if (EliminationPath == 3 && singleElimination == true){
    pros::c::screen_erase();
    pros::c::delay(5);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    screen_set_pen(pros::c::COLOR_RED);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Elimination");
    // brain.Screen.drawRectangle(0, 0, 180, 120);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
  } 

  if (EliminationPath == 4 && singleElimination == true){
    pros::c::screen_erase();
    pros::c::delay(5);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    screen_set_pen(pros::c::COLOR_BLUE);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Elimination");
    // brain.Screen.drawRectangle(0, 0, 180, 120);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
  } 
  
  if (EliminationPath == 5 && singleElimination == true){
    singleElimination = false;
    EliminationPath = 0;
    pros::c::delay(1);
    startScreen();
    return;
  }
}

void EliminationSelected() {                                     //selection code for autonomous

  // int x = status.x;
  // int y = status.y;

  if(x>=0 && x<=180 && y>=0 && y<=120){EliminationAuton(1);}
  if(x>=180 && x<=360 && y>=0 && y<=120){EliminationAuton(2);}
  if(x>=0 && x<=180 && y>=120 && y<=240){EliminationAuton(3);}
  if(x>=180 && x<=360 && y>=120 && y<=240){EliminationAuton(4);}
  if(x>=360 && x<=480 && y>=0 && y<=240){EliminationAuton(5);}
  
}


void EliminationAutonLogic() {                // Different aoutonomous paths, this is where the actual auton code goes.
    // brain.Screen.pressed(EliminationSelected);
    pros::c::screen_touch_callback(EliminationSelected, TOUCH_PRESSED);
  
  if (EliminationPath == 2){
      //this is the code for the right side autonomous red alliance
      //also known as stake side
      
      
  }

    if (EliminationPath == 1){
      //this is the code for the left side autonomous blue alliance
      //also known as stake side

    }

  if (EliminationPath == 3){
      //this is the code for the right side autonomous blue alliance
      //also known as blue ring side

    }

    if (EliminationPath == 4){
      //this is the code for the left side autonomous red alliance
      //also known as red ring side
      
    }

    if (EliminationPath == 0){
        return;
    }

}



