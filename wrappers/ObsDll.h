// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef OBSDLL_H
#define OBSDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define ObsDll "Obs.dll"
#elif __APPLE__
  #define ObsDll "libobs.dylib"
#else
  #define ObsDll "libobs.so"
#endif


// Initializes Obs DLL for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Obs.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsInit)(__int64 apPtr);


// Returns information about the current version of Obs DLL. 
// The information is placed in the string parameter passed in.
// infoStr            A string to hold the information about Obs.dll (out-Character[128])
typedef void (STDCALL *fnPtrObsGetInfo)(char infoStr[128]);


// Sets the year for transmission observation format (TTY) input files
// ttyYear            2 or 4 digits year (in-Integer)
typedef void (STDCALL *fnPtrObsSetTTYYear)(int ttyYear);


// Loads observation data from an input text file
// obsFile            The name of the file containing obs-related data (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsLoadFile)(char obsFile[512]);


// Saves the currently loaded obs data to a file
// obsFile            The name of the file in which to save the loaded obs (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// obsForm            Specifies the mode in which to save the file (0 = B3 format, 1 = TTY, 2 = CSV) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrObsSaveFile)(char obsFile[512], int saveMode, int obsForm);


// Removes an obs, represented by the obsKey, from the set of currently loaded observations
// obsKey             The observation's unique key (in-Long)
// returns 0 if the observation is successfully removed, non-0 if there is an error
typedef int (STDCALL *fnPtrObsRemove)(__int64 obsKey);


// Removes all currently loaded observations from memory
// returns 0 if all the loaded observations are removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsRemoveAll)();


// Returns the number of observations currently loaded
// returns the number of observations currently loaded
typedef int (STDCALL *fnPtrObsGetCount)();


// Retrieves all of the currently loaded obsKeys. These obsKeys can be used to access the internal data for the observations
// Sort options (order):
// (+/-)1 = (descending/ascending) time, sensor, obsType, elev
// (+/-)2 = (descending/ascending) time, elevation
// (+/-)3 = (descending/ascending) time, sensor, otype, el, satno
// (+/-)4 = (descending/ascending) sensor, satno, time, elev
// (+/-)5 = (descending/ascending) sensor, time, elevation
// (+/-)6 = (descending/ascending) sensor, satno, obsType, time, elev
// (+/-)7 = (descending/ascending) satno, time, sensor, otype, el
// (+/-)8 = (reversed/same)        order as obs were read
// 9 : as is in the tree
// order              Specifies the order in which the obsKeys should be returned (in-Integer)
// obsKeys            The array in which to store the obsKeys (out-Long[*])
typedef void (STDCALL *fnPtrObsGetLoaded)(int order, __int64 obsKeys[]);


// Loads a single observation-typed card
// card               Any single observation-typed card (B3, B3E, TTY, ...) but not OBSFIL= (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsLoadCard)(char card[512]);


// Loads a one-line or two-line observation 
// card1              Any single observation-typed card (B3, B3E, TTY, ...) or Card #1 of TTY obs type 4, 7, 8, 9 (in-Character[512])
// card2              Card #2 of TTY obs type 4, 7, 8, 9 (in-Character[512])
// returns 0 if the input card1/card2 are read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsLoadTwoCards)(char card1[512], char card2[512]);


// Adds an observation from a string in B3 observation format
// card               The input string in B3 observation format (in-Character[512])
// returns The obsKey of the newly added observation on success, a negative value on error
typedef __int64 (STDCALL *fnPtrObsAddFrB3Card)(char card[512]);


// Works like ObsAddFrB3Card but designed for Matlab
// card               The input string in B3 observation format (in-Character[512])
// obsKey             The obsKey of the newly added observation on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrObsAddFrB3CardML)(char card[512], __int64* obsKey);


// Converts B3 format to csv format without loading B3 obs into memory
// card               The input string in B3 observation format (in-Character[512])
// csvLine            The output string in csv observation format (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrObsB3ToCsv)(char card[512], char csvLine[512]);


// Converts CSV format to B3 format without loading CSV obs into memory
// csvLine            The input string in csv observation format (in-Character[512])
// newSatno           New satellite number to replace what's in CSV obs if desired (value of zero does not renumber) (in-Integer)
// card               The output string in B3 observation format (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrObsCsvToB3)(char csvLine[512], int newSatno, char card[512]);


// Adds an observation from a TTY (1 line or 2 lines) observation format
// card1              Card #1 of a TTY obs (in-Character[512])
// card2              Card #2 of TTY obs type 4, 7, 8, 9 or an empty string for other TTY obs types (in-Character[512])
// returns The obsKey of the newly added observation on success, a negative value on error
typedef __int64 (STDCALL *fnPtrObsAddFrTTYCards)(char card1[512], char card2[512]);


// Works like ObsAddFrTTYCards but designed for Matlab
// card1              Card #1 of a TTY obs (in-Character[512])
// card2              Card #2 of TTY obs type 4, 7, 8, 9 or an empty string for other TTY obs types (in-Character[512])
// obsKey             The obsKey of the newly added observation on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrObsAddFrTTYCardsML)(char card1[512], char card2[512], __int64* obsKey);


// Converts TTY format to CSV format without loading TTY obs into memory
// card1              Card #1 of a TTY obs (in-Character[512])
// card2              Card #2 of TTY obs type 4, 7, 8, 9 or an empty string for other TTY obs types (in-Character[512])
// csvLine            The obs in csv format (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrObsTTYToCsv)(char card1[512], char card2[512], char csvLine[512]);


// Converts CSV format to TTY format without loading CSV obs into memory
// csvLine            The obs in csv format (in-Character[512])
// newSatno           New satellite number to replace what's in CSV obs if desired (value of zero does not renumber) (in-Integer)
// card1              Card #1 of a TTY obs (out-Character[512])
// card2              Card #2 of TTY obs type 4, 7, 8, 9 or an empty string for other TTY obs types (out-Character[512])
// returns 0 if the conversion is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrObsCsvToTTY)(char csvLine[512], int newSatno, char card1[512], char card2[512]);


// Adds one observation using csv obs string 
// csvLine            Input csv obs string (in-Character[512])
// returns The obsKey of the newly added observation on success, a negative value on error
typedef __int64 (STDCALL *fnPtrObsAddFrCsv)(char csvLine[512]);


// Adds one observation using csv obs string - for MatLab
// csvLine            Input csv obs string (in-Character[512])
// obsKey             The obsKey of the newly added observation on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrObsAddFrCsvML)(char csvLine[512], __int64* obsKey);


// Adds one observation using its input data. Depending on the observation type, some input data might be unavailable and left blank
// secClass           security classification (in-Character)
// satNum             satellite number (in-Integer)
// senNum             sensor number (in-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (in-Double)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (in-Integer)
// ASTAT              association status assigned by SPADOC (in-Integer)
// siteTag            original satellite number (in-Integer)
// spadocTag          SPADOC-asssigned tag number (in-Integer)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// vel                velocity XYZ (km/s) (ECI or EFG) (in-Double[3])
// extArr             extra array - future use (in-Double[128])
// returns The obsKey of the newly added observation on success, a negative value on error
typedef __int64 (STDCALL *fnPtrObsAddFrFields)(char secClass, int satNum, int senNum, double obsTimeDs50utc, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, int trackInd, int ASTAT, int siteTag, int spadocTag, double pos[3], double vel[3], double extArr[128]);


