set (TARGET_NAME philox_random)

set (SOURCE_FILES
    guarded_philox_random.cc
    random.cc
    simple_philox.cc
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${TARGET_NAME} PRIVATE .)

target_include_directories(${TARGET_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(${TARGET_NAME} external_includes)

install(
    TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

