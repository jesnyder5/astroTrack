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
#include <fstream>

#ifndef __WIN32
    #include <unistd.h>
    #include <fcntl.h>
#endif

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
        if((userInput == "s") || (userInput == "S")){
            selectSat();
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
                std::ifstream satDataFile(userInput);
                if(satDataFile){ // Input file opened, file exists
                    int satAddedCount = astroTrack.getSatCount();

                    // Suppress error output when loading
                    // POSIX centric solution
                    #ifndef __Win32
                        fflush(stderr);
                        int stderr_fd = dup(STDERR_FILENO); // Copy STDERR info to temp var
                        freopen("/dev/null", "w", stderr); // Reopen STDERR to write to /dev/null for now. 
                    #endif
                    astroTrack.loadFromFile(userInput);
                    #ifndef __Win32
                        fflush(stderr);
                        std::cout.flush(); // Empty any output buffers
                        dup2(stderr_fd, STDERR_FILENO); // Reset STDERR to original info
                        close(stderr_fd); // Close temp var
                    #endif

                    satAddedCount = astroTrack.getSatCount() - satAddedCount;
                    std::cout << "Successfully added " << satAddedCount << " satellites" << std::endl;
                    userInput = "";
                    break;
                }
                else if((userInput != "q") && (userInput != "Q")){
                    std::cout << "File " << userInput << " not found" << std::endl;
                }
            }
            userInput = "";
        }
        if((userInput == "r") || (userInput == "R")){
            std::vector<std::string> loadedSatNames = astroTrack.getSatNames(); // Get satellite names
            std::ios state(nullptr); // Create state object to reset cout
            int numDigits; // Declare max number of list index digits
            std::stringstream satEntry;
            while((userInput != "q") && (userInput != "Q")){
                std::cout << "==============================AstroTrack==============================" << std::endl;
                std::cout << "||                            Remove Sat                            ||" << std::endl;
                state.copyfmt(std::cout); // Save original cout formatting


                numDigits = std::to_string(loadedSatNames.size()).length(); // Determine the max digits that need to be listed
                for(int i = 1; i < loadedSatNames.size()+1; i+=2){
                    satEntry.str(std::string()); // Clear stringstream
                    satEntry.clear();
                    satEntry << "||   " << std::setw(numDigits) << std::right << i << ") " << loadedSatNames.at(i-1); // Load in left list entry
                    std::cout << std::setw(36) << std::left << satEntry.str(); // Print left list entry
                    if(i < loadedSatNames.size()){
                        satEntry.str(std::string()); // Clear stringstream
                        satEntry.clear();
                        satEntry << std::setw(numDigits) << std::right << i+1 << ") " << loadedSatNames.at(i); // Load in right list entry
                        std::cout << std::setw(29) << std::left << satEntry.str()  << "   ||" << std::endl; // Print right list entry
                    }
                    else{ // There are none to print for the right list entry
                        std::cout << std::setw(34) << std::right << "   ||" << std::endl; // Print empty right list entry
                    }
                }

                std::cout.copyfmt(state); // Restore formatting
                std::cout << "||                                                       Q - Back   ||" << std::endl;
                std::cout << "||                                                                  ||" << std::endl;
                std::cout << "======================================================================" << std::endl;
                std::cout << "Enter The Number To Delete or Go Back -> ";
                std::getline(std::cin, userInput);
                if(!userInput.empty() && (userInput.find_first_not_of("0123456789") == std::string::npos)){ // Check that input is an integer (and positive)
                    int delInd = std::stoi(userInput);
                    if(delInd > loadedSatNames.size()){ // Check if index too big
                        std::cout << "Please enter a valid number to delete" << std::endl;
                        continue;
                    }
                    // Should be good now
                    if(astroTrack.removeSat(loadedSatNames.at(delInd-1))){
                        loadedSatNames.erase(loadedSatNames.begin() + delInd-1); // Only remove from list if successfully deleted(?)
                    }
                }
            }
            userInput = "";
        }
        if((userInput == "e") || (userInput == "E")){
            while((userInput != "q") && (userInput != "Q")){
                std::cout << "=============================AstroTrack=============================" << std::endl;
                std::cout << "||                       Erase Sat Database                       ||" << std::endl;
                std::cout << "||   Erasing the satellite database will remove all loaded        ||" << std::endl;
                std::cout << "||   satellites from the program's memory. This will NOT delete   ||" << std::endl;
                std::cout << "||   any datafiles used to load satellites. Are you sure you      ||" << std::endl;
                std::cout << "||   want to erase the satellite database?                        ||" << std::endl;
                std::cout << "||                                                                ||" << std::endl;
                std::cout << "||   Y - Yes, erase the database                       Q - Back   ||" << std::endl;
                std::cout << "||                                                                ||" << std::endl;
                std::cout << "====================================================================" << std::endl;
                std::cout << "Enter Selection -> ";
                std::getline(std::cin, userInput);
                if((userInput == "y") || (userInput == "Y")){
                    astroTrack.removeAllSats();
                }
            }
            userInput = "";
        }
    }
}

