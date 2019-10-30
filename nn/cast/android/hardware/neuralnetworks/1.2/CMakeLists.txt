set (TARGET_NAME android.hardware.neuralnetworks_1_2)

set (SOURCE_FILES
    types.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})


target_link_libraries(${TARGET_NAME}
    log
    cast_nn_hidl_base
)

install(
    TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)
