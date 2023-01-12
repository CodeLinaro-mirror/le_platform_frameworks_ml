set (TARGET_NAME neuralnetworks_common)

add_definitions(-DNN_INCLUDE_CPU_IMPLEMENTATION)

set (SOURCE_FILES
    OperationResolver.cpp
    operations/Activation.cpp
    operations/BidirectionalSequenceRNN.cpp
    operations/Broadcast.cpp
    operations/ChannelShuffle.cpp
    operations/Comparisons.cpp
    operations/Concatenation.cpp
    operations/Conv2D.cpp
    operations/Dequantize.cpp
    operations/Elementwise.cpp
    operations/FullyConnected.cpp
    operations/Gather.cpp
    operations/GenerateProposals.cpp
    operations/HeatmapMaxKeypoint.cpp
    operations/InstanceNormalization.cpp
    operations/L2Normalization.cpp
    operations/LogicalAndOr.cpp
    operations/LogicalNot.cpp
    operations/LogSoftmax.cpp
    operations/Neg.cpp
    operations/Pooling.cpp
    operations/PRelu.cpp
    operations/Quantize.cpp
    operations/Reduce.cpp
    operations/ResizeImageOps.cpp
    operations/RoiAlign.cpp
    operations/RoiPooling.cpp
    operations/Select.cpp
    operations/Slice.cpp
    operations/Softmax.cpp
    operations/Transpose.cpp
    operations/TransposeConv2D.cpp
    operations/UnidirectionalSequenceLSTM.cpp
    operations/UnidirectionalSequenceRNN.cpp
    Utils.cpp
    ValidateHal.cpp
    Utils.cpp
    ExecutionBurstController.cpp
    ExecutionBurstServer.cpp
    CpuExecutor.cpp
    ExecutionBurstController.cpp
    ExecutionBurstServer.cpp
    GraphDump.cpp
    IndexedShapeWrapper.cpp
    OperationsUtils.cpp
    TokenHasher.cpp
    Utils.cpp
    ValidateHal.cpp
    operations/ArgMinMax.cpp
    operations/BidirectionalSequenceLSTM.cpp
    operations/Cast.cpp
    operations/DepthwiseConv2D.cpp
    operations/EmbeddingLookup.cpp
    operations/ExpandDims.cpp
    operations/GroupedConv2D.cpp
    operations/HashtableLookup.cpp
    operations/LSHProjection.cpp
    operations/LSTM.cpp
    operations/MaximumMinimum.cpp
    operations/Multinomial.cpp
    operations/Normalization.cpp
    operations/Pow.cpp
    operations/TopK_V2.cpp
    operations/QuantizedLSTM.cpp
    operations/Reshape.cpp
    operations/RNN.cpp
    operations/SimpleMath.cpp
    operations/Split.cpp
    operations/StridedSlice.cpp
    operations/SVDF.cpp
    operations/Tile.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${TARGET_NAME} PRIVATE include)
target_include_directories(${TARGET_NAME} PRIVATE operations)
target_include_directories(${TARGET_NAME} PRIVATE .)
target_include_directories(${TARGET_NAME} PRIVATE ${SYSROOT_INCDIR}/gemmlowp)

target_include_directories(${TARGET_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(${TARGET_NAME}
    neuralnetworks_headers
    cutils
    utils
    base
    log
    pthread
    textclassifier_hash
    cast_nn_hidl_memory
    cast_nn_hidl_allocator
    tensorflow-lite
    philox_random
    android.hardware.neuralnetworks_1_2
    fmq
    crypto
)

install(
    TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${NNAPI_LIB_DIR}
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

install(DIRECTORY include
    DESTINATION include/neuralnetworks_common
    FILES_MATCHING
    PATTERN "*.h"
)
