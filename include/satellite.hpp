#ifndef SATELLITE_H
#define SATELLITE_H

/*
 * File: satellite.hpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 7, 2022
 *
 * Satellite object with attributes corresponding to USSF Astrodynamics Standards satellite objects
 * and related functions
 */

#include <string>

class satellite {
public:
    // Constructors and Destructors
    satellite();

    // Construct using tle lines and name
    satellite(std::string name, std::string line1, std::string line2);

    // Construct using individually provided fields
    // satellite();

    ~satellite();
    
private:
    // Utility Functions
    bool isLeapYear(int year);
    int monthToDaysOfYr(int month, int year);

    // Load/Initialize/Free needed dlls
    void LoadAstroStdDlls();
    void InitAstroStdDlls();
    void FreeAstroStdDlls();

    // GP TLE fields
    int satNum;             //Satellite number (in-Integer)
    char secClass;          //Security classification (in-Character)
    char satName[8];        //Satellite international designator (in-Character[8])
    int epochYr;            //Element epoch time - year, [YY]YY (in-Integer)
    double epochDays;       //Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
    double bstar;           //B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
    int ephType;            //Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
    int elsetNum;           //Element set number (in-Integer)
    double incli;           //Orbit inclination (degrees) (in-Double)
    double node;            //Right ascension of ascending node (degrees) (in-Double)
    double eccen;           //Eccentricity (in-Double)
    double omega;           //Argument of perigee (degrees) (in-Double)
    double mnAnomaly;       //Mean anomaly (degrees) (in-Double)
    double mnMotion;        //Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
    int revNum;             //Revolution number at epoch (in-Integer)

    // TLE SO satellite key
    long satKey;

};



#endif