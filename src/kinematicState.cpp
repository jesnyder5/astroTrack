/*
 * File: kinematicState.cpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 21, 2022
 *
 * Kinematic state object to describe position, velocity, etc. vectors
 */

#include "kinematicState.hpp"
#include <iostream>
#include <time.h>

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


kinematicState::kinematicState(){

}

kinematicState::kinematicState(satellite sat){

}

kinematicState::kinematicState(double x, double y, double z, std::string refFrame){

}

kinematicState::~kinematicState(){
    FreeAstroStdDlls();
}

// Retrieve vector components relative to the True Equator Mean Equinox (TEME) reference frame
// [Default frame used by SGP4 and Astrodynamics Standards Libraries]
double* kinematicState::getTEME(){
    return xyz; // //////////////Check for write safety
}

// Retrieve vector components relative to an Earth-Centered Earth-Fixed reference frame
// [Used by ground stations] [aka ECR/ITR]
double* kinematicState::getECEF(){
    return xyz_ECR;
}

// Updates vector components using stored satKey
bool kinematicState::updateECR(){
    time_t rawUpdateTime;
    time(&rawUpdateTime);
    tm * updateTime = gmtime(&rawUpdateTime);

    double updateTime_ds50UTC = TimeComps1ToUTC((updateTime->tm_year + 1900),
                                                    updateTime->tm_yday,
                                                    updateTime->tm_hour,
                                                    updateTime->tm_min,
                                                    (double)updateTime->tm_sec);

    double posEFG[3], velEFG[3];

    ECIToEFGTime(updateTime_ds50UTC,
                    xyz,
                    xyz_dot,
                    posEFG,
                    velEFG);
    
    EFGToECRTime(updateTime_ds50UTC,
                    posEFG,
                    velEFG,
                    xyz_ECR,
                    xyz_dot_ECR);
    
    return true;
}

// Load all the dlls being used in the program
void kinematicState::LoadAstroStdDlls(){
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
void kinematicState::InitAstroStdDlls(){
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
void kinematicState::FreeAstroStdDlls(){
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