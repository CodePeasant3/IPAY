cmake_minimum_required(VERSION 3.5)

project(IPAY VERSION 0.1 LANGUAGES CXX)

set(CPM_SOURCE_CACHE ${CMAKE_SOURCE_DIR}/cache/CPM)
include(cmake/extern_dep.cmake)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Sql Core Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Sql Core Multimedia)
file(GLOB VIEW_SOURCES ./View/*.cpp ./View/*.h ./View/*.ui)
file(GLOB COMMON_SOURCES ./Common/*.cpp ./Common/*.h)
file(GLOB UTILS_SOURCES ./Utils/*.cpp ./Utils/*.h)

set(PROJECT_SOURCES
        main.cpp
        ${VIEW_SOURCES}
        ${COMMON_SOURCES}
        ${UTILS_SOURCES}
        ipay.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(IPAY
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET IPAY APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(IPAY SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(IPAY
            ${PROJECT_SOURCES}
        )
    endif()
endif()
include_directories(
    ${CMAKE_SOURCE_DIR}/
    ${CMAKE_SOURCE_DIR}/Utils
    ${CMAKE_SOURCE_DIR}/Algo/PredictionClient
    ${CMAKE_SOURCE_DIR}/Algo/proto
)

add_subdirectory(Algo)

target_link_libraries(IPAY
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Multimedia
    proto_tensorflow
    prediction_client
)

set_target_properties(IPAY PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS IPAY
    DESTINATION .)

install(FILES config.ini DESTINATION .)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(IPAY)
endif()

#add_subdirectory(test)

