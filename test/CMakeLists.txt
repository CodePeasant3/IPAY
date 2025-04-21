add_executable(test_opencv test_opencv.cpp)
target_link_libraries(test_opencv opencv_world4110)

#add_executable(test_onnxruntime test_onnxruntime.cpp)
#target_link_libraries(test_onnxruntime opencv_world4110)

# Install
install(TARGETS test_opencv DESTINATION .)
install(DIRECTORY data DESTINATION .)
install(DIRECTORY ${OPENCV_SOURCE_DIR}/bin/ DESTINATION . FILES_MATCHING PATTERN "*.dll")
