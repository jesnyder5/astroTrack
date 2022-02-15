// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#ifndef SPPROPDLL_H
#define SPPROPDLL_H

#include "services/DllUtils.h"

// Provide the path to the dll/so
#ifdef _WIN32
  #define SpPropDll "SpProp.dll"
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
// 6 Consider paramter
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
// An error will occur if the actualEphPts is equal to the maxEphPts. In this case, the function will return all ephemereris times up to the time when that maxEphPts is reached.
// satKey             The satellite's unique key (in-Long)
// maxEphPts          Maximum number of possible ephemeris points that the function won't go over. That means actualEphPts can't be greater than maxEphPts even though the time span may have more points than that (in-Integer)
// startDs50UTC       Start time in days since 1950 UTC (in-Double)
// stopDs50UTC        Stop time in days since 1950 UTC (in-Double)
// minStepSize        Option to thin ephem points. Only pick ephem point when its next ephem point is older than the specified minStepSize (minutes). Set to 0 to get all ephem points (SP natural integration step size) (in-Double)
// actualEphPts       Actual number of ephem points that meet the requirements (out-Integer)
// ds50UTCArr         The resulting time array, in days since 1950 UTC, of all ephem points that meet the requirements (out-Double[*])
// returns 0 if the function successfully returns all the ephemeris times of the specified start/stop time span, non-0 if there is an error. Also if
typedef int (STDCALL *fnPtrSpGetEphemTimes)(__int64 satKey, int maxEphPts, double startDs50UTC, double stopDs50UTC, double minStepSize, int* actualEphPts, double ds50UTCArr[]);

// Indexes of SP 4P card fields
static const int  
   XF_4P_GEOIDX   = 1,       // Geopotential model to use
   XF_4P_BULGEFLG = 2,       // Earth gravity pertubations flag
   XF_4P_DRAGFLG  = 3,       // Drag pertubations flag 
   XF_4P_RADFLG   = 4,       // Radiation pressure pertubations flag
   XF_4P_LUNSOL   = 5,       // Lunar/Solar pertubations flag
   XF_4P_F10      = 6,       // F10 value
   XF_4P_F10AVG   = 7,       // F10 average value
   XF_4P_AP       = 8,       // Ap value
   XF_4P_TRUNC    = 9,       // Geopotential truncation order/degree/zonals
   XF_4P_CONVERG  = 10,      // Corrector step convergence criterion; exponent of 1/10; default = 10
   XF_4P_OGFLG    = 11,      // Outgassing pertubations flag
   XF_4P_TIDESFLG = 12,      // Solid earth and ocean tide pertubations flag
   XF_4P_INCOORD  = 13,      // Input vector coordinate system
   XF_4P_NTERMS   = 14,      // Nutation terms
   XF_4P_REEVAL   = 15,      // Recompute pertubations at each corrector step
   XF_4P_INTEGCTRL= 16,      // Variable of intergration control
   XF_4P_VARSTEP  = 17,      // Variable step size control
   XF_4P_INITSTEP = 18,      // Initial step size

   XF_4P_DCAFILE  = 21,      // DCA file name
   XF_4P_FLUXFILE = 22,      // Solar flux file name
   XF_4P_GEOFILE  = 23,      // Geopotential file name
   XF_4P_JPLFILE  = 24,      // JPL file name
   XF_4P_JPLSTART = 25,      // JPL start time
   XF_4P_JPLSTOP  = 26;      // JPL stop time
   
//*******************************************************************************

// Indexes of SP application control (preference) paramters
static const int  
   XF_SPAPP_GEODIR   = 1,     // Geopotential directory path
   XF_SPAPP_BUFSIZE  = 2,     // Buffer size
   XF_SPAPP_RUNMODE  = 3,     // Run mode
   XF_SPAPP_SAVEPART = 4,     // Save partials data
   XF_SPAPP_SPECTR   = 5,     // Specter compatibility mode
   XF_SPAPP_CONSIDER = 6,     // Consider paramter
   XF_SPAPP_DECAYALT = 7,     // Decay altitude
   XF_SPAPP_OUTCOORD = 8,     // Output coordinate system
   XF_SPAPP_VCMOPT   = 9;     // VCM additional options

