// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef SPVECDLL_H
#define SPVECDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define SpVecDll "SpVec.dll"
#elif __APPLE__
  #define SpVecDll "libspvec.dylib"
#else
  #define SpVecDll "libspvec.so"
#endif


// Initializes SpVec DLL for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. The error occurs if the users forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisites section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if SpVec.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecInit)(__int64 apPtr);


// Returns information about the current version of SpVec DLL. The information is placed in the string parameter you pass in
// The returned string provides information about the version number, build date, and the platform of the SpVec DLL. 
// infoStr            A string to hold the information about SpVec.dll (out-Character[128])
typedef void (STDCALL *fnPtrSpVecGetInfo)(char infoStr[128]);


// Loads a text file containing SpVec's
// The users can use this function repeatedly to load B1P records from different input files. However, only unique satKeys are stored in the binary tree. Duplicated satKeys won't be stored. 
// 
// B1P records can be included directly in the main input file or they can be read from a separate file identified with "ELTFIL=[pathname\filename]" or "VECFIL=[path/filename]".
// 
// This function only reads B1P records from the main input file or B1P records from the file identified with ELTFIL or VECFIL in the input file. It won't read anything else.
// spVecFile          The name of the file containing osculating vectors (SpVecs) to be loaded (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecLoadFile)(char spVecFile[512]);


// Saves the currently loaded SpVecs's to a file
// If the users call this routine immediately after SpVecLoadFile. The SPVECs contents in the two file should be the same (minus duplicated SPVECs or bad SPVECs).
// 
// The purpose of this function is to save the current state of the loaded SPVECs, usually used in GUI applications, for future use.
// spVecFile          The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecSaveFile)(char spVecFile[512], int saveMode, int saveForm);


// Removes an SpVec represented by the satKey from memory
// If the users enter an invalid satKey, a non-existing satKey in memory, the function will return a non-zero value indicating an error.
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the SpVec is removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecRemoveSat)(__int64 satKey);


// Removes all SpVec's from memory
// returns 0 if all SpVec's are removed successfully from memory, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecRemoveAllSats)();


// Retrieves all of the currently loaded satKeys. These satKeys can be used to access the internal data for the SpVec's
// See SpVecGetLoaded for example.
// This function is useful for dynamically allocating memory for the array that is passed to the function SpVecGetLoaded().
// returns The number of SpVec's currently loaded
typedef int (STDCALL *fnPtrSpVecGetCount)();


// Retrieves all of the currently loaded satKeys. These satKeys can be used to access the internal data for the SpVec's
// It is recommended that SpVecGetCount() is used to count how many satellites are currently loaded in the SpVec DLL's binary tree. The users then use this number to dynamically allocate the satKeys array and pass it to this function. 
// 
// If the users prefer to pass a static array to the function, make sure it is big enough to store all the satKeys in memory.
// order              Specifies the order in which the satKeys should be returned: 0=ascending, 1=descending, 2=order as loaded (in-Integer)
// satKeys            The array in which to store the satKeys (out-Long[*])
typedef void (STDCALL *fnPtrSpVecGetLoaded)(int order, __int64 satKeys[]);


// Adds an SpVec using its directly specified first and second lines
// If the satellite was previously added to the SpVec DLL's binary tree, the function also returns a negative value indicating an error. 
// 
// The users can use this function repeatedly to add many satellites (one satellite at a time) to the SpVec DLL's binary tree. 
// line1              The first input line of the two line element set (in-Character[512])
// line2              The second input line of the two line element set (in-Character[512])
// returns The satKey of the newly added SpVec on success, a negative value on error
typedef __int64 (STDCALL *fnPtrSpVecAddSatFrLines)(char line1[512], char line2[512]);


// Works like SpVecAddSatFrLines but designed for Matlab
// line1              The first input line of the two line element set (in-Character[512])
// line2              The second input line of the two line element set (in-Character[512])
// satKey             The satKey of the newly added SpVec on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrSpVecAddSatFrLinesML)(char line1[512], char line2[512], __int64* satKey);


