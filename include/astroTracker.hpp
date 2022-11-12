#ifndef ASTROTRACKER_H
#define ASTROTRACKER_H

/*
 * File: astroTracker.hpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Sep 28, 2022
 *
 * Uses USSF SGP4 libraries to track objects from an Earth-fixed terrestrial reference frame.
 */


#include "satellite.hpp"
#include "json.hpp"
using json = nlohmann::json;

class astroTracker {
public:
    //Constructors and Destructors
    astroTracker();

    // Construct using json object in OMM format
    astroTracker(json omm);

    // Construct using tle lines and name
    astroTracker(std::string name, std::string line1, std::string line2);

    // Construct using json or tle files
    astroTracker(std::string FILENAME);

    ~astroTracker();
    
    // Returns string vector of loaded satellite names
    std::vector<std::string> getSatNames();

    // Prints TLE fields for the specified satellite
    void printSatTLE(std::string name);

    // 
    // Convert latitude, longitude, and height retrived from GPS to TEME vector
    void getGPSposTEME(double posTEME[3]);

    void getSunAndMoonPosTEME(double posSunTEME[3], double posMoonTEME[3], double posTime_ds50UTC=-1);
    
    void getSunAndMoonPosECR(double posSunECR[3], double posMoonECR[3], double posTime_ds50UTC=-1);

private:
    // Vector containing loaded satellite
    std::vector<satellite> loadedSats;

    //Satellite Loading Functions
    void loadFromFile(std::string FILENAME);
    void loadFromJson(json omm);
    void loadFromTLE(std::string name, std::string line1, std::string line2);

    // ===== Astrodynamics Standards Library initialization functions =====

    // Load needed dlls
    void LoadAstroStdDlls();

    // Initialize dlls
    void InitAstroStdDlls();

    // Free dlls
    void FreeAstroStdDlls();

    //Utility Functions


    double getCurrTime_ds50UTC();


    bool isLeapYear(int year);


    int monthToDaysOfYr(int month, int year);

};

#endif