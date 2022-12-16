#ifndef ASTROTRACKER_MENU_H
#define ASTROTRACKER_MENU_H

/*
 * File: astroTracker.hpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Menu class to interface with astroTracker
 */


#include "astroTracker.hpp"

class astroTracker_menu {
public:
    /*
     * @brief Default constructor
     */
    astroTracker_menu();

    /*
     * @brief Constructs the astroTracker_menu object using satellite orbital information contained in the specified file. Currently only supports TLE files and json files in OMM format (EX: https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=json)
     * 
     * @param FILENAME (std::string) - The filename (including path from the current working directory) to the file containing satellite orbital information
     */
    astroTracker_menu(std::string FILENAME);

    /*
     * @brief Destructor
     */
    ~astroTracker_menu();


    /*
     * @brief Main menu interface start function
     */
    void mainMenu();

private:
    astroTracker astroTrack;

    /*
     * @brief Display program about page
     */
    void about();

    /*
     * @brief Start satellite database editing page
     */
    void editSatDatabase();

    /*
     * @brief Start position calculation page
     */
    void positionCalc();

    
};

#endif