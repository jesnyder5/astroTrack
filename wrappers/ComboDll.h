// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef COMBODLL_H
#define COMBODLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define ComboDll "Combo.dll"
#elif __APPLE__
  #define ComboDll "libcombo.dylib"
#else
  #define ComboDll "libcombo.so"
#endif


// Initializes Combo dll for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. The error occurs if the users forget to load and initialize all the prerequisite DLLs, as listed in the DLL Prerequisite section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if the Combo dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboInit)(__int64 apPtr);


// Returns information about the current version of Combo.dll. The information is placed in the string parameter you pass in
// The returned string provides information about the version number, build date, and the platform of the Combo DLL. 
// infoStr            A string to hold the information about Combo.dll (out-Character[128])
typedef void (STDCALL *fnPtrComboGetInfo)(char infoStr[128]);


// Loads Combo-related parameters (7P/8P/9P cards, and Combo parameter free format) from a text file
// comboInputFile     The name of the file containing Combo-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboLoadFile)(char comboInputFile[512]);


// Loads Combo control parameters and all Combo related data (environment, time, elsets) from an input text file
// comboInputFile     The name of the file containing Combo control parameters and all Combo related data (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboLoadFileAll)(char comboInputFile[512]);


// Loads a single Combo-typed card (7P, 8P, and 9P)
// card               Combo-type input card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboLoadCard)(char card[512]);


// Saves any currently loaded COMBO-related settings to a file
// The purpose of this function is to save the current Combo-related settings, usually used in GUI applications, for future use.
// comboFile          The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrComboSaveFile)(char comboFile[512], int saveMode, int saveForm);


// Returns the number of primary and secondary satellites that were entered via 7P-card, 8P-card, 9P-card, or Combo parameter free format 
// numPriSats         The number of primary satellites that were entered via 7P/9P cards or Combo parameter free format (out-Integer)
// numSecSats         The number of secondary satellites that were entered via 7P/8P cards or Combo parameter free format (out-Integer)
typedef void (STDCALL *fnPtrComboGetNumOfPriSecSats)(int* numPriSats, int* numSecSats);


// Returns an array of primary satellite numbers that were entered via 7P-card, 9P-card, or Combo parameter free format
// priSatNums         An array to hold the primary satellite numbers (out-Integer[*])
typedef void (STDCALL *fnPtrComboGetPriSatNums)(int priSatNums[]);


// Returns an array of secondary satellite numbers that were entered via 7P-card, 8P-card, or Combo parameter free format
// secSatNums         An array to hold the secondary satellite numbers (out-Integer[*])
typedef void (STDCALL *fnPtrComboGetSecSatNums)(int secSatNums[]);


// Constructs Combo 7P-Card from COMBO control parameters
// combo7pCard        A string to hold the resulting Combo Parameter Card (7P-Card) (out-Character[512])
typedef void (STDCALL *fnPtrComboGet7pCard)(char combo7pCard[512]);


// Retrieves all Combo control parameters with a single function call
// timeFlg            Input time format:	0 = Input time is in minutes since epoch (MSE),	1 = Input time is in days since 1950, UTC (ds50UTC) (out-Integer)
// startTime          Begin time in ds50UTC or MSE, depending on timeFlg (out-Double)
// stopTime           End time  in ds50UTC or MSE, depending on timeFlg (out-Double)
// relMinFlg          Control for computing relative minima: 0 = Do not compute relative minima, 1 = Compute relative minima (out-Integer)
// absMinFlg          Control for computing absolute minimum:	0 = Do not compute absolute minimum, 1 = Compute absolute minimum (out-Integer)
// closeProxFlg       Control for computing periods of close proximity: 0 = Do not compute periods of close proximity, 1 = Compute periods of close proximity (out-Integer)
// relEphFlg          Control for computing relative ephemeris: 0 = Do not compute relative ephemeris, 1 = Compute relative ephemeris (out-Integer)
// pocSigma           Probability of collision sigma (out-Double)
// relMinLim          Maximum separation for relative minima (km) (out-Double)
// closeProxLim       Close proximity limit (out-Double)
// relEphInterval     Relative ephemeris sampling interval (min) (out-Double)
// prtOpt             Print options:	0 = Relative geometry only, 1 = Position/velocity (plus option 0), 2 = Lat, lon, height (plus option 1), 3 = Relative position (plus option 2), 4 = No output (out-Integer)
typedef void (STDCALL *fnPtrComboGet7pAll)(int* timeFlg, double* startTime, double* stopTime, int* relMinFlg, int* absMinFlg, int* closeProxFlg, int* relEphFlg, double* pocSigma, double* relMinLim, double* closeProxLim, double* relEphInterval, int* prtOpt);


