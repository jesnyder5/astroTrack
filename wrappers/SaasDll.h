// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef SAASDLL_H
#define SAASDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define SaasDll "Saas.dll"
#elif __APPLE__
  #define SaasDll "libsaas.dylib"
#else
  #define SaasDll "libsaas.so"
#endif


// Initializes Saas dll for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Saas.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSaasInit)(__int64 apPtr);


// Returns information about the current version of Saas.dll. The information is placed in the
// string parameter passed-in
// infoStr            A string to hold information about the Saas.dll (out-Character[128])
typedef void (STDCALL *fnPtrSaasGetInfo)(char infoStr[128]);


// SaasGetResults executes SAAS (Satellite Attack Assessment Software) also known as DA ASAT
//   (Direct Ascent Anti-Satellite). 
// 
// 
// SAAS software description:
// 
//   SaasGetResults executes SAAS (Satellite Attack Assessment Software) also known as DA ASAT
//   (Direct Ascent Anti-Satellite). Developed by HQ AFSPC, SAAS assesses attack opportunities
//   for a direct ascent ASAT attack, similar to F-15 ASAT of the 1980's.  By its use of SGP4
//   propagation, SAAS is designed as a high-speed screening tool to identify potential target
//   objects in vulnerable orbits relative to the specified missile site/capability; however it
//   should not be considered a precision analysis model.
// 
// 
// SAAS algorithm:
// 
//   SAAS computes a ring of potential intercept points around a launch site.  The size of the
//   ring (also known as 'the kill ring') is based on the altitude limit and missile profile
//   specified for the direct ascent booster.  Each target altitude has a unique kill ring with
//   two intercept points, defined as 'pierce/entry' and exit.  The ring of potential intercept
//   points span over 360 degrees azimuth above the launch site.  The ring of intercept points
//   is circumscribed by a cone looking up from the launch site.  Target orbits are flown
//   (propagated by SGP4) over a specified period of interest and penetrations of the launch site
//   cone determine a viable intercept passes.  The time of the cone penetration, and/or cone
//   exit, are the 'intercept times'.  (Note that as the target altitude decreases, the intercept
//   point moves farther down-range from the launch site; then it moves up-range after the
//   specified missile max range is reached.) The azimuth from the launch site to the cone
//   penetration point is the launch azimuth.  Lastly, the launch time is determined as the cone
//   penetration time minus the missile time-of-flight to the target.
// 
// 
// INPUTS include:
// 
// 
//   (a) a set of target input SGP4 two-line element sets (TLEs)
//   (b) coefficient-based missile profile used for the direct ascent attack trajectory
//   (c) missile profile limits including min and max height, maximum sun angle, and maximum
//        attack angle
//   (d) ground missile location(s) including N. latitude, E. longitude, and height for one or
//        more test sites
//   (e) a specified evaluation period of interest for assessment
// 
// 
// 
// OUTPUTS include:
//   (a) attack launch time, launch azimuth, and intercept time, for each viable target pass over
//        a launch site within the specified period of interest
// 
// Order of elements in the input xa_msl array:
// 
// 
// Index
// Index Interpretation
//    
//   0 missile profile minimum height limit [km]
//   1 missile profile maximum height limit [km]
//   2 maximum allowed solar aspect angle [deg], pass qualifies 
//   3 maximum allowed missile attack angle [deg], pass qualifies only 
//   4 rejection flag*: -1=reject negative; 0=reject neither negative nor positive; 1=reject positive. 
//   5 missile profile time coefficient for the X^2 term
//   6 missile profile time coefficient for the X term
//   7 missile profile time constant for the C term
//   8 missile profile range coefficient for the X^2 term
//   9 missile profile range coefficient for the X term
//  10 missile profile range constant for the C term
//  11-31 unused at this time
//    
//  (*) The missile rejection flag designation is used by SAAS to check for sign of the desired
//      attack angles in the results.  It evaluates the sign (+ or -) of the computed attack
//      angle vs. the maximum allowed attack angle.  For example if set to -1, only positive
//      attack angles less than the max attack angle will be returned.  If set to 0, either a
//      positive or negative computed attack angle is acceptable as long as long it is less
//      than the max allowed attack angle.  If set to 1, only negative attack angles less than
//      the maximum will be accepted and returned.
// 
// Order of elements in the input xa_ls array:   
// 
// 
// Index
// Index Interpretation
//    
//  0 launch test site's latitude (+North, -South)
//  1 launch test site longitude (+East, -West)
//  2 launch test site local height above Earth average equatorial radius (meters). 
//  3-7 unused at this time
//    
// 
// Order of elements in the input xa_saasRun array:
// 
// 
// Index
// Index Interpretation
//    
//  0 Maximum number of penetration points allowed. 
//  1 SAAS assessment period-of-interest (POI) start time in fractional days since 1950, UTC
//  2 SAAS assessment period-of-interest (POI) stop time in fractional days since 1950, UTC. 
// 								 Note: if a stop time is not specified, it is defaulted by SAAS to 1 day after the specified start
// 								 time
//  3 Specified half-angle of attack cone, where if set to 0, SAAS will automatically determine the attack cone half angle. 
//   								 Note:  if a input cone angle is > 90 degrees, it is defaulted by SAAS to 90
//   								 degrees
//  4-7 unused at this time
//    
// 
// Order of elements in the returned in the first dimension of xa_satPen array (second array
//  dimension allows similar same results Elements for other viable penetration solutions at
//  different times during the assessment period of interest):
// 
// 
// Index
// Index Interpretation
//    
//  0 impact time in fractional days since 1950, UTC
//  1 missile launch time in fractional days since 1950, UTC
//  2 satellite penetration azimuth [deg]
//  3 satellite penetration elevation [deg]
//  4 satellite penetration range [km]
//  5 satellite penetration range rate [km/s]
//  6 satellite penetration solar aspect angle [deg]
//  7 satellite penetration attack angle [deg]
//  8 satellite height at penetration [km] 
//  9 ring penetration indicator:  0 = impact time is an 'entry' time; 1 = ring penetration is an 'exit'
// time
//  10-15 unused at this time
//    
// 
// Order of elements in the output xa_Ret array:
// 
// 
// Index
// Index Interpretation
//    
//  0 number of potential viable attack penetrations (opportunities) identified vs. the target set within the
// POI
//  1-15 unused at this time
//    
// 
// xa_saasRet(16) - other saas output:
// 
// 
// Index
// Index Interpretation
//    
//  0  number of actual satellite penetrations found
//  1  satellite apogee height (km)
//  2  satellite perigee height (km)
//  3  autocone minimum cone half angle (deg)
//  4  autocone maximum cone half angle (deg)
//  5-15  not used at this time
//    
// satKey             The satellite's unique key (in-Long)
// xa_saasrun         run parameters (in-Double[8])
// xa_msl             missile profile data (in-Double[32])
// xa_ls              launch site data (in-Double[8])
// xa_satPen          array that stores data of satellite penetrations (out-Double[*, 16])
// xa_saasRet         array that stores other SAAS output (out-Double[16])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSaasGetResults)(__int64 satKey, double xa_saasrun[8], double xa_msl[32], double xa_ls[8], double xa_satPen[][16], double xa_saasRet[16]);


