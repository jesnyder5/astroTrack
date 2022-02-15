// This wrapper file was generated automatically by the A3\GenDllWrappers program.

#ifndef SENSORDLL_H
#define SENSORDLL_H

#include "services/DllUtils.h"

// Provide the path to the dll/so
#ifdef _WIN32
  #define SensorDll "Sensor.dll"
#else
  #define SensorDll "libsensor.so"
#endif


// Initializes Sensor DLL for use in the program
// If this function returns an error, it is recommended that the users stop the program immediately. 
// The error occurs if the users forget to load and initialize all the prerequisite dlls, as listed 
// in the DLL Prerequisite section, before using this DLL.
// apPtr              The handle that was returned from DllMainInit() (in-Long)
// returns 0 if Sensor.dll is initialized successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorInit)(__int64 apPtr);


// Returns information about the current version of Sensor DLL. 
// The information is placed in the string parameter passed in.
// The returned string provides information about the version number, build date, and the platform of the Sensor DLL.
// infoStr            A string to hold the information about Sensor.dll (out-Character[128])
typedef void (STDCALL *fnPtrSensorGetInfo)(char infoStr[128]);


// Loads sensor data, contained in a text file, into the set of loaded sensors
// The users can use this function repeatedly to load sensor data from different input files. 
// However, only unique senKeys are stored in the binary tree.  New sensor data will overwrite the existing data. 
// 
// Sensor data can be included directly in the main input file or they can be read from a separate file 
// identified with "SENFIL=[pathname\filename]".
// 
// This function only reads sensor data from the main input file or the file identified with SENFIL in the input file. 
// It won't read anything else.
// senFile            The name of the file containing sensor data (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorLoadFile)(char senFile[512]);


// Loads a single sensor-typed card
// card               Any single sensor-typed card (in-Character[512])
// returns 0 if the input card is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorLoadCard)(char card[512]);


// Saves the currently loaded sensor data to a file
// If the users call this routine immediately after the SensorLoadFile(). 
// The sensor data contents in the two file should be the same (minus duplicated sensors or bad sensors).
// 
// The purpose of this function is to save the current state of the loaded sensors, usually used in GUI applications, for future use.
// sensorFile         The name of the file in which to save the settings (in-Character[512])
// saveMode           Specifies whether to create a new file or append to an existing one (0 = create, 1= append) (in-Integer)
// saveForm           Specifies the mode in which to save the file (0 = text format, 1 = not yet implemented, reserved for future) (in-Integer)
// returns 0 if the data is successfully saved to the file, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSaveFile)(char sensorFile[512], int saveMode, int saveForm);


// Removes a sensor, represented by the senKey, from the set of currently loaded sensors
// If the users enter an invalid senKey - a non-existing senKey, the function will return a non-zero value indicating an error.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// returns 0 if the sensor is successfully removed, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorRemove)(int senKey);


// Removes all currently loaded sensors from memory
// The function returns zero if all the loaded sensors are removed successfully from the SENSOR DLL's binary tree. Other values indicate an error.
// returns 0 if all the loaded sensors are removed successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorRemoveAll)();


// Returns the number of sensors currently loaded
// See SensorGetLoaded for example.
// This function is useful for dynamically allocating memory for the array that is passed to the function SensorGetLoaded().
// returns the number of sensors currently loaded
typedef int (STDCALL *fnPtrSensorGetCount)();


// Retrieves all of the currently loaded senKeys. 
// These senKeys can be used to access the internal data for the sensors.
// It is recommended that SensorGetCount() is used to count how many sensors are currently loaded in the SENSOR DLL's binary tree. 
// The user can then use this number to dynamically allocate the senKeys array and pass it to this function. 
// 
// If the users prefer to pass a static array to the function, make sure it is big enough to store all the senKeys in memory.
// order              Specifies the order in which the senKeys should be returned:0=Sort in ascending order, 1=Sort in descending order, 2=Sort in the order in which the senKeys were loaded in memory (in-Integer)
// senKeys            The array in which to store the senKeys (out-Integer[*])
typedef void (STDCALL *fnPtrSensorGetLoaded)(int order, int senKeys[]);


