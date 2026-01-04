#ifndef UI_H  // Include Guard starts
#define UI_H

void UI();
extern lv_obj_t * main_menu;
extern lv_obj_t * diag_menu;
extern lv_obj_t * motor_labels[9]; 

struct NamedMotor {
    pros::Motor* motor;
    const char* name;
};

// Global array for the UI to use
extern NamedMotor robot_motors[9];

void AutonLogic();

extern bool Elimination_selected;
extern bool Qualification_selected;
extern int Path_selected;

#endif // Include Guard ends