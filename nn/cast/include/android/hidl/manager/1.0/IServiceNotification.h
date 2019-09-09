#ifndef HIDL_GENERATED_ANDROID_HIDL_MANAGER_V1_0_ISERVICENOTIFICATION_H
#define HIDL_GENERATED_ANDROID_HIDL_MANAGER_V1_0_ISERVICENOTIFICATION_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>

namespace android {
namespace hidl {
namespace manager {
namespace V1_0 {

struct IServiceNotification : public ::android::hidl::base::V1_0::IBase {
    typedef android::hardware::details::i_tag _hidl_tag;

    // Forward declaration for forward reference support:


    /**
     * Must be called when a service is registered.
     *
     * @param fqName         Fully-qualified instance name (see IServiceManager)
     * @param preexisting    If true, this means the registration was
     *                       pre-existing at the time this IServiceNotification
     *                       object is itself registered. Otherwise, this means
     *                       onRegistration is triggered by a newly registered
     *                       service.
     */
    virtual ::android::hardware::Return<void> onRegistration(const ::android::hardware::hidl_string& fqName, const ::android::hardware::hidl_string& name, bool preexisting) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;

};

}  // namespace V1_0
}  // namespace manager
}  // namespace hidl
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HIDL_MANAGER_V1_0_ISERVICENOTIFICATION_H
