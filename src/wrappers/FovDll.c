// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/FovDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadFovDll()
{
   // Explicitly load the dll
   hLib = LoadLib(FovDll);


   // Assign function pointers to the appropriate dll functions
   FovInit = (fnPtrFovInit)GetFnPtr(hLib, (char*)"FovInit");
   FovGetInfo = (fnPtrFovGetInfo)GetFnPtr(hLib, (char*)"FovGetInfo");
   FovLoadFile = (fnPtrFovLoadFile)GetFnPtr(hLib, (char*)"FovLoadFile");
   FovLoadFileAll = (fnPtrFovLoadFileAll)GetFnPtr(hLib, (char*)"FovLoadFileAll");
   FovLoadCard = (fnPtrFovLoadCard)GetFnPtr(hLib, (char*)"FovLoadCard");
   FovSaveFile = (fnPtrFovSaveFile)GetFnPtr(hLib, (char*)"FovSaveFile");
   FovGetDataFrInputFiles = (fnPtrFovGetDataFrInputFiles)GetFnPtr(hLib, (char*)"FovGetDataFrInputFiles");
   FovFindTargetPasses = (fnPtrFovFindTargetPasses)GetFnPtr(hLib, (char*)"FovFindTargetPasses");
   FovTargetElset = (fnPtrFovTargetElset)GetFnPtr(hLib, (char*)"FovTargetElset");
   FovTargetElsetLook = (fnPtrFovTargetElsetLook)GetFnPtr(hLib, (char*)"FovTargetElsetLook");
   FovTargetVec = (fnPtrFovTargetVec)GetFnPtr(hLib, (char*)"FovTargetVec");
   FovTargetVecLook = (fnPtrFovTargetVecLook)GetFnPtr(hLib, (char*)"FovTargetVecLook");
   FovReset = (fnPtrFovReset)GetFnPtr(hLib, (char*)"FovReset");
}



// Free FovDll
void FreeFovDll()
{
   FreeLib(hLib, FovDll);
}
// ========================= End of auto generated code ==========================
