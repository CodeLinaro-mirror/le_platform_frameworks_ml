#ifndef HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H
#define HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hidl {
namespace allocator {
namespace V1_0 {

/**
 * Interface which allocates the required memory.
 */
struct IAllocator : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hidl.allocator@1.0::IAllocator"
     */
    static const char* descriptor;

    /**
     * Return callback for allocate
     */
    using allocate_cb = std::function<void(bool success, const ::android::hardware::hidl_memory& mem)>;
    /**
     * Return memory must have instance name corresponding to this type of memory.
     * 
     * @param size Size of memory to allocate in bytes.
     * @return success Whether allocation succeeded.
     * @return memory Unmapped memory object.
     */
    virtual ::android::hardware::Return<void> allocate(uint64_t size, allocate_cb _hidl_cb) = 0;

    /**
     * Return callback for batchAllocate
     */
    using batchAllocate_cb = std::function<void(bool success, const ::android::hardware::hidl_vec<::android::hardware::hidl_memory>& batch)>;
    /**
     * Return memory must have instance name corresponding to this type of memory.
     * 
     * @param size Size of memory to allocate in bytes.
     * @param count Number of memory instances to allocate.
     * @return success Whether allocation succeeded (returns false if any allocation failed).
     * @return batch Unmapped memory objects.
     */
    virtual ::android::hardware::Return<void> batchAllocate(uint64_t size, uint64_t count, batchAllocate_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hidl::allocator::V1_0::IAllocator>> castFrom(const ::android::sp<::android::hidl::allocator::V1_0::IAllocator>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hidl::allocator::V1_0::IAllocator>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IAllocator> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAllocator> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAllocator> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAllocator> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IAllocator> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAllocator> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAllocator> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAllocator> getService(bool getStub) { return getService("default", getStub); }
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

}  // namespace V1_0
}  // namespace allocator
}  // namespace hidl
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H
