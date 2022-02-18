/*
 * File: astroTracker.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Feb 17, 2022
 *
 * Uses USSF SGP4 to track objects from an Earth-fixed terrestrial reference frame.
 */

#include "astroTracker.hpp"
#include "frameLib.hpp"
#include <iostream>
#include <fstream>
#include "stdlib.h"

extern "C" {
#include "services/DllMainDll_Service.h"
#include "services/TimeFuncDll_Service.h"
#include "wrappers/DllMainDll.h"
#include "wrappers/EnvConstDll.h"
#include "wrappers/AstroFuncDll.h"
#include "wrappers/TimeFuncDll.h"
#include "wrappers/TleDll.h"
#include "wrappers/Sgp4PropDll.h"
}


astroTracker::astroTracker(){
    std::cout << "constructor" << std::endl;
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    char logMsg[] = "End of standard constructor";
    LogMessage(logMsg);
}

// Construct using json object in OMM format
astroTracker::astroTracker(json omm){
    std::cout << "json constructor" << std::endl;
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
    std::cout << "tle constructor" << std::endl;
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
    std::cout << "file constructor" << std::endl;
    // Load dlls
    LoadAstroStdDlls();
    // Initialize dlls
    InitAstroStdDlls();

    loadFromFile(FILENAME);
    std::cout << "Successfully loaded " << TleGetCount() << " satellites" << std::endl;

    char logMsg[] = "End of file-based constructor";
    LogMessage(logMsg);
}

astroTracker::~astroTracker(){
    std::cout << "destructor" << std::endl;
    // Free loaded AstroStd dlls
    FreeAstroStdDlls();
}

// Load all the dlls being used in the program
void astroTracker::LoadAstroStdDlls(){

    // TEST FUNCTION, REMOVE LATER
    itrs::test();

    std::cout << "LoadAstroStdDlls" << std::endl;

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
}

// Initialize all the dlls being used in the program
void astroTracker::InitAstroStdDlls(){
    std::cout << "InitAstroStdDlls" << std::endl;
   
    fAddr apPtr;
    int errCode;

    // Get pointer to the global data (data pointers, function pointers, ...) that's being used among the dlls in the program
    apPtr = DllMainInit();

    char LOGFILE[] = "sgp4_log.txt";
    OpenLogFile(LOGFILE);

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

    std::cout << "Init successful" << std::endl;
}

// Free all the dlls being used in the program
void astroTracker::FreeAstroStdDlls(){
    std::cout << "FreeAstroStdDlls" << std::endl;
   
    CloseLogFile();

    // Free MainDll dll
    FreeDllMainDll();

    // Free EnvConst dll
    FreeEnvConstDll();

    // Free AstroFunc dll
    FreeAstroFuncDll();

    // Free TimeFunc dll
    FreeTimeFuncDll();

    // Free Tle dll
    FreeTleDll();

    // Free Sgp4Prop dll
    FreeSgp4PropDll();
}

//================================================ File Loading Functions ============================

