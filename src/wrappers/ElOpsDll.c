// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/ElOpsDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadElOpsDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ElOpsDll);


   // Assign function pointers to the appropriate dll functions
   ElOpsInit = (fnPtrElOpsInit)GetFnPtr(hLib, (char*)"ElOpsInit");
   ElOpsGetInfo = (fnPtrElOpsGetInfo)GetFnPtr(hLib, (char*)"ElOpsGetInfo");
   IsGeoOrbit = (fnPtrIsGeoOrbit)GetFnPtr(hLib, (char*)"IsGeoOrbit");
   CompLonEastSubPt = (fnPtrCompLonEastSubPt)GetFnPtr(hLib, (char*)"CompLonEastSubPt");
   FindSatDecayTime = (fnPtrFindSatDecayTime)GetFnPtr(hLib, (char*)"FindSatDecayTime");
   GetSatParameters = (fnPtrGetSatParameters)GetFnPtr(hLib, (char*)"GetSatParameters");
   SatNumOf = (fnPtrSatNumOf)GetFnPtr(hLib, (char*)"SatNumOf");
}



// Free ElOpsDll
void FreeElOpsDll()
{
   FreeLib(hLib, ElOpsDll);
}
// ========================= End of auto generated code ==========================
