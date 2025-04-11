if(MSVC)
    if(CMAKE_CL_64)
        message(STATUS ">>>>> using MSCV x64 64bit <<<<<")
        set(INSTALL_SUB_DIR x64-64bit)
        CPMAddPackage(
            NAME ONNXRUNTIME
            VERSION 1.11.1
            URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/msvc-x64-64bit/onnxruntime_1.11.1.zip")
        CPMAddPackage(
            NAME OPENCV
            VERSION 4.11.1
            URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/msvc-x64-64bit/opencv_4.11.0.zip") 
    else()
        message(STATUS ">>>>> using MSCV x86 32bit <<<<<")
        set(INSTALL_SUB_DIR x86-32bit)
        CPMAddPackage(
            NAME ONNXRUNTIME
            VERSION 1.11.1
            URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/msvc-x86-32bit/onnxruntime_1.11.1.zip")
        CPMAddPackage(
            NAME OPENCV
            VERSION 4.11.1
            URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/msvc-x86-32bit/opencv_4.11.0.zip") 
    endif()

else()
    message(FATAL_ERROR "Not support other compiler")
endif()

# Download model yolo11n
CPMAddPackage(
    NAME MODEL
    VERSION 0.0.1
    DOWNLOAD_ONLY
    URL "https://thirdparty30.oss-cn-beijing.aliyuncs.com/model/num_1-yolo11n.zip")

# Compile about
include_directories(
    ${OPENCV_SOURCE_DIR}/include
    ${ONNXRUNTIME_SOURCE_DIR}/include)

link_directories(
    ${OPENCV_SOURCE_DIR}/bin
    ${OPENCV_SOURCE_DIR}/lib
    ${ONNXRUNTIME_SOURCE_DIR}/lib)

add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv opencv_world4110)

add_executable(test_onnxruntime test_onnxruntime.cpp)
target_link_libraries(test_onnxruntime opencv_world4110)


# Install
install(TARGETS test_opencv test_onnxruntime DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(DIRECTORY ${OPENCV_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
install(DIRECTORY ${MODEL_SOURCE_DIR}/ DESTINATION model FILES_MATCHING PATTERN "*.onnx")