// Sets all Combo control parameters with a single function call
// timeFlg            Input time format:	0 = Input time is in minutes since epoch (MSE),	1 = Input time is in days since 1950, UTC (ds50UTC) (in-Integer)
// startTime          Begin time in ds50UTC or MSE, depending on timeFlg (in-Double)
// stopTime           End time  in ds50UTC or MSE, depending on timeFlg (in-Double)
// relMinFlg          Control for computing relative minima: 0 = Do not compute relative minima, 1 = Compute relative minima (in-Integer)
// absMinFlg          Control for computing absolute minimum:	0 = Do not compute absolute minimum, 1 = Compute absolute minimum (in-Integer)
// closeProxFlg       Control for computing periods of close proximity: 0 = Do not compute periods of close proximity, 1 = Compute periods of close proximity (in-Integer)
// relEphFlg          Control for computing relative ephemeris: 0 = Do not compute relative ephemeris, 1 = Compute relative ephemeris (in-Integer)
// pocSigma           Probability of collision sigma (in-Double)
// relMinLim          Maximum separation for relative minima (km) (in-Double)
// closeProxLim       Close proximity limit (in-Double)
// relEphInterval     Relative ephemeris sampling interval (min) (in-Double)
// prtOpt             Print options:	0 = Relative geometry only, 1 = Position/velocity (plus option 0), 2 = Lat, lon, height (plus option 1), 3 = Relative position (plus option 2), 4 = No output (in-Integer)
typedef void (STDCALL *fnPtrComboSet7pAll)(int timeFlg, double startTime, double stopTime, int relMinFlg, int absMinFlg, int closeProxFlg, int relEphFlg, double pocSigma, double relMinLim, double closeProxLim, double relEphInterval, int prtOpt);


// Retrieves the value of a single Combo control parameter (7P-card)
// 
// Remember to convert retVal to the correct data type that it represents.
// 
// The 7P field index values for the parameter xf_7P are described in the table below.
// 
// 
// Value
// Value interpretation
// 
// 1 Input time format : 0: Minutes since epoch, 1: UTC
// 2 Begin time
// 3 End time
// 4 Control flag for computing relative minima
// 5 Control flag for computing absolute minimum
// 6 Control flag for computing periods of close proximity
// 7 Control flag for computing relative ephemeris
// 8 Control flag for computing probability of collision
// 9 Maximum separation for relative minima
// 10Close proximity limit
// 11Relative ephemeris sampling interval 
// 12Print options
// 13Primary satellite effective radius (m)
// 14Secondary satellite effective radius (m)
// 
// xf_7P              Predefined number specifying which Combo control parameter to retrieve, see XF_7P_? for field specification (in-Integer)
// retVal             A string to hold the value of the requested COMBO control parameter (out-Character[512])
typedef void (STDCALL *fnPtrComboGet7pField)(int xf_7P, char retVal[512]);


