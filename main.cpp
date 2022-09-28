/*
 * File: main.cpp
 * Author: Jeremy Snyder
 * Creation: Jan 1, 2022
 *
 * Last Update: Aug 31, 2022
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
    file = "omm-weather.json";
    //file = "weather2.tle";

    astroTracker test(file);

    std::vector<std::string> satNames = test.getSatNames();

    for(int i=0; i < satNames.size(); i++){
        std::cout << (i + 1) << ": " << satNames.at(i) << std::endl;
    }

    // std::cout << std::endl << "print first satellite (" << satNames.at(0) << ") TLE fields:" << std::endl;
    // test.printSatTLE(satNames.at(0));

    // std::cout << std::endl << "print second satellite (" << satNames.at(1) << ") TLE fields:" << std::endl;
    // test.printSatTLE(satNames.at(1));

    

    finishTime = clock();
    std::cout 
    << "Program Run time: " 
    << (double)(finishTime - startTime) / CLOCKS_PER_SEC 
    << " seconds" 
    << std::endl;
}