void astroTracker_menu::selectSat(){
    std::string userInput = "";
    std::vector<std::string> loadedSatNames = astroTrack.getSatNames(); // Get satellite names
    std::ios state(nullptr); // Create state object to reset cout
    int numDigits; // Declare max number of list index digits
    std::stringstream satEntry;

    while((userInput != "q") && (userInput != "Q")){
        std::cout << "==============================AstroTrack==============================" << std::endl;
        std::cout << "||                    Select Satellite To Track                     ||" << std::endl;
        state.copyfmt(std::cout); // Save original cout formatting


        numDigits = std::to_string(loadedSatNames.size()).length(); // Determine the max digits that need to be listed
        for(int i = 1; i < loadedSatNames.size()+1; i+=2){
            satEntry.str(std::string()); // Clear stringstream
            satEntry.clear();
            satEntry << "||   " << std::setw(numDigits) << std::right << i << ") " << loadedSatNames.at(i-1); // Load in left list entry
            std::cout << std::setw(36) << std::left << satEntry.str(); // Print left list entry
            if(i < loadedSatNames.size()){
                satEntry.str(std::string()); // Clear stringstream
                satEntry.clear();
                satEntry << std::setw(numDigits) << std::right << i+1 << ") " << loadedSatNames.at(i); // Load in right list entry
                std::cout << std::setw(29) << std::left << satEntry.str()  << "   ||" << std::endl; // Print right list entry
            }
            else{ // There are none to print for the right list entry
                std::cout << std::setw(34) << std::right << "   ||" << std::endl; // Print empty right list entry
            }
        }

        std::cout.copyfmt(state); // Restore formatting
        std::cout << "||   S - Sun                        M - Moon             Q - Back   ||" << std::endl;
        std::cout << "||                                                                  ||" << std::endl;
        std::cout << "======================================================================" << std::endl;
        std::cout << "Enter The Number To Track or Go Back -> ";
        std::getline(std::cin, userInput);
        if(!userInput.empty() && ((userInput.find_first_not_of("0123456789") == std::string::npos) || (userInput == "s") || (userInput == "S") || (userInput == "m") || (userInput == "M"))){ // Check that input is valid
            if(userInput.find_first_not_of("0123456789") == std::string::npos){
                int satInd = std::stoi(userInput);
                if(satInd > loadedSatNames.size()){ // Check if index too big
                    std::cout << "Please enter a valid number to delete" << std::endl;
                    continue;
                }
                subject_SatName = loadedSatNames.at(satInd-1);
            }
            else if((userInput == "s") || (userInput == "S")){
                subject_SatName = "Sun";
            }
            else if((userInput == "m") || (userInput == "M")){
                subject_SatName = "Moon";
            }
            // Should be good now
            trackSat();
            subject_SatName = ""; // Reset for possible re-selection
        }
    }
    userInput = "";
}
