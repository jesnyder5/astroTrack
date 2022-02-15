// This wrapper file was generated automatically by the A9\GenDllWrappers program.

#ifndef ROTASDLL_SERVICE_H
#define ROTASDLL_SERVICE_H

#include "DllUtils.h"
#include "ObsDll_Service.h"

// Residual print flag
static int 
   PRINT_ALL         =  1,    // print all residuals
   PRINT_ASTAT_01    =  2,    // print ASTAT 0s, and 1s only
   PRINT_NO          =  3,    // print no residuals
   PRINT_ASTAT_012   =  4;    // print ASTAT 0s, 1s, and 2s


static int
   RETAG_B3_ASTAT0_1  = 1,    // Retag ASTAT 0s and 1s to B3 obs file
   RETAG_TTY_ASTAT0_1 = 2,    // Retag ASTAT 0s and 1s to TTY obs file
   RETAG_B3_ASTAT0_2  = 3;    // Retag ASTAT 0s and 2s to B3 obs file



// Rotas control parameters structure
typedef struct
{
   char   rotasMode[6]; 
   double grossBeta; 
   double betaLimit; 
   double deltaTLimit;
   double deltaHLimit;
   int    astat2Mult;
   int    prtFlag; 
   int    retagFlag; 
   int    ltcFlag;
   int    maxNumAssoc;
   int    debiasFlag;
   int    diagMode; 
   int    covPrtFlag; 
   int    isTrackMode; 
   int    remRetagObs;
} RotasCtrl;

typedef struct 
{
   int     ErrCode;
   double  Azimuth;            // Azimuth residual (deg)
   double  Elevation;          // Elevation residual (deg)
   double  RightAscension;     // Right ascension residual (deg)
   double  Declination;        // Declination residual (deg)
   double  Range;              // Range residual (km)
   double  RangeRate;          // Range rate residual (km/sec)
   double  Height;             // Height residual (deg)
   double  Beta;               // Beta residual (deg)
   double  DeltaT;             // Delta T residual (min)
   double  VMag;               // Vector magnitude (km)
   double  Age;                // Time since epoch (days)
   double  RevNum;             // Revolution number  
   double  VelAngle;           // Velocity angle residual (deg)
   double  AngularMomentum;    // Angular momentum residual (deg)


   __int64 SatKey; 
   __int64 ObsKey; 
   int     SenKey; 

   double ObsTimeDs50UTC;      // Observation time in days since 1950 UTC
   double SatArgOfLatitude;    // True argument of latitude (deg)
   double SatTrueAnomaly;      // Satellite true anomaly (deg)
   double SatElevation;        // Satellite elevation (deg)
   double SatLon;              // Satellite geodetic longitude (deg)


   int ObsType;                // Observation type
   int SatCat;                 // Satellite maintenance category
   int ASTAT;                  // Observation ASTAT

} Residuals;


void PrintRotasHeader(FILE* fpOut, int useNewFormat);

void GetRotasCtrlPara(RotasCtrl* rotasCtrl);
void PrintRotasCtrls(FILE* fpOut, RotasCtrl* rotasCtrl);
void PrintAssocMultipliers(FILE* fpOut);
void GetObsResiduals(__int64 obsKey, __int64 satKey, Residuals* residuals);
void ResidualArrToStruct(__int64 obsKey, __int64 satKey, double residualArr[], Residuals* residuals);
void PrintObsResiduals(FILE* fpOut, ObsRecord* obs, int obsNum,  Residuals* residuals, int useNewFormat);
void PrintBadObs(FILE* fpOut, ObsRecord* obs, int obsNum, int useNewFormat);
void PrintNotAssociateObs(FILE* fpOut, ObsRecord* obs, int obsNum, int useNewFormat);
void PrintRotasError(FILE* fpOut, ObsRecord* obs, int obsNum, int useNewFormat);
void PrintNoMatchingElset(FILE* fpOut, ObsRecord* obs, int obsNum, int useNewFormat);
int  OKToRetag(int retagFlag, int ASTAT);
void DoRetagObs(FILE* fpOut, __int64 obsKey, int newTag, int retagFlg, int ASTAT);
int  MaxPrintASTAT(int prtFlag);



#endif
