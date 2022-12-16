/*
 * File: main.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Main file for astroTrack
 */
//export LD_LIBRARY_PATH=./lib/

#include "astroTracker_menu.hpp"
#include "astroTracker.hpp"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <time.h>

using json = nlohmann::json;

void test();

int main(){
    // test();

    astroTracker_menu main_run("weather.tle");
    main_run.mainMenu();
}


void test(){
    clock_t startTime, finishTime;
    startTime = clock();

    std::string file;
    // file = "omm-weather.json";
    file = "weather.tle";

    astroTracker test(file);

    // test.printSatPosTEME("NOAA 15");
    // std::vector<std::string> satNames = test.getSatNames();
    // for(int i = 0; i < satNames.size(); i++){
    //     std::cout << satNames.at(i) << "." << std::endl;
    // }
    // test.printSatElset("NOAA 15");
    // std::cout << std::endl;
    // test.printSatElset("NOAA 19");
    // std::cout << std::endl;
    // test.printSatElset("noaa 15");
    // std::cout << std::endl;

    test.graphSatGroundTrack("NOAA 15", 2, 2);

    std::cout << test.getSatCount() << std::endl;
    // test.loadFromFile("omm-weather copy.json");
    std::cout << test.getSatCount() << std::endl;

    double moonPos[3];
    test.getMoonPosTEME(moonPos);
    std::cout << moonPos[0] << " " << moonPos[1] << " " << moonPos[2] << std::endl;
    test.getMoonPosECR(moonPos);
    std::cout << moonPos[0] << " " << moonPos[1] << " " << moonPos[2] << std::endl;
    test.getMoonPosLLH(moonPos);
    std::cout << moonPos[0] << " " << moonPos[1] << " " << moonPos[2] << std::endl;

    // double sunPos[3];
    // test.getSunPosTEME(sunPos);
    // std::cout << sunPos[0] << " " << sunPos[1] << " " << sunPos[2] << std::endl;
    // test.getSunPosECR(sunPos);
    // std::cout << sunPos[0] << " " << sunPos[1] << " " << sunPos[2] << std::endl;
    // test.getSunPosLLH(sunPos);
    // std::cout << sunPos[0] << " " << sunPos[1] << " " << sunPos[2] << std::endl;

    // double satPos[3];
    // test.getSatPosTEME(satPos, "NOAA 15");
    // std::cout << satPos[0] << " " << satPos[1] << " " << satPos[2] << std::endl;
    // test.getSatPosECR(satPos, "NOAA 15");
    // std::cout << satPos[0] << " " << satPos[1] << " " << satPos[2] << std::endl;
    // test.getSatPosLLH(satPos, "NOAA 15");
    // std::cout << satPos[0] << " " << satPos[1] << " " << satPos[2] << std::endl;

    // std::cout << test.getTime_ds50UTC("2022Dec12111700.0") << std::endl;

    double location[] = {30, -35, 0};
    std::cout << test.isLocationSunlit(location) << std::endl;

    finishTime = clock();
    std::cout 
    << "Program Run time: " 
    << (double)(finishTime - startTime) / CLOCKS_PER_SEC 
    << " seconds" 
    << std::endl;
}
