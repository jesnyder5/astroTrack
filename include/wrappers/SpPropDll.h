// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef SPPROPDLL_H
#define SPPROPDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define SpPropDll "SpProp.dll"
#elif __APPLE__
  #define SpPropDll "libspprop.dylib"
#else
  #define SpPropDll "libspprop.so"
#endif


// Initializes SpProp DLL for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. The error occurs if the users forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisites section, before using this DLL. 
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if SpProp.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpInit)(__int64 apPtr);


// Returns information about the current version of SpProp DLL. The information is placed in the string parameter you pass in
// The returned string provides information about the version number, build date, and the platform of the Sp DLL. 
// infoStr            A string to hold the information about SpProp.dll (out-Character[128])
typedef void (STDCALL *fnPtrSpGetInfo)(char infoStr[128]);


// Loads SP-related parameters (SP application controls, prediction controls, numerical integration controls) from a text file
// spInputFile        The name of the file containing SP-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpLoadFile)(char spInputFile[512]);


// Loads SP-related parameters (SP application controls, prediction controls, numerical integration controls) and SP elsets from a text file
// spInputFile        The name of the file containing SP-related parameters and SP elsets (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpLoadFileAll)(char spInputFile[512]);


// Saves currently loaded SP-related parameters (SP application controls, prediction controls, integration controls) to a file
// The purpose of this function is to save the current SP-related settings, usually used in GUI applications, for future use.
// spFile             The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrSpSaveFile)(char spFile[512], int saveMode, int saveForm);


// Initializes an SP satellite from an SP TLE, SPVEC, or VCM
// Internally, when this function is called, the SpProp DLL will look into the right binary tree, based on the vector type extracted from the satKey, and search for the satKey. If found, the SpProp DLL will use the associated SP data to create an SP object for this satellite in its own binary tree. Subsequent calls to propagate this satellite will use the data in the SP object to compute the satellite's new state.
// 
// The users need to call this routine only once for each satellite they want to propagate or every time the satellite data, from which it was initialized, is changed. The call needs to be placed before any calls to the SP propagate routines (SpPropMse, SpPropDs50UTC...).
// satKey             The satellite's unique key (in-Long)
// returns 0 if the satellite is successfully initialized and added to SpProp.dll's set of satellites, non-0 if there is an error
typedef int (STDCALL *fnPtrSpInitSat)(__int64 satKey);


// Removes a satellite, represented by the satKey, from the set of currently loaded satellites
// Calling this function removes all satellites from the set maintained by SpProp.dll. However, the data loaded by Vcm.dll, Tle.dll, SpVec.dll, and ExtEphem.dll is unaffected.
// If the users enter an invalid satKey - a non-existing satKey in memory, the function will return a non-zero value indicating an error.
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the satellite is removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpRemoveSat)(__int64 satKey);


// Removes all currently loaded satellites from memory
// Calling this function removes all satellites from the set maintained by SpProp.dll. However, the data loaded by Vcm.dll, Tle.dll, SpVec.dll, and ExtEphem.dll is unaffected.
// The function returns zero if all the satellites were removed successfully from the SpProp DLL's binary tree.
// returns 0 if all satellites are removed successfully from memory, non-0 if there is an error
typedef int (STDCALL *fnPtrSpRemoveAllSats)();


// Returns the number of SP objects currently created. 
// returns The number of SP objects currently created.
typedef int (STDCALL *fnPtrSpGetCount)();


// Removes all SP-related data from memory (Geo models, Flux records, JPL, DCA, etc.)
typedef void (STDCALL *fnPtrSpReset)();


// Retrieves the value of an SP application control parameter
// 
// The table below shows the values for the xf_SpApp parameter:
// 
// 
// Index
// Index Interpretation
// 
// 1 Geopotential directory path
// 2 Buffer size
// 3 Run mode
// 4 Save partials data
// 5 Specter compatibility mode
// 6 Consider parameter
// 7 Decay altitude
// 8 Output coordinate system
// 9 Additional VCM options
// 
// xf_SpApp           Predefined value specifying which application control parameter to retrieve (in-Integer)
// valueStr           A string to hold the retrieved application control parameter (out-Character[512])
typedef void (STDCALL *fnPtrSpGetApCtrl)(int xf_SpApp, char valueStr[512]);


// Retrieves all SP application control parameters with a single function call
// geoDir             geopotential directory path (out-Character[512])
// bufSize            buffer size [5000] (out-Integer)
// runMode            run mode: 0=performance priority, [1]=memory priority (out-Integer)
// savePartials       propagate covariance matrix: 0=don't propagate, 1=propagate covariance matrix (if VCM has it) (out-Integer)
// isSpectr           spectr mode: 0=not compatible, 1=SPECTR compatible (out-Integer)
// consider           consider parameter (set it to 12 to match operational system) (out-Double)
// decayAlt           decay altitude (km) [10] (out-Integer)
// outCoord           ouput cooridnate system: [0]=TEME of Date, 1=TEME of Epoch, 2=MEME of J2K (out-Integer)
typedef void (STDCALL *fnPtrSpGetApCtrlAll)(char geoDir[512], int* bufSize, int* runMode, int* savePartials, int* isSpectr, double* consider, int* decayAlt, int* outCoord);


// Sets an SP application control parameter
// See SpGetApCtrl for a list of the values for the xf_SpApp parameter.
// xf_SpApp           predefined value specifying which application control parameter to set (in-Integer)
// valueStr           the new value of the specified parameter, expressed as a string (in-Character[512])
typedef void (STDCALL *fnPtrSpSetApCtrl)(int xf_SpApp, char valueStr[512]);


