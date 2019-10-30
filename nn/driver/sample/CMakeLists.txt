set (MINIMAL_NN_HAL_TARGET_NAME sample-minimal-nn-hal)

add_library(${MINIMAL_NN_HAL_TARGET_NAME} SHARED
    SampleDriverMinimal.cpp
    SampleDriver.cpp
)

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
    neuralnetworks_common
    neuralnetworks_headers
    pthread
)

install(
    TARGETS ${MINIMAL_NN_HAL_TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}/nn
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)
