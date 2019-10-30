set(TEST_GENERATOR_TARGET test-generator-headers)

add_library(${TEST_GENERATOR_TARGET} INTERFACE)

target_include_directories(${TEST_GENERATOR_TARGET} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
