set (TARGET_NAME cast_nn_hidl_base)

set (SOURCE_FILES
    Status.cpp
    HidlSupport.cpp
    StrongPointer.cpp
    native_handle.cpp
    RefBase.cpp
    HidlInternal.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${TARGET_NAME} PRIVATE include)

#EXPORT_HEADERS
install(
    DIRECTORY include/
    DESTINATION include/cast
)

install(
    TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)
