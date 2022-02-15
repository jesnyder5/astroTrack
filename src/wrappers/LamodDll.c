// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/LamodDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadLamodDll()
{
   // Explicitly load the dll
   hLib = LoadLib(LamodDll);


   // Assign function pointers to the appropriate dll functions
   LamodInit = (fnPtrLamodInit)GetFnPtr(hLib, (char*)"LamodInit");
   LamodGetInfo = (fnPtrLamodGetInfo)GetFnPtr(hLib, (char*)"LamodGetInfo");
   LamodLoadFile = (fnPtrLamodLoadFile)GetFnPtr(hLib, (char*)"LamodLoadFile");
   LamodLoadFileAll = (fnPtrLamodLoadFileAll)GetFnPtr(hLib, (char*)"LamodLoadFileAll");
   LamodLoadCard = (fnPtrLamodLoadCard)GetFnPtr(hLib, (char*)"LamodLoadCard");
   LamodSaveFile = (fnPtrLamodSaveFile)GetFnPtr(hLib, (char*)"LamodSaveFile");
   LamodGetNumOfSensSats = (fnPtrLamodGetNumOfSensSats)GetFnPtr(hLib, (char*)"LamodGetNumOfSensSats");
   LamodGetSenNums = (fnPtrLamodGetSenNums)GetFnPtr(hLib, (char*)"LamodGetSenNums");
   LamodGetSatNums = (fnPtrLamodGetSatNums)GetFnPtr(hLib, (char*)"LamodGetSatNums");
   LamodGet1pCard = (fnPtrLamodGet1pCard)GetFnPtr(hLib, (char*)"LamodGet1pCard");
   LamodGet1pAll = (fnPtrLamodGet1pAll)GetFnPtr(hLib, (char*)"LamodGet1pAll");
   LamodSet1pAll = (fnPtrLamodSet1pAll)GetFnPtr(hLib, (char*)"LamodSet1pAll");
   LamodGet1pField = (fnPtrLamodGet1pField)GetFnPtr(hLib, (char*)"LamodGet1pField");
   LamodSet1pField = (fnPtrLamodSet1pField)GetFnPtr(hLib, (char*)"LamodSet1pField");
   LamodGet3pAll = (fnPtrLamodGet3pAll)GetFnPtr(hLib, (char*)"LamodGet3pAll");
   LamodSet3pAll = (fnPtrLamodSet3pAll)GetFnPtr(hLib, (char*)"LamodSet3pAll");
   LamodGetObsFileName = (fnPtrLamodGetObsFileName)GetFnPtr(hLib, (char*)"LamodGetObsFileName");
   LamodSetObsFileName = (fnPtrLamodSetObsFileName)GetFnPtr(hLib, (char*)"LamodSetObsFileName");
   LamodSenSatVisible = (fnPtrLamodSenSatVisible)GetFnPtr(hLib, (char*)"LamodSenSatVisible");
   LamodInitSenSat = (fnPtrLamodInitSenSat)GetFnPtr(hLib, (char*)"LamodInitSenSat");
   LamodInitSenSat_MT = (fnPtrLamodInitSenSat_MT)GetFnPtr(hLib, (char*)"LamodInitSenSat_MT");
   LamodGetSenSatDataAll = (fnPtrLamodGetSenSatDataAll)GetFnPtr(hLib, (char*)"LamodGetSenSatDataAll");
   LamodGetSenSatDataField = (fnPtrLamodGetSenSatDataField)GetFnPtr(hLib, (char*)"LamodGetSenSatDataField");
   LamodSenSatDataToArray = (fnPtrLamodSenSatDataToArray)GetFnPtr(hLib, (char*)"LamodSenSatDataToArray");
   LamodGetNumPasses = (fnPtrLamodGetNumPasses)GetFnPtr(hLib, (char*)"LamodGetNumPasses");
   LamodGetRiseCulmSetTimes = (fnPtrLamodGetRiseCulmSetTimes)GetFnPtr(hLib, (char*)"LamodGetRiseCulmSetTimes");
   LamodComputeLookAngle = (fnPtrLamodComputeLookAngle)GetFnPtr(hLib, (char*)"LamodComputeLookAngle");
   LamodComputeLookView = (fnPtrLamodComputeLookView)GetFnPtr(hLib, (char*)"LamodComputeLookView");
   LamodFindExactIOTime = (fnPtrLamodFindExactIOTime)GetFnPtr(hLib, (char*)"LamodFindExactIOTime");
   LamodGetOrbSenViewdata = (fnPtrLamodGetOrbSenViewdata)GetFnPtr(hLib, (char*)"LamodGetOrbSenViewdata");
   LamodGetViewDataField = (fnPtrLamodGetViewDataField)GetFnPtr(hLib, (char*)"LamodGetViewDataField");
   LamodCompRaDec = (fnPtrLamodCompRaDec)GetFnPtr(hLib, (char*)"LamodCompRaDec");
   LamodGenObs = (fnPtrLamodGenObs)GetFnPtr(hLib, (char*)"LamodGenObs");
   LamodGenObsAtTime = (fnPtrLamodGenObsAtTime)GetFnPtr(hLib, (char*)"LamodGenObsAtTime");
   LamodRemoveSenSat = (fnPtrLamodRemoveSenSat)GetFnPtr(hLib, (char*)"LamodRemoveSenSat");
   LamodRemoveAllSenSats = (fnPtrLamodRemoveAllSenSats)GetFnPtr(hLib, (char*)"LamodRemoveAllSenSats");
   LamodReset = (fnPtrLamodReset)GetFnPtr(hLib, (char*)"LamodReset");
}



// Free LamodDll
void FreeLamodDll()
{
   FreeLib(hLib, LamodDll);
}
// ========================= End of auto generated code ==========================
