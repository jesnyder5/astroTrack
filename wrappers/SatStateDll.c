// This wrapper file was generated automatically by the GenDllWrappers program.

#include "../services/DllUtils.h"
#include "SatStateDll.h"


// SatStateDll's function pointers definition
fnPtrSatStateInit                   SatStateInit;
fnPtrSatStateGetInfo                SatStateGetInfo;
fnPtrSatStateLoadFile               SatStateLoadFile;
fnPtrSatStateSaveFile               SatStateSaveFile;
fnPtrSatStateRemoveSat              SatStateRemoveSat;
fnPtrSatStateRemoveSatAll           SatStateRemoveSatAll;
fnPtrSatStateRemoveAllSats          SatStateRemoveAllSats;
fnPtrSatStateReset                  SatStateReset;
fnPtrSatStateGetCount               SatStateGetCount;
fnPtrSatStateGetLoaded              SatStateGetLoaded;
fnPtrSatStateNumToKey               SatStateNumToKey;
fnPtrSatStateGetSatDataAll          SatStateGetSatDataAll;
fnPtrSatStateGetSatDataField        SatStateGetSatDataField;
fnPtrSatStateInitSat                SatStateInitSat;
fnPtrSatStateMse                    SatStateMse;
fnPtrSatStateDs50UTC                SatStateDs50UTC;
fnPtrSatStateGetPropOut             SatStateGetPropOut;
fnPtrSatStateEphCom                 SatStateEphCom;
fnPtrSatStateEphCom_OS              SatStateEphCom_OS;
fnPtrSatStateHasCovMtx              SatStateHasCovMtx;
fnPtrSatStateGetCovUVW              SatStateGetCovUVW;
fnPtrSatStateGenEphFile             SatStateGenEphFile;


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSatStateDll()
{
   // Explicitly load the dll
   hLib = LoadLib(SatStateDll);


   // Assign function pointers to the appropriate dll functions
   SatStateInit = (fnPtrSatStateInit)GetFnPtr(hLib, (char*)"SatStateInit");
   SatStateGetInfo = (fnPtrSatStateGetInfo)GetFnPtr(hLib, (char*)"SatStateGetInfo");
   SatStateLoadFile = (fnPtrSatStateLoadFile)GetFnPtr(hLib, (char*)"SatStateLoadFile");
   SatStateSaveFile = (fnPtrSatStateSaveFile)GetFnPtr(hLib, (char*)"SatStateSaveFile");
   SatStateRemoveSat = (fnPtrSatStateRemoveSat)GetFnPtr(hLib, (char*)"SatStateRemoveSat");
   SatStateRemoveSatAll = (fnPtrSatStateRemoveSatAll)GetFnPtr(hLib, (char*)"SatStateRemoveSatAll");
   SatStateRemoveAllSats = (fnPtrSatStateRemoveAllSats)GetFnPtr(hLib, (char*)"SatStateRemoveAllSats");
   SatStateReset = (fnPtrSatStateReset)GetFnPtr(hLib, (char*)"SatStateReset");
   SatStateGetCount = (fnPtrSatStateGetCount)GetFnPtr(hLib, (char*)"SatStateGetCount");
   SatStateGetLoaded = (fnPtrSatStateGetLoaded)GetFnPtr(hLib, (char*)"SatStateGetLoaded");
   SatStateNumToKey = (fnPtrSatStateNumToKey)GetFnPtr(hLib, (char*)"SatStateNumToKey");
   SatStateGetSatDataAll = (fnPtrSatStateGetSatDataAll)GetFnPtr(hLib, (char*)"SatStateGetSatDataAll");
   SatStateGetSatDataField = (fnPtrSatStateGetSatDataField)GetFnPtr(hLib, (char*)"SatStateGetSatDataField");
   SatStateInitSat = (fnPtrSatStateInitSat)GetFnPtr(hLib, (char*)"SatStateInitSat");
   SatStateMse = (fnPtrSatStateMse)GetFnPtr(hLib, (char*)"SatStateMse");
   SatStateDs50UTC = (fnPtrSatStateDs50UTC)GetFnPtr(hLib, (char*)"SatStateDs50UTC");
   SatStateGetPropOut = (fnPtrSatStateGetPropOut)GetFnPtr(hLib, (char*)"SatStateGetPropOut");
   SatStateEphCom = (fnPtrSatStateEphCom)GetFnPtr(hLib, (char*)"SatStateEphCom");
   SatStateEphCom_OS = (fnPtrSatStateEphCom_OS)GetFnPtr(hLib, (char*)"SatStateEphCom_OS");
   SatStateHasCovMtx = (fnPtrSatStateHasCovMtx)GetFnPtr(hLib, (char*)"SatStateHasCovMtx");
   SatStateGetCovUVW = (fnPtrSatStateGetCovUVW)GetFnPtr(hLib, (char*)"SatStateGetCovUVW");
   SatStateGenEphFile = (fnPtrSatStateGenEphFile)GetFnPtr(hLib, (char*)"SatStateGenEphFile");
}



// Free SatStateDll
void FreeSatStateDll()
{
   FreeLib(hLib, SatStateDll);
}
// ========================= End of auto generated code ==========================