// Works like ObsAddFrFields but designed for Matlab
// secClass           security classification (in-Character)
// satNum             satellite number (in-Integer)
// senNum             sensor number (in-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (in-Double)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (in-Integer)
// ASTAT              association status assigned by SPADOC (in-Integer)
// siteTag            original satellite number (in-Integer)
// spadocTag          SPADOC-asssigned tag number (in-Integer)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// vel                velocity XYZ (km/s) (ECI or EFG) (in-Double[3])
// extArr             extra array - future use (in-Double[128])
// obsKey             The obsKey of the newly added observation on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrObsAddFrFieldsML)(char secClass, int satNum, int senNum, double obsTimeDs50utc, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, int trackInd, int ASTAT, int siteTag, int spadocTag, double pos[3], double vel[3], double extArr[128], __int64* obsKey);


// Adds one observation using its input data stored in an array. Depending on the observation type, some input data might be unavailable and left blank
// xa_obs             Array containing observation data, see XA_OBS_? for array arrangement (in-Double[64])
// returns The obsKey of the newly added observation on success, a negative value on error
typedef __int64 (STDCALL *fnPtrObsAddFrArray)(double xa_obs[64]);


// Works like ObsAddFrArray but designed for Matlab
// xa_obs             Array containing observation data, see XA_OBS_? for array arrangement (in-Double[64])
// obsKey             The obsKey of the newly added observation on success, a negative value on error (out-Long)
typedef void (STDCALL *fnPtrObsAddFrArrayML)(double xa_obs[64], __int64* obsKey);


// Retrieves all observation data in a single function call. Depending on the observation type, some input data might be unavailable
// obsKey             The unique key of the requested observation (in-Long)
// secClass           security classification (out-Character)
// satNum             satellite number (out-Integer)
// senNum             sensor number (out-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (out-Double)
// elOrDec            elevation or declination (deg) (out-Double)
// azOrRA             azimuth or right-ascension (deg) (out-Double)
// range              range (km) (out-Double)
// rangeRate          range rate (km/s) (out-Double)
// elRate             elevation rate (deg/s) (out-Double)
// azRate             azimuth rate (deg/s) (out-Double)
// rangeAccel         range acceleration (km/s^2) (out-Double)
// obsType            observation type (out-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (out-Integer)
// ASTAT              association status assigned by SPADOC (out-Integer)
// siteTag            original satellite number (out-Integer)
// spadocTag          SPADOC-asssigned tag number (out-Integer)
// pos                position XYZ (km) (ECI or EFG) (out-Double[3])
// vel                velocity XYZ (km/s) (ECI or EFG) (out-Double[3])
// extArr             extra array - future use (out-Double[128])
// returns 0 if all values are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsGetAllFields)(__int64 obsKey, char* secClass, int* satNum, int* senNum, double* obsTimeDs50utc, double* elOrDec, double* azOrRA, double* range, double* rangeRate, double* elRate, double* azRate, double* rangeAccel, char* obsType, int* trackInd, int* ASTAT, int* siteTag, int* spadocTag, double pos[3], double vel[3], double extArr[128]);


// Retrieves observation data and stored it in the passing array. Depending on the observation type, some data fields might be unavailable
// See ObsGetField for description of xa_obs elements
// obsKey             The unique key of the requested observation (in-Long)
// xa_obs             The array containing observation data, see XA_OBS_? for array arrangement (out-Double[64])
// returns 0 if all values are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsDataToArray)(__int64 obsKey, double xa_obs[64]);


// Updates existing observation data with the provided new data
// obsKey             The unique key of the requested observation (in-Long)
// secClass           security classification (in-Character)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track obs) (in-Integer)
// ASTAT              association status assigned by SPADOC (in-Integer)
// siteTag            original satellite number (in-Integer)
// spadocTag          SPADOC-asssigned tag number (in-Integer)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// vel                velocity XYZ (km/s) (ECI or EFG) (in-Double[3])
// extArr             extra array - future use (in-Double[128])
// returns 0 if the requested observation is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrObsUpdateFrFields)(__int64 obsKey, char secClass, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, int trackInd, int ASTAT, int siteTag, int spadocTag, double pos[3], double vel[3], double extArr[128]);


// Retrieves the value of a specific field of an observation
// 
// The table below indicates which index values for the xf_Obs parameter.
// 
// 
// Index (xf_Obs)
// Index Interpretation
// 
// 1observation classification
// 2satellite number
// 3sensor number
// 4observation time in days since 1950 UTC
// 5elevation (deg)
// 6declination (deg)
// 7azimuth (deg)
// 8right-ascension (deg)
// 9range (km)
// 10range rate (km/s)
// 11elevation rate (deg/s)
// 12azimuth rate (deg/s)
// 13range acceleration (km/s^2)
// 14observation type
// 15track position indicator (3=start track ob, 4=in track ob, 5=end track ob)
// 16association status assigned by SPADOC
// 17original satellite number
// 18SPADOC-assigned tag number
// 19position X (km) (ECI or EFG)
// 20position Y (km) (ECI or EFG)
// 21position Z (km) (ECI or EFG)
// 22velocity X (km/s) (ECI or EFG)
// 23velocity Y (km/s) (ECI or EFG)
// 24velocity Z (km/s) (ECI or EFG)
// 
// obsKey             The observation's unique key (in-Long)
// xf_Obs             The predefined number specifying which field to retrieve, see XF_OBS_? for field specification (in-Integer)
// strValue           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the observation data is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrObsGetField)(__int64 obsKey, int xf_Obs, char strValue[512]);


// Updates the value of a field of an observation
// See ObsGetField for a description of the xf_Obs parameter.
// Satellite number, sensor number, and observation time are not allowed to be updated.
// obsKey             The observation's unique key (in-Long)
// xf_Obs             The predefined number specifying which field to update, see XF_OBS_? for field specification (in-Integer)
// strValue           The new value of the specified field, expressed as a string (in-Character[512])
// returns 0 if the observation is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrObsSetField)(__int64 obsKey, int xf_Obs, char strValue[512]);


// Returns observation in B3-card string
// obsKey             The observation's unique key (in-Long)
// b3Card             A string to hold the B3 observation format (out-Character[512])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrObsGetB3Card)(__int64 obsKey, char b3Card[512]);


// Returns observation in TTY-card string
// obsKey             The observation's unique key (in-Long)
// ttyCard1           first line of a TTY card (out-Character[512])
// ttyCard2           second line of a TTY card (might be unavailable for certain obs type) (out-Character[512])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrObsGetTTYCard)(__int64 obsKey, char ttyCard1[512], char ttyCard2[512]);


// Returns observation in CSV-format string
// obsKey             The observation's unique key (in-Long)
// csvline            A string to hold the CSV observation format (out-Character[512])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrObsGetCsv)(__int64 obsKey, char csvline[512]);


