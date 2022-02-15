// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/ComboDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadComboDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ComboDll);


   // Assign function pointers to the appropriate dll functions
   ComboInit = (fnPtrComboInit)GetFnPtr(hLib, (char*)"ComboInit");
   ComboGetInfo = (fnPtrComboGetInfo)GetFnPtr(hLib, (char*)"ComboGetInfo");
   ComboLoadFile = (fnPtrComboLoadFile)GetFnPtr(hLib, (char*)"ComboLoadFile");
   ComboLoadFileAll = (fnPtrComboLoadFileAll)GetFnPtr(hLib, (char*)"ComboLoadFileAll");
   ComboLoadCard = (fnPtrComboLoadCard)GetFnPtr(hLib, (char*)"ComboLoadCard");
   ComboSaveFile = (fnPtrComboSaveFile)GetFnPtr(hLib, (char*)"ComboSaveFile");
   ComboGetNumOfPriSecSats = (fnPtrComboGetNumOfPriSecSats)GetFnPtr(hLib, (char*)"ComboGetNumOfPriSecSats");
   ComboGetPriSatNums = (fnPtrComboGetPriSatNums)GetFnPtr(hLib, (char*)"ComboGetPriSatNums");
   ComboGetSecSatNums = (fnPtrComboGetSecSatNums)GetFnPtr(hLib, (char*)"ComboGetSecSatNums");
   ComboGet7pCard = (fnPtrComboGet7pCard)GetFnPtr(hLib, (char*)"ComboGet7pCard");
   ComboGet7pAll = (fnPtrComboGet7pAll)GetFnPtr(hLib, (char*)"ComboGet7pAll");
   ComboSet7pAll = (fnPtrComboSet7pAll)GetFnPtr(hLib, (char*)"ComboSet7pAll");
   ComboGet7pField = (fnPtrComboGet7pField)GetFnPtr(hLib, (char*)"ComboGet7pField");
   ComboSet7pField = (fnPtrComboSet7pField)GetFnPtr(hLib, (char*)"ComboSet7pField");
   ComboCompPriSec = (fnPtrComboCompPriSec)GetFnPtr(hLib, (char*)"ComboCompPriSec");
   ComboCompPriSec_MT = (fnPtrComboCompPriSec_MT)GetFnPtr(hLib, (char*)"ComboCompPriSec_MT");
   ComboPOC = (fnPtrComboPOC)GetFnPtr(hLib, (char*)"ComboPOC");
   ComboCSMPOC = (fnPtrComboCSMPOC)GetFnPtr(hLib, (char*)"ComboCSMPOC");
}



// Free ComboDll
void FreeComboDll()
{
   FreeLib(hLib, ComboDll);
}
// ========================= End of auto generated code ==========================
