// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#ifndef AOFDLL_H
#define AOFDLL_H

#include "services/DllUtils.h"

// Provide the path to the dll/so
#ifdef _WIN32
  #define AofDll "Aof.dll"
#else
  #define AofDll "libaof.so"
#endif


// Initializes Aof dll for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Aof.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofInit)(__int64 apPtr);


// Returns information about the current version of Aof.dll. The information is placed in the string parameter you pass in
// infoStr            A string to hold the information about Aof.dll. (out-Character[128])
typedef void (STDCALL *fnPtrAofGetInfo)(char infoStr[128]);


// Loads Aof-related parameters (1P/2P/3P cards, and Aof parameter free format) from an input text file
// aofInputFile       The name of the file containing Aof-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofLoadFile)(char aofInputFile[512]);


// Loads Aof-related parameters from an input text file
// aofInputFile       The name of the file containing Aof-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofLoadFileAll)(char aofInputFile[512]);


// Loads a single Aof-typed card
// card               Aof-type input card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofLoadCard)(char card[512]);


// This function retrieves various AOF input data being entered from input flat files (and/or various AOF input cards)
// 
// The following table lists the values for the xa_aofCtrl parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// TIMEFLG   0  input start/stop time type: 1=minutes since epoch (MSE), 0=date time
// (DTG)
// START     1  start time of interest (either MSE or DTG)
// STOP      2  stop time of interest (either MSE or DTG)
// INTERVAL  3  search interval (min)
// PRTOPT    4  print output control flag; 0=print penetrations only, 1=print penetrations and
// data description
// SRCHMET   5  search method: 0=use brute force method, 1=use analytical method
// SRTTYPE   6  output sort type: S=sort each area by sat#, then time, T=sort each area by time,
// then sat#   
// 
// 
// The following table lists the values for the XA_AOFSEN indexes for xa_Missions:
// 
// 
// Name
// Index
// Index Interpretation
// 
// XA_AOFSEN_SATNUM     0  satellite number of sensor-bearing satellite
// XA_AOFSEN_TYPE       1  reserved for future use
// XA_AOFSEN_MINEL      2  off nadir minimum look angle (deg) (=0 for Cone)
// XA_AOFSEN_MAXEL      3  off nadir maximum look angle (deg)
// XA_AOFSEN_MINAZ1     4  minimum azimuth of first azimuth range (deg)
// XA_AOFSEN_MAXAZ1     5  maximum azimuth of first azimuth range (deg)
// XA_AOFSEN_MINAZ2     6  minimum azimuth of second azimuth range (deg)
// XA_AOFSEN_MAXAZ2     7  maximum azimuth of second azimuth range (deg)
// XA_AOFSEN_ELEM7      8  reserved for future use
// XA_AOFSEN_ELEM8      9  reserved for future use
// XA_AOFSEN_ELEM9     10  reserved for future use
// XA_AOFSEN_ELEM10    11  reserved for future use
// SIZE  16
//    
// 
// The following table lists the values for the XA_AOFAREA indexes for xa_AofAreaDatas:
// 
// 
// Name
// Index
// Index Interpretation
// 
// XA_AOFAREA_NUM    0  Area number
// XA_AOFAREA_TYPE   1  | 1 = BOX                       | 2 = CIRCLE              | 3 =
// POINT
// XA_AOFAREA_ELEM1  2  | N lat (deg) upper left corner | N lat (deg) center point| N lat (deg)
// center point
// XA_AOFAREA_ELEM2  3  | E lon (deg) upper left corner | E lon (deg) center point| E lon (deg)
// center point
// XA_AOFAREA_ELEM3  4  | N lat (deg) lower right corner| circle radius (km)      | height (km,
// above reference geoid)
// XA_AOFAREA_ELEM4  5  | E lon (deg) lower right corner|                         | 
// SIZE  16
//    
//    
// xa_aofCtrl         AOF control parameters, see XA_AOFCTRL_? for array arrangement (out-Double[16])
// numOfInpSats       Number of satellite numbers entered in AOF P-card and/or 8P-card (out-Integer)
// xa_aofInpSats      Array of satellite numbers entered via AOF P-card and/or 8P-card (out-Integer[100])
// numOfMissions      Number of satellite/mission records entered via Satellite/Mission (Satellite/Sensor) Data card (out-Integer)
// xa_Missions        Array of mission records entered via Satellite/Mission (Satellite/Sensor) Data card, see XA_AOFSEN_? for array arrangement (out-Double[100, 16])
// numOfAreas         Number of defended areas entered via Defended Area Data card (out-Integer)
// xa_AofAreaDatas    Array of defended areas entered via Defended Area Data card (out-Double[100, 16])
typedef void (STDCALL *fnPtrAofGetDataFrInputFiles)(double xa_aofCtrl[16], int* numOfInpSats, int xa_aofInpSats[100], int* numOfMissions, double xa_Missions[100][16], int* numOfAreas, double xa_AofAreaDatas[100][16]);


