// This wrapper file was generated automatically by the GenDllWrappers program.

#include "../services/DllUtils.h"
#include "ObsOpsDll.h"


// ObsOpsDll's function pointers definition
fnPtrObsOpsInit                     ObsOpsInit;
fnPtrObsOpsGetInfo                  ObsOpsGetInfo;
fnPtrIomodLoadFile                  IomodLoadFile;
fnPtrIomodLoadFileAll               IomodLoadFileAll;
fnPtrIomodSaveFile                  IomodSaveFile;
fnPtrIomodGetIpCard                 IomodGetIpCard;
fnPtrIomodGetIpAll                  IomodGetIpAll;
fnPtrIomodSetIpAll                  IomodSetIpAll;
fnPtrIomodGetIpField                IomodGetIpField;
fnPtrIomodSetIpField                IomodSetIpField;
fnPtrManyObsToPosVel                ManyObsToPosVel;
fnPtrThreeObsToPosVel               ThreeObsToPosVel;
fnPtrIomod_OS                       Iomod_OS;
fnPtrTwoObsToPosVel                 TwoObsToPosVel;
fnPtrAnglesOnlyToPosVel             AnglesOnlyToPosVel;
fnPtrFindTrack                      FindTrack;
fnPtrATrackToPosVel                 ATrackToPosVel;
fnPtrTriGetDefParams                TriGetDefParams;
fnPtrTriComputeToFile               TriComputeToFile;
fnPtrTriCompute1                    TriCompute1;
fnPtrTriCompute2                    TriCompute2;
fnPtrTriCompute3                    TriCompute3;
fnPtrGetWaterfallAlt                GetWaterfallAlt;
fnPtrAnglesOnlyToLLH                AnglesOnlyToLLH;
fnPtrLombLengthOut                  LombLengthOut;
fnPtrLomb                           Lomb;
fnPtrLombFalseProb                  LombFalseProb;
fnPtrLombFalseProbInv               LombFalseProbInv;
fnPtrLombLengthCoef                 LombLengthCoef;
fnPtrLombWaveFit                    LombWaveFit;
fnPtrLombCalcValueFromTime          LombCalcValueFromTime;
fnPtrAngleBetweenObs                AngleBetweenObs;


static void* hLib = NULL; // handle to the dll

// Load and assign function pointers
void LoadObsOpsDll()
{
   // Explicitly load the dll
   hLib = LoadLib(ObsOpsDll);


   // Assign function pointers to the appropriate dll functions
   ObsOpsInit = (fnPtrObsOpsInit)GetFnPtr(hLib, (char*)"ObsOpsInit");
   ObsOpsGetInfo = (fnPtrObsOpsGetInfo)GetFnPtr(hLib, (char*)"ObsOpsGetInfo");
   IomodLoadFile = (fnPtrIomodLoadFile)GetFnPtr(hLib, (char*)"IomodLoadFile");
   IomodLoadFileAll = (fnPtrIomodLoadFileAll)GetFnPtr(hLib, (char*)"IomodLoadFileAll");
   IomodSaveFile = (fnPtrIomodSaveFile)GetFnPtr(hLib, (char*)"IomodSaveFile");
   IomodGetIpCard = (fnPtrIomodGetIpCard)GetFnPtr(hLib, (char*)"IomodGetIpCard");
   IomodGetIpAll = (fnPtrIomodGetIpAll)GetFnPtr(hLib, (char*)"IomodGetIpAll");
   IomodSetIpAll = (fnPtrIomodSetIpAll)GetFnPtr(hLib, (char*)"IomodSetIpAll");
   IomodGetIpField = (fnPtrIomodGetIpField)GetFnPtr(hLib, (char*)"IomodGetIpField");
   IomodSetIpField = (fnPtrIomodSetIpField)GetFnPtr(hLib, (char*)"IomodSetIpField");
   ManyObsToPosVel = (fnPtrManyObsToPosVel)GetFnPtr(hLib, (char*)"ManyObsToPosVel");
   ThreeObsToPosVel = (fnPtrThreeObsToPosVel)GetFnPtr(hLib, (char*)"ThreeObsToPosVel");
   Iomod_OS = (fnPtrIomod_OS)GetFnPtr(hLib, (char*)"Iomod_OS");
   TwoObsToPosVel = (fnPtrTwoObsToPosVel)GetFnPtr(hLib, (char*)"TwoObsToPosVel");
   AnglesOnlyToPosVel = (fnPtrAnglesOnlyToPosVel)GetFnPtr(hLib, (char*)"AnglesOnlyToPosVel");
   FindTrack = (fnPtrFindTrack)GetFnPtr(hLib, (char*)"FindTrack");
   ATrackToPosVel = (fnPtrATrackToPosVel)GetFnPtr(hLib, (char*)"ATrackToPosVel");
   TriGetDefParams = (fnPtrTriGetDefParams)GetFnPtr(hLib, (char*)"TriGetDefParams");
   TriComputeToFile = (fnPtrTriComputeToFile)GetFnPtr(hLib, (char*)"TriComputeToFile");
   TriCompute1 = (fnPtrTriCompute1)GetFnPtr(hLib, (char*)"TriCompute1");
   TriCompute2 = (fnPtrTriCompute2)GetFnPtr(hLib, (char*)"TriCompute2");
   TriCompute3 = (fnPtrTriCompute3)GetFnPtr(hLib, (char*)"TriCompute3");
   GetWaterfallAlt = (fnPtrGetWaterfallAlt)GetFnPtr(hLib, (char*)"GetWaterfallAlt");
   AnglesOnlyToLLH = (fnPtrAnglesOnlyToLLH)GetFnPtr(hLib, (char*)"AnglesOnlyToLLH");
   LombLengthOut = (fnPtrLombLengthOut)GetFnPtr(hLib, (char*)"LombLengthOut");
   Lomb = (fnPtrLomb)GetFnPtr(hLib, (char*)"Lomb");
   LombFalseProb = (fnPtrLombFalseProb)GetFnPtr(hLib, (char*)"LombFalseProb");
   LombFalseProbInv = (fnPtrLombFalseProbInv)GetFnPtr(hLib, (char*)"LombFalseProbInv");
   LombLengthCoef = (fnPtrLombLengthCoef)GetFnPtr(hLib, (char*)"LombLengthCoef");
   LombWaveFit = (fnPtrLombWaveFit)GetFnPtr(hLib, (char*)"LombWaveFit");
   LombCalcValueFromTime = (fnPtrLombCalcValueFromTime)GetFnPtr(hLib, (char*)"LombCalcValueFromTime");
   AngleBetweenObs = (fnPtrAngleBetweenObs)GetFnPtr(hLib, (char*)"AngleBetweenObs");
}



// Free ObsOpsDll
void FreeObsOpsDll()
{
   FreeLib(hLib, ObsOpsDll);
}
// ========================= End of auto generated code ==========================
