// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef LAMODDLL_H
#define LAMODDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define LamodDll "Lamod.dll"
#elif __APPLE__
  #define LamodDll "liblamod.dylib"
#else
  #define LamodDll "liblamod.so"
#endif


// Initializes Lamod dll for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. The error occurs if the users forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisite section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Lamod.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodInit)(__int64 apPtr);


// Returns information about the current version of Lamod.dll. The information is placed in the string parameter you pass in
// The returned string provides information about the version number, build date, and the platform of the Lamod DLL. 
// infoStr            A string to hold the information about Lamod.dll. (out-Character[128])
typedef void (STDCALL *fnPtrLamodGetInfo)(char infoStr[128]);


// Loads Lamod-related parameters (1P/2P/3P cards, and Lamod parameter free format) from an input text file
// Returns zero indicating the file has been read successfully. Other values indicate an error.
// lamodInputFile     The name of the file containing Lamod-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodLoadFile)(char lamodInputFile[512]);


// Loads Lamod control parameters and all Lamod related data (environment, time, elsets, sensors) from an input text file
// lamodInputFile     The name of the file containing Lamod control parameters and all Lamod related data (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodLoadFileAll)(char lamodInputFile[512]);


// Loads a single Lamod-typed card
// card               Lamod-type input card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodLoadCard)(char card[512]);


// Saves any currently loaded Lamod-related settings to a file
// The purpose of this function is to save the current Lamod-related settings, usually used in GUI applications, for future use.
// lamodFile          The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodSaveFile)(char lamodFile[512], int saveMode, int saveForm);


// Returns number of sensors/satellites entered via 1P/2P cards
// See LamodGetSenNums for example.
// numSens            The number of sensors that were entered via 1P/2P cards (out-Integer)
// numSats            number of satellites that were entered via 1P/2P cards (out-Integer)
typedef void (STDCALL *fnPtrLamodGetNumOfSensSats)(int* numSens, int* numSats);


// Retrieves all of the input sensor numbers that were entered via 1P-card  (column 38-44), 2P-card, or Lamod parameter free format (SENNO=)
// senNums            The array in which to store the list of input sensors that were entered via 1P/2P cards or Lamod parameter free format (out-Integer[*])
typedef void (STDCALL *fnPtrLamodGetSenNums)(int senNums[]);


// Retrieves all of the input satellite numbers that were entered via 1P-card (column 40-62), 2P-card, or Lamod parameter free format (SATNO=)
// See LamodGetSenNums for example.
// satNums            The array in which to store the list of input satellites that were entered via 1P/2P cards or Lamod parameter free format (out-Integer[*])
typedef void (STDCALL *fnPtrLamodGetSatNums)(int satNums[]);


// Builds and returns the Lamod parameter card (1P-Card) from the current Lamod settings
// lamod1PCard        the resulting Lamod 1P card (out-Character[512])
typedef void (STDCALL *fnPtrLamodGet1pCard)(char lamod1PCard[512]);


// Retrieves all Lamod control parameters with a single function call
// timeFlg            Time format:0 = minutes since epoch (MSE), 1 = days since 1950, UTC (out-Integer)
// startTime          Begin time in ds50UTC or MSE depending on timeFlg (out-Double)
// stopTime           End time  in ds50UTC or MSE depending on timeFlg (out-Double)
// interval           Output interval (min) (out-Double)
// prtOpt             Print options (out-Integer)
// punchObs           Flag to generate obs from look angles: 0=Do not form obs, 1=Form B3 obs from look angles, 2=Form TTY obs from look angles (out-Integer)
// visFlg             Optical visibility flag:	0=Accept all passes, 1=Accept optically visual pass only, 2=Same as 1 w/ SAA restrictions, 3=For IR sensors, 9=Use limits record (out-Integer)
// stepMode           Step mode flag: 0= use culmination mode, 1= use step mode, 2= use task mode (out-Integer)
// schedMode          Processing mode:'O' = OBSCHED mode (all sensors vs all sats), 'P' = PASCHED mode (all satellites vs all sensors) (out-Character)
// diagMode           Pass by pass diagnostic flag: 0=None, 1=Print sensor/sat position at each look, 2=Print pass-by-pass diagnostics, 3=1+2 combined (out-Integer)
// solAspAngle        Max solar aspect angle (deg) for optical sites (out-Double)
typedef void (STDCALL *fnPtrLamodGet1pAll)(int* timeFlg, double* startTime, double* stopTime, double* interval, int* prtOpt, int* punchObs, int* visFlg, int* stepMode, char* schedMode, int* diagMode, double* solAspAngle);


// Sets all Lamod control parameters with a single function call
// The values of visFlg have been changed to match those of sensor limits. VisFlg = 9 now means using limits record value (from V5.4.2 and earlier versions, this used to be visFlg = 0).
// 
// There are cases when the program switches to step mode even though the users have requested culmination mode:
// 
// When the sensor is an orbiting sensor
// When the target satellite orbit has large period (> 960 minutes)
// When the last pass's culmination time passes the requested stopTime (culmination time == 0 and setTime == 0)
// When a pass has multiple maximum elevations (culmination time == -1.0)
// 
// timeFlg            Time format:0 = minutes since epoch (MSE), 1 = days since 1950, UTC (in-Integer)
// startTime          Begin time in ds50UTC or MSE depending on timeFlg (in-Double)
// stopTime           End time  in ds50UTC or MSE depending on timeFlg (in-Double)
// interval           Output interval (min) (in-Double)
// prtOpt             Print options (in-Integer)
// punchObs           Flag to generate obs from look angles: 0=Do not form obs, 1=Form B3 obs from look angles, 2=Form TTY obs from look angles (in-Integer)
// visFlg             Optical visibility flag:	0=Accept all passes, 1=Accept optically visual pass only, 2=Same as 1 w/ SAA restrictions, 3=For IR sensors, 9=Use limits record (in-Integer)
// stepMode           Step mode flag: 0= use culmination mode, 1= use step mode, 2= use task mode (in-Integer)
// schedMode          Processing mode:'O' = OBSCHED mode (all sensors vs all sats), 'P' = PASCHED mode (all satellites vs all sensors) (in-Character)
// diagMode           Pass by pass diagnostic flag: 0=None, 1=Print sensor/sat position at each look, 2=Print pass-by-pass diagnostics, 3=1+2 combined (in-Integer)
// solAspAngle        Max solar aspect angle (deg) for optical sites (in-Double)
typedef void (STDCALL *fnPtrLamodSet1pAll)(int timeFlg, double startTime, double stopTime, double interval, int prtOpt, int punchObs, int visFlg, int stepMode, char schedMode, int diagMode, double solAspAngle);


