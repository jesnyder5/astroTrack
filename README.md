# astroTrack
This C/C++ program is a satellite tracker that uses Two Line Element and/or Orbital Mean-Elements Message  element sets to predict the location of near Earth-orbiting satellites for tracking purposes.


### Current Features:

- Loads in satellite orbital information from TLE and OMM-JSON formatted data, either directly or via a saved data file

- Can return a list of loaded satellite names, the number of loaded satellites, and can print the orbital information associated with any specified loaded satellite

- Calculates the position of the Sun, Moon, or any specified loaded satellite in the TEME and ECR reference frames, as well as the latitude, longitude, and height in kilometers at any specified time (with varying accuracy for the satellite’s position)

- Graphs the ground track of any specified loaded satellite over a specified time window

- Converts the current time or a UTC time specified in a time.h tm struct to ds50UTC

- Determines whether any location on Earth is sunlit at a specified time

### Work-in-Progress Features:

- Calculating the look angle to a specified satellite at a specified time from a specified location anywhere on Earth

- Graphing a three-dimensional representation of a specified satellite’s orbit

- Converting a DTG time string to ds50UTC

### Known Issues:
- The astrodynamics libraries require using the WGS-72 geodetic reference datum for accurate SGP4 propagation, but GPS uses WGS-84 and there does not seem to be a clear way to convert vectors/coordinates between the two. However, the inaccuracies introduced should be small enough to accept for this project’s usage at the moment

- Any conversion of vectors to the ECR reference frame only returns zeroes. There is likely some polar motion information that must be loaded in somewhere for the conversion to work. For now, any ECR vectors are returned in the EFG frame, which does not account for polar motion, creating a difference on the order of 15 meters or less

- Every satellite added logs “Error-GpRemoveNode: Unable to locate satKey [satKey] in the SGP4 binary tree.”, but the astrodynamics libraries still work as intended regardless

- The ground track plot window occasionally reappears after closing

- The ground track plotting (matplotplusplus using gnuplot) may produce its own warning messages

 
## Building:

### External Prerequisites:

To run this program, you will need the Astrodynamics Standards (SGP4) libraries, available as the SGP4_propagator at https://www.space-track.org/documentation#/sgp4. Accessing the Astrodynamics Standards (SPG4) libraries will require a free account.
The ground track function uses matplotplusplus, which is automatically downloaded, and it in turn depends on gnuplot, which must be installed.

### Short Direction List:
```
sudo apt install gcc g++ cmake gnuplot git
git clone https://github.com/jesnyder5/astroTrack
cd ./astroTrack
```
Copy libraries into ./lib, service files into ./services, and wrapper files into ./wrappers
```
mkdir ./build
cmake -S . -B ./build
cmake --build ./build
```
### Full Direction List:

This program has been designed and coded from within a Linux operating system and, at the moment, Linux is the only fully supported operating system. The following directions were tested to work from a clean Ubuntu 20.04 installation.

First, needed packages are downloaded using apt: gcc, g++, and cmake for compiling and building the C/C++ program, gnuplot for the ground track plotting, and git to pull the source code from GitHub:
```
sudo apt install gcc g++ cmake gnuplot git
```
Next, the newest version of the source code is pulled from GitHub using git:
```
git clone https://github.com/jesnyder5/astroTrack
```
 
At this point, the libraries, services, and wrappers need to be copied from the SGP4 download package into the astroTrack folder. Inside the SGP4 download package, the library files are stored in Sgp4Prop/Lib/Linux64 and need to be copied into astroTrack/lib, except for the open license file which goes into the main astroTrack directory. The services and wrappers directories are stored in Sgp4Prop/SampleCode/C/DriverExamples. These entire directories need to be copied into the main astroTrack directory.
 
Now, the program is ready to be built using cmake. Run the following commands from the main astroTrack directory. The first command creates a directory to store building files. The second command configures cmake for this program. The third command builds the program into an executable file. Building the program may take some time on the first run, but any subsequent runs will be much faster.
```
mkdir ./build
cmake -S . -B ./build/
cmake --build ./build/
```

With the program built, it can be run using the script included with the source code:
```
./astroTrack.sh
```
 
## Running the Program:

### Using the Text User Interface:

Currently, it is recommended to run the program in-place after building from the main astroTrack directory using the included script. The script will automatically set the LD_LIBRARY_PATH environment variable, used internally to locate the SGP4 libraries, and start the built executable.
When the program is run, the text-based interface opens, as shown below. The “About” page is shown followed by the main menu. From the main menu, the “Select Sat” page allows a satellite to be selected from those loaded. The program automatically loads satellite orbital information stored in “weather.tle” on startup.

Selecting a satellite or the Sun or Moon opens its tracking page, where its position at the current time can be printed in the True Equator Mean Equinox and Earth-Centered Rotating reference frames, as well as its Latitude and Longitude. From a satellite’s tracking page, the satellite’s ground track can be graphed by entering the number of hours before and after the current time to graph.

The satellite database can be manipulated directly using the text interface from the Edit Sat Database page, accessible from the main menu. Any of the loaded satellites can be individually removed, with any list of loaded satellites automatically reformatting to fit the number of satellites. New satellites can be added from an orbital information file (either TLE or OMM-JSON), with exact duplicates and malformed entries being discarded. Non-exact duplicates (such as updated information), however, are not currently handled and will be added as new satellites. The satellite database is searched by name from the first entry, so these duplicates will never be used by the program and will simply unnecessarily take up space.

The proper procedure for updating orbital information is to remove the specific satellites or erase the entire database and re-load in the satellites using the Add From File function with the updated information.

### Using the Source Code:

The program can be used from another C++ program by including the “astroTracker.hpp” header file, creating an astroTracker object, and calling the needed functions.
