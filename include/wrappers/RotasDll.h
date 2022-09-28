// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef ROTASDLL_H
#define ROTASDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define RotasDll "Rotas.dll"
#elif __APPLE__
  #define RotasDll "librotas.dylib"
#else
  #define RotasDll "librotas.so"
#endif


// Initializes Rotas DLL for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if the Rotas dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasInit)(__int64 apPtr);


// Returns information about the current version of Rotas DLL. 
// The information is placed in the string parameter passed in.
// infoStr            A string to hold the information about Rotas.dll (out-Character[128])
typedef void (STDCALL *fnPtrRotasGetInfo)(char infoStr[128]);


// Loads Rotas-related parameters from an input text file
// rotasInputFile     The name of the file containing Rotas-related parameters (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasLoadFile)(char rotasInputFile[512]);


// Loads Rotas control parameters and all Rotas related data (environment, time, elsets, sensors, obs) from an input text file
// rotasInputFile     The name of the file containing Rotas control parameters and all Rotas related data (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasLoadFileAll)(char rotasInputFile[512]);


// Loads a single Rotas-typed card
// card               Rotas-type input card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasLoadCard)(char card[512]);


// Saves current Rotas settings to a file
// rotasFile          The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasSaveFile)(char rotasFile[512], int saveMode, int saveForm);


// Builds and returns the Rotas P-Card from the current Rotas settings
// rotasPCard         The resulting Rotas P-Card string (out-Character[512])
typedef void (STDCALL *fnPtrRotasGetPCard)(char rotasPCard[512]);


// Retrieves all Rotas control parameters with a single function call
// rotasMode          Rotas processing mode: TAG=verify ob tab (default), FTAG=force assoc vs all input elsets, ALLEL=find the best # assoc elsets (out-Character[5])
// grossBeta          gross beta threshold (deg) (default=2.0) (out-Double)
// betaLimit          ASTAT 0 beta limit (deg) (default=0.05) (out-Double)
// deltaTLimit        ASTAT 0 delta-t limit (min) (default=0.05) (out-Double)
// deltaHLimit        ASTAT 0 delta-height limit (km) (default=10) (out-Double)
// astat2Mult         ASTAT 2 multiplier (default=4) (out-Integer)
// prtFlag            Residual print flag: 1=print all, 2=print ASTAT 0/1, 3=print no residuals, 4=print ASTAT 0/1/2 (out-Integer)
// retagFlag          Retag flag: 0=don't retag (default), 1=retag ASTAT 0/1 to B3, 2=retag ASTAT 0/1 to TTY, 3=retag ASTAT 0/1/2 to B3 (out-Integer)
// ltcFlag            Type 5 observation light-time correct flag: 0=don't apply LTC, 1=apply LTC analytically, 2=apply LTC exactly (out-Integer)
// maxNumAssoc        Max number of associations per ob (ALLEL mode only) (out-Integer)
// debiasFlag         Debias observation flag: 0=don't apply debias, 1=debias ob by applying sensor's bias data (out-Integer)
// diagMode           Diagnostic print flag (out-Integer)
// covPrtFlag         Covariance flag: 1=Propagate covariance and compute covariance matrix (covariance matrix must be available) (out-Integer)
// isTrackMode        Track mode: 1=use track processing (each track is treated as a single entity) (out-Integer)
// remRetagObs        Retagged obs are removed from further association (out-Integer)
// extArr             For future use (out-Double[128])
typedef void (STDCALL *fnPtrRotasGetPAll)(char rotasMode[5], double* grossBeta, double* betaLimit, double* deltaTLimit, double* deltaHLimit, int* astat2Mult, int* prtFlag, int* retagFlag, int* ltcFlag, int* maxNumAssoc, int* debiasFlag, int* diagMode, int* covPrtFlag, int* isTrackMode, int* remRetagObs, double extArr[128]);