// Retrieves the value of a specified Lamod control parameter (1P-card field) 
// 
// Remember to convert valueStr to the correct data type that it represents.
// 
// The table below shows the values for the xf_1P parameter:
// 
// 
// Index
// Index Interpretation
// 
// 1   Input time format : 0: Minutes since epoch, 1: UTC
// 2   Begin time
// 3   End time
// 4   Ouput interval
// 5   Print options: 0: print look angles, 1: print look angle and initial conditions
// 6   Generate obs from look angles flag
// 7   Compute optical visibility flag: 0: use limits record value, 1: output optically visible passes only,
// 2: output pass only if solar aspect angle 
// 8   Step mode flag: 0: use culmination mode; 1: use step mode
// 9   Processing mode: 'O': obsched mode; 'P':P ASCHED mode
// 10  Diagnostic mode: 0: none, 1: print sensor/sat position at each look, 2: print pass by pass diagnostics,
// 3: both 1 and 2
// 11  Max solar aspect for optical sites   
// 	
// xf_1P              Predefined number specifying which Lamod control parameter  to retrieve (in-Integer)
// retVal             A string to hold the value of the requested Lamod parameter (out-Character[512])
typedef void (STDCALL *fnPtrLamodGet1pField)(int xf_1P, char retVal[512]);


// Sets the value of a specified Lamod control parameter (1P-card field)
// See LamodGet1pField for description of the xf_1P parameter values.
// xf_1P              Predefined number specifying which Lamod control parameter to set (in-Integer)
// valueStr           The new value of the specified field, expressed as a string (in-Character[512])
typedef void (STDCALL *fnPtrLamodSet1pField)(int xf_1P, char valueStr[512]);


// Retrieves the concurrent viewing options read from the input 3P Parameter card
// The concurrent viewing implementation is used to be totally in the LamodDll.dll. Now, the Lamod library provides the users the capability to implement the concurrent viewing from their driver programs. There is no limit on the number of satellites/sensors being use in concurrent viewing in the new library.
// concurrFlg         Concurrent view option: 0=Normal looks (1 sen + 1 sat), 1/4=2 or 3 sens viewing the same target sat, 2/3=1 orbiting sen viewing the target sat as 2nd/3rd site(s) viewing the orbiting sen (out-Integer)
// concurrSens        Concurrent sensor numbers (maximum 3 sensors) (out-Integer[3])
typedef void (STDCALL *fnPtrLamodGet3pAll)(int* concurrFlg, int concurrSens[3]);


// Sets concurrent viewing options similar to what is entered in the input 3P Parameter card
// The concurrent viewing implementation is used to be totally in the LamodDll.dll. Now, the Lamod library provides the users the capability to implement the concurrent viewing from their driver programs. There is no limit on the number of satellites/sensors being use in concurrent viewing in the new library.
// concurrFlg         Concurrent view option: 0=Normal looks (1 sen + 1 sat), 1/4=2 or 3 sens viewing the same target sat, 2/3=1 orbiting sen viewing the target sat as 2nd/3rd site(s) viewing the orbiting sen (in-Integer)
// concurrSens        Concurrent sensor numbers (maximum 3 sensors) (in-Integer[3])
typedef void (STDCALL *fnPtrLamodSet3pAll)(int concurrFlg, int concurrSens[3]);


// Returns the full file name of the output obs file that was specified using "OBSOUT = " in the main input file or using the LamodSetObsFileName() function call
// The users need to make sure they have turned on the flag to generate obs from look angles. Otherwise, this function will return an empty string to the obsFile.
// obsFile            The output obs file name (out-Character[512])
typedef void (STDCALL *fnPtrLamodGetObsFileName)(char obsFile[512]);


// Sets the full file name of the output obs file which will be used to store the generated obs data
// Another way to set the output obs file name is entering "OBSOUT = obsFileName" in the input file. 
// 
// The users need to make sure they have also turned on the flag to generate obs from look angles.
// obsFile            The new output obs file name (in-Character[512])
typedef void (STDCALL *fnPtrLamodSetObsFileName)(char obsFile[512]);


// Checks to see whether the input satellite will ever be viewable to the input sensor
// This function is for the initial visibility check which screens out sensors that can't possibly acquire the satellite. Internally, the LamodInitSenSat() also calls this function to do the screening.
// 
// If the satellite is an EXTEPHEM (see External Ephemerides document), it will always pass this visibility check (assume the satellite is viewable to the sensor).
// senKey             The sensor's unique key (sensor number) (in-Integer)
// satKey             The satellite's unique key (in-Long)
// returns 1 if the input satellite is viewable to the input sensor, 0 if not
typedef int (STDCALL *fnPtrLamodSenSatVisible)(int senKey, __int64 satKey);


// Initializes a sensor/satellite pair in preparation for computing look angles
// It's a good practice to initialize the satellite (SatState.SatStateInitSat) before calling this routine.
// 
// The users need to call this routine only once for each sensor/satellite pair they want to compute the look angles. The function however can be called again when the sensor and/or the satellite data is changed.
// 
// Internally, this function does the initial visibility check to see if the sensor can possibly acquire the satellite. However, if the satellite is an EXTEPHEM (see External Ephemerides document), it will always pass this visibility check (assume the satellite is viewable to the sensor).
// senKey             The sensor's unique key (sensor number) (in-Integer)
// satKey             The satellite's unique key (in-Long)
// returns Returns a senSatKey: gt 0: Success, = 0: Warning, lt 0: Error
typedef __int64 (STDCALL *fnPtrLamodInitSenSat)(int senKey, __int64 satKey);


// Initializes a sensor/satellite pair in preparation for computing look angles using its own LAMOD parameters - suitable for multithread application
// This function is similar to LamodInitSenSat but allows the user to enter separate LAMOD parameters for each call which is suitable for multithread application
// It's a good practice to initialize the satellite (SatState.SatStateInitSat) before calling this routine.
// 
// The users need to call this routine only once for each sensor/satellite pair they want to compute the look angles. The function however can be called again when the sensor and/or the satellite data is changed.
// 
// Internally, this function does the initial visibility check to see if the sensor can possibly acquire the satellite. However, if the satellite is an EXTEPHEM (see External Ephemerides document), it will always pass this visibility check (assume the satellite is viewable to the sensor).
// xa_la_parms        LAMOD control parameters - see XA_LA_PARMS_? for array arrangement (in-Double[16])
// senKey             The sensor's unique key (sensor number) (in-Integer)
// satKey             The satellite's unique key (in-Long)
// returns Returns a senSatKey: gt 0: Success, = 0: Warning, lt 0: Error
typedef __int64 (STDCALL *fnPtrLamodInitSenSat_MT)(double xa_la_parms[16], int senKey, __int64 satKey);


// Retrieves all of the data for an initialized sensor/satellite pair with a single function call
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// stepMode           Step mode flag: 0= use culmination mode, 1= use step mode, 2= use task mode (out-Integer)
// visPassOnly        Visual pass only (out-Integer)
// startDs50TAI       Start time in ds50TAI (out-Double)
// stopDs50TAI        Stop time in ds50TAI (out-Double)
// interval           Output interval (min) (out-Double)
// period             Satellite's period (min) (out-Double)
// returns 0 if the computation data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGetSenSatDataAll)(__int64 senSatKey, int* stepMode, int* visPassOnly, double* startDs50TAI, double* stopDs50TAI, double* interval, double* period);


