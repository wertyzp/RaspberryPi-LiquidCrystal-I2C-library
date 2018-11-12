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
    LiquidCrystal_I2C lcd(1,0x27,16,2);
    lcd.begin();
    lcd.setBacklight(1);
    lcd.setCursor(0,0);
    
    string str;
    while (true) {
        getline(cin, str, '\n');
        cout << "Writing " << str.c_str() << endl;
        lcd.clear();
        lcd.print(str.substr(0, 16));
        if (str.length() > 16) {
            lcd.setCursor(0, 1);
            lcd.print(str.substr(16, 16));
        }
        lcd.setCursor(0, 0);
    }
    
    return 0;
}