// Sets all SP application control parameters with a single function call
// geoDir             geopotential directory path (in-Character[512])
// bufSize            buffer size [5000] (in-Integer)
// runMode            run mode: 0=performance priority, [1]=memory priority (in-Integer)
// savePartials       propagate covariance matrix: 0=don't propagate, 1=propagate covariance matrix (if VCM has it) (in-Integer)
// isSpectr           spectr mode: 0=not compatible, 1=SPECTR compatible (in-Integer)
// consider           consider parameter (set it to 12 to match operational system) (in-Double)
// decayAlt           decay altitude (km) [10] (in-Integer)
// outCoord           ouput cooridnate system: [0]=TEME of Date, 1=TEME of Epoch, 2=MEME of J2K (in-Integer)
typedef void (STDCALL *fnPtrSpSetApCtrlAll)(char geoDir[512], int bufSize, int runMode, int savePartials, int isSpectr, double consider, int decayAlt, int outCoord);


// Retrieves the value of a numerical integration control parameter
// 
// The table below shows the values for xf_4P parameter:
// 
// 
// Index
// Index Interpretation
// 
// 1   Geopotential model to use
// 2   Earth gravity pertubations flag
// 3   Drag pertubations flag 
// 4   Radiation pressure pertubations flag
// 5   Lunar/Solar pertubations flag
// 6   F10 value
// 7   F10 average value
// 8   Ap value
// 9   Geopotential truncation order/degree/zonals
// 10  Corrector step convergence criterion; exponent of 1/10; default = 10
// 11  Outgassing pertubations flag
// 12  Solid earth ocean tide pertubations flag
// 13  Input vector coordinate system
// 14  Nutation terms
// 15  Recompute pertubations at each corrector step
// 16  Variable of intergration control
// 17  Variable step size control
// 18  Initial step size
// 21  DCA file name
// 22  Solar flux file name
// 23  Geopotential file name
// 24  JPL file name
// 25  JPL start time
// 26  JPL stop time
// 
// xf_4P              Predefined value specifying which application control parameter to retrieve (in-Integer)
// valueStr           A string to hold the retrieved application control parameter (out-Character[512])
typedef void (STDCALL *fnPtrSpGet4P)(int xf_4P, char valueStr[512]);


// Sets the value of a numerical integration control parameter
// See SpGet4P for a list of the values for the xf_4P parameter.
// For flux, dca, and jpl file settings, the actual file loading happens when the first SpSatInit() is called. 
// If the user needs to load these files instantly, please call the SpLoadFile() instead
// xf_4P              predefined value specifying which application control parameter to set (in-Integer)
// valueStr           the new value of the specified parameter, expressed as a string (in-Character[512])
typedef void (STDCALL *fnPtrSpSet4P)(int xf_4P, char valueStr[512]);


// Retrieves prediction control parameters
// startFrEpoch       start time flag: 0=in days since 1950 UTC, 1=in minutes since epoch (out-Integer)
// stopFrEpoch        stop time flag : 0=in days since 1950 UTC, 1=in minutes since epoch (out-Integer)
// startTime          start time value (out-Double)
// stopTime           stop time value (out-Double)
// interval           step size (min) (out-Double)
typedef void (STDCALL *fnPtrSpGetPredCtrl)(int* startFrEpoch, int* stopFrEpoch, double* startTime, double* stopTime, double* interval);


// Sets prediction control parameters
// startFrEpoch       start time flag: 0=in days since 1950 UTC, 1=in minutes since epoch (in-Integer)
// stopFrEpoch        stop time flag : 0=in days since 1950 UTC, 1=in minutes since epoch (in-Integer)
// startTime          start time value (in-Double)
// stopTime           stop time value (in-Double)
// interval           step size (min) (in-Double)
typedef void (STDCALL *fnPtrSpSetPredCtrl)(int startFrEpoch, int stopFrEpoch, double startTime, double stopTime, double interval);


// Retrieves the value of a field of an SP satellite
// 
// The table below shows the values for the xf_SpSat parameter:
// 
// 
// Index
// Index Interpretation
// 
// 1  Satellite number I5
// 2  Satellite's epoch time in days since 1950, UTC 
// 3  Satellite's epoch time in days since 1950, TAI
// 4  Mu value 
// 5  Covariance Matrix flag
// 6  Integration mode
// 7  Nutation terms
// 8  Specter compatibility mode
// 
// satKey             The satellite's unique key (in-Long)
// xf_SpSat           Predefined number specifying which field to retrieve (in-Integer)
// valueStr           A string containing the value of the specified field (out-Character[512])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpGetSatData)(__int64 satKey, int xf_SpSat, char valueStr[512]);


// Retrieves all fields of an SP satellite with a single function call
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// epochDs50UTC       Satellite's epoch time in days since 1950 UTC (out-Double)
// epochDs50TAI       Satellite's epoch time in days since 1950 TAI (out-Double)
// mu                 mu value from Satellite's geopotential model (out-Double)
// hasCovMtx          0=This satellite doesn't have covariance matrix, 1=This satellite has covariance matrix (out-Integer)
// integMode          Partials computation mode: 0=no partials, 1=numerical, 2=semi-analytic (out-Integer)
// nTerms             number of nutation terms (out-Integer)
// isSpectr           Spectr compatible mode: 0=not compatible, 1=compatible (out-Integer)
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpGetSatDataAll)(__int64 satKey, int* satNum, double* epochDs50UTC, double* epochDs50TAI, double* mu, int* hasCovMtx, int* integMode, int* nTerms, int* isSpectr);