//*******************************************************************************

// Indexes of data fields of an initialized SP satellite
static const int  
   XF_SPSAT_SATNUM  = 1,     // Satellite number I5
   XF_SPSAT_DS50UTC = 2,     // Satellite's epoch time in days since 1950, UTC 
   XF_SPSAT_DS50TAI = 3,     // Satellite's epoch time in days since 1950, TAI
   XF_SPSAT_MU      = 4,     // Mu value 
   XF_SPSAT_HASCOV  = 5,     // Covariance Matrix flag
   XF_SPSAT_INTMODE = 6,     // Integration mode
   XF_SPSAT_NTERMS  = 7,     // Nutation terms
   XF_SPSAT_SPECTR  = 8;     // Specter compatibility mode

//*******************************************************************************
   
// Different time types for passing to SpPropAll
static const int  
   SP_TIMETYPE_MSE      = 0,   // propagation time is in minutes since epoch
   SP_TIMETYPE_DS50UTC  = 1;   // propagation time is in days since 1950, UTC
   

// Sp propagated data   
static const int     
   XA_SPOUT_UTC       =  0,    // Propagation time in days since 1950, UTC
   XA_SPOUT_MSE       =  1,    // Propagation time in minutes since the satellite's epoch time   
   XA_SPOUT_UT1       =  2,    // Propagation time in days since 1950, UT1
   XA_SPOUT_TAI       =  3,    // Propagation time in days since 1950, TAI
   XA_SPOUT_ET        =  4,    // Propagation time in days since 1950, ET
   XA_SPOUT_REVNUM    =  5,    // Revolution number
   XA_SPOUT_NTERMS    =  6,    // Number of nutation terms
   XA_SPOUT_ISSPECTR  =  7,    // Spectr compatible mode (0=not compatible, 1=compatible)
   XA_SPOUT_HASCOVMTX =  8,    // Has input covariance matrix (0=no, 1=yes)

   XA_SPOUT_J2KPOSX   = 10,    // J2K position X (km)
   XA_SPOUT_J2KPOSY   = 11,    // J2K position Y (km)
   XA_SPOUT_J2KPOSZ   = 12,    // J2K position Z (km)
   XA_SPOUT_J2KVELX   = 13,    // J2K velocity X (km/s)
   XA_SPOUT_J2KVELY   = 14,    // J2K velocity Y (km/s)
   XA_SPOUT_J2KVELZ   = 15,    // J2K velocity Z (km/s)
   XA_SPOUT_ECIPOSX   = 16,    // ECI position X (km)
   XA_SPOUT_ECIPOSY   = 17,    // ECI position Y (km)
   XA_SPOUT_ECIPOSZ   = 18,    // ECI position Z (km)
   XA_SPOUT_ECIVELX   = 19,    // ECI velocity X (km/s)
   XA_SPOUT_ECIVELY   = 20,    // ECI velocity Y (km/s)
   XA_SPOUT_ECIVELZ   = 21,    // ECI velocity Z (km/s)
   XA_SPOUT_LAT       = 22,    // Geodetic latitude (deg)
   XA_SPOUT_LON       = 23,    // Geodetic longitude (deg)
   XA_SPOUT_HEIGHT    = 24,    // Height above geoid (km)

   XA_SPOUT_COVTYPE   = 30,    // Covariance matrix type, if available: 1=UVW_DATE, 2=ECI_DATE, 3=EQNX_DATE, 11=UVW_J2K, 12=ECI_J2K, 13=EQNX_J2K
   XA_SPOUT_COVMTX    = 31,    // 6 by 6 covariance matrix (31-66)
   
                               
   XA_SPOUT_SIZE      = 128;     
   
   

// VCM additional options
static const int  
   VCMOPT_USEOWN    = 0,    // use VCM's own data
   VCMOPT_USEGLOBAL = 1;    // force VCM to use global solar flux and timing constants data

