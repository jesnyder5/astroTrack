/*
 * File: astroTracker.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Nov 13, 2022
 *
 * Uses USSF SGP4 to track objects from an Earth-fixed terrestrial reference frame.
 */

#include "astroTracker.hpp"
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "time.h"
#include <matplot/matplot.h>

#ifndef __Win32
#include <unistd.h>
#include <fcntl.h>
#endif

#ifndef ASTDYN_STD
#define ASTDYN_STD
// Provided Astrodynamics Standards library wrappers
extern "C" {
#include "DllMainDll.h"
#include "DllMainDll_Service.h"
#include "EnvConstDll.h"
#include "TimeFuncDll.h"
#include "TimeFuncDll_Service.h"
#include "AstroFuncDll.h"
#include "TleDll.h"
#include "Sgp4PropDll.h"
}
#endif

astroTracker::astroTracker(){
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    char logMsg[] = "End of standard constructor";
    LogMessage(logMsg);
}

astroTracker::astroTracker(json omm){
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    loadFromJson(omm);
    std::cout << "Successfully loaded " << TleGetCount() << " satellites" << std::endl;

    char logMsg[] = "End of json constructor";
    LogMessage(logMsg);
}

astroTracker::astroTracker(std::string name, std::string line1, std::string line2){
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    loadFromTLE(name, line1, line2);
    std::cout << "Successfully loaded " << TleGetCount() << " satellites" << std::endl;

    char logMsg[] = "End of tle constructor";
    LogMessage(logMsg);
}

astroTracker::astroTracker(std::string FILENAME){
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    loadFromFile(FILENAME);
    std::cout << "Successfully loaded " << TleGetCount() << " satellites" << std::endl;

    // Create log message variables
    std::string logMsgStr;
    char logMsg[128];

    // Log number of loaded satellites
    logMsgStr = "Successfully loaded " + std::to_string(TleGetCount()) + " satellites";
    strcpy(logMsg, logMsgStr.c_str());
    LogMessage(logMsg);

    // Log end of constuctor
    strcpy(logMsg, "End of file-based constructor");
    LogMessage(logMsg);
}

astroTracker::~astroTracker(){
    // Free loaded AstroStd dlls
    FreeAstroStdDlls();
}

//================================================ Initialization Functions ============================

// Load all the dlls being used in the program
void astroTracker::LoadAstroStdDlls(){
    // Library wrappers output loading messages to STDOUT. This will redirect to somewhere else
    // POSIX centric solution
    // #ifndef __Win32
    // fflush(stdout);
    // int stdout_fd = dup(STDOUT_FILENO); // Copy STDOUT info to temp var
    // freopen("/dev/null", "w", stdout); // Reopen STDOUT to write to /dev/null for now. 
    // #endif

    // Load MainDll dll
    LoadDllMainDll();

    // Load EnvConst dll and assign function pointers
    LoadEnvConstDll();

    // Load TimeFunc dll and assign function pointers
    LoadTimeFuncDll();

    // Load AstroFunc dll and assign function pointers
    LoadAstroFuncDll();

    // Load Tle dll and assign function pointers
    LoadTleDll();

    // Load Sgp4Prop dll and assign function pointers
    LoadSgp4PropDll();

    // #ifndef __Win32
    // fflush(stdout);
    // std::cout.flush(); // Empty any output buffers
    // dup2(stdout_fd, STDOUT_FILENO); // Reset STDOUT to original info
    // close(stdout_fd); // Close temp var
    // #endif
}

// Initialize all the dlls being used in the program
void astroTracker::InitAstroStdDlls(){
    fAddr apPtr;
    int errCode;

    // Get pointer to the global data (data pointers, function pointers, ...) that's being used among the dlls in the program
    apPtr = DllMainInit();

    char LOGFILE[] = "sgp4_log.txt";
    OpenLogFile(LOGFILE);

    // Create log message variables
    std::string logMsgStr;
    char logMsg[128];
    // Log tracker start time
    time_t rawtime;
    time(&rawtime);
    strftime(logMsg, 128,"astroTracker Start: %c UTC", gmtime(&rawtime));
    LogMessage(logMsg);

    errCode = EnvInit(apPtr);
    if (errCode != 0)
        ShowMsgAndTerminate();

    errCode = TimeFuncInit(apPtr);
    if (errCode != 0)
        ShowMsgAndTerminate();

    errCode = AstroFuncInit(apPtr);
    if (errCode != 0)
        ShowMsgAndTerminate();

    errCode = TleInit(apPtr);
    if (errCode != 0)
        ShowMsgAndTerminate();

    errCode = Sgp4Init(apPtr);
    if (errCode != 0)
        ShowMsgAndTerminate();

    // Version Info
    char DllInfo[INFOSTRLEN];
    DllMainGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);

    EnvGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);

    TimeFuncGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);

    AstroFuncGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);

    TleGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);

    Sgp4GetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    // printf("%s\n", DllInfo);
    LogMessage(DllInfo);
}

