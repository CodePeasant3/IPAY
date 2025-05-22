project(prediction_client)

add_library(${PROJECT_NAME} STATIC PredictionClient.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE
    opencv_world4110
    proto_tensorflow
)
#install(TARGETS ${PROJECT_NAME} DESTINATION .)
