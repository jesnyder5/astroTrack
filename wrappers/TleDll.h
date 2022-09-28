// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef TLEDLL_H
#define TLEDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define TleDll "Tle.dll"
#elif __APPLE__
  #define TleDll "libtle.dylib"
#else
  #define TleDll "libtle.so"
#endif


// Initializes Tle DLL for use in the program.
// If this function returns an error, it is recommended that you stop the program immediately.
// 
// An error will occur if you forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisites section of the accompanying documentation, before using this DLL.
// apPtr              The handle that was returned from DllMainInit. See the documentation for DllMain.dll for details. (in-Long)
// returns 0 if Tle.dll is initialized successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleInit)(__int64 apPtr);


// Returns the information about the Tle DLL.
// The returned string provides information about the version number, build date, and the platform of the Tle DLL. 
// infoStr            A string to hold the information about the Tle DLL. (out-Character[128])
typedef void (STDCALL *fnPtrTleGetInfo)(char infoStr[128]);


// Loads TLEs (satellites) contained in a text file into the TLE DLL's binary tree.
// You may use this function repeatedly to load TLEs from different input files. However, only unique satKeys are loaded. Duplicated TLEs won't be stored. 
// 
// TLEs can be included directly in the specified file, or they can be read from a separate file identified with "ELTFIL=[path\filename]" or "VECFIL=[path\filename]".
// 
// The input file is read in two passes. The function first looks for "ELTFIL=" and "VECFIL=" lines, then it looks for TLEs which were included directly. The result of this is that data entered using both methods will be processed, but the "ELTFIL=" and "VECFIL=" data will be processed first.
// tleFile            The name of the file containing two line element sets to be loaded. (in-Character[512])
// returns 0 if the two line element sets in the file are successfully loaded, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleLoadFile)(char tleFile[512]);


// Saves currently loaded TLEs to a file. 
// In append mode, if the specified file does not exist it will be created.
// If you call this routine immediately after TleLoadFile(), the TLE contents in the two files should be the same (minus duplicated TLE's or bad TLE's).
// 
// The purpose of this function is to save the current state of the loaded TLE's, usually used in GUI applications, for future use.
// tleFile            The name of the file in which to save the TLE's. (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing file. (0 = create new file, 1= append to existing file) (in-Integer)
// xf_tleForm         Specifies the format in which to save the file. (0 = two-line element set format, 1 =  CSV, others = future implementation) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleSaveFile)(char tleFile[512], int saveMode, int xf_tleForm);


// Removes a TLE represented by the satKey from memory. 
// If the users enter an invalid satKey (a non-existing satKey), the function will return a non-zero value indicating an error.
// satKey             The unique key of the satellite to be removed. (in-Long)
// returns 0 if the TLE is removed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleRemoveSat)(__int64 satKey);


// Removes all the TLEs from memory.
// returns 0 if all TLE's are removed successfully from memory, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleRemoveAllSats)();


// Returns the number of TLEs currently loaded. 
// See TleGetLoaded for an example.
// This function is useful for dynamically allocating memory for the array that is passed to the function TleGetLoaded().
// returns The number of TLEs currently loaded.
typedef int (STDCALL *fnPtrTleGetCount)();


// Retrieves all of the currently loaded satKeys. These satKeys can be used to access the internal data for the TLE's.
// It is recommended that TleGetCount() be  used to determine how many satellites are currently loaded. This value can then be used to dynamically allocate an array to hold the satKeys.
// 
// If you are going to pass a statically allocated array to this function, ensure it is large enough to hold all of the returned satKeys.
// order              Specifies the order in which the satKeys should be returned. 0 = sort in ascending order of satKeys, 1 = sort in descending order of satKeys, 2 = sort in the order in which the satKeys were loaded in memory, 9 = Quickest: sort in the order in which the satKeys were stored in the tree (in-Integer)
// satKeys            The array in which to store the satKeys. (out-Long[*])
typedef void (STDCALL *fnPtrTleGetLoaded)(int order, __int64 satKeys[]);


// Adds a TLE (satellite), using its directly specified first and second lines. 
// The function will indicate an error if the specified two line element set corresponds to a satellite that is already in memory.
// 
// This function can be called repeatedly to add many TLEs, one at a time.
// line1              The first line of a two line element set (or CSV Tle). (in-Character[512])
// line2              The second line of a two line element set (in-Character[512])
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrLines)(char line1[512], char line2[512]);


// This function is similar to TleAddSatFrLines but designed to be used in Matlab.
// Matlab doesn't correctly return the 19-digit satellite key using TleAddSatFrLines. This method is an alternative way to return the satKey output.
// line1              The first line of a two line element set (or CSV Tle). (in-Character[512])
// line2              The second line of a two line element set (in-Character[512])
// satKey             The satKey of the newly added TLE on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrTleAddSatFrLinesML)(char line1[512], char line2[512], __int64* satKey);


// Adds a TLE (satellite), using its CSV string format. 
// csvLine            Input CSV TLE string (in-Character[512])
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrCsv)(char csvLine[512]);


// This function is similar to TleAddSatFrCsv but designed to be used in Matlab.
// csvLine            Input CSV TLE string (in-Character[512])
// satKey             The satKey of the newly added TLE on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrTleAddSatFrCsvML)(char csvLine[512], __int64* satKey);


// Adds a GP TLE using its individually provided field values. 
// The function will indicate an error if the specified two line element set corresponds to a satellite that is already in memory.
// 
// This function can be called repeatedly to add many satellites (one satellite at a time).
// 
// SGP satellites (ephType = 0) use Kozai mean motion. SGP4 satellites (ephType = 2) use Brouwer mean motion.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrFieldsGP)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bstar, int ephType, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum);


