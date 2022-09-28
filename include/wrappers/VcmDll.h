// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef VCMDLL_H
#define VCMDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define VcmDll "Vcm.dll"
#elif __APPLE__
  #define VcmDll "libvcm.dylib"
#else
  #define VcmDll "libvcm.so"
#endif


// Initializes Vcm DLL for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. The error occurs if the users forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisites section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Vcm.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmInit)(__int64 apPtr);


// Returns information about the current version of Vcm DLL. The information is placed in the string parameter you pass in
// The returned string provides information about the version number, build date, and the platform of the Vcm DLL. 
// infoStr            A string to hold the information about Vcm.dll (out-Character[128])
typedef void (STDCALL *fnPtrVcmGetInfo)(char infoStr[128]);


// Loads a text file containing Vcm's
// The users can use this function repeatedly to load Vcm records from different input files. However, only unique satKeys are stored in the binary tree. Duplicated satKeys won't be stored. 
// 
// State vectors can be included directly in the main input file or they can be read from a separate file identified with "ELTFIL=[pathname\filename]" or "VECFIL=[path/filename]" or "SPVMSG=[path/filename]".
// 
// This function only reads Vcm records from the main input file or Vcm records from the file identified with ELTFIL or VECFIL in the input file. It won't read anything else.
// vcmFile            The name of the file containing VCMs to be loaded (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmLoadFile)(char vcmFile[512]);


// Saves the currently loaded VCM's to a file
// If the users call this routine immediately after VcmLoadFile. The VCMs contents in the two file should be the same (minus duplicated VCMs or bad VCMs).
// 
// The purpose of this function is to save the current state of the loaded VCMs, usually used in GUI applications, for future use.
// vcmFile            The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmSaveFile)(char vcmFile[512], int saveMode, int saveForm);


// Removes a VCM represented by the satKey from memory
// If the users enter an invalid satKey - a non-existing satKey in memory, the function will return a non-zero value indicating an error.
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the VCM is removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmRemoveSat)(__int64 satKey);


// Removes all VCM's from memory
// The function returns zero if all the satellites are removed successfully from the Vcm DLL's binary tree.
// returns 0 if all VCM's are removed successfully from memory, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmRemoveAllSats)();


// Retrieves all of the currently loaded satKeys. These satKeys can be used to access the internal data for the VCM's
// See VcmGetLoaded for an example.
// This function is useful for dynamically allocating memory for the array that is passed to the function VcmGetLoaded().
// returns The number of VCM's currently loaded
typedef int (STDCALL *fnPtrVcmGetCount)();


// Retrieves all of the currently loaded satKeys. These satKeys can be used to access the internal data for the VCM's
// It is recommended that VcmGetCount() is used to count how many satellites are currently loaded in the Vcm DLL's binary tree. The users then use this number to dynamically allocate the satKeys array and pass it to this function. 
// 
// If the users prefer to pass a static array to the function, make sure it is big enough to store all the satKeys in memory.
// order              Specifies the order in which the satKeys should be returned: 0=ascending, 1=descending, 2=order as loaded (in-Integer)
// satKeys            The array in which to store the satKeys (out-Long[*])
typedef void (STDCALL *fnPtrVcmGetLoaded)(int order, __int64 satKeys[]);


// Adds a VCM using its 1-line or concatenated string formats
// If the satellite was previously added to the Vcm DLL's binary tree, the function also returns a negative value indicating an error. 
// 
// The users can use this function repeatedly to add many satellites (one satellite at a time) to the Vcm DLL's binary tree. 
// vcmString          1-line or concatenated string representation of the VCM (in-Character[4000])
// returns The satKey of the newly added VCM on success, a negative value on error
typedef __int64 (STDCALL *fnPtrVcmAddSatFrLines)(char vcmString[4000]);


// Works like VcmAddSatFrLines but designed for Matlab
// vcmString          1-line or concatenated string representation of the VCM (in-Character[4000])
// satKey             The satKey of the newly added VCM on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrVcmAddSatFrLinesML)(char vcmString[4000], __int64* satKey);