// Propagates a satellite, represented by the satKey, to the time expressed in minutes since the 
// satellite's epoch time
// satKey             The satellite's unique key (in-Long)
// mse                The requested time in minutes since the satellite's epoch time (in-Double)
// timeTypes          The output array that stores different time types: 1=MSE, 2=Ds50UTC, 3=Ds50UT1, 4=Ds50TAI, 5=Ds50ET (out-Double[5])
// revNum             The resulting revolution number (out-Integer)
// posJ2K             The resulting position vector (km) in MEME of J2K (out-Double[3])
// velJ2K             The resulting velocity vector (km/s) in MEME of J2K (out-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpPropMse)(__int64 satKey, double mse, double timeTypes[5], int* revNum, double posJ2K[3], double velJ2K[3]);


// Propagates a satellite, represented by the satKey, to the time expressed in days since 1950, UTC. 
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The requested time in days since 1950 UTC (in-Double)
// timeTypes          The output array that stores different time types: 1=MSE, 2=Ds50UTC, 3=Ds50UT1, 4=Ds50TAI, 5=Ds50ET (out-Double[5])
// revNum             The resulting revolution number (out-Integer)
// posJ2K             The resuling position vector (km) in MEME of J2K (out-Double[3])
// velJ2K             The resulting velocity vector (km/s) in MEME of J2K (out-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpPropDs50UTC)(__int64 satKey, double ds50UTC, double timeTypes[5], int* revNum, double posJ2K[3], double velJ2K[3]);


// Propagates a satellite, represented by the satKey, to the time expressed in days since 1950, UTC. 
// It only returns the latitude, longitude, and height at that time in coordinate system of Date
// It is the users' responsibility to decide what to do with the returned value. For example, if the users want to check for decay or low altitude, they can put that logic into their own code.
// 
// This function is built especially for application that plots ground trace.
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The requested time in days since 1950 UTC (in-Double)
// llh                The resulting array: 1=geodetic latitude (deg), 2=geodetic longitude (deg), 3=height (km) (out-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpPropDs50UtcLLH)(__int64 satKey, double ds50UTC, double llh[3]);


// Propagates a satellite, represented by the satKey, to the time expressed in days since 1950, UTC. 
// It only returns the satellite's ECI position in TEME of DATE
// It is the users' responsibility to decide what to do with the returned value. For example, if the users want to check for decay or low altitude, they can put that logic into their own code.
// 
// This function is built especially for application that plots satellites' positions in 3D.
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The requested time in days since 1950 UTC (in-Double)
// pos                The resulting ECI position (km) in TEME of Date (out-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpPropDs50UtcPos)(__int64 satKey, double ds50UTC, double pos[3]);


// Propagates a satellite, represented by the satKey, to the time expressed in either minutes since epoch or days since 1950, UTC. 
// 
// All propagation data is returned by this function.
// 
// The table below shows the index values for the xa_spOut output array:
// 
// 
// Index
// Index Interpretation
// 
//   0  Propagation time in days since 1950, UTC
//   1  Propagation time in minutes since the satellite's epoch time   
//   2  Propagation time in days since 1950, UT1
//   3  Propagation time in days since 1950, TAI
//   4  Propagation time in days since 1950, ET
//   5  Revolution number
//   6  Number of nutation terms
//   7  Spectr compatible mode (0=not compatible, 1=compatible)
//   8  Has input covariance matrix (0=no, 1=yes)
//  10  J2K position X (km)
//  11  J2K position Y (km)
//  12  J2K position Z (km)
//  13  J2K velocity X (km/s)
//  14  J2K velocity Y (km/s)
//  15  J2K velocity Z (km/s)
//  16  ECI position X (km)
//  17  ECI position Y (km)
//  18  ECI position Z (km)
//  19  ECI velocity X (km/s)
//  20  ECI velocity Y (km/s)
//  21  ECI velocity Z (km/s)
//  22  Geodetic latitude (deg)
//  23  Geodetic longitude (deg)
//  24  Height above geoid (km)
//  30  Covariance matrix type, if available: 1=UVW_DATE, 2=ECI_DATE, 3=EQNX_DATE, 11=UVW_J2K, 12=ECI_J2K,
// 13=EQNX_J2K
//  31-67  6 by 6 covariance matrix   
// 
// satKey             The unique key of the satellite to propagate. (in-Long)
// timeType           The propagation time type: 0 = minutes since epoch, 1 = days since 1950, UTC (in-Integer)
// timeIn             The time to propagate to, expressed in either minutes since epoch or days since 1950, UTC. (in-Double)
// covType            Covariance matrix type, if available: 0=don't propagate, 1=UVW_DATE, 2=ECI_DATE, 3=EQNX_DATE, 11=UVW_J2K, 12=ECI_J2K, 13=EQNX_J2K (in-Integer)
// xa_spOut           The array that stores all Sp propagation data, see XA_SPOUT_? for array arrangement (out-Double[128])
// returns 0 if the propagation is successful, 2 on error.
typedef int (STDCALL *fnPtrSpPropAll)(__int64 satKey, int timeType, double timeIn, int covType, double xa_spOut[128]);


// Propagates a satellite, represented by the satKey, to the time expressed in days since 1950, UTC. 
// It only returns the position and velocity in TEME of Date
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The requested time in days since 1950 UTC (in-Double)
// posDate            The resulting ECI position (km) in TEME of Date (out-Double[3])
// velDate            The resulting ECI velocity (km/s) in TEME of Date (out-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpGetStateDs50UTC)(__int64 satKey, double ds50UTC, double posDate[3], double velDate[3]);


// Reepochs the state of an existing SP object associated with the satKey. 
// Proper initialization is handled internally so no need to call SpSatInit() afterward 
// satKey             The satellite's unique key (in-Long)
// ds50UTC            The requested new epoch time in days since 1950 UTC (in-Double)
// posDate            The initial ECI position (km) in TEME of Date (in-Double[3])
// velDate            The initial ECI velocity (km/s) in TEME of Date (in-Double[3])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpSetStateDs50UTC)(__int64 satKey, double ds50UTC, double posDate[3], double velDate[3]);