// Constructs a B3-card string from the input observation data fields
// secClass           security classification (in-Character)
// satNum             satellite number (in-Integer)
// senNum             sensor number (in-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (in-Double)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (in-Integer)
// ASTAT              association status assigned by SPADOC (in-Integer)
// siteTag            original satellite number (in-Integer)
// spadocTag          SPADOC-asssigned tag number (in-Integer)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// b3Card             A string to hold the B3 observation format (out-Character[512])
typedef void (STDCALL *fnPtrObsFieldsToB3Card)(char secClass, int satNum, int senNum, double obsTimeDs50utc, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, int trackInd, int ASTAT, int siteTag, int spadocTag, double pos[3], char b3Card[512]);


// Constructs a csv string from the input observation data fields
// secClass           security classification (in-Character)
// satNum             satellite number (in-Integer)
// senNum             sensor number (in-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (in-Double)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (in-Integer)
// ASTAT              association status assigned by SPADOC (in-Integer)
// siteTag            original satellite number (in-Integer)
// spadocTag          SPADOC-asssigned tag number (in-Integer)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// csvLine            A string to hold the csv observation format (out-Character[512])
typedef void (STDCALL *fnPtrObsFieldsToCsv)(char secClass, int satNum, int senNum, double obsTimeDs50utc, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, int trackInd, int ASTAT, int siteTag, int spadocTag, double pos[3], char csvLine[512]);


// Constructs a TTY-card string from the input observation data fields
// secClass           security classification (in-Character)
// satNum             satellite number (in-Integer)
// senNum             sensor number (in-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (in-Double)
// elOrDec            elevation or declination (deg) (in-Double)
// azOrRA             azimuth or right-ascension (deg) (in-Double)
// range              range (km) (in-Double)
// rangeRate          range rate (km/s), or equinox indicator (0-3) for obs type 5/9 (in-Double)
// elRate             elevation rate (deg/s) (in-Double)
// azRate             azimuth rate (deg/s) (in-Double)
// rangeAccel         range acceleration (km/s^2) (in-Double)
// obsType            observation type (in-Character)
// pos                position XYZ (km) (ECI or EFG) (in-Double[3])
// ttyCard1           first line of a TTY card (out-Character[512])
// ttyCard2           second line of a TTY card (might be unavailable for certain obs type) (out-Character[512])
typedef void (STDCALL *fnPtrObsFieldsToTTYCard)(char secClass, int satNum, int senNum, double obsTimeDs50utc, double elOrDec, double azOrRA, double range, double rangeRate, double elRate, double azRate, double rangeAccel, char obsType, double pos[3], char ttyCard1[512], char ttyCard2[512]);


// Computes an obsKey from individually provided fields
// satNum             input satellite's number (in-Integer)
// senNum             input sensor's number (in-Integer)
// obsTimeDs50utc     input observation time in days since 1950, UTC (in-Double)
// returns The newly created observation Key
typedef __int64 (STDCALL *fnPtrObsFieldsToObsKey)(int satNum, int senNum, double obsTimeDs50utc);


// Works like ObsFieldsToObsKey but designed for Matlab
// satNum             input satellite's number (in-Integer)
// senNum             input sensor's number (in-Integer)
// obsTimeDs50utc     input observation time in days since 1950, UTC (in-Double)
// obsKey             The newly created observation Key (out-Long)
typedef void (STDCALL *fnPtrObsFieldsToObsKeyML)(int satNum, int senNum, double obsTimeDs50utc, __int64* obsKey);


// Parses observation data from a B3-card (or B3E) string / one-line TTY / or CSV - Converts obs data to TEME of Date if neccessary
// b3ObsCard          input B3 observation string (in-Character[512])
// secClass           security classification (out-Character)
// satNum             satellite number (out-Integer)
// senNum             sensor number (out-Integer)
// obsTimeDs50utc     observation time in days since 1950 UTC (out-Double)
// elOrDec            elevation or declination (deg) (out-Double)
// azOrRA             azimuth or right-ascension (deg) (out-Double)
// range              range (km) (out-Double)
// rangeRate          range rate (km/s) (out-Double)
// elRate             elevation rate (deg/s) (out-Double)
// azRate             azimuth rate (deg/s) (out-Double)
// rangeAccel         range acceleration (km/s^2) (out-Double)
// obsType            observation type (out-Character)
// trackInd           track position indicator (3=start track ob, 4=in track ob, 5=end track ob) (out-Integer)
// ASTAT              association status assigned by SPADOC (out-Integer)
// siteTag            original satellite number (out-Integer)
// spadocTag          SPADOC-asssigned tag number (out-Integer)
// pos                position XYZ (km) (ECI or EFG) (out-Double[3])
// returns 0 if the data is successfully parsed, non-0 if there is an error
typedef int (STDCALL *fnPtrObsB3Parse)(char b3ObsCard[512], char* secClass, int* satNum, int* senNum, double* obsTimeDs50utc, double* elOrDec, double* azOrRA, double* range, double* rangeRate, double* elRate, double* azRate, double* rangeAccel, char* obsType, int* trackInd, int* ASTAT, int* siteTag, int* spadocTag, double pos[3]);


// Parses any observation data format (B3-card (or B3E) string / one or two line TTY / CSV - No conversion takes place
// line1              input observation string 1 (B3/B3E/line 1 TTY/CSV) (in-Character[512])
// line2              input observation string 2 (line 2 of two-line TTY) (in-Character[512])
// xa_obs             The array containing observation data, see XA_OBS_? for array arrangement (out-Double[64])
// returns 0 if the data is successfully parsed, non-0 if there is an error
typedef int (STDCALL *fnPtrObsParse)(char line1[512], char line2[512], double xa_obs[64]);


// Loads observation data from an input text file and group them together in the specified groupd id (gid).
// This allows the users to easily manage (load/retrieve/remove/save) a group of observations using the group id (gid)
// obsFile            The name of the file containing obs-related data (in-Character[512])
// gid                user specified group id (in-Integer)
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrObsLoadFileGID)(char obsFile[512], int gid);


// Saves the currently loaded obs data belong to the specified group id (gid) to a file 
// obsFile            The name of the file in which to save the settings (in-Character[512])
// gid                Group ID number (in-Integer)
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// obsForm            Specifies the obs format in which to save the file (0 = B3 format, 1 = TTY, 2 = CSV) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrObsSaveFileGID)(char obsFile[512], int gid, int saveMode, int obsForm);


// Removes all observations belong to the specified group id (gid) from the set of currently loaded observations
// gid                Group ID number (in-Integer)
// returns 0 if the observations are successfully removed, non-0 if there is an error
typedef int (STDCALL *fnPtrObsRemoveGID)(int gid);


// Returns the number of observations currently loaded that have the same gid
// gid                Group ID number (in-Integer)
// returns The number of observations currently loaded that have the same group id
typedef int (STDCALL *fnPtrObsGetCountGID)(int gid);


