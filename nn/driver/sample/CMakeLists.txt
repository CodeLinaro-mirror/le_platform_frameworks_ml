set (SAMPLE_DRIVER_TARGET_NAME NeuralNetworksSampleDriver_defaults)

add_library(${SAMPLE_DRIVER_TARGET_NAME} STATIC SampleDriver.cpp)

target_link_libraries(${SAMPLE_DRIVER_TARGET_NAME} neuralnetworks_common)
target_link_libraries(${SAMPLE_DRIVER_TARGET_NAME} neuralnetworks_headers)
target_link_libraries(${SAMPLE_DRIVER_TARGET_NAME} pthread)

set (MINIMAL_NN_HAL_TARGET_NAME sample-minimal-nn-hal)

add_library(${MINIMAL_NN_HAL_TARGET_NAME} SHARED SampleDriverMinimal.cpp)

target_link_libraries(${MINIMAL_NN_HAL_TARGET_NAME} neuralnetworks_common)
target_link_libraries(${MINIMAL_NN_HAL_TARGET_NAME} neuralnetworks_headers)

#Dynamic link to shared libraries
target_link_libraries(${MINIMAL_NN_HAL_TARGET_NAME}
    base
    textclassifier_hash
    log
    utils
    cast_nn_hidl_base
    cast_nn_hidl_memory
    cast_nn_hidl_allocator
)

#Static libraries
target_link_libraries(${MINIMAL_NN_HAL_TARGET_NAME}
    NeuralNetworksSampleDriver_defaults
    neuralnetworks_common
)

install(
    TARGETS ${MINIMAL_NN_HAL_TARGET_NAME}
    LIBRARY DESTINATION lib
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)