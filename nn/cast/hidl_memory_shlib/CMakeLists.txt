set (HIDL_MEMORY_TARGET_NAME cast_nn_hidl_memory)

set (SOURCE_FILES
    mapping.cpp
    memory/ShpMapper.cpp
    memory/ShpMemory.cpp
)

add_library(${HIDL_MEMORY_TARGET_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${HIDL_MEMORY_TARGET_NAME} PRIVATE .)

target_link_libraries(${HIDL_MEMORY_TARGET_NAME}
    cast_nn_hidl_base
)

install(
    TARGETS ${HIDL_MEMORY_TARGET_NAME}
    LIBRARY DESTINATION lib
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

# ----------------------------------------------------------

set (HIDL_ALLOCATOR_TARGET_NAME cast_nn_hidl_allocator)

add_library(${HIDL_ALLOCATOR_TARGET_NAME} SHARED allocator/ShpAllocator.cpp)

target_include_directories(${HIDL_ALLOCATOR_TARGET_NAME} PRIVATE .)

target_link_libraries(${HIDL_ALLOCATOR_TARGET_NAME}
    cast_nn_hidl_memory
)

install(
    TARGETS ${HIDL_ALLOCATOR_TARGET_NAME}
    LIBRARY DESTINATION lib
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)
