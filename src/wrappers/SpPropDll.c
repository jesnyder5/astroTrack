// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/SpPropDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSpPropDll()
{
   // Explicitly load the dll
   hLib = LoadLib(SpPropDll);


   // Assign function pointers to the appropriate dll functions
   SpInit = (fnPtrSpInit)GetFnPtr(hLib, (char*)"SpInit");
   SpGetInfo = (fnPtrSpGetInfo)GetFnPtr(hLib, (char*)"SpGetInfo");
   SpLoadFile = (fnPtrSpLoadFile)GetFnPtr(hLib, (char*)"SpLoadFile");
   SpLoadFileAll = (fnPtrSpLoadFileAll)GetFnPtr(hLib, (char*)"SpLoadFileAll");
   SpSaveFile = (fnPtrSpSaveFile)GetFnPtr(hLib, (char*)"SpSaveFile");
   SpInitSat = (fnPtrSpInitSat)GetFnPtr(hLib, (char*)"SpInitSat");
   SpRemoveSat = (fnPtrSpRemoveSat)GetFnPtr(hLib, (char*)"SpRemoveSat");
   SpRemoveAllSats = (fnPtrSpRemoveAllSats)GetFnPtr(hLib, (char*)"SpRemoveAllSats");
   SpGetCount = (fnPtrSpGetCount)GetFnPtr(hLib, (char*)"SpGetCount");
   SpReset = (fnPtrSpReset)GetFnPtr(hLib, (char*)"SpReset");
   SpGetApCtrl = (fnPtrSpGetApCtrl)GetFnPtr(hLib, (char*)"SpGetApCtrl");
   SpGetApCtrlAll = (fnPtrSpGetApCtrlAll)GetFnPtr(hLib, (char*)"SpGetApCtrlAll");
   SpSetApCtrl = (fnPtrSpSetApCtrl)GetFnPtr(hLib, (char*)"SpSetApCtrl");
   SpSetApCtrlAll = (fnPtrSpSetApCtrlAll)GetFnPtr(hLib, (char*)"SpSetApCtrlAll");
   SpGet4P = (fnPtrSpGet4P)GetFnPtr(hLib, (char*)"SpGet4P");
   SpSet4P = (fnPtrSpSet4P)GetFnPtr(hLib, (char*)"SpSet4P");
   SpGetPredCtrl = (fnPtrSpGetPredCtrl)GetFnPtr(hLib, (char*)"SpGetPredCtrl");
   SpSetPredCtrl = (fnPtrSpSetPredCtrl)GetFnPtr(hLib, (char*)"SpSetPredCtrl");
   SpGetSatData = (fnPtrSpGetSatData)GetFnPtr(hLib, (char*)"SpGetSatData");
   SpGetSatDataAll = (fnPtrSpGetSatDataAll)GetFnPtr(hLib, (char*)"SpGetSatDataAll");
   SpPropMse = (fnPtrSpPropMse)GetFnPtr(hLib, (char*)"SpPropMse");
   SpPropDs50UTC = (fnPtrSpPropDs50UTC)GetFnPtr(hLib, (char*)"SpPropDs50UTC");
   SpPropDs50UtcLLH = (fnPtrSpPropDs50UtcLLH)GetFnPtr(hLib, (char*)"SpPropDs50UtcLLH");
   SpPropDs50UtcPos = (fnPtrSpPropDs50UtcPos)GetFnPtr(hLib, (char*)"SpPropDs50UtcPos");
   SpPropAll = (fnPtrSpPropAll)GetFnPtr(hLib, (char*)"SpPropAll");
   SpGetStateDs50UTC = (fnPtrSpGetStateDs50UTC)GetFnPtr(hLib, (char*)"SpGetStateDs50UTC");
   SpSetStateDs50UTC = (fnPtrSpSetStateDs50UTC)GetFnPtr(hLib, (char*)"SpSetStateDs50UTC");
   SpSetAndProp = (fnPtrSpSetAndProp)GetFnPtr(hLib, (char*)"SpSetAndProp");
   SpGetPropOut = (fnPtrSpGetPropOut)GetFnPtr(hLib, (char*)"SpGetPropOut");
   SpGetCovMtx = (fnPtrSpGetCovMtx)GetFnPtr(hLib, (char*)"SpGetCovMtx");
   SpCompCovSigma = (fnPtrSpCompCovSigma)GetFnPtr(hLib, (char*)"SpCompCovSigma");
   SpSet4pAll = (fnPtrSpSet4pAll)GetFnPtr(hLib, (char*)"SpSet4pAll");
   SpGet4pAll = (fnPtrSpGet4pAll)GetFnPtr(hLib, (char*)"SpGet4pAll");
   SpSet4PCard = (fnPtrSpSet4PCard)GetFnPtr(hLib, (char*)"SpSet4PCard");
   SpGet4PCard = (fnPtrSpGet4PCard)GetFnPtr(hLib, (char*)"SpGet4PCard");
   SpAddFluxRec = (fnPtrSpAddFluxRec)GetFnPtr(hLib, (char*)"SpAddFluxRec");
   SpGetEphemTimes = (fnPtrSpGetEphemTimes)GetFnPtr(hLib, (char*)"SpGetEphemTimes");
}



// Free SpPropDll
void FreeSpPropDll()
{
   FreeLib(hLib, SpPropDll);
}
// ========================= End of auto generated code ==========================