// Sets all Rotas control parameters with a single function call
// rotasMode          Rotas processing mode: TAG=verify ob tab (default), FTAG=force assoc vs all input elsets, ALLEL=find the best # assoc (in-Character[5])
// grossBeta          gross beta threshold (deg) (default=2.0) (in-Double)
// betaLimit          ASTAT 0 beta limit (deg) (default=0.05) (in-Double)
// deltaTLimit        ASTAT 0 delta-t limit (min) (default=0.05) (in-Double)
// deltaHLimit        ASTAT 0 delta-height limit (km) (default=10) (in-Double)
// astat2Mult         ASTAT 2 multiplier (default=4) (in-Integer)
// prtFlag            Residual print flag: 1=print all, 2=print ASTAT 0/1, 3=print no residuals, 4=print ASTAT 0/1/2 (in-Integer)
// retagFlag          Retag flag: 0=don't retag (default), 1=retag ASTAT 0/1 to B3, 2=retag ASTAT 0/1 to TTY, 3=retag ASTAT 0/1/2 to B3 (in-Integer)
// ltcFlag            Type 5 observation light-time correct flag: 0=don't apply LTC, 1=apply LTC analytically, 2=apply LTC exactly (in-Integer)
// maxNumAssoc        Max number of associations per ob (ALLEL mode only) (in-Integer)
// debiasFlag         Debias observation flag: 0=don't apply debias, 1=debias ob by applying sensor's bias data (in-Integer)
// diagMode           Diagnostic print flag (in-Integer)
// covPrtFlag         Covariance flag: 1=Propagate covariance and compute covariance matrix (covariance matrix must be available) (in-Integer)
// isTrackMode        Track mode: 1=use track processing (each track is treated as a single entity) (in-Integer)
// remRetagObs        Retagged obs are removed from further association (in-Integer)
// extArr             For future use (in-Double[128])
typedef void (STDCALL *fnPtrRotasSetPAll)(char rotasMode[5], double grossBeta, double betaLimit, double deltaTLimit, double deltaHLimit, int astat2Mult, int prtFlag, int retagFlag, int ltcFlag, int maxNumAssoc, int debiasFlag, int diagMode, int covPrtFlag, int isTrackMode, int remRetagObs, double extArr[128]);


// Retrieves the value of a specified Rotas control parameter (P-card field)
// 
// The table below shows the values for the xf_RP parameter:
// 
// 
// Index
// Index Interpretation
// 
//  1  Rotas processing mode
//  2  Gross Beta limit (deg)
//  3  ASTAT 0 Beta limit (deg)
//  4  ASTAT 0 delta-t limit (min)
//  5  ASTAT 0 delta-height limit (km)
//  6  ASTAT 2 multiplier
//  7  Residual print flag
//  8  Retag ASTAT 1 ob flag
//  9  Light-time correction flag
// 10  Maximum number of ALLEL assoc's to compute
// 11  Diagnostic print flag
// 12  Covariance print flag
// 13  Perform track processing
// 14  Retagged ob are removed from further association
// 15  Debias ob flag
// 
// xf_RP              Predefined number specifying which Rotas control parameter  to retrieve (in-Integer)
// retVal             A string to hold the value of the requested Rotas parameter (out-Character[512])
typedef void (STDCALL *fnPtrRotasGetPField)(int xf_RP, char retVal[512]);


//  Sets the value of a specified Rotas control parameter (P-card field)
// See RotasGetPField for values for the xf_RP parameter.
// xf_RP              Predefined number specifying which Rotas control parameter to set (in-Integer)
// valueStr           The new value of the specified field, expressed as a string (in-Character[512])
typedef void (STDCALL *fnPtrRotasSetPField)(int xf_RP, char valueStr[512]);


// Gets ASTAT 1 association multipliers
// assocMultp         ASTAT 1 association multiplier array (out-Integer[12])
typedef void (STDCALL *fnPtrRotasGetAssocMultipliers)(int assocMultp[12]);


