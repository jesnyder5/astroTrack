// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef BAMDLL_H
#define BAMDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define BamDll "Bam.dll"
#elif __APPLE__
  #define BamDll "libbam.dylib"
#else
  #define BamDll "libbam.so"
#endif


// Initializes Bam dll for use in the program
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if the Bam dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrBamInit)(__int64 apPtr);


// Returns information about the current version of Bam.dll. The information is placed in the string parameter you pass in
// infoStr            A string to hold the information about Bam.dll (out-Character[128])
typedef void (STDCALL *fnPtrBamGetInfo)(char infoStr[128]);


// Computes the number of time steps using the input start/end times and the step size
// startDs50UTC       start time in days since 1950, UTC (in-Double)
// stopDs50UTC        stop time in days since 1950, UTC (in-Double)
// stepSizeMin        step size in minutes (in-Double)
// returns number of time steps computed from the input time span and step size
typedef int (STDCALL *fnPtrBamCompNumTSs)(double startDs50UTC, double stopDs50UTC, double stepSizeMin);


// Computes and returns separate/missed distance data
// 
// The table below shows the indexes for the Separation Distance values contained in the extBamArr array:
// 
//     
//         Index
//         Index Interpretation
//     
//     0time at mininum average separate distances (ds50UTC)
//     1minimum average separate distance (km)
//     2average position X at minimum average separate distance (km)
//     3average position Y at minimum average separate distance (km)
//     4average position Z at minimum average separate distance (km)
//     5average velocity X at minimum average separate distance (km/s)
//     6average velocity Y at minimum average separate distance (km/s)
//     7average velocity Z at minimum average separate distance (km/s)
//     8average latitude at minimum average separate distance (deg)
//     9average longitude at minimum average separate distance (deg)
//     10average height at minimum average separate distance (km)
// 
// 
// The table below shows the indexes for the Miss Distance values contained in the extBamArr array:
// 
//     
//         Index
//         Index Interpretation
//     
//     20time at mininum average missed distances (ds50UTC)
//     21minimum average missed distance (km)
//     22average position X of satellites when they cross the pinch point plan (km)
//     23average position Y of satellites when they cross the pinch point plan (km)
//     24average position Z of satellites when they cross the pinch point plan (km)
//     25average velocity X of satellites when they cross the pinch point plan (km/s)
//     26average velocity Y of satellites when they cross the pinch point plan (km/s)
//     27average velocity Z of satellites when they cross the pinch point plan (km/s)
//     28average latitude of satellites when they cross the pinch point plan (deg)
//     29average longitude of satellites when they cross the pinch point plan (deg)
//     30average height of satellites when they cross the pinch point plan (km)
// 
// satKeys            array of satellite keys that wil be used in BAM (in-Long[*])
// numSats            the size of the satKeys array (in-Integer)
// startDs50UTC       start time in days since 1950, UTC (in-Double)
// stopDs50UTC        stop time in days since 1950, UTC (in-Double)
// stepSizeMin        step size in minutes (in-Double)
// avgSDs             average separate distances of all time steps (out-Double[*])
// avgMDs             average missed distances of all time steps (out-Double[*])
// extBamArr          other BAM resulting data (out-Double[64])
// errCode            0 if Bam is successful, non-0 if there is an error (out-Integer)
typedef void (STDCALL *fnPtrBamCompute)(__int64 satKeys[], int numSats, double startDs50UTC, double stopDs50UTC, double stepSizeMin, double avgSDs[], double avgMDs[], double extBamArr[64], int* errCode);