// Retrieves an individual field of data for an initialized sensor/satellite pair
// 
// Remember to convert valueStr to the correct data type that it represents.
// 
// The table below shows the values for the xf_SenSat parameter:
// 
// 
// Index
// Index Interpretation
// 
//  1  Step mode
//  2  Visual pass only
//  3  Begin time in ds50TAI
//  4  End time in ds50TAI
//  5  Print interval 
//  6  Satellite's period
// 
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// xf_SenSat          Predefined number specifying which data field to retrieve (in-Integer)
// retVal             A string to contain the value of the requested field (out-Character[512])
// returns 0 if the data is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGetSenSatDataField)(__int64 senSatKey, int xf_SenSat, char retVal[512]);


// Retrieves all data fields belonging to the sensor/satellite pair via its senSatKey and store them in the passing array xa_senSat
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// xa_senSat          Array containing sensor/satellite data fields, see XA_SENSAT_? for array arrangement (out-Double[32])
// returns 0 if the sensor/satellite data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodSenSatDataToArray)(__int64 senSatKey, double xa_senSat[32]);


// Returns the number of possible passes of the sensor/satellite pair in the requested time span which pass 
// the horizontal limit test. This function only applies when the culmination mode was selected
// This is an estimated number of passes. Each pass might not return any valid look angles due to the sensor limits settings.
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// returns The number of possible passes. Special values: -1: The senSatKey is invalid, 0: culmination mode wasn't selected
typedef int (STDCALL *fnPtrLamodGetNumPasses)(__int64 senSatKey);


// Returns an array of rise, culmination, and set times of all possible passes of a sensor/satellite pair during the requested time span
// See LamodGetNumPasses for example.
// If a possible culmination time of the last pass is after the requested stop time, only the rise time is returned. The culmination and set times are set to zeros. Since there is no culmination time in this case, the host program should switch to step mode to compute look angles.
// 
// There are cases when multiple maximum elevations are detected in one pass. In these cases, the culmination times will be set to -1.0. The users need to check for this condition and switch to step mode.
// 
// For external ephemeris files, if the provided ephemerides don't cover the requested time span, the possible rise and set times will not be available and will be set to -1.0.
// senSatKey          sensor/satellite pair's unique key (in-Long)
// rcsTimeArr         array of rise/culmination/set times in days since 1950 TAI of the possible passes (out-Double[*, 3])
// returns 0 if the computation is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGetRiseCulmSetTimes)(__int64 senSatKey, double rcsTimeArr[][3]);


// Computes a single look angle of the sensor/satellite pair at the specified time
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// currDs50TAI        Time, in ds50TAI, for which to compute the look angle (in-Double)
// lookCode           lookCode: 0=valid look; 1=Fail horizon break test; 2=Fail sensor's limit tests (out-Integer)
// lookArr            look output data: ds50UTC, mse, el (deg), az (deg), range (km), rangeRate (km/s) (out-Double[6])
// senElts            sensor's state (ECI TEME of Date): position (1st-3rd), velocity (4th-6th), llh (7th-9th) (out-Double[9])
// satElts            satellite's state (ECI TEME of Date): position (1st-3rd), velocity (4th-6th), llh (7th-9th) (out-Double[9])
// returns 0 if the look angle is computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodComputeLookAngle)(__int64 senSatKey, double currDs50TAI, int* lookCode, double lookArr[6], double senElts[9], double satElts[9]);


// Computes at once look and view data of the sensor/satellite pair at the specified time
// 
// Note: This function is a thread safe alternative to LamodComputeLookAngle(), LamodGetOrbSenViewdata(), and LamodGetViewDataField()
// 
// The following table lists the values for the XA_LV array:
// 
// 
// Name
// Index
// Index Interpretation
// 
// XA_LV_LOOKCODE   0look code: 0=valid look; 1=Fail horizon break test; 2=Fail sensor's limit
// tests
// XA_LV_DS50UTC    1time in ds50UTC when the look angle is computed
// XA_LV_MSE        2time mse when the look angle is computed
// XA_LV_ELEV       3elevation (deg)
// XA_LV_AZIM       4azimuth (deg)
// XA_LV_RNG        5range (km)
// XA_LV_RNGRT      6range rate (km/s)
// XA_LV_RA         7right ascension (deg)
// XA_LV_DEC        8declination (deg)
// XA_LV_AZRATE     9azimuth rate (deg/s)
// XA_LV_ELRATE    10elevation rate (deg/s)
// XA_LV_SENPOSX   11sensor ECI position (X) (km)
// XA_LV_SENPOSY   12sensor ECI position (Y) (km)
// XA_LV_SENPOSZ   13sensor ECI position (Z) (km)
// XA_LV_SENVELX   14sensor ECI velocity (X) (km/s)
// XA_LV_SENVELY   15sensor ECI velocity (Y) (km/s)
// XA_LV_SENVELZ   16sensor ECI velocity (Z) (km/s)
// XA_LV_SENLAT    17sensor latitude (deg)
// XA_LV_SENLON    18sensor longitude (deg)
// XA_LV_SENHEIGHT 19sensor height (km)
// XA_LV_SATPOSX   20satellite ECI position (X) (km)
// XA_LV_SATPOSY   21satellite ECI position (Y) (km)
// XA_LV_SATPOSZ   22satellite ECI position (Z) (km)
// XA_LV_SATVELX   23satellite ECI velocity (X) (km/s)
// XA_LV_SATVELY   24satellite ECI velocity (Y) (km/s)
// XA_LV_SATVELZ   25satellite ECI velocity (Z) (km/s)
// XA_LV_SATLAT    26satellite latitude (deg)
// XA_LV_SATLON    27satellite longitude (deg)
// XA_LV_SATHEIGHT 28satellite height (km)
// XA_LV_UVECX     31computed U-vector to object (X)
// XA_LV_UVECY     32computed U-vector to object (Y)
// XA_LV_UVECZ     33computed U-vector to object (Z)
// XA_LV_RUVECX    34slant range unit vector (X)- vector from the sensor to the
// satellite
// XA_LV_RUVECY    35slant range unit vector (Y)- vector from the sensor to the
// satellite
// XA_LV_RUVECZ    36slant range unit vector (Z)- vector from the sensor to the
// satellite
// XA_LV_LVECX     37station unit vector (X) - vector directed from the center of the earth to
// the sensor
// XA_LV_LVECY     38station unit vector (Y) - vector directed from the center of the earth to
// the sensor
// XA_LV_LVECZ     39station unit vector (Z) - vector directed from the center of the earth to
// the sensor
// XA_LV_ZVECX     40station zenith vector (X)
// XA_LV_ZVECY     41station zenith vector (Y)
// XA_LV_ZVECZ     42station zenith vector (Z)
// XA_LV_RNGVECX   43slant range vector (X) (km) - vector from the sensor to the
// satellite
// XA_LV_RNGVECY   44slant range vector (Y) (km) - vector from the sensor to the
// satellite
// XA_LV_RNGVECZ   45slant range vector (Z) (km) - vector from the sensor to the
// satellite
// XA_LV_RRTVECX   46range-rate vector - relative velocity vector (X) (km/s)
// XA_LV_RRTVECY   47range-rate vector - relative velocity vector (Y) (km/s)
// XA_LV_RRTVECZ   48range-rate vector - relative velocity vector (Z) (km/s)
// XA_LV_USUNX     49unit vector to sun (X)
// XA_LV_USUNY     50unit vector to sun (Y)
// XA_LV_USUNZ     51unit vector to sun (Z)
// XA_LV_UMOONX    52unit vector to moon (X)
// XA_LV_UMOONY    53unit vector to moon (Y)
// XA_LV_UMOONZ    54unit vector to moon (Z)
// XA_LV_MOSESA    55moon/sensor/satellite angle (deg)
// XA_LV_MOEASA    56moon/earth/satellite angle (deg)
// XA_LV_MOEASE    57moon/earth/sensor angle (deg)
// XA_LV_SUSESA    58sun/sensor/satellite angle (deg)
// XA_LV_SUEASA    59sun/earth/satellite angle (deg)
// XA_LV_SUEASE    60sun/earth/sensor angle (deg)
// XA_LV_SOLAA     61solar aspect angle (deg)
// XA_LV_VIS       62illumination result
// XA_LV_RELVEL    63relative velocity (km/s)
// XA_LV_AZLIM     70pass azimuth check (0=failed, 1=passed)
// XA_LV_ELLIM     71pass elevation check (0=failed, 1=passed)
// XA_LV_EARTHBK   72pass earth in background check (0=failed, 1=passed)
// XA_LV_EARTHOB   73pass earth obstruction check (0=failed, 1=passed)
// XA_LV_LUNEXCL   74pass lunar exclusion check (0=failed, 1=passed)
// XA_LV_MAXRANGE  75pass maximum range check (0=failed, 1=passed)
// XA_LV_MINRANGE  76pass minimum range check (0=failed, 1=passed)
// XA_LV_PENECLIP  77pass penum eclipse check (0=failed, 1=passed)
// XA_LV_RVELLIM   78pass relative velocity check (0=failed, 1=passed)
// XA_LV_SAALIM    79pass solar aspect angle check (0=failed, 1=passed)
// XA_LV_SOLEXCL   80pass solar exclusion angle check (0=failed, 1=passed)
// XA_LV_UMBECLIP  81pass umbral eclipse check (0=failed, 1=passed)
// XA_LV_OPTVIS    82pass visibility check for optical sensor (0=failed, 1=passed)
// XA_LV_SENPOSE   90orbiting sensor EFG position (X) (km)
// XA_LV_SENPOSF   91orbiting sensor EFG position (Y) (km)
// XA_LV_SENPOSG   92orbiting sensor EFG position (Z) (km)
// XA_LV_NBORE1    93orbiting sensor boresight vector #1 (1='D', 2='U', 3='B', 4='A', 5='R',
// 6='L', 7=no limits)
// XA_LV_NBORE2    94orbiting sensor boresight vector #2 (1='D', 2='U', 3='B', 4='A', 5='R',
// 6='L', 7=no limits)
// XA_LV_OBEL1     95orbiting sensor off boresight elevation #1 (deg)
// XA_LV_OBAZ1     96orbiting sensor off boresight azimuth #1 (deg)
// XA_LV_OBAZ2     97orbiting sensor off boresight elevation #2 (deg)
// XA_LV_OBEL2     98orbiting sensor off boresight azimuth #2 (deg)
// XA_LV_SIZE     128
//    
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// currDs50TAI        Time, in ds50TAI, for which to compute the look angle (in-Double)
// xa_lv              The array that stores resulting look and view data, see XA_LV_? for array arrangement (out-Double[128])
// returns 0 if the look angle is computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodComputeLookView)(__int64 senSatKey, double currDs50TAI, double xa_lv[128]);