// Sets ASTAT 1 association multipliers
// assocMultp         ASTAT 1 association multiplier array (in-Integer[12])
typedef void (STDCALL *fnPtrRotasSetAssocMultipliers)(int assocMultp[12]);


// Resets all Rotas control parameters back to their default values
typedef void (STDCALL *fnPtrRotasResetAll)();


// Determines if the observation/satellite pair can possibly have an association
// obsKey             The obervation's unique key (in-Long)
// satKey             The satellite's unique key (in-Long)
// returns 0 if the observation/satellite pair doesn't have an association, 1 if the pair has an association
typedef int (STDCALL *fnPtrRotasHasASTAT)(__int64 obsKey, __int64 satKey);


// Determines if the observation/satellite pair can possibly have an association - suitable for multithread application
// xa_rt_parms        ROTAS control parameters - see XA_RT_PARMS_? for array arrangement (in-Double[16])
// obsKey             The obervation's unique key (in-Long)
// satKey             The satellite's unique key (in-Long)
// returns 0 if the observation/satellite pair doesn't have an association, 1 if the pair has an association
typedef int (STDCALL *fnPtrRotasHasASTAT_MT)(double xa_rt_parms[16], __int64 obsKey, __int64 satKey);


// Computes residuals for one observation against one satellite
// Obs type 0 (range rate only) cannot be used to compute residuals.
// obsKey             The observation's unique key (in-Long)
// satKey             The satellite's unique key (in-Long)
// xa_ObsRes          The resulting array of obs residuals, see XA_OBSRES_? for array arrangement (out-Double[100])
// satElts            satellite state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); satellite LLH (7th-9th) (out-Double[9])
// obElts             observation state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); observation LLH (7th-9th) (out-Double[9])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasComputeObsResiduals)(__int64 obsKey, __int64 satKey, double xa_ObsRes[100], double satElts[9], double obElts[9]);


// Computes residuals for one observation against one satellite - suitable for multithread application
// Obs type 0 (range rate only) cannot be used to compute residuals.
// xa_rt_parms        ROTAS control parameters - see XA_RT_PARMS_? for array arrangement (in-Double[16])
// obsKey             The observation's unique key (in-Long)
// satKey             The satellite's unique key (in-Long)
// xa_ObsRes          The resulting array of obs residuals, see XA_OBSRES_? for array arrangement (out-Double[100])
// satElts            satellite state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); satellite LLH (7th-9th) (out-Double[9])
// obElts             observation state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); observation LLH (7th-9th) (out-Double[9])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasComputeObsResiduals_MT)(double xa_rt_parms[16], __int64 obsKey, __int64 satKey, double xa_ObsRes[100], double satElts[9], double obElts[9]);


// Computes residuals for a track of observations against one satellite. Each track is treated as a single entity
// obsKeys            The input array of obsKeys sorted in ascending order of sensor, satno, obsType, time, elev (in-Long[*])
// trackStartIdx      The start index of the first obs of the track (in-Integer)
// trackLength        The input track length (in-Integer)
// satKey             The satellite's unique key (in-Long)
// xa_ObsRes          The resulting array of obs residuals, see XA_OBSRES_? for array arrangement (out-Double[100])
// trackObsKeys       The 3 obsKeys of the 3 obs that were chosen to represent the track (out-Long[3])
// b3ObsCard          The resulting B3-card created by IOMOD to represent the whole track (out-Character[512])
// satElts            satellite state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); satellite LLH (8th-9th) (out-Double[9])
// obElts             observation state in ECI/TEME of Date: position (1st-3rd), velocity (4th-6th); observation LLH (8th-9th) (out-Double[9])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasComputeTrackResiduals)(__int64 obsKeys[], int trackStartIdx, int trackLength, __int64 satKey, double xa_ObsRes[100], __int64 trackObsKeys[3], char b3ObsCard[512], double satElts[9], double obElts[9]);