// Retrieves all of the currently loaded obsKeys that have the same gid. These obsKeys can be used to access the internal data for the observations
// Sort options (order):
// (+/-)1 = (descending/ascending) time, sensor, obsType, elev
// (+/-)2 = (descending/ascending) time, elevation
// (+/-)3 = (descending/ascending) time, sensor, otype, el, satno
// (+/-)4 = (descending/ascending) sensor, satno, time, elev
// (+/-)5 = (descending/ascending) sensor, time, elevation
// (+/-)6 = (descending/ascending) sensor, satno, obsType, time, elev
// (+/-)7 = (descending/ascending) satno, time, sensor, otype, el
// (+/-)8 = (reversed/same)        order as obs were read
// 9 : as is in the tree
// gid                Group ID number (in-Integer)
// order              Specifies the order in which the obsKeys should be returned (in-Integer)
// obsKeys            The array in which to store the obsKeys (out-Long[*])
typedef void (STDCALL *fnPtrObsGetLoadedGID)(int gid, int order, __int64 obsKeys[]);


// Converts obs type from character to integer
// obsTypeChar        The input obs type character (in-Character)
// returns The resulting obs type integer
typedef int (STDCALL *fnPtrObsTypeCToI)(char obsTypeChar);


// Converts obs type from integer to character
// obsTypeInt         The input obs type integer (in-Integer)
// returns The resulting obs type character
typedef char (STDCALL *fnPtrObsTypeIToC)(int obsTypeInt);


// Resets obs selection settings
typedef void (STDCALL *fnPtrObsResetSelObs)();


// Computes other states of the input observation
// 
// The table below indicates which index values correspond to which fields in the xa_obState array.
// 
// 
// Index
// Index Interpretation
// 
// 0Satellite number
// 1Sensor number
// 2Observation time in DS50UTC
// 10Position X/ECI (km)
// 11Position Y/ECI (km)
// 12Position Z/ECI (km)
// 13Velocity X/ECI (km/s)
// 14Velocity Y/ECI (km/s)
// 15Velocity Z/ECI (km/s)
// 16Geodetic latitude (deg)
// 17Geodetic longitude (deg)
// 18Geodetic height (km)
// 19Position X/EFG (km)
// 20Position Y/EFG (km)
// 21Position Z/EFG (km)
// 
// obsKey             The observation's unique key (in-Long)
// range_km           Use this default range (km) for angle only obs (in-Double)
// xa_obState         Data derived from the obs data (out-Double[64])
// returns 0 if the observation states are successfully computed
typedef int (STDCALL *fnPtrObsGetStates)(__int64 obsKey, double range_km, double xa_obState[64]);


// Computes observation states from the observation data
// See ObsGetStates for a list of the values for the xa_obState parameter.
// xa_obs             Array containing observation data, see XA_OBS_? for array arrangement (in-Double[64])
// xa_obState         Data derived from the obs data (out-Double[64])
// returns 0 if the observation states are successfully computed
typedef int (STDCALL *fnPtrObsDataToStates)(double xa_obs[64], double xa_obState[64]);


// Reconstructs obs string (B3-card/one or two line TTY/CSV) from obs data in the input array xa_obs
// xa_obs             The array containing observation data, see XA_OBS_? for array arrangement (in-Double[64])
// obsForm            Desired obs string format (B3 = 0, TTY=1, CSV=2) (in-Integer)
// line1              output observation string 1 (B3/B3E/line 1 TTY/CSV) (out-Character[512])
// line2              output observation string 2 (line 2 of two-line TTY if obsForm = 1) (out-Character[512])
// returns 0 if the data is successfully , non-0 if there is an error
typedef int (STDCALL *fnPtrObsArrToLines)(double xa_obs[64], int obsForm, char line1[512], char line2[512]);


// Sets OBS key mode
// This mode can also be turned on if the user loads an input text file that includes this line - "AS_DMA_OBS_ON" -
// and is currently calling any of these methods: DllMainLoadFile(), or ObsLoadFile()
// obs_keyMode        Desired obs key mode (see OBS_KEYMODE_? for available modes) (in-Integer)
// returns 0 if the set is successful, non-0 if there is an error.
typedef int (STDCALL *fnPtrSetObsKeyMode)(int obs_keyMode);


// Gets current OBS key mode
// returns Current obs key mode (see OBS_KEYMODE_? for available modes)
typedef int (STDCALL *fnPtrGetObsKeyMode)();


// Returs the satellite number associated with the input obsKey
// obsKey             The observation's unique key (in-Long)
// returns The satellite number associated with the input obsKey (satNum = -1 if obsKey doesn't exist)
typedef int (STDCALL *fnPtrSatNumFrObsKey)(__int64 obsKey);


