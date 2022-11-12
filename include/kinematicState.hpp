#ifndef KINEMATICSTATE_H
#define KINEMATICSTATE_H

/*
 * File: kinematicState.hpp
 * Author: Jeremy Snyder
 * Creation: Sep 7, 2022
 *
 * Last Update: Sep 21, 2022
 *
 * Kinematic state object to describe position, velocity, etc. vectors
 */

#include "satellite.hpp"
#include <string>

class kinematicState {
public:
    //Constructors and Destructors
    kinematicState();

    // Construct using current position of satellite object
    kinematicState(satellite sat);

    kinematicState(double x, double y, double z, std::string refFrame);

    ~kinematicState();
    
    // Retrieve vector components relative to the True Equator Mean Equinox (TEME) reference frame
    // [Default frame used by SGP4 and Astrodynamics Standards Libraries]
    double* getTEME();

    // Retrieve vector components relative to an Earth-Centered Earth-Fixed reference frame
    // [Used by ground stations] [aka ECR/ITR]
    double* getECEF();

private:
    // Kinematic state instantaneous time
     double ds50UTC = -1;
    
    // Position vector components
    double xyz[3] = {0,0,0};    // TEME
    double xyz_ECR[3]= {0,0,0}; // ECR

    // Velocity vector components
    double xyz_dot[3] = {0,0,0};    // TEME
    double xyz_dot_ECR[3]= {0,0,0}; // ECR

    // ASTDYN Stds satKey for direct retrieval of vector components
    long satKey = -1;
    

    // Updates vector components using stored satkey
    bool updateECR();

    // Load/Initialize/Free needed dlls
    void LoadAstroStdDlls();
    void InitAstroStdDlls();
    void FreeAstroStdDlls();

};



#endif