#include "Devices.h"
#include "UserControll.h"
#include "AutonSkills.h"
#include "AutonQualification.h"
#include "UI.h"
#include "AutonFunction.h"
#include "AutonElimination.h"
#include "main.h"
#include "liblvgl/lvgl.h"

void AutonLogic() {

  isAutonActive = true;

  if (Qualification_selected) {
    QualificationAutonLogic();
  } else if (Elimination_selected) {
    EliminationAutonLogic();
  } else {
    SkillsAuton();
  }

  isAutonActive = false;
}

NamedMotor robot_motors[9] = {
    {&leftfrontmotor, "Left Front Motor"}, {&rightfrontmotor, "Right Front Motor"}, {&Intake3, "Intake 3"},
    {&leftmiddlemotor, "Left Middle Motor"}, {&rigtmiddlemotor, "Right Middle Motor"}, {&Intake2, "Intake 2"},
    {&leftbackmotor, "Left Back Motor"},     {&rightbackmotor, "Right Back Motor"},     {&Intake1, "Intake 1"}
};

lv_obj_t* motor_labels[9];

lv_obj_t * main_menu;
lv_obj_t * diag_menu;
lv_obj_t * auton_first_menue;
lv_obj_t * qualification_elimination_menu;
lv_obj_t * skills_menu;


// variables to controll which auton is selected. 0 does nothing

bool Elimination_state = false;   //these variables are for use in this file to say which secreen is selected
bool Qualification_state = false;

int Path_selected = -1;
bool Elimination_selected = false; // these variables are what actually define the auton path.
bool Qualification_selected = false;

lv_obj_t * btn_Qualification;
lv_obj_t * btn_Elimination;
lv_obj_t * btn_Skills;

lv_obj_t * btn_right_blue;
lv_obj_t * btn_left_red;
lv_obj_t * btn_right_red;
lv_obj_t * btn_left_blue;

lv_obj_t * btn_skills_verify;

lv_obj_t* Elim_Qual_buttons[4];
lv_color_t original_colors[4];

int selected_state = 0; // 1 is qualification, 2 is elimination, 3 is skills.
int current_state = 0; 

lv_obj_t* status_labels[2];
lv_obj_t* status_dots[2];

