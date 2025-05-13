include(cmake/CPM.cmake)

if(CMAKE_CL_64)
    message(STATUS ">>>>> using MSCV x64 64bit <<<<<")
    set(DEPS_PREFIX_PATH msvc-x64-64bit)
else()
    message(STATUS ">>>>> using MSCV x86 32bit <<<<<")
    set(DEPS_PREFIX_PATH msvc-x86-32bit)
endif()

CPMAddPackage(
    NAME OPENCV
    VERSION 4.11.1
    URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/${DEPS_PREFIX_PATH}/opencv_4.11.0.zip")
CPMAddPackage(
    NAME GRPC
    VERSION 1.71.1
    URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/${DEPS_PREFIX_PATH}/Release/grpc-Release-1.71.0.zip")

# Compile about
include_directories(
    ${OPENCV_SOURCE_DIR}/include
    ${GRPC_SOURCE_DIR}/include
)

link_directories(
    ${OPENCV_SOURCE_DIR}/bin
    ${OPENCV_SOURCE_DIR}/lib
    ${GRPC_SOURCE_DIR}/lib
)
