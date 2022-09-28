// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef ELCOMPDLL_H
#define ELCOMPDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define ElCompDll "ElComp.dll"
#elif __APPLE__
  #define ElCompDll "libelcomp.dylib"
#else
  #define ElCompDll "libelcomp.so"
#endif


// Initializes ElComp dll for use in the program 
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if the ElComp dll is initialized successfully, non-0 if error
typedef int (STDCALL *fnPtrElCompInit)(__int64 apPtr);


// Returns information about the current version of ElComp.dll. The information is placed in the
// string parameter passed-in
// infoStr            A string to hold the information about ElComp.dll (out-Character[128])
typedef void (STDCALL *fnPtrElCompGetInfo)(char infoStr[128]);


// ElCompSetCriteria for ElComp 'Manual' mode which replaces default association status criteria
// for "FULL", including primary vs. secondary element comparison difference thresholds in 
// inclination, coplanar angle (determined as the dot product of the primary and secondary 
// angular momentum vectors), perigee height, eccentricity, orbital period, and argument of perigee.
// See ElCompGetCriteria for a description of the xa_ecdiff array.
// xa_ecdiff          Array to store manual setting criteria for "FULL" (MAX1 parameters only) (in-Double[32])
typedef void (STDCALL *fnPtrElCompSetCriteria)(double xa_ecdiff[32]);


// Retrieves criteria settings for ElComp
// 
// ElCompGetCriteria establishes the difference thresholds the element comparison program uses
// to evaluate the association statuses between the primary and secondary element sets.  The
// following values are the default settings for ELCOMP:
// 
// 
//     FULL element comparison, if all of the following criteria are met:
//         
//             Inclination                         difference less than      0.10 degrees
//             Angular Momentum Vector             difference less than      0.15 degrees
//             Perigee Height                      difference less than        25 km
//             Period                              difference less than      0.15 minutes
//             Eccentricity                        difference less than     0.005
//             argument of perigee (when e>.005)   difference less than         5 degrees
//         
//     CLOSE element comparison, if all the following criteria are met:
//         
//             Inclination                         difference less than      0.15 degrees
//             Angular Momentum Vector             difference less than      0.30 degrees
//             Perigee Height                      difference less than        75 km
//             Period                              difference less than      0.50 minutes
//             Eccentricity                        difference less than     0.015 
//             argument of perigee (when e>.005)   difference less than        10 degrees
//         
//     MAYBE element comparison, if all of the following criteria are met:
//         
//             Inclination                         difference less than      0.25 degrees
//             Angular Momentum Vector             difference less than      0.50 degrees
//             Perigee Height                      difference less than       100 km
//             Period                              difference less than      10.0 minutes
//             Eccentricity                        difference less than     0.025
//             argument of perigee (when e>.005)   difference less than        20 degrees
//         
//     If none of the combined criteria are met as described above, then ElComp found NONE in
//          the satellite comparison. The user may define their own criteria or use the automatic/
//          default criteria summarized above.
// 
// 
// Order of elements in the input xa_ecdiff array:
// 
// 
// Index
// Index Interpretation
// 
//  0  inclination difference criteria for FULL evaluation, [degrees]
//  1  inclination difference criteria for CLOSE evaluation, [degrees]
//  2  inclination difference criteria for MAYBE evaluation, [degrees]
//  3  w Angular Momentum Vector dot product criteria for FULL evalutation, [degrees]
//  4  w Angular Momentum Vector dot product criteria for CLOSE evalutation, [degrees]
//  5  w Angular Momentum Vector dot product criteria for MAYBE evalutation, [degrees]
//  6  Perigee height difference criteria for FULL evaluation, [kilometers]
//  7  Perigee height difference criteria for CLOSE evaluation, [kilometers]
//  8  Perigee height difference criteria for MAYBE evaluation, [kilometers]
//  9  Eccentricity difference criteria for FULL evaluation
// 10  Eccentricity difference criteria for CLOSE evaluation
// 11  Eccentricity difference criteria for MAYBE evaluation
// 12  Period difference criteria for FULL evaluation
// 13  Period difference criteria for CLOSE evaluation
// 14  Period difference criteria for MAYBE evaluation
// 15  Argument of Perigee difference criteria for FULL evaluation
// 16  Argument of Perigee difference criteria for CLOSE evaluation
// 17  Argument of Perigee difference criteria for MAYBE evaluation
// 18-31  unused at this time  
//       
// xa_ecdiff          Array to receive the ElComp criteria (out-Double[32])
typedef void (STDCALL *fnPtrElCompGetCriteria)(double xa_ecdiff[32]);


