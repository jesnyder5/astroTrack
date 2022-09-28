// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef SATSTATEDLL_H
#define SATSTATEDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define SatStateDll "SatState.dll"
#elif __APPLE__
  #define SatStateDll "libsatstate.dylib"
#else
  #define SatStateDll "libsatstate.so"
#endif


// Initializes SatState DLL for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. 
// The error occurs if the users forget to load and initialize all the prerequisite DLLs, 
// as listed in the DLL Prerequisite section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if SatState.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateInit)(__int64 apPtr);


// Returns information about the current version of SatState DLL. 
// The information is placed in the string parameter passed in.
// The returned string provides information about the version number, build date, and the platform of the SatState DLL. 
// infoStr            A string to hold the information about SatState.dll (out-Character[128])
typedef void (STDCALL *fnPtrSatStateGetInfo)(char infoStr[128]);


// Loads any orbital element types (TLE's/SPVEC's/VCM's), EXTEPHEM's, and/or propagator controls from an input text file
// Internally, if taskMode = 1, this function calls SpProp.SpLoadFile(); 
// and if taskMode = 2, this function calls Tle.TleLoadFile(), SpVec.SpVecLoadFile(), Vcm.VcmLoadFile(), ExtEphem.ExtEphLoadFile(); 
// if taskMode = 3, both tasks (1 and 2) are executed.
// inputFile          The name of the input file to load (in-Character[512])
// xf_Task            Specified task mode: 1=load SP control parameters, 2=load elsets only, 3=both 1 + 2 (in-Integer)
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateLoadFile)(char inputFile[512], int xf_Task);


// Saves currently loaded orbital element types (TLE's/SPVEC's/VCM's), EXTEPHEM's, and/or propagator controls to a file
// The purpose of this function is to save the current SatState-related settings, usually used in GUI applications, for future use.
// 
// Internally, if taskMode = 1, this function calls SpProp.SpSaveFile(); 
// and if taskMode = 2, this function calls Tle.TleSaveFile(), SpVec.SpVecSavedFile(), Vcm.VcmSaveFile(), ExtEphem.ExtEphSaveFile(); 
// if taskMode = 3, both tasks (1 and 2) are executed.
// outFile            The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// xf_Task            Specified task mode: 1=Only save propagator control parameters, 2=Only save orbital elements/external ephemeris data,	3=Save both 1 + 2 (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateSaveFile)(char outFile[512], int saveMode, int saveForm, int xf_Task);


// Removes a satellite from the appropriate elset DLL's set of loaded satellites. 
// The function will automatically choose the proper set of elsets from which to remove the satellite. 
// The choices are: Tle.dll, SpVec.dll, Vcm.dll, or ExtEphem.dll   
// If the users enter an invalid satKey (a satKey that does not exist in memory), the function will return a non-zero value indicating an error.
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the satellite is successfully removed from memory, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateRemoveSat)(__int64 satKey);


// Removes a satellite from the appropriate sets of loaded satellites (elset dll and propagator dll). 
// The function will remove the satellite from the elset DLL's sets as in SatStateRemoveSat() and 
// from the appropriate propagator's set of initialized satellites if it exists there.
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the satellite is successfully removed from memory, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateRemoveSatAll)(__int64 satKey);


// Removes all satellites from all of the loaded data sets. 
// It will remove all satellites from the following sets: Tle, SpVec, Vcm, ExtEphem, Sgp4Prop, and SpProp
// returns 0 if all of the data sets are cleared successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateRemoveAllSats)();


// Resets propagator settings back to their default values
typedef void (STDCALL *fnPtrSatStateReset)();


// Returns the total number of satellites (TLE's, SPVEC's, VCM's, and EXTEPHEM's) currently loaded in memory
// See SatStateGetLoaded for example.
// This function is useful for dynamically allocating memory for the array that is passed to the function SatStateGetLoaded.
// returns The total number of currently loaded satellites
typedef int (STDCALL *fnPtrSatStateGetCount)();


