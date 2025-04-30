add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv opencv_world4110)

add_executable(test_tensorflow_server test_tensorflow_server.cpp)
target_link_libraries(test_tensorflow_server opencv_world4110 prediction_client proto_tensorflow)

# Install
install(TARGETS test_opencv test_tensorflow_server DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(DIRECTORY ${OPENCV_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