// Retrieves sensor location data for a sensor
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// astroLat           Astronomical Latitude (deg): astroLat[-90, 90], (+ = North; - = South) (out-Double)
// astroLon           Astronomical Longitude (deg): astroLon[-360, 360], (+ = West; - = East) (out-Double)
// senPos             Sensor XYZ geocentric position (meters) (out-Double[3])
// senDesc            Sensor location description (out-Character[24])
// orbSatNum          For orbiting sensors, this is the associated satellite number. For ground sensors, orbSatNum = 0 (out-Integer)
// secClass           Sensor classification: U = Unclassified, C = Confidential, S = Secret (out-Character)
// returns 0 if all sensor location data fields are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetLocAll)(int senKey, double* astroLat, double* astroLon, double senPos[3], char senDesc[24], int* orbSatNum, char* secClass);


// Adds/updates sensor location data for a sensor using individually provided field values
// This function is shared between ground sensors and orbiting sensors. The users need to provide the proper data fields for each sensor type.
// 
// If the function is invoked with a senKey that already exists in the SENSOR DLL's binary tree, the senKey's associated data will be updated with the provided data.
// 
// If it is an orbiting sensor, the users need to provide the associated satellite number.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// astroLat           Astronomical Latitude (deg): astroLat[-90, 90], (+ = North; - = South) (in-Double)
// astroLon           Astronomical Longitude (deg): astroLon[-360, 360], (+ = West; - = East) (in-Double)
// senPos             Sensor XYZ geocentric position (meters) (in-Double[3])
// senDesc            Sensor location description (in-Character[24])
// orbSatNum          For orbiting sensors, this is the associated satellite number. For ground sensors, orbSatNum = 0 (in-Integer)
// secClass           Sensor classification: U = Unclassified, C = Confidential, S = Secret (in-Character)
// returns 0 if the sensor location data is added/updated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSetLocAll)(int senKey, double astroLat, double astroLon, double senPos[3], char senDesc[24], int orbSatNum, char secClass);


// Retrieves the value of an individual field of sensor location data
// 
// Make sure to use the appropriate field index for ground sensors and orbiting sensors.
// 
// The table below shows the values for the xf_SenLoc parameter:
// 
// 
// Index
// Index Interpretation
// 
// 1Sensor number
// 2Sensor astronomical latitude (deg)
// 3Sensor astronomical longitude (deg)
// 4Sensor position X (km)
// 5Sensor position Y (km)
// 6Sensor position Z (km)
// 7Sensor description
// 8Orbiting sensor's number (satnum)   
// 9Sensor classification    
//    
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xf_SenLoc          Predefined number specifying which field to retrieve (in-Integer)
// strValue           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the sensor location data is successfully retrieved, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetLocField)(int senKey, int xf_SenLoc, char strValue[512]);


// Updates the value of an individual field of sensor location data
// See SensorGetLocField for a description of the xf_SenLoc values.
// The set value type was intentionally chosen as a character string because it allows the users to set value for different data types.
// 
// Make sure to use the appropriate field index for ground sensors and orbiting sensors.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xf_SenLoc          Predefined number specifying which field to retrieve (in-Integer)
// strValue           The new value of the specified field, expressed as a string (in-Character[512])
// returns 0 if the sensor location data is successfully updated, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSetLocField)(int senKey, int xf_SenLoc, char strValue[512]);


// Retrieves sensor limits data
// This function is shared between ground sensors and orbiting sensors. Make sure to interpret the data correctly.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// viewType           Sensor viewing type (out-Character)
// obsType            Sensor observation type (out-Character)
// rngUnits           Units of range and range rate: 0=km, km/sec, 1=nm, nm/sec (out-Integer)
// maxRngLim          Maximum observable range limit (km) (out-Double)
// boresight1         Orbiting sensor boresight1 vector (out-Character)
// elLim1             Elevation limit #1 (low, deg) OR orbiting sensor off-boresight angle (out-Double)
// elLim2             Elevation limit #2 (high, deg) OR orbiting sensor off-boresight angle (out-Double)
// azLim1             Azimuth limit #1 (left, deg) OR orbiting sensor clock angle (out-Double)
// azLim2             Azimuth limit #2 (right, deg) OR orbiting sensor clock angle (out-Double)
// interval           ouput interval (min) (out-Double)
// visFlg             Visual pass control flag (out-Integer)
// rngLimFlg          Range limits control flag (out-Integer)
// maxPPP             Max number of points per pass (0=unlimited) (out-Integer)
// minRngLim          Minimum observable range limit (km) (out-Double)
// plntryRes          Orbiting sensor planetary restrictions (out-Integer)
// rrLim              Range rate/relative velocity limit (km/sec) (out-Double)
// returns 0 if all sensor limits data fields are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGet1L)(int senKey, char* viewType, char* obsType, int* rngUnits, double* maxRngLim, char* boresight1, double* elLim1, double* elLim2, double* azLim1, double* azLim2, double* interval, int* visFlg, int* rngLimFlg, int* maxPPP, double* minRngLim, int* plntryRes, double* rrLim);


