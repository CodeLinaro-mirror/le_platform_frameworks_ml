set (TARGET_NAME neuralnetworks_common)

set (SOURCE_FILES
    CpuExecutor.cpp
    OperationsUtils.cpp
    operations/Activation.cpp
    operations/Concatenation.cpp
    operations/Conv2D.cpp
    operations/DepthwiseConv2D.cpp
    operations/EmbeddingLookup.cpp
    operations/FullyConnected.cpp
    operations/HashtableLookup.cpp
    operations/LSHProjection.cpp
    operations/LSTM.cpp
    operations/Normalization.cpp
    operations/Pooling.cpp
    operations/Reshape.cpp
    operations/RNN.cpp
    operations/SimpleMath.cpp
    operations/StridedSlice.cpp
    operations/SVDF.cpp
    Utils.cpp
    ValidateHal.cpp
)

add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})

include_directories(${SYSROOT_INCDIR}/gemmlowp)

target_include_directories(${TARGET_NAME} PRIVATE include)
target_include_directories(${TARGET_NAME} PRIVATE operations)
target_include_directories(${TARGET_NAME} PRIVATE .)

target_include_directories(${TARGET_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(${TARGET_NAME}
    base
    log
    textclassifier_hash
    cast_nn_hidl_memory
    cast_nn_hidl_allocator
    tensorflow-lite
)