// Adds a VCM using its individually provided field values
// 
// The table below indicates starting character position for each field in the xs_vcm parameter:
// 
// 
// Starting Character Position
// Input Description
// 
//  0satellite name, A8
//  8common satellite name, A25
// 33geopotential name, A6 (WGS-72, WGS-84, EGM-96, ...)
// 39drag model, A12
// 51lunar solar pertubations, A3 (ON, OFF)
// 54radiation pressure pertubations, A3 (ON, OFF)
// 57Earth + ocean tides pertubation, A3 (ON, OFF)
// 60intrack thrust, A3 (ON, OFF)
// 63integration mode, A6 (ASW, OSW, SPADOC, ...)
// 69coordinate system, A5
// 74type of partial derivatives, A8
// 82step mode, A4 (AUTO, TIME, S)
// 86fixed step size indicator, A3 (ON, OFF)
// 89initial step size selection, A6 (AUTO, MANUAL)
// 
//  
// The table below indicates the index for each field in the xa_vcm array:
// 
// 
// Index (xa_vcm)
// index Interpretation
// 
//   0satellite number
//   1satellite's epoch time
//   2epoch revolution number
//   3J2K position X (km)
//   4J2K position Y (km)
//   5J2K position Z (km)
//   6J2K velocity X (km/s)
//   7J2K velocity Y (km/s)
//   8J2K velocity Z (km/s)
//   9ECI position X (km)
//  10ECI position Y (km)
//  11ECI position Z (km)
//  12ECI velocity X (km/s)
//  13ECI velocity Y (km/s)
//  14ECI velocity Z (km/s)
//  15EFG position X (km)
//  16EFG position Y (km)
//  17EFG position Z (km)
//  18EFG velocity X (km/s)
//  19EFG velocity Y (km/s)
//  20EFG velocity Z (km/s)
//  21geopotential zonals
//  22geopotential tesserals
//  23ballistic coefficient (m^2/kg)
//  24BDOT (m^2/kg-s)
//  25solar radiation pressure coefficient (m^2/kg)
//  26energy dissipation rate (w/kg)
//  27outgassing parameter/thrust acceleration (km/s^2)
//  28center of mass offset (m)
//  29solar flux F10
//  30average F10
//  31average Ap
//  32TAI - UTC (s)
//  33UT1 - UTC (s)
//  34UT1 rate (ms/day)
//  35polar motion X (arcsec)
//  36polar motion Y (arcsec)
//  37nutation terms
//  38leap second time in days since 1950 UTC
//  39initial step size
//  40integrator control error
//  41position u sigma (km)
//  42position v sigma (km)
//  43position w sigma (km)
//  44velocity u sigma (km/s)
//  45velocity v sigma (km/s)
//  46velocity w sigma (km/s)
//  47covariance matrix size
//  48weighted RM of last DC on the satellite
// 100the lower triangle portion of the full cov matrix (100-120: 6x6 covmtx, ..., 100-144: 9x9
// covmtx)
// 
// 
// The order of the values in the lower half of the covariance matrix is described in the VCM Data Description section.  
// 
// For a 6x6 covariance matrix, the 21 values should be entered in the xa_vcm array using index values 100-120.  
// 
// For a 9x9 covariance matrix, the 45 values should be entered using the index values 100-144.
// xs_vcm             The input string that contains all VCM's text fields (in-Character[512])
// xa_vcm             The input array that contains all VCM's numerical fields (in-Double[512])
// returns The satKey of the newly added VCM on success, a negative value on error
typedef __int64 (STDCALL *fnPtrVcmAddSatFrFields)(char xs_vcm[512], double xa_vcm[512]);


// Works like VcmAddSatFrFields but designed for Matlab
// 
// See VcmAddSatFrFields for definitions of the xs_vcm and xa_vcm parameters.
// xs_vcm             The input string that contains all VCM's text fields (in-Character[512])
// xa_vcm             The input array that contains all VCM's numerical fields (in-Double[512])
// satKey             The satKey of the newly added VCM on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrVcmAddSatFrFieldsML)(char xs_vcm[512], double xa_vcm[512], __int64* satKey);


// Retrieves VCM data associated with the input satKey
// satKey             The satKey of the loaded VCM (in-Long)
// xs_vcm             The output string that contains all VCM's text fields (out-Character[512])
// xa_vcm             The output array that contains all VCM's numerical fields (out-Double[512])
// returns 0 if the VCM data is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmRetrieveAllData)(__int64 satKey, char xs_vcm[512], double xa_vcm[512]);


