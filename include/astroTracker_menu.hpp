#ifndef ASTROTRACKER_MENU_H
#define ASTROTRACKER_MENU_H

/*
 * File: astroTracker_menu.hpp
 * Author: Jeremy Snyder
 * Creation: Dec 16, 2022
 *
 * Menu class to interface with astroTracker
 */


#include "astroTracker.hpp"

class astroTracker_menu {
public:
    /*
     * @brief Constructs the astroTracker_menu object without loading any satellite orbital information
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
     * @brief astroTracker_menu Main Menu interface start function
     */
    void mainMenu();

private:
    astroTracker astroTrack;
    std::string subject_SatName;

    /*
     * @brief Display program about page
     */
    void about();

    /*
     * @brief Manipulate satellite database (add, remove, erase)
     */
    void editSatDatabase();

    /*
     * @brief Select satellite (or Sun/Moon) for tracking
     */
    void selectSat();

    /*
     * @brief Track satellite (position/ground track)
     */
    void trackSat();

    /*
     * @brief Track Sun/Moon (position)
     */
    void trackSunMoon();

};

#endif