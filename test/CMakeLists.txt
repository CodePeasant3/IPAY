add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv opencv_world4110)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

include_directories(
    ${Qt${QT_VERSION_MAJOR}Network_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/Common
)
add_executable(test_md5 test_md5.cpp)
target_link_libraries(test_md5
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

add_executable(test_request
    ${CMAKE_CURRENT_SOURCE_DIR}/test_request.cpp
    ${CMAKE_SOURCE_DIR}/Common/httpsrequest.cpp)

target_link_libraries(test_request
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

# Install
install(TARGETS test_opencv test_md5 test_request DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(DIRECTORY ${OPENCV_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
