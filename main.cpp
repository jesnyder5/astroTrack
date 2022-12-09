/*
 * File: main.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Nov 13, 2022
 *
 * [desc]
 */
//export LD_LIBRARY_PATH=./lib/

#include "astroTracker.hpp"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <time.h>

using json = nlohmann::json;

int main(){
    clock_t startTime, finishTime;
    startTime = clock();

    std::string file;
    // file = "omm-weather.json";
    file = "weather.tle";

    astroTracker test(file);

    // double posSunTEME[3], posMoonTEME[3], posSunECR[3], posMoonECR[3];
    // test.getSunAndMoonPosTEME(posSunTEME, posMoonTEME);
    // test.getSunAndMoonPosECR(posSunECR, posMoonECR);
    // std::cout << "Sun Position Vector (TEME): " << posSunTEME[0] << " " << posSunTEME[1] << " " << posSunTEME[2] << std::endl;
    // std::cout << "Sun Position Vector (ECR): " << posSunECR[0] << " " << posSunECR[1] << " " << posSunECR[2] << std::endl;
    // std::cout << "Moon Position Vector (TEME): " << posMoonTEME[0] << " " << posMoonTEME[1] << " " << posMoonTEME[2] << std::endl;
    // std::cout << "Moon Position Vector (ECR): " << posMoonECR[0] << " " << posMoonECR[1] << " " << posMoonECR[2] << std::endl;


    // test.printSatPosTEME("NOAA 15");
    // std::vector<std::string> satNames = test.getSatNames();
    // for(int i = 0; i < satNames.size(); i++){
    //     std::cout << satNames.at(i) << "." << std::endl;
    // }
    test.graphSatGroundTrack("NOAA 15", 2, 2);
    test.printSatElset("NOAA 15");
    std::cout << std::endl;
    test.printSatElset("NOAA 19");
    std::cout << std::endl;
    test.printSatElset("noaa 15");

    finishTime = clock();
    std::cout 
    << "Program Run time: " 
    << (double)(finishTime - startTime) / CLOCKS_PER_SEC 
    << " seconds" 
    << std::endl;
}

