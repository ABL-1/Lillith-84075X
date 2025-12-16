#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "AutonMain.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "PID.h"
#include "main.h"



bool singleQualification = true;

int aoutonpath = 0;


void setauton(int val){   //shows what was selected for autonomous
  aoutonpath = val;

  if (aoutonpath == 0){aoutonpath = 2;}

  if (aoutonpath == 1 && singleQualification == true){
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
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Qualification");
    // brain.Screen.clearScreen();
    // wait(5, msec);
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

  if (aoutonpath == 2 && singleQualification == true){
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
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Qualification");
    // brain.Screen.clearScreen();
    // wait(5, msec);
    //  brain.Screen.drawRectangle(0, 0, 180, 120);
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

  if (aoutonpath == 3 && singleQualification == true){
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
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Qualification");
    // brain.Screen.clearScreen();
    // wait(5, msec);
    //  brain.Screen.drawRectangle(0, 0, 180, 120);
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

  if (aoutonpath == 4 && singleQualification == true){
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
    pros::c::screen_print_at(TEXT_SMALL, 5, 180, "Qualification");
    // brain.Screen.clearScreen();
    // wait(5, msec);
    //  brain.Screen.drawRectangle(0, 0, 180, 120);
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

  if (aoutonpath == 5 && singleQualification == true){
    singleQualification = false;
    aoutonpath = 0;
    pros::c::delay(1);
    startScreen();
    return;
  }
}

void QualificationSelected() {                                     //selection code for autonomous
  // int x = status.x;
  // int y = status.y;

  if(x>=0 && x<=180 && y>=0 && y<=120){setauton(1);}
  if(x>=180 && x<=360 && y>=0 && y<=120){setauton(2);}
  if(x>=0 && x<=180 && y>=120 && y<=240){setauton(3);}
  if(x>=180 && x<=360 && y>=120 && y<=240){setauton(4);}
  if(x>=360 && x<=480 && y>=0 && y<=240){setauton(5);}
  
}


void QualificationAutonLogic() {                // Different aoutonomous paths, this is where the actual auton code goes.
    pros::c::screen_touch_callback(QualificationSelected, TOUCH_PRESSED);
  
  if (aoutonpath == 2 || aoutonpath == 3){
      //this is the code for the right side autonomous blue alliance and right side auton red alliance
      // PIDcontroll = true;
      
      // Devour();
      // wait(.75, sec);

      // Drive(50);
      // wait(1.75, sec);
      // Turn(35);
      // wait(2.15, sec);
      // Drive(27);
      // wait(2, sec);
      // Turn(-70);
      // wait(1.5, sec);
      // Drive(15);
      // wait(1, sec);
      // ScoreBottom();
        
      // PIDcontroll = false; 
      pros::c::screen_erase();
      pros::c::screen_print(TEXT_SMALL, 1, "Right Auton Ran");
      pros::c::delay(5000);
  }

    if (aoutonpath == 1 || aoutonpath == 4){
      //this is the code for the left side autonomous blue alliance and lest side auton blue alliance 
      // PIDcontroll = true;
      
      // Devour();
      // wait(.75, sec);

      // Drive(50);
      // wait(1.75, sec);
      // Turn(-35);
      // wait(1.5, sec);
      // Drive(27);
      // wait(2, sec);
      // Turn(90);
      // wait(1.5, sec);
      // Drive(22);
      // wait(1, sec);
      // ScoreMiddle();
      
      // PIDcontroll = false; 
      pros::c::screen_erase();
      pros::c::screen_print(TEXT_SMALL, 1, "Left Auton Ran");
      pros::c::delay(5000);

    }


    if (aoutonpath == 0){
      return;
    }

}