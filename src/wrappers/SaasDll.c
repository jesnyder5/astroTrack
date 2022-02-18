// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/SaasDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSaasDll()
{
   // Explicitly load the dll
   hLib = LoadLib(SaasDll);


   // Assign function pointers to the appropriate dll functions
   SaasInit = (fnPtrSaasInit)GetFnPtr(hLib, (char*)"SaasInit");
   SaasGetInfo = (fnPtrSaasGetInfo)GetFnPtr(hLib, (char*)"SaasGetInfo");
   SaasGetResults = (fnPtrSaasGetResults)GetFnPtr(hLib, (char*)"SaasGetResults");
   SaasAutoConeSize = (fnPtrSaasAutoConeSize)GetFnPtr(hLib, (char*)"SaasAutoConeSize");
   SaasMissileFlightTime = (fnPtrSaasMissileFlightTime)GetFnPtr(hLib, (char*)"SaasMissileFlightTime");
   ComputeLnchOrbPlane = (fnPtrComputeLnchOrbPlane)GetFnPtr(hLib, (char*)"ComputeLnchOrbPlane");
   FindPlanerIntersection = (fnPtrFindPlanerIntersection)GetFnPtr(hLib, (char*)"FindPlanerIntersection");
}



// Free SaasDll
void FreeSaasDll()
{
   FreeLib(hLib, SaasDll);
}
// ========================= End of auto generated code ==========================