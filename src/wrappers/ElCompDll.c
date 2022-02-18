// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/ElCompDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadElCompDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ElCompDll);


   // Assign function pointers to the appropriate dll functions
   ElCompInit = (fnPtrElCompInit)GetFnPtr(hLib, (char*)"ElCompInit");
   ElCompGetInfo = (fnPtrElCompGetInfo)GetFnPtr(hLib, (char*)"ElCompGetInfo");
   ElCompSetCriteria = (fnPtrElCompSetCriteria)GetFnPtr(hLib, (char*)"ElCompSetCriteria");
   ElCompGetCriteria = (fnPtrElCompGetCriteria)GetFnPtr(hLib, (char*)"ElCompGetCriteria");
   ElCompGetResults = (fnPtrElCompGetResults)GetFnPtr(hLib, (char*)"ElCompGetResults");
   ElCompFrElData = (fnPtrElCompFrElData)GetFnPtr(hLib, (char*)"ElCompFrElData");
   ElCompResetCriteria = (fnPtrElCompResetCriteria)GetFnPtr(hLib, (char*)"ElCompResetCriteria");
   CocoSetCriteria = (fnPtrCocoSetCriteria)GetFnPtr(hLib, (char*)"CocoSetCriteria");
   CocoGetCriteria = (fnPtrCocoGetCriteria)GetFnPtr(hLib, (char*)"CocoGetCriteria");
   CocoGetResults = (fnPtrCocoGetResults)GetFnPtr(hLib, (char*)"CocoGetResults");
   CocoGetResultsWOA = (fnPtrCocoGetResultsWOA)GetFnPtr(hLib, (char*)"CocoGetResultsWOA");
   CocoFrElData = (fnPtrCocoFrElData)GetFnPtr(hLib, (char*)"CocoFrElData");
   CocoFrElDataWOA = (fnPtrCocoFrElDataWOA)GetFnPtr(hLib, (char*)"CocoFrElDataWOA");
   CocoResetCriteria = (fnPtrCocoResetCriteria)GetFnPtr(hLib, (char*)"CocoResetCriteria");
}



// Free ElCompDll
void FreeElCompDll()
{
   FreeLib(hLib, ElCompDll);
}
// ========================= End of auto generated code ==========================