// Adds/updates sensor limits data via individually provided field values
// This function is shared between ground sensors and orbiting sensors. The users need to provide the proper data fields for each sensor type.
// 
// If the function is invoked with a senKey that already exists in the SENSOR DLL's binary tree, the senKey's associated data will be updated with the provided data.
// 
// If it is an orbiting sensor, the users need to provide the associated satellite number.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// viewType           Sensor viewing type (in-Character)
// obsType            Sensor observation type (in-Character)
// rngUnits           Units of range and range rate: 0=km, km/sec, 1=nm, nm/sec (in-Integer)
// maxRngLim          Maximum observable range limit (km) (in-Double)
// boresight1         Orbiting sensor boresight1 vector (in-Character)
// elLim1             Elevation limit #1 (low, deg) OR orbiting sensor off-boresight angle (in-Double)
// elLim2             Elevation limit #2 (high, deg) OR orbiting sensor off-boresight angle (in-Double)
// azLim1             Azimuth limit #1 (left, deg) OR orbiting sensor clock angle (in-Double)
// azLim2             Azimuth limit #2 (right, deg) OR orbiting sensor clock angle (in-Double)
// interval           ouput interval (min) (in-Double)
// visFlg             Visual pass control flag (in-Integer)
// rngLimFlg          Range limits control flag (in-Integer)
// maxPPP             Max number of points per pass (0=unlimited) (in-Integer)
// minRngLim          Minimum observable range limit (km) (in-Double)
// plntryRes          Orbiting sensor planetary restrictions (in-Integer)
// rrLim              Range rate/relative velocity limit (km/sec) (in-Double)
// returns 0 if the sensor limits data is added/updated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSet1L)(int senKey, char viewType, char obsType, int rngUnits, double maxRngLim, char boresight1, double elLim1, double elLim2, double azLim1, double azLim2, double interval, int visFlg, int rngLimFlg, int maxPPP, double minRngLim, int plntryRes, double rrLim);


// Retrieves additional sensor limits data
// This function is shared between ground sensors and orbiting sensors. Make sure to interpret the data correctly.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// boresight2         Orbiting sensor boresight2 vector (out-Character)
// elLim3             Elevation limit #3 (low, deg) OR orbiting sensor off-boresight angle (out-Double)
// elLim4             Elevation limit #4 (high, deg) OR orbiting sensor off-boresight angle (out-Double)
// azLim3             Azimuth limit #3 (left, deg) OR orbiting sensor clock angle (out-Double)
// azLim4             Azimuth limit #4 (right, deg) OR orbiting sensor clock angle (out-Double)
// earthBckgrnd       Flag; if set, allow orb sensor to view satellite against earth background (out-Integer)
// earthLimb          Orbiting sensor earth limb exclusion distance (km) (out-Double)
// solarXAngle        Orbiting sensor solar exclusion angle (deg) (out-Double)
// lunarXAngle        Orbiting sensor lunar exclusion angle (deg) (out-Double)
// minIllum           Orbiting sensor minimum illumination angle (deg) (out-Double)
// twilit             Ground site twilight offset angle (deg) (out-Double)
// returns 0 if all optional/additional sensor limits data fields are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGet2L)(int senKey, char* boresight2, double* elLim3, double* elLim4, double* azLim3, double* azLim4, int* earthBckgrnd, double* earthLimb, double* solarXAngle, double* lunarXAngle, double* minIllum, double* twilit);


