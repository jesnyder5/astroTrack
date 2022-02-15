#include "services/DllUtils.h"
#include "services/DllMainDll_Service.h"
#include "services/SensorDll_Service.h"

#include "wrappers/DllMainDll.h"
#include "wrappers/SensorDll.h"


// Retrieve Sensor location/limits data from the dll
int GetSensorData(int senKey, SensorLocation* senLoc, SensorLimits1L* senLim1L, SensorLimits2L* senLim2L)
{
   int errCode;

   errCode = GetSensorLocation(senKey, senLoc);
   if(errCode != 0)
      return errCode;

   errCode = GetSensorLimits1L(senKey, senLim1L);
   if(errCode != 0)
      return errCode;
   
   errCode = GetSensorLimits2L(senKey, senLim2L);
   if(errCode != 0)
      return errCode;

   return errCode;
}

// Retrieve Sensor location data from the dll
int GetSensorLocation(int senKey, SensorLocation* senLoc)
{
   double astroLat, astroLon;
   double senPos[3];
   char   senDesc[25];
   int    orbSatNum;
   char   secClass;

   int    errCode;

   // Retrieve sensor location data from the dll
   errCode = SensorGetLocAll(senKey, &astroLat, &astroLon, senPos, senDesc, &orbSatNum, &secClass);
   if (errCode != 0)
   {
      //ShowMsgAndTerminate();
      ShowErrMsg();
      return errCode;
   }
   
   senLoc->senNum = senKey;
   senLoc->astroLat = astroLat;
   senLoc->astroLon = astroLon;
   memcpy(senLoc->senPos, senPos, sizeof(senPos));
   senDesc[24] = 0;
   strcpy(senLoc->senDesc, senDesc);
   senLoc->orbSatNum = orbSatNum;
   senLoc->secClass = secClass;

   return errCode;
}

// Retrieve Sensor limits (1L-Card) data from the dll
int GetSensorLimits1L(int senKey, SensorLimits1L* senLim1L)
{
   char     viewType, obsType, boresight1;
   int      rngUnits, visFlg, rngLimFlg, maxPPP, plntryRes;
   double   interval, maxRngLim, elLim1, elLim2, azLim1, azLim2, minRngLim, rrLim;

   int    errCode;

   // Retrieve sensor limits data (1L-Card) from the dll
   errCode = SensorGet1L(senKey, &viewType, &obsType, &rngUnits, &maxRngLim,
                         &boresight1, &elLim1, &elLim2, &azLim1, &azLim2,
                         &interval, &visFlg, &rngLimFlg, &maxPPP, &minRngLim,
                         &plntryRes, &rrLim);
   if (errCode != 0)
   {
      //ShowMsgAndTerminate();
      ShowErrMsg();
      return errCode;
   }
   
   senLim1L->senNum     = senKey;
   senLim1L->viewType   = viewType;
   senLim1L->obsType    = obsType;
   senLim1L->rngUnits   = rngUnits;
   senLim1L->maxRngLim  = maxRngLim;
   senLim1L->boresight1 = boresight1;
   senLim1L->elLim1     = elLim1;
   senLim1L->elLim2     = elLim2;
   senLim1L->azLim1     = azLim1;
   senLim1L->azLim2     = azLim2;
   senLim1L->interval   = interval;
   senLim1L->visFlg     = visFlg;
   senLim1L->rngLimFlg  = rngLimFlg;
   senLim1L->maxPPP     = maxPPP;
   senLim1L->minRngLim  = minRngLim;
   senLim1L->plntryRes  = plntryRes;
   senLim1L->rrLim      = rrLim;

   return errCode;
}


// Retrieve Sensor limits (2L-Card) data from the dll
int GetSensorLimits2L(int senKey, SensorLimits2L* senLim2L)
{
   char     boresight2;  
   int      earthBckgrnd;
   double   elLim3, elLim4, azLim3, azLim4, earthLimb, solarXAngle, lunarXAngle, minIlum, twilit;

   int      errCode;

   // Retrieve sensor limits data (2L-Card) from the dll
   errCode = SensorGet2L(senKey, &boresight2, &elLim3, &elLim4,
                         &azLim3, &azLim4, &earthBckgrnd, &earthLimb,
                         &solarXAngle, &lunarXAngle, &minIlum, &twilit);
   if (errCode != 0)
   {
      //ShowMsgAndTerminate();
      ShowErrMsg();
      return errCode;
   }
   
   senLim2L->senNum        = senKey;
   senLim2L->boresight2    = boresight2;
   senLim2L->elLim3        = elLim3;
   senLim2L->elLim4        = elLim4;
   senLim2L->azLim3        = azLim3;
   senLim2L->azLim4        = azLim4;
   senLim2L->earthBckgrnd  = earthBckgrnd;
   senLim2L->earthLimb     = earthLimb;
   senLim2L->solarXAngle   = solarXAngle;
   senLim2L->lunarXAngle   = lunarXAngle;
   senLim2L->minIlum       = minIlum;
   senLim2L->twilit        = twilit;

   return errCode;
}

