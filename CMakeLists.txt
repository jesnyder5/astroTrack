cmake_minimum_required(VERSION 3.0.0)
project(astroTrack VERSION 0.1.0)

include(CTest)
enable_testing()

set (SRC_FILES 
        main.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/astroTracker.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/satellite.cpp
)

set(WRAPPER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/AofDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/AstroFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/BamDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/BatchDCDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ComboDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/DllMainDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ElCompDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ElOpsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/EnvConstDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ExtEphemDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/FovDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/LamodDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ObsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/ObsOpsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/RotasDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SaasDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SatStateDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SensorDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/Sgp4PropDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SpPropDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/SpVecDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/TimeFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/TleDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/wrappers/VcmDll.c
)

set(SERVICE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/services/AofDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/AstroFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/BatchDCDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ComboDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/DllMainDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/DllUtils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ElOpsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ExtEphemDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/FovDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/LamodDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ObsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/ObsOpsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/RotasDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/SatStateDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/SensorDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/SpPropDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/TimeFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/services/TleDll_Service.c
)

add_executable(astroTrack ${SRC_FILES} ${WRAPPER_FILES} ${SERVICE_FILES})

target_link_libraries(astroTrack ${CMAKE_DL_LIBS})
target_include_directories(astroTrack PUBLIC 
                                ${CMAKE_CURRENT_SOURCE_DIR}/include
                                ${CMAKE_CURRENT_SOURCE_DIR}/wrappers
                                ${CMAKE_CURRENT_SOURCE_DIR}/services
                                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
