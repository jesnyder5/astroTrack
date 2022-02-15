// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/DllMainDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadDllMainDll()
{
   // Explicitly load the dll
   hLib = LoadLib(DllMainDll);


   // Assign function pointers to the appropriate dll functions
   DllMainInit = (fnPtrDllMainInit)GetFnPtr(hLib, (char*)"DllMainInit");
   DllMainGetInfo = (fnPtrDllMainGetInfo)GetFnPtr(hLib, (char*)"DllMainGetInfo");
   DllMainLoadFile = (fnPtrDllMainLoadFile)GetFnPtr(hLib, (char*)"DllMainLoadFile");
   OpenLogFile = (fnPtrOpenLogFile)GetFnPtr(hLib, (char*)"OpenLogFile");
   CloseLogFile = (fnPtrCloseLogFile)GetFnPtr(hLib, (char*)"CloseLogFile");
   LogMessage = (fnPtrLogMessage)GetFnPtr(hLib, (char*)"LogMessage");
   GetLastErrMsg = (fnPtrGetLastErrMsg)GetFnPtr(hLib, (char*)"GetLastErrMsg");
   GetLastInfoMsg = (fnPtrGetLastInfoMsg)GetFnPtr(hLib, (char*)"GetLastInfoMsg");
   GetInitDllNames = (fnPtrGetInitDllNames)GetFnPtr(hLib, (char*)"GetInitDllNames");
   TestInterface = (fnPtrTestInterface)GetFnPtr(hLib, (char*)"TestInterface");
   GetMOICData = (fnPtrGetMOICData)GetFnPtr(hLib, (char*)"GetMOICData");
   SetElsetKeyMode = (fnPtrSetElsetKeyMode)GetFnPtr(hLib, (char*)"SetElsetKeyMode");
   GetElsetKeyMode = (fnPtrGetElsetKeyMode)GetFnPtr(hLib, (char*)"GetElsetKeyMode");
}



// Free DllMainDll
void FreeDllMainDll()
{
   FreeLib(hLib, DllMainDll);
}
// ========================= End of auto generated code ==========================