// Returs the sensor number associated with the input obsKey
// obsKey             The observation's unique key (in-Long)
// returns The satellite number associated with the input obsKey (senNum = -1 if obsKey doesn't exist)
typedef int (STDCALL *fnPtrSenNumFrObsKey)(__int64 obsKey);
  
  // CSV SIGMA TYPE INDICATOR
  static const int CSVSIGMATYPE = 7;
  
  // INDEXES OF OBSERVATION DATA FIELDS
  static const int  
     XF_OBS_SECCLASS     =  1,     // SECURITY CLASSIFICATION
     XF_OBS_SATNUM       =  2,     // SATELLITE NUMBER
     XF_OBS_SENNUM       =  3,     // SENSOR NUMBER
     XF_OBS_DS50UTC      =  4,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XF_OBS_ELEVATION    =  5,     // ELEVATION (DEG)
     XF_OBS_DECLINATION  =  6,     // DECLINATION (DEG)
     XF_OBS_AZIMUTH      =  7,     // AZIMUTH (DEG)
     XF_OBS_RA           =  8,     // RIGHT-ASCENSION (DEG)
     XF_OBS_RANGE        =  9,     // RANGE (KM)
     XF_OBS_RANGERATE    = 10,     // RANGE RATE (KM/S)
     XF_OBS_ELRATE       = 11,     // ELEVATION RATE (DEG/S)
     XF_OBS_AZRATE       = 12,     // AZIMUTH RATE (DEG/S)
     XF_OBS_RANGEACCEL   = 13,     // RANGE ACCELERATION (KM/S^2)
     XF_OBS_OBSTYPE      = 14,     // OBSERVATION TYPE
     XF_OBS_TRACKIND     = 15,     // TRACK POSITION INDICATOR (3=START TRACK OB, 4=IN TRACK OB, 5=END TRACK OB)
     XF_OBS_ASTAT        = 16,     // ASSOCIATION STATUS ASSIGNED BY SPADOC
     XF_OBS_SITETAG      = 17,     // ORIGINAL SATELLITE NUMBER
     XF_OBS_SPADOCTAG    = 18,     // SPADOC-ASSSIGNED TAG NUMBER
     XF_OBS_POSE         = 19,     // POSITION X/EFG (KM)
     XF_OBS_POSF         = 20,     // POSITION Y/EFG (KM)
     XF_OBS_POSG         = 21,     // POSITION Z/EFG (KM)
     XF_OBS_POSX         = 22,     // POSITION X/ECI (KM)
     XF_OBS_POSY         = 23,     // POSITION Y/ECI (KM)
     XF_OBS_POSZ         = 24,     // POSITION Z/ECI (KM)
  
     XF_OBS_RCS_PP       = 25,     // PRINCIPAL POLARIZATION RCS
     XF_OBS_RCS_OP       = 26,     // ORTHOGONAL POLARIZATION RCS
     XF_OBS_RCS_PPS      = 27,     // PRINCIPAL POLARIZATION RCS SIGMA
     XF_OBS_RCS_OPS      = 28,     // ORTHOGONAL POLARIZATION RCS SIGMA
     XF_OBS_SNR          = 29,     // RADAR SIGNAL TO NOISE RATIO
     XF_OBS_BORE_AZ      = 30,     // AZIMUTH OF BORESITE
     XF_OBS_BORE_EL      = 31,     // ELEVATION OF BORESITE
     XF_OBS_VISMAG       = 32,     // APPARENT VISUAL MAGNITUDE
     XF_OBS_VISMAG_NORM  = 33,     // GEO NORMALIZED VISUAL MAGNITUDE
     XF_OBS_SOL_PHASE    = 34,     // SOLAR PHASE ANGLE
     XF_OBS_FRAME        = 35,     // FRAME NUMBER
     XF_OBS_ABERRATION   = 36,     // ABERRATION CORRECTION INDICATOR (0=YES, 1=NO)
     XF_OBS_ASTAT_METHOD = 37;     // EITHER R" OR T; ROTAS=GENERAL PERTURBATIONS, TRACK=SPECIAL PERTURBATIONS
  
  // INDEXES OF OBSERVATION DATA IN AN ARRAY
  static const int  
     XA_OBS_SECCLASS     =  0,     // SECURITY CLASSIFICATION, 1 = UNCLASSIFIED, 2 = CONFIDENTIAL, 3 = SECRET
     XA_OBS_SATNUM       =  1,     // SATELLITE NUMBER
     XA_OBS_SENNUM       =  2,     // SENSOR NUMBER
     XA_OBS_DS50UTC      =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OBS_ELORDEC      =  4,     // ELEVATION (FOR OB TYPE 1, 2, 3, 4, 8) OR DECLINATION (FOR OB TYPE 5, 9) (DEG)
     XA_OBS_AZORRA       =  5,     // AZIMUTH (FOR OB TYPE 1, 2, 3, 4, 8) OR RIGHT ASCESION (FOR OB TYPE 5, 9) (DEG)
     XA_OBS_RANGE        =  6,     // RANGE (KM)
     XA_OBS_RANGERATE    =  7,     // RANGE RATE (KM/S) FOR NON-OPTICAL OBS TYPE
     XA_OBS_ELRATE       =  8,     // ELEVATION RATE (DEG/S)
     XA_OBS_AZRATE       =  9,     // AZIMUTH RATE (DEG/S)
     XA_OBS_RANGEACCEL   = 10,     // RANGE ACCELERATION (KM/S^2)
     XA_OBS_OBSTYPE      = 11,     // OBSERVATION TYPE   
     XA_OBS_TRACKIND     = 12,     // TRACK POSITION INDICATOR (3=START TRACK OB, 4=IN TRACK OB, 5=END TRACK OB)
     XA_OBS_ASTAT        = 13,     // ASSOCIATION STATUS ASSIGNED BY SPADOC
     XA_OBS_SITETAG      = 14,     // ORIGINAL SATELLITE NUMBER
     XA_OBS_SPADOCTAG    = 15,     // SPADOC-ASSSIGNED TAG NUMBER
     XA_OBS_POSX         = 16,     // POSITION X/ECI OR X/EFG (KM)
     XA_OBS_POSY         = 17,     // POSITION Y/ECI OR Y/EFG (KM)
     XA_OBS_POSZ         = 18,     // POSITION Z/ECI OR Z/EFG (KM)   
     XA_OBS_VELX         = 19,     // VELOCITY X/ECI (KM/S)  (OR EDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OBS_VELY         = 20,     // VELOCITY Y/ECI (KM/S)  (OR FDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OBS_VELZ         = 21,     // VELOCITY Z/ECI (KM/S)  (OR GDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OBS_YROFEQNX     = 22,     // YEAR OF EQUINOX INDICATOR FOR OBS TYPE 5/9 (0= TIME OF OBS, 1= 0 JAN OF DATE, 2= J2000, 3= B1950)
  
     XA_OBS_AZORRABIAS   = 33,     // AZ/RA BIAS (DEG)
     XA_OBS_ELORDECBIAS  = 34,     // EL/DEC BIAS (DEG)
     XA_OBS_RGBIAS       = 35,     // RANGE BIAS (KM)
     XA_OBS_RRBIAS       = 36,     // RANGE-RATE BIAS (KM/SEC)
     XA_OBS_TIMEBIAS     = 37,     // TIME BIAS (SEC)
     XA_OBS_RAZORRABIAS  = 38,     // AZ/RA RATE BIAS (DEG/SEC) 
     XA_OBS_RELORDECBIAS = 39,     // EL/DEC RATE BIAS (DEG/SEC)
  
     XA_OBS_SIGMATYPE    = 40,     // INDIVIDUAL OBS'S SIGMAS TYPE (0: N/A, 6: 6 ELEMENTS, 21: 21 ELEMENTS, 7: THIS IS CSV OBS)
     XA_OBS_SIGMAEL1     = 41,     // SIGMA\COVARIANCE ELEMENT 1 - 6 ELEMENS - AZ SIGMA
     XA_OBS_SIGMAEL2     = 42,     // SIGMA\COVARIANCE ELEMENT 2 - 6 ELEMENS - EL SIGMA
     XA_OBS_SIGMAEL3     = 43,     // SIGMA\COVARIANCE ELEMENT 3 - 6 ELEMENS - RANGE SIGMA
     XA_OBS_SIGMAEL4     = 44,     // SIGMA\COVARIANCE ELEMENT 4 - 6 ELEMENS - RANGE RATE SIGMA
     XA_OBS_SIGMAEL5     = 45,     // SIGMA\COVARIANCE ELEMENT 5 - 6 ELEMENS - AZ RATE SIGMA
     XA_OBS_SIGMAEL6     = 46,     // SIGMA\COVARIANCE ELEMENT 6 - 6 ELEMENS - EL RATE SIGMA
     XA_OBS_SIGMAEL7     = 47,     // SIGMA\COVARIANCE ELEMENT 7 
     XA_OBS_SIGMAEL8     = 48,     // SIGMA\COVARIANCE ELEMENT 8
     XA_OBS_SIGMAEL9     = 49,     // SIGMA\COVARIANCE ELEMENT 9
     XA_OBS_SIGMAEL10    = 50,     // SIGMA\COVARIANCE ELEMENT 10
     XA_OBS_SIGMAEL11    = 51,     // SIGMA\COVARIANCE ELEMENT 11
     XA_OBS_SIGMAEL12    = 52,     // SIGMA\COVARIANCE ELEMENT 12
     XA_OBS_SIGMAEL13    = 53,     // SIGMA\COVARIANCE ELEMENT 13
     XA_OBS_SIGMAEL14    = 54,     // SIGMA\COVARIANCE ELEMENT 14
     XA_OBS_SIGMAEL15    = 55,     // SIGMA\COVARIANCE ELEMENT 15
     XA_OBS_SIGMAEL16    = 56,     // SIGMA\COVARIANCE ELEMENT 16
     XA_OBS_SIGMAEL17    = 57,     // SIGMA\COVARIANCE ELEMENT 17
     XA_OBS_SIGMAEL18    = 58,     // SIGMA\COVARIANCE ELEMENT 18
     XA_OBS_SIGMAEL19    = 59,     // SIGMA\COVARIANCE ELEMENT 19
     XA_OBS_SIGMAEL20    = 60,     // SIGMA\COVARIANCE ELEMENT 20
     XA_OBS_SIGMAEL21    = 61,     // SIGMA\COVARIANCE ELEMENT 21
  
     XA_OBS_SIZE         = 64;
     
  // INDEXES OF OBSERVATION DATA IN AN ARRAY (OBS TYPE CSV SPECIFIC)
  static const int  
     XA_OTCSV_SECCLASS     =  0,     // SECURITY CLASSIFICATION, 1 = UNCLASSIFIED, 2 = CONFIDENTIAL, 3 = SECRET
     XA_OTCSV_SATNUM       =  1,     // SATELLITE NUMBER
     XA_OTCSV_SENNUM       =  2,     // SENSOR NUMBER
     XA_OTCSV_DS50UTC      =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OTCSV_ELORDEC      =  4,     // ELEVATION (FOR OB TYPE 1, 2, 3, 4, 8) OR DECLINATION (FOR OB TYPE 5, 9) (DEG)
     XA_OTCSV_AZORRA       =  5,     // AZIMUTH (FOR OB TYPE 1, 2, 3, 4, 8) OR RIGHT ASCESION (FOR OB TYPE 5, 9) (DEG)
     XA_OTCSV_RANGE        =  6,     // RANGE (KM)
     XA_OTCSV_RANGERATE    =  7,     // RANGE RATE (KM/S) FOR NON-OPTICAL OBS TYPE
     XA_OTCSV_ELRATE       =  8,     // ELEVATION RATE (DEG/S)
     XA_OTCSV_AZRATE       =  9,     // AZIMUTH RATE (DEG/S)
     XA_OTCSV_RANGEACCEL   = 10,     // RANGE ACCELERATION (KM/S^2)
     XA_OTCSV_OBSTYPE      = 11,     // OBSERVATION TYPE   
     XA_OTCSV_TRACKIND     = 12,     // TRACK POSITION INDICATOR (3=START TRACK OB, 4=IN TRACK OB, 5=END TRACK OB)
     XA_OTCSV_ASTAT        = 13,     // ASSOCIATION STATUS ASSIGNED BY SPADOC
     XA_OTCSV_SITETAG      = 14,     // ORIGINAL SATELLITE NUMBER
     XA_OTCSV_SPADOCTAG    = 15,     // SPADOC-ASSSIGNED TAG NUMBER
     XA_OTCSV_POSX         = 16,     // POSITION X/ECI OR X/EFG (KM)
     XA_OTCSV_POSY         = 17,     // POSITION Y/ECI OR Y/EFG (KM)
     XA_OTCSV_POSZ         = 18,     // POSITION Z/ECI OR Z/EFG (KM)   
     XA_OTCSV_VELX         = 19,     // VELOCITY X/ECI (KM/S)  (OR EDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OTCSV_VELY         = 20,     // VELOCITY Y/ECI (KM/S)  (OR FDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OTCSV_VELZ         = 21,     // VELOCITY Z/ECI (KM/S)  (OR GDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OTCSV_YROFEQNX     = 22,     // YEAR OF EQUINOX INDICATOR FOR OBS TYPE 5/9 (0= TIME OF OBS, 1= 0 JAN OF DATE, 2= J2000, 3= B1950)
  
     XA_OTCSV_RCS_PP       = 23,     // PRINCIPAL POLARIZATION RCS
     XA_OTCSV_RCS_OP       = 24,     // ORTHOGONAL POLARIZATION RCS
     XA_OTCSV_RCS_PPS      = 25,     // PRINCIPAL POLARIZATION RCS SIGMA
     XA_OTCSV_RCS_OPS      = 26,     // ORTHOGONAL POLARIZATION RCS SIGMA
     XA_OTCSV_SNR          = 27,     // RADAR SIGNAL TO NOISE RATIO
     XA_OTCSV_BORE_AZ      = 28,     // AZIMUTH OF BORESITE
     XA_OTCSV_BORE_EL      = 29,     // ELEVATION OF BORESITE
     XA_OTCSV_VISMAG       = 30,     // APPARENT VISUAL MAGNITUDE
     XA_OTCSV_VISMAG_NORM  = 31,     // GEO NORMALIZED VISUAL MAGNITUDE
     XA_OTCSV_SOL_PHASE    = 32,     // SOLAR PHASE ANGLE
     XA_OTCSV_FRAME        = 33,     // FRAME NUMBER
     XA_OTCSV_ABERRATION   = 34,     // ABERRATION CORRECTION INDICATOR (0=YES, 1=NO)
     XA_OTCSV_ASTAT_METHOD = 35,     // 0 = ROTAS, 1 = TRACK
     
     XA_OTCSV_SIGMATYPE    = 40,     // MUST EQUAL TO 7 TO SIGNIFY THIS IS CSV FORMAT
     XA_OTCSV_SIGMAEL1     = 41,     // SIGMA\COVARIANCE ELEMENT 1 - AZ SIGMA
     XA_OTCSV_SIGMAEL2     = 42,     // SIGMA\COVARIANCE ELEMENT 2 - EL SIGMA
     XA_OTCSV_SIGMAEL3     = 43,     // SIGMA\COVARIANCE ELEMENT 3 - RANGE SIGMA
     XA_OTCSV_SIGMAEL4     = 44,     // SIGMA\COVARIANCE ELEMENT 4 - RANGE RATE SIGMA
     XA_OTCSV_SIGMAEL5     = 45,     // SIGMA\COVARIANCE ELEMENT 5 - AZ RATE SIGMA
     XA_OTCSV_SIGMAEL6     = 46,     // SIGMA\COVARIANCE ELEMENT 6 - EL RATE SIGMA
     XA_OTCSV_SIGMAEL7     = 47,     // SIGMA\COVARIANCE ELEMENT 7 - TIME SIGMA 
     XA_OTCSV_BIAS1        = 48,     // AZ/RA BIAS
     XA_OTCSV_BIAS2        = 49,     // EL/DEC BIAS
     XA_OTCSV_BIAS3        = 50,     // RANGE BIAS
     XA_OTCSV_BIAS4        = 51,     // RANGE-RATE BIAS
     XA_OTCSV_BIAS5        = 52,     // TIME BIAS
  
     
     XA_OTCSV_SIZE         = 64;   
     
  // INDEXES OF OBSERVATION DATA IN AN ARRAY
  static const int  
     XA_OBSTATE_SATNUM       =  0,     // SATELLITE NUMBER
     XA_OBSTATE_SENNUM       =  1,     // SENSOR NUMBER
     XA_OBSTATE_DS50UTC      =  2,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     
     XA_OBSTATE_POSX         = 10,     // POSITION X/ECI (KM)
     XA_OBSTATE_POSY         = 11,     // POSITION Y/ECI (KM)
     XA_OBSTATE_POSZ         = 12,     // POSITION Z/ECI (KM)   
     XA_OBSTATE_VELX         = 13,     // VELOCITY X/ECI (KM/S)
     XA_OBSTATE_VELY         = 14,     // VELOCITY Y/ECI (KM/S)
     XA_OBSTATE_VELZ         = 15,     // VELOCITY Z/ECI (KM/S)   
     XA_OBSTATE_LAT          = 16,     // GEODETIC LATITUDE (DEG)
     XA_OBSTATE_LON          = 17,     // GEODETIC LONGITUDE (DEG)
     XA_OBSTATE_HGHT         = 18,     // GEODETIC HEIGHT (KM)   
     XA_OBSTATE_POSE         = 19,     // POSITION X/EFG (KM)
     XA_OBSTATE_POSF         = 20,     // POSITION Y/EFG (KM)   
     XA_OBSTATE_POSG         = 21,     // POSITION Z/EFG (KM)
  
     
     XA_OBSTATE_SIZE         = 64;   
     
  // INDEXES OF OBSERVATION DATA AVAILABLE FOR EACH OBS TYPE (OT0: OBS TYPE 0, OT1: OBS TYPE 1, ...)
  // ALL OBS TYPES HAVE THESE COMMON DATA FIELDS  XA_OBS_SECCLASS = 0, XA_OBS_SATNUM = 1, AND  XA_OBS_SENNUM = 2
  static const int     
     XA_OT0_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT0_RANGERATE =  7,     // RANGE RATE (KM/S)  
    
     XA_OT1_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT1_ELEVATION =  4,     // ELEVATION (DEG)
     XA_OT1_AZIMUTH   =  5,     // AZIMUTH (DEG)
  
     XA_OT2_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT2_ELEVATION =  4,     // ELEVATION (DEG)
     XA_OT2_AZIMUTH   =  5,     // AZIMUTH (DEG)
     XA_OT2_RANGE     =  6,     // RANGE (KM)
  
     XA_OT3_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT3_ELEVATION =  4,     // ELEVATION (DEG)
     XA_OT3_AZIMUTH   =  5,     // AZIMUTH (DEG)
     XA_OT3_RANGE     =  6,     // RANGE (KM)
     XA_OT3_RANGERATE =  7,     // RANGE RATE (KM/S) 
  
     XA_OT4_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT4_ELEVATION =  4,     // ELEVATION (DEG)
     XA_OT4_AZIMUTH   =  5,     // AZIMUTH (DEG)
     XA_OT4_RANGE     =  6,     // RANGE (KM)
     XA_OT4_RANGERATE =  7,     // RANGE RATE (KM/S) 
     XA_OT4_ELRATE    =  8,     // ELEVATION RATE (DEG/S)
     XA_OT4_AZRATE    =  9,     // AZIMUTH RATE (DEG/S)
     XA_OT4_RANGEACCEL= 10,     // RANGE ACCELERATION (KM/S^2)
  
     XA_OT5_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT5_DECL      =  4,     // DECLINATION (DEG)
     XA_OT5_RIGHTASC  =  5,     // RIGHT ASCESION (DEG)
     XA_OT5_YROFEQNX  = 22,     // YEAR OF EQUINOX INDICATOR (0= TIME OF OBS, 1= 0 JAN OF DATE, 2= J2000, 3= B1950)
  
     XA_OT6_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT6_RANGE     =  6,     // RANGE (KM)
  
     XA_OT8_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT8_ELEVATION =  4,     // ELEVATION (DEG)
     XA_OT8_AZIMUTH   =  5,     // AZIMUTH (DEG)
     XA_OT8_RANGE     =  6,     // OPTIONAL - RANGE (KM)
     XA_OT8_POSE      = 16,     // ORBITING SENSOR POSITION X/EFG (KM)
     XA_OT8_POSF      = 17,     // ORBITING SENSOR POSITION Y/EFG (KM)
     XA_OT8_POSG      = 18,     // ORBITING SENSOR POSITION Z/EFG (KM)   
  
     XA_OT9_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OT9_DECL      =  4,     // DECLINATION (DEG)
     XA_OT9_RIGHTASC  =  5,     // RIGHT ASCESION (DEG)
     XA_OT9_RANGE     =  6,     // OPTIONAL - RANGE (KM)
     XA_OT9_POSE      = 16,     // ORBITING SENSOR POSITION X/EFG (KM)
     XA_OT9_POSF      = 17,     // ORBITING SENSOR POSITION Y/EFG (KM)
     XA_OT9_POSG      = 18,     // ORBITING SENSOR POSITION Z/EFG (KM)   
     XA_OT9_YROFEQNX  = 22,     // YEAR OF EQUINOX INDICATOR (0= TIME OF OBS, 1= 0 JAN OF DATE, 2= J2000, 3= B1950)   
  
     XA_OTP_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OTP_POSX      = 16,     // POSITION X/ECI OR X/EFG (KM)
     XA_OTP_POSY      = 17,     // POSITION Y/ECI OR Y/EFG (KM)
     XA_OTP_POSZ      = 18,     // POSITION Z/ECI OR Z/EFG (KM)   
     
     XA_OTV_DS50UTC   =  3,     // OBSERVATION TIME IN DAYS SINCE 1950 UTC
     XA_OTV_POSX      = 16,     // POSITION X/ECI OR X/EFG (KM)
     XA_OTV_POSY      = 17,     // POSITION Y/ECI OR Y/EFG (KM)
     XA_OTV_POSZ      = 18,     // POSITION Z/ECI OR Z/EFG (KM)   
     XA_OTV_VELX      = 19,     // VELOCITY X/ECI (KM/S)  (OR EDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OTV_VELY      = 20,     // VELOCITY Y/ECI (KM/S)  (OR FDOT/EFG (KM) FOR OB TYPE 7 TTY)
     XA_OTV_VELZ      = 21;     // VELOCITY Z/ECI (KM/S)  (OR GDOT/EFG (KM) FOR OB TYPE 7 TTY)
     
     
  
  // EQUINOX INDICATOR
  static const int  
     EQUINOX_OBSTIME = 0,       // TIME OF OBSERVATION
     EQUINOX_OBSYEAR = 1,       // TIME @ 0 JAN YEAR OF DATE
     EQUINOX_J2K     = 2,       // J2000
     EQUINOX_B1950   = 3;       // B1950
     
  // INDEXES FOR SORTING OB
  // SORT OPTIONS:
  // (+/-) 1 = (DESCENDING/ASCENDING) TIME, SENSOR, OBSTYPE, ELEV
  // (+/-) 2 = (DESCENDING/ASCENDING) TIME, ELEVATION
  // (+/-) 3 = (DESCENDING/ASCENDING) TIME, SENSOR, OTYPE, EL, SATNO
  // (+/-) 4 = (DESCENDING/ASCENDING) SENSOR, SATNO, TIME, ELEV
  // (+/-) 5 = (DESCENDING/ASCENDING) SENSOR, TIME, ELEVATION
  // (+/-) 6 = (DESCENDING/ASCENDING) SENSOR, SATNO, OBSTYPE, TIME, ELEV
  // (+/-) 7 = (DESCENDING/ASCENDING) SATNO, TIME, SENSOR, OTYPE, EL
  // (+/-)10 = (DESCENDING/ASCENDING) SATNO, SENSOR, TIME     
     
  static const int  
     SORT_TIMESENTYPEEL      =  1,   // SORT ORDER IS TIME, SENSOR, OBSTYPE, ELEV (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_TIMEEL             =  2,   // SORT ORDER IS TIME, ELEVATION (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_TIMESENTYPEELSAT   =  3,   // SORT ORDER IS TIME, SENSOR, OTYPE, EL, SATNO (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_SENSATTIMEEL       =  4,   // SORT ORDER IS SENSOR, SATNO, TIME, ELEV (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_SENTIMEEL          =  5,   // SORT ORDER IS SENSOR, TIME, ELEVATION (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_SENSATTYPETIMEEL   =  6,   // SORT ORDER IS SENSOR, SATNO, OBSTYPE, TIME, ELEV (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_SATTIMESENTYPEEL   =  7,   // SORT ORDER IS SATNO, TIME, SENSOR, OTYPE, EL (NEGATIVE VALUE FOR REVERSE ORDER)
     SORT_ORDERASREAD        =  8,   // SORT ORDER IS THE ORDER OF OBS WHEN THEY WERE LOADED 
     SORT_SATSENTIME         = 10;   // SORT ORDER IS SATNO, SENSOR, TIME (NEGATIVE VALUE FOR REVERSE ORDER)    
     
     
  // INDEXES OF DIFFERENT OBS FILE FORMAT
  static const int  
     OBSFORM_B3   = 0,   // B3 OBS FORMAT
     OBSFORM_TTY  = 1,   // TRANSMISSION OBS FORMAT
     OBSFORM_CSV  = 2;   // CSV OBS FORMAT
     
  static const int BADOBSKEY = -1;   
  static const int DUPOBSKEY = 0;
  
  
  // DIFFERENT KEY MODE OPTIONS FOR OBSKEY
  static const int  
     OBS_KEYMODE_NODUP  = 0,    // DEFAULT - DUPLICATE OBS CAN NOT BE LOADED IN BINARY TREE                           
     OBS_KEYMODE_DMA    = 1;    // ALLOW DUPLICATE OBS TO BE LOADED AND HAVE DIRECT MEMORY ACCESS (DMA - NO DUPLICATION CHECK AND NO BINARY TREE)   
  
     
  //*******************************************************************************   
     