void astroTracker::FreeAstroStdDlls(){
    // Library wrappers output loading messages to STDOUT. This will redirect to somewhere else
    // POSIX centric solution
    // #ifndef __Win32
    // fflush(stdout);
    // int stdout_fd = dup(STDOUT_FILENO); // Copy STDOUT info to temp var
    // freopen("/dev/null", "w", stdout); // Reopen STDOUT to write to /dev/null for now. 
    // #endif

    // Free Sgp4Prop dll
    FreeSgp4PropDll();
    
    // Free Tle dll
    FreeTleDll();

    // Free AstroFunc dll
    FreeAstroFuncDll();

    // Free TimeFunc dll
    FreeTimeFuncDll();

    // Free EnvConst dll
    FreeEnvConstDll();

    // Create log message variables
    std::string logMsgStr;
    char logMsg[128];
    // Log tracker stop time
    time_t rawtime;
    time(&rawtime);
    strftime(logMsg, 128,"astroTracker Stop: %c UTC", gmtime(&rawtime));
    LogMessage(logMsg);
    CloseLogFile();

    // Free MainDll dll
    FreeDllMainDll();

    // #ifndef __Win32
    // fflush(stdout);
    // std::cout.flush(); // Empty any output buffers
    // dup2(stdout_fd, STDOUT_FILENO); // Reset STDOUT to original info
    // close(stdout_fd); // Close temp var
    // #endif
}

//================================================ Satellite Loading Functions ============================

void astroTracker::loadFromFile(std::string FILENAME){
    if(FILENAME.substr(FILENAME.length()-5) == ".json"){
        // std::cout << "Loading json file" << std::endl;
        std::ifstream jsonFile(FILENAME);
        json j = json::parse(jsonFile);

        for(int i = 0; i < j.size(); i++){
            loadFromJson(j.at(i));
        }

    }
    else if(FILENAME.substr(FILENAME.length()-4) == ".tle"){
        //TleLoadFile(&FILENAME[0]);
        // std::cout << "Loading TLE file" << std::endl;

        std::ifstream tleFile(FILENAME);
        std::string name, line1, line2;
        int startInd = 0;
        while(tleFile.good()){
            name, line1, line2 = "";
            getline(tleFile, name);
            startInd = name.find_first_not_of(" \t");
            name = name.substr(startInd,(name.find_last_not_of(" \t") - startInd + 1));
            getline(tleFile, line1);
            getline(tleFile, line2);
            if((line1[0] == '1') && (line2[0] == '2')){
                loadFromTLE(name, line1, line2);
            }
        }

    } else{

    }
}

void astroTracker::loadFromJson(json omm){
    char satName[8]; 
    std::string satNameStr = omm.at("OBJECT_ID").get<std::string>();
    satNameStr.erase(remove(satNameStr.begin(), satNameStr.end(), '-'), satNameStr.end());
    satNameStr.copy(satName, 8);

    std::string epochStr = omm.at("EPOCH").get<std::string>();
    //Year
    int epochYr = std::stoi(epochStr.substr(0,4));
    //Month
    double epochDays = (double)monthToDaysOfYr(std::stoi(epochStr.substr(5, 2)), epochYr);
    //Day
    epochDays += std::stod(epochStr.substr(8, 2));
    //Hour
    epochDays += (std::stod(epochStr.substr(11, 2)) / 24);
    //Minute
    epochDays += (std::stod(epochStr.substr(14, 2)) / (24 * 60));
    //Second
    epochDays += (std::stod(epochStr.substr(17, 9)) / (24 * 60 * 60));

    loadedSats.push_back(satellite(omm.at("OBJECT_NAME").get<std::string>(),
            omm.at("NORAD_CAT_ID").get<int>(),
            omm.at("CLASSIFICATION_TYPE").get<std::string>()[0],
            satName,
            epochYr,
            epochDays,
            omm.at("BSTAR").get<double>(),
            omm.at("EPHEMERIS_TYPE").get<int>(),
            omm.at("ELEMENT_SET_NO").get<int>(),
            omm.at("INCLINATION").get<double>(),
            omm.at("RA_OF_ASC_NODE").get<double>(),
            omm.at("ECCENTRICITY").get<double>(),
            omm.at("ARG_OF_PERICENTER").get<double>(),
            omm.at("MEAN_ANOMALY").get<double>(),
            omm.at("MEAN_MOTION").get<double>(),
            omm.at("REV_AT_EPOCH").get<int>()));

}