// Sets the value of a single Combo control parameter (7P-card)
// See ComboGet7pField for a list of index values for the parameter xf_7P.
// xf_7P              Predefined number specifying which Combo control parameter to set, see XF_7P_? for field specification (in-Integer)
// valueStr           the new value of the specified COMBO control parameter, expressed as a string (in-Character[512])
typedef void (STDCALL *fnPtrComboSet7pField)(int xf_7P, char valueStr[512]);


// Returns computation of miss between orbits (COMBO) data for the specified primary and secondary satellites
// 
// If absMinDs50UTC = 0 or absMinDist = 1.0E20, this means no absolute minimum found. Otherwise, the absMinDs50UTC and absMinDist are returned whether or not absMinDist is greater than the specified "Close proximity limit".
// 
// Returns zero indicating the COMBO data was computed successfully. Other values indicate an error. Here is the list of possible error/warning code it returns:
// 
// 
// Value
// Value Interpretation
// 
// 101 Primary satellite's epoch too far from the time span
// 102 Secondary satellite's epoch too far from the time span
// 103 Primary/secondary satellites are identical
// 104 Secondary satellite failed perigee/apogee test
// 105 Secondary satellite is considered a brief span
// 106 Secondary satellite is in sustained relative geometry
// 
// 
// When the function's returned value is 108 (secondary satellite is in sustained relative geometry), the entry/exit times should be ignored.
// priSatKey          The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// absMinDs50UTC      Time (in days since 1950, UTC) when the primary and secondary satellites are in closest approach (absolute minimum) (out-Double)
// absMinDist         Absolute minimum distance (km) between primary and secondary satellites obtained at the time absMinDs50UTC (out-Double)
// relMinDs50UTCs     Times (in days since 1950, UTC) when  the primary and secondary satellites are at relative minima (out-Double[1000])
// numOfRelMins       Number of relative minima found during the requested time span (out-Integer)
// entryDs50UTCs      Times (in days since 1950, UTC) when the primary and secondary satellites approach the distance as specified in the "Maximum separation for relative minima" (out-Double[1000])
// exitDs50UTCs       Times (in days since 1950, UTC) when the primary and secondary satellites leave the distance as specified in the "Maximum separation for relative minima" (out-Double[1000])
// numOfEntryExits    Number of times when the primary and secondary satellites enter and exit the "Maximum separation for relative minima" (out-Integer)
// returns 0 if the COMBO data was computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboCompPriSec)(__int64 priSatKey, __int64 secSatKey, double* absMinDs50UTC, double* absMinDist, double relMinDs50UTCs[1000], int* numOfRelMins, double entryDs50UTCs[1000], double exitDs50UTCs[1000], int* numOfEntryExits);


// Returns computation of miss between orbits (COMBO) data for the specified primary and secondary satellites
// This function is similar to ComboCompPriSec but allows the user to enter separate COMBO parameters for each call which is suitable for multithread application
// xa_cb_parms        Combo control parameters - see XA_CB_PARMS_? for array arrangement (in-Double[16])
// priSatKey          The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// absMinDs50UTC      Time (in days since 1950, UTC) when the primary and secondary satellites are in closest approach (absolute minimum) (out-Double)
// absMinDist         Absolute minimum distance (km) between primary and secondary satellites obtained at the time absMinDs50UTC (out-Double)
// relMinDs50UTCs     Times (in days since 1950, UTC) when  the primary and secondary satellites are at relative minima (out-Double[1000])
// numOfRelMins       Number of relative minima found during the requested time span (out-Integer)
// entryDs50UTCs      Times (in days since 1950, UTC) when the primary and secondary satellites approach the distance as specified in the "Maximum separation for relative minima" (out-Double[1000])
// exitDs50UTCs       Times (in days since 1950, UTC) when the primary and secondary satellites leave the distance as specified in the "Maximum separation for relative minima" (out-Double[1000])
// numOfEntryExits    Number of times when the primary and secondary satellites enter and exit the "Maximum separation for relative minima" (out-Integer)
// returns 0 if the COMBO data was computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboCompPriSec_MT)(double xa_cb_parms[16], __int64 priSatKey, __int64 secSatKey, double* absMinDs50UTC, double* absMinDist, double relMinDs50UTCs[1000], int* numOfRelMins, double entryDs50UTCs[1000], double exitDs50UTCs[1000], int* numOfEntryExits);


