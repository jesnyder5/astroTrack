// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef ELOPSDLL_H
#define ELOPSDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define ElOpsDll "ElOps.dll"
#elif __APPLE__
  #define ElOpsDll "libelops.dylib"
#else
  #define ElOpsDll "libelops.so"
#endif


// Initializes ElOps dll for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if the ElOps dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrElOpsInit)(__int64 apPtr);


// Returns information about the current version of ElOps.dll. The information is placed in the string parameter you pass in
// infoStr            A string to hold the information about ElOps.dll (out-Character[128])
typedef void (STDCALL *fnPtrElOpsGetInfo)(char infoStr[128]);


// Checks to see if satellite has geo orbit
// incli              satellite's inclination (deg) (in-Double)
// period             satellite's period (min) (in-Double)
// returns Return 1 if satellite has geo orbit, 0 if it doesn't
typedef int (STDCALL *fnPtrIsGeoOrbit)(double incli, double period);


// Estimates the approx long east subpt
// ds50UTC            time in days since 1950, UTC (in-Double)
// node               right ascension of the ascending node (deg) (in-Double)
// omega              argument of perigee (deg) (in-Double)
// mnAnomaly          mean anomaly (deg) (in-Double)
// returns estimated long east sub point (deg)
typedef double (STDCALL *fnPtrCompLonEastSubPt)(double ds50UTC, double node, double omega, double mnAnomaly);


// Computes the decay time of the input satellite
// satKey             The input satKey of the satellite needs to compute decay time (in-Long)
// f10Avg             Input F10 average value (in-Double)
// decayDs50UTC       The output decay time in days since 1950 UTC (out-Double)
// returns Returns 0 if success, 1 if nDot/2 lt 0, 2 if mean motion lt 1.5, and 3 if f2log lt 0
typedef int (STDCALL *fnPtrFindSatDecayTime)(__int64 satKey, double f10Avg, double* decayDs50UTC);


// Returs parameters of a satellite via its satKey
// satKey             The input satKey of the satellite needs to compute gobs parameters (in-Long)
// xa_satparm         Output satellite's parameters (out-Double[32])
// returns 0 if the satellite parameters are successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrGetSatParameters)(__int64 satKey, double xa_satparm[32]);