// Adds/updates additional sensor limits data
// This function is shared between ground sensors and orbiting sensors. The users need to provide the proper data fields for each sensor type.
// 
// If the function is invoked with a senKey that already exists in the SENSOR DLL's binary tree, the senKey's associated data will be updated with the provided data.	
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// boresight2         Orbiting sensor boresight2 vector (in-Character)
// elLim3             Elevation limit #3 (low, deg) OR orbiting sensor off-boresight angle (in-Double)
// elLim4             Elevation limit #4 (high, deg) OR orbiting sensor off-boresight angle (in-Double)
// azLim3             Azimuth limit #3 (left, deg) OR orbiting sensor clock angle (in-Double)
// azLim4             Azimuth limit #4 (right, deg) OR orbiting sensor clock angle (in-Double)
// earthBckgrnd       Flag; if set, allow orb sensor to view satellite against earth background (in-Integer)
// earthLimb          Orbiting sensor earth limb exclusion distance (km) (in-Double)
// solarXAngle        Orbiting sensor solar exclusion angle (deg) (in-Double)
// lunarXAngle        Orbiting sensor lunar exclusion angle (deg) (in-Double)
// minIllum           Orbiting sensor minimum illumination angle (deg) (in-Double)
// twilit             Ground site twilight offset angle (deg) (in-Double)
// returns 0 if the optional/additional sensor limits data is added/updated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSet2L)(int senKey, char boresight2, double elLim3, double elLim4, double azLim3, double azLim4, int earthBckgrnd, double earthLimb, double solarXAngle, double lunarXAngle, double minIllum, double twilit);


// Retrieves an individual field of sensor limits data
// 
// Make sure to use the appropriate field index for ground sensors and orbiting sensors.
// 
// The table below shows the values for the xf_SenLim parameter:
// 
// 
// Index
// Index Interpretation
// 
// 11 Sensor view type
// 12 Sensor observation type
// 13 Unit on range/range rate
// 14 Max observable range (km)
// 15 Min observable range (km)
// 16 Output interval (min)
// 17 Visual pass control flag
// 18 Range limit control flag 
// 19 Max number of points per pass
// 20 Range rate/relative velocity limit (km/sec)
// 31 Elevation limits (deg) 1, 2, 3, 4 or Sensor off-boresight angle (deg)
// 32 
// 33 
// 34 
// 35 Azimuth limits (deg) 1, 2,3, 4 or Sensor clock angle (deg)
// 36 
// 37 
// 38 
// 52 Orbiting sensor planetary restriction
// 53 Orbiting sensor boresight vector 1
// 54 Orbiting sensor boresight vector 2
// 55 Allow orbiting sensor to view sat against earth background
// 56 Orbiting sensor earth limb exclusion distance (km)
// 57 Orbiting sensor solar exclusion angle (deg)   
// 58 Orbiting sensor lunar exclusion angle (deg)
// 59 Orbiting sensor min illumination angle (deg)
// 60 Ground site twilight offset angle (deg)    
//    
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xf_SenLim          Predefined number specifying which field to retrieve (in-Integer)
// strValue           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the sensor limits data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetLimField)(int senKey, int xf_SenLim, char strValue[512]);


// Updates an individual field of sensor limits data
// See SensorGetLimField for a description of the xf_SenLim parameter.
// The set value type was intentionally chosen as a character string because it allows the users to set value for different data types.
// 
// Make sure to use the appropriate field index for ground sensors and orbiting sensors.
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xf_SenLim          Predefined number specifying which field to retrieve (in-Integer)
// strValue           The new value of the specified field, expressed as a string (in-Character[512])
// returns Returns zero indicating the sensor limits data has been successfully updated. Other values indicate an error
typedef int (STDCALL *fnPtrSensorSetLimField)(int senKey, int xf_SenLim, char strValue[512]);


// Retrieves sensor sigma/bias data
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// biasSigmaArr       bias/sigma array 0=azSigma, 1=elSigma, 2=rgSigma, 3=rrSigma, 8=azBias, 9=elBias, 10=rgBias, 11=rrBias, 15=timeBias (out-Double[16])
// returns 0 if all sensor sigma/bias data fields are retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetBS)(int senKey, double biasSigmaArr[16]);


// Adds/updates sensor sigma/bias data 
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// biasSigmaArr       bias/sigma array 0=azSigma, 1=elSigma, 2=rgSigma, 3=rrSigma, 8=azBias, 9=elBias, 10=rgBias, 11=rrBias, 15=timeBias (in-Double[16])
// returns 0 if the sensor sigma/bias data is added/updated successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSetBS)(int senKey, double biasSigmaArr[16]);