// Retrieves other BAM data
// 
// The table below shows the indexes for the values for the xf_bam parameter:
// 
//     
//         Index
//         Index Interpretation
//     
//     0times when satellites cross the pinch point plan (ds50UTC)
//     1missed distances from satellites to the pinch point (km)
//     2nadir angles of satellites when they cross the pinch point plan
//     3position Xs of satellites when they cross the pinch point plan (km)
//     4position Ys of satellites when they cross the pinch point plan (km)
//     5position Zs of satellites when they cross the pinch point plan (km)
//     6velocity Xs of satellites when they cross the pinch point plan (km/s)
//     7velocity Ys of satellites when they cross the pinch point plan (km/s)
//     8velocity Zs of satellites when they cross the pinch point plan (km/s)
//     9latitude of satellites when they cross the pinch point plan (deg)
//     10longitude of satellites when they cross the pinch point plan (deg)
//     11height of satellites when they cross the pinch point plan (km)
// 
// xf_bam             Predefined number specifying which BAM array to retrieve (in-Integer)
// bamArr             An array to store the retrieved result (out-Double[*])
typedef void (STDCALL *fnPtrBamGetResults)(int xf_bam, double bamArr[]);
  
  static const int  
     BAM_SD_TIME    =  0,    // TIME AT MININUM AVERAGE SEPARATE DISTANCES (DS50UTC)
     BAM_SD_DIST    =  1,    // MINIMUM AVERAGE SEPARATE DISTANCE (KM)
     BAM_SD_POSX    =  2,    // AVERAGE POSITION X AT MINIMUM AVERAGE SEPARATE DISTANCE (KM) 
     BAM_SD_POSY    =  3,    // AVERAGE POSITION Y AT MINIMUM AVERAGE SEPARATE DISTANCE (KM) 
     BAM_SD_POSZ    =  4,    // AVERAGE POSITION Z AT MINIMUM AVERAGE SEPARATE DISTANCE (KM) 
     BAM_SD_VELX    =  5,    // AVERAGE VELOCITY X AT MINIMUM AVERAGE SEPARATE DISTANCE (KM/S)
     BAM_SD_VELY    =  6,    // AVERAGE VELOCITY Y AT MINIMUM AVERAGE SEPARATE DISTANCE (KM/S)
     BAM_SD_VELZ    =  7,    // AVERAGE VELOCITY Z AT MINIMUM AVERAGE SEPARATE DISTANCE (KM/S)
     BAM_SD_LAT     =  8,    // AVERAGE LATITUDE AT MINIMUM AVERAGE SEPARATE DISTANCE (DEG) 
     BAM_SD_LON     =  9,    // AVERAGE LONGITUDE AT MINIMUM AVERAGE SEPARATE DISTANCE (DEG)  
     BAM_SD_HEIGHT  = 10,    // AVERAGE HEIGHT AT MINIMUM AVERAGE SEPARATE DISTANCE (KM) 
  
     BAM_MD_TIME    = 20,    // TIME AT MININUM AVERAGE MISSED DISTANCES (DS50UTC)
     BAM_MD_DIST    = 21,    // MINIMUM AVERAGE MISSED DISTANCE (KM)
     BAM_MD_POSX    = 22,    // AVERAGE POSITION X OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     BAM_MD_POSY    = 23,    // AVERAGE POSITION Y OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     BAM_MD_POSZ    = 24,    // AVERAGE POSITION Z OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     BAM_MD_VELX    = 25,    // AVERAGE VELOCITY X OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     BAM_MD_VELY    = 26,    // AVERAGE VELOCITY Y OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     BAM_MD_VELZ    = 27,    // AVERAGE VELOCITY Z OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     BAM_MD_LAT     = 28,    // AVERAGE LATITUDE OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (DEG) 
     BAM_MD_LON     = 29,    // AVERAGE LONGITUDE OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (DEG)  
     BAM_MD_HEIGHT  = 30,    // AVERAGE HEIGHT OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
  
     BAM_MD_SIZE    = 64;    
     
  static const int  
     XF_BAM_MDTIME  =  0,    // TIMES WHEN SATELLITES CROSS THE PINCH POINT PLAN (DS50UTC) 
     XF_BAM_RANGE   =  1,    // MISSED DISTANCES FROM SATELLITES TO THE PINCH POINT (KM)
     XF_BAM_NADIR   =  2,    // NADIR ANGLES OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN
     XF_BAM_POSX    =  3,    // POSITION XS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM)   
     XF_BAM_POSY    =  4,    // POSITION YS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     XF_BAM_POSZ    =  5,    // POSITION ZS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     XF_BAM_VELX    =  6,    // VELOCITY XS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     XF_BAM_VELY    =  7,    // VELOCITY YS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     XF_BAM_VELZ    =  8,    // VELOCITY ZS OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM/S)
     XF_BAM_LAT     =  9,    // LATITUDE OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (DEG) 
     XF_BAM_LON     = 10,    // LONGITUDE OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (DEG)  
     XF_BAM_HEIGHT  = 11;    // HEIGHT OF SATELLITES WHEN THEY CROSS THE PINCH POINT PLAN (KM) 
     
  
     
// BamDll's function pointers declaration
extern fnPtrBamInit                        BamInit;
extern fnPtrBamGetInfo                     BamGetInfo;
extern fnPtrBamCompNumTSs                  BamCompNumTSs;
extern fnPtrBamCompute                     BamCompute;
extern fnPtrBamGetResults                  BamGetResults;



void LoadBamDll();
void FreeBamDll();




#endif
// ========================= End of auto generated code ==========================