// Adds an SpVec using its individually provided field values
// pos                position vector (km) (in-Double[3])
// vel                velocity vector (m/s) (in-Double[3])
// secClass           Security classification: U=Unclass, C=Confidential, S=Secret (in-Character)
// satNum             Satellite number (in-Integer)
// satName            Satellite name A8 (in-Character[8])
// epochDtg           Satellite's epoch A17 (YYYYDDDHHMMSS.SSS) (in-Character[17])
// revNum             Revolution number (in-Integer)
// elsetNum           Element set number (in-Integer)
// bterm              Bterm m^2/kg (in-Double)
// agom               Agom  m^2/kg (in-Double)
// ogParm             Outgassing parameter (km/s^2) (in-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (in-Character[5])
// returns The satKey of the newly added SpVec on success, a negative value on error
typedef __int64 (STDCALL *fnPtrSpVecAddSatFrFields)(double pos[3], double vel[3], char secClass, int satNum, char satName[8], char epochDtg[17], int revNum, int elsetNum, double bterm, double agom, double ogParm, char coordSys[5]);


// Works like SpVecAddSatFrFields but designed for Matlab 
// pos                position vector (km) (in-Double[3])
// vel                velocity vector (m/s) (in-Double[3])
// secClass           Security classification: U=Unclass, C=Confidential, S=Secret (in-Character)
// satNum             Satellite number (in-Integer)
// satName            Satellite name A8 (in-Character[8])
// epochDtg           Satellite's epoch A17 (YYYYDDDHHMMSS.SSS) (in-Character[17])
// revNum             Revolution number (in-Integer)
// elsetNum           Element set number (in-Integer)
// bterm              Bterm m^2/kg (in-Double)
// agom               Agom  m^2/kg (in-Double)
// ogParm             Outgassing parameter (km/s^2) (in-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (in-Character[5])
// satKey             The satKey of the newly added SpVec on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrSpVecAddSatFrFieldsML)(double pos[3], double vel[3], char secClass, int satNum, char satName[8], char epochDtg[17], int revNum, int elsetNum, double bterm, double agom, double ogParm, char coordSys[5], __int64* satKey);


// Updates an SpVec satellite's data in memory using individually provided field values. Note: satNum, epoch string can't be updated.
// The satellite's unique key will not be changed in this function call. 
// satKey             The sattelite's unique key (in-Long)
// pos                position vector (km) (in-Double[3])
// vel                velocity vector (m/s) (in-Double[3])
// secClass           Security classification: U=Unclass, C=Confidential, S=Secret (in-Character)
// satName            Satellite name A8 (in-Character[8])
// revNum             Revolution number (in-Integer)
// elsetNum           Element set number (in-Integer)
// bterm              Bterm m^2/kg (in-Double)
// agom               Agom  m^2/kg (in-Double)
// ogParm             Outgassing parameter (km/s^2) (in-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (in-Character[5])
// returns 0 if the SpVec is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecUpdateSatFrFields)(__int64 satKey, double pos[3], double vel[3], char secClass, char satName[8], int revNum, int elsetNum, double bterm, double agom, double ogParm, char coordSys[5]);


// Retrieves the value of a specific field of an SpVec
// 
// The table below shows the values for the xf_SpVec parameter:
// 
// 
// Index
// Index Interpretation
// 
//  1-3First 3 elements of 1P
//  4-6Second 3 elements of 1P
//  7Security classification
//  9Satellite number
// 10Satellite common name
// 11Epoch date
// 12Epoch revolution number
// 13Elset number
// 14Ballistic coefficient
// 15Radiation pressure coefficient
// 16Outgassing parameter
// 17Input coordinate system
// 
// satKey             The satellite's unique key (in-Long)
// xf_SpVec           Predefined number specifying which field to set (in-Integer)
// valueStr           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the SpVec is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecGetField)(__int64 satKey, int xf_SpVec, char valueStr[512]);


