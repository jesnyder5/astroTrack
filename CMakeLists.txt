cmake_minimum_required(VERSION 3.14.0)
project(astroTrack VERSION 0.1.0)
set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_NAME Windows)

include(FetchContent)
include(CTest)
enable_testing()

set (SRC_FILES 
        main.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/astroTracker_menu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/astroTracker.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/satellite.cpp
)

set(WRAPPER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/AstroFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/DllMainDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ElOpsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/EnvConstDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ExtEphemDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ObsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SatStateDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SensorDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/Sgp4PropDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SpVecDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/TimeFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/TleDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/VcmDll.c
)

set(SERVICE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/services/AstroFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/DllMainDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/DllUtils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ElOpsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ExtEphemDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ObsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/SatStateDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/SensorDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/TimeFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/TleDll_Service.c
)

add_executable(astroTrack ${SRC_FILES} ${WRAPPER_FILES} ${SERVICE_FILES})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package(Matplot++ QUIET)
        if(NOT Matplot++_FOUND)
                FetchContent_Declare(matplotplusplus GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus GIT_TAG origin/master)
                FetchContent_GetProperties(matplotplusplus)
                if(NOT matplotplusplus_POPULATED)
                        FetchContent_Populate(matplotplusplus)
                        add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
                endif()
        endif()
        target_link_libraries(astroTrack ${CMAKE_DL_LIBS} matplot)
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(${CMAKE_IGNORE_PATH} ./build/matplotplusplus)
        # modify default behavior of FIND_XXX() commands
        set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
        set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
        set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -Os")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -Os")
        target_link_libraries(astroTrack)
endif()

target_include_directories(astroTrack PUBLIC 
                                ${CMAKE_CURRENT_SOURCE_DIR}/include
                                ${CMAKE_CURRENT_SOURCE_DIR}/wrappers
                                ${CMAKE_CURRENT_SOURCE_DIR}/services
                                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