// This function is similar to TleAddSatFrFieldsGP but includes nDotO2 and n2DotO6. 
// nDotO2 and n2DotO6 values are not used in the SGP4 propagator. However, some users still want to preserve the integrity of all input data.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// nDotO2             Mean motion derivative (rev/day /2) (in-Double)
// n2DotO6            Mean motion second derivative (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (in-Double)
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrFieldsGP2)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bstar, int ephType, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, double nDotO2, double n2DotO6);


// This function is similar to TleAddSatFrFieldsGP2 but designed to be used in Matlab. 
// Matlab doesn't seem to correctly return the 19-digit satellite key using TleAddSatFrFieldsGP2. This method is an alternative way to return the satKey output.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// nDotO2             Mean motion derivative (rev/day /2) (in-Double)
// n2DotO6            Mean motion second derivative (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (in-Double)
// satKey             The satKey of the newly added TLE on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrTleAddSatFrFieldsGP2ML)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bstar, int ephType, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, double nDotO2, double n2DotO6, __int64* satKey);


// Updates a GP satellite's data in memory by providing its individual field values. Note: satNum, year, day, and ephtype can't be updated.
// The satellite's unique key will not be changed by this function. If you specify a satKey that does not correspond to a currently loaded satellite, the function will indicate an error.
// 
// Remember to use the correct mean motion depending on the satellite's ephType.
// satKey             The satellite's unique key (in-Long)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion  (rev/day) (ephType = 0: Kozai mean motion, ephType = 2: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// returns 0 if the TLE is successfully updated, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleUpdateSatFrFieldsGP)(__int64 satKey, char secClass, char satName[8], double bstar, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum);


// This function is similar to TleUpdateSatFrFieldsGP but includes nDotO2 and n2DotO6. Note: satNum, year, day, and ephtype can't be updated.
// nDotO2 and n2DotO6 values are not used in the SGP4 propagator. However, some users still want to preserve the integrity of all input data.
// satKey             The satellite's unique key (in-Long)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion  (rev/day) (ephType = 0: Kozai mean motion, ephType = 2: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// nDotO2             Mean motion derivative (rev/day /2) (in-Double)
// n2DotO6            Mean motion second derivative (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (in-Double)
// returns 0 if the TLE is successfully updated, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleUpdateSatFrFieldsGP2)(__int64 satKey, char secClass, char satName[8], double bstar, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, double nDotO2, double n2DotO6);


// Adds an SP satellite using the individually provided field values.
// Only applies to SP propagator.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bTerm              Ballistic coefficient (m^2/kg) (in-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (in-Double)
// agom               agom (m^2/kg) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrFieldsSP)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bTerm, double ogParm, double agom, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum);


// This function is similar to TleAddSatFrFieldsSP but designed to be used in Matlab.
// Only applies to SP propagator.
// Matlab doesn't correctly return the 19-digit satellite key using TleAddSatFrFieldsSP. This method is an alternative way to return the satKey output.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bTerm              Ballistic coefficient (m^2/kg) (in-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (in-Double)
// agom               agom (m^2/kg) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// satKey             The satKey of the newly added TLE on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrTleAddSatFrFieldsSPML)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bTerm, double ogParm, double agom, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, __int64* satKey);


// Updates an SP satellite's data in memory using its individually provided field values. Note: satNum, year, day, and ephtype can't be updated.
// Only applies to SP propagator.
// The satellite's unique key will not be changed by this function. If you specify a satKey that does not correspond to a currently loaded TLE, the function will indicate an error. 
// satKey             The satellite's unique key (in-Long)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// bterm              Ballistic coefficient (m^2/kg) (in-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (in-Double)
// agom               agom (m^2/kg) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// returns 0 if the TLE is successfully updated, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleUpdateSatFrFieldsSP)(__int64 satKey, char secClass, char satName[8], double bterm, double ogParm, double agom, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum);


// Updates the value of a field of a TLE. This function can be used for both GP and SP satellites.
// 
// The table below indicates which index values correspond to which fields. Make sure to use the appropriate field index for GP TLEs and SP TLEs.  For indexes 5, 15 and 16, the interpretation depends on the ephemeris type of the TLE.
// satNum (1), Epoch (4), and Ephemeris Type (5) cannot be altered.
// 
// 
// 	index
// 	index Interpretation
// 
// 1Satellite number
// 2Security classification
// 3Satellite international designator
// 4Epoch
// 5Ephemeris type = 0,2: B* drag term (1/er) Ephemeris type = 6   : SP radiation pressure
// coefficient agom (m2/kg)
// 6Ephemeris type
// 7Element set number
// 8Orbit inclination (degrees)
// 9Right ascension of ascending node (degrees)
// 10Eccentricity
// 11Argument of perigee (degrees)
// 12Mean anomaly (degrees)
// 13Mean motion (rev/day)
// 14Revolution number at epoch
// 15Ephemeris type = 0: SGP mean motion derivative (rev/day /2) or Ephemeris type = 6: SP
// ballistic coefficient (m2/kg)
// 16Ephemeris type = 0: SGP mean motion second derivative (rev/day**2 /6) or Ephemeris type = 6:
// SP Outgassing parameter/Thrust Acceleration (km/s2)
// 
// satKey             The satellite's unique key. (in-Long)
// xf_Tle             Predefined number specifying which field to set. See remarks. (in-Integer)
// valueStr           The new value of the specified field, expressed as a string. (in-Character[512])
// returns 0 if the TLE is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrTleSetField)(__int64 satKey, int xf_Tle, char valueStr[512]);