// ElCompGetResults executes ELCOMP, Element Comparison, to evaluate two element sets loaded
//   via their satKeys 
// 
// 
// ELCOMP software description:
// 
//   ElCompGetResults executes ELCOMP, Element Comparison, to evaluate two element sets loaded
//   via their satKeys 
// 
// 
// ELCOMP algorithm:
// 
//   ELCOMP uses inclination, right ascension of ascending node, perigee height, eccentricity,
//   period, argument of perigee, nodal crossing time, orbit plane alignment (via dot product
//   between the primary and secondary angular momentum vectors), and East Longitude (for
//   Geosynchronous orbits) to evaluate the degree of similarity between primary and secondary
//   element sets (orbit definitions) in terms of their relative size, shape, and orientation.
//   ELCOMP computes a correction, due to drag, to the nodal crossing time for each elset as part
//   of the nodal crossing time-difference evaluation. Because the epoch times of the primary and
//   secondary element sets are rarely the same, ELCOMP updates time-variant quantities to a
//   common time prior to element comparison.  Element sets with epochs that differ by more than
//   90 days are not evaluated.  Time-variant quantities updated to a common time include:
//   Right Ascension of Ascending Node, Argument of Perigee, and East Longitude (for Geosynchronous
//   oribts).  Time-variant quantities are updated to a common time by using the difference in
//   epoch times between the primary and secondary element sets and by determining the change
//   in argument of perigee with respect to time, the change in Right Ascension of Ascending
//   Node with respect to time, and for geosynchronous orbits, the East Longitude drift rate. 
//   ELCOMP also sets the nodal-crossing time criteria according to orbit type and epoch age,
//   allowing for longer nodal-crossing time differences for deep-space orbits versus near-Earth,
//   and longer time differences with greater differences in epoch, while also taking into account
//   perigee height for more circular orbits.  Argument of perigee is evaluated for eccentricities
//   greater than 0.005 only.  This is because for very-near circular orbits, the argement of perigee
//   becomes ill-defined such that perigee may vary widely due to epoch time difference, when in
//   fact the orbits are the same.  User-specified or default thresholds, along with orbital
//   element comparison differences are used by ELCOMP to produce an element comparison association
//   status for each primary-secondary pair.  Association statuses include FULL, CLOSE, MAYBE,
//   and NONE.  A typical application for ELCOMP is to automate determining if a new or external
//   element set is a duplicate or very similar element set to an existing internal element set
//   within a large catalog of element sets.
// 
// 
// INPUTS include:
// 
//   (a) Primary element set to compare
//   (b) Secondary element set to be compared against
//   
//       (c)
//        
//          Specified orbital element comparison threshold values for FULL, CLOSE, MAYBE, and NONE
//       association statuses.  Specified element comparison thresholds include:
//         
//         
//         inclination
//         plane
//         perigee height
//         eccentricity
//         period
//         argument of perigee 
//         
//       
//   
// 
// 
// 
// OUTPUTS include:
//   (a) Evaluation results of FULL, CLOSE, MAYBE, or NONE for each primary-secondary element
//       set pair
// 
// Order of the input xa_elcom_pri(16) array - primary TLE satellite data:
// 
// 
// Index
// Index Interpretation
// 
// 0  inclination [degrees]
// 1  right ascension of ascending node [degrees]
// 2  eccentricity [unitless]
// 3  argument of perigee [degrees]
// 4  mean anomaly [degrees]
// 5  mean motion [revs/day]
// 6  epoch [fractional days since 1950]
// 7-15  not used at this time
//    
// Order of the input xa_elcomp_sec(16) array - secondary TLE sat data, is same order as primary
// 
// Order of the output xa_elcomp_deltas(16) array - delta quantities between primary and secondary
// 
// 
// Index
// Index Interpretation
// 
// 0  delta Inclination [degrees]
// 1  delta Right Ascension of Ascending Node (RAAN) [degrees]
// 2  delta Perigeee Height [kilometers]
// 3  delta Orbital Period [minutes]
// 4  delta Coplanar angle (dot product of the w angular momentum vetors) [degrees]
// 5  delta Right Ascension dot (rate of change of the delta RAAN) [degrees/day]
// 6  delta Nodal crossing time [minutes]
// 7  number of fractional days to achieve 0.0 delta in RAAN, if 
// 8  Flag - sustained close approach possible, if non-zero
// 9  Flag - possible constellation member, if non-zero
//    
// 
//  elcom_astat possible return values:
// 
// 
// Value
// Interpretation
// 
// 1  FULL
// 2  CLOSE
// 3  MAYBE
// 4  NONE
//    
// priSatKey          The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// checkDeltaTime     Suppress=0/Allow=1: check on nodal time and sync long (in-Integer)
// xa_elcom_pri       primary satellite data (out-Double[16])
// xa_elcom_sec       secondary satellite data (out-Double[16])
// xa_elcom_deltas    delta quantities between primary and secondary satellites (out-Double[16])
// elcom_astat        =1:FULL, =2:CLOSE, =3:MAYBE, =4:NONE (out-Integer)
// returns 0 if ElComp is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrElCompGetResults)(__int64 priSatKey, __int64 secSatKey, int checkDeltaTime, double xa_elcom_pri[16], double xa_elcom_sec[16], double xa_elcom_deltas[16], int* elcom_astat);