// Retrieves an individual field of sensor sigma/bias data
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xaf_SenBS          Predefined number specifying which field to retrieve: 0=azSigma, 1=elSigma, 2=rgSigma, 3=rrSigma, 8=azBias, 9=elBias, 10=rgBias, 11=rrBias, 15=timeBias (in-Integer)
// strValue           A string to contain the value of the requested field (out-Character[512])
// returns 0 if the sensor sigma/bias data is retrieved successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetBSField)(int senKey, int xaf_SenBS, char strValue[512]);


// Updates an individual field of sensor sigma/bias data
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// xaf_SenBS          Predefined number specifying which field to retrieve: 0=azSigma, 1=elSigma, 2=rgSigma, 3=rrSigma, 8=azBias, 9=elBias, 10=rgBias, 11=rrBias, 15=timeBias (in-Integer)
// strValue           The new value of the specified field, expressed as a string (in-Character[512])
// returns Returns zero indicating the sensor sigma/bias data has been successfully updated. Other values indicate an error
typedef int (STDCALL *fnPtrSensorSetBSField)(int senKey, int xaf_SenBS, char strValue[512]);


// Retrieves the sensor data in form of S-Card, L1-Card, and L2-Card of the sensor
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// sCard              S-Card string of the sensor (out-Character[512])
// l1Card             L1-Card string of the sensor (out-Character[512])
// l2Card             L2-Card string of the sensor (out-Character[512])
// returns 0 on success, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetLines)(int senKey, char sCard[512], char l1Card[512], char l2Card[512]);


// Gets sensor's orbiting satellite's satKey
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// orbSatKey          The orbiting satellite's unique key (out-Long)
// returns 0 on success, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetOrbSatKey)(int senKey, __int64* orbSatKey);


// Sets sensor's orbiting satellite's satKey
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// orbSatKey          The orbiting satellite's unique key (in-Long)
// returns 0 on success, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorSetOrbSatKey)(int senKey, __int64 orbSatKey);


// Loads Space Fence's detailed azimuth-elevation definition table
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// azElTableFile      The name of the file containing Space Fence's az/el definition table (in-Character[512])
// returns 0 if the input file is read successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorLoadAzElTable)(int senKey, char azElTableFile[512]);


// Adds a new sensor segment whose limits defined by the input parameters - a cone or a dome portion 
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// segType            Input segment type (bounded-cone = 1, dome = 2) (in-Integer)
// xa_seg             sensor segment data (in-Double[16])
// returns 0 if the new sensor segment is added successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorAddSegment)(int senKey, int segType, double xa_seg[16]);


// Retrieves sensor segment data of the specified segment (segNum)
// senKey             The sensor's unique key (same as the sensor number) (in-Integer)
// segNum             The segment number of the sensor segment whose data is returned (in-Integer)
// segType            The output segment type (bounded-cone = 1, dome = 2) (out-Integer)
// xa_seg             The resulting sensor segment data (out-Double[16])
// returns 0 if the sensor segment data is returned successfully, non-0 if there is an error
typedef int (STDCALL *fnPtrSensorGetSegment)(int senKey, int segNum, int* segType, double xa_seg[16]);

