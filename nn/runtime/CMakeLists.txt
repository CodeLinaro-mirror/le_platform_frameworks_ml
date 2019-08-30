add_library(neuralnetworks_headers INTERFACE)

target_include_directories(neuralnetworks_headers
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

set (TARGET_NAME neuralnetworks)

set (SOURCE_FILES
    Callbacks.cpp
    CompilationBuilder.cpp
    ExecutionBuilder.cpp
    ExecutionPlan.cpp
    Manager.cpp
    Memory.cpp
    ModelBuilder.cpp
    NeuralNetworks.cpp
    VersionedIDevice.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

#Dynamic link to shared libraries
target_link_libraries(${TARGET_NAME}
    pthread
    cast_nn_hidl_base
    textclassifier_hash
)

target_link_libraries(${TARGET_NAME}
    neuralnetworks_common
    dl
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
