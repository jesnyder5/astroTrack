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

// #include "SensorDll.h"
// #include "SensorDll_Service.h"
// #include "ObsDll.h"
// #include "ObsDll_Service.h"
// #include "LamodDll.h"
// #include "LamodDll_Service.h"
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

// Construct using json object in OMM format
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

// Construct using tle lines and name
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

// Construct using json or tle files
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

    // LoadSensorDll();

    // LoadObsDll();

    // LoadLamodDll(); // ITAR restrictions, can't use

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
    strftime(logMsg, 128,"astroTracker Start: %c", localtime(&rawtime));
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

    // errCode = SensorInit(apPtr);
    // if (errCode != 0)
    //     ShowMsgAndTerminate();

    // errCode = ObsInit(apPtr);
    // if (errCode != 0)
    //     ShowMsgAndTerminate();

    // errCode = LamodInit(apPtr);
    // if (errCode != 0)
    //     ShowMsgAndTerminate();
    
    // Temp call until user input implemented
    // sensorInit();

    // Version Info
    /*
    std::cout << std::endl;
    char DllInfo[INFOSTRLEN];
    DllMainGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);

    EnvGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);

    TimeFuncGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);

    AstroFuncGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);

    TleGetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);

    Sgp4GetInfo(DllInfo);
    DllInfo[INFOSTRLEN-1] = 0;
    printf("%s\n", DllInfo);
    std::cout << std::endl;
    */
}