// Updates the value of a field of an SpVec
// See SpVecGetField for a description of the xf_SpVec parameter.  satNum (9) and epoch date (11) cannot be altered.
// The set value type was intentionally chosen as a character string because it allows the users to set value for different data types.
// satKey             The satellite's unique key (in-Long)
// xf_SpVec           Predefined number specifying which field to set (in-Integer)
// valueStr           The new value of the specified field, expressed as a string (in-Character[512])
// returns 0 if the SpVec is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecSetField)(__int64 satKey, int xf_SpVec, char valueStr[512]);


// Retrieves all of the data for an SpVec satellite in a single function call
// satKey             The satellite's unique key (in-Long)
// pos                position vector (km) (out-Double[3])
// vel                velocity vector (m/s) (out-Double[3])
// secClass           Security classification U: unclass, C: confidential, S: Secret (out-Character)
// satNum             Satellite number (out-Integer)
// satName            Satellite name A8 (out-Character[8])
// epochDtg           Satellite's epoch A17 (YYYYDDDHHMMSS.SSS) (out-Character[17])
// revNum             Revolution number (out-Integer)
// elsetNum           Element set number (out-Integer)
// bterm              Bterm m^2/kg (out-Double)
// agom               Agom  m^2/kg (out-Double)
// ogParm             Outgassing parameter (km/s^2) (out-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (out-Character[5])
// returns 0 if the SpVec is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecGetAllFields)(__int64 satKey, double pos[3], double vel[3], char* secClass, int* satNum, char satName[8], char epochDtg[17], int* revNum, int* elsetNum, double* bterm, double* agom, double* ogParm, char coordSys[5]);


// Retrieves all of the data for an SpVec satellite in a single function call
// line1              the first input line of a 1P/2P card (in-Character[512])
// line2              the second input line of a 1P/2P card (in-Character[512])
// pos                position vector (km) (out-Double[3])
// vel                velocity vector (m/s) (out-Double[3])
// secClass           Security classification U: unclass, C: confidential, S: Secret (out-Character)
// satNum             Satellite number (out-Integer)
// satName            Satellite name A8 (out-Character[8])
// epochDtg           Satellite's epoch A17 (YYYYDDDHHMMSS.SSS) (out-Character[17])
// revNum             Revolution number (out-Integer)
// elsetNum           Element set number (out-Integer)
// bterm              Bterm m^2/kg (out-Double)
// agom               Agom  m^2/kg (out-Double)
// ogParm             Outgassing parameter (km/s^2) (out-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (out-Character[5])
// returns 0 if the SpVec data is successfully parsed, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecParse)(char line1[512], char line2[512], double pos[3], double vel[3], char* secClass, int* satNum, char satName[8], char epochDtg[17], int* revNum, int* elsetNum, double* bterm, double* agom, double* ogParm, char coordSys[5]);


// Parses SPVEC data from the input first and second lines of an 1P/2P state vector and store that data back into the output parameters.
// This function only parses data from the input SPVEC but DOES NOT load/add the input SPVEC to memory.
// line1              The first line of the two line element set. (in-Character[512])
// line2              The second line of the two line element set (in-Character[512])
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (out-Double[512])
// xs_spVec           Output string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (out-Character[512])
// returns 0 if the SPVEC is parsed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrSpVecLinesToArray)(char line1[512], char line2[512], double xa_spVec[512], char xs_spVec[512]);


// Returns the first and second lines of the 1P/2P representation of an SpVec
// satKey             The satellite's unique key (in-Long)
// line1              The resulting first line of a 1P/2P card (out-Character[512])
// line2              The resulting second line of a 1P/2P card (out-Character[512])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrSpVecGetLines)(__int64 satKey, char line1[512], char line2[512]);