// Retrieves all of the currently loaded satKeys. 
// These satKeys can be used to access the internal data for the satellites.
// It is recommended that SatStateGetCount() is used to count how many satellites are currently loaded in memory. 
// The user can then use this number to dynamically allocate the satKeys array and pass it to this function.
// 
// If the user prefers to pass a static array to the function, make sure it is big enough to store all the satKeys in memory.
// order              Specifies the order in which the satKeys should be returned:	0=ascending order, 1=descending order, 2=order in which the satKeys were loaded in memory (in-Integer)
// satKeys            The array in which to store the satKeys (out-Long[*])
typedef void (STDCALL *fnPtrSatStateGetLoaded)(int order, __int64 satKeys[]);


// Returns the first satKey that contains the specified satellite number in all sets of loaded satellites. 
// These sets will be searched: Tle, SpVec, Vcm, and ExtEphem.
// This function is useful when a satellite is used in applications that require only one record for one 
// satellite and the applications refer to that satellite by its satellite number. 
// However, the Astrodynamic Standard Shared library is only working with satKeys, this function helps to return the associated satKey of that satellite.
// satNum             The satellite number to search for (in-Integer)
// returns The satKey of the matching satellite if one is found, a negative value indicating an error if not
typedef __int64 (STDCALL *fnPtrSatStateNumToKey)(int satNum);


// Retrieves the data which is common to all satellite types. 
// All common fields are retrieved with a single function call.
// The apogee height and perigee height are defined as the distance above an ellipsoid 
// created using the earth flattening factor from the selected geopotential model.
// Note:  When using SP elsets (TLE type 6, SPVEC, or VCM), calling SatStateGetSatDataAll 
// will implicitly call SpInit in order to extract the mu value from the GEO file the elset is tied to.  
// The elset must have a valid GEO directory available or an error will be returned.
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// satName            Satellite international designator (out-Character[8])
// eltType            Element type (see ELTTYPE_? which is listed in DllMain for list of possible element types) (out-Integer)
// revNum             Revolution number at epoch (out-Integer)
// epochDs50UTC       Epoch time time in days since 1950 UTC (out-Double)
// bField             Ballistic coefficient (m^2/kg) (out-Double)
// elsetNum           Element set number (out-Integer)
// incli              Inclination (deg) (out-Double)
// node               Right ascension of ascending node (deg) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (deg) (out-Double)
// mnAnomaly          Mean anomaly (deg) (out-Double)
// mnMotion           Mean motion (rev/day) (out-Double)
// period             Satellite period (min) (out-Double)
// perigeeHt          Satellite perigee height (km) above the ellipsoid (out-Double)
// apogeeHt           Satellite apogee height (km) above the ellipsoid (out-Double)
// perigee            Satellite perigee height from the center of the earth (km) (out-Double)
// apogee             Satellite apogee height from the center of the earth (km) (out-Double)
// A                  Semi-major axis (km) (out-Double)
// returns 0 if all satellite data fields are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateGetSatDataAll)(__int64 satKey, int* satNum, char satName[8], int* eltType, int* revNum, double* epochDs50UTC, double* bField, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, double* period, double* perigeeHt, double* apogeeHt, double* perigee, double* apogee, double* A);


// Retrieves an individual field of a satellite. 
// 
// Only data fields common to all satellite types can be retrieved.
// 
// The table below shows the valid values for the xf_Sat parameter:
// 
// 
// Index
// Index Interpretation
// 
//  1Satellite number I5
//  2Satellite international designator A8
//  3Element type I1 
//  4Epoch revolution number I6
//  5Epoch time in days since 1950
//  6BStar drag component (GP) or Ballistic coefficient-BTerm (SP) (m^2/kg)
//  7Element set number
//  8Inclination (deg)
//  9Right ascension of ascending node (deg)
// 10Eccentricity
// 11Argument of perigee (deg)
// 12Mean anomaly (deg)
// 13Mean motion (revs/day)
// 14Satellite period (min)
// 15Perigee Height(km)
// 16Apogee Height (km)
// 17Perigee(km)
// 18Apogee (km)
// 19Semi-major axis (km)
//    
// satKey             The satellite's unique key (in-Long)
// xf_Sat             Predefined number specifying which field to retrieve, see XF_SAT_? for field specification (in-Integer)
// retVal             A string to contain the value of the requested field (out-Character[512])
// returns 0 if the satellite data is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateGetSatDataField)(__int64 satKey, int xf_Sat, char retVal[512]);


