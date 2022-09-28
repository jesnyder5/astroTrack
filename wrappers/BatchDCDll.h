// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef BATCHDCDLL_H
#define BATCHDCDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define BatchDCDll "BatchDC.dll"
#elif __APPLE__
  #define BatchDCDll "libbatchdc.dylib"
#else
  #define BatchDCDll "libbatchdc.so"
#endif


// Initializes BatchDC DLL for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if BatchDC.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCInit)(__int64 apPtr);


// Returns information about the current version of BatchDC DLL. 
// The information is placed in the string parameter passed in.
// infoStr            A string to hold the information about BatchDC.dll (out-Character[128])
typedef void (STDCALL *fnPtrBatchDCGetInfo)(char infoStr[128]);


// Read/Load BatchDC input data from an input file
// batchDCInputFile   The name of the file containing BatchDC-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCLoadFile)(char batchDCInputFile[512]);


// Loads BatchDC control parameters and all BatchDC related data (environment, time, elsets, sensors) from an input text file
// batchDCInputFile   The name of the file containing BatchDC and BatchDC-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCLoadFileAll)(char batchDCInputFile[512]);


// Read/Load BatchDC-typed input data from an input card
// card               BatchDC-type input card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCLoadCard)(char card[512]);


// Builds and returns the DC parameter card (1P-Card) from the current DC settings
// dcPCard            the resulting DC 1P-Card (out-Character[512])
typedef void (STDCALL *fnPtrBatchDCGetPCard)(char dcPCard[512]);


// Saves any currently loaded BatchDC-related settings to a file
// batchDCFile        The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCSaveFile)(char batchDCFile[512], int saveMode, int saveForm);


// Gets BatchDC parameter data (P Card) - all fields
// 
// The table below shows the structure of the integer array xai_ctrl:
// 
//     
//         Index
//         Index Interpretation
//     
//     0DC print option
//     1Apply biases from sensor file
//     2Weighed DC flag
//     3Epoch placement control
//     4Element correction flag - Ag
//     5Element correction flag - Af
//     6Element correction flag - Psi
//     7Element correction flag - Chi
//     8Element correction flag - L
//     9Element correction flag - N
//     10Element correction flag - B* (SGP4) B (SP)
//     11Element correction flag - Agom (SP)
//     12Correction order
//     13Correct by the specified correction order for 1 iteration only
//     14Flag specifies which residuals are used for RMS calculation and convergence
//     15Flag; if set, produce sensor performance analysis summary
//     16Flag; if set, deweight according to # of obs per track
//     17Iteration summary control
//     18Partials method
//     19Light time correction control
//     20Number of iteration to allow no auto rejection of residuals
//     21Propagation method
//     22Flag; if set, correct B* vs X
//     23Max # of iterations before declaring divergence
//     24Use predicted RMS versus previous RMS for convergence testing
// 
// 
// The table below shows the structure of the real array xar_ctrl:
// 
//     
//         Index
//         Index Interpretation
//     
//     0RMS multiplier
//     1Time of specified epoch
//     2Convergence criteria on time correction (%)
//     3First pass delta-t rejection criteria
//     4Convergence criteria on 7-elt correction (%)
//     5Reset value for B term in subset correction
// 
// xai_ctrl           Array contains integer BatchDC parameters (out-Integer[256])
// xar_ctrl           Array contains double BatchDC parameters (out-Double[256])
// xas_ctrl           BatchDC parameters in character string format - not yet used (out-Character[512])
typedef void (STDCALL *fnPtrBatchDCGetParams)(int xai_ctrl[256], double xar_ctrl[256], char xas_ctrl[512]);


// Sets BatchDC parameter data (P Card) - all fields
// See BatchDCGetParams for the structure of the xai_ctrl and xar_ctrl arrays.
// xai_ctrl           Array contains integer BatchDC parameters (in-Integer[256])
// xar_ctrl           Array contains double BatchDC parameters (in-Double[256])
// xas_ctrl           BatchDC parameters in character string format - not yet used (in-Character[512])
typedef void (STDCALL *fnPtrBatchDCSetParams)(int xai_ctrl[256], double xar_ctrl[256], char xas_ctrl[512]);


// Initializes DC parameters for the satellite
// See BatchDCGetParams for the structure of the xai_dcElts and xar_dcElts arrays.
// satKey             The satellite's unique key (in-Long)
// numObs             Actual number of obs being selected to be used in the DC (out-Integer)
// obsKeys            The array in which to store the obsKeys (out-Long[*])
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data - not yet used (out-Character[512])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCInitSat)(__int64 satKey, int* numObs, __int64 obsKeys[], int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);