// This function resets all Aof control parameters previously loaded from input text files
typedef void (STDCALL *fnPtrAofReset)();


// Computes entry/exit times of basic overflight satellite/sensor (cone) versus basic defended areas (box, circle, point)
// 
// The following table lists the values for the xa_aofRun parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// MAXPASSES0 Maximum number of possible passes that AOF returns in one start/stop
// time
// START    1 AOF start time in days since 1950, UTC
// STOP     2 AOF stop time in days since 1950, UTC
// INTERVAL 3 Search interval (min) 
// 
// 
// The following table lists the values for the xa_aofSen parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// SATNUM   0 satellite number of sensor-bearing satellite
// TYPE     1 reserved for future use
// MINEL    2 off nadir minimum look angle (deg) (=0 for Cone)
// MAXEL    3 off nadir maximum look angle (deg)
// MINAZ1   4 minimum azimuth of first azimuth range (deg)
// MAXAZ1   5 maximum azimuth of first azimuth range (deg)
// MINAZ2   6 minimum azimuth of second azimuth range (deg)
// MAXAZ2   7 maximum azimuth of second azimuth range (deg)
// ELEM7    8 reserved for future use
// ELEM8    9 reserved for future use
// ELEM9   10 reserved for future use
// ELEM10  11 reserved for future use
//    
// 
// The following table lists the values for the xa_aofAreaData parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// NUM    0  Area number
// TYPE   1  1 = BOX                       | 2 = CIRCLE              | 3 = POINT
// ELEM1  2  N lat (deg) upper left corner | N lat (deg) center point| N lat (deg) center
// point
// ELEM2  3  E lon (deg) upper left corner | E lon (deg) center point| E lon (deg) center
// point
// ELEM3  4  N lat (deg) lower right corner| circle radius (km)      | height (km, above
// reference geoid)
// ELEM4  5  E lon (deg) lower right corner|                         |
//    
// 
// Note:  for xa_aofAreaData TYPE=4 (polygon), use the AofComplex method.
// xa_aofRun          aof run parameters, see XA_AOFRUN_? for array arrangement (in-Double[8])
// satKey             the overflight satellite's unique key (in-Long)
// xa_aofSen          satellite/mission data, see XA_AOFSEN_? for array arrangement (in-Double[16])
// xa_aofAreaData     defended area data, see XA_AOFAREA_? for array arrangement (in-Double[16])
// numOfPasses        number of passes found (out-Integer)
// xa_entExitTimes    array of entry/exit times (out-Double[*])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofBasic)(double xa_aofRun[8], __int64 satKey, double xa_aofSen[16], double xa_aofAreaData[16], int* numOfPasses, double xa_entExitTimes[]);


// Computes entry/exit times of overflight satellite/sensor having complex configurations (cone, donut, butterfly, leftButterly, rightButterfly)
// versus defended areas defined by multiple lat lon height points (polygon)
// For a description of the input parameter arrays xa_aofRun and xa_aofSen, see AofBasic.
// The input array xa_llhPoints is a zero-based array with latitude, longitude and altitude of each point in subsequent entries, e.g.:
// xa_llhPoints[0] = point 1 latitude, 
// xa_llhPoints[1] = point 1 longitude, 
// xa_llhPoints[2] = point 1 altitude, 
// xa_llhPoints[3] = point 2 latitude, etc.
// xa_aofRun          aof run parameters, see XA_AOFRUN_? for array arrangement (in-Double[8])
// satKey             the overflight satellite's unique key (in-Long)
// xa_aofSen          satellite/mission data, see XA_AOFSEN_? for array arrangement (in-Double[16])
// numOfLlhPts        number of actual input lat-lon-height points (maximum 120 points) - lat+N (deg)/lon+E (deg)/height (m) (in-Integer)
// xa_llhPoints       defended area defined by array of lat-lon-height points (maximum 120 points) (in-Double[360])
// numOfPasses        number of passes found (out-Integer)
// xa_entExitTimes    array of entry/exit times (out-Double[*])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofComplex)(double xa_aofRun[8], __int64 satKey, double xa_aofSen[16], int numOfLlhPts, double xa_llhPoints[360], int* numOfPasses, double xa_entExitTimes[]);


