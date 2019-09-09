#ifndef HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IPREPAREDMODELCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IPREPAREDMODELCALLBACK_H

#include <android/hardware/neuralnetworks/1.0/IPreparedModel.h>
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

struct IPreparedModelCallback : public ::android::hidl::base::V1_0::IBase {
    // Forward declaration for forward reference support:

    /**
     * notify must be invoked immediately after the asynchronous task holding
     * this callback has finished preparing the model. If the model was
     * successfully prepared, notify must be invoked with ErrorStatus::NONE and
     * the prepared model. If the model was not able to be successfully
     * prepared, notify must be invoked with the appropriate ErrorStatus and
     * nullptr as the IPreparedModel. If the asynchronous task holding this
     * callback fails to launch or if the model provided to
     * IDevice::prepareModel is invalid, notify must be invoked with the
     * appropriate error as well as nullptr for the IPreparedModel.
     *
     * @param status Error status returned from the asynchronous model
     *               preparation task; must be:
     *               - NONE if the asynchronous task successfully prepared the
     *                 model
     *               - DEVICE_UNAVAILABLE if driver is offline or busy
     *               - GENERAL_FAILURE if the asynchronous task resulted in an
     *                 unspecified error
     *               - INVALID_ARGUMENT if one of the input arguments to
     *                 prepareModel is invalid
     * @param preparedModel A model that has been asynchronously prepared for
     *                      execution. If the model was unable to be prepared
     *                      due to an error, nullptr must be passed in place of
     *                      the IPreparedModel object.
     */
    virtual ::android::hardware::Return<void> notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModel>& preparedModel) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;


    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;




};

}  // namespace V1_0
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_0_IPREPAREDMODELCALLBACK_H
