/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: werty
 *
 * Created on November 12, 2018, 12:32 AM
 */

#include <cstdlib>
#include <iostream>
#include "LiquidCrystal_I2C.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "No string specified" << endl;
        return EXIT_FAILURE;
    }
    
    LiquidCrystal_I2C lcd(1,0x27,16,2);
    lcd.begin();
    lcd.setBacklight(1);
    lcd.setCursor(0,0);
    lcd.print(argv[1]);
    if (argc > 2) {
        lcd.setCursor(0, 1);
        lcd.print(argv[2]);
    }
    
    return EXIT_SUCCESS;
}