// Free all the dlls being used in the program
void astroTracker::FreeAstroStdDlls(){
    // Library wrappers output loading messages to STDOUT. This will redirect to somewhere else
    // POSIX centric solution
    // #ifndef __Win32
    // fflush(stdout);
    // int stdout_fd = dup(STDOUT_FILENO); // Copy STDOUT info to temp var
    // freopen("/dev/null", "w", stdout); // Reopen STDOUT to write to /dev/null for now. 
    // #endif

    // // Free LaMod dll
    // FreeLamodDll();

    // // Free Ops dll
    // FreeObsDll();

    // // Free Sensor dll
    // FreeSensorDll();

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
    strftime(logMsg, 128,"astroTracker Stop: %c", localtime(&rawtime));
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
/*
bool astroTracker::sensorInit(){
    // Get ECR location
    double metricLLH[3] = {39.05, -76.65, 0.04}, // TEST CASE
           posEFG[3] = {0,0,0},
           posECR[3] = {0,0,0},
           ds50UTCcurr;

    // Swap Earth model for GPS (WGS72 -> WGS84)
    EnvSetGeoIdx(84);

    // Convert Geodetic coordinates to ECR (via EFG)
    LLHToEFGPos(metricLLH, posEFG);
    
    // Calculate current time in ds50UT1
    std::time_t t = std::time(0);
    tm* now = std::localtime(&t);
    // Replace relevant tm fields with GPS time?
    ds50UTCcurr = TimeComps2ToUTC(
            now->tm_year,
            now->tm_mon,
            now->tm_mday,
            now->tm_hour,
            now->tm_min,
            now->tm_sec
    );

    EFGToECRTime(ds50UTCcurr, posEFG, {0}, posECR, {0});

    // Swap Earth model back to WGS72 for SGP4 propagation
    EnvSetGeoIdx(72);
    
    char senDesc[] = "astroTracker User Loc";

    // Create sensor
    SensorSetLocAll(
        005, // senKey
        metricLLH[0], // astroLat (not sure how to do astronomical coordinate conversion)
        metricLLH[1], // astroLon
        posECR, // sensor ECR position
        senDesc, // sensor description [24]
        0, // 0 for ground-based
        'U' // unclassified
    );
    return true;
}
*/
//================================================ Satellite Loading Functions ============================

// Load satellite objects from either .json or .tle file
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

// Load satellite objects from OMM json object
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

// Load satellite objects from TLE lines and satellite name
void astroTracker::loadFromTLE(std::string name, std::string line1, std::string line2){
    loadedSats.push_back(satellite(name, line1, line2));
}

//================================================ Main Functions ====================================

std::vector<std::string> astroTracker::getSatNames(){
    std::vector<std::string> satNames;
    for(int i = 0; i < loadedSats.size(); i++){
        satNames.push_back(loadedSats[i].getSatelliteName());
    }
    return satNames;
}

void astroTracker::printSatTLE(std::string name){
/*
    loadedSats.

    std::cout << std::endl;
    std::cout << "satNum: " << sats[name].get<nlohmann::json>()["Norad_ID"].get<int>() << std::endl;
    std::cout << "secClass: " << sats[name].get<nlohmann::json>()["Security_Class"].get<char>() << std::endl;
    std::cout << "satName: " << sats[name].get<nlohmann::json>()["Intl_Des"].get<std::string>() << std::endl;
    std::cout << "epochYr: " << sats[name].get<nlohmann::json>()["Epoch_Year"].get<int>() << std::endl;
    std::cout << "epochDays: " << sats[name].get<nlohmann::json>()["Epoch_Days"].get<double>() << std::endl;
    std::cout << "bstar: " << sats[name].get<nlohmann::json>()["Bstar"].get<double>() << std::endl;
    std::cout << "ephType: " << sats[name].get<nlohmann::json>()["Eph_Type"].get<int>() << std::endl;
    std::cout << "elsetNum: " << sats[name].get<nlohmann::json>()["Element_Set_Num"].get<int>() << std::endl;
    std::cout << "incli: " << sats[name].get<nlohmann::json>()["Inclination"].get<double>() << std::endl;
    std::cout << "node: " << sats[name].get<nlohmann::json>()["RA_Node"].get<double>() << std::endl;
    std::cout << "eccen: " << sats[name].get<nlohmann::json>()["Eccentricity"].get<double>() << std::endl;
    std::cout << "omega: " << sats[name].get<nlohmann::json>()["Arg_Perigee"].get<double>() << std::endl;
    std::cout << "mnAnomaly: " << sats[name].get<nlohmann::json>()["Mean_Anomaly"].get<double>() << std::endl;
    std::cout << "mnMotion: " << sats[name].get<nlohmann::json>()["Mean_Motion"].get<double>() << std::endl;
    std::cout << "revNum: " << sats[name].get<nlohmann::json>()["Revolution_Num"].get<int>() << std::endl;
    std::cout << std::endl;
*/
}

//  The following function has at least some of the logic to convert current WGS84 GPS coordinates
//  I don't remember writing it, but it was in GitHub's version of this file, so I guess I did
//  Either way, it appears to essentially be the logic I only just came up with to solve the WGS84-WGS72 conversion issue
//  ****Review and update before implementing
/*
// Convert latitude, longitude, and height retrived from GPS to TEME vector
void astroTracker::getGPSposTEME(double posTEME[3]){
    double thetaG,
           metricLLH[3] = {39.05, -76.65, 0.04}, // TEST CASE
           ds50UT1;
    
    // Zero out current vector
    posTEME[0] = 0;
    posTEME[1] = 0;
    posTEME[2] = 0;

    // Swap Earth model for GPS (WGS72 -> WGS84)
    // EnvSetGeoIdx(84);

    // Retrieve GPS info (converting to Metric if needed) -> metricLLH
    
    // === Calculate Greenwich Sidereal (thetaG) ===
    // Calculate current time in ds50UT1
    std::time_t t = std::time(0);
    tm* now = std::localtime(&t);
    // Replace relevant tm fields with GPS time?
    ds50UT1 = UTCToUT1(
        TimeComps2ToUTC(
            now->tm_year,
            now->tm_mon,
            now->tm_mday,
            now->tm_hour,
            now->tm_min,
            now->tm_sec
        )
    );

    thetaG = ThetaGrnwch(ds50UT1, EnvGetFkPtr());

    // === Convert LLH to ECI position vector (TEME of Date in km)
    LLHToXYZ(thetaG, metricLLH, posTEME);

    // Convert position vector to something independent of Earth model
    // Swap Earth model back to WGS72 for SGP4 propagation
    // EnvSetGeoIdx(72);
    // Convert position vector back to TEME

    // === Convert posTEME to unit vector ===
    // (Is this even needed?)
    double mag = sqrt(
        (
            (posTEME[0]*posTEME[0])+
            (posTEME[1]*posTEME[1])+
            (posTEME[2]*posTEME[2])
        )
    );

    posTEME[0] = (posTEME[0] / mag);
    posTEME[1] = (posTEME[1] / mag);
    posTEME[2] = (posTEME[2] / mag);

}
*/

void astroTracker::getSunAndMoonPosTEME(double posSunTEME[3], double posMoonTEME[3], double posTime_ds50UTC){
    if(posTime_ds50UTC == -1){
        posTime_ds50UTC = getCurrTime_ds50UTC();
    }
    double sunVecMag, moonVecMag;
    CompSunMoonPos(posTime_ds50UTC, posSunTEME, &sunVecMag, posMoonTEME, &moonVecMag);
}

void astroTracker::getSunAndMoonPosECR(double posSunECR[3], double posMoonECR[3], double posTime_ds50UTC){
    if(posTime_ds50UTC == -1){
        posTime_ds50UTC = getCurrTime_ds50UTC();
    }
    double sunVecMag, moonVecMag, posSunTEME[3], posMoonTEME[3], tempLLH[3];
    CompSunMoonPos(posTime_ds50UTC, posSunTEME, &sunVecMag, posMoonTEME, &moonVecMag);
    double velSunTEME[3] = {0, 0, 0}, velSunECR[3] = {0, 0, 0};
    ECIToEFGTime(posTime_ds50UTC, posSunTEME, velSunTEME, posSunECR, velSunECR);
    double velMoonTEME[3] = {0, 0, 0}, velMoonECR[3] = {0, 0, 0};
    ECIToEFGTime(posTime_ds50UTC, posMoonTEME, velMoonTEME, posMoonECR, velMoonECR);
    // std::cout << velMoonECR[0] << std::endl;
    // XYZToLLHTime(posTime_ds50UTC, posSunTEME, tempLLH); // nan start
    // LLHToEFGPos(tempLLH, posSunECR);
    // std::cout << posSunTEME[0] << std::endl;
    // std::cout << tempLLH[0] << std::endl;
    // std::cout << posSunECR[0] << std::endl;

    // XYZToLLHTime(posTime_ds50UTC, posMoonTEME, tempLLH);
    // LLHToEFGPos(tempLLH, posMoonECR);
}

void astroTracker::printSatPosTEME(std::string satName){
    satellite subjectSat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName()==satName){
            subjectSat = loadedSats.at(i);
        }
    }
    double subject_ds50UTC = getCurrTime_ds50UTC();
    __int64 subjectSatKey = subjectSat.getSatKey();
    double subjectPosTEME[3];
    Sgp4PropDs50UtcPos(subjectSatKey, subject_ds50UTC, subjectPosTEME);
    std::cout << subjectSat.getSatelliteName() << " is at: (" 
    << subjectPosTEME[0] << ", " 
    << subjectPosTEME[1] << ", " 
    << subjectPosTEME[2] << ")"
    << std::endl;
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

