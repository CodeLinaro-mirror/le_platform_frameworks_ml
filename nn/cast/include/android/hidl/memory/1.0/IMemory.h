#ifndef HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMEMORY_H
#define HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMEMORY_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hidl {
namespace memory {
namespace V1_0 {

struct IMemory : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hidl.memory@1.0::IMemory"
     */
    static const char* descriptor;

    /**
     * Notify that you are about to use all of this memory.
     */
    virtual ::android::hardware::Return<void> update() = 0;

    /**
     * Notify that you are about to use the specific range.
     *
     * start + length must be < size
     *
     * @param start Offset from start of buffer about to be updated.
     * @param length Number of bytes to be updated.
     */
    virtual ::android::hardware::Return<void> updateRange(uint64_t start, uint64_t length) = 0;

    /**
     * Notify that you are about to start reading all of this memory.
     */
    virtual ::android::hardware::Return<void> read() = 0;

    /**
     * Notify that you are about to read the specific range.
     *
     * @param start Offset from start of buffer about to be read.
     * @param length Number of bytes to be read.
     */
    virtual ::android::hardware::Return<void> readRange(uint64_t start, uint64_t length) = 0;

    /**
     * Notify that you are done reading and/or writing this memory.
     *
     * Must commit all previous update's and updateAll's.
     */
    virtual ::android::hardware::Return<void> commit() = 0;

    /**
     * Must return the same value everytime it is called. Must be callable
     * at any point in or outside of the update/commit process.
     *
     * @return ptr Actual pointer to underlying memory.
     */
    virtual ::android::hardware::Return<void*> getPointer() = 0;

    /**
     * @return size Size in bytes of underlying memory.
     */
    virtual ::android::hardware::Return<uint64_t> getSize() = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hidl::memory::V1_0::IMemory>> castFrom(const ::android::sp<::android::hidl::memory::V1_0::IMemory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hidl::memory::V1_0::IMemory>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     * 
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IMemory> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMemory> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMemory> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMemory> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IMemory> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMemory> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMemory> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMemory> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hidl::memory::V1_0::IMemory>& o);

}  // namespace V1_0
}  // namespace memory
}  // namespace hidl
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HIDL_MEMORY_V1_0_IMEMORY_H