// Updates an SP object associated with the satKey with the new input data stored in setDataArr. 
// Then propagates the updated SP object to the requested time propTimeDs50UTC. 
// Resulting propagated data will be stored in propDataArr.
// satKey             The satellite's unique key (in-Long)
// setDataArr         0-2: posECI (km), 3-5: velECI (km/s), 6: bTerm (m2/kg), 7: agom (m2/kg) (in-Double[128])
// propTimeDs50UTC    The requested time in days since 1950 UTC (in-Double)
// propDataArr        0-2: out posECI (km), 3-5: out velECI (km/s) (out-Double[128])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpSetAndProp)(__int64 satKey, double setDataArr[128], double propTimeDs50UTC, double propDataArr[128]);


// This function is reserved for future use. The purpose is to return propagator output data based on user special requests that have not yet been determined
// Use this function immediately after the call to SpPropMse or SpPropDs50UTC. 
// satKey             The satellite's unique key (in-Long)
// index              Index specified ouput data (in-Integer)
// destArr            The resulting array (out-Double[*])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpGetPropOut)(__int64 satKey, int index, double destArr[]);


// Returns the covariance matrix of a satellite
// Use this function immediately after the call to SpPropMse or SpPropDs50UTC. 
// satKey             The satellite's unique key (in-Long)
// covType            Covariance matrix type: 1=UVW_DATE, 2=ECI_DATE, 3=EQNX_DATE, 11=UVW_J2K, 12=ECI_J2K, 13=EQNX_J2K (in-Integer)
// covMtx             Resulting covariance matrix 6x6 (out-Double[6, 6])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpGetCovMtx)(__int64 satKey, int covType, double covMtx[6][6]);


// Computes the covariance sigma from the input covariance matrix
// covMtx             Input covariance matrix (in-Double[6, 6])
// covSigma           Resulting covariance sigma (out-Double[6])
typedef void (STDCALL *fnPtrSpCompCovSigma)(double covMtx[6][6], double covSigma[6]);


// Sets all numerical integration control parameters with a single function call
// geoIdx             geopotential model (in-Integer)
// bulgePert          earth gravity flag (in-Integer)
// dragPert           drag pertubation flag (in-Integer)
// radPresPert        radiation pressure pertubation flag (in-Integer)
// lunSolPert         lunar/solar pertubation flag (in-Integer)
// f10                f10 value (in-Integer)
// f10Avg             f10 average value (in-Integer)
// ap                 ap (in-Integer)
// trunc              geo truncation order/degree/zonals (in-Integer)
// incr               corrector step convergenece criterion (in-Integer)
// ogPert             outgassing pertubation flag (in-Integer)
// tidePert           solid earth + ocean tide pertubation flag (in-Integer)
// inCoord            input vector coordinate system (in-Integer)
// nTerms             nutation terms (in-Integer)
// reEval             recompute pertubations at each corrector step (in-Integer)
// integStepMode      variable of integration control (in-Integer)
// stepSizeMethod     variable step size control (in-Integer)
// initStepSize       initial step size (in-Double)
// dcaFile            DCA file name (in-Character[512])
// fluxFile           Flux file name (in-Character[512])
// geoFile            Geo file name (in-Character[512])
// jplFile            JPL file name (in-Character[512])
// jplStart           JPL start time (in-Character[512])
// jplStop            JPL stop time (in-Character[512])
typedef void (STDCALL *fnPtrSpSet4pAll)(int geoIdx, int bulgePert, int dragPert, int radPresPert, int lunSolPert, int f10, int f10Avg, int ap, int trunc, int incr, int ogPert, int tidePert, int inCoord, int nTerms, int reEval, int integStepMode, int stepSizeMethod, double initStepSize, char dcaFile[512], char fluxFile[512], char geoFile[512], char jplFile[512], char jplStart[512], char jplStop[512]);


// Retrieves all numerical integration control parameters with a single function call
// geoIdx             geopotential model (out-Integer)
// bulgePert          earth gravity flag (out-Integer)
// dragPert           drag pertubation flag (out-Integer)
// radPresPert        radiation pressure pertubation flag (out-Integer)
// lunSolPert         lunar/solar pertubation flag (out-Integer)
// f10                f10 value (out-Integer)
// f10Avg             f10 average value (out-Integer)
// ap                 ap (out-Integer)
// trunc              geo truncation order/degree/zonals (out-Integer)
// incr               corrector step convergenece criterion (out-Integer)
// ogPert             outgassing pertubation flag (out-Integer)
// tidePert           solid earth + ocean tide pertubation flag (out-Integer)
// inCoord            input vector coordinate system (out-Integer)
// nTerms             nutation terms (out-Integer)
// reEval             recompute pertubations at each corrector step (out-Integer)
// integStepMode      variable of integration control (out-Integer)
// stepSizeMethod     variable step size control (out-Integer)
// initStepSize       initial step size (out-Double)
// dcaFile            DCA file name (out-Character[512])
// fluxFile           Flux file name (out-Character[512])
// geoFile            Geo file name (out-Character[512])
// jplFile            JPL file name (out-Character[512])
// jplStart           JPL start time (out-Character[512])
// jplStop            JPL stop time (out-Character[512])
typedef void (STDCALL *fnPtrSpGet4pAll)(int* geoIdx, int* bulgePert, int* dragPert, int* radPresPert, int* lunSolPert, int* f10, int* f10Avg, int* ap, int* trunc, int* incr, int* ogPert, int* tidePert, int* inCoord, int* nTerms, int* reEval, int* integStepMode, int* stepSizeMethod, double* initStepSize, char dcaFile[512], char fluxFile[512], char geoFile[512], char jplFile[512], char jplStart[512], char jplStop[512]);


