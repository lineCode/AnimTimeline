CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )
PROJECT(AnimTimeline)

################################################################################
# Compiler and linker options
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################################################################################
# Sources and headers
FIND_PACKAGE(Qt5 COMPONENTS Core Widgets REQUIRED)

FILE(GLOB_RECURSE headers src/*.h)
FILE(GLOB_RECURSE sources src/*.cpp)

file(GLOB_RECURSE app_uis src/*.ui)
qt5_wrap_ui(app_uis_moc ${app_uis})

#add_definitions(${Qt5Core_DEFINITIONS})
#add_definitions(${Qt5Widges_DEFINITIONS})

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
include_directories(
    src/
    src/AnimTimeline/ #for ui include "ui_animtimeline.h", moc not visible
    ${CMAKE_CURRENT_BINARY_DIR}
#    ${CMAKE_CURRENT_SOURCE_DIR}
    )

#add_definitions( ${Qt5Core_DEFINITIONS} )
#add_definitions( ${Qt5Widges_DEFINITIONS} )

################################################################################
# Compile target
#ADD_EXECUTABLE(${PROJECT_NAME} ${V1_SOURCE_FILES} ${V1_HEADER_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/resource/timeline.qrc)
ADD_EXECUTABLE(${PROJECT_NAME} ${sources} ${headers} ${app_uis} src/AnimTimeline/timeline.qrc)
# https://www.kdab.com/using-cmake-with-qt-5/
qt5_use_modules(${PROJECT_NAME} Core Widgets)

#add_definitions(-DQT_NO_DEBUG_OUTPUT)
if(CMAKE_BUILD_TYPE MATCHES "Release")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()