// Returs the satellite number associated with the input satKey
// satKey             The input satKey (in-Long)
// returns The satellite number associated with the input satKey (satNum = -1 if satKey doesn't exist)
typedef int (STDCALL *fnPtrSatNumOf)(__int64 satKey);
  
  // SATELLITE MAINTENANCE CATEGORY
  static const int  
     SATCAT_SYNCHRONOUS = 1,       // SYNCHRONOUS
     SATCAT_DEEPSPACE   = 2,       // DEEP SPACE (NOT SYNCHRONOUS)
     SATCAT_DECAYING    = 3,       // DECAYING (PERIGEE HEIGHT BELOW 575 KM)
     SATCAT_ROUTINE     = 4;       // ROUTINE (EVERYTHING ELSE)   
     
  // INDEXES OF AVAILABLE SATELLITE DATA FIELDS
  static const int  
     XF_ELFIELD_EPOCHUTC =  1,     // EPOCH IN DAYS SINCE 1950, UTC
     XF_ELFIELD_MNANOM   =  2,     // MEAN ANOMALY (DEG)
     XF_ELFIELD_NODE     =  3,     // RIGHT ASCENSION OF THE ASENDING NODE (DEG) 
     XF_ELFIELD_OMEGA    =  4,     // ARGUMENT OF PERIGEE (DEG) 
     XF_ELFIELD_PERIOD   =  5,     // PERIOD (MIN)
     XF_ELFIELD_ECCEN    =  6,     // ECCENTRICITY (UNITLESS)    
     XF_ELFIELD_INCLI    =  7,     // INCLINATION (DEG)
     XF_ELFIELD_MNMOTION =  8,     // MEAN MOTION (REVS/DAY)
     XF_ELFIELD_BFIELD   =  9,     // EITHER SGP4 BSTAR (1/ER) OR SP BTERM (M2/KG)
     XF_ELFIELD_PERIGEEHT= 10,     // PERIGEE HEIGHT (KM) 
     XF_ELFIELD_APOGEEHT = 11,     // APOGEE HEIGHT (KM) 
     XF_ELFIELD_PERIGEE  = 12,     // PERIGEE (KM)
     XF_ELFIELD_APOGEE   = 13,     // APOGEE (KM)
     XF_ELFIELD_A        = 14,     // SEMI MAJOR AXIS (KM)
     XF_ELFIELD_SATCAT   = 15,     // SATELLITE CATEGORY (SYNCHRONOUS, DEEP SPACE, DECAYING, ROUTINE)
     XF_ELFIELD_HTM3     = 16,     // ASTAT 3 HEIGHT MULTIPLIER
     XF_ELFIELD_CMOFFSET = 17,     // CENTER OF MASS OFFSET (M)
     XF_ELFIELD_N2DOT    = 18;     // N-DOUBLE-DOT/6  (FOR SGP, EPH-TYPE = 0)  
  
     
  // INDEXES OF AVAILABLE SATELLITE PARAMETERS
  static const int  
     XA_SATPARM_EPOCHUTC =  0,     // SATELLITE'S EPOCH IN DAYS SINCE 1950, UTC
     XA_SATPARM_MNANOM   =  1,     // SATELLITE'S MEAN ANOMALY (DEG)
     XA_SATPARM_NODE     =  2,     // SATELLITE'S RIGHT ASCENSION OF THE ASENDING NODE (DEG) 
     XA_SATPARM_OMEGA    =  3,     // SATELLITE'S ARGUMENT OF PERIGEE (DEG) 
     XA_SATPARM_PERIOD   =  4,     // SATELLITE'S PERIOD (MIN)
     XA_SATPARM_ECCEN    =  5,     // SATELLITE'S ECCENTRICITY (UNITLESS)    
     XA_SATPARM_INCLI    =  6,     // SATELLITE'S INCLINATION (DEG)
     XA_SATPARM_MNMOTION =  7,     // SATELLITE'S MEAN MOTION (REVS/DAY)
     XA_SATPARM_BFIELD   =  8,     // SATELLITE'S EITHER SGP4 BSTAR (1/ER) OR SP BTERM (M2/KG)
     XA_SATPARM_PERIGEEHT=  9,     // SATELLITE'S PERIGEE HEIGHT (KM) 
     XA_SATPARM_APOGEEHT = 10,     // SATELLITE'S APOGEE HEIGHT (KM) 
     XA_SATPARM_PERIGEE  = 11,     // SATELLITE'S PERIGEE (KM)
     XA_SATPARM_APOGEE   = 12,     // SATELLITE'S APOGEE (KM)
     XA_SATPARM_A        = 13,     // SATELLITE'S SEMI MAJOR AXIS (KM)
     XA_SATPARM_SATCAT   = 14,     // SATELLITE'S CATEGORY (1=SYNCHRONOUS, 2=DEEP SPACE, 3=DECAYING, 4=ROUTINE)
     XA_SATPARM_CMOFFSET = 15,     // SATELLITE'S CENTER OF MASS OFFSET (M)
     XA_SATPARM_LONE     = 16,     // SATELLITE'S EAST LONGITUDE EAST SUBPOINT (DEG) - ONLY FOR SYNCHRONOUS ORBITS
     XA_SATPARM_DRIFT    = 17,     // SATELLITE'S LONGITUDE DRIFT RATE (DEG EAST/DAY) - ONLY FOR SYNCHRONOUS ORBITS
     XA_SATPARM_OMEGADOT = 18,     // SATELLITE'S OMEGA RATE OF CHANGE (DEG/DAY)
     XA_SATPARM_RADOT    = 19,     // SATELLITE'S NODAL PRECESSION RATE (DEG/DAY)
     XA_SATPARM_NODALPRD = 20,     // SATELLITE'S NODAL PERIOD (MIN)
     XA_SATPARM_NODALX   = 21,     // SATELLITE'S NODAL CROSSING TIME PRIOR TO ITS EPOCH (DS50UTC)
     XA_SATPARM_ISGEO    = 22,     // SATELLITE IS GEO: 0=NO, 1=YES
     XA_SATPARM_RELENERGY= 23,     // SATELLITE'S RELATIVE ENERGY - ONLY FOR GOBS
     XA_SATPARM_SATNUM   = 24,     // SATELLITE'S RELATIVE ENERGY - ONLY FOR GOBS
     XA_SATPARM_OET      = 25,     // SATELLITE'S ORBITAL ELSET TYPE - SEE OET_? FOR LIST OF AVAILABLE VALUES
     XA_SATPARM_PROPTYPE = 26,     // SATELLITE'S PROPAGATION TYPE - SEE PROPTYPE_? FOR LIST OF AVAILABLE VALUES
     XA_SATPARM_ELSETNUM = 27,     // SATELLITE'S ELEMENT NUMBER
     
     XA_SATPARM_SIZE     = 32;
  
// ElOpsDll's function pointers declaration
extern fnPtrElOpsInit                      ElOpsInit;
extern fnPtrElOpsGetInfo                   ElOpsGetInfo;
extern fnPtrIsGeoOrbit                     IsGeoOrbit;
extern fnPtrCompLonEastSubPt               CompLonEastSubPt;
extern fnPtrFindSatDecayTime               FindSatDecayTime;
extern fnPtrGetSatParameters               GetSatParameters;
extern fnPtrSatNumOf                       SatNumOf;



void LoadElOpsDll();
void FreeElOpsDll();




#endif
// ========================= End of auto generated code ==========================
