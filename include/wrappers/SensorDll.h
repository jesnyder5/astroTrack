// This wrapper file was generated automatically by the GenDllWrappers program.

#ifndef SENSORDLL_H
#define SENSORDLL_H

#include "../services/DllUtils.h"

// Provide the path to the dll/so/dylib
#if defined (_WIN32) || defined (__CYGWIN__)
  #define SensorDll "Sensor.dll"
#elif __APPLE__
  #define SensorDll "libsensor.dylib"
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
// 8Orbiting sensor's number (satNum)   
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
  
  // INDEXES OF SENSOR DATA FIELDS
  static const int  
     XF_SENLOC_NUM  = 1,             // SENSOR NUMBER
     XF_SENLOC_LAT  = 2,             // SENSOR LOCATION - ASTRONOMICAL LONGITUDE (DEG) (+=WEST/-=EAST)
     XF_SENLOC_LON  = 3,             // SENSOR LOCATION - ASTRONOMICAL LATITUDE (DEG)  (+=NORTH/-=SOUTH)
     XF_SENLOC_POSX = 4,             // SENSOR ECR POSITION X (KM)
     XF_SENLOC_POSY = 5,             // SENSOR ECR POSITION Y (KM)
     XF_SENLOC_POSZ = 6,             // SENSOR ECR POSITION Z (KM)
     XF_SENLOC_DESC = 7,             // SENSOR DESCRIPTION
     XF_SENLOC_ORBSATNUM = 8,        // ORBITING SENSOR'S NUMBER (SATNUM)   
     XF_SENLOC_SECCLASS  = 9,        // SENSOR CLASSIFICATION   
     
     XF_SENLIM_VIEWTYPE  = 11,       // SENSOR VIEW TYPE
     XF_SENLIM_OBSTYPE   = 12,       // SENSOR OBSERVATION TYPE
     XF_SENLIM_UNIT      = 13,       // UNIT ON RANGE/RANGE RATE
     XF_SENLIM_MAXRNG    = 14,       // MAX OBSERVABLE RANGE (KM)
     XF_SENLIM_MINRNG    = 15,       // MIN OBSERVABLE RANGE (KM)
     XF_SENLIM_INTERVAL  = 16,       // OUTPUT INTERVAL (MIN)
     XF_SENLIM_OPTVISFLG = 17,       // VISUAL PASS CONTROL FLAG
     XF_SENLIM_RNGLIMFLG = 18,       // RANGE LIMIT CONTROL FLAG 
     XF_SENLIM_PTSPERPAS = 19,       // MAX NUMBER OF POINTS PER PASS
     XF_SENLIM_RRLIM     = 20,       // RANGE RATE/RELATIVE VELOCITY LIMIT (KM/SEC)
     
     XF_SENLIM_ELLIM1    = 31,       // ELEVATION LIMITS #1 (LOW, DEG) OR ORBITING SENSOR OFF-BORESIGHT ANGLE (LOW, DEG) OR CONICAL SENSOR BORESIGHT ELVATION (DEG)
     XF_SENLIM_ELLIM2    = 32,       // ELEVATION LIMITS #2 (HIGH, DEG) OR ORBITING SENSOR OFF-BORESIGHT ANGLE (HIGH, DEG) OR CONICAL SENSOR BORESIGHT MINIMUM ANGLE (DEG)
     XF_SENLIM_ELLIM3    = 33,       // ELEVATION LIMITS #3 (LOW, DEG) OR ORBITING SENSOR OFF-BORESIGHT ANGLE (LOW, DEG) OR 
     XF_SENLIM_ELLIM4    = 34,       // ELEVATION LIMITS #4 (HIGH, DEG) OR ORBITING SENSOR OFF-BORESIGHT ANGLE (HIGH, DEG)
     XF_SENLIM_AZLIM1    = 35,       // AZIMUTH LIMITS #1 (LOW, DEG) OR ORBITING SENSOR CLOCK ANGLE (FROM, DEG) OR CONICAL SENSOR BORESIGHT AZIMUTH (DEG)
     XF_SENLIM_AZLIM2    = 36,       // AZIMUTH LIMITS #2 (HIGH, DEG) OR ORBITING SENSOR CLOCK ANGLE (TO, DEG) OR CONICAL SENSOR OFF-BORESIGHT AZIMUTH ANGLE (DEG)
     XF_SENLIM_AZLIM3    = 37,       // AZIMUTH LIMITS #3 (LOW, DEG) OR ORBITING SENSOR CLOCK ANGLE (FROM, DEG)
     XF_SENLIM_AZLIM4    = 38,       // AZIMUTH LIMITS #4 (HIGH, DEG) OR ORBITING SENSOR CLOCK ANGLE (TO, DEG)
     
     
     XF_SENLIM_PLNTRYRES = 52,       // ORBITING SENSOR PLANETARY RESTRICTION
     XF_SENLIM_BOREVEC1  = 53,       // ORBITING SENSOR BORESIGHT VECTOR 1
     XF_SENLIM_BOREVEC2  = 54,       // ORBITING SENSOR BORESIGHT VECTOR 2
     XF_SENLIM_KEARTH    = 55,       // ALLOW ORBITING SENSOR TO VIEW SAT AGAINST EARTH BACKGROUND
     XF_SENLIM_ELIMB     = 56,       // ORBITING SENSOR EARTH LIMB EXCLUSION DISTANCE (KM)
     XF_SENLIM_SOLEXCANG = 57,       // ORBITING SENSOR SOLAR EXCLUSION ANGLE (DEG)   
     XF_SENLIM_LUNEXCANG = 58,       // ORBITING SENSOR LUNAR EXCLUSION ANGLE (DEG)
     
     
     XF_SENLIM_MINIL     = 59,       // ORBITING SENSOR MIN ILLUMINATION ANGLE (DEG)
     XF_SENLIM_TWILIT    = 60,       // GROUND SITE TWILIGHT OFFSET ANGLE (DEG) 
     XF_SENLIM_SMSEN     = 61,       // IS SPECIAL MOBIL SENSOR FLAG / COLUMN 9 IN 1L CARD
     XF_SENLIM_NUMSEGS   = 62,       // NUMBER OF ADDITIONAL SEGMENTS ADDED TO SENSOR LIMITS
     XF_SENLIM_FILE      = 63,       // SPACE FENCE FOR'S AZ/EL TABLE FILE NAME
     XF_SENLIM_AZELROWS  = 64;       // NUMBER OF ROWS IN SPACE FENCE FOR'S AZ/EL TABLE 
  
  //*******************************************************************************
     
  // INDEXES OF SENSOR LOCATION DATA
  static const int     
     XA_SENLOC_NUM     =  0,       // SENSOR NUBMER
     XA_SENLOC_LAT     =  1,       // SENSOR LOCATION - ASTRONOMICAL LATITUDE (DEG)  (+=NORTH/-=SOUTH)
     XA_SENLOC_LON     =  2,       // SENSOR LOCATION - ASTRONOMICAL LONGITUDE (DEG) (+=WEST/-=EAST)
     XA_SENLOC_POSX    =  3,       // SENSOR ECR POSITION X (KM)
     XA_SENLOC_POSY    =  4,       // SENSOR ECR POSITION Y (KM)
     XA_SENLOC_POSZ    =  5,       // SENSOR ECR POSITION Z (KM)
     
     XA_SENLOC_SIZE    = 16;   
     
  //*******************************************************************************
     
  // INDEXES OF SENSOR'S SIGMA   BIASES DATA FIELDS
  static const int  
     XAF_SENBS_AZSIGMA =  0,    // AZIMUTH SIGMA (DEG)
     XAF_SENBS_ELSIGMA =  1,    // ELEVATION SIGMA (DEG)
     XAF_SENBS_RGSIGMA =  2,    // RANGE SIGMA (KM)
     XAF_SENBS_RRSIGMA =  3,    // RANGE-RATE SIGMA (KM/SEC) 
     XAF_SENBS_ARSIGMA =  4,    // AZ RATE SIGMA (DEG/SEC)
     XAF_SENBS_ERSIGMA =  5,    // EL RATE SIGMA (DEG/SEC)
  
     XAF_SENBS_AZBIAS  =  8,    // AZIMUTH BIAS (DEG)
     XAF_SENBS_ELBIAS  =  9,    // ELEVATION BIAS (DEG)
     XAF_SENBS_RGBIAS  = 10,    // RANGE BIAS (KM)
     XAF_SENBS_RRBIAS  = 11,    // RANGE-RATE BIAS (KM/SEC)
     XAF_SENBS_TIMEBIAS= 15;    // TIME BIAS (SEC)
     
     
     
  // SENSOR SEGMENT TYPES
  static const int  
     SEG_BCONE = 1,      // BOUNDED-CONE-TYPED LIMIT: BORESIGHT AZ/EL, MIN/MAX HALFCONE ANGLE/RANGE, MINIMUM CUT-OFF ELEVATION
     SEG_DOME  = 2;      // DOME-TYPED LIMIT: MIN/MAX AZ/EL/RANGE
     
  
  
  // INDEXES OF DOME SEGMENT PARAMETERS
  static const int  
     XA_SEG_DOME_AZFR   =  0,   // START AZIMUTH (DEG)          
     XA_SEG_DOME_AZTO   =  1,   // END AZIMUTH (DEG)            
     XA_SEG_DOME_ELFR   =  2,   // LOWER-BOUND ELEVATION (DEG)  
     XA_SEG_DOME_ELTO   =  3,   // HIGHER-BOUND ELEVATION (DEG) 
     XA_SEG_DOME_MINRNG =  4,   // MINIMUM RANGE (KM)           
     XA_SEG_DOME_MAXRNG =  5,   // MAXIMUM RANGE (KM)           
     
     XA_SEG_DOME_SIZE   = 16;
     
  
  // INDEXES OF BOUNDED-CONE SEGMENT PARAMETERS
  static const int  
     XA_SEG_BCONE_BSAZ   =  0,   // BORESIGHT AZIMUTH (DEG)
     XA_SEG_BCONE_BSEL   =  1,   // BORESIGHT ELEVATION (DEG)          
     XA_SEG_BCONE_ANGFR  =  2,   // OFFBORESIGHT LOWER ANGLE (DEG)
     XA_SEG_BCONE_ANGTO  =  3,   // OFFBORESIGHT HIGHER ANGLE (DEG)
     XA_SEG_BCONE_MINRNG =  4,   // MINIMUM RANGE (KM)
     XA_SEG_BCONE_MAXRNG =  5,   // MAXIMUM RANGE (KM)
     XA_SEG_BCONE_MINEL  =  6,   // MINIMUM CUT-OFF ELEVATION (DEG)
     
     XA_SEG_BCONE_SIZE   = 16;
     
     