// Run Modes
static const int  
   IDX_RUNMODE_PERF = 0,   // Perfromance priority. This mode allows the buffer of integration points to extend freely
   IDX_RUNMODE_MEM  = 1;   // Memory priority. This mode only allows a number of integration points to be saved in the buffer at any one time
   
//*******************************************************************************
   
// Partials Saving Modes
static const int  
   IDX_PARTIALS_SAVE = 1,     // Save partials in the buffer
   IDX_PARTIALS_DONT = 0;     // Don't save partials in the buffer

// Indexes of different covariance matrices
static const int  
   XF_COVMTX_UVW_DATE  =  1,     // UVW convariance matrix - TEME of DATE
   XF_COVMTX_XYZ_DATE  =  2,     // Cartesian covariance matrix - TEME of DATE 
   XF_COVMTX_EQNX_DATE =  3,     // Equinoctial covariance matrix - TEME of DATE (not available for "PARTIALS: ANALYTIC")
   XF_COVMTX_UVW_J2K   = 11,     // UVW convariance matrix - MEME of J2K
   XF_COVMTX_XYZ_J2K   = 12,     // Cartesian covariance matrix - MEME of J2K
   XF_COVMTX_EQNX_J2K  = 13;     // Equinoctial covariance matrix - MEME of J2K  (not available for "PARTIALS: ANALYTIC")
//*******************************************************************************




// SpPropDll's function pointers
fnPtrSpInit                         SpInit;
fnPtrSpGetInfo                      SpGetInfo;
fnPtrSpLoadFile                     SpLoadFile;
fnPtrSpLoadFileAll                  SpLoadFileAll;
fnPtrSpSaveFile                     SpSaveFile;
fnPtrSpInitSat                      SpInitSat;
fnPtrSpRemoveSat                    SpRemoveSat;
fnPtrSpRemoveAllSats                SpRemoveAllSats;
fnPtrSpGetCount                     SpGetCount;
fnPtrSpReset                        SpReset;
fnPtrSpGetApCtrl                    SpGetApCtrl;
fnPtrSpGetApCtrlAll                 SpGetApCtrlAll;
fnPtrSpSetApCtrl                    SpSetApCtrl;
fnPtrSpSetApCtrlAll                 SpSetApCtrlAll;
fnPtrSpGet4P                        SpGet4P;
fnPtrSpSet4P                        SpSet4P;
fnPtrSpGetPredCtrl                  SpGetPredCtrl;
fnPtrSpSetPredCtrl                  SpSetPredCtrl;
fnPtrSpGetSatData                   SpGetSatData;
fnPtrSpGetSatDataAll                SpGetSatDataAll;
fnPtrSpPropMse                      SpPropMse;
fnPtrSpPropDs50UTC                  SpPropDs50UTC;
fnPtrSpPropDs50UtcLLH               SpPropDs50UtcLLH;
fnPtrSpPropDs50UtcPos               SpPropDs50UtcPos;
fnPtrSpPropAll                      SpPropAll;
fnPtrSpGetStateDs50UTC              SpGetStateDs50UTC;
fnPtrSpSetStateDs50UTC              SpSetStateDs50UTC;
fnPtrSpSetAndProp                   SpSetAndProp;
fnPtrSpGetPropOut                   SpGetPropOut;
fnPtrSpGetCovMtx                    SpGetCovMtx;
fnPtrSpCompCovSigma                 SpCompCovSigma;
fnPtrSpSet4pAll                     SpSet4pAll;
fnPtrSpGet4pAll                     SpGet4pAll;
fnPtrSpSet4PCard                    SpSet4PCard;
fnPtrSpGet4PCard                    SpGet4PCard;
fnPtrSpAddFluxRec                   SpAddFluxRec;
fnPtrSpGetEphemTimes                SpGetEphemTimes;



void LoadSpPropDll();
void FreeSpPropDll();




#endif
// ========================= End of auto generated code ==========================
