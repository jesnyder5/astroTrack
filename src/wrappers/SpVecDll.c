// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/SpVecDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSpVecDll()
{
   // Explicitly load the dll
   hLib = LoadLib(SpVecDll);


   // Assign function pointers to the appropriate dll functions
   SpVecInit = (fnPtrSpVecInit)GetFnPtr(hLib, (char*)"SpVecInit");
   SpVecGetInfo = (fnPtrSpVecGetInfo)GetFnPtr(hLib, (char*)"SpVecGetInfo");
   SpVecLoadFile = (fnPtrSpVecLoadFile)GetFnPtr(hLib, (char*)"SpVecLoadFile");
   SpVecSaveFile = (fnPtrSpVecSaveFile)GetFnPtr(hLib, (char*)"SpVecSaveFile");
   SpVecRemoveSat = (fnPtrSpVecRemoveSat)GetFnPtr(hLib, (char*)"SpVecRemoveSat");
   SpVecRemoveAllSats = (fnPtrSpVecRemoveAllSats)GetFnPtr(hLib, (char*)"SpVecRemoveAllSats");
   SpVecGetCount = (fnPtrSpVecGetCount)GetFnPtr(hLib, (char*)"SpVecGetCount");
   SpVecGetLoaded = (fnPtrSpVecGetLoaded)GetFnPtr(hLib, (char*)"SpVecGetLoaded");
   SpVecAddSatFrLines = (fnPtrSpVecAddSatFrLines)GetFnPtr(hLib, (char*)"SpVecAddSatFrLines");
   SpVecAddSatFrLinesML = (fnPtrSpVecAddSatFrLinesML)GetFnPtr(hLib, (char*)"SpVecAddSatFrLinesML");
   SpVecAddSatFrFields = (fnPtrSpVecAddSatFrFields)GetFnPtr(hLib, (char*)"SpVecAddSatFrFields");
   SpVecAddSatFrFieldsML = (fnPtrSpVecAddSatFrFieldsML)GetFnPtr(hLib, (char*)"SpVecAddSatFrFieldsML");
   SpVecUpdateSatFrFields = (fnPtrSpVecUpdateSatFrFields)GetFnPtr(hLib, (char*)"SpVecUpdateSatFrFields");
   SpVecGetField = (fnPtrSpVecGetField)GetFnPtr(hLib, (char*)"SpVecGetField");
   SpVecSetField = (fnPtrSpVecSetField)GetFnPtr(hLib, (char*)"SpVecSetField");
   SpVecGetAllFields = (fnPtrSpVecGetAllFields)GetFnPtr(hLib, (char*)"SpVecGetAllFields");
   SpVecParse = (fnPtrSpVecParse)GetFnPtr(hLib, (char*)"SpVecParse");
   SpVecLinesToArray = (fnPtrSpVecLinesToArray)GetFnPtr(hLib, (char*)"SpVecLinesToArray");
   SpVecGetLines = (fnPtrSpVecGetLines)GetFnPtr(hLib, (char*)"SpVecGetLines");
   SpVecFieldsToLines = (fnPtrSpVecFieldsToLines)GetFnPtr(hLib, (char*)"SpVecFieldsToLines");
   SpVecArrayToLines = (fnPtrSpVecArrayToLines)GetFnPtr(hLib, (char*)"SpVecArrayToLines");
   SpVecGetSatKey = (fnPtrSpVecGetSatKey)GetFnPtr(hLib, (char*)"SpVecGetSatKey");
   SpVecGetSatKeyML = (fnPtrSpVecGetSatKeyML)GetFnPtr(hLib, (char*)"SpVecGetSatKeyML");
   SpVecFieldsToSatKey = (fnPtrSpVecFieldsToSatKey)GetFnPtr(hLib, (char*)"SpVecFieldsToSatKey");
   SpVecFieldsToSatKeyML = (fnPtrSpVecFieldsToSatKeyML)GetFnPtr(hLib, (char*)"SpVecFieldsToSatKeyML");
   SpVecAddSatFrArray = (fnPtrSpVecAddSatFrArray)GetFnPtr(hLib, (char*)"SpVecAddSatFrArray");
   SpVecAddSatFrArrayML = (fnPtrSpVecAddSatFrArrayML)GetFnPtr(hLib, (char*)"SpVecAddSatFrArrayML");
   SpVecUpdateSatFrArray = (fnPtrSpVecUpdateSatFrArray)GetFnPtr(hLib, (char*)"SpVecUpdateSatFrArray");
   SpVecDataToArray = (fnPtrSpVecDataToArray)GetFnPtr(hLib, (char*)"SpVecDataToArray");
}



// Free SpVecDll
void FreeSpVecDll()
{
   FreeLib(hLib, SpVecDll);
}
// ========================= End of auto generated code ==========================