// Finds exact time when satellite is IN or OUT of sensor's coverage
// 
// Note: The start and end times must have different look values (valid and invalid looks or vice versa)
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// t1Ds50TAI          The bracket start time when satellite changes its coverage status, in ds50TAI (in-Double)
// t2Ds50TAI          The bracket end time when satellite changes its coverage status, in ds50TAI (in-Double)
// returns The exact time when satellite is IN or OUT of sensor's coverage (= 0 if none exists)
typedef double (STDCALL *fnPtrLamodFindExactIOTime)(__int64 senSatKey, double t1Ds50TAI, double t2Ds50TAI);


// Returns viewing and geometric data for orbiting sensors
// 
// Note: This function is not thread safe, please use LamodComputeLookView() instead   
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// uvSun              unit vector to the sun (out-Double[3])
// uvMoon             unit vector to the moon (out-Double[3])
// angArr             array of angles (deg): moon/sen/sat, sun/earth/sat, sun/earth/sen, sun/sen/sat, solar aspect angle (out-Double[5])
// nBore1             Orbiting sensor boresight vector (U, V, W) for limits interval #1 (out-Integer)
// nBore2             Orbiting sensor boresight vector (U, V, W) for limits interval #2 (out-Integer)
// offBoreAzEl        array of angles (deg): Off-boresight az #1, Off-boresight az #2, Off-boresight el #1, Off-boresight el #2 (out-Double[4])
// returns 0 if the viewing data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGetOrbSenViewdata)(__int64 senSatKey, double uvSun[3], double uvMoon[3], double angArr[5], int* nBore1, int* nBore2, double offBoreAzEl[4]);


// Retrieves a single field of look angle viewing data
// 
// See LamodCompRaDec for an example.
// 
// Note: This function is not thread safe, please use LamodComputeLookView() instead    
// 
// When the users pass the retArray to this function, make sure it has the proper size as shown in the retArray size column.
// 
// The retArray Arrangement column lists the order of the elements in the array. It is not necessarily the subscript of the element in the array since this is language-dependent. For example, in C/C++ the first element in every array is the zero-subscripted element.
// 
// The table below shows the values for the xf_View parameter:
// 
// 
// Index
// Index Interpretation
// 
//  1  computed U-vector to object
//  2  range unit vector
//  3  topocentric L unit vector
//  4  station zenith vector
//  5  computed range vector (km)
//  6  computed range-rate vector/relative velocity vector (er/kem)
//  7  vector to sun  (km)
//  8  vector to moon (km)
//  9  angle array (1:moon/sen/sat, 2:sun/earth/sat, 3:sun/earth/sen, 4:sun/sen/sat, 5:solar aspect
// angle)
// 10  illumination result
// 11  Relative velocity (km/sec)
// 12  sensor position EFG
// 13  limit check flags
// 14  azimuth and elevation rates (deg/sec)
// 15  moon angles (1:moon/earth/sat in deg, 2:moon/earth/sen in deg)
// 	
// 
// The table below shows the values for the limit check flags (xf_View = 13):
// 
// 
// Index
// Index Interpretation
// 
//   0 az limits test flag
//   1 el limits test flag
//   2 earth in background flag
//   3 earth obstructed flag
//   4 lunar exclusion angle fl
//   5 max range test flag
//   6 min range test flag
//   7 penumb eclipse test flag
//   8 relative velocity test fl
//   9 solar aspect angle test
//  10 solar exclusion angle fl
//  11 umbral eclipse test flag
// 	
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// xf_View            Predefined value specifying which field to retrieve (in-Integer)
// retVal             An array to store the retrieved result (out-Double[*])
// returns 0 if the viewing data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGetViewDataField)(__int64 senSatKey, int xf_View, double retVal[]);