// Updates a VCM using its individual field values. Note: satellite's number and epoch won't be updated
// 
// See VcmAddSatFrFields for definitions of the xs_vcm and xa_vcm parameters.
// satKey             The unique key of the satellite to update (in-Long)
// xs_vcm             The input string that contains all VCM's text fields (in-Character[512])
// xa_vcm             The input array that contains all VCM's numerical fields (in-Double[512])
// returns 0 if the Vcm data is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmUpdateSatFrFields)(__int64 satKey, char xs_vcm[512], double xa_vcm[512]);


// Retrieves the value of a specific field of a VCM
// 
// The table below shows the values for the xf_Vcm parameter:
// 
// 
// index
// index Interpretation
// 
//  1  Satellite number I5
//  2  Satellite international designator A8
//  3  Epoch YYYYDDDHHMMSS.SSS A17
//  4  Revolution number I5
//  5  position X (km) F16.8 
//  6  position Y (km) F16.8 
//  7  position Z (km) F16.8   
//  8  velocity X (km/s) F16.12
//  9  velocity Y (km/s) F16.12
// 10  velocity Z (km/s) F16.12
// 11  Geo Name A6
// 12  Geo zonals I2
// 13  Geo tesserals I2
// 14  Drag modelel A12 (NONE, JAC70/MSIS90) 
// 15  Lunar solar A3 (ON/OFF)
// 16  Radiation pressure pertubations A3 (ON/OFF)
// 17  Earth + ocean tides pertubations A3 (ON/OFF)
// 18  Intrack thrust A3 (ON/OFF)
// 19  Ballistic coefficient (m^2/kg)
// 20  Radiation pressure coefficient  (m^2/kg)
// 21  Outgassing parameter (km/s^2)
// 22  Center of mass offset (m)
// 23  Solar flux F10 I3
// 24  Solar flux F10 average I3
// 25  Ap average F5.1
// 26  TAI minus UTC (s)I2
// 27  UT1 minus UTC (s) F7.5
// 28  UT1 rate (ms/day)  F5.3
// 29  Polar motion X (arcsec) F6.4
// 30  Polar motion Y (arcsec) F6.4
// 31  Nutation terms I3
// 32  Leap second time YYYYDDDHHMMSS.SSS A17
// 33  Integration mode A6 (ASW, OSW, SPADOC)
// 34  Type of partial derivatives A8 (ANALYTIC, FULL NUM, FAST NUM)
// 35  Integration step mode A4 (AUTO/TIME, S)
// 36  Fixed step size indicator A3 (ON/OFF)
// 37  Initial step size selection A6 (AUTO/MANUAL)
// 38  Initial integration step size F8.3
// 39  Integrator error control E9.3
// 40  Weighted RMS of last DC E10.5
// 41  BDOT (M2/KG-S)
// 42  EDR (W/KG)
// 
// satKey             The satellite's unique key (in-Long)
// xf_Vcm             Predefined number specifying which field to set (in-Integer)
// valueStr           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the VCM is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmGetField)(__int64 satKey, int xf_Vcm, char valueStr[512]);


// Updates the value of a specific field of a VCM
// See VcmGetField for a description of the xf_Vcm parameter.
// satKey             The satellite's unique key (in-Long)
// xf_Vcm             Predefined number specifying which field to set (in-Integer)
// valueStr           The new value of the specified field, expressed as a string (in-Character[512])
// returns 0 if the VCM is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmSetField)(__int64 satKey, int xf_Vcm, char valueStr[512]);