// Indexes of Sensor data fields
static const int  
   XF_SENLOC_NUM  = 1,             // Sensor number
   XF_SENLOC_LAT  = 2,             // Sensor location - astronomical longitude (deg) (+=West/-=East)
   XF_SENLOC_LON  = 3,             // Sensor location - astronomical latitude (deg)  (+=North/-=South)
   XF_SENLOC_POSX = 4,             // Sensor ECR position X (km)
   XF_SENLOC_POSY = 5,             // Sensor ECR position Y (km)
   XF_SENLOC_POSZ = 6,             // Sensor ECR position Z (km)
   XF_SENLOC_DESC = 7,             // Sensor description
   XF_SENLOC_ORBSATNUM = 8,        // Orbiting sensor's number (satnum)   
   XF_SENLOC_SECCLASS  = 9,        // Sensor classification   
   
   XF_SENLIM_VIEWTYPE  = 11,       // Sensor view type
   XF_SENLIM_OBSTYPE   = 12,       // Sensor observation type
   XF_SENLIM_UNIT      = 13,       // Unit on range/range rate
   XF_SENLIM_MAXRNG    = 14,       // Max observable range (km)
   XF_SENLIM_MINRNG    = 15,       // Min observable range (km)
   XF_SENLIM_INTERVAL  = 16,       // Output interval (min)
   XF_SENLIM_OPTVISFLG = 17,       // Visual pass control flag
   XF_SENLIM_RNGLIMFLG = 18,       // Range limit control flag 
   XF_SENLIM_PTSPERPAS = 19,       // Max number of points per pass
   XF_SENLIM_RRLIM     = 20,       // Range rate/relative velocity limit (km/sec)
   
   XF_SENLIM_ELLIM1    = 31,       // Elevation limits #1 (low, deg) or orbiting sensor off-boresight angle (low, deg) or conical sensor boresight elvation (deg)
   XF_SENLIM_ELLIM2    = 32,       // Elevation limits #2 (high, deg) or orbiting sensor off-boresight angle (high, deg) or conical sensor boresight minimum angle (deg)
   XF_SENLIM_ELLIM3    = 33,       // Elevation limits #3 (low, deg) or orbiting sensor off-boresight angle (low, deg) or 
   XF_SENLIM_ELLIM4    = 34,       // Elevation limits #4 (high, deg) or orbiting sensor off-boresight angle (high, deg)
   XF_SENLIM_AZLIM1    = 35,       // Azimuth limits #1 (low, deg) or orbiting sensor clock angle (from, deg) or conical sensor boresight azimuth (deg)
   XF_SENLIM_AZLIM2    = 36,       // Azimuth limits #2 (high, deg) or orbiting sensor clock angle (to, deg) or conical sensor off-boresight azimuth angle (deg)
   XF_SENLIM_AZLIM3    = 37,       // Azimuth limits #3 (low, deg) or orbiting sensor clock angle (from, deg)
   XF_SENLIM_AZLIM4    = 38,       // Azimuth limits #4 (high, deg) or orbiting sensor clock angle (to, deg)
   
   
   XF_SENLIM_PLNTRYRES = 52,       // Orbiting sensor planetary restriction
   XF_SENLIM_BOREVEC1  = 53,       // Orbiting sensor boresight vector 1
   XF_SENLIM_BOREVEC2  = 54,       // Orbiting sensor boresight vector 2
   XF_SENLIM_KEARTH    = 55,       // Allow orbiting sensor to view sat against earth background
   XF_SENLIM_ELIMB     = 56,       // Orbiting sensor earth limb exclusion distance (km)
   XF_SENLIM_SOLEXCANG = 57,       // Orbiting sensor solar exclusion angle (deg)   
   XF_SENLIM_LUNEXCANG = 58,       // Orbiting sensor lunar exclusion angle (deg)
   
   
   XF_SENLIM_MINIL     = 59,       // Orbiting sensor min illumination angle (deg)
   XF_SENLIM_TWILIT    = 60,       // Ground site twilight offset angle (deg) 
   XF_SENLIM_SMSEN     = 61,       // Is special mobil sensor flag / column 9 in 1L card
   XF_SENLIM_NUMSEGS   = 62,       // Number of additional segments added to sensor limits
   XF_SENLIM_FILE      = 63,       // Space fence FOR's Az/El table file name
   XF_SENLIM_AZELROWS  = 64;       // Number of rows in space fence FOR's Az/El table 

//*******************************************************************************
   
// Indexes of sensor location data
static const int     
   XA_SENLOC_NUM     =  0,       // Sensor nubmer
   XA_SENLOC_LAT     =  1,       // Sensor location - astronomical latitude (deg)  (+=North/-=South)
   XA_SENLOC_LON     =  2,       // Sensor location - astronomical longitude (deg) (+=West/-=East)
   XA_SENLOC_POSX    =  3,       // Sensor ECR position X (km)
   XA_SENLOC_POSY    =  4,       // Sensor ECR position Y (km)
   XA_SENLOC_POSZ    =  5,       // Sensor ECR position Z (km)
   
   XA_SENLOC_SIZE    = 16;   
   
//*******************************************************************************
   
