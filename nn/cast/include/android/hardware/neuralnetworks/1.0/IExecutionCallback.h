#ifndef HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IEXECUTIONCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IEXECUTIONCALLBACK_H

#include <android/hardware/neuralnetworks/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_0 {

struct IExecutionCallback : public ::android::hidl::base::V1_0::IBase {
    // Forward declaration for forward reference support:


    /**
     * notify must be invoked immediately after the asynchronous task has
     * finished performing the execution. notify must be provided with the
     * ErrorStatus resulting from the execution. If the asynchronous task
     * is not launched, notify must be invoked with the appropriate error.
     *
     * @param status Error status returned from launching the asynchronous task
     *               (if the launch fails) or from the asynchronous task itself
     *               (if the launch succeeds). Must be:
     *               - NONE if the asynchronous execution was successful
     *               - DEVICE_UNAVAILABLE if driver is offline or busy
     *               - GENERAL_FAILURE if the asynchronous task resulted in an
     *                 unspecified error
     *               - OUTPUT_INSUFFICIENT_SIZE if provided output buffer is
     *                 not large enough to store the resultant values
     *               - INVALID_ARGUMENT if one of the input arguments to
     *                 prepareModel is invalid
     */
    virtual ::android::hardware::Return<void> notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;

};

}  // namespace V1_0
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IEXECUTIONCALLBACK_H