// Retrieves all of the data for a VCM in a single function call
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// satName            Satellite name A8 (out-Character[8])
// epochDtg           Satellite epoch time A17 YYYYDDDHHMMSS.SSS (out-Character[17])
// revNum             Revolution number (out-Integer)
// posECI             ECI position (out-Double[3])
// velECI             ECI velocity (out-Double[3])
// geoName            Geopotential name A6 (WGS-72, WGS-84, EGM-96...) (out-Character[6])
// geoZonals          Geopotential zonals (out-Integer)
// geoTesserals       Geopotential tesserals (out-Integer)
// dragModel          Drag model A12 (NONE, JAC70/MSIS90...) (out-Character[12])
// lunarSolar         Lunar solar pertubations A3: ON, OFF (out-Character[3])
// radPress           Radiation pressure pertubations A3: ON, OFF (out-Character[3])
// earthTides         Earth + ocean tides pertubations A3: ON, OFF (out-Character[3])
// intrackThrust      Intrack thrust A3: ON, OFF (out-Character[3])
// bTerm              Ballistic coefficient (m2/kg) E13.10 (out-Double)
// agom               Solar radiation pressure coefficient (m2/kg) E13.10 (out-Double)
// ogParm             Outgassing parameter/Thrust acceleration (m/s2) E13.10 (out-Double)
// cmOffset           Center of mass offset (m) (out-Double)
// f10                Solar flux F10 I3 (out-Integer)
// f10Avg             Soluar flux F10 average I3 (out-Integer)
// apAvg              Ap average F5.1 (out-Double)
// tconRec            1: TaiMinusUTC, 2: UT1MinusUTC, 3: UT1Rate, 4: PolarX, 5: PolarY (out-Double[5])
// nTerms             Number of nutation terms I3 (out-Integer)
// leapYrDtg          Leap second time (out-Character[17])
// integMode          Integration mode A6: ASW, OSW, SPADOC (SPECTR=1 if ASW, OSW) (out-Character[6])
// partials           Type of partial derivatives A8 (Analytic, FULL NUM, FAST NUM) (out-Character[8])
// stepMode           Integrator step mode A4: AUTO, TIME, S (out-Character[4])
// fixStep            Fixed step size indicator A3: ON, OFF (out-Character[3])
// stepSelection      Initial step size selection A6: AUTO, MANUAL (out-Character[6])
// initStepSize       Initial integration step size  F8.3 (out-Double)
// errCtrl            Integrator error control  E9.3 (out-Double)
// rms                Weighted RMS of last DC on the satellite E10.5 (out-Double)
// returns ! 0 if the VCM is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrVcmGetAllFields)(__int64 satKey, int* satNum, char satName[8], char epochDtg[17], int* revNum, double posECI[3], double velECI[3], char geoName[6], int* geoZonals, int* geoTesserals, char dragModel[12], char lunarSolar[3], char radPress[3], char earthTides[3], char intrackThrust[3], double* bTerm, double* agom, double* ogParm, double* cmOffset, int* f10, int* f10Avg, double* apAvg, double tconRec[5], int* nTerms, char leapYrDtg[17], char integMode[6], char partials[8], char stepMode[4], char fixStep[3], char stepSelection[6], double* initStepSize, double* errCtrl, double* rms);


// Returns the concatenated string representation of a VCM by the satellite's satKey
// satKey             The satellite's unique key (in-Long)
// vcmLines           The resulting concatenated string representation of the VCM (out-Character[4000])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrVcmGetLines)(__int64 satKey, char vcmLines[4000]);


// Converts VCM 1-line format to multi-line format (as a concatenated string)
// vcm1Line           The input VCM 1-line format (in-Character[1500])
// vcmLines           The resulting concatenated string (out-Character[4000])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrVcm1LineToMultiLine)(char vcm1Line[1500], char vcmLines[4000]);


// Converts VCM multi-line format (as a concatenated string) to 1-line format 
// vcmLines           The input concatenated string (in-Character[4000])
// vcm1Line           The resulting VCM 1-line format (out-Character[1500])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrVcmMultiLineTo1Line)(char vcmLines[4000], char vcm1Line[1500]);


// Returns the first satKey from the currently loaded set of VCM's that contains the specified satellite number
// This function is useful when Vcm dll is used in applications that requires only one record (one Vcm entry) for one satellite and the applications refer to that Vcm by its satellite number. However, the Standardized Astrodynamic Algorithms library is only working with satKeys, this function helps to return the associated satKey of that satellite.
// satNum             The input satellite number (in-Integer)
// returns The satellite's unique key
typedef __int64 (STDCALL *fnPtrVcmGetSatKey)(int satNum);