// Return a string representing the viewType
const char* GetViewTypeStr(char viewType)
{
   if (viewType == '0')
      return "0- Constant Elevation";
   else if (viewType == '1')
      return "1- Non-const elevation fan";
   else if (viewType == '2')
      return "2- Bounded-cone tracker";
   else if (viewType == '3')
      return "3- Conventional tracker";
   else if (viewType == '4')
      return "4- Optical tracker";
   else if (viewType == '5')
      return "5- General fan defined by 2 unit vectors";
   else if (viewType == '6')
      return "6- Const AZ fan sweeping to vertical";
   else if (viewType == '7')
      return "7- Const AZ fan sweeping vertical plane";
   else if (viewType == '9')
      return "9- Orbiting sensor";
   else if (viewType == 'R')
      return "R- Space fence FoR";
   else if (viewType == 'V')
      return "V- Space fence detection fence";
   else
      return " ";
}

// Return a string representing the obsType
const char* GetObsTypeStr(char obsType)
{
   if (obsType == '0')
      return "0- Range-rate only";
   else if (obsType == '1')
      return "1- Az, El";
   else if (obsType == '2')
      return "2- Az, El, Rng";
   else if (obsType == '3')
      return "3- Az, El, Rng, Rng Rate";
   else if (obsType == '4')
      return "4- 3 + Az Rate + El Rate";
   else if (obsType == '5')
      return "5- RA, DEC";
   else if (obsType == '6')
      return "6- Range only";
   else if (obsType == '7')
      return "7- Rotating EFG vector";
   else if (obsType == '8')
      return "8- Az, El, sen rotate EFG";
   else if (obsType == '9')
      return "9- RA, DEC, sen rotate EFG";
   else if (obsType == 'V')
      return "V- ECI position/velocity vec";
   else if (obsType == 'P')
      return "P- ECI position vec";
   else if (obsType == 'M')
      return "M- Az, El, sen rotate EFG + Rng";
   else if (obsType == 'O')
      return "O- RA, DEC, sen rotate EFG + Rng";
   else
      return " ";
}

// Return a string representing the boresight vector
const char* GetSenBoreVecStr(char boreVec)
{
   if (boreVec == ' ')
      return "No Limits";
   else if (boreVec == 'D')
      return "D- Down";
   else if (boreVec == 'U')
      return "U- Up";
   else if (boreVec == 'B')
      return "B- Back";
   else if (boreVec == 'A')
      return "A- Ahead";
   else if (boreVec == 'R')
      return "R- Right";
   else if (boreVec == 'L')
      return "L- Left";
   else 
      return " ";
}