// Retrieves the value of a specific field of a TLE. 
// 
// The table below indicates which index values correspond to which fields. Make sure to use the appropriate field index for GP TLEs and SP TLEs.  For indexes 5, 15 and 16, the interpretation depends on the ephemeris type of the TLE.
// 
// 
// 	index
// 	index Interpretation
// 
// 1Satellite number
// 2Security classification
// 3Satellite international designator
// 4Epoch
// 5Ephemeris type = 0,2: B* drag term (1/er) Ephemeris type = 6   : SP radiation pressure
// coefficient agom (m2/kg)
// 6Ephemeris type
// 7Element set number
// 8Orbit inclination (degrees)
// 9Right ascension of ascending node (degrees)
// 10Eccentricity
// 11Argument of perigee (degrees)
// 12Mean anomaly (degrees)
// 13Mean motion (rev/day)
// 14Revolution number at epoch
// 15Ephemeris type = 0: SGP mean motion derivative (rev/day /2) or Ephemeris type = 6: SP
// ballistic coefficient (m2/kg)
// 16Ephemeris type = 0: SGP mean motion second derivative (rev/day**2 /6) or Ephemeris type = 6:
// SP Outgassing parameter/Thrust Acceleration (km/s2)
// 
// satKey             The satellite's unique key. (in-Long)
// xf_Tle             Predefined number specifying which field to retrieve. See remarks. (in-Integer)
// valueStr           A string to contain the value of the requested field. (out-Character[512])
// returns 0 if the TLE data is successfully retrieved, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleGetField)(__int64 satKey, int xf_Tle, char valueStr[512]);


// Retrieves all of the data for a GP satellite in a single function call. 
// This function only works for GP satellites. The field values are placed in the corresponding parameters of the function. 
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// secClass           Security classification (out-Character)
// satName            Satellite international designator (out-Character[8])
// epochYr            Element epoch time - year, [YY]YY (out-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (out-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (out-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4, 6: SP) (out-Integer)
// elsetNum           Element set number (out-Integer)
// incli              Orbit inclination (degrees) (out-Double)
// node               Right ascension of ascending node (degrees) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (degrees) (out-Double)
// mnAnomaly          Mean anomaly (deg) (out-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (out-Double)
// revNum             Revolution number at epoch (out-Integer)
// returns 0 if all values are retrieved successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleGetAllFieldsGP)(__int64 satKey, int* satNum, char* secClass, char satName[8], int* epochYr, double* epochDays, double* bstar, int* ephType, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, int* revNum);


// Retrieves all of the data (including nDotO2 and n2DotO6) for a GP satellite in a single function call. 
// This function is similar to TleGetAllFieldsGP but also includes nDotO2 and n2DotO6. 
// This function only works for GP satellites. The field values are placed in the corresponding parameters of the function. 
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// secClass           Security classification (out-Character)
// satName            Satellite international designator (out-Character[8])
// epochYr            Element epoch time - year, [YY]YY (out-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (out-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (out-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4, 6: SP) (out-Integer)
// elsetNum           Element set number (out-Integer)
// incli              Orbit inclination (degrees) (out-Double)
// node               Right ascension of ascending node (degrees) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (degrees) (out-Double)
// mnAnomaly          Mean anomaly (degrees) (out-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (out-Double)
// revNum             Revolution number at epoch (out-Integer)
// nDotO2             Mean motion derivative (rev/day /2) (out-Double)
// n2DotO6            Mean motion second derivative (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (out-Double)
// returns 0 if all values are retrieved successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleGetAllFieldsGP2)(__int64 satKey, int* satNum, char* secClass, char satName[8], int* epochYr, double* epochDays, double* bstar, int* ephType, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, int* revNum, double* nDotO2, double* n2DotO6);


// Retrieves all of the data for an SP satellite in a single function call.
// Only applies to SP propagator.
// This function only works for SP satellites. The field values are placed in the corresponding parameters of the function. 
// satKey             The satellite's unique key (in-Long)
// satNum             Satellite number (out-Integer)
// secClass           Security classification (out-Character)
// satName            Satellite international designator (out-Character[8])
// epochYr            Element epoch time - year, [YY]YY (out-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (out-Double)
// bTerm              Ballistic coefficient (m^2/kg) (out-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (out-Double)
// agom               Agom (m^2/kg) (out-Double)
// elsetNum           Element set number (out-Integer)
// incli              Orbit inclination (degrees) (out-Double)
// node               Right ascension of ascending node (degrees) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (degrees) (out-Double)
// mnAnomaly          Mean anomaly (degrees) (out-Double)
// mnMotion           Mean motion (rev/day) (out-Double)
// revNum             Revolution number at epoch (out-Integer)
// returns 0 if all values are retrieved successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleGetAllFieldsSP)(__int64 satKey, int* satNum, char* secClass, char satName[8], int* epochYr, double* epochDays, double* bTerm, double* ogParm, double* agom, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, int* revNum);


// Parses GP data from the input first and second lines of a two line element set or a CSV Tle.
// This function only parses data from the input TLE but DOES NOT load/add the input TLE to memory.
// line1              The first line of the two line element set or a CSV tle (in-Character[512])
// line2              The second line of the two line element set or an empty string for a CVS tle (in-Character[512])
// satNum             Satellite number (out-Integer)
// secClass           Security classification (out-Character)
// satName            Satellite international designator (out-Character[8])
// epochYr            Element epoch time - year, [YY]YY (out-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (out-Double)
// nDotO2             n-dot/2 (for SGP, ephType = 0) (out-Double)
// n2DotO6            n-double-dot/6 (for SGP, ephType = 0) or agom (ephType = 4, XP) (m2/kg) (out-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (out-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4, 6: SP) (out-Integer)
// elsetNum           Element set number (out-Integer)
// incli              Orbit inclination (degrees) (out-Double)
// node               Right ascension of ascending node (degrees) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (degrees) (out-Double)
// mnAnomaly          Mean anomaly (degrees) (out-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (out-Double)
// revNum             Revolution number at epoch (out-Integer)
// returns 0 if the TLE is parsed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleParseGP)(char line1[512], char line2[512], int* satNum, char* secClass, char satName[8], int* epochYr, double* epochDays, double* nDotO2, double* n2DotO6, double* bstar, int* ephType, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, int* revNum);