// Works like VcmGetSatKey but designed for Matlab
// satNum             The input satellite number (in-Integer)
// satKey             The satellite's unique key (out-Long)
typedef void (STDCALL *fnPtrVcmGetSatKeyML)(int satNum, __int64* satKey);


// Computes a satKey from the input data
// This is the proper way to reconstruct a satKey from its fields. If the users use their own routine to do this, the computed satKey might be different. 
// satNum             The input satellite number (in-Integer)
// epochDtg           [yy]yydddhhmmss.sss or [yy]yyddd.ddddddd or DTG15, DTG17, DTG20 (in-Character[20])
// returns The satellite's unique key
typedef __int64 (STDCALL *fnPtrVcmFieldsToSatKey)(int satNum, char epochDtg[20]);


// Works like VcmFieldsToSatKey but designed for Matlab
// satNum             The input satellite number (in-Integer)
// epochDtg           [yy]yydddhhmmss.sss or [yy]yyddd.ddddddd or DTG15, DTG17, DTG20 (in-Character[20])
// satKey             The satellite's unique key (out-Long)
typedef void (STDCALL *fnPtrVcmFieldsToSatKeyML)(int satNum, char epochDtg[20], __int64* satKey);


// Constructs a multi-line VCM (as a concatenated string) from the VCM data stored in the input arrays.
// xa_vcm             Array containing VCM's numerical fields, see XA_VCM_? for array arrangement (in-Double[512])
// xs_vcm             Input string that contains all VCM's text fields, see XS_VCM_? for column arrangement (in-Character[512])
// vcmLines           The resulting concatenated string representation of a VCM (out-Character[4000])
typedef void (STDCALL *fnPtrVcmArrayToVcmLines)(double xa_vcm[512], char xs_vcm[512], char vcmLines[4000]);


// Constructs a 1-line VCM from the VCM data stored in the input arrays.
// xa_vcm             Array containing VCM's numerical fields, see XA_VCM_? for array arrangement (in-Double[512])
// xs_vcm             Input string that contains all VCM's text fields, see XS_VCM_? for column arrangement (in-Character[512])
// vcm1Line           The resulting 1-line VCM (out-Character[1500])
typedef void (STDCALL *fnPtrVcmArrayToVcm1Line)(double xa_vcm[512], char xs_vcm[512], char vcm1Line[1500]);