void astroTracker::graphSatGroundtrack(std::string satName, double backwardsHours, double forwardHours){
    satellite subjectSat = satellite();
    for(int i = 0; i < loadedSats.size(); i++){
        if(loadedSats.at(i).getSatelliteName() == satName){
            std::cout << "Found satellite: " << satName << std::endl;
            subjectSat = loadedSats.at(i);
            break;
        }
    }
    double subject_ds50UTC = getCurrTime_ds50UTC();
    __int64 subjectSatKey = subjectSat.getSatKey();

    double startTime = subject_ds50UTC - (backwardsHours/24);
    double endTime = subject_ds50UTC + (forwardHours/24);
    double subject_LLH[] = {0,0,0};
    double subject_Pos[] = {0,0,0};
    std::vector<double> groundtrack_Lat, groundtrack_Lon, groundtrack_Times;
    std::vector<std::vector<double>> groundtrack_Lat_split, groundtrack_Lon_split;
    groundtrack_Lat_split.push_back(groundtrack_Lat);
    groundtrack_Lon_split.push_back(groundtrack_Lon);

    for(double i = startTime; i < endTime; i += ((endTime-startTime)/2000)){
        Sgp4PropDs50UtcPos(subjectSatKey, i, subject_Pos);
        // EnvSetGeoIdx(84); // Set GeoId for modern GPS coords
        XYZToLLHTime(i, subject_Pos, subject_LLH);
        // EnvSetGeoIdx(72); // Reset GeoId to default for SGP4
        groundtrack_Lat.push_back(subject_LLH[0]);
        groundtrack_Lon.push_back(subject_LLH[1]);
        groundtrack_Times.push_back(i);
    }

    bool satLocSplit = true;
    int ind = 0;
    for(int i = 0; i < groundtrack_Lon.size(); i++){
        if(groundtrack_Lon.at(i) > 180){
            while(groundtrack_Lon.at(i) > 180){
                groundtrack_Lon.at(i) -= 180;
            }
            groundtrack_Lon.at(i) -= 180;
        }
        if(((subject_ds50UTC - 0.001) <= groundtrack_Times.at(i)) && (groundtrack_Times.at(i) <= (subject_ds50UTC + 0.001)) && satLocSplit){
            subject_LLH[1] = groundtrack_Lon.at(i);
            satLocSplit = false;
            std::vector<double> temp;
            if(i > 0){
                groundtrack_Lat_split.push_back(temp);
                groundtrack_Lon_split.push_back(temp);
                ind++;
            }
            groundtrack_Lat_split.at(ind).push_back(groundtrack_Lat.at(i));
            groundtrack_Lon_split.at(ind).push_back(groundtrack_Lon.at(i));
            groundtrack_Lat_split.push_back(temp);
            groundtrack_Lon_split.push_back(temp);
            ind++;
            continue;
        }
        if(i > 0){
            if(((groundtrack_Lon.at(i) < -90) && (groundtrack_Lon.at(i-1) > 90)) || ((groundtrack_Lon.at(i) > 90) && (groundtrack_Lon.at(i-1) < -90))){
                std::cout << groundtrack_Lon.at(i) << " " << groundtrack_Lon.at(i-1) << std::endl;
                std::vector<double> temp;
                groundtrack_Lat_split.push_back(temp);
                groundtrack_Lon_split.push_back(temp);
                ind++;
            }
        }
        groundtrack_Lat_split.at(ind).push_back(groundtrack_Lat.at(i));
        groundtrack_Lon_split.at(ind).push_back(groundtrack_Lon.at(i));
    }

    std::string groundTrack_Line = "r-";
    for(int i = 0; i < groundtrack_Lon_split.size(); i++){
        if(groundtrack_Lon_split.at(i).at(0) == subject_LLH[1]){
            matplot::geoplot(groundtrack_Lat_split.at(i), groundtrack_Lon_split.at(i), "p-*")->marker_size(10);
            groundTrack_Line = "b-";
            continue;
        }
        matplot::geoplot(groundtrack_Lat_split.at(i), groundtrack_Lon_split.at(i), groundTrack_Line);
    }
    matplot::geolimits({-90, 90}, {-180, 180});
    matplot::wait();
    matplot::cla();
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