// Read the integration control settings from a 4P-Card
// card4P             The input 4P card (in-Character[512])
// returns 0 if the input 4P card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpSet4PCard)(char card4P[512]);


// Builds and returns the integration control card (4P-Card) from the current settings
// card4P             A string to hold the retrieved 4P card (out-Character[512])
typedef void (STDCALL *fnPtrSpGet4PCard)(char card4P[512]);


// Adds one solar flux record to memory. This API can be used to avoid SpLoadFile's file I/O      
// refDs50UTC         Time tag of this record (DS50; UTC) (in-Double)
// f10                f10 value (in-Double)
// f10Avg             f10avg value (in-Double)
// ap                 Array of 3-hourly values of Ap (in-Double[8])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrSpAddFluxRec)(double refDs50UTC, double f10, double f10Avg, double ap[8]);


// Returns the times, in days since 1950 UTC, of ephemeris points stored in SP buffer that meet the requirement as specified in the minStepSize
// This function is used to retrieve times in which SP propagator stored satellite's state vectors in memory (natural integration step size).
// An error will occur if the actualEphPts reaches the maxEphPts. In this case, the function will return all ephemereris times up to the time when that maxEphPts is reached.
// satKey             The satellite's unique key (in-Long)
// maxEphPts          Maximum number of possible ephemeris points that the function won't go over. That means actualEphPts can't be greater than maxEphPts even though the time span may have more points than that (in-Integer)
// startDs50UTC       Start time in days since 1950 UTC (in-Double)
// stopDs50UTC        Stop time in days since 1950 UTC (in-Double)
// minStepSize        Option to thin ephem points. Only pick ephem point when its next ephem point is older than the specified minStepSize (minutes). Set to 0 to get all ephem points (SP natural integration step size) (in-Double)
// actualEphPts       Actual number of ephem points that meet the requirements (out-Integer)
// ds50UTCArr         The resulting time array, in days since 1950 UTC, of all ephem points that meet the requirements (out-Double[*])
// returns 0 if the function successfully returns all the ephemeris times of the specified start/stop time span, non-0 if there is an error. Also if
typedef int (STDCALL *fnPtrSpGetEphemTimes)(__int64 satKey, int maxEphPts, double startDs50UTC, double stopDs50UTC, double minStepSize, int* actualEphPts, double ds50UTCArr[]);


// Generates ephemerides for the input satellite, represented by its satKey, for the specified time span and step size
// Notes: if arrSize isn't big enough to store all the ephemeris points, the function will exit when the ephemArr reaches
// that many points (arrSize) and the errCode is set to IDX_ERR_WARN
// satKey             The unique key of the satellite to generate ephemerides. (in-Long)
// startDs50UTC       Start time expressed in days since 1950, UTC. (in-Double)
// stopDs50UTC        End time expressed in days since 1950, UTC. (in-Double)
// stepSize           Step size in minutes, set to 0 if want to use SP natural integration step size (in-Double)
// sp_ephem           Output ephemeris type: 1=ECI, 2=J2K. (in-Integer)
// arrSize            Size of input ephemArr (in-Integer)
// ephemArr           Output ephemerides - 0: time in days since 1950 UTC, 1-3: pos (km), 4-6: vel (km/sec) (out-Double[*, 7])
// genEphemPts        Actual number of ephemeris points generated (always &le; arrSize) (out-Integer)
// returns 0 if the propagation is successful, non-0 if there is an error (see error decoder in GP_ERR_?).
typedef int (STDCALL *fnPtrSpGenEphems)(__int64 satKey, double startDs50UTC, double stopDs50UTC, double stepSize, int sp_ephem, int arrSize, double ephemArr[][7], int* genEphemPts);


// Generates ephemerides for the input vcm (in string format) for the specified time span and step size
// Notes: if arrSize isn't big enough to store all the ephemeris points, the function will exit when the ephemArr reaches
// that many points (arrSize) and the errCode is set to IDX_ERR_WARN
// vcmString          1-line or concatenated string representation of the VCM (in-Character[4000])
// startDs50UTC       Start time expressed in days since 1950, UTC. (in-Double)
// stopDs50UTC        End time expressed in days since 1950, UTC. (in-Double)
// stepSize           Step size in minutes, set to 0 if want to use SP natural integration step size (in-Double)
// sp_ephem           Output ephemeris type: 1=ECI, 2=J2K. (in-Integer)
// arrSize            Size of input ephemArr (in-Integer)
// ephemArr           Output ephemerides - 0: time in days since 1950 UTC, 1-3: pos (km), 4-6: vel (km/sec) (out-Double[*, 7])
// genEphemPts        Actual number of ephemeris points generated (always &le; arrSize) (out-Integer)
// returns 0 if the propagation is successful, non-0 if there is an error (see error decoder in GP_ERR_?).
typedef int (STDCALL *fnPtrSpGenEphemsVcm_OS)(char vcmString[4000], double startDs50UTC, double stopDs50UTC, double stepSize, int sp_ephem, int arrSize, double ephemArr[][7], int* genEphemPts);


