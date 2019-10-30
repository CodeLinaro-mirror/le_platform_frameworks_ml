set (VTS_TARGET_TEST_BASE_NAME vts_hal_hidl_target_test_base)

set (SOURCE_FILES
    vts_hal_hidl_target/VtsHalHidlTargetCallbackBase.cpp
    vts_hal_hidl_target/VtsHalTargetTestBase.cpp
    vts_hal_hidl_target/VtsHalTargetTestEnvBase.cpp
)

add_library(${VTS_TARGET_TEST_BASE_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${VTS_TARGET_TEST_BASE_NAME} PRIVATE vts_hal_hidl_target)

target_link_libraries(${VTS_TARGET_TEST_BASE_NAME}
    cast_nn_hidl_base
)

set (TEST_UTILS_TARGET_NAME nnhal_test_utils)

set (SOURCE_FILES
    1.0/vts/functional/Callbacks.cpp
    1.0/vts/functional/GeneratedTestHarness.cpp
)

add_library(${TEST_UTILS_TARGET_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${TEST_UTILS_TARGET_NAME} PRIVATE vts_hal_hidl_target)

target_link_libraries(${TEST_UTILS_TARGET_NAME}
    neuralnetworks
    cast_nn_hidl_base
    cast_nn_hidl_memory
    cast_nn_hidl_allocator
    test-generator-headers
)

set (NNHAL_TEST_1_0_TARGET_NAME nnhal-1_0-vendor-target-test)

set (SOURCE_FILES
    1.0/vts/functional/BasicTests.cpp
    1.0/vts/functional/GeneratedTests.cpp
    1.0/vts/functional/ValidateModel.cpp
    1.0/vts/functional/ValidateRequest.cpp
    1.0/vts/functional/VtsHalNeuralnetworksLib.cpp
)
add_executable(${NNHAL_TEST_1_0_TARGET_NAME} ${SOURCE_FILES})

target_include_directories(${NNHAL_TEST_1_0_TARGET_NAME} PRIVATE
    vts_hal_hidl_target
)

target_link_libraries(${NNHAL_TEST_1_0_TARGET_NAME}
    neuralnetworks_common
    nnhal_test_utils
    vts_hal_hidl_target_test_base
    gtest
    gtest_main
    tensorflow-lite
    base
    log
)

install(
    TARGETS ${NNHAL_TEST_1_0_TARGET_NAME}
    RUNTIME DESTINATION bin
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

############################################################

set (NNHAL_TEST_1_1_TARGET_NAME nnhal-1_1-vendor-target-test)

set (SOURCE_FILES
    1.1/vts/functional/BasicTests.cpp
    1.1/vts/functional/GeneratedTests.cpp
    1.1/vts/functional/GeneratedTestsV1_0.cpp
    1.1/vts/functional/ValidateModel.cpp
    1.1/vts/functional/ValidateRequest.cpp
    1.1/vts/functional/VtsHalNeuralnetworksLib.cpp
)

add_executable(${NNHAL_TEST_1_1_TARGET_NAME} ${SOURCE_FILES})

target_include_directories(${NNHAL_TEST_1_1_TARGET_NAME} PRIVATE
    vts_hal_hidl_target
)

target_link_libraries(${NNHAL_TEST_1_1_TARGET_NAME}
    neuralnetworks_common
    nnhal_test_utils
    vts_hal_hidl_target_test_base
    gtest
    gtest_main
    tensorflow-lite
    base
    log
)

install(
    TARGETS ${NNHAL_TEST_1_1_TARGET_NAME}
    RUNTIME DESTINATION bin
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

############################################################

set (NNHAL_TEST_1_2_TARGET_NAME nnhal-1_2-vendor-target-test)

set (SOURCE_FILES
    1.2/vts/functional/BasicTests.cpp
    1.2/vts/functional/CompilationCachingTests.cpp
    1.2/vts/functional/GeneratedTests.cpp
    1.2/vts/functional/GeneratedTestsV1_0.cpp
    1.2/vts/functional/GeneratedTestsV1_1.cpp
    1.2/vts/functional/ValidateModel.cpp
    1.2/vts/functional/ValidateRequest.cpp
    1.2/vts/functional/VtsHalNeuralnetworksLib.cpp
)

add_executable(${NNHAL_TEST_1_2_TARGET_NAME} ${SOURCE_FILES})

target_include_directories(${NNHAL_TEST_1_2_TARGET_NAME} PRIVATE
    vts_hal_hidl_target
)

target_compile_options(${NNHAL_TEST_1_2_TARGET_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-Os>
)

target_link_libraries(${NNHAL_TEST_1_2_TARGET_NAME}
    neuralnetworks_common
    nnhal_test_utils
    vts_hal_hidl_target_test_base
    gtest
    gtest_main
    tensorflow-lite
    base
    log
)

install(
    TARGETS ${NNHAL_TEST_1_2_TARGET_NAME}
    RUNTIME DESTINATION bin
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)