// Computes right-ascension and declination from the input sensor's range unit vector (also called local horizon vector)
// The users need to be careful when -1 < decDeg < 0 because they might easily display it incorrectly (missing the negative sign of its value).
// xlPos              sensor local horizon vector (range unit vector) (in-Double[3])
// rasc               computed right ascension (deg) (out-Double)
// decl               computed declination (deg) (out-Double)
// raHr               Right-ascension hour (out-Integer)
// raMin              Right-ascension minute (out-Integer)
// raSec              Right-ascension second (out-Double)
// decDeg             Declination hour (out-Integer)
// decMin             Declination minute (out-Integer)
// decSec             Declination second (out-Double)
typedef void (STDCALL *fnPtrLamodCompRaDec)(double xlPos[3], double* rasc, double* decl, int* raHr, int* raMin, double* raSec, int* decDeg, int* decMin, double* decSec);


// Retrieves the formatted observation strings, either in B3 or transmission format, generated from the most recent look angle data
// Note: This function is not thread safe, please use LamodGenObsAtTime() instead 
// The function returns one-line or two-line formatted obs string depending on the input punchObs and the sensor's observation type.  The users need to check the returned value of numLines to see what type of the output strings they are.
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// punchObs           Generate obs from look angles flag: 1/11=Form B3 obs, 2/12=Form transmission, 3/13=SP Tasker (11/12/13 is for LTC), 4=CSV format (in-Integer)
// obsClass           Input character specifying the classification of the generated obs (in-Character)
// obsLine1           First line of the formatted obs strings (out-Character[512])
// obsLine2           Second line, if available, of the formatted obs strings (out-Character[512])
// numLines           Number of lines of the output strings (out-Integer)
// returns 0 if the generated obs strings are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGenObs)(__int64 senSatKey, int punchObs, char obsClass, char obsLine1[512], char obsLine2[512], int* numLines);


// Generates formatted observation strings, either in B3 or transmission format, from a VALID look angle obtained at the requested time 
// Note: This is a thread-safe version of the LamodGenObs
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// currDs50TAI        Time, in ds50TAI, for which to compute the look angle (in-Double)
// punchObs           Generate obs from look angles flag: 1=Form B3 obs, 2=Form transmission, 3=SP Tasker, 4=CSV format (in-Integer)
// obsClass           Input character specifying the classification of the generated obs (in-Character)
// obsLine1           First line of the formatted obs strings (out-Character[512])
// obsLine2           Second line, if available, of the formatted obs strings (out-Character[512])
// numLines           Number of lines of the output strings (out-Integer)
// returns 0 if the generated obs strings are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodGenObsAtTime)(__int64 senSatKey, double currDs50TAI, int punchObs, char obsClass, char obsLine1[512], char obsLine2[512], int* numLines);


// Removes a sensor/satellite pair from Lamod.dll's set of loaded sensor/satellite pairs
// senSatKey          The sensor/satellite pair's unique key (in-Long)
// returns 0 if the sensor/satellite pair is removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodRemoveSenSat)(__int64 senSatKey);


// Removes all sensor/satellite pairs from Lamod.dll's set of sensor/satellite pairs
// returns 0 if all sensor/satellite pairs are removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrLamodRemoveAllSenSats)();


