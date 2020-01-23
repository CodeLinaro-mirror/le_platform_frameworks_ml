set (TARGET_NAME platform_includes)
add_library(${TARGET_NAME} INTERFACE)
target_include_directories(${TARGET_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

#EXPORT_HEADERS
install(
    DIRECTORY .
    DESTINATION include/cast
)
