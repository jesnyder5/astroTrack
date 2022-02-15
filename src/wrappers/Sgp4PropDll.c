// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/Sgp4PropDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSgp4PropDll()
{
   // Explicitly load the dll
   hLib = LoadLib(Sgp4PropDll);


   // Assign function pointers to the appropriate dll functions
   Sgp4Init = (fnPtrSgp4Init)GetFnPtr(hLib, (char*)"Sgp4Init");
   Sgp4GetInfo = (fnPtrSgp4GetInfo)GetFnPtr(hLib, (char*)"Sgp4GetInfo");
   Sgp4InitSat = (fnPtrSgp4InitSat)GetFnPtr(hLib, (char*)"Sgp4InitSat");
   Sgp4RemoveSat = (fnPtrSgp4RemoveSat)GetFnPtr(hLib, (char*)"Sgp4RemoveSat");
   Sgp4RemoveAllSats = (fnPtrSgp4RemoveAllSats)GetFnPtr(hLib, (char*)"Sgp4RemoveAllSats");
   Sgp4GetCount = (fnPtrSgp4GetCount)GetFnPtr(hLib, (char*)"Sgp4GetCount");
   Sgp4PropMse = (fnPtrSgp4PropMse)GetFnPtr(hLib, (char*)"Sgp4PropMse");
   Sgp4PropDs50UTC = (fnPtrSgp4PropDs50UTC)GetFnPtr(hLib, (char*)"Sgp4PropDs50UTC");
   Sgp4PropDs50UtcPosVel = (fnPtrSgp4PropDs50UtcPosVel)GetFnPtr(hLib, (char*)"Sgp4PropDs50UtcPosVel");
   Sgp4PropDs50UtcLLH = (fnPtrSgp4PropDs50UtcLLH)GetFnPtr(hLib, (char*)"Sgp4PropDs50UtcLLH");
   Sgp4PropDs50UtcPos = (fnPtrSgp4PropDs50UtcPos)GetFnPtr(hLib, (char*)"Sgp4PropDs50UtcPos");
   Sgp4GetPropOut = (fnPtrSgp4GetPropOut)GetFnPtr(hLib, (char*)"Sgp4GetPropOut");
   Sgp4PropAll = (fnPtrSgp4PropAll)GetFnPtr(hLib, (char*)"Sgp4PropAll");
   Sgp4PosVelToKep = (fnPtrSgp4PosVelToKep)GetFnPtr(hLib, (char*)"Sgp4PosVelToKep");
   Sgp4PosVelToTleArr = (fnPtrSgp4PosVelToTleArr)GetFnPtr(hLib, (char*)"Sgp4PosVelToTleArr");
   Sgp4ReepochTLE = (fnPtrSgp4ReepochTLE)GetFnPtr(hLib, (char*)"Sgp4ReepochTLE");
   Sgp4ReepochCsv = (fnPtrSgp4ReepochCsv)GetFnPtr(hLib, (char*)"Sgp4ReepochCsv");
   Sgp4SetLicFilePath = (fnPtrSgp4SetLicFilePath)GetFnPtr(hLib, (char*)"Sgp4SetLicFilePath");
   Sgp4GetLicFilePath = (fnPtrSgp4GetLicFilePath)GetFnPtr(hLib, (char*)"Sgp4GetLicFilePath");
   Sgp4GenEphems = (fnPtrSgp4GenEphems)GetFnPtr(hLib, (char*)"Sgp4GenEphems");
   Sgp4GenEphems_OS = (fnPtrSgp4GenEphems_OS)GetFnPtr(hLib, (char*)"Sgp4GenEphems_OS");
   Sgp4PropAllSats = (fnPtrSgp4PropAllSats)GetFnPtr(hLib, (char*)"Sgp4PropAllSats");
}



// Free Sgp4PropDll
void FreeSgp4PropDll()
{
   FreeLib(hLib, Sgp4PropDll);
}
// ========================= End of auto generated code ==========================
