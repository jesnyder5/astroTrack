// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/AofDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadAofDll()
{
   // Explicitly load the dll
   hLib = LoadLib(AofDll);


   // Assign function pointers to the appropriate dll functions
   AofInit = (fnPtrAofInit)GetFnPtr(hLib, (char*)"AofInit");
   AofGetInfo = (fnPtrAofGetInfo)GetFnPtr(hLib, (char*)"AofGetInfo");
   AofLoadFile = (fnPtrAofLoadFile)GetFnPtr(hLib, (char*)"AofLoadFile");
   AofLoadFileAll = (fnPtrAofLoadFileAll)GetFnPtr(hLib, (char*)"AofLoadFileAll");
   AofLoadCard = (fnPtrAofLoadCard)GetFnPtr(hLib, (char*)"AofLoadCard");
   AofGetDataFrInputFiles = (fnPtrAofGetDataFrInputFiles)GetFnPtr(hLib, (char*)"AofGetDataFrInputFiles");
   AofReset = (fnPtrAofReset)GetFnPtr(hLib, (char*)"AofReset");
   AofBasic = (fnPtrAofBasic)GetFnPtr(hLib, (char*)"AofBasic");
   AofComplex = (fnPtrAofComplex)GetFnPtr(hLib, (char*)"AofComplex");
   AofGetLook = (fnPtrAofGetLook)GetFnPtr(hLib, (char*)"AofGetLook");
   AofGetView = (fnPtrAofGetView)GetFnPtr(hLib, (char*)"AofGetView");
   AofGetDarknessLevel = (fnPtrAofGetDarknessLevel)GetFnPtr(hLib, (char*)"AofGetDarknessLevel");
}



// Free AofDll
void FreeAofDll()
{
   FreeLib(hLib, AofDll);
}
// ========================= End of auto generated code ==========================