// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/RotasDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadRotasDll()
{
   // Explicitly load the dll
   hLib = LoadLib(RotasDll);


   // Assign function pointers to the appropriate dll functions
   RotasInit = (fnPtrRotasInit)GetFnPtr(hLib, (char*)"RotasInit");
   RotasGetInfo = (fnPtrRotasGetInfo)GetFnPtr(hLib, (char*)"RotasGetInfo");
   RotasLoadFile = (fnPtrRotasLoadFile)GetFnPtr(hLib, (char*)"RotasLoadFile");
   RotasLoadFileAll = (fnPtrRotasLoadFileAll)GetFnPtr(hLib, (char*)"RotasLoadFileAll");
   RotasLoadCard = (fnPtrRotasLoadCard)GetFnPtr(hLib, (char*)"RotasLoadCard");
   RotasSaveFile = (fnPtrRotasSaveFile)GetFnPtr(hLib, (char*)"RotasSaveFile");
   RotasGetPCard = (fnPtrRotasGetPCard)GetFnPtr(hLib, (char*)"RotasGetPCard");
   RotasGetPAll = (fnPtrRotasGetPAll)GetFnPtr(hLib, (char*)"RotasGetPAll");
   RotasSetPAll = (fnPtrRotasSetPAll)GetFnPtr(hLib, (char*)"RotasSetPAll");
   RotasGetPField = (fnPtrRotasGetPField)GetFnPtr(hLib, (char*)"RotasGetPField");
   RotasSetPField = (fnPtrRotasSetPField)GetFnPtr(hLib, (char*)"RotasSetPField");
   RotasGetAssocMultipliers = (fnPtrRotasGetAssocMultipliers)GetFnPtr(hLib, (char*)"RotasGetAssocMultipliers");
   RotasSetAssocMultipliers = (fnPtrRotasSetAssocMultipliers)GetFnPtr(hLib, (char*)"RotasSetAssocMultipliers");
   RotasResetAll = (fnPtrRotasResetAll)GetFnPtr(hLib, (char*)"RotasResetAll");
   RotasHasASTAT = (fnPtrRotasHasASTAT)GetFnPtr(hLib, (char*)"RotasHasASTAT");
   RotasHasASTAT_MT = (fnPtrRotasHasASTAT_MT)GetFnPtr(hLib, (char*)"RotasHasASTAT_MT");
   RotasComputeObsResiduals = (fnPtrRotasComputeObsResiduals)GetFnPtr(hLib, (char*)"RotasComputeObsResiduals");
   RotasComputeObsResiduals_MT = (fnPtrRotasComputeObsResiduals_MT)GetFnPtr(hLib, (char*)"RotasComputeObsResiduals_MT");
   RotasComputeTrackResiduals = (fnPtrRotasComputeTrackResiduals)GetFnPtr(hLib, (char*)"RotasComputeTrackResiduals");
   RotasCompObResDirect = (fnPtrRotasCompObResDirect)GetFnPtr(hLib, (char*)"RotasCompObResDirect");
   RotasGetRetagObsFile = (fnPtrRotasGetRetagObsFile)GetFnPtr(hLib, (char*)"RotasGetRetagObsFile");
   RotasSetRetagObsFile = (fnPtrRotasSetRetagObsFile)GetFnPtr(hLib, (char*)"RotasSetRetagObsFile");
}



// Free RotasDll
void FreeRotasDll()
{
   FreeLib(hLib, RotasDll);
}
// ========================= End of auto generated code ==========================
