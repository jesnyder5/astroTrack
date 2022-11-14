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
    // Constructors and Destructors
    satellite();

    // Construct using tle lines and name
    satellite(std::string name, std::string line1, std::string line2);

    // Construct using individually provided fields
    satellite(std::string name,
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

    // Construct using pre-initialized satKey
    satellite(__int64 satKey);

    ~satellite();
    
    // Retrieve satellite name string
    std::string getSatelliteName();

    __int64 getSatKey();

private:
    // Satellite Name
    std::string satelliteName = "null";


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
    __int64 satKey;

};



#endif