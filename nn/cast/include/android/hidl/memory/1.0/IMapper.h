#ifndef HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMAPPER_H
#define HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMAPPER_H

#include <android/hidl/base/1.0/IBase.h>
#include <android/hidl/memory/1.0/IMemory.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>

namespace android {
namespace hidl {
namespace memory {
namespace V1_0 {

struct IMapper : public ::android::hidl::base::V1_0::IBase {
    // Forward declaration for forward reference support:

    virtual bool isRemote() const { return false; }

    virtual ::android::hardware::Return<::android::sp<::android::hidl::memory::V1_0::IMemory>> mapMemory(const ::android::hardware::hidl_memory& mem) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;


    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;

    // cast static functions
    static ::android::hardware::Return<::android::sp<::android::hidl::memory::V1_0::IMapper>> castFrom(const ::android::sp<::android::hidl::memory::V1_0::IMapper>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<::android::hidl::memory::V1_0::IMapper>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static const char* descriptor;

    static ::android::sp<IMapper> tryGetService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IMapper> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    static ::android::sp<IMapper> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    static ::android::sp<IMapper> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    static ::android::sp<IMapper> getService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IMapper> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    static ::android::sp<IMapper> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    static ::android::sp<IMapper> getService(bool getStub) { return getService("default", getStub); }
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
};

}  // namespace V1_0
}  // namespace memory
}  // namespace hidl
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMAPPER_H