// Computes probability of collision between a primary and secondary satellite
// priSatPos          The primary satellite's ECI position vector (km) (in-Double[3])
// priSatVel          The primary satellite's ECI velocity vector (km/s) (in-Double[3])
// priSatCov          The primary satellite's 3x3 covariance matrix (in-Double[3, 3])
// priSatRad          The primary satellite's effective radius (m) (in-Double)
// secSatPos          The secondary satellite's ECI position vector (km) (in-Double[3])
// secSatVel          The secondary satellite's ECI velocity vector (km/s) (in-Double[3])
// secSatCov          The secondary satellite's 3x3 covariance matrix (in-Double[3, 3])
// secSatRad          The secondary satellite's effective radius (m) (in-Double)
// xf_CovType         Input covariance type: 1 = ECI, 2 = UVW (in-Integer)
// pocArr             The resulting probability of collision:	1=Normalized distance (n-sigma) to circumscribing square, 2=POC of square, 3=Normalized distance (n-sigma) to circle, 4=POC of circle (out-Double[4])
// returns 0 if the probability of collision is computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboPOC)(double priSatPos[3], double priSatVel[3], double priSatCov[3][3], double priSatRad, double secSatPos[3], double secSatVel[3], double secSatCov[3][3], double secSatRad, int xf_CovType, double pocArr[4]);