// Resets all Lamod-related parameters back to their default values
// See LamodRemoveAllSenSats for example.
typedef void (STDCALL *fnPtrLamodReset)();
  
  // INDEXES OF SENSATDATA FIELDS
  static const int  
     XF_SENSAT_STEPMODE     = 1,      // STEP MODE FLAG: 0= USE CULMINATION MODE, 1= USE STEP MODE, 2= USE TASK MODE
     XF_SENSAT_VISPASSONLY  = 2,      // VISUAL PASS ONLY
     XF_SENSAT_BEGDS50TAI   = 3,      // BEGIN TIME IN DS50TAI
     XF_SENSAT_ENDDS50TAI   = 4,      // END TIME IN DS50TAI
     XF_SENSAT_INTERVAL     = 5,      // PRINT INTERVAL 
     XF_SENSAT_PERIOD       = 6;      // SATELLITE'S PERIOD 
  
  
  //*******************************************************************************
  // INDEXES OF LOOKCODE
  static const int  
     LOOK_VALID   = 0,             // VALID LOOK 
     LOOK_HTEST   = 1,             // FAILED HORIZON BREAK TEST
     LOOK_SENLIMS = 2;             // FAILED LIMIT TESTS
  
  //*******************************************************************************
  
  // INDEXES OF LOOK ANGLE DATA OUTPUT
  static const int  
     XA_LOOK_DS50UTC= 0,          // LOOK TIME IN DS50UTC
     XA_LOOK_MSE    = 1,          // LOOK TIME IN MINUTES SINCE EPOCH
     XA_LOOK_ELEV   = 2,          // ELEVATION (DEG)
     XA_LOOK_AZIM   = 3,          // AZIMUTH (DEG)
     XA_LOOK_RNG    = 4,          // RANGE (KM) OR ? FOR OPTICAL SENSOR
     XA_LOOK_RNGRT  = 5,          // RANGE RATE (KM/SEC) OR ? FOR OPTICAL SENSOR
     XA_LOOK_SIZE   = 6;
     
  //*******************************************************************************   
  
  // INDEXES OF VIEWING DATA OUTPUT
  static const int  
     XF_VIEW_UVEC      =  1,         // COMPUTED U-VECTOR TO OBJECT
     XF_VIEW_RUVEC     =  2,         // RANGE UNIT VECTOR
     XF_VIEW_LVEC      =  3,         // TOPOCENTRIC L UNIT VECTOR
     XF_VIEW_ZVEC      =  4,         // STATION ZENITH VECTOR
     XF_VIEW_RNGVEC    =  5,         // COMPUTED RANGE VECTOR (KM)
     XF_VIEW_RRTVEC    =  6,         // COMPUTED RANGE-RATE VECTOR/RELATIVE VELOCITY VECTOR (ER/KEM)
     XF_VIEW_SUNVEC    =  7,         // UNIT VECTOR OF SUN 
     XF_VIEW_MOONVEC   =  8,         // UNIT VECTOR OF MOON
     XF_VIEW_ANGARR    =  9,         // ANGLE ARRAY (1:MOON/SEN/SAT, 2:SUN/EARTH/SAT, 3:SUN/EARTH/SEN, 4:SUN/SEN/SAT, 5:SOLAR ASPECT ANGLE)
     XF_VIEW_CVIS      = 10,         // ILLUMINATION RESULT
     XF_VIEW_RELVEL    = 11,         // RELATIVE VELOCITY (KM/SEC)
     XF_VIEW_SENEFG    = 12,         // SENSOR POSITION EFG
     XF_VIEW_LIMFLGS   = 13,         // LIMIT CHECK FLAGS
     XF_VIEW_AZELRATES = 14,         // AZIMUTH AND ELEVATION RATES (DEG/SEC)
     XF_VIEW_MOONANGLES= 15;         // MOON ANGLES (1:MOON/EARTH/SAT IN DEG, 2:MOON/EARTH/SEN IN DEG)
     
     
  //*******************************************************************************   
  
  // INDEXES OF ANGLE ARRAY
  static const int  
     XA_ANGLE_MOONSENSAT  = 0,        //  MOON/SEN/SAT ANGLE (DEG)
     XA_ANGLE_SUNEARTHSAT = 1,        //  SUN/EARTH/SAT ANGLE (DEG)
     XA_ANGLE_SUNEARTHSEN = 2,        //  SUN/EARTH/SEN ANGLE (DEG)
     XA_ANGLE_SUNSENSAT   = 3,        //  SUN/SEN/SAT ANGLE (DEG) - SOLAR EXCLUSION ANGLE
     XA_ANGLE_SOLARASPECT = 4,        //  EARTH/SAT/SUN ANGLE (DEG) - SOLAR ASPECT ANGLE/SOLAR PHASE ANGLE
     XA_ANGLE_SIZE        = 5;
  
  // INDEXES OF MOON ANGLE ARRAY
  static const int  
     // DHN 18JAN13 - ADD MOON/EARTH/SAT, MOON/EARTH/SEN  ANGLES
     XA_ANGLE_MOONEARTHSAT = 0,       //  MOON/EARTH/SAT ANGLE (DEG)
     XA_ANGLE_MOONEARTHSEN = 1;       //  MOON/EARTH/SEN ANGLE (DEG)
  
     
  //*******************************************************************************   
  
  // INDEXES OF ORBITING SENSOR'S OFF-BORESIGHT/CLOCK  ARRAY
  static const int  
     XA_OFFBORE_EL1 = 0,              //  OFF-BORESIGHT ANGLE 1 
     XA_OFFBORE_AZ1 = 1,              //  OFF-BORESIGHT CLOCK 1
     XA_OFFBORE_EL2 = 2,              //  OFF-BORESIGHT ANGLE 2 
     XA_OFFBORE_AZ2 = 3,              //  OFF-BORESIGHT CLOCK 2
     XA_OFFBORE_SIZE= 4;
     
  //*******************************************************************************   
  
  // INDEXES OF LAMOD 1P-CARD DATA
  static const int  
     XF_1P_TIMEFRM = 1,        // INPUT TIME FORMAT: 0=MINUTES SINCE EPOCH, 1=UTC
     XF_1P_BEGTIME = 2,        // BEGIN TIME
     XF_1P_ENDTIME = 3,        // END TIME
     XF_1P_INTERVAL= 4,        // OUPUT INTERVAL
     XF_1P_PRTOPT  = 5,        // PRINT OPTIONS: 0: PRINT LOOK ANGLES, 1: PRINT LOOK ANGLE AND INITIAL CONDITIONS
     XF_1P_GENOBS  = 6,        // GENERATE OBS FROM LOOK ANGLES FLAG
     XF_1P_VISFLG  = 7,        // COMPUTE OPTICAL VISIBILITY FLAG: 0: USE SEN LIMITS,  1: OPTICALLY VISIBLE PASSES ONLY, 2: OUTPUT PASS ONLY IF SAA LESS THAN MAX SAA
     XF_1P_STEPMODE = 8,       // STEP MODE FLAG: 0= USE CULMINATION MODE, 1= USE STEP MODE, 2= USE TASK MODE
     XF_1P_PROCMODE = 9,       // PROCESSING MODE: 'O': OBSCHED MODE; 'P': P ASCHED MODE
     XF_1P_DIAGNOST = 10,      // DIAGNOSTIC MODE: 0: NONE, 1: PRINT SEN/SAT POS AT EACH LOOK, 2: PRINT PASS BY PASS DIAGNOSTICS, 3: BOTH 1 AND 2
     XF_1P_MAXSAA   = 11;      // MAX SOLAR ASPECT FOR OPTICAL SITES
     
  //*******************************************************************************  
     
  // INDEXES OF LIMIT TEST FLAGS IN THE RETURNED ARRAY 
  static const int  
     XA_LIMFLG_AZLIM    =  0,      //  AZ LIMITS TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_ELLIM    =  1,      //  EL LIMITS TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_EARTHBK  =  2,      //  EARTH IN BACKGROUND FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_EARTHOB  =  3,      //  EARTH OBSTRUCTED FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_LUNEXCL  =  4,      //  LUNAR EXCLUSION ANGLE FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_MAXRANGE =  5,      //  MAX RANGE TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_MINRANGE =  6,      //  MIN RANGE TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_PENECLIP =  7,      //  PENUMB ECLIPSE TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_RVELLIM  =  8,      //  RELATIVE VELOCITY TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_SAALIM   =  9,      //  SOLAR ASPECT ANGLE TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_SOLEXCL  = 10,      //  SOLAR EXCLUSION ANGLE FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_UMBECLIP = 11,      //  UMBRAL ECLIPSE TEST FLAG (0=FAILED, 1=PASSED)
     XA_LIMFLG_SIZE     = 12;
     
  
  // GENERATE OBS OPTIONS
  static const int  
     GENOBS_NONE      =  0,     // DON'T GENERATE OBS
     GENOBS_B3        =  1,     // GENERATE B3 OBS
     GENOBS_TTY       =  2,     // GENERATE TYY OBS
     GENOBS_SPTASKER  =  3,     // GENERATE SP TASKER V OBSTYPE
     GENOBS_CSV       =  4;     // GENERATE CSV OBS
     
  
  // INDEXES OF LOOK AND VIEW DATA IN AN ARRAY
  static const int  
     XA_LV_LOOKCODE =   0,    // LOOK CODE: 0=VALID LOOK; 1=FAIL HORIZON BREAK TEST; 2=FAIL SENSOR'S LIMIT TESTS
     XA_LV_DS50UTC  =   1,    // TIME IN DS50UTC WHEN THE LOOK ANGLE IS COMPUTED    
     XA_LV_MSE      =   2,    // TIME MSE WHEN THE LOOK ANGLE IS COMPUTED
     XA_LV_ELEV     =   3,    // ELEVATION (DEG)
     XA_LV_AZIM     =   4,    // AZIMUTH (DEG)
     XA_LV_RNG      =   5,    // RANGE (KM) 
     XA_LV_RNGRT    =   6,    // RANGE RATE (KM/S) 
     XA_LV_RA       =   7,    // RIGHT ASCENSION (DEG)
     XA_LV_DEC      =   8,    // DECLINATION (DEG)
     XA_LV_AZRATE   =   9,    // AZIMUTH RATE (DEG/S)
     XA_LV_ELRATE   =  10,    // ELEVATION RATE (DEG/S)
  
     XA_LV_SENPOSX  =  11,    // SENSOR ECI POSITION (X) (KM) 
     XA_LV_SENPOSY  =  12,    // SENSOR ECI POSITION (Y) (KM) 
     XA_LV_SENPOSZ  =  13,    // SENSOR ECI POSITION (Z) (KM) 
     XA_LV_SENVELX  =  14,    // SENSOR ECI VELOCITY (X) (KM/S)
     XA_LV_SENVELY  =  15,    // SENSOR ECI VELOCITY (Y) (KM/S)
     XA_LV_SENVELZ  =  16,    // SENSOR ECI VELOCITY (Z) (KM/S)
     XA_LV_SENLAT   =  17,    // SENSOR LATITUDE (DEG)
     XA_LV_SENLON   =  18,    // SENSOR LONGITUDE (DEG) 
     XA_LV_SENHEIGHT=  19,    // SENSOR HEIGHT (KM)
  
     XA_LV_SATPOSX  =  20,    // SATELLITE ECI POSITION (X) (KM) 
     XA_LV_SATPOSY  =  21,    // SATELLITE ECI POSITION (Y) (KM) 
     XA_LV_SATPOSZ  =  22,    // SATELLITE ECI POSITION (Z) (KM) 
     XA_LV_SATVELX  =  23,    // SATELLITE ECI VELOCITY (X) (KM/S) 
     XA_LV_SATVELY  =  24,    // SATELLITE ECI VELOCITY (Y) (KM/S) 
     XA_LV_SATVELZ  =  25,    // SATELLITE ECI VELOCITY (Z) (KM/S) 
     XA_LV_SATLAT   =  26,    // SATELLITE LATITUDE (DEG)
     XA_LV_SATLON   =  27,    // SATELLITE LONGITUDE (DEG)
     XA_LV_SATHEIGHT=  28,    // SATELLITE HEIGHT (KM)
  
     XA_LV_UVECX    =  31,    // COMPUTED U-VECTOR TO OBJECT (X)
     XA_LV_UVECY    =  32,    // COMPUTED U-VECTOR TO OBJECT (Y)
     XA_LV_UVECZ    =  33,    // COMPUTED U-VECTOR TO OBJECT (Z)
     XA_LV_RUVECX   =  34,    // SLANT RANGE UNIT VECTOR (X)- VECTOR FROM THE SENSOR TO THE SATELLITE 
     XA_LV_RUVECY   =  35,    // SLANT RANGE UNIT VECTOR (Y)- VECTOR FROM THE SENSOR TO THE SATELLITE  
     XA_LV_RUVECZ   =  36,    // SLANT RANGE UNIT VECTOR (Z)- VECTOR FROM THE SENSOR TO THE SATELLITE  
     XA_LV_LVECX    =  37,    // STATION UNIT VECTOR (X) - VECTOR DIRECTED FROM THE CENTER OF THE EARTH TO THE SENSOR
     XA_LV_LVECY    =  38,    // STATION UNIT VECTOR (Y) - VECTOR DIRECTED FROM THE CENTER OF THE EARTH TO THE SENSOR
     XA_LV_LVECZ    =  39,    // STATION UNIT VECTOR (Z) - VECTOR DIRECTED FROM THE CENTER OF THE EARTH TO THE SENSOR
     XA_LV_ZVECX    =  40,    // STATION ZENITH VECTOR (X)  
     XA_LV_ZVECY    =  41,    // STATION ZENITH VECTOR (Y)
     XA_LV_ZVECZ    =  42,    // STATION ZENITH VECTOR (Z) 
     XA_LV_RNGVECX  =  43,    // SLANT RANGE VECTOR (X) (KM) - VECTOR FROM THE SENSOR TO THE SATELLITE 
     XA_LV_RNGVECY  =  44,    // SLANT RANGE VECTOR (Y) (KM) - VECTOR FROM THE SENSOR TO THE SATELLITE 
     XA_LV_RNGVECZ  =  45,    // SLANT RANGE VECTOR (Z) (KM) - VECTOR FROM THE SENSOR TO THE SATELLITE 
     XA_LV_RRTVECX  =  46,    // RANGE-RATE VECTOR - RELATIVE VELOCITY VECTOR (X) (KM/S)
     XA_LV_RRTVECY  =  47,    // RANGE-RATE VECTOR - RELATIVE VELOCITY VECTOR (Y) (KM/S)
     XA_LV_RRTVECZ  =  48,    // RANGE-RATE VECTOR - RELATIVE VELOCITY VECTOR (Z) (KM/S)
     XA_LV_USUNX    =  49,    // UNIT VECTOR TO SUN (X)
     XA_LV_USUNY    =  50,    // UNIT VECTOR TO SUN (Y) 
     XA_LV_USUNZ    =  51,    // UNIT VECTOR TO SUN (Z) 
     XA_LV_UMOONX   =  52,    // UNIT VECTOR TO MOON (X) 
     XA_LV_UMOONY   =  53,    // UNIT VECTOR TO MOON (Y) 
     XA_LV_UMOONZ   =  54,    // UNIT VECTOR TO MOON (Z) 
     XA_LV_MOSESA   =  55,    // MOON/SENSOR/SATELLITE ANGLE (DEG)    
     XA_LV_MOEASA   =  56,    // MOON/EARTH/SATELLITE ANGLE (DEG)     
     XA_LV_MOEASE   =  57,    // MOON/EARTH/SENSOR ANGLE (DEG)     
     XA_LV_SUSESA   =  58,    // SUN/SENSOR/SATELLITE ANGLE (DEG)   
     XA_LV_SUEASA   =  59,    // SUN/EARTH/SATELLITE ANGLE (DEG) 
     XA_LV_SUEASE   =  60,    // SUN/EARTH/SENSOR ANGLE (DEG)  
     XA_LV_SOLAA    =  61,    // SOLAR ASPECT ANGLE (DEG)
     XA_LV_VIS      =  62,    // ILLUMINATION RESULT
     XA_LV_RELVEL   =  63,    // RELATIVE VELOCITY (KM/S)
  
     XA_LV_AZLIM    =  70,    // PASS AZIMUTH CHECK (0=FAILED, 1=PASSED)
     XA_LV_ELLIM    =  71,    // PASS ELEVATION CHECK (0=FAILED, 1=PASSED) 
     XA_LV_EARTHBK  =  72,    // PASS EARTH IN BACKGROUND CHECK (0=FAILED, 1=PASSED) 
     XA_LV_EARTHOB  =  73,    // PASS EARTH OBSTRUCTION CHECK (0=FAILED, 1=PASSED) 
     XA_LV_LUNEXCL  =  74,    // PASS LUNAR EXCLUSION CHECK (0=FAILED, 1=PASSED)
     XA_LV_MAXRANGE =  75,    // PASS MAXIMUM RANGE CHECK (0=FAILED, 1=PASSED)
     XA_LV_MINRANGE =  76,    // PASS MINIMUM RANGE CHECK (0=FAILED, 1=PASSED)
     XA_LV_PENECLIP =  77,    // PASS PENUM ECLIPSE CHECK (0=FAILED, 1=PASSED)
     XA_LV_RVELLIM  =  78,    // PASS RELATIVE VELOCITY CHECK (0=FAILED, 1=PASSED)
     XA_LV_SAALIM   =  79,    // PASS SOLAR ASPECT ANGLE CHECK (0=FAILED, 1=PASSED)
     XA_LV_SOLEXCL  =  80,    // PASS SOLAR EXCLUSION ANGLE CHECK (0=FAILED, 1=PASSED)
     XA_LV_UMBECLIP =  81,    // PASS UMBRAL ECLIPSE CHECK (0=FAILED, 1=PASSED)
     XA_LV_OPTVIS   =  82,    // PASS VISIBILITY CHECK FOR OPTICAL SENSOR (0=FAILED, 1=PASSED)
  
     XA_LV_SENPOSE  =  90,    // ORBITING SENSOR EFG POSITION (X) (KM)
     XA_LV_SENPOSF  =  91,    // ORBITING SENSOR EFG POSITION (Y) (KM)
     XA_LV_SENPOSG  =  92,    // ORBITING SENSOR EFG POSITION (Z) (KM)
     XA_LV_NBORE1   =  93,    // ORBITING SENSOR BORESIGHT VECTOR #1 (1='D', 2='U', 3='B', 4='A', 5='R', 6='L', 7=NO LIMITS)
     XA_LV_NBORE2   =  94,    // ORBITING SENSOR BORESIGHT VECTOR #2 (1='D', 2='U', 3='B', 4='A', 5='R', 6='L', 7=NO LIMITS)
     XA_LV_OBEL1    =  95,    // ORBITING SENSOR OFF BORESIGHT ELEVATION #1 (DEG)
     XA_LV_OBAZ1    =  96,    // ORBITING SENSOR OFF BORESIGHT AZIMUTH #1 (DEG)
     XA_LV_OBAZ2    =  97,    // ORBITING SENSOR OFF BORESIGHT ELEVATION #2 (DEG)
     XA_LV_OBEL2    =  98,    // ORBITING SENSOR OFF BORESIGHT AZIMUTH #2 (DEG)
  
     XA_LV_SIZE     = 128;
  
  
  // INDEXES OF SENSOR/SATELLITE DATA IN AN ARRAY
  static const int  
     XA_SENSAT_SENNUM     =  0,       // SENSOR NUMBER
     XA_SENSAT_SATNUM     =  1,       // SATELLITE NUMBER
     XA_SENSAT_VIEWTYPE   =  2,       // SENSOR VIEW TYPE
     XA_SENSAT_OBSTYPE    =  3,       // SENSOR OBSERVATION TYPE
     XA_SENSAT_PTSPERPAS  =  4,       // MAX NUMBER OF POINTS PER PASS
     XA_SENSAT_STEPMODE   =  5,       // STEP MODE FLAG: 0= USE CULMINATION MODE, 1= USE STEP MODE, 2= USE TASK MODE
     XA_SENSAT_VISPASSONLY=  6,       // VISUAL PASS ONLY
     XA_SENSAT_STARTAI    =  7,       // START TIME IN DS50TAI
     XA_SENSAT_STOPTAI    =  8,       // STOP TIME IN DS50TAI
     XA_SENSAT_INTERVAL   =  9,       // OUTPUT INTERVAL (MIN)
     XA_SENSAT_PERIOD     = 10,       // SATELLITE'S PERIOD (MIN)
  
     XA_SENSAT_SIZE       = 32;        
  
  
  // LAMOD CONTROL PARAMETERS IN INPUT ARRAY XA_LA_PARMS THAT IS USED IN LAMODINITSENSAT_MT()
  static const int  
     XA_LA_PARMS_TIMEFLG     =  1,   // INPUT FORMAT FOR BEGIN AND END TIMES (0: MINUTES SINCE EPOCH, 1: DAYS SINCE 1950 UTC)
     XA_LA_PARMS_STARTTIME   =  2,   // BEGIN TIME
     XA_LA_PARMS_STOPTIME    =  3,   // END TIME
     XA_LA_PARMS_STEPMODE    =  4,   // STEP MODE FLAG: 0= USE CULMINATION MODE, 1= USE STEP MODE, 2= USE TASK MODE
     XA_LA_PARMS_VISFLG      =  5,   // OPTICAL VISIBILITY FLAG:	0=ACCEPT ALL PASSES, 1=ACCEPT OPTICALLY VISUAL PASS ONLY, 2=SAME AS 1 W/ SAA RESTRICTIONS, 3=FOR IR SENSORS, 9=USE LIMITS RECORD
     XA_LA_PARMS_XMSAA       =  6,   // MAX SOLAR ASPECT ANGLE (DEG) FOR OPTICAL SITES
     
     XA_LA_PARMS_SIZE        = 16;
  
        