// Constructs 1P/2P cards from individually provided SpVec data fields
// Returned line1 and line2 are empty if the function fails to construct the lines as requested.
// pos                position vector (km) (in-Double[3])
// vel                velocity vector (m/s) (in-Double[3])
// secClass           Security classification U: unclass, C: confidential, S: Secret (in-Character)
// satNum             Satellite number (in-Integer)
// satName            Satellite name A8 (in-Character[8])
// epochDtg           Satellite's epoch A17 (YYYYDDDHHMMSS.SSS) (in-Character[17])
// revNum             Revolution number (in-Integer)
// elsetNum           Element set number (in-Integer)
// bterm              Bterm m^2/kg (in-Double)
// agom               Agom  m^2/kg (in-Double)
// ogParm             Outgassing parameter (km/s^2) (in-Double)
// coordSys           Input coordinate system A5 - TMDAT/TMEPO: Epoch, MMB50/MMJ2K: J2000 (in-Character[5])
// line1              The resulting first line of a 1P/2P card (out-Character[512])
// line2              The resulting second line of a 1P/2P card (out-Character[512])
typedef void (STDCALL *fnPtrSpVecFieldsToLines)(double pos[3], double vel[3], char secClass, int satNum, char satName[8], char epochDtg[17], int revNum, int elsetNum, double bterm, double agom, double ogParm, char coordSys[5], char line1[512], char line2[512]);


// Constructs 1P/2P cards from SPVEC data stored in the input arrays.
// This function only parses data from the input data but DOES NOT load/add the SPVEC to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (in-Double[512])
// xs_spVec           Input string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (in-Character[512])
// line1              Returned first line of an SPVEC. (out-Character[512])
// line2              Returned second line of an SPVEC (out-Character[512])
typedef void (STDCALL *fnPtrSpVecArrayToLines)(double xa_spVec[512], char xs_spVec[512], char line1[512], char line2[512]);


// Returns the first satKey from the currently loaded set of SpVec's that contains the specified satellite number
// This function is useful when SpVec DLL is used in applications that requires only one record (one SpVec entry) for one satellite and the applications refer to that SpVec by its satellite number. However, the Standardized Astrodynamic Algorithms library is only working with satKeys, this function helps to return the associated satKey of that satellite.
// satNum             The input satellite number (in-Integer)
// returns The satellite's unique key
typedef __int64 (STDCALL *fnPtrSpVecGetSatKey)(int satNum);


// This function is similar to SpVecGetSatKey but designed to be used in Matlab. 
// This function is useful when SpVec DLL is used in applications that requires only one record (one SpVec entry) for one satellite and the applications refer to that SpVec by its satellite number. However, the Standardized Astrodynamic Algorithms library is only working with satKeys, this function helps to return the associated satKey of that satellite.
// satNum             The input satellite number (in-Integer)
// satKey             The satellite's unique key (out-Long)
typedef void (STDCALL *fnPtrSpVecGetSatKeyML)(int satNum, __int64* satKey);


// Computes a satKey from the input data
// This is the proper way to reconstruct a satKey from its fields. If the users use their own routine to do this, the computed satKey might be different.
// satNum             The input satellite number (in-Integer)
// epochDtg           [yy]yydddhhmmss.sss or [yy]yyddd.ddddddd or DTG15, DTG17, DTG20 (in-Character[20])
// returns The resulting satellite key
typedef __int64 (STDCALL *fnPtrSpVecFieldsToSatKey)(int satNum, char epochDtg[20]);


// This function is similar to SpVecFieldsToSatKey but designed to be used in Matlab. 
// This is the proper way to reconstruct a satKey from its fields. If the users use their own routine to do this, the computed satKey might be different.
// satNum             The input satellite number (in-Integer)
// epochDtg           [yy]yydddhhmmss.sss or [yy]yyddd.ddddddd or DTG15, DTG17, DTG20 (in-Character[20])
// satKey             The resulting satellite key (out-Long)
typedef void (STDCALL *fnPtrSpVecFieldsToSatKeyML)(int satNum, char epochDtg[20], __int64* satKey);