// Parses GP data from the input first and second lines of a two line element set or a CSV tle and store that data back into the output parameters.
// This function only parses data from the input TLE but DOES NOT load/add the input TLE to memory.
// line1              The first line of the two line element set or a CSV tle (in-Character[512])
// line2              The second line of the two line element set or an empty string for a CVS tle (in-Character[512])
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (out-Double[64])
// xs_tle             Output string that contains all TLE's text fields, see XS_TLE_? for column arrangement (out-Character[512])
// returns 0 if the TLE is parsed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleLinesToArray)(char line1[512], char line2[512], double xa_tle[64], char xs_tle[512]);


// Parses SP data from the input first and second lines of a two line element set.
// Only applies to SP propagator.
// This function only parses data from the input TLE but DOES NOT load/add the input TLE to memory.
// line1              The first line of the two line element set (in-Character[512])
// line2              The second line of the two line element set (in-Character[512])
// satNum             Satellite number (out-Integer)
// secClass           Security classification (out-Character)
// satName            Satellite international designator (out-Character[8])
// epochYr            Element epoch time - year, [YY]YY (out-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (out-Double)
// bTerm              Ballistic coefficient (m^2/kg) (out-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (out-Double)
// agom               Agom (m^2/kg) (out-Double)
// elsetNum           Element set number (out-Integer)
// incli              Orbit inclination (degrees) (out-Double)
// node               Right ascension of ascending node (degrees) (out-Double)
// eccen              Eccentricity (out-Double)
// omega              Argument of perigee (degrees) (out-Double)
// mnAnomaly          Mean anomaly (degrees) (out-Double)
// mnMotion           Mean motion (rev/day) (out-Double)
// revNum             Revolution number at epoch (out-Integer)
// returns 0 if the TLE is parsed successfully, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleParseSP)(char line1[512], char line2[512], int* satNum, char* secClass, char satName[8], int* epochYr, double* epochDays, double* bTerm, double* ogParm, double* agom, int* elsetNum, double* incli, double* node, double* eccen, double* omega, double* mnAnomaly, double* mnMotion, int* revNum);


// Returns the first and second lines representation of a TLE of a satellite. 
// satKey             The satellite's unique key. (in-Long)
// line1              A string to hold the first line of the TLE (out-Character[512])
// line2              A string to hold the second line of the TLE (out-Character[512])
// returns 0 if successful, non-0 on error.
typedef int (STDCALL *fnPtrTleGetLines)(__int64 satKey, char line1[512], char line2[512]);


// Returns the CSV string representation of a TLE of a satellite. 
// satKey             The satellite's unique key. (in-Long)
// csvLine            A string to hold the TLE in csv format. (out-Character[512])
// returns 0 if successful, non-0 on error.
typedef int (STDCALL *fnPtrTleGetCsv)(__int64 satKey, char csvLine[512]);


// Constructs a TLE from individually provided GP data fields.
// This function only parses data from the input fields but DOES NOT load/add the TLE to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// nDotO2             N Dot/2 (rev/day /2) (in-Double)
// n2DotO6            N Double Dot/6 (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (in-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// line1              Returned first line of a TLE. (out-Character[512])
// line2              Returned second line of a TLE. (out-Character[512])
typedef void (STDCALL *fnPtrTleGPFieldsToLines)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double nDotO2, double n2DotO6, double bstar, int ephType, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, char line1[512], char line2[512]);


// Constructs a TLE from individually provided GP data fields.
// This function only parses data from the input fields but DOES NOT load/add the TLE to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// nDotO2             N Dot/2 (rev/day /2) (in-Double)
// n2DotO6            N Double Dot/6 (rev/day**2 /6) or agom (ephType = 4, XP) (m2/kg) (in-Double)
// bstar              B* drag term (1/er) (ephType = 0, 2) or BTerm - ballistic coefficient (m2/kg) (ephType = 4, XP) (in-Double)
// ephType            Satellite ephemeris type (0: SGP, 2: SGP4) (in-Integer)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (ephType = 0: Kozai mean motion, ephType = 2 or 4: Brouwer mean motion) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// csvLine            A string to hold the TLE in csv format. (out-Character[512])
typedef void (STDCALL *fnPtrTleGPFieldsToCsv)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double nDotO2, double n2DotO6, double bstar, int ephType, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, char csvLine[512]);


// Constructs a TLE from GP data stored in the input parameters.
// This function only parses data from the input data but DOES NOT load/add the TLE to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (in-Double[64])
// xs_tle             Input string that contains all TLE's text fields, see XS_TLE_? for column arrangement (in-Character[512])
// line1              Returned first line of a TLE (out-Character[512])
// line2              Returned second line of a TLE (out-Character[512])
typedef void (STDCALL *fnPtrTleGPArrayToLines)(double xa_tle[64], char xs_tle[512], char line1[512], char line2[512]);


// Constructs a TLE from GP data stored in the input parameters.
// This function only parses data from the input data but DOES NOT load/add the TLE to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (in-Double[64])
// xs_tle             Input string that contains all TLE's text fields, see XS_TLE_? for column arrangement (in-Character[512])
// csvline            Returned csv format elements. (out-Character[512])
typedef void (STDCALL *fnPtrTleGPArrayToCsv)(double xa_tle[64], char xs_tle[512], char csvline[512]);


