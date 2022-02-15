/*
 * File: main.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Jan 12, 2022
 *
 * [desc]
 */
//export LD_LIBRARY_PATH=/home/jeremy/projects/astroTrack/lib/

#include "astroTracker.hpp"
#include <iostream>
#include <fstream>
#include <json.hpp>
#include <time.h>

using json = nlohmann::json;

int main(){

    clock_t startTime, finishTime;
    startTime = clock();

    //astroTracker test;
    //astroTracker test2(j);
    std::string file;
    file = "omm-weather.json";
    //file = "weather2.tle";

    astroTracker test(file);

    std::vector<std::string> satNames = test.getSatNames();

    for(int i=0; i < satNames.size(); i++){
        std::cout << (i + 1) << ": " << satNames.at(i) << std::endl;
    }

    finishTime = clock();
    std::cout 
    << "Program Run time: " 
    << (double)(finishTime - startTime) / CLOCKS_PER_SEC 
    << " seconds" 
    << std::endl;
}