// Performs batch-least-square differential corrections to the specified satellite and
// return the corrected elements and related data - using all loaded obs
// 
// Note: The input satellite must be intialized by calling BatchDCInitSat() prior to calling this routine
// 
// See BatchDCGetParams for the structure of the xai_dcElts array.
// 
// The table below shows the structure of the integer array xar_dcElts:
// 
//     
//         Index
//         Index Interpretation
//     
//     0elset's epoch time in days since 1950 UTC
//     1n-dot/2  (for SGP, eph-type = 0)
//     2n-double-dot/6  (for SGP, eph-type = 0)
//     3either SGP4 bStar (1/er) or SP bTerm (m2/kg)
//     4SP agom (m**2/kg)
//     5SP outgassing parameter (km/s**2)
//     6semi major axis (km)
//     7eccentricity
//     8inclination (deg)
//     9mean anamoly (deg)
//     10right ascension of the ascending node (deg)
//     11argument of perigee (deg)
//     12AF
//     13AG
//     14CHI
//     15PSI
//     16mean longitude (deg)
//     17mean motion (revs/day)
//     18ECI posX (km)
//     19ECI posY (km)
//     20ECI posZ (km)
//     21ECI velX (km/s)
//     22ECI velY (km/s)
//     23ECI velZ (km/s)
//     
//     40RMS (km)
//     41unweighted RMS (km)
//     42delta T RMS (min)
//     43beta RMS (deg)
//     44delta height RMS (km)
//     45convergence value (km)
//     46predicted RMS (km)
//     
//     60covariance diagonal L
//     61covariance diagonal N
//     62covariance diagonal CHI
//     63covariance diagonal PSI
//     64covariance diagonal AF
//     65covariance diagonal AG
//     66covariance diagonal BTERM
//     67covariance not used
//     68covariance diagonal AGOM
//     
//     200-244equinoctial covariance matrix - the lower triangular half 200-244
// 
// satKey             The satellite's unique key (in-Long)
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data  - not yet used (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrBatchDCSolve)(__int64 satKey, int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);


// Performs batch-least-square differential corrections to the specified satellite and
// return the corrected elements and related data - using only the provided obsKeys (not all loaded obs)
// Note: The input satellite must be intialized by calling BatchDCInitSat() prior to calling this routine
// See BatchDCGetParams for the structure of the xai_dcElts array.
// See BatchDCSolve for the structure of the xar_dcElts array.
// satKey             The satellite's unique key (in-Long)
// obsKeys            The array of obs keys that wil be used in the DC (in-Long[*])
// numObs             The size of the obsKeys array (in-Integer)
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data  - not yet used (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrBatchDCSolveSelObs)(__int64 satKey, __int64 obsKeys[], int numObs, int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);


// Removes a satellite, represented by the satKey, from BatchDC's memory
// satKey             The unique key of the satellite to be removed (in-Long)
// returns 0 if the satellite is removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCRemoveSat)(__int64 satKey);


// Iterates DC for the satellite
// 
// obsResArr size is [numObs, 100].  obsRejFlags size is [numObs, 32].
// 
// The table below shows the values contained in obsResArr for each ob:
// 
//     
//         Index
//         Index Interpretation
//     
//      0  Azimuth residual (deg)
//      1  Elevation residual (deg)
//      2  Range residual (km)
//      3  Height residual (deg)
//      4  Beta residual (deg)
//      5  Delta T residual (min)
//      6  Vector magnitude (km)
//      7  Time since epoch (days)
//      8  True argument of latitude (deg)
//      9  Revolution number  
//     10  Range rate residual (km/sec)
//     11  observation ASTAT
//     12  observation type
//     13  satellite true anomaly (deg)
//     14  satellite elevation (deg)
//     15  satellite maintenance category
//     16  obs time in ds50UTC
//     17  obs azimuth (deg)
//     18  obs elevation (deg)
//     19  Velocity angle residual (deg)
//     20  Angular momentum residual (deg)
//     21  Right ascension residual (deg) (for ob types 5, 9, 19)
//     22  Declination residual (deg) (for ob types 5, 9, 19)
//     23  Delta X position (km)
//     24  Delta Y position (km)
//     25  Delta Z position (km)
//     26  Delta X velocity (km/sec)
//     27  Delta Y velocity (km/sec)
//     28  Delta Z velocity (km/sec)
//     29  Angle only obs computed range (km)
//     30  obs azimuth (deg)
//     31  obs elevation (deg)
// 
// 
// See BatchDCGetParams for the structure of the xai_dcElts array.
// 
// See BatchDCSolve for the structure of the xar_dcElts array.
// satKey             The satellite's unique key (in-Long)
// obsResArr          Obs residual array (out-Double[*, 100])
// obsRejFlags        Obs rejection flag array (out-Integer[*, 32])
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data  - not yet used (out-Character[512])
// returns iterating code: 0=successful, 1=has error, 2=iterating, 3=diverged\try to recover
typedef int (STDCALL *fnPtrBatchDCIterate)(__int64 satKey, double obsResArr[][100], int obsRejFlags[][32], int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);


