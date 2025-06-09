add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv opencv_world4110)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Core)

include_directories(
    ${Qt${QT_VERSION_MAJOR}Network_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/Common
)
add_executable(test_md5 test_md5.cpp)
target_link_libraries(test_md5
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

add_executable(test_snowflake test_snowflake.cpp)
target_link_libraries(test_snowflake
    Qt${QT_VERSION_MAJOR}::Core
)

add_executable(test_tf test_tensorflow_server.cpp)
target_link_libraries(test_tf
    prediction_client
)

add_executable(test_log
    test_log.cpp
    ${CMAKE_SOURCE_DIR}/Common/logging.cpp
)
target_link_libraries(test_log
    Qt${QT_VERSION_MAJOR}::Core
)

add_executable(test_json
    test_json.cpp
)
target_link_libraries(test_json
    Qt${QT_VERSION_MAJOR}::Core
)

# Install
install(TARGETS test_opencv test_md5 test_tf test_log test_json DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(DIRECTORY ${OPENCV_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
install(DIRECTORY ${GRPC_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