// Computes residuals for one observation against one satellite directly (no need to load ob and propagate satellite)
// 
// The table below shows the values contained in XA_OBSRES:
// 
// 
// Name
// Index
// Index Interpretation
// 
//  XA_OBSRES_AZ       0  Azimuth residual (deg) 
//  XA_OBSRES_EL       1  Elevation residual (deg) 
//  XA_OBSRES_RANGE    2  Range residual (km) 
//  XA_OBSRES_HEIGHT   3  Height residual (deg) 
//  XA_OBSRES_BETA     4  Beta residual (deg) 
//  XA_OBSRES_DELTAT   5  Delta T residual (min) 
//  XA_OBSRES_VMAG     6  Vector magnitude (km) 
//  XA_OBSRES_AGE      7  Time since epoch (days) 
//  XA_OBSRES_SU       8  True argument of latitude (deg) 
//  XA_OBSRES_REVNUM   9  Revolution number   
//  XA_OBSRES_RNGRATE 10  Range rate residual (km/sec) 
//  XA_OBSRES_ASTAT   11  observation ASTAT 
//  XA_OBSRES_OBSTYPE 12  observation type 
//  XA_OBSRES_SATANOM 13  satellite true anomaly (deg) 
//  XA_OBSRES_SATELEV 14  satellite elevation (deg) 
//  XA_OBSRES_SATCAT  15  satellite maintenance category 
//  XA_OBSRES_OBSTIME 16  obs time in ds50UTC 
//  XA_OBSRES_OBSAZ   17  obs azimuth (deg) 
//  XA_OBSRES_OBSEL   18  obs elevation (deg) 
//  XA_OBSRES_VELANG  19  Velocity angle residual (deg) 
//  XA_OBSRES_ANGMOM  20  Angular momentum residual (deg) 
//  XA_OBSRES_RA      21  Right ascension residual (deg) (for ob types 5, 9, 19) 
//  XA_OBSRES_DEC     22  Declination residual (deg) (for ob types 5, 9, 19) 
//  XA_OBSRES_POSX    23  Delta X position (km) 
//  XA_OBSRES_POSY    24  Delta Y position (km) 
//  XA_OBSRES_POSZ    25  Delta Z position (km) 
//  XA_OBSRES_VELX    26  Delta X velocity (km/sec) 
//  XA_OBSRES_VELY    27  Delta Y velocity (km/sec) 
//  XA_OBSRES_VELZ    28  Delta Z velocity (km/sec) 
//  XA_OBSRES_OBSRNG  29  Angle only obs computed range (km) 
//  XA_OBSRES_OBSRA   30  obs right ascension (deg) 
//  XA_OBSRES_OBSDEC  31  obs declination (deg) 
//  XA_OBSRES_LON     32  delta longitude (deg) 
// 
// obDataArr          The array storing observation data: position (1st-3rd), velocity (4th-6th) (in-Double[16])
// satDataArr         The array storing satellite data: position (1st-3rd), velocity (4th-6th) (in-Double[16])
// xa_ObsRes          The resulting array of obs residuals, see XA_OBSRES_? for array arrangement (out-Double[100])
// returns 0 if successful, non-0 if there is an error
typedef int (STDCALL *fnPtrRotasCompObResDirect)(double obDataArr[16], double satDataArr[16], double xa_ObsRes[100]);


// Returns the name of the retag obs file
// retagObsFile       The resulting retag file name (out-Character[512])
typedef void (STDCALL *fnPtrRotasGetRetagObsFile)(char retagObsFile[512]);


