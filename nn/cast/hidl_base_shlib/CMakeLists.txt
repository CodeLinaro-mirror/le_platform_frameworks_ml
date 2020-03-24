set (EXTERNAL_TARGET_NAME external_includes)

add_library(${EXTERNAL_TARGET_NAME} INTERFACE)

target_include_directories(${EXTERNAL_TARGET_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/external>)

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

target_include_directories(${TARGET_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(${TARGET_NAME}
    external_includes
    log
)

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
