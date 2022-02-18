#ifndef FRAMELIB_HPP
#define FRAMELIB_HPP

/*
 * File: frameLib.hpp
 * Author: Jeremy Snyder
 * Creation: Feb 1, 2022
 *
 * Last Update: Feb 17, 2022
 *
 * Handles reference frame conversion
 */


/*
 * SGP4's True Equator Mean Equinox frame
 * 
 * 
 * 
 */
class teme {
public:
    
    static void rotation_at();
    
private:
    
    // Returns the angle of Greenwich Mean Standard Time 1982 given the JD
    static void theta_GMST1982();

};


/*
 * International Terrestrial Reference System (ITRS)
 * 
 * From SkyField:
 * This is the IAU standard for an Earth-centered Earth-fixed (ECEF)
 * coordinate system, anchored to the Earth’s crust and continents.
 * This reference frame combines three other reference frames: the
 * Earth’s true equator and equinox of date, the Earth’s rotation with
 * respect to the stars, and (if your ``Timescale`` has polar offsets
 * loaded) the polar wobble of the crust with respect to the Earth’s
 * pole of rotation.
 * 
 * 
 * 
 * 
 * 
 */
class itrs {
public:
    
    static void fromTEME();
    
    static void test();
    
private:
    
};



#endif