// Adds an SpVec using its individually provided field values
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (in-Double[512])
// xs_spVec           Input string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (in-Character[512])
// returns The satKey of the newly added SPVEC on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrSpVecAddSatFrArray)(double xa_spVec[512], char xs_spVec[512]);


// Adds an SpVec using its individually provided field values
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (in-Double[512])
// xs_spVec           Input string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (in-Character[512])
// satKey             The satKey of the newly added SPVEC on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrSpVecAddSatFrArrayML)(double xa_spVec[512], char xs_spVec[512], __int64* satKey);


// Updates existing SPVEC data with the provided new data stored in the input parameters. Note: satNum, epoch string can't be updated.
// satKey             The satellite's unique key (in-Long)
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (in-Double[512])
// xs_spVec           Input string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (in-Character[512])
// returns 0 if the SPVEC is successfully updated, non-0 if there is an error.
typedef int (STDCALL *fnPtrSpVecUpdateSatFrArray)(__int64 satKey, double xa_spVec[512], char xs_spVec[512]);


// Retrieves SPVEC data and stored it in the passing parameters
// 
// The table below indicates which index values correspond to which fields in the xa_spVec array. 
// 
// 
// Index
// Index Interpretation
// 
// 0Satellite number
// 1Epoch date in Ds50UTC
// 2Epoch revolution number
// 3Eslet number
// 4Ballistic coefficient (m^2/kg)
// 5Radiation pressure coefficient (m^2/kg)
// 6Outgassing parameter (km/s^2)
// 7Input coordinate system
// 20X component of satellite's position (km)
// 21Y component of satellite's position (km)
// 22Z component of satellite's position (km)
// 23X component of satellite's velocity (km/s)
// 24Y component of satellite's velocity (km/s)
// 25Z component of satellite's velocity (km/s)
// 
// 
// 
// The table below indicates which columns corerspond to which fields in the xs_spVec string.
// 
// 
// Index
// Index Interpretation
// 
// 0Security classification
// 1-8Satellite common name
// 
// satKey             The satellite's unique key (in-Long)
// xa_spVec           Array containing SPVEC's numerical fields, see XA_SPVEC_? for array arrangement (out-Double[512])
// xs_spVec           Output string that contains all SPVEC's text fields, see XS_SPVEC_? for column arrangement (out-Character[512])
// returns 0 if all values are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSpVecDataToArray)(__int64 satKey, double xa_spVec[512], char xs_spVec[512]);
  
  // INDEXES OF SPVEC DATA FIELDS
  static const int  
     XF_SPVEC_POS1     =  1,      // X COMPONENT OF SATELLITE'S POSITION (KM)
     XF_SPVEC_POS2     =  2,      // Y COMPONENT OF SATELLITE'S POSITION (KM)
     XF_SPVEC_POS3     =  3,      // Z COMPONENT OF SATELLITE'S POSITION (KM)
     XF_SPVEC_VEL1     =  4,      // X COMPONENT OF SATELLITE'S VELOCITY (M/S)
     XF_SPVEC_VEL2     =  5,      // Y COMPONENT OF SATELLITE'S VELOCITY (M/S)
     XF_SPVEC_VEL3     =  6,      // Z COMPONENT OF SATELLITE'S VELOCITY (M/S)
     XF_SPVEC_SECCLASS =  7,      // SECURITY CLASSIFICATION
     XF_SPVEC_SATNUM   =  9,      // SATELLITE NUMBER
     XF_SPVEC_SATNAME  = 10,      // SATELLITE COMMON NAME
     XF_SPVEC_EPOCH    = 11,      // EPOCH DATE
     XF_SPVEC_REVNUM   = 12,      // EPOCH REVOLUTION NUMBER
     XF_SPVEC_ELSETNUM = 13,      // ELSET NUMBER
     XF_SPVEC_BTERM    = 14,      // BALLISTIC COEFFICIENT (M^2/KG)
     XF_SPVEC_AGOM     = 15,      // RADIATION PRESSURE COEFFICIENT (M^2/KG)
     XF_SPVEC_OGPARM   = 16,      // OUTGASSING PARAMETER (KM/S^2)
     XF_SPVEC_INPCOORD = 17;      // INPUTE COORDINATE SYSTEM
     
     
  // INDEXES OF SPVEC NUMERICAL DATA IN AN ARRAY
  static const int  
     XA_SPVEC_SATNUM   =   0,      // SATELLITE NUMBER
     XA_SPVEC_EPOCH    =   1,      // EPOCH DATE IN DAYS SINCE 1950 UTC
     XA_SPVEC_REVNUM   =   2,      // EPOCH REVOLUTION NUMBER
     XA_SPVEC_ELSETNUM =   3,      // ELSET NUMBER
     XA_SPVEC_BTERM    =   4,      // BALLISTIC COEFFICIENT (M^2/KG)
     XA_SPVEC_AGOM     =   5,      // RADIATION PRESSURE COEFFICIENT (M^2/KG)
     XA_SPVEC_OGPARM   =   6,      // OUTGASSING PARAMETER (KM/S^2)
     XA_SPVEC_INPCOORD =   7,      // INPUTE COORDINATE SYSTEM; = 0: USE 4P, = 1:TMDAT, = 2: MMJ2K
  
     XA_SPVEC_POS1     =  20,      // X COMPONENT OF SATELLITE'S POSITION (KM)
     XA_SPVEC_POS2     =  21,      // Y COMPONENT OF SATELLITE'S POSITION (KM)
     XA_SPVEC_POS3     =  22,      // Z COMPONENT OF SATELLITE'S POSITION (KM)
     XA_SPVEC_VEL1     =  23,      // X COMPONENT OF SATELLITE'S VELOCITY (M/S)
     XA_SPVEC_VEL2     =  24,      // Y COMPONENT OF SATELLITE'S VELOCITY (M/S)
     XA_SPVEC_VEL3     =  25,      // Z COMPONENT OF SATELLITE'S VELOCITY (M/S)
     
     XA_SPVEC_HASOWNCRL=  70,      // FLAG TO INDICATE SP VEC HAS ITS OWN NUMERICAL INTEGRATION CONTROL
     XA_SPVEC_GEOIDX   =  71,      // GEOPOTENTIAL MODEL TO USE
     XA_SPVEC_BULGEFLG =  72,      // EARTH GRAVITY PERTUBATIONS FLAG
     XA_SPVEC_DRAGFLG  =  73,      // DRAG PERTUBATIONS FLAG 
     XA_SPVEC_RADFLG   =  74,      // RADIATION PRESSURE PERTUBATIONS FLAG
     XA_SPVEC_LUNSOL   =  75,      // LUNAR/SOLAR PERTUBATIONS FLAG
     XA_SPVEC_F10      =  76,      // F10 VALUE
     XA_SPVEC_F10AVG   =  77,      // F10 AVERAGE VALUE
     XA_SPVEC_AP       =  78,      // AP VALUE
     XA_SPVEC_TRUNC    =  79,      // GEOPOTENTIAL TRUNCATION ORDER/DEGREE/ZONALS
     XA_SPVEC_CONVERG  =  80,      // CORRECTOR STEP CONVERGENCE CRITERION; EXPONENT OF 1/10; DEFAULT = 10
     XA_SPVEC_OGFLG    =  81,      // OUTGASSING PERTUBATIONS FLAG
     XA_SPVEC_TIDESFLG =  82,      // SOLID EARTH AND OCEAN TIDE PERTUBATIONS FLAG
     XA_SPVEC_INCOORD  =  83,      // INPUT VECTOR COORDINATE SYSTEM
     XA_SPVEC_NTERMS   =  84,      // NUTATION TERMS
     XA_SPVEC_REEVAL   =  85,      // RECOMPUTE PERTUBATIONS AT EACH CORRECTOR STEP
     XA_SPVEC_INTEGCTRL=  86,      // VARIABLE OF INTERGRATION CONTROL
     XA_SPVEC_VARSTEP  =  87,      // VARIABLE STEP SIZE CONTROL
     XA_SPVEC_INITSTEP =  88,      // INITIAL STEP SIZE
     
     XA_SPVEC_RMS      =  99,      // WEIGHTED RM OF LAST DC ON THE SATELLITE 
     XA_SPVEC_COVELEMS = 100,      // THE LOWER TRIANGLE PORTION OF THE FULL COV MATRIX (100-120: 6X6 COVMTX, ..., 100-154: 10X10 COVMTX)
     
     XA_SPVEC_SIZE     = 512;
     
  
  // INDEXES OF SPVEC TEXT DATA IN AN ARRAY OF CHARS
  static const int     
     XS_SPVEC_SECCLASS_1 =  0,      // SECURITY CLASSIFICATION
     XS_SPVEC_SATNAME_8  =  1,      // SATELLITE COMMON NAME
     
     XS_SPVEC_SIZE       = 512;
     
  
  
