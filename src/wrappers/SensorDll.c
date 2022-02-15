// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#include "services/DllUtils.h"
#include "wrappers/SensorDll.h"


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadSensorDll()
{
   // Explicitly load the dll
   hLib = LoadLib(SensorDll);


   // Assign function pointers to the appropriate dll functions
   SensorInit = (fnPtrSensorInit)GetFnPtr(hLib, (char*)"SensorInit");
   SensorGetInfo = (fnPtrSensorGetInfo)GetFnPtr(hLib, (char*)"SensorGetInfo");
   SensorLoadFile = (fnPtrSensorLoadFile)GetFnPtr(hLib, (char*)"SensorLoadFile");
   SensorLoadCard = (fnPtrSensorLoadCard)GetFnPtr(hLib, (char*)"SensorLoadCard");
   SensorSaveFile = (fnPtrSensorSaveFile)GetFnPtr(hLib, (char*)"SensorSaveFile");
   SensorRemove = (fnPtrSensorRemove)GetFnPtr(hLib, (char*)"SensorRemove");
   SensorRemoveAll = (fnPtrSensorRemoveAll)GetFnPtr(hLib, (char*)"SensorRemoveAll");
   SensorGetCount = (fnPtrSensorGetCount)GetFnPtr(hLib, (char*)"SensorGetCount");
   SensorGetLoaded = (fnPtrSensorGetLoaded)GetFnPtr(hLib, (char*)"SensorGetLoaded");
   SensorGetLocAll = (fnPtrSensorGetLocAll)GetFnPtr(hLib, (char*)"SensorGetLocAll");
   SensorSetLocAll = (fnPtrSensorSetLocAll)GetFnPtr(hLib, (char*)"SensorSetLocAll");
   SensorGetLocField = (fnPtrSensorGetLocField)GetFnPtr(hLib, (char*)"SensorGetLocField");
   SensorSetLocField = (fnPtrSensorSetLocField)GetFnPtr(hLib, (char*)"SensorSetLocField");
   SensorGet1L = (fnPtrSensorGet1L)GetFnPtr(hLib, (char*)"SensorGet1L");
   SensorSet1L = (fnPtrSensorSet1L)GetFnPtr(hLib, (char*)"SensorSet1L");
   SensorGet2L = (fnPtrSensorGet2L)GetFnPtr(hLib, (char*)"SensorGet2L");
   SensorSet2L = (fnPtrSensorSet2L)GetFnPtr(hLib, (char*)"SensorSet2L");
   SensorGetLimField = (fnPtrSensorGetLimField)GetFnPtr(hLib, (char*)"SensorGetLimField");
   SensorSetLimField = (fnPtrSensorSetLimField)GetFnPtr(hLib, (char*)"SensorSetLimField");
   SensorGetBS = (fnPtrSensorGetBS)GetFnPtr(hLib, (char*)"SensorGetBS");
   SensorSetBS = (fnPtrSensorSetBS)GetFnPtr(hLib, (char*)"SensorSetBS");
   SensorGetBSField = (fnPtrSensorGetBSField)GetFnPtr(hLib, (char*)"SensorGetBSField");
   SensorSetBSField = (fnPtrSensorSetBSField)GetFnPtr(hLib, (char*)"SensorSetBSField");
   SensorGetLines = (fnPtrSensorGetLines)GetFnPtr(hLib, (char*)"SensorGetLines");
   SensorGetOrbSatKey = (fnPtrSensorGetOrbSatKey)GetFnPtr(hLib, (char*)"SensorGetOrbSatKey");
   SensorSetOrbSatKey = (fnPtrSensorSetOrbSatKey)GetFnPtr(hLib, (char*)"SensorSetOrbSatKey");
   SensorLoadAzElTable = (fnPtrSensorLoadAzElTable)GetFnPtr(hLib, (char*)"SensorLoadAzElTable");
   SensorAddSegment = (fnPtrSensorAddSegment)GetFnPtr(hLib, (char*)"SensorAddSegment");
   SensorGetSegment = (fnPtrSensorGetSegment)GetFnPtr(hLib, (char*)"SensorGetSegment");
}



// Free SensorDll
void FreeSensorDll()
{
   FreeLib(hLib, SensorDll);
}
// ========================= End of auto generated code ==========================
