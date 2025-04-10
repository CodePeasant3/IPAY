cmake_minimum_required(VERSION 3.5)

project(IPAY VERSION 0.1 LANGUAGES CXX)

include(cmake/CPM.cmake)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


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
include_directories(${CMAKE_SOURCE_DIR}/Utils)

target_link_libraries(IPAY PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(IPAY PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS IPAY
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(IPAY)
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_subdirectory(test)
endif()