// Computes auto cone size based on satellite height and missile profile      
// satHeight          satelite height (km) (in-Double)
// xa_msl             missile profile data (in-Double[32])
// returns computed auto cone size (deg)
typedef double (STDCALL *fnPtrSaasAutoConeSize)(double satHeight, double xa_msl[32]);


// Computes missile time of flight based on satellite height and missile profile  
// satHeight          satellite height (km) (in-Double)
// xa_msl             missile profile data (in-Double[32])
// returns computed missile flight time (sec)
typedef double (STDCALL *fnPtrSaasMissileFlightTime)(double satHeight, double xa_msl[32]);


// Computes launch orbital plane (inclination and node) based on the launch data
// xa_lnch            The input launch data (see XA_LNCH_ for array arrangement) (in-Double[8])
// incli              The output planer's inclination (deg) (out-Double)
// node               The output planer's node (deg) (out-Double)
typedef void (STDCALL *fnPtrComputeLnchOrbPlane)(double xa_lnch[8], double* incli, double* node);


// Compares a satellite elset against a new launch to find planer intersection time and associated data
// satKey             The satellite's unique key (in-Long)
// xa_plnr            The input new launch and time of flight data (in-Double[16])
// xa_intxn           The output planer intersection data (out-Double[16])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrFindPlanerIntersection)(__int64 satKey, double xa_plnr[16], double xa_intxn[16]);
  
  //*******************************************************************************
  
  // MISSILE PROFILE
  static const int     
     XA_MSL_MINHGT  =  0,     // MISSILE PROFILE'S MINIMUM HEIGHT LIMIT (KM)
     XA_MSL_MAXHGT  =  1,     // MISSILE PROFILE'S MAXIMUM HEIGHT LIMIT (KM)
     XA_MSL_MAXSA   =  2,     // MAXIMUM ALLOWED SOLAR ASPECT ANGLE (DEG)
     XA_MSL_ANGMAX  =  3,     // MAXIMUM ALLOWED MISSILE ATTACK ANGLE (DEG)
     XA_MSL_REJFLG  =  4,     // REJECTION FLAG (-1: REJECT NEGATIVE, 0: REJECT NEG AND POS, 1: REJECT POS) 
     XA_MSL_TIMCOE1 =  5,     // MISSILE TRAJECTORY TIME COEFFICIENT FOR THE *X**2 TERM [SEC]
     XA_MSL_TIMCOE2 =  6,     // MISSILE TRAJECTORY TIME COEFFICIENT FOR THE *X TERM [SEC]
     XA_MSL_TIMCOE3 =  7,     // MISSILE TRAJECTORY TIME CONSTANT FOR THE C TERM [SEC] 
     XA_MSL_RNGCOE1 =  8,     // MISSILE TRAJECTORY RANGE COEFFICIENT *X**2 TERM [KM]
     XA_MSL_RNGCOE2 =  9,     // MISSILE TRAJECTORY RANGE COEFFICIENT *X TERM [KM]
     XA_MSL_RNGCOE3 = 10,     // MISSILE TRAJECTORY RANGE CONSTANT FOR THE C TERM [KM]
   
     XA_MSL_SIZE    = 32;
  
  //*******************************************************************************
     
  // LAUNCH SITE LOCATION
  static const int     
     XA_LS_LAT     = 0,     // LAUNCH SITE'S LATITUDE (DEG)  (+N) (-S)
     XA_LS_LON     = 1,     // LAUNCH SITE'S LONGITUDE (DEG) (+E) (-W)
     XA_LS_HEIGHT  = 2,     // LAUNCH SITE'S HEIGHT(M)
     
     XA_LS_SIZE    = 8;
     
  //*******************************************************************************   
     
  // SAAS RUN PARAMETERS
  static const int     
     XA_SAASRUN_MAXPENS  = 0,     // MAXIMUM NUMBER OF PENETRATION POINTS THAT ARE ALLOWED
     XA_SAASRUN_START    = 1,     // SAAS START TIME IN DAYS SINCE 1950, UTC
     XA_SAASRUN_STOP     = 2,     // SAAS STOP TIME IN DAYS SINCE 1950, UTC
     XA_SAASRUN_HALFCONE = 3,     // HALF ANGLE OF ATTACK CONE (0=AUTO)
     
     XA_SAASRUN_SIZE     = 8;      
     
  //*******************************************************************************      
  
  // SATELLITE PENETRATION DATA
  static const int     
     XA_SATPEN_IMPTIME  =  0,     // IMPACT TIME IN DAYS SINCE 1950, UTC
     XA_SATPEN_LAUTIME  =  1,     // MSL LAUNCH TIME IN DAYS SINCE 1950, UTC
     XA_SATPEN_AZ       =  2,     // AZIMUTH (DEG)
     XA_SATPEN_EL       =  3,     // ELEVATION (DEG)
     XA_SATPEN_RANGE    =  4,     // RANGE (KM)
     XA_SATPEN_RNGRATE  =  5,     // RANGE RATE (KM/S)
     XA_SATPEN_SOLANG   =  6,     // SOLAR ASPECT ANGLE (DEG)
     XA_SATPEN_ATTCKANG =  7,     // ATTACK ANGLE (DEG)
     XA_SATPEN_SATHGHT  =  8,     // SATELLITE'S HEIGHT (KM)
     XA_SATPEN_EN0EX1   =  9,     // RING PENETRATION ENTRY OR EXIT TIME (0=ENTRY, 1=EXIT)
     
     XA_SATPEN_SIZE     = 16;      
     
  //*******************************************************************************      
  
  // SAAS OUPUT DATA
  static const int     
     XA_SAASRET_NUMOFPENS =  0,     // NUMBER OF ACTUAL SATELLITE PENETRATIONS
     XA_SAASRET_SATAHT    =  1,     // SATELLITE APOGEE HEIGHT (KM)
     XA_SAASRET_SATPHT    =  2,     // SATELLITE PERIGEE HEIGHT (KM)
     XA_SAASRET_MINCONE   =  3,     // AUTOCONE MINIMUM CONE HALF ANGLE (DEG)
     XA_SAASRET_MAXCONE   =  4,     // AUTOCONE MAXIMUM CONE HALF ANGLE (DEG)
     
     
  
     
     XA_SAASRET_SIZE     = 16;      
     
  //*******************************************************************************      
  
  // PREDEFINED VALUES FOR DIFFERENT ORBIT TYPES USED IN PLANER PROGRAM
  static const int  
     ORBTYPE_LEO = 1,    // ORBIT TYPE LEO
     ORBTYPE_MEO = 2,    // ORBIT TYPE MEO
     ORBTYPE_GEO = 3;    // ORBIT TYPE GEO
  
  //*******************************************************************************      
  
  // INDEXES OF FIELDS SPECIFYING PARAMETERS FOR PLANER INTERSECTION PROGRAM
  static const int  
    XA_LNCH_LAT     = 0,       // LAUNCH SITE LATITUDE (DEG)
    XA_LNCH_LON     = 1,       // LAUNCH SITE LONGITUDE (DEG)
    XA_LNCH_INJAZ   = 2,       // INJECTION AZIMUTH (DEG)
    XA_LNCH_DS50UTC = 3,       // LAUNCH TIME IN DAYS SINCE 1950 UTC
    
    XA_LNCH_SIZE    = 8;
    
  //*******************************************************************************   
    
  // INDEXES OF FIELDS SPECIFYING PARAMETERS FOR PLANER INTERSECTION PROGRAM
  static const int  
    XA_PLNR_ORBTYPE  = 0,       // ORBITAL TYPE (LEO = 1, MEO = 2, GEO = 3)
    XA_PLNR_LSLAT    = 1,       // LAUNCH SITE LATITUDE (DEG)
    XA_PLNR_LSLON    = 2,       // LAUNCH SITE LONGITUDE (DEG)
    XA_PLNR_DS50UTC  = 4,       // LAUNCH TIME IN DAYS SINCE 1950 UTC
    XA_PLNR_TOFFR    = 5,       // TIME OF FLIGHT START (MIN)
    XA_PLNR_TOFTO    = 6,       // TIME OF FLIGHT END (MIN) 
    XA_PLNR_INCLI    = 7,       // PLANER'S INCLINATION (DEG)
    XA_PLNR_NODE     = 8,       // PLANER'S NODE (DEG)
    
    XA_PLNR_SIZE     = 16;
    
  //*******************************************************************************        
     
  // INDEXES OF OUTPUT DATA RETURNED BY PLANER INTERSECTION PROGRAM
  static const int  
     XA_INTXN_DS50UTC = 0,      // TIME OF INTERSECTION IN DAYS SINCE 1950 UTC
     XA_INTXN_INCLI   = 1,      // SATELLITE INCLINATION (DEG)
     XA_INTXN_LAT     = 2,      // SATELLITE LATITUDE (DEG) AT THE TIME OF THE INTERSECTION 
     XA_INTXN_LON     = 3,      // SATELLITE LONGITUDE (DEG) AT THE TIME OF THE INTERSECTION                            
     XA_INTXN_HEIGHT  = 4,      // SATELLITE HEIGHT (KM) AT THE TIME OF THE INTERSECTION                               
     XA_INTXN_TOF     = 5,      // TIME OF FLIGHT (MIN) SINCE LAUNCH TIME                          
     XA_INTXN_COPLANG = 6,      // COPLANER ANGLE (DEG)                     
     
     XA_INTXN_SIZE    = 16;                               
     
  //*******************************************************************************         
     
// SaasDll's function pointers declaration
extern fnPtrSaasInit                       SaasInit;
extern fnPtrSaasGetInfo                    SaasGetInfo;
extern fnPtrSaasGetResults                 SaasGetResults;
extern fnPtrSaasAutoConeSize               SaasAutoConeSize;
extern fnPtrSaasMissileFlightTime          SaasMissileFlightTime;
extern fnPtrComputeLnchOrbPlane            ComputeLnchOrbPlane;
extern fnPtrFindPlanerIntersection         FindPlanerIntersection;



void LoadSaasDll();
void FreeSaasDll();




#endif
// ========================= End of auto generated code ==========================