// Initializes a TLE, SPVEC, or VCM in preparation for propagation, or an EXTEPHEM in preparation for interpolation
// satKey             The satellite's unique key (in-Long)
// returns 0 if the satellite is successfully initialized, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateInitSat)(__int64 satKey);


// Propagates a TLE/SPVEC/VCM, or interpolates an EXTEPHEM. 
// The satellite is propagated/interpolated to the specified time calculated in minutes since the satellite's epoch time
// satKey             The satellite's unique key (in-Long)
// mse                The time to propagate to, specified in minutes since the satellite's epoch time (in-Double)
// ds50UTC            Resulting time in days since 1950, UTC (out-Double)
// revNum             Revolution number (out-Integer)
// pos                Resulting ECI position vector (km) in True Equator and Mean Equinox of Epoch (out-Double[3])
// vel                Resulting ECI velocity vector (km/s) in True Equator and Mean Equinox of Epoch (out-Double[3])
// llh                Resulting geodetic latitude (deg), longitude(deg), and height (km) (out-Double[3])
// returns 0 if the satellite is propagated/interpolated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateMse)(__int64 satKey, double mse, double* ds50UTC, int* revNum, double pos[3], double vel[3], double llh[3]);


// Propagates a TLE/SPVEC/VCM, or interpolates an EXTEPHEM. 
// The satellite is propagated/interpolated to the specified time calculated in days since 1950, UTC.
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The time to propagate to, specified in days since 1950, UTC (in-Double)
// mse                Resulting time in minutes since the satellite's epoch time (out-Double)
// revNum             Revolution number (out-Integer)
// pos                Resulting ECI position vector (km) in True Equator and Mean Equinox of Epoch (out-Double[3])
// vel                Resulting ECI velocity vector (km/s) in True Equator and Mean Equinox of Epoch (out-Double[3])
// llh                Resulting geodetic latitude (deg), longitude(deg), and height (km) (out-Double[3])
// returns 0 if the satellite is propagated/interpolated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateDs50UTC)(__int64 satKey, double ds50UTC, double* mse, int* revNum, double pos[3], double vel[3], double llh[3]);


// Returns additional propagated/interpolated results (reserved for future implementation)
// Reserved for future implementation
// Use this function immediately after the call to SatStateMse or SatStateDs50UTC. 
// satKey             the satellite's unique key (in-Long)
// index              type of returned data (in-Integer)
// destArr            the resulting array (out-Double[128])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateGetPropOut)(__int64 satKey, int index, double destArr[128]);


// Returns various ephemeris comparison results between two satellite states.
// xa_Delta array arrangement:
//  1: delta position (km).
//  2: delta time (sec).
//  3: delta position in radial direction (km).
//  4: delta position in in-track direction (km).
//  5: delta position in cross-track direction (km).
//  6: delta velocity (km/sec).
//  7: delta velocity in radial direction (km/sec).
//  8: delta velocity in in-track direction (km/sec).
//  9: delta velocity in cross-track direction (km/sec).
// 10: delta beta (deg).
// 11: delta height (km).
// 12: delta angular momentum (deg).
// The "in-track" is NOT the velocity direction, but is defined as completing the right handed coordinate system 
// defined by the position vector (radial) and the angular momentum vector (cross-track).
// primSatKey         The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// ds50UTC            Requested time in days since 1950 UTC (in-Double)
// uvwFlag            UVW coordinate system flag: 0=use rotating UVW, 1=use inertial UVW (in-Integer)
// xa_Delta           The resulting ephemeris comparison deltas, see XA_DELTA_? for array arrangement (out-Double[100])
// returns 0 if the comparison results are computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateEphCom)(__int64 primSatKey, __int64 secSatKey, double ds50UTC, int uvwFlag, double xa_Delta[100]);