// Returns a concatenated string representation of a VCM generated by a successful DC
// satKey             The satellite's unique key (in-Long)
// vcmLines           The resulting concatenated string representation of the VCM, (out-Character[4000])
// returns 0 if successful, non-0 on error
typedef int (STDCALL *fnPtrBatchDCGetVcm)(__int64 satKey, char vcmLines[4000]);


// Returns the full file name of the output SP Vector file that was specified using "SPVOUT = " 
// in the main input file or using the BatchDCSetSpVOutFileName() function call
// spVOutFile         The output file that stores SP output message (out-Character[512])
typedef void (STDCALL *fnPtrBatchDCGetSpVOut)(char spVOutFile[512]);


// Sets the full file name of the SP Vector output file which will be used to store the generated SP vector data
// spVOutFile         The output file that stores SP vector output (VCM message) (in-Character[512])
typedef void (STDCALL *fnPtrBatchDCSetSpVOut)(char spVOutFile[512]);


// Resets all BatchDC control parameters back to their default values and empties the DC binary tree (objects created by BatchDCInitSat)
typedef void (STDCALL *fnPtrBatchDCResetAll)();


// Returns DC acceptance criteria data for the specified satellite
// 
// The table below shows the values contained in xa_ac:
// 
//     
//         index
//         index Interpretation
//     
//      0 days from epoch, standard
//      1 number of residuals, standard
//      2 percent residual, standard
//      3 RMS (km), standard
//      4 obs span (days), standard
//      5 change in plan (deg), standard
//      6 change in abar, standard
//      7 change in N (rev/day), standard
//      8 change in B term, standard
//     
//     20 days from epoch, actual
//     21 number of residuals, actual
//     22 percent residual, actual
//     23 RMS (km), actual
//     24 obs span (days), actual
//     25 change in plan (deg), actual
//     26 change in abar, actual
//     27 change in N (rev/day), actual
//     28 change in B term, actual
// 
// satKey             The satellite's unique key (in-Long)
// xa_ac              acceptance criteria values in an array, see XA_AC_? for array arrangement (out-Double[64])
// returns 0 if the acceptance criteria is successfully returned, non-0 if there is an error
typedef int (STDCALL *fnPtrBatchDCGetAccptCrit)(__int64 satKey, double xa_ac[64]);


// Performs batch-least-square differential corrections to the specified satellite (VCM/SPVEC) and
// returns the corrected SGP4/SGP4-XP elements and related data
// Note: No need to initialize VCM before calling this method
// satKey             The satellite's unique key of the specified satellite (must be VCM or SPVEC) (in-Long)
// xa_egpCtrl         Array (in/out) containing settings for SpToEGP conversion, see XA_EGPCTRL_? for array arrangement (inout-Double[64])
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data - not yet used (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrSpToEGP)(__int64 satKey, double xa_egpCtrl[64], int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);


// Performs batch-least-square differential corrections to the specified satellite (VCM/SPVEC) and
// returns the corrected elements SGP4/SGP4-XP in form of a TLE
// Note: No need to initialize VCM before calling this method
// satKey             The satellite's unique key of the specified satellite (must be VCM or SPVEC) (in-Long)
// xa_egpCtrl         Array (in/out) containing settings for SpToEGP conversion, see XA_EGPCTRL_? for array arrangement (inout-Double[64])
// line1              Returned first line of a TLE. (out-Character[512])
// line2              Returned second line of a TLE (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrSpToTle)(__int64 satKey, double xa_egpCtrl[64], char line1[512], char line2[512]);


// Performs batch-least-square differential corrections to the specified satellite (VCM/SPVEC) and
// returns the corrected elements SGP4/SGP4-XP in form of a TLE
// Note: No need to initialize VCM before calling this method
// satKey             The satellite's unique key (in-Long)
// xa_egpCtrl         Array (in/out) containing settings for SpToEGP conversion, see XA_EGPCTRL_? for array arrangement (inout-Double[64])
// csvLine            A string to hold the TLE in csv format. (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrSpToCsv)(__int64 satKey, double xa_egpCtrl[64], char csvLine[512]);


