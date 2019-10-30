#ifndef HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IEXECUTIONCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IEXECUTIONCALLBACK_H

#include <android/hardware/neuralnetworks/1.0/IExecutionCallback.h>
#include <android/hardware/neuralnetworks/1.0/types.h>
#include <android/hardware/neuralnetworks/1.2/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_2 {

/**
 * IExecutionCallback must be used to return the error status result from an
 * execution asynchronously launched from IPreparedModel::execute.
 */
struct IExecutionCallback : public ::android::hardware::neuralnetworks::V1_0::IExecutionCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.neuralnetworks@1.2::IExecutionCallback"
     */
    static const char* descriptor;

//    /**
//     * Returns whether this object's implementation is outside of the current process.
//     */
//    virtual bool isRemote() const override { return false; }

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

    /**
     * Either notify_1_2 or notify must be invoked immediately after the asynchronous
     * task has finished performing the execution. Either notify_1_2 or notify must be
     * provided with the ErrorStatus from the execution. If the asynchronous task is
     * not launched, either notify_1_2 or notify must be invoked with the appropriate
     * error.
     * 
     * @param status Error status returned from launching the asynchronous task
     *               (if the launch fails) or from the asynchronous task itself
     *               (if the launch succeeds). Must be:
     *               - NONE if the asynchronous execution was successful
     *               - DEVICE_UNAVAILABLE if driver is offline or busy
     *               - GENERAL_FAILURE if the asynchronous task resulted in an
     *                 unspecified error
     *               - OUTPUT_INSUFFICIENT_SIZE if at least one output
     *                 operand buffer is not large enough to store the
     *                 corresponding output
     *               - INVALID_ARGUMENT if one of the input arguments to
     *                 prepareModel is invalid
     * @param outputShapes A list of shape information of model output operands.
     *                     The index into "outputShapes" corresponds with to index
     *                     of the output operand in the Request outputs vector.
     *                     outputShapes must be empty unless the status is either
     *                     NONE or OUTPUT_INSUFFICIENT_SIZE.
     * @return Timing Duration of execution. Unless MeasureTiming::YES was passed when
     *                launching the execution and status is NONE, all times must
     *                be reported as UINT64_MAX. A driver may choose to report
     *                any time as UINT64_MAX, indicating that particular measurement is
     *                not available.
     */
    virtual ::android::hardware::Return<void> notify_1_2(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>& outputShapes, const ::android::hardware::neuralnetworks::V1_2::Timing& timing) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IExecutionCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IExecutionCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExecutionCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExecutionCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExecutionCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IExecutionCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExecutionCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExecutionCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExecutionCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& o);

//
// type header definitions for package
//

//static inline std::string toString(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& o) {
//    std::string os = "[class or subclass of ";
//    os += ::android::hardware::neuralnetworks::V1_2::IExecutionCallback::descriptor;
//    os += "]";
//    os += o->isRemote() ? "@remote" : "@local";
//    return os;
//}


}  // namespace V1_2
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IEXECUTIONCALLBACK_H