// Sets the file name of the retag obs file
// retagObsFile       The retag file name (in-Character[512])
typedef void (STDCALL *fnPtrRotasSetRetagObsFile)(char retagObsFile[512]);
  
  // INDEXES OF ROTAS CONTROL PARAMETER FIELDS (ROTAS P-CARD)
  static const int  
     XF_RP_MODE       =  1,     // ROTAS PROCESSING MODE
     XF_RP_GROSSBETA  =  2,     // GROSS BETA LIMIT (DEG)
     XF_RP_BETALIM    =  3,     // ASTAT 0 BETA LIMIT (DEG)
     XF_RP_DELTATLIM  =  4,     // ASTAT 0 DELTA-T LIMIT (MIN)
     XF_RP_DELTAHLIM  =  5,     // ASTAT 0 DELTA-HEIGHT LIMIT (KM)
     XF_RP_ASTAT2MULT =  6,     // ASTAT 2 MULTIPLIER
     XF_RP_PRTFLAG    =  7,     // RESIDUAL PRINT FLAG
     XF_RP_RETAGFLAG  =  8,     // RETAG ASTAT 1 OB FLAG
     XF_RP_LTC        =  9,     // LIGHT-TIME CORRECTION FLAG
     XF_RP_NUMASSOC   = 10,     // MAXIMUM NUMBER OF ALLEL ASSOC'S TO COMPUTE
     XF_RP_DIAGNOSTIC = 11,     // DIAGNOSTIC PRINT FLAG
     XF_RP_PRTCOV     = 12,     // COVARIANCE PRINT FLAG
     XF_RP_TRACKFLAG  = 13,     // PERFORM TRACK PROCESSING
     XF_RP_REMRETAG   = 14,     // RETAGGED OB ARE REMOVED FROM FURTHER ASSOCIATION
     XF_RP_DEBIAS     = 15,     // DEBIAS OB FLAG
     XF_RP_RESCOMPMETH= 16;     // RESIDUAL COMPUTATION METHOD: 1=DELTA/427M, 2=SPADOC-4(DEFAULT)
  
  // ROTAS CONTROL PARAMETERS IN INPUT ARRAY XA_RT_PARMS THAT IS USED IN ROTASHASASTAT_MT() AND 
  static const int  
     XA_RT_PARMS_GROSSBETA   =  1,   // GROSS BETA LIMIT (DEG)
     XA_RT_PARMS_BETALIM     =  2,   // ASTAT 0 BETA LIMIT (DEG)
     XA_RT_PARMS_DELTATLIM   =  3,   // ASTAT 0 DELTA-T LIMIT (MIN)
     XA_RT_PARMS_DELTAHLIM   =  4,   // ASTAT 0 DELTA-HEIGHT LIMIT (KM)
     XA_RT_PARMS_ASTAT2MULT  =  5,   // ASTAT 2 MULTIPLIER
     XA_RT_PARMS_LTC         =  6,   // LIGHT-TIME CORRECTION (LTC) FLAG: 1= DON'T APPLY LTC, 2= APPLY LTC ANALYTICALLY, 3= APPLY LTC EXACTLY
     XA_RT_PARMS_DEBIAS      =  7,   // DEBIAS OB FLAG: 0= DO NOT DEBIAS, 1= DEBIAS OB
     XA_RT_PARMS_RESCOMPMETH =  8,   // RESIDUAL COMPUTATION METHOD: 1=DELTA/427M, 2=SPADOC-4(DEFAULT)
     
     XA_RT_PARMS_SIZE        = 16;
  
  
  
  // RESIDUAL COMPUTATION METHODS
  static const int  
     RESCOMPMETH_DELTA427M = 1,   // DELTA/427M METHOD
     RESCOMPMETH_SPADOC4   = 2;   // SPADOC 4 METHOD
  
  // PV OB DATA
  static const int  
     XA_OBPV_POSX     =  0,      // OB ECI POSITION X (KM) IN TEME OF DATE
     XA_OBPV_POSY     =  1,      // OB ECI POSITION Y (KM) IN TEME OF DATE
     XA_OBPV_POSZ     =  2,      // OB ECI POSITION Z (KM) IN TEME OF DATE
     XA_OBPV_VELX     =  3,      // OB ECI VELOCITY X (KM/SEC) IN TEME OF DATE
     XA_OBPV_VELY     =  4,      // OB ECI VELOCITY Y (KM/SEC) IN TEME OF DATE
     XA_OBPV_VELZ     =  5,      // OB ECI VELOCITY Z (KM/SEC) IN TEME OF DATE
     XA_OBPV_TIME     =  6,      // OB TIME IN DAYS SINCE 1950, UTC
     
     XA_OBPV_END      = 15,      // THE LAST AVAILABLE INDEX
     XA_OBPV_SIZE     = 16;
  
  // SATELLITE STATE DATA
  static const int  
     XA_SATPV_POSX    =  0,      // SATELLITE ECI POSITION X (KM) IN TEME OF DATE
     XA_SATPV_POSY    =  1,      // SATELLITE ECI POSITION Y (KM) IN TEME OF DATE
     XA_SATPV_POSZ    =  2,      // SATELLITE ECI POSITION Z (KM) IN TEME OF DATE
     XA_SATPV_VELX    =  3,      // SATELLITE ECI VELOCITY X (KM/SEC) IN TEME OF DATE
     XA_SATPV_VELY    =  4,      // SATELLITE ECI VELOCITY Y (KM/SEC) IN TEME OF DATE
     XA_SATPV_VELZ    =  5,      // SATELLITE ECI VELOCITY Z (KM/SEC) IN TEME OF DATE
     
     XA_SATPV_END     = 15,      // THE LAST AVAILABLE INDEX
     XA_SATPV_SIZE    = 16;
  
     
  // OBS RESIDUAL DATA FIELD INDEXES
  static const int  
     XA_OBSRES_AZ     =  0,           // AZIMUTH RESIDUAL (DEG)
     XA_OBSRES_EL     =  1,           // ELEVATION RESIDUAL (DEG)
     XA_OBSRES_RANGE  =  2,           // RANGE RESIDUAL (KM)
     XA_OBSRES_HEIGHT =  3,           // HEIGHT RESIDUAL (DEG)
     XA_OBSRES_BETA   =  4,           // BETA RESIDUAL (DEG). ASIN(DOT(PRIU, SECW))
     XA_OBSRES_DELTAT =  5,           // DELTA T RESIDUAL (MIN)
     XA_OBSRES_VMAG   =  6,           // VECTOR MAGNITUDE (KM)
     XA_OBSRES_AGE    =  7,           // TIME SINCE EPOCH (DAYS)
     XA_OBSRES_SU     =  8,           // TRUE ARGUMENT OF LATITUDE (DEG)
     XA_OBSRES_REVNUM =  9,           // REVOLUTION NUMBER  
     XA_OBSRES_RNGRATE= 10,           // RANGE RATE RESIDUAL (KM/SEC)
     XA_OBSRES_ASTAT  = 11,           // OBSERVATION ASTAT
     XA_OBSRES_OBSTYPE= 12,           // OBSERVATION TYPE
     XA_OBSRES_SATANOM= 13,           // SATELLITE TRUE ANOMALY (DEG)
     XA_OBSRES_SATELEV= 14,           // SATELLITE ELEVATION (DEG)
     XA_OBSRES_SATCAT = 15,           // SATELLITE MAINTENANCE CATEGORY
     XA_OBSRES_OBSTIME= 16,           // OBS TIME IN DS50UTC
     XA_OBSRES_OBSAZ  = 17,           // OBS AZIMUTH (DEG)
     XA_OBSRES_OBSEL  = 18,           // OBS ELEVATION (DEG)
     XA_OBSRES_VELANG = 19,           // VELOCITY ANGLE RESIDUAL (DEG)
     XA_OBSRES_ANGMOM = 20,           // ANGULAR MOMENTUM RESIDUAL (DEG).  ACOS(DOT(PRIW, SECW))
     XA_OBSRES_RA     = 21,           // RIGHT ASCENSION RESIDUAL (DEG) (FOR OB TYPES 5, 9, 19)
     XA_OBSRES_DEC    = 22,           // DECLINATION RESIDUAL (DEG) (FOR OB TYPES 5, 9, 19)
     XA_OBSRES_POSX   = 23,           // DELTA X POSITION (KM)
     XA_OBSRES_POSY   = 24,           // DELTA Y POSITION (KM)
     XA_OBSRES_POSZ   = 25,           // DELTA Z POSITION (KM)
     XA_OBSRES_VELX   = 26,           // DELTA X VELOCITY (KM/SEC)
     XA_OBSRES_VELY   = 27,           // DELTA Y VELOCITY (KM/SEC)
     XA_OBSRES_VELZ   = 28,           // DELTA Z VELOCITY (KM/SEC)
     XA_OBSRES_OBSRNG = 29,           // ANGLE ONLY - OBS COMPUTED RANGE (KM)
  
     XA_OBSRES_OBSRA  = 30,           // OBS RIGHT ASCENSION (DEG)
     XA_OBSRES_OBSDEC = 31,           // OBS DECLINATION (DEG)
     XA_OBSRES_LON    = 32,           // DELTA EAST LONGITUDE (DEG) 
     
     XA_OBSRES_POSU   = 33,           // DELTA U POSITION (KM)
     XA_OBSRES_POSV   = 34,           // DELTA V POSITION (KM)
     XA_OBSRES_POSW   = 35,           // DELTA W POSITION (KM)
     XA_OBSRES_CHI    = 36,           // 3D POSITION CHI-SQUARED RESIDUAL (KM) (LIGHT TIME CORRECTION FLAG MUST BE SET TO 0 OR 2, WILL NOT WORK WITH 1)
  
     XA_OBSRES_ANGSEP = 38,           // ANGULAR SEPARATION BETWEEN OBS AND STATE (DEG)
  
     XA_OBSRES_SIZE   =100;           
  
     
     
  