// Returns various ephemeris comparison results between two satellite states (_OS one step) .
// xa_Delta array arrangement:
//  1: delta position (km).
//  2: delta time (sec).
//  3: delta position in radial direction (km).
//  4: delta position in in-track direction (km).
//  5: delta position in cross-track direction (km).
//  6: delta velocity (km/sec).
//  7: delta velocity in radial direction (km/sec).
//  8: delta velocity in in-track direction (km/sec).
//  9: delta velocity in cross-track direction (km/sec).
// 10: delta beta (deg).
// 11: delta height (km).
// 12: delta angular momentum (deg).
// The "in-track" is NOT the velocity direction, but is defined as completing the right handed coordinate system 
// defined by the position vector (radial) and the angular momentum vector (cross-track).
// priPosVel          The primary satellite's state (TEME of Date) in an array (position(1st-3rd, km), velocity(4th-6th, km/s)) (in-Double[6])
// secPosVel          The secondary satellite's state (TEME of Date) in an array (position(1st-3rd, km), velocity(4th-6th, km/s)) (in-Double[6])
// ds50UTC            Requested time in days since 1950 UTC (in-Double)
// uvwFlag            UVW coordinate system flag: 0=use rotating UVW, 1=use inertial UVW (in-Integer)
// xa_Delta           The resulting ephemeris comparison deltas, see XA_DELTA_? for array arrangement (out-Double[100])
typedef void (STDCALL *fnPtrSatStateEphCom_OS)(double priPosVel[6], double secPosVel[6], double ds50UTC, int uvwFlag, double xa_Delta[100]);


// Determines if a satellite contains covariance matrix. 
// 0=no, 1=yes
// satKey             the satellite's unique key (in-Long)
// returns 0=sat doesn't have cov mtx, 1=sat has cov mtx
typedef int (STDCALL *fnPtrSatStateHasCovMtx)(__int64 satKey);


// Propagates/Interpolates UVW covariance matrix from VCM/External ephemeris to the time in days since 1950
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The input time in days since 1950 UTC (in-Double)
// covUVW             6x6 UVW covariance matrix (out-Double[6, 6])
// returns 0 if the UVW covariance matrix is propagated/interpolated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateGetCovUVW)(__int64 satKey, double ds50UTC, double covUVW[6][6]);