// Parses data either in 1-line or multi-line (as a concatenated string) VCM and stores that data into the output arrays
// This function only parses data from the input VCM but DOES NOT load/add the input VCM to memory.
// vcmString          An input 1-line or concatenated string representation of the VCM (in-Character[4000])
// xa_vcm             Array containing VCM's numerical fields, see XA_VCM_? for array arrangement (out-Double[512])
// xs_vcm             Output string that contains all VCM's text fields, see XS_VCM_? for column arrangement (out-Character[512])
// returns 0 if the VCM is parsed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrVcmStringToArray)(char vcmString[4000], double xa_vcm[512], char xs_vcm[512]);
    
  // STARTING LOCATION OF THE VCM'S TEXT DATA FIELDS
  static const int  
     XS_VCM_SATNAME       =   0,     // SATELLITE NAME A8
     XS_VCM_COMMNAME      =   8,     // COMMON SATELLITE NAME A25
     XS_VCM_GEONAME       =  33,     // GEOPOTENTIAL NAME A6 (WGS-72, WGS-84, EGM-96, ...)
     XS_VCM_DRAGMOD       =  39,     // DRAG MODEL A12
     XS_VCM_LUNAR         =  51,     // LUNAR SOLAR PERTUBATIONS A3 (ON, OFF)
     XS_VCM_RADPRESS      =  54,     // RADIATION PRESSURE PERTUBATIONS A3 (ON, OFF)
     XS_VCM_EARTHTIDES    =  57,     // EARTH + OCEAN TIDES PERTUBATION A3 (ON, OFF)
     XS_VCM_INTRACK       =  60,     // INTRACK THRUST A3 (ON, OFF)
     XS_VCM_INTEGMODE     =  63,     // INTEGRATION MODE A6 (ASW, OSW, SPADOC, ...)
     XS_VCM_COORDSYS      =  69,     // COORDINATE SYSTEM A5
     XS_VCM_PARTIALS      =  74,     // TYPE OF PARTIAL DERIVATIVES A8
     XS_VCM_STEPMODE      =  82,     // STEP MODE A4 (AUTO, TIME, S)
     XS_VCM_FIXEDSTEP     =  86,     // FIXED STEP SIZE INDICATOR A3 (ON, OFF)
     XS_VCM_STEPSEL       =  89,     // INITIAL STEP SIZE SELECTION A6 (AUTO, MANUAL)
     
     XS_VCM_SIZE          = 512;
  
  // INDEXES TO ACCESS DATA FROM AN ARRAY CONTAINING VCM NUMERICAL DATA FIELDS
  static const int     
     XA_VCM_SATNUM        =   0,     // SATELLITE NUMBER
     XA_VCM_EPOCHDS50UTC  =   1,     // SATELLITE'S EPOCH TIME
     XA_VCM_REVNUM        =   2,     // EPOCH REVOLUTION NUMBER
     XA_VCM_J2KPOSX       =   3,     // J2K POSITION X (KM)
     XA_VCM_J2KPOSY       =   4,     // J2K POSITION Y (KM)
     XA_VCM_J2KPOSZ       =   5,     // J2K POSITION Z (KM)
     XA_VCM_J2KVELX       =   6,     // J2K VELOCITY X (KM/S)
     XA_VCM_J2KVELY       =   7,     // J2K VELOCITY Y (KM/S)
     XA_VCM_J2KVELZ       =   8,     // J2K VELOCITY Z (KM/S)
     XA_VCM_ECIPOSX       =   9,     // ECI POSITION X (KM)
     XA_VCM_ECIPOSY       =  10,     // ECI POSITION Y (KM)
     XA_VCM_ECIPOSZ       =  11,     // ECI POSITION Z (KM)
     XA_VCM_ECIVELX       =  12,     // ECI VELOCITY X (KM/S)
     XA_VCM_ECIVELY       =  13,     // ECI VELOCITY Y (KM/S)
     XA_VCM_ECIVELZ       =  14,     // ECI VELOCITY Z (KM/S)
     XA_VCM_EFGPOSX       =  15,     // EFG POSITION X (KM)
     XA_VCM_EFGPOSY       =  16,     // EFG POSITION Y (KM)
     XA_VCM_EFGPOSZ       =  17,     // EFG POSITION Z (KM)
     XA_VCM_EFGVELX       =  18,     // EFG VELOCITY X (KM/S)
     XA_VCM_EFGVELY       =  19,     // EFG VELOCITY Y (KM/S)
     XA_VCM_EFGVELZ       =  20,     // EFG VELOCITY Z (KM/S)
     XA_VCM_GEOZON        =  21,     // GEOPOTENTIAL ZONALS
     XA_VCM_GEOTES        =  22,     // GEOPOTENTIAL TESSERALS
     XA_VCM_BTERM         =  23,     // BALLISTIC COEFFICIENT (M^2/KG)
     XA_VCM_BDOT          =  24,     // BDOT (M^2/KG-S)
     XA_VCM_AGOM          =  25,     // SOLAR RADIATION PRESSURE COEFFICIENT (M^2/KG)
     XA_VCM_EDR           =  26,     // ENERGY DISSIPATION RATE (W/KG)
     XA_VCM_OGPARM        =  27,     // OUTGASSING PARAMETER/THRUST ACCELERATION (M/S^2)
     XA_VCM_CMOFFSET      =  28,     // CENTER OF MASS OFFSET (M)
     XA_VCM_F10           =  29,     // SOLAR FLUX F10
     XA_VCM_F10AVG        =  30,     // AVERAGE F10
     XA_VCM_APAVG         =  31,     // AVERAGE AP
     XA_VCM_TAIMUTC       =  32,     // TAI - UTC (S)
     XA_VCM_UT1MUTC       =  33,     // UT1 - UTC (S)
     XA_VCM_UT1RATE       =  34,     // UT1 RATE (MS/DAY)
     XA_VCM_POLMOTX       =  35,     // POLAR MOTION X (ARCSEC)
     XA_VCM_POLMOTY       =  36,     // POLAR MOTION Y (ARCSEC)
     XA_VCM_NUTTERMS      =  37,     // NUTATION TERMS
     XA_VCM_LEAPDS50UTC   =  38,     // LEAP SECOND TIME IN DAYS SINCE 1950 UTC
     XA_VCM_INITSTEP      =  39,     // INITIAL STEP SIZE
     XA_VCM_ERRCTRL       =  40,     // INTEGRATOR CONTROL ERROR 
     XA_VCM_POSUSIG       =  41,     // POSITION U SIGMA (KM)   
     XA_VCM_POSVSIG       =  42,     // POSITION V SIGMA (KM)
     XA_VCM_POSWSIG       =  43,     // POSITION W SIGMA (KM)
     XA_VCM_VELUSIG       =  44,     // VELOCITY U SIGMA (KM/S)
     XA_VCM_VELVSIG       =  45,     // VELOCITY V SIGMA (KM/S)
     XA_VCM_VELWSIG       =  46,     // VELOCITY W SIGMA (KM/S)
     XA_VCM_COVMTXSIZE    =  47,     // COVARIANCE MATRIX SIZE
     XA_VCM_RMS           =  48,     // WEIGHTED RM OF LAST DC ON THE SATELLITE
     XA_VCM_COVELEMS      = 100,     // THE LOWER TRIANGLE PORTION OF THE FULL COV MATRIX (100-120: 6X6 COVMTX, ..., 100-144: 9X9 COVMTX)
     
     XA_VCM_SIZE          = 512;
  
  // INDEXES OF VCM DATA FIELDS
  static const int  
     XF_VCM_SATNUM    =  1,      // SATELLITE NUMBER I5
     XF_VCM_SATNAME   =  2,      // SATELLITE INTERNATIONAL DESIGNATOR A8
     XF_VCM_EPOCH     =  3,      // EPOCH YYYYDDDHHMMSS.SSS A17
     XF_VCM_REVNUM    =  4,      // REVOLUTION NUMBER I5
     XF_VCM_POSX      =  5,      // POSITION X (KM) F16.8 
     XF_VCM_POSY      =  6,      // POSITION Y (KM) F16.8 
     XF_VCM_POSZ      =  7,      // POSITION Z (KM) F16.8   
     XF_VCM_VELX      =  8,      // VELOCITY X (KM/S) F16.12
     XF_VCM_VELY      =  9,      // VELOCITY Y (KM/S) F16.12
     XF_VCM_VELZ      = 10,      // VELOCITY Z (KM/S) F16.12
     XF_VCM_GEONAME   = 11,      // GEO NAME A6
     XF_VCM_GEOZONALS = 12,      // GEO ZONALS I2
     XF_VCM_GEOTESSER = 13,      // GEO TESSERALS I2
     XF_VCM_DRAGMODE  = 14,      // DRAG MODELEL A12 (NONE, JAC70/MSIS90) 
     XF_VCM_LUNSOL    = 15,      // LUNAR SOLAR A3 (ON/OFF)
     XF_VCM_RADPRESS  = 16,      // RADIATION PRESSURE PERTUBATIONS A3 (ON/OFF)
     XF_VCM_ERTHTIDES = 17,      // EARTH + OCEAN TIDES PERTUBATIONS A3 (ON/OFF)
     XF_VCM_INTRACK   = 18,      // INTRACK THRUST A3 (ON/OFF)
     XF_VCM_BTERM     = 19,      // BALLISTIC COEFFICIENT (M^2/KG)
     XF_VCM_AGOM      = 20,      // RADIATION PRESSURE COEFFICIENT  (M^2/KG)
     XF_VCM_OGPARM    = 21,      // OUTGASSING PARAMETER (M/S^2)
     XF_VCM_CMOFFSET  = 22,      // CENTER OF MASS OFFSET (M)
     XF_VCM_F10       = 23,      // SOLAR FLUX F10 I3
     XF_VCM_F10AVG    = 24,      // SOLAR FLUX F10 AVERAGE I3
     XF_VCM_APAVG     = 25,      // AP AVERAGE F5.1
     XF_VCM_TAIMUTC   = 26,      // TAI MINUS UTC (S)I2
     XF_VCM_UT1MUTC   = 27,      // UT1 MINUS UTC (S) F7.5
     XF_VCM_UT1RATE   = 28,      // UT1 RATE (MS/DAY)  F5.3
     XF_VCM_POLARX    = 29,      // POLAR MOTION X (ARCSEC) F6.4
     XF_VCM_POLARY    = 30,      // POLAR MOTION Y (ARCSEC) F6.4
     XF_VCM_NTERMS    = 31,      // NUTATION TERMS I3
     XF_VCM_LEAPYR    = 32,      // LEAP SECOND TIME YYYYDDDHHMMSS.SSS A17
     XF_VCM_INTEGMODE = 33,      // INTEGRATION MODE A6 (ASW, OSW, SPADOC)
     XF_VCM_PARTIALS  = 34,      // TYPE OF PARTIAL DERIVATIVES A8 (ANALYTIC, FULL NUM, FAST NUM)
     XF_VCM_STEPMODE  = 35,      // INTEGRATION STEP MODE A4 (AUTO/TIME, S)
     XF_VCM_FIXEDSTEP = 36,      // FIXED STEP SIZE INDICATOR A3 (ON/OFF)
     XF_VCM_STEPSLCTN = 37,      // INITIAL STEP SIZE SELECTION A6 (AUTO/MANUAL)
     XF_VCM_STEPSIZE  = 38,      // INITIAL INTEGRATION STEP SIZE F8.3
     XF_VCM_ERRCTRL   = 39,      // INTEGRATOR ERROR CONTROL E9.3
     XF_VCM_RMS       = 40,      // WEIGHTED RMS OF LAST DC E10.5
     XF_VCM_BDOT      = 41,      // BDOT (M2/KG-S)
     XF_VCM_EDR       = 42;      // EDR (W/KG)
     
     
  
  // MAXIMUM STRING LENGTH OF A MULTI-LINE VCM CONCATENATED INTO ONE BIG STRING
  #define VCMSTRLEN   4000 
  
  
  // MAXIMUM STRING LENGTH OF A 1-LINE VCM STRING
  static const int VCM1LINELEN = 1500;
  
