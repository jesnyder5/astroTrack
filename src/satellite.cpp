/*
 * File: satellite.cpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 7, 2022
 *
 * Satellite object with attributes corresponding to USSF Astrodynamics Standards satellite objects
 * and related functions
 */

#include "satellite.hpp"
#include <iostream>

#ifndef ASTDYN_STD
#define ASTDYN_STD
// Provided Astrodynamics Standards library wrappers
extern "C" {
#include "DllMainDll_Service.h"
#include "TimeFuncDll_Service.h"
#include "DllMainDll.h"
#include "EnvConstDll.h"
#include "AstroFuncDll.h"
#include "TimeFuncDll.h"
#include "TleDll.h"
#include "Sgp4PropDll.h"
}
#endif

// Load satellite objects from TLE lines and satellite name
satellite::satellite(std::string name, std::string line1, std::string line2){
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

}

// Load all the dlls being used in the program
void satellite::LoadAstroStdDlls(){
    std::cout << "Loading Libraries..." << std::endl;

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

    std::cout << "Libraries loaded successfully" << std::endl;
}

// Initialize all the dlls being used in the program
void satellite::InitAstroStdDlls(){
    std::cout << "Initializing Libraries..." << std::endl;
   
    fAddr apPtr;
    int errCode;

    // Get pointer to the global data (data pointers, function pointers, ...) that's being used among the dlls in the program
    apPtr = DllMainInit();

    // Begin logging
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
    std::cout << std::endl;

    std::cout << "Library initialization successful" << std::endl;
}

// Free all the dlls being used in the program
void satellite::FreeAstroStdDlls(){
    std::cout << "Freeing libraries" << std::endl;

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

    std::cout << "Libraries freed successfully" << std::endl;
}

