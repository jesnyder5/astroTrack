#ifndef ASTROTRACKER_H
#define ASTROTRACKER_H

/*
 * File: astroTracker.hpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Jan 12, 2022
 *
 * Uses USSF SGP4 libraries to track objects from an Earth-fixed terrestrial reference frame.
 */


#include <json.hpp>
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

    // Convert latitude, longitude, and height retrived from GPS to TEME vector
    void getGPSposTEME(double posTEME[3]);

    void getSunAndMoonPosTEME(double posSunTEME[3]);
    
private:
    // Json object using satellite names as keys and storing satellite properties as well as corresponding TLE dll satKey
    json sats;

    // Vector containing loaded satellite names (used as keys for sats json)
    std::vector<std::string> satNames;

    //Loading Functions
    void loadFromFile(std::string FILENAME);
    void loadFromJson(json omm);
    void loadFromTLE(std::string name, std::string line1, std::string line2);

    // Load needed dlls
    void LoadAstroStdDlls();

    // Initialize dlls
    void InitAstroStdDlls();

    // Free dlls
    void FreeAstroStdDlls();

    //Utility Functions
    bool isLeapYear(int year);
    int monthToDaysOfYr(int month, int year);


    //GP TLE fields
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

    //TLE SO satellite key
    long satKey;
};



#endif