// Constructs a TLE from individually provided SP data fields.
// Only applies to SP propagator.
// This function only parses data from the input fields but DOES NOT load/add the TLE to memory.
// Returned line1 and line2 will be empty if the function fails to construct the lines as requested.
// satNum             Satellite number (in-Integer)
// secClass           Security classification (in-Character)
// satName            Satellite international designator (in-Character[8])
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// bTerm              Ballistic coefficient (m^2/kg) (in-Double)
// ogParm             Outgassing parameter/Thrust Acceleration (km/s^2) (in-Double)
// agom               Agom (m^2/kg) (in-Double)
// elsetNum           Element set number (in-Integer)
// incli              Orbit inclination (degrees) (in-Double)
// node               Right ascension of ascending node (degrees) (in-Double)
// eccen              Eccentricity (in-Double)
// omega              Argument of perigee (degrees) (in-Double)
// mnAnomaly          Mean anomaly (degrees) (in-Double)
// mnMotion           Mean motion (rev/day) (in-Double)
// revNum             Revolution number at epoch (in-Integer)
// line1              Returned first line of a TLE. (out-Character[512])
// line2              Returned second line of a TLE. (out-Character[512])
typedef void (STDCALL *fnPtrTleSPFieldsToLines)(int satNum, char secClass, char satName[8], int epochYr, double epochDays, double bTerm, double ogParm, double agom, int elsetNum, double incli, double node, double eccen, double omega, double mnAnomaly, double mnMotion, int revNum, char line1[512], char line2[512]);


// Returns the first satKey from the currently loaded set of TLEs that contains the specified satellite number.
// This function is useful when Tle.dll is used in applications that require only one record (one TLE entry) for one satellite, and which refer to that TLE by its satellite number. This function can be used to retrieve a satKey in that situation, which is useful since the Standardized Astrodynamic Algorithms library works only with satKeys.
// A negative value will be returned if there is an error.
// satNum             Satellite number (in-Integer)
// returns The satellite's unique key
typedef __int64 (STDCALL *fnPtrTleGetSatKey)(int satNum);


// This function is similar to TleGetSatKey but designed to be used in Matlab. 
// Matlab doesn't correctly return the 19-digit satellite key using TleGetSatKey. This method is an alternative way to return the satKey output.
// This function is useful when Tle.dll is used in applications that require only one record (one TLE entry) for one satellite, and which refer to that TLE by its satellite number. This function can be used to retrieve a satKey in that situation, which is useful since the Standardized Astrodynamic Algorithms library works only with satKeys.
// A negative value will be returned in satKey if there is an error.
// satNum             Satellite number (in-Integer)
// satKey             The satKey of the satellite if a satellite with the requested number is found in the set of loaded satellites, a negative value if there is an error. (out-Long)
typedef void (STDCALL *fnPtrTleGetSatKeyML)(int satNum, __int64* satKey);


// Computes a satKey from the input data.
// There is no need for a matching satellite to be loaded prior to using this function. The function simply computes the satKey from the provided fields.
// 
// This is the proper way to reconstruct a satKey from its fields. If you use your own routine to do this, the computed satKey might be different. 
// A negative value will be returned if there is an error.
// satNum             Satellite number (in-Integer)
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// ephType            Ephemeris type (in-Integer)
// returns The resulting satellite key if the computation is successful; a negative value if there is an error.
typedef __int64 (STDCALL *fnPtrTleFieldsToSatKey)(int satNum, int epochYr, double epochDays, int ephType);


// This function is similar to TleFieldsToSatKey but designed to be used in Matlab. 
// Matlab doesn't correctly return the 19-digit satellite key using TleFieldsToSatKey. This method is an alternative way to return the satKey output.
// There is no need for a matching satellite to be loaded prior to using this function. The function simply computes the satKey from the provided fields.
// 
// This is the proper way to reconstruct a satKey from its fields. If you use your own routine to do this, the computed satKey might be different.
// A negative value will be returned in satKey if there is an error.
// satNum             Satellite number (in-Integer)
// epochYr            Element epoch time - year, [YY]YY (in-Integer)
// epochDays          Element epoch time - day of year, DDD.DDDDDDDD (in-Double)
// ephType            Ephemeris type (in-Integer)
// satKey             The satKey if the computation is successful, a negative value if there is an error. (out-Long)
typedef void (STDCALL *fnPtrTleFieldsToSatKeyML)(int satNum, int epochYr, double epochDays, int ephType, __int64* satKey);


// Adds a TLE (satellite), using its data stored in the input parameters.
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (in-Double[64])
// xs_tle             Input string that contains all TLE's text fields, see XS_TLE_? for column arrangement (in-Character[512])
// returns The satKey of the newly added TLE on success, a negative value on error.
typedef __int64 (STDCALL *fnPtrTleAddSatFrArray)(double xa_tle[64], char xs_tle[512]);


// This function is similar to TleAddSatFrArray but designed to be used in Matlab. 
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (in-Double[64])
// xs_tle             Input string that contains all TLE's text fields, see XS_TLE_? for column arrangement (in-Character[512])
// satKey             The satKey of the newly added TLE on success, a negative value on error. (out-Long)
typedef void (STDCALL *fnPtrTleAddSatFrArrayML)(double xa_tle[64], char xs_tle[512], __int64* satKey);


// Updates existing TLE data with the provided new data stored in the input parameters. Note: satNum, year, day, and ephtype can't be updated.
// nDotO2 and n2DotO6 values are not used in the SGP4 propagator. However, some users still want to preserve the integrity of all input data.
// satKey             The satellite's unique key (in-Long)
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (in-Double[64])
// xs_tle             Input string that contains all TLE's text fields, see XS_TLE_? for column arrangement (in-Character[512])
// returns 0 if the TLE is successfully updated, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleUpdateSatFrArray)(__int64 satKey, double xa_tle[64], char xs_tle[512]);


