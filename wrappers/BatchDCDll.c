// This wrapper file was generated automatically by the GenDllWrappers program.

#include "../services/DllUtils.h"
#include "BatchDCDll.h"


// BatchDCDll's function pointers definition
fnPtrBatchDCInit                    BatchDCInit;
fnPtrBatchDCGetInfo                 BatchDCGetInfo;
fnPtrBatchDCLoadFile                BatchDCLoadFile;
fnPtrBatchDCLoadFileAll             BatchDCLoadFileAll;
fnPtrBatchDCLoadCard                BatchDCLoadCard;
fnPtrBatchDCGetPCard                BatchDCGetPCard;
fnPtrBatchDCSaveFile                BatchDCSaveFile;
fnPtrBatchDCGetParams               BatchDCGetParams;
fnPtrBatchDCSetParams               BatchDCSetParams;
fnPtrBatchDCInitSat                 BatchDCInitSat;
fnPtrBatchDCSolve                   BatchDCSolve;
fnPtrBatchDCSolveSelObs             BatchDCSolveSelObs;
fnPtrBatchDCRemoveSat               BatchDCRemoveSat;
fnPtrBatchDCIterate                 BatchDCIterate;
fnPtrBatchDCGetVcm                  BatchDCGetVcm;
fnPtrBatchDCGetSpVOut               BatchDCGetSpVOut;
fnPtrBatchDCSetSpVOut               BatchDCSetSpVOut;
fnPtrBatchDCResetAll                BatchDCResetAll;
fnPtrBatchDCGetAccptCrit            BatchDCGetAccptCrit;
fnPtrSpToEGP                        SpToEGP;
fnPtrSpToTle                        SpToTle;
fnPtrSpToCsv                        SpToCsv;
fnPtrExtEphemToEGP                  ExtEphemToEGP;


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadBatchDCDll()
{
   // Explicitly load the dll
   hLib = LoadLib(BatchDCDll);


   // Assign function pointers to the appropriate dll functions
   BatchDCInit = (fnPtrBatchDCInit)GetFnPtr(hLib, (char*)"BatchDCInit");
   BatchDCGetInfo = (fnPtrBatchDCGetInfo)GetFnPtr(hLib, (char*)"BatchDCGetInfo");
   BatchDCLoadFile = (fnPtrBatchDCLoadFile)GetFnPtr(hLib, (char*)"BatchDCLoadFile");
   BatchDCLoadFileAll = (fnPtrBatchDCLoadFileAll)GetFnPtr(hLib, (char*)"BatchDCLoadFileAll");
   BatchDCLoadCard = (fnPtrBatchDCLoadCard)GetFnPtr(hLib, (char*)"BatchDCLoadCard");
   BatchDCGetPCard = (fnPtrBatchDCGetPCard)GetFnPtr(hLib, (char*)"BatchDCGetPCard");
   BatchDCSaveFile = (fnPtrBatchDCSaveFile)GetFnPtr(hLib, (char*)"BatchDCSaveFile");
   BatchDCGetParams = (fnPtrBatchDCGetParams)GetFnPtr(hLib, (char*)"BatchDCGetParams");
   BatchDCSetParams = (fnPtrBatchDCSetParams)GetFnPtr(hLib, (char*)"BatchDCSetParams");
   BatchDCInitSat = (fnPtrBatchDCInitSat)GetFnPtr(hLib, (char*)"BatchDCInitSat");
   BatchDCSolve = (fnPtrBatchDCSolve)GetFnPtr(hLib, (char*)"BatchDCSolve");
   BatchDCSolveSelObs = (fnPtrBatchDCSolveSelObs)GetFnPtr(hLib, (char*)"BatchDCSolveSelObs");
   BatchDCRemoveSat = (fnPtrBatchDCRemoveSat)GetFnPtr(hLib, (char*)"BatchDCRemoveSat");
   BatchDCIterate = (fnPtrBatchDCIterate)GetFnPtr(hLib, (char*)"BatchDCIterate");
   BatchDCGetVcm = (fnPtrBatchDCGetVcm)GetFnPtr(hLib, (char*)"BatchDCGetVcm");
   BatchDCGetSpVOut = (fnPtrBatchDCGetSpVOut)GetFnPtr(hLib, (char*)"BatchDCGetSpVOut");
   BatchDCSetSpVOut = (fnPtrBatchDCSetSpVOut)GetFnPtr(hLib, (char*)"BatchDCSetSpVOut");
   BatchDCResetAll = (fnPtrBatchDCResetAll)GetFnPtr(hLib, (char*)"BatchDCResetAll");
   BatchDCGetAccptCrit = (fnPtrBatchDCGetAccptCrit)GetFnPtr(hLib, (char*)"BatchDCGetAccptCrit");
   SpToEGP = (fnPtrSpToEGP)GetFnPtr(hLib, (char*)"SpToEGP");
   SpToTle = (fnPtrSpToTle)GetFnPtr(hLib, (char*)"SpToTle");
   SpToCsv = (fnPtrSpToCsv)GetFnPtr(hLib, (char*)"SpToCsv");
   ExtEphemToEGP = (fnPtrExtEphemToEGP)GetFnPtr(hLib, (char*)"ExtEphemToEGP");
}



// Free BatchDCDll
void FreeBatchDCDll()
{
   FreeLib(hLib, BatchDCDll);
}
// ========================= End of auto generated code ==========================
