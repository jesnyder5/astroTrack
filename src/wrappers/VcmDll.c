// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/VcmDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadVcmDll()
{
   // Explicitly load the dll
   hLib = LoadLib(VcmDll);


   // Assign function pointers to the appropriate dll functions
   VcmInit = (fnPtrVcmInit)GetFnPtr(hLib, (char*)"VcmInit");
   VcmGetInfo = (fnPtrVcmGetInfo)GetFnPtr(hLib, (char*)"VcmGetInfo");
   VcmLoadFile = (fnPtrVcmLoadFile)GetFnPtr(hLib, (char*)"VcmLoadFile");
   VcmSaveFile = (fnPtrVcmSaveFile)GetFnPtr(hLib, (char*)"VcmSaveFile");
   VcmRemoveSat = (fnPtrVcmRemoveSat)GetFnPtr(hLib, (char*)"VcmRemoveSat");
   VcmRemoveAllSats = (fnPtrVcmRemoveAllSats)GetFnPtr(hLib, (char*)"VcmRemoveAllSats");
   VcmGetCount = (fnPtrVcmGetCount)GetFnPtr(hLib, (char*)"VcmGetCount");
   VcmGetLoaded = (fnPtrVcmGetLoaded)GetFnPtr(hLib, (char*)"VcmGetLoaded");
   VcmAddSatFrLines = (fnPtrVcmAddSatFrLines)GetFnPtr(hLib, (char*)"VcmAddSatFrLines");
   VcmAddSatFrLinesML = (fnPtrVcmAddSatFrLinesML)GetFnPtr(hLib, (char*)"VcmAddSatFrLinesML");
   VcmAddSatFrFields = (fnPtrVcmAddSatFrFields)GetFnPtr(hLib, (char*)"VcmAddSatFrFields");
   VcmAddSatFrFieldsML = (fnPtrVcmAddSatFrFieldsML)GetFnPtr(hLib, (char*)"VcmAddSatFrFieldsML");
   VcmRetrieveAllData = (fnPtrVcmRetrieveAllData)GetFnPtr(hLib, (char*)"VcmRetrieveAllData");
   VcmUpdateSatFrFields = (fnPtrVcmUpdateSatFrFields)GetFnPtr(hLib, (char*)"VcmUpdateSatFrFields");
   VcmGetField = (fnPtrVcmGetField)GetFnPtr(hLib, (char*)"VcmGetField");
   VcmSetField = (fnPtrVcmSetField)GetFnPtr(hLib, (char*)"VcmSetField");
   VcmGetAllFields = (fnPtrVcmGetAllFields)GetFnPtr(hLib, (char*)"VcmGetAllFields");
   VcmGetLines = (fnPtrVcmGetLines)GetFnPtr(hLib, (char*)"VcmGetLines");
   Vcm1LineToMultiLine = (fnPtrVcm1LineToMultiLine)GetFnPtr(hLib, (char*)"Vcm1LineToMultiLine");
   VcmMultiLineTo1Line = (fnPtrVcmMultiLineTo1Line)GetFnPtr(hLib, (char*)"VcmMultiLineTo1Line");
   VcmGetSatKey = (fnPtrVcmGetSatKey)GetFnPtr(hLib, (char*)"VcmGetSatKey");
   VcmGetSatKeyML = (fnPtrVcmGetSatKeyML)GetFnPtr(hLib, (char*)"VcmGetSatKeyML");
   VcmFieldsToSatKey = (fnPtrVcmFieldsToSatKey)GetFnPtr(hLib, (char*)"VcmFieldsToSatKey");
   VcmFieldsToSatKeyML = (fnPtrVcmFieldsToSatKeyML)GetFnPtr(hLib, (char*)"VcmFieldsToSatKeyML");
   VcmArrayToVcmLines = (fnPtrVcmArrayToVcmLines)GetFnPtr(hLib, (char*)"VcmArrayToVcmLines");
   VcmArrayToVcm1Line = (fnPtrVcmArrayToVcm1Line)GetFnPtr(hLib, (char*)"VcmArrayToVcm1Line");
   VcmStringToArray = (fnPtrVcmStringToArray)GetFnPtr(hLib, (char*)"VcmStringToArray");
}



// Free VcmDll
void FreeVcmDll()
{
   FreeLib(hLib, VcmDll);
}
// ========================= End of auto generated code ==========================
