// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/BamDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadBamDll()
{
   // Explicitly load the dll
   hLib = LoadLib(BamDll);


   // Assign function pointers to the appropriate dll functions
   BamInit = (fnPtrBamInit)GetFnPtr(hLib, (char*)"BamInit");
   BamGetInfo = (fnPtrBamGetInfo)GetFnPtr(hLib, (char*)"BamGetInfo");
   BamCompNumTSs = (fnPtrBamCompNumTSs)GetFnPtr(hLib, (char*)"BamCompNumTSs");
   BamCompute = (fnPtrBamCompute)GetFnPtr(hLib, (char*)"BamCompute");
   BamGetResults = (fnPtrBamGetResults)GetFnPtr(hLib, (char*)"BamGetResults");
}



// Free BamDll
void FreeBamDll()
{
   FreeLib(hLib, BamDll);
}
// ========================= End of auto generated code ==========================