// Performs batch-least-square differential corrections using the input external ephemeris and treating them as observations and
// returns the corrected SGP4/SGP4-XP elements and related data
// extEphFile         The name of the file containing external ephemeris data to be used in EGP (in-Character[512])
// xa_egpCtrl         Array (in/out) containing settings for SpToEGP conversion, see XA_EGPCTRL_? for array arrangement (inout-Double[64])
// xai_dcElts         Array of integers containing resulting BatchDC data (out-Integer[256])
// xar_dcElts         Array of doubles containing resulting BatchDC data (out-Double[256])
// xas_dcElts         String containing resulting BatchDC data - not yet used (out-Character[512])
// returns 0 if successful, 1: dc fails, best elset returned, 2: dc fails, no eleset returned
typedef int (STDCALL *fnPtrExtEphemToEGP)(char extEphFile[512], double xa_egpCtrl[64], int xai_dcElts[256], double xar_dcElts[256], char xas_dcElts[512]);
  
  // DC SETTING PARAMETERS
  
  #define MAX_PARAMS   256 
  
  
  // DC PRINT OPTIONS
  static const int  
     DC_PRINT_FIRSTBEST   =  0,   // PRINT FIRST AND LAST ITERATION
     DC_PRINT_ALLPASS     =  1,   // PRINT EVERY PASS AND SUMMARY
     DC_PRINT_SUMONLY     =  2,   // PRINT SUMMARY ONLY
     DC_PRINT_ELTONLY     =  3,   // PRINT OUTPUT ELEMENETS ONLY 
     DC_PRINT_NONE        =  4;   // DO NOT PRINT ANYTHING 
     
  // ITERATION SUMMARY OPTIONS
  static const int     
     ITER_SUM_KEP         =  1,   // PRINT SUMMARY EVERY ITERATION IN KEPLERIAN ELTS
     ITER_SUM_EQNX        =  2;   // PRINT SUMMARY EVERY ITERATION IN EQUINOCTIAL ELTS
  
  // INDEXES FOR INTEGER DATA FIELDS
  static const int  
     XAI_CTRL_PRINTOPTION  =  0,    // DC PRINT OPTION
     XAI_CTRL_DEBIASOBS    =  1,    // APPLY BIASES FROM SENSOR FILE
     XAI_CTRL_WEIGHTEDDC   =  2,    // WEIGHED DC FLAG
     XAI_CTRL_EPOCHOPTION  =  3,    // EPOCH PLACEMENT CONTROL
     XAI_CTRL_CORRECT_AG   =  4,    // ELEMENT CORRECTION FLAG - AG
     XAI_CTRL_CORRECT_AF   =  5,    // ELEMENT CORRECTION FLAG - AF
     XAI_CTRL_CORRECT_PSI  =  6,    // ELEMENT CORRECTION FLAG - PSI
     XAI_CTRL_CORRECT_CHI  =  7,    // ELEMENT CORRECTION FLAG - CHI
     XAI_CTRL_CORRECT_L    =  8,    // ELEMENT CORRECTION FLAG - L
     XAI_CTRL_CORRECT_N    =  9,    // ELEMENT CORRECTION FLAG - N
     XAI_CTRL_CORRECT_B    = 10,    // ELEMENT CORRECTION FLAG - B* (SGP4) B (SP)
     XAI_CTRL_CORRECT_AGOM = 11,    // ELEMENT CORRECTION FLAG - AGOM (SP)
     XAI_CTRL_CORRECTORDER = 12,    // CORRECTION ORDER
     XAI_CTRL_FOR1ITERONLY = 13,    // CORRECT BY THE SPECIFIED CORRECTION ORDER FOR 1 ITERATION ONLY
     XAI_CTRL_RESIDSELECT  = 14,    // FLAG SPECIFIES WHICH RESIDUALS ARE USED FOR RMS CALCULATION AND CONVERGENCE
     XAI_CTRL_SENPERFORM   = 15,    // FLAG; IF SET, PRODUCE SENSOR PERFORMANCE ANALYSIS SUMMARY
     XAI_CTRL_DWOBSPERTRCK = 16,    // FLAG; IF SET, DEWEIGHT ACCORDING TO # OF OBS PER TRACK 
     XAI_CTRL_ITERSUMOPT   = 17,    // ITERATION SUMMARY CONTROL
     XAI_CTRL_PARTIALMETH  = 18,    // PARTIALS METHOD 
     XAI_CTRL_LTC          = 19,    // LIGHT TIME CORRECTION CONTROL
     XAI_CTRL_BRUCE        = 20,    // NUMBER OF ITERATION TO ALLOW NO AUTO REJECTION OF RESIDUALS
     XAI_CTRL_PROPMETHOD   = 21,    // PROPAGATION METHOD - GP=0, XP=4, SP=99
     XAI_CTRL_CORRECTBVSX  = 22,    // FLAG; IF SET, CORRECT B* VS X
     XAI_CTRL_MAXOFITERS   = 23,    // MAX # OF ITERATIONS BEFORE DECLARING DIVERGENCE
     XAI_CTRL_USEPREDRMS   = 24,    // USE PREDICTED RMS VERSUS PREVIOUS RMS FOR CONVERGENCE TESTING
     XAI_CTRL_RESCOMPMETH  = 25,    // RESIDUAL COMPUTATION METHOD (GP ONLY): DELTA/427M=1, SPADOC4=2
     XAI_CTRL_USEANGRATES  = 26,    // FLAG; IF SET, USE ANGLE RATES (OBSTYPES = 4, 11)
     
     XAI_CTRL_SIZE         = 256;  
     
  
  
  // INDEXES FOR REAL DATA FIELDS
  static const int  
     XAR_CTRL_RMSMULT        =   0,    // RMS MULTIPLIER
     XAR_CTRL_USEREPOCH      =   1,    // TIME OF SPECIFIED EPOCH
     XAR_CTRL_CNVCRITONT     =   2,    // CONVERGENCE CRITERIA ON TIME CORRECTION (%)
     XAR_CTRL_1STPASDELTAT   =   3,    // FIRST PASS DELTA-T REJECTION CRITERIA
     XAR_CTRL_CNVCRITON7ELT  =   4,    // CONVERGENCE CRITERIA ON 7-ELT CORRECTION (%)
     XAR_CTRL_BRESET         =   5,    // RESET VALUE FOR B TERM IN SUBSET CORRECTION
     XAR_CTRL_SIZE           = 256;
  
  
  // INDEXES FOR ACCESSING DC'S INTEGER DATA
  static const int  
     XAI_DCELTS_SATNUM       =   0,    // SATELLITE NUMBER
     XAI_DCELTS_ELSETNUM     =   1,    // ELSET NUMBER
     XAI_DCELTS_ORBTYPE      =   2,    // ELSET'S ORBITAL/ELEMENT TYPE - SEE ELTTYPE_ CONSTANTS FOR A LIST OF POSSIBLE VALUES
     XAI_DCELTS_PROPTYPE     =   3,    // PROPAGATION METHOD - SEE PROPTYPE_ CONSTANTS FOR A LIST OF POSSIBLE VALUES (GP=1, SP=2, EXTERNAL EPHEMERIS=3)
     XAI_DCELTS_SPECTR       =   4,    // SPECTR MODE
     XAI_DCELTS_REVNUM       =   5,    // EPOCH REVOLUTION NUMBER
     XAI_DCELTS_CORRTYPE     =   6,    // CORRECTION TYPE: 0=TIME, 1=PLANE", 2=7-ELT, 3=IN-TRK, 4=8-ELT, 5=SUBELT
     
     XAI_DCELTS_ITERCOUNT    =  10,    // TOTAL ITERATION COUNT
     XAI_DCELTS_SUBITER      =  11,    // SUB ITERATION COUNT
     XAI_DCELTS_RESACC       =  12,    // # RESIDUAL ACCEPTED
     XAI_DCELTS_RESREJ       =  13,    // # RESIDUAL REJECTED
     
     XAI_DCELTS_CORRFLGS     =  20,    // 20-28 CORRECTION ELEMENT FLAGS  
     
     XAI_DCELTS_SIZE         = 256;
  
  // INDEXES FOR ACCESSING DC'S REAL DATA   
  static const int  
     XAR_DCELTS_EPOCHDS50UTC =   0,    // ELSET'S EPOCH TIME IN DAYS SINCE 1950 UTC
     XAR_DCELTS_NDOT         =   1,    // N-DOT/2  (FOR SGP, EPH-TYPE = 0)
     XAR_DCELTS_N2DOT        =   2,    // N-DOUBLE-DOT/6  (FOR SGP, EPH-TYPE = 0)
     XAR_DCELTS_BFIELD       =   3,    // EITHER SGP4 BSTAR (1/ER) OR SGP4-XP/SP BTERM (M2/KG)
     XAR_DCELTS_AGOM         =   4,    // SGP4-XP/SP AGOM (M**2/KG)
     XAR_DCELTS_OGPARM       =   5,    // SP OUTGASSING PARAMETER (KM/S**2)
     XAR_DCELTS_KEP_A        =   6,    // SEMI MAJOR AXIS (KM)
     XAR_DCELTS_KEP_E        =   7,    // ECCENTRICITY 
     XAR_DCELTS_KEP_INCLI    =   8,    // INCLINATION (DEG)
     XAR_DCELTS_KEP_MA       =   9,    // MEAN ANAMOLY (DEG)
     XAR_DCELTS_KEP_NODE     =  10,    // RIGHT ASCENSION OF THE ASCENDING NODE (DEG)
     XAR_DCELTS_KEP_OMEGA    =  11,    // ARGUMENT OF PERIGEE (DEG)
     XAR_DCELTS_EQNX_AF      =  12,    // AF
     XAR_DCELTS_EQNX_AG      =  13,    // AG
     XAR_DCELTS_EQNX_CHI     =  14,    // CHI
     XAR_DCELTS_EQNX_PSI     =  15,    // PSI
     XAR_DCELTS_EQNX_L       =  16,    // MEAN LONGITUDE (DEG)
     XAR_DCELTS_EQNX_N       =  17,    // MEAN MOTION (REVS/DAY)
     XAR_DCELTS_POSX         =  18,    // ECI POSX (KM)
     XAR_DCELTS_POSY         =  19,    // ECI POSY (KM)
     XAR_DCELTS_POSZ         =  20,    // ECI POSZ (KM)
     XAR_DCELTS_VELX         =  21,    // ECI VELX (KM/S)
     XAR_DCELTS_VELY         =  22,    // ECI VELY (KM/S)
     XAR_DCELTS_VELZ         =  23,    // ECI VELZ (KM/S)
     
     XAR_DCELTS_RMS          =  40,    // RMS (KM)
     XAR_DCELTS_RMSUNWTD     =  41,    // UNWEIGHTED RMS (KM)
     XAR_DCELTS_DELTATRMS    =  42,    // DELTA T RMS (MIN)
     XAR_DCELTS_BETARMS      =  43,    // BETA RMS (DEG)
     XAR_DCELTS_DELTAHTRMS   =  44,    // DELTA HEIGHT RMS (KM)
     XAR_DCELTS_CONVQLTY     =  45,    // CONVERGENCE VALUE (KM)
     XAR_DCELTS_RMSPD        =  46,    // PREDICTED RMS (KM)
     
     XAR_DCELTS_COVL         =  60,    // COVARIANCE DIAGONAL L
     XAR_DCELTS_COVN         =  61,    // COVARIANCE DIAGONAL N   
     XAR_DCELTS_COVCHI       =  62,    // COVARIANCE DIAGONAL CHI
     XAR_DCELTS_COVPSI       =  63,    // COVARIANCE DIAGONAL PSI
     XAR_DCELTS_COVAF        =  64,    // COVARIANCE DIAGONAL AF
     XAR_DCELTS_COVAG        =  65,    // COVARIANCE DIAGONAL AG
     XAR_DCELTS_COVBTERM     =  66,    // COVARIANCE DIAGONAL BTERM
     XAR_DCELTS_COVNA        =  67,    // COVARIANCE NOT USED
     XAR_DCELTS_COVAGOM      =  68,    // COVARIANCE DIAGONAL AGOM
     
     XAR_DCELTS_XMAX         =  70,    // MAX PARTIAL RESIDUAL (KM) 
     XAR_DCELTS_XMAX2        =  71,    // MAX VELOCITY RESID (KM/SEC)
     XAR_DCELTS_XMAX3        =  72,    // MAX BETA RESIDUAL (DEG)
     XAR_DCELTS_XMAX4        =  73,    // MAX DELTA-T RESIDUAL (MIN)
     XAR_DCELTS_PATCL        =  74,    // LOW ARGUMENT OF LATITUDE COVERAGE (DEG)
     XAR_DCELTS_PATCH        =  75,    // HIGH ARGUMENT OF LATITUDE COVERAGE (DEG)
     
     XAR_DCELTS_EQNXCOVMTX   = 200,    // EQUINOCTIAL COVARIANCE MATRIX - THE LOWER TRIANGULAR HALF 200-244
     
     XAR_DCELTS_SIZE         = 256;
     
  // INDEXES FOR ACCESSING OBS REJECTION FLAGS
  static const int  
     XA_REJFLG_DECAYED      =   0,    // SATELLITE HAS DECAYED AT THE TIME OF OBS
     XA_REJFLG_ERROR        =   1,    // OBS RESIDUAL COMPUTATION ERROR CODE
     XA_REJFLG_RA           =   2,    // RIGHT ASCENSION RESIDUAL REJECTED
     XA_REJFLG_BETA         =   3,    // BETA RESIDUAL REJECTED
     XA_REJFLG_DEC          =   4,    // DECLINATION RESIDUAL REJECTED
     XA_REJFLG_HEIGHT       =   5,    // DELTA H RESIDUAL REJECTED
     XA_REJFLG_RANGE        =   6,    // RANGE RESIDUAL REJECTED
     XA_REJFLG_RR           =   7,    // RANGE RATE RESIDUAL REJECTED
     XA_REJFLG_TIME         =   8,    // DELTA T RESIDUAL REJECTED
     
     XA_REJFLG_SIZE         =  32;
     
  // INDEXES FOR ACCESSING DC'S ACCEPTANCE CRITERIA DATA   
  static const int  
     XA_AC_STD_EPOCH    =   0,    // STANDARD - DAYS FROM EPOCH
     XA_AC_STD_NORES    =   1,    // STANDARD - NUMBER OF RESIDUALS
     XA_AC_STD_PRCNTRES =   2,    // STANDARD - PERCENT RESIDUAL
     XA_AC_STD_RMS      =   3,    // STANDARD - RMS (KM)
     XA_AC_STD_OBSSPAN  =   4,    // STANDARD - OBS SPAN (DAYS)
     XA_AC_STD_DELTAW   =   5,    // STANDARD - CHANGE IN PLAN (DEG)
     XA_AC_STD_DELTAABAR=   6,    // STANDARD - CHANGE IN ABAR 
     XA_AC_STD_DELTAN   =   7,    // STANDARD - CHANGE IN N (REV/DAY)
     XA_AC_STD_DELTAB   =   8,    // STANDARD - CHANGE IN B TERM
  
     XA_AC_ACT_EPOCH    =  20,    // ACTUAL - DAYS FROM EPOCH
     XA_AC_ACT_NORES    =  21,    // ACTUAL - NUMBER OF RESIDUALS
     XA_AC_ACT_PRCNTRES =  22,    // ACTUAL - PERCENT RESIDUAL
     XA_AC_ACT_RMS      =  23,    // ACTUAL - RMS (KM)
     XA_AC_ACT_OBSSPAN  =  24,    // ACTUAL - OBS SPAN (DAYS)
     XA_AC_ACT_DELTAW   =  25,    // ACTUAL - CHANGE IN PLAN (DEG)
     XA_AC_ACT_DELTAABAR=  26,    // ACTUAL - CHANGE IN ABAR 
     XA_AC_ACT_DELTAN   =  27,    // ACTUAL - CHANGE IN N (REV/DAY)
     XA_AC_ACT_DELTAB   =  28,    // ACTUAL - CHANGE IN B TERM
     
     XA_AC_SIZE         =  64; 
     
  // DIFFERENT DC PROPAGATION METHOD
  static const int  
     DCPROPTYPE_GP =  0,      // DC PROPAGATOR METHOD IS GP
     DCPROPTYPE_XP =  4,      // DC PROPAGATOR METHOD IS SGP4-XP
     DCPROPTYPE_SP = 99;      // DC PROPAGATOR METHOD IS SP 
  
  // DC ITERATING RETURNED CODE   
  static const int  
     ITERCODE_DONE      = 0,     // DC WAS SUCCESSFUL
     ITERCODE_ERROR     = 1,     // DC HAS ERROR
     ITERCODE_ITERATING = 2,     // DC IS STILL ITERATING
     ITERCODE_DIVERGED  = 3;     // DC DIVERGED BUT TRYING TO RECOVER
    
    
  // INDEXES FOR OB REJECTION ERROR CODE
  static const int  
     OBREJ_NONE       = 0,      // OB RESIDUAL COMPUTATION OK
     OBREJ_NOSENDATA  = 1,      // SENSOR DATA RETRIEVAL ERROR
     OBREJ_NOSENLOC   = 2,      // NO SENSOR LOCATION
     OBREJ_RESCOMPERR = 3;      // RESIDUAL COMPUTATION ERROR
     
  // INDEXES REPRESENT EPOCH PLACEMENT OPTIONS
  static const int     
     EPFLG_NODALXINGLATESTOB = 0,     // NODAL CROSSING NEAREST LATEST OBS
     EPFLG_LATESTOB          = 1,     // EXACT TIME OF LATEST OBS
     EPFLG_NODALXINGATTIME   = 2,     // NODAL CROSSING CLOSEST TO SPECIFIED TIME
     EPFLG_ATEPOCH           = 3,     // DO NOT CHANGE EPOCH 
     EPFLG_ATSPECIFIEDTIME   = 4,     // EXACT AT SPECIFIED TIME
     EPFLG_MIDDLEOBSSPAN     = 5,     // MIDDLE OF OBS SPAN
     EPFLG_EARLIESTOB        = 6,     // EXACT TIME OF EARLIEST OBS 
     EPFLG_BEGINDAYEPOCH     = 7,     // BEGINNING OF DAY OF EPOCH, GOOD FOR EGP
     EPFLG_BEGINDAYLATESTOB  = 8,     // BEGINNING OF DAY OF LAST OBS
     EPFLG_NODALXINGEPOCH    = 9;     // NODAL CROSSING NEAREST EPOCH, GOOD FOR EGP
     
  // INDEXES FOR EGP CONTROL PARAMETERS FOR INPUT VCM/SPVEC-TYPED ELSETS OR EXTERNAL EPHEMERIS FILE
  static const int  
     XA_EGPCTRL_OPTION     =  0,      // NOT BEING USED YET
     XA_EGPCTRL_DCELTTYPE  =  1,      // DC ELEMENT TYPE: 0=SPG4, 4=SGP4-XP
     XA_EGPCTRL_STARTMSE   =  2,      // FIT SPAN START TIME (MINUTES SINCE VCM'S EPOCH/SPECIFIED NEW EPOCH) (SET START/STOP = 0 TO AUTO SELECT)
     XA_EGPCTRL_STOPMSE    =  3,      // FIT SPAN STOP TIME (MINUTES SINCE VCM'S EPOCH/SPECIFIED NEW EPOCH) (SET START/STOP = 0 TO AUTO SELECT)
     XA_EGPCTRL_STEPMIN    =  4,      // STEP SIZE IN MINUTES (HOW OFTEN OBS ARE GENERATED) (SET TO ZERO TO AUTO SELECT AND THEN ACTUAL STEP SIZE WILL BE RETURNED)
     XA_EGPCTRL_DRAGCOR    =  5,      // DRAG CORRECTION: 0=NO CORRECTION, 1=CORRECT BSTAR(SGP4)/BTERM(SGP4-XP), 2=CORRECT X(SGP4 ONLY)
     XA_EGPCTRL_AGOMCOR    =  6,      // AGOM CORRECTION: 0=NO CORRECTION, 1=CORRECT AGOM (ONLY WHEN DC ELEMENT = SGP4-XP)
     XA_EGPCTRL_EPFLG      =  7,      // EPOCH PLACEMENT FLAG - SEE EPFLG_? FOR DESCRIPTION
     XA_EGPCTRL_NEWEPOCH   =  8,      // TIME OF SPECIFIED EPOCH IN DS50UTC (ONLY FOR XA_EGPCTRL_EPFLG = 2 OR 4)                 * 
     
     XA_EGPCTRL_BVAL       =  9,      // ADDTIONAL OPTION IF INPUT IS EXTERNAL EPHEMERIS FILE - BSTAR(SGP4)/BTERM(SGP4-XP) IF XA_EGPCTRL_DRAGCOR IS SET (= 1) 
     XA_EGPCTRL_AGOMVAL    = 10,      // ADDTIONAL OPTION IF INPUT IS EXTERNAL EPHEMERIS FILE - AGOM VALUE IF XA_EGPCTRL_AGOMCOR IS SET (= 1)
     
     XA_EGPCTRL_SIZE       = 64;
    
     