// Retrieves TLE data and stored it in the passing parameters
// 
// The following table lists the values for the XA_TLE array:
// 
// 
// name
// index
// index Interpretation
// 
// XA_TLE_SATNUM          0Satellite number
// XA_TLE_EPOCH           1Satellite's epoch time in DS50UTC
// XA_TLE_NDOT            2GP Mean motion derivative (rev/day /2)
// XA_TLE_NDOTDOT         3GP Mean motion second derivative (rev/day**2 /6)
// XA_TLE_BSTAR           4GP B* drag term (1/er)  
// XA_TLE_EPHTYPE         5Satellite ephemeris type: 0=SGP, 2=SGP4, 6=SP
// XA_TLE_OBJTYPE         6Object type; 0=unknown, 1=payload, 2=rocket body, 3=platform, 4=debris,
// 5=manned
// XA_TLE_EXTRPLTNTYPE    7Extrapolation theory used to generate element set: 0=no extrapolation DC
// 
// XA_TLE_RCSBIN          8RCS size bin
// XA_TLE_INCLI          20Orbit inclination (deg)
// XA_TLE_NODE           21Right ascension of ascending node (deg)
// XA_TLE_ECCEN          22Eccentricity
// XA_TLE_OMEGA          23Argument of perigee (deg)
// XA_TLE_MNANOM         24Mean anomaly (deg)
// XA_TLE_MNMOTN         25Mean motion (rev/day) (ephType=0: Kozai, ephType=2: Brouwer)
// XA_TLE_REVNUM         26Revolution number at epoch 
// XA_TLE_ELSETNUM       30Element set number
// XA_TLE_ERRGRWRATE     31Error growth rate km/day
// XA_TLE_LSTOBSTIME     32+/- time of last observation offset relative to epoch (+/- ddd.ddddd
// fractional days)
// XA_TLE_RADARXSECT     33Radar cross section (in meters squared, followed by character designating
// radar frequency type used)
// XA_TLE_VISMAG         34Median visual magnitude of object scaled to 36000km
// XA_TLE_DRAGCOEFF      35Drag coefficient
// XA_TLE_AGOMGP         38Radiation Pressure Coefficient GP
// XA_TLE_SP_BTERM        2SP ballistic coefficient (m2/kg)
// XA_TLE_SP_OGPARM       3SP outgassing parameter (km/s2)
// XA_TLE_SP_AGOM         4SP Radiation Pressure Coefficient
// XA_TLE_SIZE           64
// 
// 
// The following table lists the values for the XS_TLE array:
// 
// 
// name
// index
// index Interpretation
// 
// XS_TLE_SECCLASS_1     0Security classification of line 1 and line 2
// XS_TLE_SATNAME_12     1Satellite name
// XS_TLE_SECCLASSL3_1  13Security classification of line 3 
// XS_TLE_DISTMARKING_4 14Distribution marking
// XS_TLE_OBJSTAT_1     18Object status: 'A'=Active, 'D'=Dead, 'U'=Unknown
// XS_TLE_MSSNCODE_2    19Primary payload mission code
// XS_TLE_MSSNSTAT_1    21Primary mission status (table lookup)
// XS_TLE_MANEUV_1      22Maneuverability 'Y'=Yes, 'N'=No, 'U'=Unknown
// XS_TLE_OOCNTRY_4     23Payload Owner/Operator 
// XS_TLE_FREQBAND_1    27Frequency Band of the RCS: U=UHF, C=C-Band, L=L-Band, S=S-Band, X=X-Band
// 
// XS_TLE_TBLERATE_1    28Tumble rate 
// XS_TLE_SIZE          512
// 
// satKey             The satellite's unique key (in-Long)
// xa_tle             Array containing TLE's numerical fields, see XA_TLE_? for array arrangement (out-Double[64])
// xs_tle             Output string that contains all TLE's text fields, see XS_TLE_? for column arrangement (out-Character[512])
// returns 0 if all values are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrTleDataToArray)(__int64 satKey, double xa_tle[64], char xs_tle[512]);


// Converts TLE two line format to CSV format
// line1              The first line of a two line element set (in-Character[512])
// line2              The second line of a two line element set (in-Character[512])
// csvline            A string to hold the TLE in csv format. (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleLinesToCsv)(char line1[512], char line2[512], char csvline[512]);


// Converts TLE CSV format to two line format
// csvLine            The input TLE in CSV format (in-Character[512])
// newSatno           New satellite number to replace what's in CSV obs if desired (won't use/renumber if it's zero) (in-Integer)
// line1              The output first line of the two line element set (out-Character[512])
// line2              The output second line of the two line element set (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error.
typedef int (STDCALL *fnPtrTleCsvToLines)(char csvLine[512], int newSatno, char line1[512], char line2[512]);


// Sets TLE key mode - This function was deprecated, please use DllMain/SetElsetKeyMode() instead
// tle_keyMode        Desired Tle key mode (see TLE_KEYMODE_? for available modes) (in-Integer)
// returns 0 if the set is successful, non-0 if there is an error.
typedef int (STDCALL *fnPtrSetTleKeyMode)(int tle_keyMode);