void astroTracker::loadFromTLE(std::string subject_SatName, std::string line1, std::string line2){
    loadedSats.push_back(satellite(subject_SatName, line1, line2));
}

//================================================ Main Functions ====================================

std::vector<std::string> astroTracker::getSatNames(){
    std::vector<std::string> satNames;
    for(int i = 0; i < loadedSats.size(); i++){
        satNames.push_back(loadedSats[i].getSatelliteName());
    }
    return satNames;
}

void astroTracker::printSatElset(std::string subject_SatName){
    // Find subject satellite's satkey in loadedSats vector by satellite name
    satellite subject_Sat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName() == subject_SatName){
            std::cout << "Found satellite: " << subject_SatName << std::endl;
            subject_Sat = loadedSats.at(i);
            break;
        }
    }
    // If the subject satellite isn't in the database print error and return
    if(subject_Sat.getSatelliteName() == "null"){
        std::cout << "Error: Could not find " << subject_SatName << " in satellite database" << std::endl;
        return;
    }

    subject_Sat.printSatElset();    
}

void astroTracker::getSunAndMoonPosTEME(double posSunTEME[3], double posMoonTEME[3], double subject_ds50UTC){
    // Calculate current time, if needed
    if(subject_ds50UTC == -1){
        subject_ds50UTC = getCurrTime_ds50UTC();
    }
    double sunVecMag, moonVecMag;
    CompSunMoonPos(subject_ds50UTC, posSunTEME, &sunVecMag, posMoonTEME, &moonVecMag);
}

void astroTracker::getSunAndMoonPosECR(double posSunECR[3], double posMoonECR[3], double subject_ds50UTC){
    // Calculate current time, if needed
    if(subject_ds50UTC == -1){
        subject_ds50UTC = getCurrTime_ds50UTC();
    }
    double sunVecMag, moonVecMag, posSunTEME[3], posMoonTEME[3], tempLLH[3];
    CompSunMoonPos(subject_ds50UTC, posSunTEME, &sunVecMag, posMoonTEME, &moonVecMag);
    double velSunTEME[3] = {0, 0, 0}, velSunECR[3] = {0, 0, 0};
    ECIToEFGTime(subject_ds50UTC, posSunTEME, velSunTEME, posSunECR, velSunECR);
    double velMoonTEME[3] = {0, 0, 0}, velMoonECR[3] = {0, 0, 0};
    ECIToEFGTime(subject_ds50UTC, posMoonTEME, velMoonTEME, posMoonECR, velMoonECR);
    // std::cout << velMoonECR[0] << std::endl;
    // XYZToLLHTime(subject_ds50UTC, posSunTEME, tempLLH); // nan start
    // LLHToEFGPos(tempLLH, posSunECR);
    // std::cout << posSunTEME[0] << std::endl;
    // std::cout << tempLLH[0] << std::endl;
    // std::cout << posSunECR[0] << std::endl;

    // XYZToLLHTime(subject_ds50UTC, posMoonTEME, tempLLH);
    // LLHToEFGPos(tempLLH, posMoonECR);
}

void astroTracker::getSatPosTEME(double posSatTEME[3], std::string subject_SatName, double subject_ds50UTC){
    // Find subject satellite's satkey in loadedSats vector by satellite name
    satellite subject_Sat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName() == subject_SatName){
            std::cout << "Found satellite: " << subject_SatName << std::endl;
            subject_Sat = loadedSats.at(i);
            break;
        }
    }
    // If the subject satellite isn't in the database print error and return
    if(subject_Sat.getSatelliteName() == "null"){
        std::cout << "Error: Could not find " << subject_SatName << " in satellite database" << std::endl;
        return;
    }
    // Calculate current time, if needed
    if(subject_ds50UTC == -1){
        subject_ds50UTC = getCurrTime_ds50UTC();
    }
    // Propagate satellite to subject_ds50UTC, storing result in posSatTEME
    Sgp4PropDs50UtcPos(subject_Sat.getSatKey(), subject_ds50UTC, posSatTEME);
}