// Returns comparison results between two elsets without loading the elsets into memory
// See ElCompGetResults for a description of the input and output values.
// checkDeltaTime     Supress=0/Allow=1: check on nodal time and sync long (in-Integer)
// xa_elcom_pri       primary satellite data   : 0:incli, 1:node, 2:E, 3:omega, 4: mean anomaly, 5:mean motion, 6:epoch (in-Double[16])
// xa_elcom_sec       secondary satellite data : 0:incli, 1:node, 2:E, 3:omega, 4: mean anomaly, 5:mean motion, 6:epoch (in-Double[16])
// xa_elcom_deltas    delta quantities between primary and secondary satellites (out-Double[16])
// elcom_astat        =1:FULL, =2:CLOSE, =3:MAYBE, =4:not assoc (out-Integer)
typedef void (STDCALL *fnPtrElCompFrElData)(int checkDeltaTime, double xa_elcom_pri[16], double xa_elcom_sec[16], double xa_elcom_deltas[16], int* elcom_astat);


// Resets criteria to default values for ElComp 
typedef void (STDCALL *fnPtrElCompResetCriteria)();


// Sets up criteria for Coco 
// See CocoGetCriteria for a description of the input and output values.
// xa_ecdiff          Array to set the Coco criteria (in-Double[32])
typedef void (STDCALL *fnPtrCocoSetCriteria)(double xa_ecdiff[32]);


// Retrieves criteria settings for Coco
// 
// Order of elements in the input xa_ecdiff array:
// 
// 
// Index
// Index Interpretation
// 
//  0  inclination difference criteria for SAME evaluation, [degrees]
//  1  inclination difference criteria for CLOSE evaluation, [degrees]
//  2  inclination difference criteria for NEARBY evaluation, [degrees]
//  3  w Angular Momentum Vector dot product criteria for SAME evalutation, [degrees]
//  4  w Angular Momentum Vector dot product criteria for CLOSE evalutation, [degrees]
//  5  w Angular Momentum Vector dot product criteria for NEARBY evalutation, [degrees]
//  6  Perigee height difference criteria for SAME evaluation, [kilometers]
//  7  Perigee height difference criteria for CLOSE evaluation, [kilometers]
//  8  Perigee height difference criteria for NEARBY evaluation, [kilometers]
//  9  Eccentricity difference criteria for SAME evaluation
// 10  Eccentricity difference criteria for CLOSE evaluation
// 11  Eccentricity difference criteria for NEARBY evaluation
// 12  Period difference criteria for SAME evaluation
// 13  Period difference criteria for CLOSE evaluation
// 14  Period difference criteria for NEARBY evaluation
// 15  Argument of Perigee difference criteria for SAME evaluation
// 16  Argument of Perigee difference criteria for CLOSE evaluation
// 17  Argument of Perigee difference criteria for NEARBY evaluation
// 18-31  unused at this time
//    
// xa_ecdiff          Array to receive the Coco criteria (out-Double[32])
typedef void (STDCALL *fnPtrCocoGetCriteria)(double xa_ecdiff[32]);


