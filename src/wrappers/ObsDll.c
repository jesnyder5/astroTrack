// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/ObsDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadObsDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ObsDll);


   // Assign function pointers to the appropriate dll functions
   ObsInit = (fnPtrObsInit)GetFnPtr(hLib, (char*)"ObsInit");
   ObsGetInfo = (fnPtrObsGetInfo)GetFnPtr(hLib, (char*)"ObsGetInfo");
   ObsSetTTYYear = (fnPtrObsSetTTYYear)GetFnPtr(hLib, (char*)"ObsSetTTYYear");
   ObsLoadFile = (fnPtrObsLoadFile)GetFnPtr(hLib, (char*)"ObsLoadFile");
   ObsSaveFile = (fnPtrObsSaveFile)GetFnPtr(hLib, (char*)"ObsSaveFile");
   ObsRemove = (fnPtrObsRemove)GetFnPtr(hLib, (char*)"ObsRemove");
   ObsRemoveAll = (fnPtrObsRemoveAll)GetFnPtr(hLib, (char*)"ObsRemoveAll");
   ObsGetCount = (fnPtrObsGetCount)GetFnPtr(hLib, (char*)"ObsGetCount");
   ObsGetLoaded = (fnPtrObsGetLoaded)GetFnPtr(hLib, (char*)"ObsGetLoaded");
   ObsLoadCard = (fnPtrObsLoadCard)GetFnPtr(hLib, (char*)"ObsLoadCard");
   ObsLoadTwoCards = (fnPtrObsLoadTwoCards)GetFnPtr(hLib, (char*)"ObsLoadTwoCards");
   ObsAddFrB3Card = (fnPtrObsAddFrB3Card)GetFnPtr(hLib, (char*)"ObsAddFrB3Card");
   ObsAddFrB3CardML = (fnPtrObsAddFrB3CardML)GetFnPtr(hLib, (char*)"ObsAddFrB3CardML");
   ObsB3ToCsv = (fnPtrObsB3ToCsv)GetFnPtr(hLib, (char*)"ObsB3ToCsv");
   ObsCsvToB3 = (fnPtrObsCsvToB3)GetFnPtr(hLib, (char*)"ObsCsvToB3");
   ObsAddFrTTYCards = (fnPtrObsAddFrTTYCards)GetFnPtr(hLib, (char*)"ObsAddFrTTYCards");
   ObsAddFrTTYCardsML = (fnPtrObsAddFrTTYCardsML)GetFnPtr(hLib, (char*)"ObsAddFrTTYCardsML");
   ObsTTYToCsv = (fnPtrObsTTYToCsv)GetFnPtr(hLib, (char*)"ObsTTYToCsv");
   ObsCsvToTTY = (fnPtrObsCsvToTTY)GetFnPtr(hLib, (char*)"ObsCsvToTTY");
   ObsAddFrCsv = (fnPtrObsAddFrCsv)GetFnPtr(hLib, (char*)"ObsAddFrCsv");
   ObsAddFrCsvML = (fnPtrObsAddFrCsvML)GetFnPtr(hLib, (char*)"ObsAddFrCsvML");
   ObsAddFrFields = (fnPtrObsAddFrFields)GetFnPtr(hLib, (char*)"ObsAddFrFields");
   ObsAddFrFieldsML = (fnPtrObsAddFrFieldsML)GetFnPtr(hLib, (char*)"ObsAddFrFieldsML");
   ObsAddFrArray = (fnPtrObsAddFrArray)GetFnPtr(hLib, (char*)"ObsAddFrArray");
   ObsAddFrArrayML = (fnPtrObsAddFrArrayML)GetFnPtr(hLib, (char*)"ObsAddFrArrayML");
   ObsGetAllFields = (fnPtrObsGetAllFields)GetFnPtr(hLib, (char*)"ObsGetAllFields");
   ObsDataToArray = (fnPtrObsDataToArray)GetFnPtr(hLib, (char*)"ObsDataToArray");
   ObsUpdateFrFields = (fnPtrObsUpdateFrFields)GetFnPtr(hLib, (char*)"ObsUpdateFrFields");
   ObsGetField = (fnPtrObsGetField)GetFnPtr(hLib, (char*)"ObsGetField");
   ObsSetField = (fnPtrObsSetField)GetFnPtr(hLib, (char*)"ObsSetField");
   ObsGetB3Card = (fnPtrObsGetB3Card)GetFnPtr(hLib, (char*)"ObsGetB3Card");
   ObsGetTTYCard = (fnPtrObsGetTTYCard)GetFnPtr(hLib, (char*)"ObsGetTTYCard");
   ObsGetCsv = (fnPtrObsGetCsv)GetFnPtr(hLib, (char*)"ObsGetCsv");
   ObsFieldsToB3Card = (fnPtrObsFieldsToB3Card)GetFnPtr(hLib, (char*)"ObsFieldsToB3Card");
   ObsFieldsToCsv = (fnPtrObsFieldsToCsv)GetFnPtr(hLib, (char*)"ObsFieldsToCsv");
   ObsFieldsToTTYCard = (fnPtrObsFieldsToTTYCard)GetFnPtr(hLib, (char*)"ObsFieldsToTTYCard");
   ObsFieldsToObsKey = (fnPtrObsFieldsToObsKey)GetFnPtr(hLib, (char*)"ObsFieldsToObsKey");
   ObsFieldsToObsKeyML = (fnPtrObsFieldsToObsKeyML)GetFnPtr(hLib, (char*)"ObsFieldsToObsKeyML");
   ObsB3Parse = (fnPtrObsB3Parse)GetFnPtr(hLib, (char*)"ObsB3Parse");
   ObsParse = (fnPtrObsParse)GetFnPtr(hLib, (char*)"ObsParse");
   ObsLoadFileGID = (fnPtrObsLoadFileGID)GetFnPtr(hLib, (char*)"ObsLoadFileGID");
   ObsSaveFileGID = (fnPtrObsSaveFileGID)GetFnPtr(hLib, (char*)"ObsSaveFileGID");
   ObsRemoveGID = (fnPtrObsRemoveGID)GetFnPtr(hLib, (char*)"ObsRemoveGID");
   ObsGetCountGID = (fnPtrObsGetCountGID)GetFnPtr(hLib, (char*)"ObsGetCountGID");
   ObsGetLoadedGID = (fnPtrObsGetLoadedGID)GetFnPtr(hLib, (char*)"ObsGetLoadedGID");
   ObsTypeCToI = (fnPtrObsTypeCToI)GetFnPtr(hLib, (char*)"ObsTypeCToI");
   ObsTypeIToC = (fnPtrObsTypeIToC)GetFnPtr(hLib, (char*)"ObsTypeIToC");
   ObsResetSelObs = (fnPtrObsResetSelObs)GetFnPtr(hLib, (char*)"ObsResetSelObs");
   ObsGetStates = (fnPtrObsGetStates)GetFnPtr(hLib, (char*)"ObsGetStates");
   ObsDataToStates = (fnPtrObsDataToStates)GetFnPtr(hLib, (char*)"ObsDataToStates");
   ObsArrToLines = (fnPtrObsArrToLines)GetFnPtr(hLib, (char*)"ObsArrToLines");
}



// Free ObsDll
void FreeObsDll()
{
   FreeLib(hLib, ObsDll);
}
// ========================= End of auto generated code ==========================