// Gets current TLE key mode - This function was deprecated, please use DllMain/GetElsetKeyMode() instead
// returns Current Tle key mode (see TLE_KEYMODE_? for available modes)
typedef int (STDCALL *fnPtrGetTleKeyMode)();
  
  // TLE TYPES (TLE EPHEMERIS TYPES) - THEY ARE DIFFERENT THAN ELTTYPE
  static const int  
     TLETYPE_SGP  = 0,    // TLE SGP ELSET (KOZAI MEAN MOTION)
     TLETYPE_SGP4 = 2,    // TLE SGP4 ELSET (BROUWER MEAN MOTION)
     TLETYPE_XP   = 4,    // TLE SGP4-XP ELSET (BROUWER MEAN MOTION)
     TLETYPE_SP   = 6;    // TLE SP ELSET (OSCULATING ELEMENTS)
  
  // INDEXES OF TLE DATA FIELDS
  static const int  
     XF_TLE_SATNUM     =  1,    // SATELLITE NUMBER
     XF_TLE_CLASS      =  2,    // SECURITY CLASSIFICATION U: UNCLASS, C: CONFIDENTIAL, S: SECRET
     XF_TLE_SATNAME    =  3,    // SATELLITE NAME A8
     XF_TLE_EPOCH      =  4,    // SATELLITE'S EPOCH TIME "YYYYJJJ.JJJJJJJJ"
     XF_TLE_BSTAR      =  5,    // GP B* DRAG TERM (1/ER)  (NOT THE SAME AS XF_TLE_BTERM) 
     XF_TLE_EPHTYPE    =  6,    // SATELLITE EPHEMERIS TYPE: 0=SGP, 2=SGP4, 6=SP
     XF_TLE_ELSETNUM   =  7,    // ELEMENT SET NUMBER
     XF_TLE_INCLI      =  8,    // ORBIT INCLINATION (DEG)
     XF_TLE_NODE       =  9,    // RIGHT ASCENSION OF ASENDING NODE (DEG)
     XF_TLE_ECCEN      = 10,    // ECCENTRICITY
     XF_TLE_OMEGA      = 11,    // ARGUMENT OF PERIGEE (DEG)
     XF_TLE_MNANOM     = 12,    // MEAN ANOMALY (DEG)
     XF_TLE_MNMOTN     = 13,    // MEAN MOTION (REV/DAY) (EPHTYPE=0: KOZAI, EPHTYPE=2: BROUWER)
     XF_TLE_REVNUM     = 14,    // REVOLUTION NUMBER AT EPOCH 
     
     XF_TLE_NDOT       = 15,    // GP MEAN MOTION DERIVATIVE (REV/DAY /2)
     XF_TLE_NDOTDOT    = 16,    // GP MEAN MOTION SECOND DERIVATIVE (REV/DAY**2 /6)
     XF_TLE_AGOMGP     = 16,    // SOLAR RADIATION PRESSURE GP (M2/KG)
  
     XF_TLE_SP_AGOM    =  5,    // SP RADIATION PRESSURE COEFFICIENT
     XF_TLE_SP_BTERM   = 15,    // SP BALLISTIC COEFFICIENT (M2/KG)
     XF_TLE_SP_OGPARM  = 16,    // SP OUTGASSING PARAMETER (KM/S2)
  
     XF_TLE_ORGSATNUM  = 17,    // ORIGINAL SATELLITE NUMBER
     XF_TLE_BTERM      = 18,    // GP BALLISTIC COEFFICIENT (M2/KG) (NOT THE SAME AS XF_TLE_BSTAR)
     XF_TLE_OBSTIME    = 19,    // TIME OF LAST OBSERVATION RELATIVE TO EPOCH +/- FRACTIONAL DAYS
     XF_TLE_EGR        = 20,    // LAST CALCULATED ERROR GROWTH RATE (KM/DAY)
     XF_TLE_EDR        = 21,    // LAST CALCULATED ENERGY DISSIPATION RATE (W/KG)
     XF_TLE_VISMAG     = 22,    // MEDIAN VISMAG 
     XF_TLE_RCS        = 23,    // MEDIAN RCS - DIAMETER IN CENTIMETERS (CM)
     XF_TLE_OBJTYPE    = 24,    // OBJECT TYPE (PAYLOAD, ROCKET BODY, PLATFORM, DEBRIS, UNKNOWN)
     XF_TLE_SATNAME_12 = 25;    // SATELLITE NAME A12 (UPTO 12 CHARACTER LONG)
     
     
  // INDEXES OF TLE NUMERICAL DATA IN AN ARRAY
  static const int  
     // LINE 1
     XA_TLE_SATNUM        =  0,    // SATELLITE NUMBER
     XA_TLE_EPOCH         =  1,    // SATELLITE'S EPOCH TIME IN DS50UTC
     XA_TLE_NDOT          =  2,    // GP MEAN MOTION DERIVATIVE (REV/DAY /2)
     XA_TLE_NDOTDOT       =  3,    // GP MEAN MOTION SECOND DERIVATIVE (REV/DAY**2 /6)
     XA_TLE_BSTAR         =  4,    // GP B* DRAG TERM (1/ER)  
     XA_TLE_EPHTYPE       =  5,    // SATELLITE EPHEMERIS TYPE: 0=SGP, 2=SGP4, 4=SGP4-XP, 6=SP
     
     // LINE 2
     XA_TLE_INCLI         = 20,    // ORBIT INCLINATION (DEG)
     XA_TLE_NODE          = 21,    // RIGHT ASCENSION OF ASENDING NODE (DEG)
     XA_TLE_ECCEN         = 22,    // ECCENTRICITY
     XA_TLE_OMEGA         = 23,    // ARGUMENT OF PERIGEE (DEG)
     XA_TLE_MNANOM        = 24,    // MEAN ANOMALY (DEG)
     XA_TLE_MNMOTN        = 25,    // MEAN MOTION (REV/DAY) (EPHTYPE=0, 4: KOZAI, EPHTYPE=2: BROUWER)
     XA_TLE_REVNUM        = 26,    // REVOLUTION NUMBER AT EPOCH 
     XA_TLE_ELSETNUM      = 30,    // ELEMENT SET NUMBER
     
     // CSV (OR TLE-XP, EPHEMTYPE=4) SPECIFIC FIELDS 
     XA_TLE_ORGSATNUM     = 31,    // ORIGINAL SATELLITE NUMBER
     XA_TLE_BTERM         = 32,    // SP/SGP4-XP BALLISTIC COEFFICIENT (M2/KG) 
     XA_TLE_OBSTIME       = 33,    // TIME OF LAST OBSERVATION RELATIVE TO EPOCH +/- FRACTIONAL DAYS
     XA_TLE_EGR           = 34,    // LAST CALCULATED ERROR GROWTH RATE (KM/DAY)
     XA_TLE_EDR           = 35,    // LAST CALCULATED ENERGY DISSIPATION RATE (W/KG)
     XA_TLE_VISMAG        = 36,    // MEDIAN VISMAG 
     XA_TLE_RCS           = 37,    // MEDIAN RCS - DIAMETER IN CENTIMETERS (CM)
  
     // CSV (OR TLE-XP, EPHEMTYPE=4)
     XA_TLE_AGOMGP        = 38,    // SOLAR RADIATION PRESSURE COEFFICIENT GP (M2/KG)
  
     
     // SP SPECIFIC FIELDS
     XA_TLE_SP_BTERM      =  2,    // SP BALLISTIC COEFFICIENT (M2/KG)
     XA_TLE_SP_OGPARM     =  3,    // SP OUTGASSING PARAMETER (KM/S2)
     XA_TLE_SP_AGOM       =  4,    // SP RADIATION PRESSURE COEFFICIENT
     
     XA_TLE_SIZE          = 64;
  
  // INDEXES OF TLE TEXT DATA IN AN ARRAY OF CHARS
  static const int  
     XS_TLE_SECCLASS_1   =  0,    // SECURITY CLASSIFICATION OF LINE 1 AND LINE 2
     XS_TLE_SATNAME_12   =  1,    // SATELLITE NAME
     XS_TLE_OBJTYPE_11   = 13,    // OBJECT TYPE (PAYLOAD, ROCKET BODY, PLATFORM, DEBRIS, UNKNOWN)
     
     
     XS_TLE_SIZE         = 512;      
     
  // INDEXES OF DIFFERENT TLE FILE'S FORMATS
  static const int  
     XF_TLEFORM_ORG    =  0,    // ORIGINAL TLE FORMAT
     XF_TLEFORM_CSV    =  1;    // CSV FORMAT
     
     