void astroTracker::getSatPosECR(double posSatECR[3], std::string subject_SatName, double subject_ds50UTC){
    // Find subject satellite's satkey in loadedSats vector by satellite name
    satellite subject_Sat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName() == subject_SatName){
            std::cout << "Found satellite: " << subject_SatName << std::endl;
            subject_Sat = loadedSats.at(i);
            break;
        }
    }
    // If the subject satellite isn't in the database print error and return
    if(subject_Sat.getSatelliteName() == "null"){
        std::cout << "Error: Could not find " << subject_SatName << " in satellite database" << std::endl;
        return;
    }
    // Calculate current time, if needed
    if(subject_ds50UTC == -1){
        subject_ds50UTC = getCurrTime_ds50UTC();
    }
    // Declare temp vars for frame conversion
    double posSatTEME[3], posSatEFG[3], velTemp1[3]={0,0,0}, velTemp2[3]={0,0,0};
    // Propagate satellite to subject_ds50UTC and convert position to ECR, storing result in posSatECR
    Sgp4PropDs50UtcPos(subject_Sat.getSatKey(), subject_ds50UTC, posSatTEME);
    ECIToEFGTime(subject_ds50UTC, posSatTEME, velTemp1, posSatEFG, velTemp2);
    EFGToECRTime(subject_ds50UTC, posSatEFG, velTemp2, posSatECR, velTemp1);
}

void astroTracker::printSatLA(std::string satName){
    satellite subjectSat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName()==satName){
            subjectSat = loadedSats.at(i);
        }
    }
    double subject_ds50UTC = getCurrTime_ds50UTC();
    __int64 subjectSatKey = subjectSat.getSatKey();

    // LamodSet1pAll(
    //     1,
    //     subject_ds50UTC,
    //     subject_ds50UTC+300.0,
    //     30,
    //     0,
    //     0,
    //     0,
    //     0,
    //     'O',
    //     0,
    //     45.0
    // );
    // __int64 subject_senSatKey = LamodInitSenSat(005, subjectSatKey);
    // std::cout << subjectSat.getSatelliteName() << " passes overhead "
    //     << LamodGetNumPasses(subject_senSatKey) << "times." 
    //     << std::endl;

    double subject_pos[] = {0,0,0};
    Sgp4PropDs50UtcPos(subjectSatKey, subject_ds50UTC, subject_pos);
}