static void auton_logic_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * clicked_btn = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_t * target_page = (lv_obj_t *)lv_event_get_user_data(e);

    if(code == LV_EVENT_CLICKED) {
        // Logic for setting variables
        if(clicked_btn == btn_Qualification) {
            current_state = 1;
            Elimination_state = false;
            Qualification_state = true;
        } else if(clicked_btn == btn_Elimination) {
            Elimination_state = true;
            Qualification_state = false;
            current_state = 2;
        } else if(clicked_btn == btn_Skills){
          Elimination_state = false;
          Qualification_state = false;
          current_state = 3;
        }
    if(Path_selected > -1){
      if(current_state != selected_state){
        for(int i = 0; i < 4; i++) {
          lv_obj_set_style_bg_color(Elim_Qual_buttons[i], lv_palette_main(LV_PALETTE_GREY), 0);
          lv_obj_set_style_bg_opa(Elim_Qual_buttons[i], LV_OPA_60, 0);
        }
      } 
        if (current_state == selected_state && Path_selected < 4) {
        lv_obj_set_style_bg_color(Elim_Qual_buttons[Path_selected], original_colors[Path_selected], 0);
        lv_obj_set_style_bg_opa(Elim_Qual_buttons[Path_selected], LV_OPA_COVER, 0);
        }
      
    }

        // Screen switching logic (Manual call to switcher or integrated here)
        if (target_page != nullptr) {
            lv_obj_add_flag(main_menu, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(diag_menu, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(auton_first_menue, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(qualification_elimination_menu, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(skills_menu, LV_OBJ_FLAG_HIDDEN);
            
            lv_obj_remove_flag(target_page, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

const char* path_names[4] = {
    "Right Blue", 
    "Left Red", 
    "Right Red", 
    "Left Blue"
};

void update_all_banners() {
    // Determine the Mode Name
    const char* mode = (selected_state == 1) ? "Qual" : 
                       (selected_state == 2) ? "Elim" : 
                       (selected_state == 3) ? "Skills" : "None";
    
    // Determine the Path Name based on index
    const char* p_name = (Path_selected >= 0 && Path_selected < 4) ? 
                          path_names[Path_selected] : "None";

    // Determine the Dot Color
    lv_color_t dot_color = (Path_selected >= 0) ? 
                            lv_palette_main(LV_PALETTE_GREEN) : 
                            lv_palette_main(LV_PALETTE_RED);

    for (int i = 0; i < 2; i++) {
        if (status_labels[i] != nullptr) {
            // Use %s for strings
            lv_label_set_text_fmt(status_labels[i], "Mode: %s | Path: %s", mode, p_name);
            lv_obj_set_style_bg_color(status_dots[i], dot_color, 0);
        }
    }
}


static void auton_path_cb(lv_event_t * e){
  lv_obj_t * clicked_btn = (lv_obj_t *)lv_event_get_target(e);


    for(int i = 0; i < 4; i++) {
        if(Elim_Qual_buttons[i] == clicked_btn) {
            // Highlight the selected button

            Path_selected = i;

            if(Elimination_state == true){
              Elimination_selected = true;
              Qualification_selected = false;
              selected_state = 2;
            } else if(Qualification_state == true){
              Elimination_selected = false;
              Qualification_selected = true;
              selected_state = 1;
            } else if(Elimination_state == false && Qualification_state == false){
              Elimination_selected = false;
              Qualification_selected = false;
              selected_state = 3;
            } 

            

            lv_obj_set_style_bg_color(Elim_Qual_buttons[i], original_colors[i], 0);
            lv_obj_set_style_bg_opa(Elim_Qual_buttons[i], LV_OPA_COVER, 0);


        } else {
            // Grey out the others
            lv_obj_set_style_bg_color(Elim_Qual_buttons[i], lv_palette_main(LV_PALETTE_GREY), 0);
            lv_obj_set_style_bg_opa(Elim_Qual_buttons[i], LV_OPA_60, 0); // Optional: make them semi-transparent
            lv_obj_set_style_bg_color(btn_skills_verify, lv_palette_main(LV_PALETTE_GREY), 0);
            lv_obj_set_style_bg_opa(btn_skills_verify, LV_OPA_60, 0);
        }
    }
    update_all_banners();
}

// Switches between Main Menu and Diagnostics
static void switch_page_cb(lv_event_t * e) {
    // 1. Retrieve the target page pointer
    lv_obj_t * target = (lv_obj_t *)lv_event_get_user_data(e);
    
    // 2. Safety check: If any pointer is NULL, stop to prevent DATA ABORT
    if (target == nullptr) {
        return; 
    }
    
    // 3. Hide all potential pages
    lv_obj_add_flag(main_menu, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(diag_menu, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(auton_first_menue, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(qualification_elimination_menu, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(skills_menu, LV_OBJ_FLAG_HIDDEN);
    
    // 4. Show the target (use remove_flag for v9)
    lv_obj_remove_flag(target, LV_OBJ_FLAG_HIDDEN);

    update_all_banners();
}

void add_border(lv_obj_t * obj) {
    lv_obj_set_style_border_width(obj, 3, 0);
    lv_obj_set_style_border_color(obj, lv_palette_main(LV_PALETTE_LAST), 0);
}

static void skills_cb(lv_event_t * e) {
  lv_obj_set_style_bg_color(btn_skills_verify, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_obj_set_style_bg_opa(btn_skills_verify, LV_OPA_COVER, 0);

  for(int i = 0; i < 4; i++) {
    lv_obj_set_style_bg_color(Elim_Qual_buttons[i], lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_set_style_bg_opa(Elim_Qual_buttons[i], LV_OPA_60, 0);
  }

  Elimination_state = false;
  Qualification_state = false;
  selected_state = 3;
  Path_selected = 5;

  update_all_banners();

}

void UI(){
// 1. Get the active screen (Corrected for LVGL v9)
    lv_obj_t * screen = lv_screen_active(); 

    //////////////////////////////////////////////////////
    // Create main menu and set as first menu
    //////////////////////////////////////////////////////

    // 2. Create Main Menu Container
    main_menu = lv_obj_create(screen);
    lv_obj_set_size(main_menu, 480, 240);

    // 3. Create Button (Corrected: lv_button_create)  Motor Button
    lv_obj_t * btn_diag_Motor = lv_button_create(main_menu); 
    lv_obj_align(btn_diag_Motor, LV_ALIGN_CENTER, 90, 0);
    lv_obj_t * label_diag_Motor = lv_label_create(btn_diag_Motor);
    lv_label_set_text(label_diag_Motor, "Motor Stats");

    lv_obj_t * btn_Auton = lv_button_create(main_menu); 
    lv_obj_align(btn_Auton, LV_ALIGN_CENTER, -90, 0);
    lv_obj_t * label_Auton = lv_label_create(btn_Auton);
    lv_label_set_text(label_Auton, "Auton Selection");

    lv_obj_t* banner_main = lv_obj_create(main_menu);
    lv_obj_set_size(banner_main, 480, 40);
    lv_obj_align(banner_main, LV_ALIGN_CENTER, 0, 70);
    status_labels[0] = lv_label_create(banner_main);
    lv_obj_center(status_labels[0]);
    lv_obj_set_style_border_width(banner_main, 0, 0);
    lv_obj_set_style_border_color(banner_main, lv_palette_main(LV_PALETTE_LAST), 0);

    status_dots[0] = lv_obj_create(banner_main); 
    lv_obj_set_size(status_dots[0], 15, 15);    // Small circle
    lv_obj_set_style_radius(status_dots[0], LV_RADIUS_CIRCLE, 0); // Make it a dot
    lv_obj_align(status_dots[0], LV_ALIGN_LEFT_MID, 90, 0); // Place on the left of the banner
    lv_obj_set_style_bg_opa(status_dots[0], LV_OPA_COVER, 0);

    //////////////////////////////////////////////////////////
    // Diagnostics Page
    //////////////////////////////////////////////////////////

    // --- 2. DIAGNOSTICS PAGE ---
    diag_menu = lv_obj_create(screen);
    lv_obj_set_size(diag_menu, 480, 240);
    lv_obj_add_flag(diag_menu, LV_OBJ_FLAG_HIDDEN); // Hide initially

    // Setup Flex Layout for the 3x3 Grid
    lv_obj_set_flex_flow(diag_menu, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(diag_menu, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(diag_menu, 5, 0);
    lv_obj_set_style_pad_gap(diag_menu, 5, 0);

    // Create 9 Grid Cells for Named Motors
    for (int i = 0; i < 9; i++) {
        lv_obj_t* cell = lv_obj_create(diag_menu);
        lv_obj_set_size(cell, 145, 60); // Fits 3 across nicely
        lv_obj_remove_flag(cell, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_pad_all(cell, 2, 0);

        motor_labels[i] = lv_label_create(cell);
        lv_label_set_text(motor_labels[i], robot_motors[i].name);
        lv_obj_center(motor_labels[i]);
    }

    // --- 3. BACK BUTTON (Placed on top of the grid) ---
    // Note: To keep the back button accessible, we create it as a child of diag_menu
    // but give it a specific alignment that won't interfere with the flex wrap.
    lv_obj_t* btn_back = lv_button_create(diag_menu);
    lv_obj_set_size(btn_back, 100, 40);
    lv_obj_t* lbl_back = lv_label_create(btn_back);
    lv_label_set_text(lbl_back, "    Back");

    ////////////////////////////////////////////////////////////////
    // Auton Selection Page 1
    ////////////////////////////////////////////////////////////////

    auton_first_menue = lv_obj_create(screen);
    lv_obj_set_size(auton_first_menue, 480, 240);
    lv_obj_add_flag(auton_first_menue, LV_OBJ_FLAG_HIDDEN);

    btn_Qualification = lv_button_create(auton_first_menue);   //Qualification 
    lv_obj_align(btn_Qualification, LV_ALIGN_CENTER, -160, 0);
    lv_obj_t * label_Qualification = lv_label_create(btn_Qualification);
    lv_label_set_text(label_Qualification, "Qualification");

    btn_Elimination = lv_button_create(auton_first_menue);  //Elimination
    lv_obj_align(btn_Elimination, LV_ALIGN_CENTER, 0, 0);
    lv_obj_t * label_Elimination = lv_label_create(btn_Elimination);
    lv_label_set_text(label_Elimination, " Elimination ");

    btn_Skills = lv_button_create(auton_first_menue); //Skills
    lv_obj_align(btn_Skills, LV_ALIGN_CENTER, 160, 0);
    lv_obj_t * label_Skills = lv_label_create(btn_Skills);
    lv_label_set_text(label_Skills, "     Skills     ");

    lv_obj_t* btn_back_main = lv_button_create(auton_first_menue); //back
    lv_obj_set_size(btn_back_main, 100, 40);
    lv_obj_t* lbl_back_1 = lv_label_create(btn_back_main);
    lv_label_set_text(lbl_back_1, "    Back");

    lv_obj_t* banner_auton = lv_obj_create(auton_first_menue);
    lv_obj_set_size(banner_auton, 480, 40);
    lv_obj_align(banner_auton, LV_ALIGN_CENTER, 0, 70);
    status_labels[1] = lv_label_create(banner_auton);
    lv_obj_center(status_labels[1]);
    lv_obj_set_style_border_width(banner_auton, 0, 0);
    lv_obj_set_style_border_color(banner_auton, lv_palette_main(LV_PALETTE_LAST), 0);

    status_dots[1] = lv_obj_create(banner_auton); 
    lv_obj_set_size(status_dots[1], 15, 15);    // Small circle
    lv_obj_set_style_radius(status_dots[1], LV_RADIUS_CIRCLE, 0); // Make it a dot
    lv_obj_align(status_dots[1], LV_ALIGN_LEFT_MID, 90, 0); // Place on the left of the banner
    lv_obj_set_style_bg_opa(status_dots[1], LV_OPA_COVER, 0);


    update_all_banners();

    /////////////////////////////////////////////////////////////////
    // Qualification / Elimination Page
    /////////////////////////////////////////////////////////////////

    qualification_elimination_menu = lv_obj_create(screen);
    lv_obj_set_size(qualification_elimination_menu, 480, 240);
    lv_obj_add_flag(qualification_elimination_menu, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_pad_all(qualification_elimination_menu, 0, 0);

    lv_obj_t* btn_back_qual = lv_button_create(qualification_elimination_menu); //back button
    lv_obj_t* lbl_back_2 = lv_label_create(btn_back_qual);
    lv_label_set_text(lbl_back_2, "Back");
    lv_obj_center(lbl_back_2);
    lv_obj_set_size(btn_back_qual, 120, 240);
    lv_obj_align(btn_back_qual, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(btn_back_qual, lv_palette_main(LV_PALETTE_ORANGE), 0);
    add_border(btn_back_qual);

    btn_right_blue = lv_button_create(qualification_elimination_menu);
    lv_obj_t* lbl_right_blue = lv_label_create(btn_right_blue);
    lv_label_set_text(lbl_right_blue, "Right");
    lv_obj_center(lbl_right_blue);
    lv_obj_set_size(btn_right_blue, 180, 120);
    lv_obj_align(btn_right_blue, LV_ALIGN_TOP_LEFT, 180, 0);
    lv_obj_set_style_bg_color(btn_right_blue, lv_palette_main(LV_PALETTE_BLUE), 0);
    add_border(btn_right_blue);

    btn_left_red = lv_button_create(qualification_elimination_menu);
    lv_obj_t* lbl_left_red = lv_label_create(btn_left_red);
    lv_label_set_text(lbl_left_red, "Left");
    lv_obj_center(lbl_left_red);
    lv_obj_set_size(btn_left_red, 180, 120);
    lv_obj_align(btn_left_red, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_bg_color(btn_left_red, lv_palette_main(LV_PALETTE_RED), 0);
    add_border(btn_left_red);

    btn_right_red = lv_button_create(qualification_elimination_menu);
    lv_obj_t* lbl_right_red = lv_label_create(btn_right_red);
    lv_label_set_text(lbl_right_red, "Right");
    lv_obj_center(lbl_right_red);
    lv_obj_set_size(btn_right_red, 180, 120);
    lv_obj_align(btn_right_red, LV_ALIGN_TOP_LEFT, 0, 120);
    lv_obj_set_style_bg_color(btn_right_red, lv_palette_main(LV_PALETTE_RED), 0);
    add_border(btn_right_red);

    btn_left_blue = lv_button_create(qualification_elimination_menu);
    lv_obj_t* lbl_left_blue = lv_label_create(btn_left_blue);
    lv_label_set_text(lbl_left_blue, "Left");
    lv_obj_center(lbl_left_blue);
    lv_obj_set_size(btn_left_blue, 180, 120);
    lv_obj_align(btn_left_blue, LV_ALIGN_TOP_LEFT, 180, 120);
    lv_obj_set_style_bg_color(btn_left_blue, lv_palette_main(LV_PALETTE_BLUE), 0);
    add_border(btn_left_blue);

    Elim_Qual_buttons[0] = btn_right_blue;
    Elim_Qual_buttons[1] = btn_left_red;
    Elim_Qual_buttons[2] = btn_right_red;
    Elim_Qual_buttons[3] = btn_left_blue;
        

    /////////////////////////////////////////////////////////////////
    // Skills Selection Page
    /////////////////////////////////////////////////////////////////

    skills_menu = lv_obj_create(screen);
    lv_obj_set_size(skills_menu, 480, 240);
    lv_obj_add_flag(skills_menu, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_pad_all(skills_menu, 0, 0);

    lv_obj_t* btn_back_skill = lv_button_create(skills_menu); //back button
    lv_obj_t* lbl_back_3 = lv_label_create(btn_back_skill);
    lv_label_set_text(lbl_back_3, "Back");
    lv_obj_center(lbl_back_3);
    lv_obj_set_size(btn_back_skill, 120, 240);
    lv_obj_align(btn_back_skill, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(btn_back_skill, lv_palette_main(LV_PALETTE_ORANGE), 0);
    add_border(btn_back_skill);

    btn_skills_verify = lv_button_create(skills_menu);
    lv_obj_t * lbl_skills_verification = lv_label_create(btn_skills_verify);
    lv_label_set_text(lbl_skills_verification, "Skills");
    lv_obj_set_size(btn_skills_verify, 230, 230);
    lv_obj_set_style_radius(btn_skills_verify, LV_RADIUS_CIRCLE, 0);
    lv_obj_center(lbl_skills_verification);
    lv_obj_set_style_shadow_width(btn_skills_verify, 0, 0);
    lv_obj_align(btn_skills_verify, LV_ALIGN_TOP_LEFT, 65, 5);
    lv_obj_set_style_bg_color(btn_skills_verify, lv_palette_main(LV_PALETTE_RED), 0);

    ////////////////////////////////////////////////////////////////
    // Code to prevent scrolling
    //////////////////////////////////////////////////////////////////

    lv_obj_remove_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(main_menu, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(diag_menu, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(auton_first_menue, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(qualification_elimination_menu, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(skills_menu, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(banner_main, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(banner_auton, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(status_dots[0], LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_remove_flag(status_dots[1], LV_OBJ_FLAG_SCROLLABLE);
    

    /////////////////////////////////////////////////////////////////
    //  Assign Callbacks
    /////////////////////////////////////////////////////////////////

    lv_obj_add_event_cb(btn_diag_Motor, switch_page_cb, LV_EVENT_CLICKED, diag_menu); // motor menu buttons
    lv_obj_add_event_cb(btn_back, switch_page_cb, LV_EVENT_CLICKED, main_menu);

    lv_obj_add_event_cb(btn_Auton, switch_page_cb, LV_EVENT_CLICKED, auton_first_menue); // auton screen one buttons
    lv_obj_add_event_cb(btn_back_main, switch_page_cb, LV_EVENT_CLICKED, main_menu);
    lv_obj_add_event_cb(btn_Qualification, auton_logic_cb, LV_EVENT_CLICKED, qualification_elimination_menu);
    lv_obj_add_event_cb(btn_Elimination, auton_logic_cb, LV_EVENT_CLICKED, qualification_elimination_menu);
    lv_obj_add_event_cb(btn_Skills, auton_logic_cb, LV_EVENT_CLICKED, skills_menu);

    lv_obj_add_event_cb(btn_back_qual, switch_page_cb, LV_EVENT_CLICKED, auton_first_menue); //Qualification / elimination buttons
    for(int i = 0; i < 4; i++) {
      original_colors[i] = lv_obj_get_style_bg_color(Elim_Qual_buttons[i], 0);
      lv_obj_add_event_cb(Elim_Qual_buttons[i], auton_path_cb, LV_EVENT_CLICKED, NULL);
    }

    lv_obj_add_event_cb(btn_back_skill, switch_page_cb, LV_EVENT_CLICKED, auton_first_menue); //Skills buttons
    lv_obj_add_event_cb(btn_skills_verify, skills_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_update_layout(screen);
    lv_refr_now(NULL);
}