// TleDll's function pointers declaration
extern fnPtrTleInit                        TleInit;
extern fnPtrTleGetInfo                     TleGetInfo;
extern fnPtrTleLoadFile                    TleLoadFile;
extern fnPtrTleSaveFile                    TleSaveFile;
extern fnPtrTleRemoveSat                   TleRemoveSat;
extern fnPtrTleRemoveAllSats               TleRemoveAllSats;
extern fnPtrTleGetCount                    TleGetCount;
extern fnPtrTleGetLoaded                   TleGetLoaded;
extern fnPtrTleAddSatFrLines               TleAddSatFrLines;
extern fnPtrTleAddSatFrLinesML             TleAddSatFrLinesML;
extern fnPtrTleAddSatFrCsv                 TleAddSatFrCsv;
extern fnPtrTleAddSatFrCsvML               TleAddSatFrCsvML;
extern fnPtrTleAddSatFrFieldsGP            TleAddSatFrFieldsGP;
extern fnPtrTleAddSatFrFieldsGP2           TleAddSatFrFieldsGP2;
extern fnPtrTleAddSatFrFieldsGP2ML         TleAddSatFrFieldsGP2ML;
extern fnPtrTleUpdateSatFrFieldsGP         TleUpdateSatFrFieldsGP;
extern fnPtrTleUpdateSatFrFieldsGP2        TleUpdateSatFrFieldsGP2;
extern fnPtrTleAddSatFrFieldsSP            TleAddSatFrFieldsSP;
extern fnPtrTleAddSatFrFieldsSPML          TleAddSatFrFieldsSPML;
extern fnPtrTleUpdateSatFrFieldsSP         TleUpdateSatFrFieldsSP;
extern fnPtrTleSetField                    TleSetField;
extern fnPtrTleGetField                    TleGetField;
extern fnPtrTleGetAllFieldsGP              TleGetAllFieldsGP;
extern fnPtrTleGetAllFieldsGP2             TleGetAllFieldsGP2;
extern fnPtrTleGetAllFieldsSP              TleGetAllFieldsSP;
extern fnPtrTleParseGP                     TleParseGP;
extern fnPtrTleLinesToArray                TleLinesToArray;
extern fnPtrTleParseSP                     TleParseSP;
extern fnPtrTleGetLines                    TleGetLines;
extern fnPtrTleGetCsv                      TleGetCsv;
extern fnPtrTleGPFieldsToLines             TleGPFieldsToLines;
extern fnPtrTleGPFieldsToCsv               TleGPFieldsToCsv;
extern fnPtrTleGPArrayToLines              TleGPArrayToLines;
extern fnPtrTleGPArrayToCsv                TleGPArrayToCsv;
extern fnPtrTleSPFieldsToLines             TleSPFieldsToLines;
extern fnPtrTleGetSatKey                   TleGetSatKey;
extern fnPtrTleGetSatKeyML                 TleGetSatKeyML;
extern fnPtrTleFieldsToSatKey              TleFieldsToSatKey;
extern fnPtrTleFieldsToSatKeyML            TleFieldsToSatKeyML;
extern fnPtrTleAddSatFrArray               TleAddSatFrArray;
extern fnPtrTleAddSatFrArrayML             TleAddSatFrArrayML;
extern fnPtrTleUpdateSatFrArray            TleUpdateSatFrArray;
extern fnPtrTleDataToArray                 TleDataToArray;
extern fnPtrTleLinesToCsv                  TleLinesToCsv;
extern fnPtrTleCsvToLines                  TleCsvToLines;
extern fnPtrSetTleKeyMode                  SetTleKeyMode;
extern fnPtrGetTleKeyMode                  GetTleKeyMode;



void LoadTleDll();
void FreeTleDll();




#endif
// ========================= End of auto generated code ==========================
