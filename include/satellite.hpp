#ifndef SATELLITE_H
#define SATELLITE_H

/*
 * File: satellite.hpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 28, 2022
 *
 * Satellite object with attributes corresponding to USSF Astrodynamics Standards satellite objects
 * and related functions
 */

#include <string>

//Directives for Windows PC and UNIX platforms
#ifdef _WIN32
   #include <windows.h>
   //#define STDCALL __stdcall // Remember to use this __stdcall in VC++ 6.0
   #define STDCALL __cdecl   // Remember to select this __cdecl in VS 2008
   // windows platforms has __int64 type - 64-bit integer
#else
   #include <dlfcn.h>
   #define STDCALL 
   // unix-family platforms doesn't support __int64, therefore need to define it here
   typedef long long __int64;
#endif

class satellite {
public:
    // ===== Constructors and Destructor =====

    /*
     * @brief Default constructor
     * @warning Do not attempt to use with Astrodynamics Standards libraries
     */
    satellite();

    /*
     * @brief Constructs satellite object using the satellite name and its TLE entry
     * @warning The Astrodynamics Standards SGP4 library must be loaded before construction
     * 
     * @param subject_SatName (std::string) - The name of the satellite
     * @param line1 (std::string) - The first TLE entry line for the satellite
     * @param line2 (std::string) - The second TLE entry line for the satellite
     */
    satellite(std::string subject_SatName, std::string line1, std::string line2);

    /*
     * @brief Constructs satellite object using its individually provided fields
     * @warning The Astrodynamics Standards SGP4 library must be loaded before construction
     * 
     * @param subject_SatName (std::string) - The name of the satellite
     * @param in_satNum (int) - Satellite number
     * @param secClass (char) - Security classification
     * @param satName (char[8]) - Satellite international designator
     * @param epochYr (int) -  Element epoch time - year, [YY]YY
     * @param epochDays (double) - Element epoch time - day of year, DDD.DDDDDDDD
     * @param bstar (double) - B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP)
     * @param ephType (int) - Satellite ephemeris type (0: SGP, 2: SGP4)
     * @param elsetNum (int) - Element set number
     * @param incli (double) - Orbit inclination (degrees)
     * @param node (double) - Right ascension of ascending node (degrees)
     * @param eccen (double) - Eccentricity
     * @param omega (double) - Argument of perigee (degrees)
     * @param mnAnomaly (double) - Mean anomaly (degrees)
     * @param mnMotion (double) - Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion)
     * @param revNum (int) - Revolution number at epoch
     */
    satellite(std::string subject_SatName,
                int in_satNum,
                char in_secClass,
                char in_satName[8],
                int in_epochYr,
                double in_epochDays,
                double in_bstar,
                int in_ephType,
                int in_elsetNum,
                double in_incli,
                double in_node,
                double in_eccen,
                double in_omega,
                double in_mnAnomaly,
                double in_mnMotion,
                int in_revNum
            );

    /*
     * @brief Destructor
     */
    ~satellite();
    
    // ===== Main Functions =====

    /*
     * @brief Prints the orbital element set fields for the specified satellite
     */
    void printSatElset();

    /*
     * @brief Returns a string of the satellite name
     * 
     * @return Returns an std::string of the satellite name
     */
    std::string getSatelliteName();

    /*
     * @brief Returns the __int64 (long long) of the satellite object's corresponding Astrodynamics Standards library satKey
     * 
     * @return Returns an __int64 of the satellite's satKey
     */
    __int64 getSatKey();

private:
    // Satellite Name
    std::string satelliteName = "null";

    // TLE SO satellite key
    __int64 satKey = -1;

    // GP TLE fields
    int satNum = -1;            //Satellite number (in-Integer)
    char secClass = '-';        //Security classification (in-Character)
    char satName[8] = "null";   //Satellite international designator (in-Character[8])
    int epochYr = -1;           //Element epoch time - year, [YY]YY (in-Integer)
    double epochDays = -1;      //Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
    double bstar = -1;          //B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
    int ephType = -1;           //Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
    int elsetNum = -1;          //Element set number (in-Integer)
    double incli = -1;          //Orbit inclination (degrees) (in-Double)
    double node = -1;           //Right ascension of ascending node (degrees) (in-Double)
    double eccen = -1;          //Eccentricity (in-Double)
    double omega = -1;          //Argument of perigee (degrees) (in-Double)
    double mnAnomaly = -1;      //Mean anomaly (degrees) (in-Double)
    double mnMotion = -1;       //Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
    int revNum = -1;            //Revolution number at epoch (in-Integer)
};



#endif