// Generate external ephemeris file for the specified satellite (via its unique satKey) 
// Note: No need to initialize the satellite before this call. If it was intialized, it will be removed after this call
// satKey             The satellite's unique key (in-Long)
// startDs50UTC       Start time in days since 1950 UTC (in-Double)
// stopDs50UTC        Stop time in days since 1950 UTC (in-Double)
// stepSizeSecs       Step size in seconds. Set to zero if natural integration step size (auto adjust) is desired for SP propagator (in-Double)
// ephFileName        The generated external ephemeris file name (in-Character[512])
// ephFileType        External ephemeris file type: 1=ITC, 2=ITC without CovMtx (in-Integer)
// returns 0 if the external ephemeris file was generated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSatStateGenEphFile)(__int64 satKey, double startDs50UTC, double stopDs50UTC, double stepSizeSecs, char ephFileName[512], int ephFileType);
  
  // INDEXES OF SATELLITE DATA FIELDS
  static const int  
     XF_SAT_NUM      =  1,      // SATELLITE NUMBER I5
     XF_SAT_NAME     =  2,      // SATELLITE INTERNATIONAL DESIGNATOR A8
     XF_SAT_EPHTYPE  =  3,      // ELEMENT TYPE I1 
     XF_SAT_REVNUM   =  4,      // EPOCH REVOLUTION NUMBER I6
     XF_SAT_EPOCH    =  5,      // EPOCH TIME IN DAYS SINCE 1950
     XF_SAT_BFIELD   =  6,      // BSTAR DRAG COMPONENT (GP) OR BALLISTIC COEFFICIENT-BTERM (SP) (M^2/KG)
     XF_SAT_ELSETNUM =  7,      // ELEMENT SET NUMBER
     XF_SAT_INCLI    =  8,      // INCLINATION (DEG)
     XF_SAT_NODE     =  9,      // RIGHT ASCENSION OF ASCENDING NODE (DEG)
     XF_SAT_ECCEN    = 10,      // ECCENTRICITY
     XF_SAT_OMEGA    = 11,      // ARGUMENT OF PERIGEE (DEG)
     XF_SAT_MNANOM   = 12,      // MEAN ANOMALY (DEG)
     XF_SAT_MNMOTN   = 13,      // MEAN MOTION (REVS/DAY)
     XF_SAT_PERIOD   = 14,      // SATELLITE PERIOD (MIN)
     XF_SAT_PERIGEEHT= 15,      // PERIGEE HEIGHT(KM)
     XF_SAT_APOGEEHT = 16,      // APOGEE HEIGHT (KM)
     XF_SAT_PERIGEE  = 17,      // PERIGEE(KM)
     XF_SAT_APOGEE   = 18,      // APOGEE (KM)
     XF_SAT_A        = 19;      // SEMI-MAJOR AXIS (KM)
  
  
  // INDEXES OF SATSTATE'S LOAD/SAVE FILE TASK MODE
  static const int  
     XF_TASK_CTRLONLY = 1,     // ONLY LOAD/SAVE PROPAGATOR CONTROL PARAMETERS
     XF_TASK_SATONLY  = 2,     // ONLY LOAD/SAVE ORBITAL ELEMENTS/EXTERNAL EPHEMERIS DATA
     XF_TASK_BOTH     = 3;     // LOAD/SAVE BOTH 1 AND 2
  
  
  // INDEXES OF AVAILABLE SATELLITE DATA FIELDS
  static const int  
     XF_SATFIELD_EPOCHUTC =  1,    // SATELLITE NUMBER
     XF_SATFIELD_MNANOM   =  2,    // MEAN ANOMALY (DEG)
     XF_SATFIELD_NODE     =  3,    // RIGHT ASCENSION OF ASENDING NODE (DEG) 
     XF_SATFIELD_OMEGA    =  4,    // ARGUMENT OF PERIGEE (DEG)
     XF_SATFIELD_PERIOD   =  5,    // SATELLITE'S PERIOD (MIN)
     XF_SATFIELD_ECCEN    =  6,    // ECCENTRICITY
     XF_SATFIELD_INCLI    =  7,    // ORBIT INCLINATION (DEG)
     XF_SATFIELD_MNMOTION =  8,    // MEAN MOTION (REV/DAY)
     XF_SATFIELD_BFIELD   =  9,    // GP B* DRAG TERM (1/ER)  OR SP RADIATION PRESSURE COEFFICIENT
     XF_SATFIELD_PERIGEEHT= 10,    // PERIGEE HEIGHT ABOVE THE GEOID (KM)
     XF_SATFIELD_APOGEEHT = 11,    // APOGEE HEIGHT ABOVE THE GEOID (KM)
     XF_SATFIELD_PERIGEE  = 12,    // PERIGEE HEIGHT ABOVE THE CENTER OF THE EARTH (KM)
     XF_SATFIELD_APOGEE   = 13,    // APOGEE HEIGHT ABOVE THE CENTER OF THE EARTH (KM)
     XF_SATFIELD_A        = 14,    // SEMIMAJOR AXIS (KM)
     XF_SATFIELD_NDOT     = 15,    // MEAN MOTION DERIVATIVE (REV/DAY /2)
     XF_SATFIELD_SATCAT   = 16,    // SATELLITE CATEGORY (SYNCHRONOUS, DEEP SPACE, DECAYING, ROUTINE)
     XF_SATFIELD_HTM3     = 17,    // ASTAT 3 HEIGHT MULTIPLIER
     XF_SATFIELD_CMOFFSET = 18,    // CENTER OF MASS OFFSET (M)
     XF_SATFIELD_N2DOT    = 19,    // UNUSED
     XF_SATFIELD_NODEDOT  = 20,    // GP NODE DOT (DEG/S)
     XF_SATFIELD_ERRORTIME= 21,    // GP ONLY - THE LAST TIME WHEN PROPAGATION HAS ERROR
     XF_SATFIELD_MU       = 22;    // VALUE OF MU
  
    
  //*******************************************************************************
  
  // INDEXES OF AVAILABLE DELTAS
  static const int  
     XA_DELTA_POS         =  0,     // DELTA POSITION (KM)
     XA_DELTA_TIME        =  1,     // DELTA TIME (SEC)
     XA_DELTA_PRADIAL     =  2,     // DELTA POSITION IN RADIAL DIRECTION (KM)
     XA_DELTA_PINTRCK     =  3,     // DELTA POSITION IN IN-TRACK DIRECTION (KM)
     XA_DELTA_PCRSSTRCK   =  4,     // DELTA POSITION IN CROSS-TRACK DIRECTION (KM)
     XA_DELTA_VEL         =  5,     // DELTA VELOCITY (KM/SEC)
     XA_DELTA_VRADIAL     =  6,     // DELTA VELOCITY IN RADIAL DIRECTION (KM/SEC)
     XA_DELTA_VINTRCK     =  7,     // DELTA VELOCITY IN IN-TRACK DIRECTION (KM/SEC)
     XA_DELTA_VCRSSTRCK   =  8,     // DELTA VELOCITY IN CROSS-TRACK DIRECTION (KM/SEC)
     XA_DELTA_BETA        =  9,     // DELTA BETA (DEG)
     XA_DELTA_HEIGHT      = 10,     // DELTA HEIGHT (KM)
     XA_DELTA_ANGMOM      = 11,     // DELTA ANGULAR MOMENTUM (DEG)
     XA_DELTA_MHLNBS_UVW  = 12,     // 3D POSITION MAHALANOBIS DISTANCE IN UVW SPACE (BUBBLE COVARIANCE, ONLY IF COVARIANCE PROPAGATION IS AVAILABLE OR TURNED ON)
     XA_DELTA_MHLNBS_HTB  = 13,     // 3D POSITION MAHALANOBIS DISTANCE IN HEIGHT-TIME_BETA SPACE (BANANA COVARIANCE, ONLY IF COVARIANCE PROPAGATION IS AVAILABLE OR TURNED ON)
     
     XA_DELTA_SIZE        =100; 
     
     
  
  //*******************************************************************************
  
  static const int  
     TIME_IS_MSE = 1,     // INPUT TIME IS IN MINUTES SINCE EPOCH 
     TIME_IS_TAI = 2,     // INPUT TIME IS IN DAYS SINCE 1950 TAI
     TIME_IS_UTC = 3;     // INPUT TIME IS IN DAYS SINCE 1950 UTC
     
  //*******************************************************************************
  
  
