/*
 * File: satellite.cpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 28, 2022
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

// ========== Constructors and Destructor ==========

satellite::satellite(){

}  

satellite::satellite(std::string subject_SatName, std::string line1, std::string line2){
    // Record satellite name
    satelliteName = subject_SatName;
    
    // Create and initialize Astrodynamics Standards library binary tree satKey
    satKey = TleAddSatFrLines(&line1[0], &line2[0]);
    Sgp4InitSat(satKey);

    // Record GP TLE fields from TLE library
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

satellite::satellite(std::string subject_SatName,
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
                        int in_revNum){

    // Record satellite name
    satelliteName = subject_SatName;

    // Create and initialize Astrodynamics Standards library binary tree satKey
    satKey = TleAddSatFrFieldsGP(in_satNum,
                in_secClass,
                in_satName,
                in_epochYr,
                in_epochDays,
                in_bstar,
                in_ephType,
                in_elsetNum,
                in_incli,
                in_node,
                in_eccen,
                in_omega,
                in_mnAnomaly,
                in_mnMotion,
                in_revNum
            );
    Sgp4InitSat(satKey);

    // Record GP TLE fields from TLE library
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

satellite::~satellite(){

}

// ========== Main Functions ==========

void satellite::printSatElset(){
    std::cout << "Element Set for " << satelliteName << std::endl;
    std::cout << "satNum: " << satNum << std::endl;
    std::cout << "secClass: " << secClass << std::endl;
    std::cout << "satName: " << satName << std::endl;
    std::cout << "epochYr: " << epochYr << std::endl;
    std::cout << "epochDays: " << epochDays << std::endl;
    std::cout << "bstar: " << bstar << std::endl;
    std::cout << "ephType: " << ephType << std::endl;
    std::cout << "elsetNum: " << elsetNum << std::endl;
    std::cout << "incli: " << incli << std::endl;
    std::cout << "node: " << node << std::endl;
    std::cout << "eccen: " << eccen << std::endl;
    std::cout << "omega: " << omega << std::endl;
    std::cout << "mnAnomaly: " << mnAnomaly << std::endl;
    std::cout << "mnMotion: " << mnMotion << std::endl;
    std::cout << "revNum: " << revNum << std::endl;
}

// Retrieve satellite name string
std::string satellite::getSatelliteName(){
    return satelliteName;
}

__int64 satellite::getSatKey(){
    return satKey;
}
