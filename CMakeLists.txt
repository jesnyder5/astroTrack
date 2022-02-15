cmake_minimum_required(VERSION 3.0.0)
project(astroTrack VERSION 0.1.0)

include(CTest)
enable_testing()

set (SRC_FILES 
        main.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/astroTracker.cpp
)

set(WRAPPER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/AofDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/AstroFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/BamDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/BatchDCDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ComboDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/DllMainDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ElCompDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ElOpsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/EnvConstDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ExtEphemDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/FovDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/LamodDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ObsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/ObsOpsDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/RotasDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/SaasDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/SatStateDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/SensorDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/Sgp4PropDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/SpPropDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/SpVecDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/TimeFuncDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/TleDll.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/wrappers/VcmDll.c
)

set(SERVICE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/AofDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/AstroFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/BatchDCDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/ComboDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/DllMainDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/DllUtils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/ElOpsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/ExtEphemDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/FovDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/LamodDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/ObsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/ObsOpsDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/RotasDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/SatStateDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/SensorDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/SpPropDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/TimeFuncDll_Service.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/services/TleDll_Service.c
)

add_executable(astroTrack ${SRC_FILES} ${WRAPPER_FILES} ${SERVICE_FILES})

target_link_libraries(astroTrack ${CMAKE_DL_LIBS})
target_include_directories(astroTrack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