// Indexes of Sensor's sigma   biases data fields
static const int  
   XAF_SENBS_AZSIGMA =  0,    // azimuth sigma (deg)
   XAF_SENBS_ELSIGMA =  1,    // elevation sigma (deg)
   XAF_SENBS_RGSIGMA =  2,    // range sigma (km)
   XAF_SENBS_RRSIGMA =  3,    // range-rate sigma (km/sec) 
   XAF_SENBS_ARSIGMA =  4,    // az rate sigma (deg/sec)
   XAF_SENBS_ERSIGMA =  5,    // el rate sigma (deg/sec)

   XAF_SENBS_AZBIAS  =  8,    // azimuth bias (deg)
   XAF_SENBS_ELBIAS  =  9,    // elevation bias (deg)
   XAF_SENBS_RGBIAS  = 10,    // range bias (km)
   XAF_SENBS_RRBIAS  = 11,    // range-rate bias (km/sec)
   XAF_SENBS_TIMEBIAS= 15;    // time bias (sec)
   
   
   
// Sensor segment types
static const int  
   SEG_BCONE = 1,      // bounded-cone-typed limit: Boresight Az/El, Min/Max halfcone angle/Range, minimum cut-off elevation
   SEG_DOME  = 2;      // dome-typed limit: Min/Max Az/El/Range
   


// Indexes of dome segment parameters
static const int  
   XA_SEG_DOME_AZFR   =  0,   // start azimuth (deg)          
   XA_SEG_DOME_AZTO   =  1,   // end azimuth (deg)            
   XA_SEG_DOME_ELFR   =  2,   // lower-bound elevation (deg)  
   XA_SEG_DOME_ELTO   =  3,   // higher-bound elevation (deg) 
   XA_SEG_DOME_MINRNG =  4,   // minimum range (km)           
   XA_SEG_DOME_MAXRNG =  5,   // maximum range (km)           
   
   XA_SEG_DOME_SIZE   = 16;
   

// Indexes of bounded-cone segment parameters
static const int  
   XA_SEG_BCONE_BSAZ   =  0,   // boresight azimuth (deg)
   XA_SEG_BCONE_BSEL   =  1,   // boresight elevation (deg)          
   XA_SEG_BCONE_ANGFR  =  2,   // offboresight lower angle (deg)
   XA_SEG_BCONE_ANGTO  =  3,   // offboresight higher angle (deg)
   XA_SEG_BCONE_MINRNG =  4,   // minimum range (km)
   XA_SEG_BCONE_MAXRNG =  5,   // maximum range (km)
   XA_SEG_BCONE_MINEL  =  6,   // minimum cut-off elevation (deg)
   
   XA_SEG_BCONE_SIZE   = 16;
   
   



// SensorDll's function pointers
fnPtrSensorInit                     SensorInit;
fnPtrSensorGetInfo                  SensorGetInfo;
fnPtrSensorLoadFile                 SensorLoadFile;
fnPtrSensorLoadCard                 SensorLoadCard;
fnPtrSensorSaveFile                 SensorSaveFile;
fnPtrSensorRemove                   SensorRemove;
fnPtrSensorRemoveAll                SensorRemoveAll;
fnPtrSensorGetCount                 SensorGetCount;
fnPtrSensorGetLoaded                SensorGetLoaded;
fnPtrSensorGetLocAll                SensorGetLocAll;
fnPtrSensorSetLocAll                SensorSetLocAll;
fnPtrSensorGetLocField              SensorGetLocField;
fnPtrSensorSetLocField              SensorSetLocField;
fnPtrSensorGet1L                    SensorGet1L;
fnPtrSensorSet1L                    SensorSet1L;
fnPtrSensorGet2L                    SensorGet2L;
fnPtrSensorSet2L                    SensorSet2L;
fnPtrSensorGetLimField              SensorGetLimField;
fnPtrSensorSetLimField              SensorSetLimField;
fnPtrSensorGetBS                    SensorGetBS;
fnPtrSensorSetBS                    SensorSetBS;
fnPtrSensorGetBSField               SensorGetBSField;
fnPtrSensorSetBSField               SensorSetBSField;
fnPtrSensorGetLines                 SensorGetLines;
fnPtrSensorGetOrbSatKey             SensorGetOrbSatKey;
fnPtrSensorSetOrbSatKey             SensorSetOrbSatKey;
fnPtrSensorLoadAzElTable            SensorLoadAzElTable;
fnPtrSensorAddSegment               SensorAddSegment;
fnPtrSensorGetSegment               SensorGetSegment;



void LoadSensorDll();
void FreeSensorDll();




#endif
// ========================= End of auto generated code ==========================