//   CocoGetResults executes COCO, Computation of coplanar Orbits, to evaluate two element sets
//   loaded via their satKeys.   
// COCO software description:
//   CocoGetResults executes COCO, Computation of coplanar Orbits, to evaluate two element sets
//   loaded via their satKeys.   
// COCO algortihm:
//   A primary element set is compared to a secondary element set using criteria summarized
//   above. The program uses data from standard two-line element sets (TLEs) as input.  The COCO
//   program was modified to allow for nodal crossing time comparison when the input element sets
//   are not at the node, and thereby addresses various inherent Keplerian orbital-element
//   comparison difficulties by accounting for nodal-crossing time differences between primary
//   and secondary element sets which are rarely epoched to the time of nodal crossing. COCO
//   uses inclination, right ascension of ascending node, perigee height, eccentricity, period,
//   argument of perigee, and nodal crossing time (via dot product between the primary and secondary
//   angular momentum vectors), to evaluate the degree of coplanarness between a primary and 
//   secondary element set in terms of their relative size, shape, and orientation.  COCO 
//   computes a correction, due to drag, to the nodal crossing time for each elset as part of 
//   the nodal cross time-difference evaluation.
// INPUTS include:
//   (a) Primary element set to compare
//   (b) Secondary element set to be compared against
//   (c) Specified orbital element threshold values for SAME, CLOSE, and NEARBY coplanar
//       definitions. Specified orbital element thresholds include:
//         inclination
//         plane
//         perigee height
//         eccentricity
//         period
//         argument of perigee 
// OUTPUTS include:
//   (a) Evaluation results of SAME, CLOSE, NEARBY, or NO MATCH for each primary-secondary element
//       set pair
//   (b) Special advisories for comparisons that evaluate to:
//         SUSTAINED CLOSE APPROACH POSSIBLE
//         POSSIBLE CONSTELLATION MEMBER
//         RIGHT ASCENSION OF ASCENDING NODE DIFFERENCE WILL BE 0.0 WITHIN 60 DAYS (along with the
//         estimated number of days to 0.0 degrees nodal nodal crossing difference)
// priSatKey          The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// xa_satData_pri     primary satellite data (see order below) (out-Double[16])
// xa_satData_sec     secondary satellite data (see order below) (out-Double[16])
// xa_coco            primary v.secondary delta quantities (see below) (out-Double[16])
// coco_astat         =1:SAME, =2:CLOSE, =5:not assoc (out-Integer)
// returns 0 if Coco is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrCocoGetResults)(__int64 priSatKey, __int64 secSatKey, double xa_satData_pri[16], double xa_satData_sec[16], double xa_coco[16], int* coco_astat);


//   CocoGetResultsWOA executes COCO, Computation of coplanar Orbits, to evaluate two element sets
//   loaded via their satKeys. It's similar to CocoGetResults but without returning the ASTAT value
// priSatKey          The primary satellite's unique key (in-Long)
// secSatKey          The secondary satellite's unique key (in-Long)
// xa_satData_pri     primary satellite data (see order below) (out-Double[16])
// xa_satData_sec     secondary satellite data (see order below) (out-Double[16])
// xa_coco            primary v.secondary delta quantities (see below) (out-Double[16])
// returns 0 if Coco is successful, non-0 if there is an error
typedef int (STDCALL *fnPtrCocoGetResultsWOA)(__int64 priSatKey, __int64 secSatKey, double xa_satData_pri[16], double xa_satData_sec[16], double xa_coco[16]);