// SatStateDll's function pointers declaration
extern fnPtrSatStateInit                   SatStateInit;
extern fnPtrSatStateGetInfo                SatStateGetInfo;
extern fnPtrSatStateLoadFile               SatStateLoadFile;
extern fnPtrSatStateSaveFile               SatStateSaveFile;
extern fnPtrSatStateRemoveSat              SatStateRemoveSat;
extern fnPtrSatStateRemoveSatAll           SatStateRemoveSatAll;
extern fnPtrSatStateRemoveAllSats          SatStateRemoveAllSats;
extern fnPtrSatStateReset                  SatStateReset;
extern fnPtrSatStateGetCount               SatStateGetCount;
extern fnPtrSatStateGetLoaded              SatStateGetLoaded;
extern fnPtrSatStateNumToKey               SatStateNumToKey;
extern fnPtrSatStateGetSatDataAll          SatStateGetSatDataAll;
extern fnPtrSatStateGetSatDataField        SatStateGetSatDataField;
extern fnPtrSatStateInitSat                SatStateInitSat;
extern fnPtrSatStateMse                    SatStateMse;
extern fnPtrSatStateDs50UTC                SatStateDs50UTC;
extern fnPtrSatStateGetPropOut             SatStateGetPropOut;
extern fnPtrSatStateEphCom                 SatStateEphCom;
extern fnPtrSatStateEphCom_OS              SatStateEphCom_OS;
extern fnPtrSatStateHasCovMtx              SatStateHasCovMtx;
extern fnPtrSatStateGetCovUVW              SatStateGetCovUVW;
extern fnPtrSatStateGenEphFile             SatStateGenEphFile;



void LoadSatStateDll();
void FreeSatStateDll();




#endif
// ========================= End of auto generated code ==========================