// RotasDll's function pointers declaration
extern fnPtrRotasInit                      RotasInit;
extern fnPtrRotasGetInfo                   RotasGetInfo;
extern fnPtrRotasLoadFile                  RotasLoadFile;
extern fnPtrRotasLoadFileAll               RotasLoadFileAll;
extern fnPtrRotasLoadCard                  RotasLoadCard;
extern fnPtrRotasSaveFile                  RotasSaveFile;
extern fnPtrRotasGetPCard                  RotasGetPCard;
extern fnPtrRotasGetPAll                   RotasGetPAll;
extern fnPtrRotasSetPAll                   RotasSetPAll;
extern fnPtrRotasGetPField                 RotasGetPField;
extern fnPtrRotasSetPField                 RotasSetPField;
extern fnPtrRotasGetAssocMultipliers       RotasGetAssocMultipliers;
extern fnPtrRotasSetAssocMultipliers       RotasSetAssocMultipliers;
extern fnPtrRotasResetAll                  RotasResetAll;
extern fnPtrRotasHasASTAT                  RotasHasASTAT;
extern fnPtrRotasHasASTAT_MT               RotasHasASTAT_MT;
extern fnPtrRotasComputeObsResiduals       RotasComputeObsResiduals;
extern fnPtrRotasComputeObsResiduals_MT    RotasComputeObsResiduals_MT;
extern fnPtrRotasComputeTrackResiduals     RotasComputeTrackResiduals;
extern fnPtrRotasCompObResDirect           RotasCompObResDirect;
extern fnPtrRotasGetRetagObsFile           RotasGetRetagObsFile;
extern fnPtrRotasSetRetagObsFile           RotasSetRetagObsFile;



void LoadRotasDll();
void FreeRotasDll();




#endif
// ========================= End of auto generated code ==========================