// VcmDll's function pointers declaration
extern fnPtrVcmInit                        VcmInit;
extern fnPtrVcmGetInfo                     VcmGetInfo;
extern fnPtrVcmLoadFile                    VcmLoadFile;
extern fnPtrVcmSaveFile                    VcmSaveFile;
extern fnPtrVcmRemoveSat                   VcmRemoveSat;
extern fnPtrVcmRemoveAllSats               VcmRemoveAllSats;
extern fnPtrVcmGetCount                    VcmGetCount;
extern fnPtrVcmGetLoaded                   VcmGetLoaded;
extern fnPtrVcmAddSatFrLines               VcmAddSatFrLines;
extern fnPtrVcmAddSatFrLinesML             VcmAddSatFrLinesML;
extern fnPtrVcmAddSatFrFields              VcmAddSatFrFields;
extern fnPtrVcmAddSatFrFieldsML            VcmAddSatFrFieldsML;
extern fnPtrVcmRetrieveAllData             VcmRetrieveAllData;
extern fnPtrVcmUpdateSatFrFields           VcmUpdateSatFrFields;
extern fnPtrVcmGetField                    VcmGetField;
extern fnPtrVcmSetField                    VcmSetField;
extern fnPtrVcmGetAllFields                VcmGetAllFields;
extern fnPtrVcmGetLines                    VcmGetLines;
extern fnPtrVcm1LineToMultiLine            Vcm1LineToMultiLine;
extern fnPtrVcmMultiLineTo1Line            VcmMultiLineTo1Line;
extern fnPtrVcmGetSatKey                   VcmGetSatKey;
extern fnPtrVcmGetSatKeyML                 VcmGetSatKeyML;
extern fnPtrVcmFieldsToSatKey              VcmFieldsToSatKey;
extern fnPtrVcmFieldsToSatKeyML            VcmFieldsToSatKeyML;
extern fnPtrVcmArrayToVcmLines             VcmArrayToVcmLines;
extern fnPtrVcmArrayToVcm1Line             VcmArrayToVcm1Line;
extern fnPtrVcmStringToArray               VcmStringToArray;



void LoadVcmDll();
void FreeVcmDll();




#endif
// ========================= End of auto generated code ==========================