// Returns comparison results between two elsets without loading the elsets into TLE dll
// 
// Order of the input xa_satData_pri(16) array - primary satellite data:
// 
// 
// Index
// Index Interpretation
// 
// 0  inclination [degrees]
// 1  right ascension of ascending node [degrees]
// 2  eccentricity [unitless]
// 3  argument of perigee [degrees]
// 4  mean anomaly [degrees]
// 5  mean motion [revs/day]
// 6  epoch [fractional days since 1950]
// 7-15  not used at this time
//    
// 
// Order of the input xa_satData_sec(16) array - secondary sat data, is same order as primary
// 
// Order of the output xa_coco(16) array - delta quantities between primary and secondary
// 
// 
// Index
// Index Interpretation
// 
// 0  delta Inclination [degrees]
// 1  delta Right Ascension of Ascending Node (RAAN) [degrees]
// 2  delta Perigeee Height [kilometers]
// 3  delta Orbital Period [minutes]
// 4  delta Coplanar angle (dot product of the w angular momentum vetors) [degrees]
// 5  delta Right Ascension dot (rate of change of the delta RAAN) [degrees/day]
// 6  delta Nodal crossing time [minutes]
// 7  number of fractional days to achieve 0.0 delta in RAAN, if 
// 8  Flag - sustained close approach possible, if non-zero
// 9  Flag - possible constellation member, if non-zero
//    
// 
//  coco_astat possible return values:
// 
// 
// Value
// Interpretation
// 
// 1  SAME
// 2  CLOSE
// 3  NEARBY
// 5  NONE
//    
// xa_satData_pri     primary sat data, see XA_SATDATA_? for array arrangement (in-Double[16])
// xa_satData_sec     secondary sat data, see XA_SATDATA_? for array arrangement (in-Double[16])
// xa_coco            delta quantities between pri/sec satellites, see XA_COCO_? for array arrangement (out-Double[16])
// coco_astat         resulting astat value; 1=SAME, 2=CLOSE, 3=NEARBY, 5=NONE (out-Integer)
typedef void (STDCALL *fnPtrCocoFrElData)(double xa_satData_pri[16], double xa_satData_sec[16], double xa_coco[16], int* coco_astat);


// Returns comparison results between two elsets without loading the elsets into TLE dll. It's similar to CocoFrElData but without returning the ASTAT value
// xa_satData_pri     primary sat data, see XA_SATDATA_? for array arrangement (in-Double[16])
// xa_satData_sec     secondary sat data, see XA_SATDATA_? for array arrangement (in-Double[16])
// xa_coco            delta quantities between pri/sec satellites, see XA_COCO_? for array arrangement (out-Double[16])
typedef void (STDCALL *fnPtrCocoFrElDataWOA)(double xa_satData_pri[16], double xa_satData_sec[16], double xa_coco[16]);