bool astroTracker::graphSatGroundTrack(std::string subject_SatName, double backwardsHours, double forwardHours){
    // Find subject satellite's satkey in loadedSats vector by satellite name
    __int64 subject_SatKey = -1;
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName() == subject_SatName){
            std::cout << "Found satellite: " << subject_SatName << std::endl;
            subject_SatKey = loadedSats.at(i).getSatKey();
            break;
        }
    }
    // If the subject satellite isn't in the database print error and return false
    if(subject_SatKey == -1){
        std::cout << "Error: Could not find " << subject_SatName << " in satellite database" << std::endl;
        return false;
    }

    double subject_ds50UTC = getCurrTime_ds50UTC(); // Get the current time
    // Create ground track time window
    double startTime = subject_ds50UTC - (backwardsHours/24);
    double endTime = subject_ds50UTC + (forwardHours/24);
    // Create temp arrays to hold satellite position
    double subject_LLH[] = {0,0,0};
    double subject_Pos[] = {0,0,0};

    // matplot++ uses vectors of latitude and longitude for geoplot
    // matplot++'s geoplot won't handle lines that cross the 180 meridian, so vectors of vectors are used to hold coordinates
    std::vector<std::vector<double>> groundTrack_Lat_split, groundTrack_Lon_split;
    // An uninitialized double vector is needed to more easily prime sub-vectors for adding numbers
    std::vector<double> vectorStarter;
    groundTrack_Lat_split.push_back(vectorStarter);
    groundTrack_Lon_split.push_back(vectorStarter);

    double satLon = -1000; // Current longitude of the satellite to mark it on the ground track
    int ind = 0; // Index count for sub-vectors
    for(double pointTime = startTime; pointTime < endTime; pointTime += ((endTime-startTime)/2000.0)){ // More divisions gives a higher track resolution
        Sgp4PropDs50UtcPos(subject_SatKey, pointTime, subject_Pos); // Propagate satellite to pointTime
        XYZToLLHTime(pointTime, subject_Pos, subject_LLH); // Convert propagated position to LatLon

        // SGP4 requires the WGS-72 datum to work, while GPS coordinates now use WGS-84
        // The Astrodynamics Standards libraries don't seem to provide a way to translate between datums, and I have not as of yet figured out how to do it manually
        // So, for now these coordinates will just have to be a bit inaccurate
        // If I do figure out how, the implementation (or function call at least) will go here

        // Adjust longitudes to fit in -180 to 180
        if(subject_LLH[1] > 180){
            while(subject_LLH[1] > 180){
                subject_LLH[1] -= 180;
            }
            subject_LLH[1] -= 180;
        }
        // Find one position close to the satellite's runtime position and split it off into its own sub-vector
        if(((subject_ds50UTC - 0.001) <= pointTime) && (pointTime <= (subject_ds50UTC + 0.001)) && (satLon == -1000)){
            satLon = subject_LLH[1]; // Record runtime satellite longitude
            if(groundTrack_Lon_split.at(ind).size() > 0){ // Only split before runtime position if the propagation time is greater than the start time 
                groundTrack_Lat_split.push_back(vectorStarter);
                groundTrack_Lon_split.push_back(vectorStarter);
                ind++;
            }
            // Push runtime position into the current sub-vector, then add a new sub-vector and start adding to that
            groundTrack_Lat_split.at(ind).push_back(subject_LLH[0]);
            groundTrack_Lon_split.at(ind).push_back(subject_LLH[1]);
            groundTrack_Lat_split.push_back(vectorStarter);
            groundTrack_Lon_split.push_back(vectorStarter);
            ind++;
            continue; // Skip the rest of the loop to avoid adding the runtime position twice
        }
        if(groundTrack_Lon_split.at(ind).size() > 0){ // Do this for all but the first point
            // If the satellite is about to loop over the 180 meridian
            if(((subject_LLH[1] < -90) && (groundTrack_Lon_split.at(ind).back() > 90)) || ((subject_LLH[1] > 90) && (groundTrack_Lon_split.at(ind).back() < -90))){
                std::cout << subject_LLH[1] << " " << groundTrack_Lon_split.at(ind).back() << std::endl; // debug
                // Add a new sub-vector and start adding to that
                groundTrack_Lat_split.push_back(vectorStarter);
                groundTrack_Lon_split.push_back(vectorStarter);
                ind++;
                std::cout << "New sub-vector" << std::endl; // debug
            }
        }
        // Add latitude and longitude to last sub-vector
        groundTrack_Lat_split.at(ind).push_back(subject_LLH[0]);
        groundTrack_Lon_split.at(ind).push_back(subject_LLH[1]);
    }
    std::cout << "Propagation complete" << std::endl; // debug

    std::string groundTrack_Line = "r-"; // Set ground track line color
    for(int i = 0; i < groundTrack_Lon_split.size(); i++){ // For each sub-vector
        if(groundTrack_Lon_split.at(i).at(0) == satLon){ // If it is the sub-vector containing the runtime position
            matplot::geoplot(groundTrack_Lat_split.at(i), groundTrack_Lon_split.at(i), "p-*")->marker_size(10); // Add a marker to the map
            groundTrack_Line = "b-"; // Change the ground track line color
            continue; // Already drew marker, skip to next loop
        }
        matplot::geoplot(groundTrack_Lat_split.at(i), groundTrack_Lon_split.at(i), groundTrack_Line); // Draw ground track
    }
    matplot::geolimits({-90, 90}, {-180, 180}); // Show the whole map
    matplot::wait(); // Make sure the user has time to see the map
    matplot::cla(); // Clear the axes to prevent subsequent calls from drawing on top of the same map
    return true; // Presumably, nothing broke by the time it gets down here
}

//================================================ Utility Functions =================================


double astroTracker::getCurrTime_ds50UTC(){
    time_t rawCurrTime;
    time(&rawCurrTime);
    tm * currTime = gmtime(&rawCurrTime);

    return TimeComps1ToUTC((currTime->tm_year + 1900),
                            (currTime->tm_yday + 1),
                            currTime->tm_hour,
                            currTime->tm_min,
                            (double)currTime->tm_sec);

}

//Returns true if year is a leap year
bool astroTracker::isLeapYear(int year){
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }

//Converts number of months to day number in the year, returns -1 if month other than 1-12
int astroTracker::monthToDaysOfYr(int month, int year){
    switch(month){
        case 1:
            return 0;
        case 2:
            return 31;
        case 3:
            if(isLeapYear(year))
                return 31 + 29;
            else
                return 31 + 28;
        case 4:
            if(isLeapYear(year))
                return 31 + 29 + 31;
            else
                return 31 + 28 + 31;
        case 5:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30;
            else
                return 31 + 28 + 31 + 30;
        case 6:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31;
            else
                return 31 + 28 + 31 + 30 + 31;
        case 7:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30;
            else
                return 31 + 28 + 31 + 30 + 31 + 30;
        case 8:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30 + 31;
            else
                return 31 + 28 + 31 + 30 + 31 + 30 + 31;
        case 9:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
            else
                return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        case 10:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            else
                return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        case 11:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            else
                return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        case 12:
            if(isLeapYear(year))
                return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            else
                return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        default:
            return -1;
    }
}