// BatchDCDll's function pointers declaration
extern fnPtrBatchDCInit                    BatchDCInit;
extern fnPtrBatchDCGetInfo                 BatchDCGetInfo;
extern fnPtrBatchDCLoadFile                BatchDCLoadFile;
extern fnPtrBatchDCLoadFileAll             BatchDCLoadFileAll;
extern fnPtrBatchDCLoadCard                BatchDCLoadCard;
extern fnPtrBatchDCGetPCard                BatchDCGetPCard;
extern fnPtrBatchDCSaveFile                BatchDCSaveFile;
extern fnPtrBatchDCGetParams               BatchDCGetParams;
extern fnPtrBatchDCSetParams               BatchDCSetParams;
extern fnPtrBatchDCInitSat                 BatchDCInitSat;
extern fnPtrBatchDCSolve                   BatchDCSolve;
extern fnPtrBatchDCSolveSelObs             BatchDCSolveSelObs;
extern fnPtrBatchDCRemoveSat               BatchDCRemoveSat;
extern fnPtrBatchDCIterate                 BatchDCIterate;
extern fnPtrBatchDCGetVcm                  BatchDCGetVcm;
extern fnPtrBatchDCGetSpVOut               BatchDCGetSpVOut;
extern fnPtrBatchDCSetSpVOut               BatchDCSetSpVOut;
extern fnPtrBatchDCResetAll                BatchDCResetAll;
extern fnPtrBatchDCGetAccptCrit            BatchDCGetAccptCrit;
extern fnPtrSpToEGP                        SpToEGP;
extern fnPtrSpToTle                        SpToTle;
extern fnPtrSpToCsv                        SpToCsv;
extern fnPtrExtEphemToEGP                  ExtEphemToEGP;



void LoadBatchDCDll();
void FreeBatchDCDll();




#endif
// ========================= End of auto generated code ==========================
