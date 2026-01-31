#include "Devices.h"
#include "lemlib/api.hpp"
#include "main.h"



void Devour(){
    Intake1.move_voltage(12000);
    Intake2.move_voltage(-8000);
    //Intake3.move_voltage(8000);
    gate.set_value(0);
}

void Halt_Intake(){
    Intake1.move_voltage(0);
    Intake2.move_voltage(0);
    Intake3.move_voltage(0);
    gate.set_value(0);
}

void ScoreBottom(){
    Intake1.move_voltage(-12000);
    Intake2.move_voltage(8000);
    //Intake3.move_voltage(-8000);
    gate.set_value(0);
}

void ScoreMiddle(){
    Intake3.move_voltage(-8000);
    Intake1.move_voltage(12000);
    Intake2.move_voltage(-8000);
    gate.set_value(0);
}

void ScoreTop(){
    Intake1.move_voltage(12000);
    Intake2.move_voltage(-8000);
    Intake3.move_voltage(8000);
    gate.set_value(1);
}