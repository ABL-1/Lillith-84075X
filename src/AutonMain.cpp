#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "AutonMain.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "main.h"


void AutonLogic(){
    QualificationAutonLogic();
    EliminationAutonLogic();
    SkillsAuton();
}

int setpath = 0; 

bool singleRun = true;


  int x = 0;
  int y = 0;


void setcode(int val){
  setpath = val;

  pros::c::screen_erase();
}

void selection() {                                     //selection code for autonomous

  pros::screen_touch_status_s_t status;

  status = pros::c::screen_touch_status();

  int x = 0;
  int y = 0;

  x = status.x;
  y = status.y;

  if(x>=0 && x<=160 && y>=0 && y<=240){setcode(1);}
  if(x>=160 && x<=320 && y>=0 && y<=240){setcode(2);}
  if(x>=320 && x<=480 && y>=0 && y<=240){setcode(3);}
  
  if(setpath == 1 && singleRun == true){
    singleRun = false;
    pros::c::screen_erase();
    pros::c::delay(5);
    pros::c::screen_set_pen(pros::c::COLOR_RED);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    pros::c::screen_set_pen(pros::c::COLOR_BLUE);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    pros::c::screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    pros::c::screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Qualification");
    pros::c::screen_touch_callback(QualificationSelected, TOUCH_PRESSED);
    // brain.Screen.drawRectangle(0, 0, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
    // brain.Screen.pressed(QualificationSelected);
    // brain.Screen.printAt(5, 120, "Qualification");
    // Controller1.Screen.print("Qualification           ");
  }

  if(setpath == 2 && singleRun == true){
    singleRun = false;
    pros::c::screen_erase();
    pros::c::delay(5);
    pros::c::screen_set_pen(pros::c::COLOR_RED);
    pros::c::screen_fill_rect(0, 0, 180, 120);
    pros::c::screen_fill_rect(0, 120, 120, 180);
    pros::c::screen_set_pen(pros::c::COLOR_BLUE);
    pros::c::screen_fill_rect(180, 0, 360, 120);
    pros::c::screen_fill_rect(180, 120, 360, 240);
    pros::c::screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(320, 0, 480, 240);
    pros::c::screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 60, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 60, "Right Side");
    pros::c::screen_print_at(TEXT_SMALL, 185, 180, "Left Side");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit");
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Elimination");
    pros::c::screen_touch_callback(EliminationSelected, TOUCH_PRESSED);
    // brain.Screen.drawRectangle(0, 0, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 60, "Left Side");
    // brain.Screen.drawRectangle(0, 120, 180, 120, pros::Color::red);
    // brain.Screen.printAt(5, 180, "Right Side");
    // brain.Screen.drawRectangle(180, 0, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 60, "Right Side");
    // brain.Screen.drawRectangle(180, 120, 180, 120, pros::Color::blue);
    // brain.Screen.printAt(185, 180, "Left Side");
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.printAt(365, 120, "Exit");
    // brain.Screen.pressed(EliminationSelected);
    // brain.Screen.printAt(5, 120, "Elimination");
    // Controller1.Screen.print("Elimination             ");
  }

  if(setpath == 3 && singleRun == true){
    singleRun = false;
    pros::c::screen_erase();
    pros::c::delay(5);
    pros::c::screen_set_pen(pros::c::COLOR_RED);
    pros::c::screen_fill_circle(180, 120, 120);
    pros::c::screen_set_pen(pros::c::COLOR_ORANGE);
    pros::c::screen_fill_rect(360, 0, 480, 240);
    pros::c::screen_set_pen(pros::c::COLOR_BLACK);
    pros::c::screen_print_at(TEXT_SMALL, 5, 120, "Skills");
    pros::c::screen_print_at(TEXT_SMALL, 365, 120, "Exit"); 
    pros::c::screen_touch_callback(SkillsSelected, TOUCH_PRESSED);
    // brain.Screen.drawCircle(180, 120, 120, pros::Color::red);
    // brain.Screen.drawRectangle(360, 0, 120, 240, pros::Color::orange);
    // brain.Screen.pressed(SkillsSelected);
    // brain.Screen.printAt(5, 120, "Skills");
    // brain.Screen.printAt(365, 120, "Exit");
    // Controller1.Screen.print("Skills                ");
  }
}

void startScreen(){
  pros::c::delay(3);
  singleRun = true;
  setpath = 0;
  pros::c::screen_erase();
  pros::c::delay(3);
  pros::c::screen_set_pen(pros::c::COLOR_GREEN);
  pros::c::screen_fill_rect(0,0,160,240);
  pros::c::screen_fill_rect(160,0,320,240);
  pros::c::screen_fill_rect(320,0,480,240);
  pros::c::screen_set_pen(pros::c::COLOR_BLACK);
  pros::c::screen_print_at(TEXT_SMALL, 5, 120, "Qualification");
  pros::c::screen_print_at(TEXT_SMALL, 165, 120, "Elimination");
  pros::c::screen_print_at(TEXT_SMALL, 325, 120, "Skills");
  pros::c::screen_touch_callback(selection, TOUCH_PRESSED);
  // brain.Screen.drawRectangle(0, 0, 160, 240, pros::Color::green);
  // brain.Screen.printAt(5, 120, "Qualification");
  // brain.Screen.drawRectangle(160, 0, 160, 240, pros::Color::green);
  // brain.Screen.printAt(165, 120, "Elimination");
  // brain.Screen.drawRectangle(320, 0, 160, 240, pros::Color::green);
  // brain.Screen.printAt(325, 120, "Skills");
  // brain.Screen.pressed(selection);
  return;                                              // Remove this if it accidentially kills the UI
}