// Computes probability of collision using data from a CSM/OCM file
// csmFile            ocm or csm file (in-Character[512])
// sumR               hard-body radius (R1 + R2) (m), if not zero, overwrite values in csm's (in-Double)
// pocArr             The resulting probability of collision:	1=Normalized distance (n-sigma) to circumscribing square, 2=POC of square, 3=Normalized distance (n-sigma) to circle, 4=POC of circle (out-Double[4])
// returns 0 if the POC was computed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrComboCSMPOC)(char csmFile[512], double sumR, double pocArr[4]);
  
  // INDEXES OF LAMOD 7P-CARD FIELDS
  static const int  
     XF_7P_TIMEFLAG    = 1,       // INPUT TIME FORMAT : 0: MINUTES SINCE EPOCH, 1: UTC
     XF_7P_BEGTIME     = 2,       // BEGIN TIME
     XF_7P_ENDTIME     = 3,       // END TIME
     XF_7P_RELMINFLG   = 4,       // CONTROL FLAG FOR COMPUTING RELATIVE MINIMA
     XF_7P_ABSMINFLG   = 5,       // CONTROL FLAG FOR COMPUTING ABSOLUTE MINIMUM
     XF_7P_EETIMES     = 6,       // CONTROL FLAG FOR COMPUTING PERIODS OF CLOSE PROXIMITY
     XF_7P_RELEPHFLG   = 7,       // CONTROL FLAG FOR COMPUTING RELATIVE EPHEMERIS
     XF_7P_POCSIGMA    = 8,       // CONTROL FLAG FOR COMPUTING PROBABILITY OF COLLISION
     XF_7P_RELMINLIM   = 9,       // MAXIMUM SEPARATION FOR RELATIVE MINIMA
     XF_7P_ABSMINLIM   = 10,      // CLOSE PROXIMITY LIMIT
     XF_7P_RELEPHINT   = 11,      // RELATIVE EPHEMERIS SAMPLING INTERVAL 
     XF_7P_PRTOPT      = 12,      // PRINT OPTIONS
     XF_7P_PRADIUS     = 13,      // PRIMARY SATELLITE EFFECTIVE RADIUS (M)
     XF_7P_SRADIUS     = 14;      // SECONDARY SATELLITE EFFECTIVE RADIUS (M)
     
  // DIFFERENT INPUT OF COVARIANCE MATRIX TO COMPUTE POC   
  static const int  
     XF_COVTYPE_ECI   = 1,        // ECI POS, VEL, AND ECI COVARIANCE
     XF_COVTYPE_UVW   = 2;        // EFG POS, VEL, AND UVW COVARIANCE
  
  
  
  // COMBO CONTROL PARAMETERS IN INPUT ARRAY XA_CB_PARMS THAT IS USED IN COMBOCOMPPRISEC_MT()
  static const int  
     XA_CB_PARMS_TIMEFLG     =  1,       // INPUT FORMAT FOR BEGIN AND END TIMES (0: MINUTES SINCE EPOCH, 1: DAYS SINCE 1950 UTC)
     XA_CB_PARMS_STARTTIME   =  2,       // BEGIN TIME
     XA_CB_PARMS_STOPTIME    =  3,       // END TIME
     XA_CB_PARMS_MAXSEP      =  4,       // MAXIMUM SEPARATION FOR RELATIVE MINIMA (KM) - FOR REPORTING TIMES WHEN RELATIVE MINIMA IS LESS THAN THIS SPECIFIED VALUE
     XA_CB_PARMS_PROXLIM     =  5,       // CLOSE PROXIMITY LIMIT (KM) - FOR REPORTING ENTRY/EXIT TIMES WHEN PRI/SEC SEPARATION DISTANCE EQUALS THIS SPECIFIED VALUE   
     XA_CB_PARMS_SIZE        = 16;
  
  // CONSTANTS REPRESENT COMBO FAILED CASES
  static const int  
     FAILED_PRITOOFAR = 101,       // PRIMARY SATELLITE'S EPOCH TOO FAR FROM TIME SPAN
     FAILED_SECTOOFAR = 102,       // SECONDARY SATELLITE'S EPOCH TOO FAR FROM TIME SPAN
     FAILED_SAMESAT   = 103,       // PRIMARY/SECONDARY SATELLITES ARE IDENTICAL  
     FAILED_ALTITUDE  = 104,       // SECONDARY SATELLITE FAILED PERIGEE/APOGEE TEST 
     WARN_BRIEFSPAN   = 105,       // SECONDARY SATELLITE IS CONSIDERED A BRIEF SPAN
     WARN_SUSRELGEO   = 106;       // SECONDARY SATELLITE IS IN SUSTAINED RELATIVE GEOMETRY
  
// ComboDll's function pointers declaration
extern fnPtrComboInit                      ComboInit;
extern fnPtrComboGetInfo                   ComboGetInfo;
extern fnPtrComboLoadFile                  ComboLoadFile;
extern fnPtrComboLoadFileAll               ComboLoadFileAll;
extern fnPtrComboLoadCard                  ComboLoadCard;
extern fnPtrComboSaveFile                  ComboSaveFile;
extern fnPtrComboGetNumOfPriSecSats        ComboGetNumOfPriSecSats;
extern fnPtrComboGetPriSatNums             ComboGetPriSatNums;
extern fnPtrComboGetSecSatNums             ComboGetSecSatNums;
extern fnPtrComboGet7pCard                 ComboGet7pCard;
extern fnPtrComboGet7pAll                  ComboGet7pAll;
extern fnPtrComboSet7pAll                  ComboSet7pAll;
extern fnPtrComboGet7pField                ComboGet7pField;
extern fnPtrComboSet7pField                ComboSet7pField;
extern fnPtrComboCompPriSec                ComboCompPriSec;
extern fnPtrComboCompPriSec_MT             ComboCompPriSec_MT;
extern fnPtrComboPOC                       ComboPOC;
extern fnPtrComboCSMPOC                    ComboCSMPOC;



void LoadComboDll();
void FreeComboDll();




#endif
// ========================= End of auto generated code ==========================