// SpVecDll's function pointers declaration
extern fnPtrSpVecInit                      SpVecInit;
extern fnPtrSpVecGetInfo                   SpVecGetInfo;
extern fnPtrSpVecLoadFile                  SpVecLoadFile;
extern fnPtrSpVecSaveFile                  SpVecSaveFile;
extern fnPtrSpVecRemoveSat                 SpVecRemoveSat;
extern fnPtrSpVecRemoveAllSats             SpVecRemoveAllSats;
extern fnPtrSpVecGetCount                  SpVecGetCount;
extern fnPtrSpVecGetLoaded                 SpVecGetLoaded;
extern fnPtrSpVecAddSatFrLines             SpVecAddSatFrLines;
extern fnPtrSpVecAddSatFrLinesML           SpVecAddSatFrLinesML;
extern fnPtrSpVecAddSatFrFields            SpVecAddSatFrFields;
extern fnPtrSpVecAddSatFrFieldsML          SpVecAddSatFrFieldsML;
extern fnPtrSpVecUpdateSatFrFields         SpVecUpdateSatFrFields;
extern fnPtrSpVecGetField                  SpVecGetField;
extern fnPtrSpVecSetField                  SpVecSetField;
extern fnPtrSpVecGetAllFields              SpVecGetAllFields;
extern fnPtrSpVecParse                     SpVecParse;
extern fnPtrSpVecLinesToArray              SpVecLinesToArray;
extern fnPtrSpVecGetLines                  SpVecGetLines;
extern fnPtrSpVecFieldsToLines             SpVecFieldsToLines;
extern fnPtrSpVecArrayToLines              SpVecArrayToLines;
extern fnPtrSpVecGetSatKey                 SpVecGetSatKey;
extern fnPtrSpVecGetSatKeyML               SpVecGetSatKeyML;
extern fnPtrSpVecFieldsToSatKey            SpVecFieldsToSatKey;
extern fnPtrSpVecFieldsToSatKeyML          SpVecFieldsToSatKeyML;
extern fnPtrSpVecAddSatFrArray             SpVecAddSatFrArray;
extern fnPtrSpVecAddSatFrArrayML           SpVecAddSatFrArrayML;
extern fnPtrSpVecUpdateSatFrArray          SpVecUpdateSatFrArray;
extern fnPtrSpVecDataToArray               SpVecDataToArray;



void LoadSpVecDll();
void FreeSpVecDll();




#endif
// ========================= End of auto generated code ==========================