// SensorDll's function pointers declaration
extern fnPtrSensorInit                     SensorInit;
extern fnPtrSensorGetInfo                  SensorGetInfo;
extern fnPtrSensorLoadFile                 SensorLoadFile;
extern fnPtrSensorLoadCard                 SensorLoadCard;
extern fnPtrSensorSaveFile                 SensorSaveFile;
extern fnPtrSensorRemove                   SensorRemove;
extern fnPtrSensorRemoveAll                SensorRemoveAll;
extern fnPtrSensorGetCount                 SensorGetCount;
extern fnPtrSensorGetLoaded                SensorGetLoaded;
extern fnPtrSensorGetLocAll                SensorGetLocAll;
extern fnPtrSensorSetLocAll                SensorSetLocAll;
extern fnPtrSensorGetLocField              SensorGetLocField;
extern fnPtrSensorSetLocField              SensorSetLocField;
extern fnPtrSensorGet1L                    SensorGet1L;
extern fnPtrSensorSet1L                    SensorSet1L;
extern fnPtrSensorGet2L                    SensorGet2L;
extern fnPtrSensorSet2L                    SensorSet2L;
extern fnPtrSensorGetLimField              SensorGetLimField;
extern fnPtrSensorSetLimField              SensorSetLimField;
extern fnPtrSensorGetBS                    SensorGetBS;
extern fnPtrSensorSetBS                    SensorSetBS;
extern fnPtrSensorGetBSField               SensorGetBSField;
extern fnPtrSensorSetBSField               SensorSetBSField;
extern fnPtrSensorGetLines                 SensorGetLines;
extern fnPtrSensorGetOrbSatKey             SensorGetOrbSatKey;
extern fnPtrSensorSetOrbSatKey             SensorSetOrbSatKey;
extern fnPtrSensorLoadAzElTable            SensorLoadAzElTable;
extern fnPtrSensorAddSegment               SensorAddSegment;
extern fnPtrSensorGetSegment               SensorGetSegment;



void LoadSensorDll();
void FreeSensorDll();




#endif
// ========================= End of auto generated code ==========================