// Load satellite objects from either .json or .tle file
void astroTracker::loadFromFile(std::string FILENAME){
    if(FILENAME.substr(FILENAME.length()-5) == ".json"){
        std::cout << "Loading json file" << std::endl;
        std::ifstream jsonFile(FILENAME);
        json j = json::parse(jsonFile);

        for(int i = 0; i < j.size()-1; i++){
            loadFromJson(j[i]);
        }

    }
    else if(FILENAME.substr(FILENAME.length()-4) == ".tle"){
        //TleLoadFile(&FILENAME[0]);
        std::cout << "Loading TLE file" << std::endl;

        std::ifstream tleFile(FILENAME);
        std::string name, line1, line2;
        while(tleFile.good()){
            name, line1, line2 = "";
            getline(tleFile, name);
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
    satNum = omm["NORAD_CAT_ID"].get<int>();
    secClass = omm["CLASSIFICATION_TYPE"].get<std::string>()[0]; //convert to string then pull first character to get char

    std::string satNameStr = omm["OBJECT_ID"].get<std::string>();
    satNameStr.erase(remove(satNameStr.begin(), satNameStr.end(), '-'), satNameStr.end());
    satNameStr.copy(satName, 8);


    std::string epochStr = omm["EPOCH"].get<std::string>();
    //Year
    epochYr = std::stoi(epochStr.substr(0,4));
    //Month
    epochDays = (double)monthToDaysOfYr(std::stoi(epochStr.substr(5, 2)), epochYr);
    //Day
    epochDays += std::stod(epochStr.substr(8, 2));
    //Hour
    epochDays += (std::stod(epochStr.substr(11, 2)) / 24);
    //Minute
    epochDays += (std::stod(epochStr.substr(14, 2)) / (24 * 60));
    //Second
    epochDays += (std::stod(epochStr.substr(17, 9)) / (24 * 60 * 60));


    bstar = omm["BSTAR"].get<double>();
    ephType = omm["EPHEMERIS_TYPE"].get<int>();
    elsetNum = omm["ELEMENT_SET_NO"].get<int>();
    incli = omm["INCLINATION"].get<double>();
    node = omm["RA_OF_ASC_NODE"].get<double>();
    eccen = omm["ECCENTRICITY"].get<double>();
    omega = omm["ARG_OF_PERICENTER"].get<double>();
    mnAnomaly = omm["MEAN_ANOMALY"].get<double>();
    mnMotion = omm["MEAN_MOTION"].get<double>();
    revNum = omm["REV_AT_EPOCH"].get<int>();


    satKey = TleAddSatFrFieldsGP(
        satNum,
        secClass,
        satName,
        epochYr,
        epochDays,
        bstar,
        ephType,
        elsetNum,
        incli,
        node,
        eccen,
        omega,
        mnAnomaly,
        mnMotion,
        revNum
    );
    Sgp4InitSat(satKey);

    sats[omm["OBJECT_NAME"].get<std::string>()] = {
        {"SatKey", satKey},
        {"Norad_ID", satNum},
        {"Security_Class", secClass},
        {"Intl_Des", satName},
        {"Epoch_Year", epochYr},
        {"Epoch_Days", epochDays},
        {"Bstar", bstar},
        {"Eph_Type", ephType},
        {"Element_Set_Num", elsetNum},
        {"Inclination", incli},
        {"RA_Node", node},
        {"Eccentricity", eccen},
        {"Arg_Perigee", omega},
        {"Mean_Anomaly", mnAnomaly},
        {"Mean_Motion", mnMotion},
        {"Revolution_Num", revNum}
    };

    satNames.push_back(omm["OBJECT_NAME"].get<std::string>());

}

// Load satellite objects from TLE lines and satellite name
void astroTracker::loadFromTLE(std::string name, std::string line1, std::string line2){
    satKey = TleAddSatFrLines(&line1[0], &line2[0]);
    Sgp4InitSat(satKey);

    TleGetAllFieldsGP(
        satKey,
        &satNum,
        &secClass,
        satName,
        &epochYr,
        &epochDays,
        &bstar,
        &ephType,
        &elsetNum,
        &incli,
        &node,
        &eccen,
        &omega,
        &mnAnomaly,
        &mnMotion,
        &revNum
    );

    sats[name] = {
        {"SatKey", satKey},
        {"Norad_ID", satNum},
        {"Security_Class", secClass},
        {"Intl_Des", satName},
        {"Epoch_Year", epochYr},
        {"Epoch_Days", epochDays},
        {"Bstar", bstar},
        {"Eph_Type", ephType},
        {"Element_Set_Num", elsetNum},
        {"Inclination", incli},
        {"RA_Node", node},
        {"Eccentricity", eccen},
        {"Arg_Perigee", omega},
        {"Mean_Anomaly", mnAnomaly},
        {"Mean_Motion", mnMotion},
        {"Revolution_Num", revNum}
    };

    satNames.push_back(name);

}

//================================================ Main Functions ====================================

std::vector<std::string> astroTracker::getSatNames(){
    return satNames;
}

//================================================ Utility Functions =================================

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