// Propagates all input satellites, represented by their satKeys, to the time expressed in days since 1950, UTC. 
// satKeys            The satellite keys of all input satellites (in-Long[*])
// numOfSats          The total number of satellites (in-Integer)
// ds50UTC            The time to propagate all satelllites to, expressed in days since 1950, UTC. (in-Double)
// ephemArr           0-2: pos (km), 3-5: vel (km/sec) - ECI TEME of Date (out-Double[*, 6])
// returns 0 if the propagation is successful, non-0 if there is an error.
typedef int (STDCALL *fnPtrSpPropAllSats)(__int64 satKeys[], int numOfSats, double ds50UTC, double ephemArr[][6]);
  
  // INDEXES OF SP 4P CARD FIELDS
  static const int  
     XF_4P_GEOIDX   = 1,       // GEOPOTENTIAL MODEL TO USE
     XF_4P_BULGEFLG = 2,       // EARTH GRAVITY PERTUBATIONS FLAG
     XF_4P_DRAGFLG  = 3,       // DRAG PERTUBATIONS FLAG 
     XF_4P_RADFLG   = 4,       // RADIATION PRESSURE PERTUBATIONS FLAG
     XF_4P_LUNSOL   = 5,       // LUNAR/SOLAR PERTUBATIONS FLAG
     XF_4P_F10      = 6,       // F10 VALUE
     XF_4P_F10AVG   = 7,       // F10 AVERAGE VALUE
     XF_4P_AP       = 8,       // AP VALUE
     XF_4P_TRUNC    = 9,       // GEOPOTENTIAL TRUNCATION ORDER/DEGREE/ZONALS
     XF_4P_CONVERG  = 10,      // CORRECTOR STEP CONVERGENCE CRITERION; EXPONENT OF 1/10; DEFAULT = 10
     XF_4P_OGFLG    = 11,      // OUTGASSING PERTUBATIONS FLAG
     XF_4P_TIDESFLG = 12,      // SOLID EARTH AND OCEAN TIDE PERTUBATIONS FLAG
     XF_4P_INCOORD  = 13,      // INPUT VECTOR COORDINATE SYSTEM
     XF_4P_NTERMS   = 14,      // NUTATION TERMS
     XF_4P_REEVAL   = 15,      // RECOMPUTE PERTUBATIONS AT EACH CORRECTOR STEP
     XF_4P_INTEGCTRL= 16,      // VARIABLE OF INTERGRATION CONTROL
     XF_4P_VARSTEP  = 17,      // VARIABLE STEP SIZE CONTROL
     XF_4P_INITSTEP = 18,      // INITIAL STEP SIZE
  
     XF_4P_DCAFILE  = 21,      // DCA FILE NAME
     XF_4P_FLUXFILE = 22,      // SOLAR FLUX FILE NAME
     XF_4P_GEOFILE  = 23,      // GEOPOTENTIAL FILE NAME
     XF_4P_JPLFILE  = 24,      // JPL FILE NAME
     XF_4P_JPLSTART = 25,      // JPL START TIME
     XF_4P_JPLSTOP  = 26;      // JPL STOP TIME
  
     //XF_4P_PLANETS  = 27,      // SETS PERTURBATIONS FROM ALL PLANETS TO ON
     //XF_4P_MERCURY  = 28,      // SETS PERTURBATION FROM MERCURY TO ON
     //XF_4P_VENUS    = 29,      // SETS PERTURBATION FROM VENUS TO ON
     //XF_4P_MARS     = 30,      // SETS PERTURBATION FROM MARS TO ON
     //XF_4P_JUPITER  = 31,      // SETS PERTURBATION FROM JUPITER TO ON
     //XF_4P_SATURN   = 32,      // SETS PERTURBATION FROM SATURN TO ON
     //XF_4P_URANUS   = 33,      // SETS PERTURBATION FROM URANUS TO ON
     //XF_4P_NEPTUNE  = 34,      // SETS PERTURBATION FROM NEPTUNE TO ON
     //XF_4P_PLUTO    = 35;      // SETS PERTURBATION FROM PLUTO TO ON
     
  //*******************************************************************************
  
  // INDEXES OF SP APPLICATION CONTROL (PREFERENCE) PARAMETERS
  static const int  
     XF_SPAPP_GEODIR   = 1,     // GEOPOTENTIAL DIRECTORY PATH
     XF_SPAPP_BUFSIZE  = 2,     // BUFFER SIZE
     XF_SPAPP_RUNMODE  = 3,     // RUN MODE
     XF_SPAPP_SAVEPART = 4,     // SAVE PARTIALS DATA
     XF_SPAPP_SPECTR   = 5,     // SPECTER COMPATIBILITY MODE
     XF_SPAPP_CONSIDER = 6,     // CONSIDER PARAMETER
     XF_SPAPP_DECAYALT = 7,     // DECAY ALTITUDE
     XF_SPAPP_OUTCOORD = 8,     // OUTPUT COORDINATE SYSTEM
     XF_SPAPP_VCMOPT   = 9;     // VCM ADDITIONAL OPTIONS
  
  //*******************************************************************************
  
  // INDEXES OF DATA FIELDS OF AN INITIALIZED SP SATELLITE
  static const int  
     XF_SPSAT_SATNUM  = 1,     // SATELLITE NUMBER I5
     XF_SPSAT_DS50UTC = 2,     // SATELLITE'S EPOCH TIME IN DAYS SINCE 1950, UTC 
     XF_SPSAT_DS50TAI = 3,     // SATELLITE'S EPOCH TIME IN DAYS SINCE 1950, TAI
     XF_SPSAT_MU      = 4,     // MU VALUE 
     XF_SPSAT_HASCOV  = 5,     // COVARIANCE MATRIX FLAG
     XF_SPSAT_INTMODE = 6,     // INTEGRATION MODE
     XF_SPSAT_NTERMS  = 7,     // NUTATION TERMS
     XF_SPSAT_SPECTR  = 8;     // SPECTER COMPATIBILITY MODE
  
  //*******************************************************************************
  
  //// INDEXES OF PLANETARY CONTROL
  //static const int  
  //   XAI_PLANET_MERCURY = 1,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_VENUS   = 2,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_EARTH   = 3,   // NOT USED
  //   XAI_PLANET_MARS    = 4,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_JUPITER = 5,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_SATRUN  = 6,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_URANUS  = 7,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_NEPTUNE = 8,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_PLUTO   = 9,   // 0 = OFF, 1 = ON
  //   XAI_PLANET_SIZE    = 9;   // SIZE OF ARRAY
  //
  ////*******************************************************************************
     
  // DIFFERENT TIME TYPES FOR PASSING TO SPPROPALL
  static const int  
     SP_TIMETYPE_MSE      = 0,   // PROPAGATION TIME IS IN MINUTES SINCE EPOCH
     SP_TIMETYPE_DS50UTC  = 1;   // PROPAGATION TIME IS IN DAYS SINCE 1950, UTC
     
  
  // SP PROPAGATED DATA   
  static const int     
     XA_SPOUT_UTC       =  0,    // PROPAGATION TIME IN DAYS SINCE 1950, UTC
     XA_SPOUT_MSE       =  1,    // PROPAGATION TIME IN MINUTES SINCE THE SATELLITE'S EPOCH TIME   
     XA_SPOUT_UT1       =  2,    // PROPAGATION TIME IN DAYS SINCE 1950, UT1
     XA_SPOUT_TAI       =  3,    // PROPAGATION TIME IN DAYS SINCE 1950, TAI
     XA_SPOUT_ET        =  4,    // PROPAGATION TIME IN DAYS SINCE 1950, ET
     XA_SPOUT_REVNUM    =  5,    // REVOLUTION NUMBER
     XA_SPOUT_NTERMS    =  6,    // NUMBER OF NUTATION TERMS
     XA_SPOUT_ISSPECTR  =  7,    // SPECTR COMPATIBLE MODE (0=NOT COMPATIBLE, 1=COMPATIBLE)
     XA_SPOUT_HASCOVMTX =  8,    // HAS INPUT COVARIANCE MATRIX (0=NO, 1=YES)
  
     XA_SPOUT_J2KPOSX   = 10,    // J2K POSITION X (KM)
     XA_SPOUT_J2KPOSY   = 11,    // J2K POSITION Y (KM)
     XA_SPOUT_J2KPOSZ   = 12,    // J2K POSITION Z (KM)
     XA_SPOUT_J2KVELX   = 13,    // J2K VELOCITY X (KM/S)
     XA_SPOUT_J2KVELY   = 14,    // J2K VELOCITY Y (KM/S)
     XA_SPOUT_J2KVELZ   = 15,    // J2K VELOCITY Z (KM/S)
     XA_SPOUT_ECIPOSX   = 16,    // ECI POSITION X (KM)
     XA_SPOUT_ECIPOSY   = 17,    // ECI POSITION Y (KM)
     XA_SPOUT_ECIPOSZ   = 18,    // ECI POSITION Z (KM)
     XA_SPOUT_ECIVELX   = 19,    // ECI VELOCITY X (KM/S)
     XA_SPOUT_ECIVELY   = 20,    // ECI VELOCITY Y (KM/S)
     XA_SPOUT_ECIVELZ   = 21,    // ECI VELOCITY Z (KM/S)
     XA_SPOUT_LAT       = 22,    // GEODETIC LATITUDE (DEG)
     XA_SPOUT_LON       = 23,    // GEODETIC LONGITUDE (DEG)
     XA_SPOUT_HEIGHT    = 24,    // HEIGHT ABOVE GEOID (KM)
  
     XA_SPOUT_COVTYPE   = 30,    // COVARIANCE MATRIX TYPE, IF AVAILABLE: 1=UVW_DATE, 2=ECI_DATE, 3=EQNX_DATE, 11=UVW_J2K, 12=ECI_J2K, 13=EQNX_J2K
     XA_SPOUT_COVMTX    = 31,    // 6 BY 6 COVARIANCE MATRIX (31-66)
     
     XA_SPOUT_J2KACCX   = 70,    // J2K ACCELERATION X (KM/S^2)
     XA_SPOUT_J2KACCY   = 71,    // J2K ACCELERATION Y (KM/S^2)
     XA_SPOUT_J2KACCZ   = 72,    // J2K ACCELERATION Z (KM/S^2)
     XA_SPOUT_ECIACCX   = 73,    // ECI ACCELERATION X (KM/S^2)
     XA_SPOUT_ECIACCY   = 74,    // ECI ACCELERATION Y (KM/S^2)
     XA_SPOUT_ECIACCZ   = 75,    // ECI ACCELERATION Z (KM/S^2)
     
  
                                 
     XA_SPOUT_SIZE      = 128;     
  
  // DIFFERENT OPTIONS FOR GENERATING EPHEMERIDES FROM SP
  static const int  
     SP_EPHEM_ECI   = 1,       // ECI TEME OF DATE     - 0: TIME IN DAYS SINCE 1950 UTC, 1-3: POS (KM), 4-6: VEL (KM/SEC)
     SP_EPHEM_J2K   = 2;       // MEME OF J2K (4 TERMS)- 0: TIME IN DAYS SINCE 1950 UTC, 1-3: POS (KM), 4-6: VEL (KM/SEC) 
  
     
     
  
  // VCM ADDITIONAL OPTIONS
  static const int  
     VCMOPT_USEOWN    = 0,    // USE VCM'S OWN DATA
     VCMOPT_USEGLOBAL = 1;    // FORCE VCM TO USE GLOBAL SOLAR FLUX AND TIMING CONSTANTS DATA
  
  // RUN MODES
  static const int  
     IDX_RUNMODE_PERF = 0,   // PERFROMANCE PRIORITY. THIS MODE ALLOWS THE BUFFER OF INTEGRATION POINTS TO EXTEND FREELY
     IDX_RUNMODE_MEM  = 1;   // MEMORY PRIORITY. THIS MODE ONLY ALLOWS A NUMBER OF INTEGRATION POINTS TO BE SAVED IN THE BUFFER AT ANY ONE TIME
     
  //*******************************************************************************
     
  // PARTIALS SAVING MODES
  static const int  
     IDX_PARTIALS_SAVE = 1,     // SAVE PARTIALS IN THE BUFFER
     IDX_PARTIALS_DONT = 0;     // DON'T SAVE PARTIALS IN THE BUFFER
  
  // INDEXES OF DIFFERENT COVARIANCE MATRICES
  static const int  
     XF_COVMTX_UVW_DATE  =  1,     // UVW CONVARIANCE MATRIX - TEME OF DATE
     XF_COVMTX_XYZ_DATE  =  2,     // CARTESIAN COVARIANCE MATRIX - TEME OF DATE 
     XF_COVMTX_EQNX_DATE =  3,     // EQUINOCTIAL COVARIANCE MATRIX - TEME OF DATE (NOT AVAILABLE FOR "PARTIALS: ANALYTIC")
     XF_COVMTX_UVW_J2K   = 11,     // UVW CONVARIANCE MATRIX - MEME OF J2K
     XF_COVMTX_XYZ_J2K   = 12,     // CARTESIAN COVARIANCE MATRIX - MEME OF J2K
     XF_COVMTX_EQNX_J2K  = 13;     // EQUINOCTIAL COVARIANCE MATRIX - MEME OF J2K  (NOT AVAILABLE FOR "PARTIALS: ANALYTIC")
  //*******************************************************************************
  
  // INDEXES OF LUNAR/SOLAR AND PLANETS PERTURBATION MODES
  static const int  
     LSPERT_NONE      = 0,   // LUNAR/SOLAR PERTURBATION OFF
     LSPERT_ANALYTIC  = 1,   // LUNAR/SOLAR PERTURBATION ON (USING ANALYTIC MODE)
     LSPERT_JPL       = 2,   // LUNAR/SOLAR PERTURBATION USING JPL EPHEMERIS FILE
     LSPERT_ALL       = 3,   // LUNAR/SOLAR + ALL PLANETS PERTURBATION USING JPL EPHEMERIS FILE 
     LSPERT_BIG       = 4,   // LUNAR/SOLAR + JUPITER AND VENUS USING JPL EPHEMERIS FILE (BIG FORCE PLANETS) 
     LSPERT_MED       = 5,   // LUNAR/SOLAR + JUPITER, VENUS, SATURN, MARS, AND MERCURY USING JPL EPHEMERIS FILE (BIG AND MEDIUM FORCE PLANETS) 
     LSPERT_SMA       = 6;   // LUNAR/SOLAR + ALL PLANETS PERTURBATION EXCEPT PLUTO USING JPL EPHEMERIS FILE (BIG, MEDIUM, AND SMALL FORCE PLANETS)
  
  //*******************************************************************************   
  