// Resets criteria to default values for Coco 
typedef void (STDCALL *fnPtrCocoResetCriteria)();
     
  // INDEXES FOR ELCOMP REFERENCE SAT DATA AND DELTAS   
  static const int     
     XA_ELCOM_INCLI    =  0,     // INCLINATION (DEG)
     XA_ELCOM_NODE     =  1,     // RIGHT ASCENSION OF THE ASENDING NODE (DEG) 
     XA_ELCOM_E        =  2,     // ECCENTRICITY (UNITLESS)    
     XA_ELCOM_OMEGA    =  3,     // ARGUMENT OF PERIGEE (DEG) 
     XA_ELCOM_MNANOM   =  4,     // MEAN ANOMALY (DEG)
     XA_ELCOM_MNMOTION =  5,     // MEAN MOTION (REVS/DAY)
     XA_ELCOM_EPOCH    =  6,     // EPOCH IN DAYS SINCE 1950, UTC
     
     XA_ELCOM_PHT      =  7,     // PERIGEE HEIGHT (KM) 
     XA_ELCOM_PERIOD   =  8,     // PERIOD (MIN)
     XA_ELCOM_TNODE    =  9,     // DELTA T BETWEEN NODAL CROSSING TIMES (MIN)
     XA_ELCOM_LONGE    = 10,     // DELTA EAST LONGITUDE FOR GEO SATELLITES (DEG)
     
     XA_ELCOM_SIZE     = 16;
     
  // INDEXES FOR SETTING CRITERIA FOR FULL, CLOSE, MAYBE
  static const int     
     XA_ECDIFF_INCMAX1  =  0,    // INCLI DIFF IN DEG - FULL
     XA_ECDIFF_INCMAX2  =  1,    // INCLI DIFF IN DEG - CLOSE
     XA_ECDIFF_INCMAX3  =  2,    // INCLI DIFF IN DEG - MAYBE
     
     XA_ECDIFF_RAMAX1   =  3,    // W VECTOR DOT PRODUCT IN DEG - FULL
     XA_ECDIFF_RAMAX2   =  4,    // W VECTOR DOT PRODUCT IN DEG - CLOSE
     XA_ECDIFF_RAMAX3   =  5,    // W VECTOR DOT PRODUCT IN DEG - MAYBE
     
     XA_ECDIFF_PHTMAX1  =  6,    // PERIGEE HEIGHT DIFF IN KM - FULL
     XA_ECDIFF_PHTMAX2  =  7,    // PERIGEE HEIGHT DIFF IN KM - CLOSE
     XA_ECDIFF_PHTMAX3  =  8,    // PERIGEE HEIGHT DIFF IN KM - MAYBE
     
     XA_ECDIFF_ECCMAX1  =  9,    // ECCENTRICITY DIFF - FULL
     XA_ECDIFF_ECCMAX2  = 10,    // ECCENTRICITY DIFF - CLOSE
     XA_ECDIFF_ECCMAX3  = 11,    // ECCENTRICITY DIFF - MAYBE
     
     XA_ECDIFF_PERMAX1  = 12,    // PERIOD DIFF IN MIN - FULL
     XA_ECDIFF_PERMAX2  = 13,    // PERIOD DIFF IN MIN - CLOSE
     XA_ECDIFF_PERMAX3  = 14,    // PERIOD DIFF IN MIN - MAYBE
     
     XA_ECDIFF_APMAX1   = 15,    // ARGUMENT OF PERIGEE DIFF IN DEG - FULL
     XA_ECDIFF_APMAX2   = 16,    // ARGUMENT OF PERIGEE DIFF IN DEG - CLOSE
     XA_ECDIFF_APMAX3   = 17,    // ARGUMENT OF PERIGEE DIFF IN DEG - MAYBE
     
     XA_ECDIFF_SIZE     = 32;   
     
  // INDEXES FOR ASSOCIATION STATUS FROM ELCOMP   
  static const int  
     ELCOM_ASTAT_FULL  = 1,     // "FULL" ASSOCIATION
     ELCOM_ASTAT_CLOSE = 2,     // "CLOSE" ASSOCIATION
     ELCOM_ASTAT_MAYBE = 3,     // "MAYBE" ASSOCIATION
     ELCOM_ASTAT_NONE  = 4;     // "NONE" ASSOCIATION
     
  // INDEXES FOR SETTING CRITERIA FOR FULL, CLOSE, MAYBE
  static const int     
     XA_COCODIFF_INCMAX1  =  0,    // INCLI DIFF IN DEG - SAME
     XA_COCODIFF_INCMAX2  =  1,    // INCLI DIFF IN DEG - CLOSE
     XA_COCODIFF_INCMAX3  =  2,    // INCLI DIFF IN DEG - NEAR-BY
     
     XA_COCODIFF_RAMAX1   =  3,    // W VECTOR DOT PRODUCT IN DEG - SAME
     XA_COCODIFF_RAMAX2   =  4,    // W VECTOR DOT PRODUCT IN DEG - CLOSE
     XA_COCODIFF_RAMAX3   =  5,    // W VECTOR DOT PRODUCT IN DEG - NEAR-BY
     
     XA_COCODIFF_PHTMAX1  =  6,    // PERIGEE HEIGHT DIFF IN KM - SAME
     XA_COCODIFF_PHTMAX2  =  7,    // PERIGEE HEIGHT DIFF IN KM - CLOSE
     XA_COCODIFF_PHTMAX3  =  8,    // PERIGEE HEIGHT DIFF IN KM - NEAR-BY
     
     XA_COCODIFF_PERMAX1  =  9,    // PERIOD DIFF IN MIN - SAME
     XA_COCODIFF_PERMAX2  = 10,    // PERIOD DIFF IN MIN - CLOSE
     XA_COCODIFF_PERMAX3  = 11,    // PERIOD DIFF IN MIN - NEAR-BY
     
     XA_COCODIFF_SIZE     = 32;   
  
     
  // INDEXES FOR COCO SAT DATA AND COPLANAR DELTAS FIELDS
  static const int     
     XA_SATDATA_INCLI    =  0,     // INCLINATION (DEG)
     XA_SATDATA_NODE     =  1,     // RIGHT ASCENSION OF THE ASENDING NODE (DEG) 
     XA_SATDATA_E        =  2,     // ECCENTRICITY (UNITLESS)    
     XA_SATDATA_OMEGA    =  3,     // ARGUMENT OF PERIGEE (DEG) 
     XA_SATDATA_MNANOM   =  4,     // MEAN ANOMALY (DEG)
     XA_SATDATA_MNMOTION =  5,     // MEAN MOTION (REVS/DAY)
     XA_SATDATA_EPOCH    =  6,     // EPOCH IN DAYS SINCE 1950, UTC
     
     XA_SATDATA_PHT      =  7,     // PERIGEE HEIGHT (KM) 
     XA_SATDATA_PERIOD   =  8,     // PERIOD (MIN)
     
     XA_SATDATA_SIZE     = 16;
     
     
  // INDEXES FOR COCO SAT DATA AND COPLANAR DELTAS FIELDS
  static const int     
     XA_COCO_INCLI    =  0,     // INCLINATION (DEG)
     XA_COCO_NODE     =  1,     // RIGHT ASCENSION OF THE ASENDING NODE (DEG) 
     XA_COCO_PHT      =  2,     // PERIGEE HEIGHT (KM) 
     XA_COCO_PERIOD   =  3,     // PERIOD (MIN)
     XA_COCO_WDOT     =  4,     // COPLANAR ANGLE (DOT THE W VECTORS) (DEG) 
     XA_COCO_RADOT    =  5,     // RIGHT ASCENSION DOT (DEG/DAY)
     XA_COCO_TNODE    =  6,     // NODAL CROSSING (MIN)   
     XA_COCO_TZERO    =  7,     // TIME IN DAYS TO APPROACH 0.0 RA DELTA
     XA_COCO_SCAP     =  8,     // SUSTAINED CLOSE APPROACH POSSIBLE
     XA_COCO_PCM      =  9,     // POTENTIAL CONSTELLATION MEMBER
     XA_COCO_PNODALX  = 10,     // TIME IN DS50UTC WHEN PRIMARY AT NODAL CROSSING (PRIOR TO ITS EPOCH)
     XA_COCO_SNODALX  = 11,     // TIME IN DS50UTC WHEN SECONDARY AT NODAL CROSSING (AFTER PRIMARY NODAL CROSSING TIME)
     
     XA_COCO_SIZE     = 16;   
     
     
  // INDEXES FOR ASSOCIATION STATUS FROM COCO  
  static const int  
     COCO_ASTAT_SAME   = 1,     // "SAME" ASSOCIATION
     COCO_ASTAT_CLOSE  = 2,     // "CLOSE" ASSOCIATION
     COCO_ASTAT_NEARBY = 3,     // "NEARBY" ASSOCIATION
     COCO_ASTAT_NONE   = 5;     // "NONE" ASSOCIATION
  
// ElCompDll's function pointers declaration
extern fnPtrElCompInit                     ElCompInit;
extern fnPtrElCompGetInfo                  ElCompGetInfo;
extern fnPtrElCompSetCriteria              ElCompSetCriteria;
extern fnPtrElCompGetCriteria              ElCompGetCriteria;
extern fnPtrElCompGetResults               ElCompGetResults;
extern fnPtrElCompFrElData                 ElCompFrElData;
extern fnPtrElCompResetCriteria            ElCompResetCriteria;
extern fnPtrCocoSetCriteria                CocoSetCriteria;
extern fnPtrCocoGetCriteria                CocoGetCriteria;
extern fnPtrCocoGetResults                 CocoGetResults;
extern fnPtrCocoGetResultsWOA              CocoGetResultsWOA;
extern fnPtrCocoFrElData                   CocoFrElData;
extern fnPtrCocoFrElDataWOA                CocoFrElDataWOA;
extern fnPtrCocoResetCriteria              CocoResetCriteria;



void LoadElCompDll();
void FreeElCompDll();




#endif
// ========================= End of auto generated code ==========================
