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
    // ===== Constructors and Destructor =====

    /*
     * @brief Default constructor
     */
    astroTracker();

    /*
     * @brief Constructs astroTracker object using json object in OMM format
     * 
     * @param omm (nlohmann::json) - A json object containing a satellite's orbital information in OMM format (EX: https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=json)
     */
    astroTracker(json omm);

    /*
     * @brief Constructs astroTracker object using a single TLE entry and the satellite name
     * 
     * @param subject_SatName (std::string) - The name of the satellite
     * @param line1 (std::string) - The first TLE entry line for the satellite
     * @param line2 (std::string) - The second TLE entry line for the satellite
     */
    astroTracker(std::string subject_SatName, std::string line1, std::string line2);

    /*
     * @brief Constructs astroTracker object using satellite orbital information contained in the specified file. Currently only supports TLE files and json files in OMM format (EX: https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=json)
     * 
     * @param FILENAME (std::string) - The filename (including path from the current working directory) to the file containing satellite orbital information
     */
    astroTracker(std::string FILENAME);

    /*
     * @brief Destructor
     */
    ~astroTracker();
    
    // ===== Satellite Loading Functions =====

    /*
     * @brief Adds new satellites to the satellite database using satellite orbital information contained in the specified file. Currently only supports TLE files and json files in OMM format (EX: https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=json)
     * 
     * @param FILENAME (std::string) - The filename (including path from the current working directory) to the file containing satellite orbital information
     */
    void loadFromFile(std::string FILENAME);

    /*
     * @brief Adds a new satellite to the satellite database using its json object in OMM format
     * 
     * @param omm (nlohmann::json) - A json object containing a satellite's orbital information in OMM format (EX: https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=json)
     */
    void loadFromJson(json omm);

    /*
     * @brief Adds a new satellite to satellite database using the satellite name and its TLE entry
     * 
     * @param subject_SatName (std::string) - The name of the satellite
     * @param line1 (std::string) - The first TLE entry line for the satellite
     * @param line2 (std::string) - The second TLE entry line for the satellite
     */
    void loadFromTLE(std::string name, std::string line1, std::string line2);

    // ===== Main Functions =====

    /*
     * @brief Returns a string vector containing the names of all loaded satellites
     * 
     * @return Returns a std::vector<std::string> containing the names of all loaded satellite objects
     */
    std::vector<std::string> getSatNames();

    /*
     * @brief Returns the number of loaded satellites
     * 
     * @return Returns an integer of the number of loaded satellites
     */
    int getSatCount();

    /*
     * @brief Prints the orbital element set fields for the specified satellite
     * 
     * @param subject_SatName (std::string) - The name of the satellite to print the orbital elements of. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     */
    void printSatElset(std::string subject_SatName);

    /*
     * @brief Calculates the position unit vector to the Sun at subject_ds50UTC in the TEME frame
     * 
     * @param posSunTEME (OUT-double[3]) - A 3-element double array to store the position of the Sun at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the positions at. Defaults to -1, indicating to calculate the current time
     */
    void getSunPosTEME(double posSunTEME[3], double posTime_ds50UTC=-1);
    
    /*
     * @brief Calculates the position unit vector to the Sun at subject_ds50UTC in the ECR frame
     * @note ECR conversion is not currently working. For now this function outputs in the EFG frame (a difference on the order of 15 meters or less)
     * 
     * @param posSunECR (OUT-double[3]) - A 3-element double array to store the position of the Sun at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the positions at. Defaults to -1, indicating to calculate the current time
     */
    void getSunPosECR(double posSunECR[3], double subject_ds50UTC=-1);

    /*
     * @brief Calculates the latitude, longitude, and height in kilometers of the Sun at subject_ds50UTC
     * 
     * @param posSunLLH (OUT-double[3]) - A 3-element double array to store the latitude, longitude, and height in km of the Sun at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the position at. Defaults to -1, indicating to calculate the current time
     */
    void getSunPosLLH(double posSunLLH[3], double subject_ds50UTC=-1);

    /*
     * @brief Calculates the position unit vector to the Moon at subject_ds50UTC in the TEME frame
     * 
     * @param posMoonTEME (OUT-double[3]) - A 3-element double array to store the position of the Moon at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the positions at. Defaults to -1, indicating to calculate the current time
     */
    void getMoonPosTEME(double posMoonTEME[3], double posTime_ds50UTC=-1);
    
    /*
     * @brief Calculates the position unit vector to the Moon at subject_ds50UTC in the ECR frame
     * @note ECR conversion is not currently working. For now this function outputs in the EFG frame (a difference on the order of 15 meters or less)
     * 
     * @param posMoonECR (OUT-double[3]) - A 3-element double array to store the position of the Moon at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the positions at. Defaults to -1, indicating to calculate the current time
     */
    void getMoonPosECR(double posMoonECR[3], double subject_ds50UTC=-1);

    /*
     * @brief Calculates the latitude, longitude, and height in kilometers of the Moon at subject_ds50UTC
     * 
     * @param posMoonLLH (OUT-double[3]) - A 3-element double array to store the latitude, longitude, and height in km of the Moon at subject_ds50UTC.
     * @param subject_ds50UTC (IN-double) - The time to calculate the position at. Defaults to -1, indicating to calculate the current time
     */
    void getMoonPosLLH(double posMoonLLH[3], double subject_ds50UTC=-1);

    /*
     * @brief Calculates the position vector to the specified satellite at subject_ds50UTC in the TEME frame
     * 
     * @param posSatTEME (OUT-double[3]) - A 3-element double array to store the position of the satellite at subject_ds50UTC.
     * @param subject_SatName (IN-std::string) - The name of the satellite to calculate the position of. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     * @param subject_ds50UTC (IN-double) - The time to calculate the position at. Defaults to -1, indicating to calculate the current time
     */
    void getSatPosTEME(double posSatTEME[3], std::string subject_SatName, double subject_ds50UTC=-1);

    /*
     * @brief Calculates the position vector to the specified satellite at subject_ds50UTC in the ECR frame
     * @note ECR conversion is not currently working. For now this function outputs in the EFG frame (a difference on the order of 15 meters or less)
     * 
     * @param posSatECR (OUT-double[3]) - A 3-element double array to store the position of the satellite at subject_ds50UTC.
     * @param subject_SatName (IN-std::string) - The name of the satellite to calculate the position of. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     * @param subject_ds50UTC (IN-double) - The time to calculate the position at. Defaults to -1, indicating to calculate the current time
     */
    void getSatPosECR(double posSatECR[3], std::string subject_SatName, double subject_ds50UTC=-1);

    /*
     * @brief Calculates the latitude, longitude, and height in kilometers of the specified satellite at subject_ds50UTC
     * 
     * @param posSatLLH (OUT-double[3]) - A 3-element double array to store the latitude, longitude, and height in km of the satellite at subject_ds50UTC.
     * @param subject_SatName (IN-std::string) - The name of the satellite to calculate the position of. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     * @param subject_ds50UTC (IN-double) - The time to calculate the position at. Defaults to -1, indicating to calculate the current time
     */
    void getSatPosLLH(double posSatLLH[3], std::string subject_SatName, double subject_ds50UTC=-1);

    /*
     * @brief [NOT FULLY IMPLEMENTED] Calculates the look angle to a specified satellite at subject_ds50UTC[?] from an observer's position
     * 
     * @param subject_SatName (std::string) - The name of the satellite to calculate a look angle for. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     */
    void printSatLA(std::string subject_SatName);

    /*
     * @brief [NOT YET IMPLEMENTED] Displays graph of satellite orbit using matplotplusplus
     * 
     * @param subject_SatName (std::string) - The name of the satellite to graph the orbit of. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     * @param backwardsHours (double) - The number of hours before the current time to track the satellite. Defaults to 1
     * @param forwardHours (double) - The number of hours after the current time to track the satellite. Defaults to 1
     * 
     * @return Returns false if the satellite could not be found by the name provided. Returns true otherwise.
     */
    void graphSatOrbit(std::string subject_SatName, double backwardsHours=1, double forwardHours=1);

    /*
     * @brief Displays graph of satellite ground track using matplotplusplus
     * 
     * @param subject_SatName (std::string) - The name of the satellite to create a ground track for. This should be the same name as returned by the satellite object's getSatelliteName() and designated when creating the object.
     * @param backwardsHours (double) - The number of hours before the current time to track the satellite. Defaults to 1
     * @param forwardHours (double) - The number of hours after the current time to track the satellite. Defaults to 1
     * 
     * @return Returns false if the satellite could not be found by the name provided. Returns true otherwise.
     */
    bool graphSatGroundTrack(std::string subject_SatName, double backwardsHours=1, double forwardHours=1);

    // ===== Utility Functions =====

    /*
     * @brief Calculates and returns the current time in ds50UTC
     * 
     * @return Returns a double representing the current time in ds50TUC
     */
    double getCurrTime_ds50UTC();

private:
    // Vector containing loaded satellite
    std::vector<satellite> loadedSats;

    // ===== Astrodynamics Standards Library initialization functions =====

    // Load needed dlls
    void LoadAstroStdDlls();

    // Initialize dlls
    void InitAstroStdDlls();

    // Free dlls
    void FreeAstroStdDlls();

    // ===== Utility Functions =====

    // Determines whether the provided year is a leap year
    bool isLeapYear(int year);

    // Converts a month number and year to a day-of-month displacement
    int monthToDaysOfYr(int month, int year);

};

#endif