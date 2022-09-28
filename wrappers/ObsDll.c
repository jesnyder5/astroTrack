// This wrapper file was generated automatically by the GenDllWrappers program.

#include "../services/DllUtils.h"
#include "ObsDll.h"


// ObsDll's function pointers definition
fnPtrObsInit                        ObsInit;
fnPtrObsGetInfo                     ObsGetInfo;
fnPtrObsSetTTYYear                  ObsSetTTYYear;
fnPtrObsLoadFile                    ObsLoadFile;
fnPtrObsSaveFile                    ObsSaveFile;
fnPtrObsRemove                      ObsRemove;
fnPtrObsRemoveAll                   ObsRemoveAll;
fnPtrObsGetCount                    ObsGetCount;
fnPtrObsGetLoaded                   ObsGetLoaded;
fnPtrObsLoadCard                    ObsLoadCard;
fnPtrObsLoadTwoCards                ObsLoadTwoCards;
fnPtrObsAddFrB3Card                 ObsAddFrB3Card;
fnPtrObsAddFrB3CardML               ObsAddFrB3CardML;
fnPtrObsB3ToCsv                     ObsB3ToCsv;
fnPtrObsCsvToB3                     ObsCsvToB3;
fnPtrObsAddFrTTYCards               ObsAddFrTTYCards;
fnPtrObsAddFrTTYCardsML             ObsAddFrTTYCardsML;
fnPtrObsTTYToCsv                    ObsTTYToCsv;
fnPtrObsCsvToTTY                    ObsCsvToTTY;
fnPtrObsAddFrCsv                    ObsAddFrCsv;
fnPtrObsAddFrCsvML                  ObsAddFrCsvML;
fnPtrObsAddFrFields                 ObsAddFrFields;
fnPtrObsAddFrFieldsML               ObsAddFrFieldsML;
fnPtrObsAddFrArray                  ObsAddFrArray;
fnPtrObsAddFrArrayML                ObsAddFrArrayML;
fnPtrObsGetAllFields                ObsGetAllFields;
fnPtrObsDataToArray                 ObsDataToArray;
fnPtrObsUpdateFrFields              ObsUpdateFrFields;
fnPtrObsGetField                    ObsGetField;
fnPtrObsSetField                    ObsSetField;
fnPtrObsGetB3Card                   ObsGetB3Card;
fnPtrObsGetTTYCard                  ObsGetTTYCard;
fnPtrObsGetCsv                      ObsGetCsv;
fnPtrObsFieldsToB3Card              ObsFieldsToB3Card;
fnPtrObsFieldsToCsv                 ObsFieldsToCsv;
fnPtrObsFieldsToTTYCard             ObsFieldsToTTYCard;
fnPtrObsFieldsToObsKey              ObsFieldsToObsKey;
fnPtrObsFieldsToObsKeyML            ObsFieldsToObsKeyML;
fnPtrObsB3Parse                     ObsB3Parse;
fnPtrObsParse                       ObsParse;
fnPtrObsLoadFileGID                 ObsLoadFileGID;
fnPtrObsSaveFileGID                 ObsSaveFileGID;
fnPtrObsRemoveGID                   ObsRemoveGID;
fnPtrObsGetCountGID                 ObsGetCountGID;
fnPtrObsGetLoadedGID                ObsGetLoadedGID;
fnPtrObsTypeCToI                    ObsTypeCToI;
fnPtrObsTypeIToC                    ObsTypeIToC;
fnPtrObsResetSelObs                 ObsResetSelObs;
fnPtrObsGetStates                   ObsGetStates;
fnPtrObsDataToStates                ObsDataToStates;
fnPtrObsArrToLines                  ObsArrToLines;
fnPtrSetObsKeyMode                  SetObsKeyMode;
fnPtrGetObsKeyMode                  GetObsKeyMode;
fnPtrSatNumFrObsKey                 SatNumFrObsKey;
fnPtrSenNumFrObsKey                 SenNumFrObsKey;


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
   SetObsKeyMode = (fnPtrSetObsKeyMode)GetFnPtr(hLib, (char*)"SetObsKeyMode");
   GetObsKeyMode = (fnPtrGetObsKeyMode)GetFnPtr(hLib, (char*)"GetObsKeyMode");
   SatNumFrObsKey = (fnPtrSatNumFrObsKey)GetFnPtr(hLib, (char*)"SatNumFrObsKey");
   SenNumFrObsKey = (fnPtrSenNumFrObsKey)GetFnPtr(hLib, (char*)"SenNumFrObsKey");
}



// Free ObsDll
void FreeObsDll()
{
   FreeLib(hLib, ObsDll);
}
// ========================= End of auto generated code ==========================