// This function returns a look angle from the llh point to the overfly satellite at the specified time
// 
// The following table lists the values for the xa_look parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// DS50UTC  0  Look time in ds50UTC
// MSE      1  Look time in minutes since epoch
// ELEV     2  Elevation (deg)
// AZIM     3  Azimuth (deg)
// RNG      4  Range (km)
// RNGRT    5  Range rate (km/sec)
// 
// ds50TAI            Time, in ds50TAI, for which to compute the look angle (in-Double)
// llh                lat +N -S (deg) /lon (+E) (deg) / height (m) (in-Double[3])
// satKey             the overflight satellite's unique key (in-Long)
// xa_look            look angle data, see XA_LOOK_? for array arrangement (out-Double[8])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofGetLook)(double ds50TAI, double llh[3], __int64 satKey, double xa_look[8]);


// This function returns a view angle from the overfly satellite to a llh point at the specified time
// 
// The following table lists the values for the xa_look parameter:
// 
// 
// Name
// Index
// Index Interpretation
// 
// AZIM    0  Azimuth (deg)
// ELEV    1  Elevation (deg)
// HASLOS  2  Has line of sight to the point (1=Yes, 0=No-earth obstructs the view)
// 
// ds50TAI            Time, in ds50TAI, for which to compute the view angle (in-Double)
// llh                lat +N -S (deg) /lon (+E) (deg) / height (m) (in-Double[3])
// satKey             the overflight satellite's unique key (in-Long)
// xa_aofView         view angle data, see XA_AOFVIEW_? for array arrangement (out-Double[8])
// returns 0 if successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrAofGetView)(double ds50TAI, double llh[3], __int64 satKey, double xa_aofView[8]);


// Determines darkness level of the "defended" area at the specified time
// For a description of the input parameter array xa_aofAreaData, see AofBasic.
// ds50TAI            Time, in ds50TAI, for which to compute the darkness status of the defended area (in-Double)
// xa_aofAreaData     defended area data, see XA_AOFAREA_? for array arrangement (in-Double[16])
// returns darkness level, see DARKLEVEL_? for available values
typedef int (STDCALL *fnPtrAofGetDarknessLevel)(double ds50TAI, double xa_aofAreaData[16]);

   


// AOF parameters
static const int  
   XA_AOFCTRL_TIMEFLG  =  0,   // input start/stop time type: 1=minutes since epoch (MSE), 0=date time (DTG)
   XA_AOFCTRL_START    =  1,   // start time of interest (either MSE or DTG)
   XA_AOFCTRL_STOP     =  2,   // stop time of interest (either MSE or DTG)
   XA_AOFCTRL_INTERVAL =  3,   // search interval (min)
   XA_AOFCTRL_PRTOPT   =  4,   // print output control flag; 0=print penetrations only, 1=print penetrations and data description
   XA_AOFCTRL_SRCHMET  =  5,   // search method: 0=use brute force method, 1=use analytical method
   XA_AOFCTRL_SRTTYPE  =  6,   // output sort type: S=sort each area by sat#, then time, T=sort each area by time, then sat#
   
   XA_AOFCTRL_SIZE     = 16;

   
// Defended area types   
static const int  
   AREATYPE_I_BOX     =  1,     // area box type
   AREATYPE_I_CIRCLE  =  2,     // area circle type
   AREATYPE_I_POINT   =  3,     // area point type
   AREATYPE_I_POLYGON =  4;
   
   
