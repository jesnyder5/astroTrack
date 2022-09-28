// This wrapper file was generated automatically by the GenDllWrappers program.

#include "../services/DllUtils.h"
#include "ExtEphemDll.h"


// ExtEphemDll's function pointers definition
fnPtrExtEphInit                     ExtEphInit;
fnPtrExtEphGetInfo                  ExtEphGetInfo;
fnPtrExtEphLoadFile                 ExtEphLoadFile;
fnPtrExtEphSaveFile                 ExtEphSaveFile;
fnPtrExtEphRemoveSat                ExtEphRemoveSat;
fnPtrExtEphRemoveAllSats            ExtEphRemoveAllSats;
fnPtrExtEphGetCount                 ExtEphGetCount;
fnPtrExtEphGetLoaded                ExtEphGetLoaded;
fnPtrExtEphAddSat                   ExtEphAddSat;
fnPtrExtEphAddSatEphem              ExtEphAddSatEphem;
fnPtrExtEphAddSatEphemCovMtx        ExtEphAddSatEphemCovMtx;
fnPtrExtEphAddSatEphemExt           ExtEphAddSatEphemExt;
fnPtrExtEphGetAllFields             ExtEphGetAllFields;
fnPtrExtEphGetField                 ExtEphGetField;
fnPtrExtEphSetField                 ExtEphSetField;
fnPtrExtEphStartEndTime             ExtEphStartEndTime;
fnPtrExtEphGetEphemeris             ExtEphGetEphemeris;
fnPtrExtEphGetCovMtx                ExtEphGetCovMtx;
fnPtrExtEphMse                      ExtEphMse;
fnPtrExtEphMseCovMtx                ExtEphMseCovMtx;
fnPtrExtEphDs50UTC                  ExtEphDs50UTC;
fnPtrExtEphDs50UTCCovMtx            ExtEphDs50UTCCovMtx;
fnPtrExtEphXten                     ExtEphXten;
fnPtrExtEphGetLine                  ExtEphGetLine;
fnPtrExtEphGetSatKey                ExtEphGetSatKey;
fnPtrExtEphFieldsToSatKey           ExtEphFieldsToSatKey;


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadExtEphemDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ExtEphemDll);


   // Assign function pointers to the appropriate dll functions
   ExtEphInit = (fnPtrExtEphInit)GetFnPtr(hLib, (char*)"ExtEphInit");
   ExtEphGetInfo = (fnPtrExtEphGetInfo)GetFnPtr(hLib, (char*)"ExtEphGetInfo");
   ExtEphLoadFile = (fnPtrExtEphLoadFile)GetFnPtr(hLib, (char*)"ExtEphLoadFile");
   ExtEphSaveFile = (fnPtrExtEphSaveFile)GetFnPtr(hLib, (char*)"ExtEphSaveFile");
   ExtEphRemoveSat = (fnPtrExtEphRemoveSat)GetFnPtr(hLib, (char*)"ExtEphRemoveSat");
   ExtEphRemoveAllSats = (fnPtrExtEphRemoveAllSats)GetFnPtr(hLib, (char*)"ExtEphRemoveAllSats");
   ExtEphGetCount = (fnPtrExtEphGetCount)GetFnPtr(hLib, (char*)"ExtEphGetCount");
   ExtEphGetLoaded = (fnPtrExtEphGetLoaded)GetFnPtr(hLib, (char*)"ExtEphGetLoaded");
   ExtEphAddSat = (fnPtrExtEphAddSat)GetFnPtr(hLib, (char*)"ExtEphAddSat");
   ExtEphAddSatEphem = (fnPtrExtEphAddSatEphem)GetFnPtr(hLib, (char*)"ExtEphAddSatEphem");
   ExtEphAddSatEphemCovMtx = (fnPtrExtEphAddSatEphemCovMtx)GetFnPtr(hLib, (char*)"ExtEphAddSatEphemCovMtx");
   ExtEphAddSatEphemExt = (fnPtrExtEphAddSatEphemExt)GetFnPtr(hLib, (char*)"ExtEphAddSatEphemExt");
   ExtEphGetAllFields = (fnPtrExtEphGetAllFields)GetFnPtr(hLib, (char*)"ExtEphGetAllFields");
   ExtEphGetField = (fnPtrExtEphGetField)GetFnPtr(hLib, (char*)"ExtEphGetField");
   ExtEphSetField = (fnPtrExtEphSetField)GetFnPtr(hLib, (char*)"ExtEphSetField");
   ExtEphStartEndTime = (fnPtrExtEphStartEndTime)GetFnPtr(hLib, (char*)"ExtEphStartEndTime");
   ExtEphGetEphemeris = (fnPtrExtEphGetEphemeris)GetFnPtr(hLib, (char*)"ExtEphGetEphemeris");
   ExtEphGetCovMtx = (fnPtrExtEphGetCovMtx)GetFnPtr(hLib, (char*)"ExtEphGetCovMtx");
   ExtEphMse = (fnPtrExtEphMse)GetFnPtr(hLib, (char*)"ExtEphMse");
   ExtEphMseCovMtx = (fnPtrExtEphMseCovMtx)GetFnPtr(hLib, (char*)"ExtEphMseCovMtx");
   ExtEphDs50UTC = (fnPtrExtEphDs50UTC)GetFnPtr(hLib, (char*)"ExtEphDs50UTC");
   ExtEphDs50UTCCovMtx = (fnPtrExtEphDs50UTCCovMtx)GetFnPtr(hLib, (char*)"ExtEphDs50UTCCovMtx");
   ExtEphXten = (fnPtrExtEphXten)GetFnPtr(hLib, (char*)"ExtEphXten");
   ExtEphGetLine = (fnPtrExtEphGetLine)GetFnPtr(hLib, (char*)"ExtEphGetLine");
   ExtEphGetSatKey = (fnPtrExtEphGetSatKey)GetFnPtr(hLib, (char*)"ExtEphGetSatKey");
   ExtEphFieldsToSatKey = (fnPtrExtEphFieldsToSatKey)GetFnPtr(hLib, (char*)"ExtEphFieldsToSatKey");
}



// Free ExtEphemDll
void FreeExtEphemDll()
{
   FreeLib(hLib, ExtEphemDll);
}
// ========================= End of auto generated code ==========================
