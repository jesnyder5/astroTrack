/*
 * File: astroTracker.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Nov 13, 2022
 *
 * Uses USSF SGP4 to track objects from an Earth-fixed terrestrial reference frame.
 */

#include "astroTracker_menu.hpp"
#include <iostream>

astroTracker_menu::astroTracker_menu(){
}

astroTracker_menu::astroTracker_menu(std::string FILENAME){
    astroTrack.loadFromFile(FILENAME);
}

astroTracker_menu::~astroTracker_menu(){

}


void astroTracker_menu::mainMenu(){
    about();

    std::string userInput = "";
    while((userInput != "q") && (userInput != "Q")){
        std::cout << "=======================AstroTrack=======================" << std::endl;
        std::cout << "||                     Main Menu                      ||" << std::endl;
        std::cout << "||   A - About                       S - Select Sat   ||" << std::endl;
        std::cout << "||   E - Edit Sat Database           Q - Quit         ||" << std::endl;
        std::cout << "||                                                    ||" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << "Enter Selection -> ";
        std::getline(std::cin, userInput);
        
        if((userInput == "a") || (userInput == "A")){
            about();
        }
        if((userInput == "e") || (userInput == "E")){
            editSatDatabase();
        }

    }
}

void astroTracker_menu::about(){
    std::cout << "========================================================" << std::endl;
    std::cout << "||                     AstroTrack                     ||" << std::endl;
    std::cout << "||                                                    ||" << std::endl;
    std::cout << "||              created by Jeremy Snyder              ||" << std::endl;
    std::cout << "||                                                    ||" << std::endl;
    std::cout << "||         A C/C++ satellite tracking program         ||" << std::endl;
    std::cout << "||             using the official US SpOC             ||" << std::endl;
    std::cout << "||         Astrodynamics Standards Libraries          ||" << std::endl;
    std::cout << "========================================================" << std::endl;
}

void astroTracker_menu::editSatDatabase(){
    std::string userInput = "";
    while((userInput != "q") && (userInput != "Q")){
        std::cout << "=======================AstroTrack=======================" << std::endl;
        std::cout << "||                 Edit Sat Database                  ||" << std::endl;
        std::cout << "||   A - Add from file               R - Remove Sat   ||" << std::endl;
        std::cout << "||   E - Erase Sat Database          Q - Back         ||" << std::endl;
        std::cout << "||                                                    ||" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << "Enter Selection -> ";
        std::getline(std::cin, userInput);
        
        if((userInput == "a") || (userInput == "A")){
            while((userInput != "q") && (userInput != "Q")){
                std::cout << "=======================AstroTrack=======================" << std::endl;
                std::cout << "||                    Add from file                   ||" << std::endl;
                std::cout << "||  Warning: This program can handle exact duplicate  ||" << std::endl;
                std::cout << "||   and malformed orbital information, but cannot    ||" << std::endl;
                std::cout << "||   currently handle updating information in-place.  ||" << std::endl;
                std::cout << "||   Remove satellites from database before loading   ||" << std::endl;
                std::cout << "||   updated orbital information.                     ||" << std::endl;
                std::cout << "||                                         Q - Back   ||" << std::endl;
                std::cout << "||                                                    ||" << std::endl;
                std::cout << "========================================================" << std::endl;
                std::cout << "Enter Filename or Go Back -> ";
                std::getline(std::cin, userInput);
            }
            userInput = "";
        }
        if((userInput == "r") || (userInput == "R")){
            std::vector<std::string> loadedSatNames = astroTrack.getSatNames();
            std::ios state(nullptr);
            int numDigits;
            std::stringstream satEntry;
            while((userInput != "q") && (userInput != "Q")){
                std::cout << "============================AstroTrack============================" << std::endl;
                std::cout << "||                          Remove Sat                          ||" << std::endl;
                state.copyfmt(std::cout); // Save formatting


                numDigits = std::to_string(loadedSatNames.size()).length(); // Determine the max digits that need to be listed
                for(int i = 1; i < loadedSatNames.size()+1; i+=2){
                    satEntry.str(std::string());
                    satEntry.clear();
                    satEntry << "||   " << std::setw(numDigits) << std::right << i << ") " << loadedSatNames.at(i-1);
                    std::cout << std::setw(35) << std::left << satEntry.str();
                    if(i < loadedSatNames.size()){
                        satEntry.str(std::string());
                        satEntry.clear();
                        satEntry << std::setw(numDigits) << std::right << i+1 << ") " << loadedSatNames.at(i);
                        std::cout << std::setw(26) << std::left << satEntry.str()  << "   ||" << std::endl;
                    }
                    else{
                        std::cout << std::setw(31) << std::right << "   ||" << std::endl;
                    }
                }

                std::cout.copyfmt(state); // Restore formatting
                std::cout << "||                                                   Q - Back   ||" << std::endl;
                std::cout << "||                                                              ||" << std::endl;
                std::cout << "==================================================================" << std::endl;
                std::cout << "Enter Filename or Go Back -> ";
                std::getline(std::cin, userInput);
            }
            userInput = "";
        }
        if((userInput == "e") || (userInput == "E")){
            while((userInput != "q") && (userInput != "Q")){
                std::cout << "=======================AstroTrack=======================" << std::endl;
                std::cout << "||                    Add from file                   ||" << std::endl;
                std::cout << "||  Warning: This program can handle exact duplicate  ||" << std::endl;
                std::cout << "||   and malformed orbital information, but cannot    ||" << std::endl;
                std::cout << "||   currently handle updating information in-place.  ||" << std::endl;
                std::cout << "||   Remove satellites from database before loading   ||" << std::endl;
                std::cout << "||   updated orbital information.                     ||" << std::endl;
                std::cout << "||                                         Q - Back   ||" << std::endl;
                std::cout << "||                                                    ||" << std::endl;
                std::cout << "========================================================" << std::endl;
                std::cout << "Enter Filename or Go Back -> ";
                std::getline(std::cin, userInput);
            }
            userInput = "";
        }
    }
}