// AOF satellite/mission (satellite/sensor) data
static const int  
   XA_AOFSEN_SATNUM   =  0,   // satellite number of sensor-bearing satellite
   XA_AOFSEN_TYPE     =  1,   // reserved for future use
   XA_AOFSEN_MINEL    =  2,   // off nadir minimum look angle (deg) (=0 for Cone)
   XA_AOFSEN_MAXEL    =  3,   // off nadir maximum look angle (deg)
   XA_AOFSEN_MINAZ1   =  4,   // minimum azimuth of first azimuth range (deg)
   XA_AOFSEN_MAXAZ1   =  5,   // maximum azimuth of first azimuth range (deg)
   XA_AOFSEN_MINAZ2   =  6,   // minimum azimuth of second azimuth range (deg)
   XA_AOFSEN_MAXAZ2   =  7,   // maximum azimuth of second azimuth range (deg)
   XA_AOFSEN_ELEM7    =  8,   // reserved for future use
   XA_AOFSEN_ELEM8    =  9,   // reserved for future use
   XA_AOFSEN_ELEM9    = 10,   // reserved for future use
   XA_AOFSEN_ELEM10   = 11,   // reserved for future use
   
   XA_AOFSEN_SIZE     = 16;


// AOF satellite/sensor types   
static const int  
   AOFSENTYPE_CIRCLE = 0;  // circle (specify only off-nadir maximum look angle)


// AOF run parameters
static const int     
   XA_AOFRUN_MAXPASSES= 0,     // Maximum number of passes that AOF returns in one start/stop time
   XA_AOFRUN_START    = 1,     // AOF start time in days since 1950, UTC
   XA_AOFRUN_STOP     = 2,     // AOF stop time in days since 1950, UTC
   XA_AOFRUN_INTERVAL = 3,     // Search interval (min) 
   
   XA_AOFRUN_SIZE     = 8;      
   
   
// AOF defended area types   
static const int  
   AOF_AREATYPE_BOX     = 1,    // Defended area is a box
   AOF_AREATYPE_CIRCLE  = 2,    // Defended area is a circle
   AOF_AREATYPE_POINT   = 3,    // Defended area is a point
   AOF_AREATYPE_POLYGON = 4;    // Defended area is a polygon
   
   
   
// AOF defended area data   
static const int  
   XA_AOFAREA_NUM   = 0,      // Area number
   XA_AOFAREA_TYPE  = 1,      // | 1 = BOX                       | 2 = CIRCLE              | 3 = POINT
   XA_AOFAREA_ELEM1 = 2,      // | N lat (deg) upper left corner | N lat (deg) center point| N lat (deg) center point
   XA_AOFAREA_ELEM2 = 3,      // | E lon (deg) upper left corner | E lon (deg) center point| E lon (deg) center point
   XA_AOFAREA_ELEM3 = 4,      // | N lat (deg) lower right corner| circle radius (km)      | height (km, above reference geoid)
   XA_AOFAREA_ELEM4 = 5,      // | E lon (deg) lower right corner|                         |            
   
   XA_AOFAREA_SIZE  = 16;
   
   
// Penetration-level darkness status   
static const int  
   DARKLEVEL_ALLLIT  = 0,   // lit throughout penetration
   DARKLEVEL_ALLDARK = 1,   // dark throughout penetration
   DARKLEVEL_PARTLIT = 2;   // partly-lit during penetration
   
// View angle from overfly satellite to a llh point
static const int  
   XA_AOFVIEW_AZIM   = 0,   // Azimuth (deg)
   XA_AOFVIEW_ELEV   = 1,   // Elevation (deg)
   XA_AOFVIEW_HASLOS = 2,   // Has line of sight to the point (1=Yes, 0=No-earth obstructs the view)
   
   XA_AOFVIEW_SIZE   = 8;
   
static const int MAX_LLHPOINTS = 120; // maximum of number of lat-lon-height points that can be used to describe a defended area   

   





// AofDll's function pointers
fnPtrAofInit                        AofInit;
fnPtrAofGetInfo                     AofGetInfo;
fnPtrAofLoadFile                    AofLoadFile;
fnPtrAofLoadFileAll                 AofLoadFileAll;
fnPtrAofLoadCard                    AofLoadCard;
fnPtrAofGetDataFrInputFiles         AofGetDataFrInputFiles;
fnPtrAofReset                       AofReset;
fnPtrAofBasic                       AofBasic;
fnPtrAofComplex                     AofComplex;
fnPtrAofGetLook                     AofGetLook;
fnPtrAofGetView                     AofGetView;
fnPtrAofGetDarknessLevel            AofGetDarknessLevel;



void LoadAofDll();
void FreeAofDll();




#endif
// ========================= End of auto generated code ==========================
