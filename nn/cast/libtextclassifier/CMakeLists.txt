set (TARGET_NAME textclassifier_hash)

set (SOURCE_FILES
    utils/hash/farmhash.cc
    util/hash/hash.cc
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${TARGET_NAME} PRIVATE .)

target_include_directories(${TARGET_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

#EXPORT_HEADERS
install(
    DIRECTORY util/
    DESTINATION include/cast
    FILES_MATCHING
    PATTERN "*.h"
)

install(
    DIRECTORY .
    DESTINATION libtextclassifier
    FILES_MATCHING
    PATTERN "*.h"
)

install(
    TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)