// ObsDll's function pointers declaration
extern fnPtrObsInit                        ObsInit;
extern fnPtrObsGetInfo                     ObsGetInfo;
extern fnPtrObsSetTTYYear                  ObsSetTTYYear;
extern fnPtrObsLoadFile                    ObsLoadFile;
extern fnPtrObsSaveFile                    ObsSaveFile;
extern fnPtrObsRemove                      ObsRemove;
extern fnPtrObsRemoveAll                   ObsRemoveAll;
extern fnPtrObsGetCount                    ObsGetCount;
extern fnPtrObsGetLoaded                   ObsGetLoaded;
extern fnPtrObsLoadCard                    ObsLoadCard;
extern fnPtrObsLoadTwoCards                ObsLoadTwoCards;
extern fnPtrObsAddFrB3Card                 ObsAddFrB3Card;
extern fnPtrObsAddFrB3CardML               ObsAddFrB3CardML;
extern fnPtrObsB3ToCsv                     ObsB3ToCsv;
extern fnPtrObsCsvToB3                     ObsCsvToB3;
extern fnPtrObsAddFrTTYCards               ObsAddFrTTYCards;
extern fnPtrObsAddFrTTYCardsML             ObsAddFrTTYCardsML;
extern fnPtrObsTTYToCsv                    ObsTTYToCsv;
extern fnPtrObsCsvToTTY                    ObsCsvToTTY;
extern fnPtrObsAddFrCsv                    ObsAddFrCsv;
extern fnPtrObsAddFrCsvML                  ObsAddFrCsvML;
extern fnPtrObsAddFrFields                 ObsAddFrFields;
extern fnPtrObsAddFrFieldsML               ObsAddFrFieldsML;
extern fnPtrObsAddFrArray                  ObsAddFrArray;
extern fnPtrObsAddFrArrayML                ObsAddFrArrayML;
extern fnPtrObsGetAllFields                ObsGetAllFields;
extern fnPtrObsDataToArray                 ObsDataToArray;
extern fnPtrObsUpdateFrFields              ObsUpdateFrFields;
extern fnPtrObsGetField                    ObsGetField;
extern fnPtrObsSetField                    ObsSetField;
extern fnPtrObsGetB3Card                   ObsGetB3Card;
extern fnPtrObsGetTTYCard                  ObsGetTTYCard;
extern fnPtrObsGetCsv                      ObsGetCsv;
extern fnPtrObsFieldsToB3Card              ObsFieldsToB3Card;
extern fnPtrObsFieldsToCsv                 ObsFieldsToCsv;
extern fnPtrObsFieldsToTTYCard             ObsFieldsToTTYCard;
extern fnPtrObsFieldsToObsKey              ObsFieldsToObsKey;
extern fnPtrObsFieldsToObsKeyML            ObsFieldsToObsKeyML;
extern fnPtrObsB3Parse                     ObsB3Parse;
extern fnPtrObsParse                       ObsParse;
extern fnPtrObsLoadFileGID                 ObsLoadFileGID;
extern fnPtrObsSaveFileGID                 ObsSaveFileGID;
extern fnPtrObsRemoveGID                   ObsRemoveGID;
extern fnPtrObsGetCountGID                 ObsGetCountGID;
extern fnPtrObsGetLoadedGID                ObsGetLoadedGID;
extern fnPtrObsTypeCToI                    ObsTypeCToI;
extern fnPtrObsTypeIToC                    ObsTypeIToC;
extern fnPtrObsResetSelObs                 ObsResetSelObs;
extern fnPtrObsGetStates                   ObsGetStates;
extern fnPtrObsDataToStates                ObsDataToStates;
extern fnPtrObsArrToLines                  ObsArrToLines;
extern fnPtrSetObsKeyMode                  SetObsKeyMode;
extern fnPtrGetObsKeyMode                  GetObsKeyMode;
extern fnPtrSatNumFrObsKey                 SatNumFrObsKey;
extern fnPtrSenNumFrObsKey                 SenNumFrObsKey;



void LoadObsDll();
void FreeObsDll();




#endif
// ========================= End of auto generated code ==========================