// Print sensor's limits data
int PrintSensorData(FILE* fp, int senKey)
{
   char unitStr[2][11] = { "km, km/sec", "nm, nm/sec" };
   char noYes[3][4] = { "no", "yes", "yes" };

   char dashLine[] = "-------------------------------------------------------------------------------";
   char ddashLine[] = "===============================================================================";

   char* lim1Str;
   char* lim2Str;

   int errCode;
   char valueStr[GETSETSTRLEN];
   char fileName[44];
   int segNum, segType, numOfSegs;
   double xa_seg[16];


   SensorLocation senLoc;
   SensorLimits1L senLim1L;
   SensorLimits2L senLim2L;


   errCode = GetSensorData(senKey, &senLoc, &senLim1L, &senLim2L);
   if (errCode != 0)
   {
      WriteErrMsg(fp);
      return errCode;
   }

   lim1Str = "ELEVATION";
   lim2Str = " AZIMUTH ";

   fprintf(fp, " %s\n", ddashLine);
   if (senLim1L.viewType == '9') // orbiting sensor
   {
      fprintf(fp, " |                ORBITNG SENSOR %3d (SATELLITE %5d) DATA                    |\n", senKey, senLoc.orbSatNum);
      if (senLim1L.boresight1 > 0)
      {
         lim1Str = "OFF-BORST";
         lim2Str = "CLOCK ANG";
      }
   }
   else
   {
      fprintf(fp, " |                               SENSOR %3d DATA                               |\n", senKey);
      fprintf(fp, " %s\n", dashLine);
      fprintf(fp, " |  SENSOR LOCATION                                                            |\n");
      fprintf(fp, " |  ASTRONOMICAL LAT  (deg): %9.4f%-41s|\n", senLoc.astroLat, " ");
      fprintf(fp, " |  ASTRONOMICAL LONG (deg): %9.4f%-41s|\n", senLoc.astroLon, " ");
      fprintf(fp, " |  GEOCENTRIC ROT. X (m)  : %9.0f%-41s|\n", senLoc.senPos[0], " ");
      fprintf(fp, " |  GEOCENTRIC ROT. Y (m)  : %9.0f%-41s|\n", senLoc.senPos[1], " ");
      fprintf(fp, " |  GEOCENTRIC ROT. Z (m)  : %9.0f%-41s|\n", senLoc.senPos[2], " ");
   }

   fprintf(fp, " %s\n", dashLine);
   fprintf(fp, " |  SENSOR LIMITS                                                              |\n");
   fprintf(fp, " |  A.  SENSOR TYPE:                %-43s|\n", GetViewTypeStr(senLim1L.viewType));
   fprintf(fp, " |  B.  SENSOR OBSERVATION TYPE:    %-43s|\n", GetObsTypeStr(senLim1L.obsType));


   fprintf(fp, " |  C.  RANGE/RANGE-RATE UNITS:     %-43s|\n", unitStr[senLim1L.rngUnits]);
   fprintf(fp, " |  D.  APPLY RANGE CONSTRAINTS?    %-43s|\n", senLim1L.rngLimFlg == 0 ? "yes" : "no");
   if (senLim1L.rngLimFlg == 0)
      fprintf(fp, " |  E.  MIN/MAX OBSERVABLE RANGE:   %8.0f to%9.0f %-22s|\n", senLim1L.minRngLim, senLim1L.maxRngLim, senLim1L.rngUnits == 0 ? "km" : "nm");

   if (senLim1L.viewType == 'R')
   {
      SensorGetLimField(senKey, XF_SENLIM_FILE, valueStr);
      strncpy(fileName, valueStr, 43);
      fileName[43] = '\0';
      fprintf(fp, " |  F.  AZ/EL TABLE FILE NAME   :   %43s|\n", fileName);
   }
   else if (senLim1L.viewType == 'V')
   {
      fprintf(fp, " |  F.  N/S BEAMWIDTH ANGLE:        %8.3f%-35s|\n", senLim1L.elLim1, " deg");
      fprintf(fp, " |  G.  FENCE TILT ANGLE   :        %8.3f%-35s|\n", senLim1L.elLim2, " deg");
   }
   else if (senLim1L.viewType == '2')
   {
      if (senLim1L.azLim1 != 0 && senLim1L.azLim2 != 0 && senLim1L.elLim1 != 0 && senLim1L.elLim2 != 0)
      {
         fprintf(fp, " |  F.  BORESIGHT AZIMUTH  :        %8.3f%-35s|\n", senLim1L.azLim1, " deg");
         fprintf(fp, " |  G.  BORESIGHT ELEVATION:        %8.3f%-35s|\n", senLim1L.elLim1, " deg");
         fprintf(fp, " |  H.  OFF-BORESIGHT ANGLE:        %8.3f%-35s|\n", senLim1L.azLim2, " deg");
         fprintf(fp, " |  I.  MIN ELEVATION ANGLE:        %8.3f%-35s|\n", senLim1L.elLim2, " deg");
      }
   }
   else if (senLim1L.viewType != 'V')
   {
      fprintf(fp, " |  F.  FIRST  %s INTERVAL:  %8.3f to %8.3f%-23s|\n", lim1Str, senLim1L.elLim1, senLim1L.elLim2, " deg");
      fprintf(fp, " |  G.  FIRST  %s INTERVAL:  %8.3f to %8.3f%-23s|\n", lim2Str, senLim1L.azLim1, senLim1L.azLim2, " deg");
   }

   if (senLim1L.viewType == '9' && senLim2L.boresight2 == ' ') // no limit or n/a
   {
      fprintf(fp, " |  H.  SECOND %s INTERVAL:  %-43s|\n", lim1Str, "n/a");
      fprintf(fp, " |  I.  SECOND %s INTERVAL:  %-43s|\n", lim2Str, "n/a");
   }
   else if (senLim1L.viewType != '2' && senLim1L.viewType != '7' && senLim1L.viewType != 'R' && senLim1L.viewType != 'V')
   {
      fprintf(fp, " |  H.  SECOND %s INTERVAL:  %8.3f to %8.3f%-23s|\n", lim1Str, senLim2L.elLim3, senLim2L.elLim4, " deg");
      fprintf(fp, " |  I.  SECOND %s INTERVAL:  %8.3f to %8.3f%-23s|\n", lim2Str, senLim2L.azLim3, senLim2L.azLim4, " deg");
   }

   numOfSegs = GetKey32IntegerField((fnPtrGetKey32Field)SensorGetLimField, senKey, XF_SENLIM_NUMSEGS);
   if (numOfSegs > 0)
   {
      fprintf(fp, " |  ADDITIONAL SENSOR LIMITS  (via 3L-Card or call SensorAddSegments() API     |\n");
      fprintf(fp, " |  - DOME: Az fr/to (deg), El fr/to (deg), Range min/max (km)                 |\n");
      fprintf(fp, " |  - CONE: BS Az/El (deg), Angle fr/to (deg), Range min/max (km), min El (deg)|\n"); 
   }

   for (segNum = 1; segNum <= numOfSegs; segNum++)
   {
      errCode = SensorGetSegment(senKey, segNum, &segType, xa_seg);
      if (segType == SEG_DOME)
      {
         fprintf(fp, " |  %3d - DOME: %7.3f, %7.3f, %7.3f, %7.3f, %7.0f, %7.0f           |\n", segNum,
            xa_seg[0], xa_seg[1], xa_seg[2], xa_seg[3], xa_seg[4], xa_seg[5]);
      }
      else if (segType== SEG_BCONE)
      {
         fprintf(fp, " |  %3d - CONE: %7.3f, %7.3f, %7.3f, %7.3f, %7.0f, %7.0f, %7.3f  |\n", segNum,
            xa_seg[0], xa_seg[1], xa_seg[2], xa_seg[3], xa_seg[4], xa_seg[5], xa_seg[6]);
      }
   }

   fprintf(fp, " |  J.  NUMBER OF POINTS PER PASS:  %4d%39s|\n", senLim1L.maxPPP, " ");
   fprintf(fp, " |  K.  INTERVAL BETWEEN POINTS:    %8.3f%-35s|\n", senLim1L.interval, " min");
   fprintf(fp, " |      (Note: The Lamod's Output Inverval value takes precedence over this)   |\n");

   if (senLim1L.obsType == '5' || senLim1L.obsType == '9' || 
       senLim1L.obsType == 'O' || senLim1L.obsType == '1')
   {
      fprintf(fp, " |  L.  IR/OPTICAL VISIBILITY CK:   %-43s|\n", SenOptVisFlgStr[senLim1L.visFlg]);
      fprintf(fp, " |      (Note: The Lamod's Optical Visibility flag takes precedence over this) |\n");
   }
   else if (senLim1L.visFlg == 2 || senLim1L.visFlg == 3)
      fprintf(fp, " |  L.  APPLY SOLAR ASPECT ANGLE:   %-43s|\n", "yes");
   else
   {
      fprintf(fp, " |  L.  OPTICALLY VISIBLE OPTION:   %-43s|\n", "n/a");
      fprintf(fp, " |      (Note: The Lamod's Optical Visibility flag takes precedence over this) |\n");
   }

   fprintf(fp, " |  M.  RGE-RT/REL-VELOCITY LIMIT:  %8.3f%-35s|\n", senLim1L.rrLim, " k/s");
   if (senLim1L.viewType == '9')
   {
      fprintf(fp, " |  O.  PLANETARY RESTRICTIONS:     %-43s|\n", SenPlntryRstrtnStr[senLim1L.plntryRes]);
      if (senLim1L.plntryRes != 5)
      {
         fprintf(fp, " |  P.  ALLOW EARTH IN BACKGROUND?  %-43s|\n", noYes[senLim2L.earthBckgrnd]);
         fprintf(fp, " |  R.  EARTH LIMB EXCLUSION DIST.  %8.3f%-35s|\n", senLim2L.earthLimb,   " km");
         fprintf(fp, " |  S.  SOLAR EXCLUSION ANGLE:      %8.3f%-35s|\n", senLim2L.solarXAngle, " deg");
         fprintf(fp, " |  T.  LUNAR EXCLUSION ANGLE:      %8.3f%-35s|\n", senLim2L.lunarXAngle, " deg");
      }
      fprintf(fp, " |  U.  SENSOR BORESIGHT VECTOR 1:  %-43s|\n", GetSenBoreVecStr(senLim1L.boresight1));
      fprintf(fp, " |  V.  SENSOR BORESIGHT VECTOR 2:  %-43s|\n", GetSenBoreVecStr(senLim2L.boresight2));
      fprintf(fp, " |  W.  MIN ILLUMINATION ANGLE:     %8.3f %-34s|\n", senLim2L.minIlum, " ");
   }
   else
   {
      fprintf(fp, " |  X.  TWILIGHT OFFSET ANGLE:      %8.3f %-34s|\n", senLim2L.twilit, "deg below horizon");
   }
   fprintf(fp, " %s\n\n", dashLine);

   return errCode;

}