// LamodDll's function pointers declaration
extern fnPtrLamodInit                      LamodInit;
extern fnPtrLamodGetInfo                   LamodGetInfo;
extern fnPtrLamodLoadFile                  LamodLoadFile;
extern fnPtrLamodLoadFileAll               LamodLoadFileAll;
extern fnPtrLamodLoadCard                  LamodLoadCard;
extern fnPtrLamodSaveFile                  LamodSaveFile;
extern fnPtrLamodGetNumOfSensSats          LamodGetNumOfSensSats;
extern fnPtrLamodGetSenNums                LamodGetSenNums;
extern fnPtrLamodGetSatNums                LamodGetSatNums;
extern fnPtrLamodGet1pCard                 LamodGet1pCard;
extern fnPtrLamodGet1pAll                  LamodGet1pAll;
extern fnPtrLamodSet1pAll                  LamodSet1pAll;
extern fnPtrLamodGet1pField                LamodGet1pField;
extern fnPtrLamodSet1pField                LamodSet1pField;
extern fnPtrLamodGet3pAll                  LamodGet3pAll;
extern fnPtrLamodSet3pAll                  LamodSet3pAll;
extern fnPtrLamodGetObsFileName            LamodGetObsFileName;
extern fnPtrLamodSetObsFileName            LamodSetObsFileName;
extern fnPtrLamodSenSatVisible             LamodSenSatVisible;
extern fnPtrLamodInitSenSat                LamodInitSenSat;
extern fnPtrLamodInitSenSat_MT             LamodInitSenSat_MT;
extern fnPtrLamodGetSenSatDataAll          LamodGetSenSatDataAll;
extern fnPtrLamodGetSenSatDataField        LamodGetSenSatDataField;
extern fnPtrLamodSenSatDataToArray         LamodSenSatDataToArray;
extern fnPtrLamodGetNumPasses              LamodGetNumPasses;
extern fnPtrLamodGetRiseCulmSetTimes       LamodGetRiseCulmSetTimes;
extern fnPtrLamodComputeLookAngle          LamodComputeLookAngle;
extern fnPtrLamodComputeLookView           LamodComputeLookView;
extern fnPtrLamodFindExactIOTime           LamodFindExactIOTime;
extern fnPtrLamodGetOrbSenViewdata         LamodGetOrbSenViewdata;
extern fnPtrLamodGetViewDataField          LamodGetViewDataField;
extern fnPtrLamodCompRaDec                 LamodCompRaDec;
extern fnPtrLamodGenObs                    LamodGenObs;
extern fnPtrLamodGenObsAtTime              LamodGenObsAtTime;
extern fnPtrLamodRemoveSenSat              LamodRemoveSenSat;
extern fnPtrLamodRemoveAllSenSats          LamodRemoveAllSenSats;
extern fnPtrLamodReset                     LamodReset;



void LoadLamodDll();
void FreeLamodDll();




#endif
// ========================= End of auto generated code ==========================
