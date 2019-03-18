#ifndef HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H
#define HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>

namespace android {
namespace hidl {
namespace allocator {
namespace V1_0 {

struct IAllocator : public ::android::hidl::base::V1_0::IBase {
    // Forward declaration for forward reference support:

    using allocate_cb = std::function<void(bool success, const ::android::hardware::hidl_memory& mem)>;
    /**
     * Return memory must have instance name corresponding to this type of memory.
     *
     * @param size Size of memory to allocate in bytes.
     * @return success Whether allocation succeeded.
     * @return memory Unmapped memory object.
     */
    virtual ::android::hardware::Return<void> allocate(uint64_t size, allocate_cb _hidl_cb) = 0;

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

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;

    // cast static functions
    static ::android::hardware::Return<::android::sp<::android::hidl::allocator::V1_0::IAllocator>> castFrom(const ::android::sp<::android::hidl::allocator::V1_0::IAllocator>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<::android::hidl::allocator::V1_0::IAllocator>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static ::android::sp<IAllocator> getService(const std::string& type);
};

}  // namespace V1_0
}  // namespace allocator
}  // namespace hidl
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HIDL_ALLOCATOR_V1_0_IALLOCATOR_H