// SpPropDll's function pointers declaration
extern fnPtrSpInit                         SpInit;
extern fnPtrSpGetInfo                      SpGetInfo;
extern fnPtrSpLoadFile                     SpLoadFile;
extern fnPtrSpLoadFileAll                  SpLoadFileAll;
extern fnPtrSpSaveFile                     SpSaveFile;
extern fnPtrSpInitSat                      SpInitSat;
extern fnPtrSpRemoveSat                    SpRemoveSat;
extern fnPtrSpRemoveAllSats                SpRemoveAllSats;
extern fnPtrSpGetCount                     SpGetCount;
extern fnPtrSpReset                        SpReset;
extern fnPtrSpGetApCtrl                    SpGetApCtrl;
extern fnPtrSpGetApCtrlAll                 SpGetApCtrlAll;
extern fnPtrSpSetApCtrl                    SpSetApCtrl;
extern fnPtrSpSetApCtrlAll                 SpSetApCtrlAll;
extern fnPtrSpGet4P                        SpGet4P;
extern fnPtrSpSet4P                        SpSet4P;
extern fnPtrSpGetPredCtrl                  SpGetPredCtrl;
extern fnPtrSpSetPredCtrl                  SpSetPredCtrl;
extern fnPtrSpGetSatData                   SpGetSatData;
extern fnPtrSpGetSatDataAll                SpGetSatDataAll;
extern fnPtrSpPropMse                      SpPropMse;
extern fnPtrSpPropDs50UTC                  SpPropDs50UTC;
extern fnPtrSpPropDs50UtcLLH               SpPropDs50UtcLLH;
extern fnPtrSpPropDs50UtcPos               SpPropDs50UtcPos;
extern fnPtrSpPropAll                      SpPropAll;
extern fnPtrSpGetStateDs50UTC              SpGetStateDs50UTC;
extern fnPtrSpSetStateDs50UTC              SpSetStateDs50UTC;
extern fnPtrSpSetAndProp                   SpSetAndProp;
extern fnPtrSpGetPropOut                   SpGetPropOut;
extern fnPtrSpGetCovMtx                    SpGetCovMtx;
extern fnPtrSpCompCovSigma                 SpCompCovSigma;
extern fnPtrSpSet4pAll                     SpSet4pAll;
extern fnPtrSpGet4pAll                     SpGet4pAll;
extern fnPtrSpSet4PCard                    SpSet4PCard;
extern fnPtrSpGet4PCard                    SpGet4PCard;
extern fnPtrSpAddFluxRec                   SpAddFluxRec;
extern fnPtrSpGetEphemTimes                SpGetEphemTimes;
extern fnPtrSpGenEphems                    SpGenEphems;
extern fnPtrSpGenEphemsVcm_OS              SpGenEphemsVcm_OS;
extern fnPtrSpPropAllSats                  SpPropAllSats;



void LoadSpPropDll();
void FreeSpPropDll();




#endif
// ========================= End of auto generated code ==========================
