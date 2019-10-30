#ifndef HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IPREPAREDMODEL_H
#define HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IPREPAREDMODEL_H

#include <android/hardware/neuralnetworks/1.0/IPreparedModel.h>
#include <android/hardware/neuralnetworks/1.0/types.h>
#include <android/hardware/neuralnetworks/1.2/IBurstCallback.h>
#include <android/hardware/neuralnetworks/1.2/IBurstContext.h>
#include <android/hardware/neuralnetworks/1.2/IExecutionCallback.h>
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
 * IPreparedModel describes a model that has been prepared for execution and
 * is used to launch executions.
 */
struct IPreparedModel : public ::android::hardware::neuralnetworks::V1_0::IPreparedModel {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.neuralnetworks@1.2::IPreparedModel"
     */
//    static const char* descriptor;
//
//    /**
//     * Returns whether this object's implementation is outside of the current process.
//     */
//    virtual bool isRemote() const override { return false; }
//
    /**
     * Launches an asynchronous execution on a prepared model.
     * 
     * The execution is performed asynchronously with respect to the caller.
     * execute must verify the inputs to the function are correct. If there is
     * an error, execute must immediately invoke the callback with the
     * appropriate ErrorStatus value, then return with the same ErrorStatus. If
     * the inputs to the function are valid and there is no error, execute must
     * launch an asynchronous task to perform the execution in the background,
     * and immediately return with ErrorStatus::NONE. If the asynchronous task
     * fails to launch, execute must immediately invoke the callback with
     * ErrorStatus::GENERAL_FAILURE, then return with
     * ErrorStatus::GENERAL_FAILURE.
     * 
     * When the asynchronous task has finished its execution, it must
     * immediately invoke the callback object provided as an input to the
     * execute function. This callback must be provided with the ErrorStatus of
     * the execution.
     * 
     * If the prepared model was prepared from a model wherein all
     * tensor operands have fully specified dimensions, and the inputs
     * to the function are valid, then the execution should launch
     * and complete successfully (ErrorStatus::NONE). There must be
     * no failure unless the device itself is in a bad state.
     * 
     * Multiple threads can call the execute function on the same IPreparedModel
     * object concurrently with different requests.
     * 
     * @param request The input and output information on which the prepared
     *                model is to be executed.
     * @param callback A callback object used to return the error status of
     *                 the execution. The callback object's notify function must
     *                 be called exactly once, even if the execution was
     *                 unsuccessful.
     * @return status Error status of the call, must be:
     *                - NONE if task is successfully launched
     *                - DEVICE_UNAVAILABLE if driver is offline or busy
     *                - GENERAL_FAILURE if there is an unspecified error
     *                - OUTPUT_INSUFFICIENT_SIZE if provided output buffer is
     *                  not large enough to store the resultant values
     *                - INVALID_ARGUMENT if one of the input arguments is
     *                  invalid
     */
    virtual ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> execute(const ::android::hardware::neuralnetworks::V1_0::Request& request, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IExecutionCallback>& callback) = 0;

    /**
     * Launches an asynchronous execution on a prepared model.
     * 
     * The execution is performed asynchronously with respect to the caller.
     * execute_1_2 must verify the inputs to the function are correct. If there is
     * an error, execute_1_2 must immediately invoke the callback with the
     * appropriate ErrorStatus value, then return with the same ErrorStatus. If
     * the inputs to the function are valid and there is no error, execute_1_2 must
     * launch an asynchronous task to perform the execution in the background,
     * and immediately return with ErrorStatus::NONE. If the asynchronous task
     * fails to launch, execute_1_2 must immediately invoke the callback with
     * ErrorStatus::GENERAL_FAILURE, then return with
     * ErrorStatus::GENERAL_FAILURE.
     * 
     * When the asynchronous task has finished its execution, it must
     * immediately invoke the callback object provided as an input to the
     * execute_1_2 function. This callback must be provided with the ErrorStatus of
     * the execution.
     * 
     * If the prepared model was prepared from a model wherein all
     * tensor operands have fully specified dimensions, and the inputs
     * to the function are valid, then the execution should launch
     * and complete successfully (ErrorStatus::NONE). There must be
     * no failure unless the device itself is in a bad state.
     * 
     * Any number of calls to the execute, execute_1_2, and executeSynchronously
     * functions, in any combination, may be made concurrently, even on the same
     * IPreparedModel object.
     * 
     * @param request The input and output information on which the prepared
     *                model is to be executed.
     * @param measure Specifies whether or not to measure duration of the execution.
     *                The duration runs from the time the driver sees the call
     *                to the execute_1_2 function to the time the driver invokes
     *                the callback.
     * @param callback A callback object used to return the error status of
     *                 the execution. The callback object's notify function must
     *                 be called exactly once, even if the execution was
     *                 unsuccessful.
     * @return status Error status of the call, must be:
     *                - NONE if task is successfully launched
     *                - DEVICE_UNAVAILABLE if driver is offline or busy
     *                - GENERAL_FAILURE if there is an unspecified error
     *                - OUTPUT_INSUFFICIENT_SIZE if provided output buffer is
     *                  not large enough to store the resultant values
     *                - INVALID_ARGUMENT if one of the input arguments is
     *                  invalid
     */
    virtual ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> execute_1_2(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& callback) = 0;

    /**
     * Return callback for executeSynchronously
     */
    using executeSynchronously_cb = std::function<void(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>& outputShapes, const ::android::hardware::neuralnetworks::V1_2::Timing& timing)>;
    /**
     * Performs a synchronous execution on a prepared model.
     * 
     * The execution is performed synchronously with respect to the caller.
     * executeSynchronously must verify the inputs to the function are
     * correct. If there is an error, executeSynchronously must immediately
     * return with the appropriate ErrorStatus value. If the inputs to the
     * function are valid and there is no error, executeSynchronously must
     * perform the execution, and must not return until the execution is
     * complete.
     * 
     * If the prepared model was prepared from a model wherein all tensor
     * operands have fully specified dimensions, and the inputs to the function
     * are valid, then the execution should complete successfully
     * (ErrorStatus::NONE). There must be no failure unless the device itself is
     * in a bad state.
     * 
     * Any number of calls to the execute, execute_1_2, and executeSynchronously
     * functions, in any combination, may be made concurrently, even on the same
     * IPreparedModel object.
     * 
     * @param request The input and output information on which the prepared
     *                model is to be executed.
     * @param measure Specifies whether or not to measure duration of the execution.
     *                The duration runs from the time the driver sees the call
     *                to the executeSynchronously function to the time the driver
     *                returns from the function.
     * @return status Error status of the execution, must be:
     *                - NONE if execution is performed successfully
     *                - DEVICE_UNAVAILABLE if driver is offline or busy
     *                - GENERAL_FAILURE if there is an unspecified error
     *                - OUTPUT_INSUFFICIENT_SIZE if at least one output
     *                  operand buffer is not large enough to store the
     *                  corresponding output
     *                - INVALID_ARGUMENT if one of the input arguments is
     *                  invalid
     * @return outputShapes A list of shape information of model output operands.
     *                      The index into "outputShapes" corresponds to the index
     *                      of the output operand in the Request outputs vector.
     *                      outputShapes must be empty unless the status is either
     *                      NONE or OUTPUT_INSUFFICIENT_SIZE.
     * @return Timing Duration of execution. Unless measure is YES and status is
     *                NONE, all times must be reported as UINT64_MAX. A driver may
     *                choose to report any time as UINT64_MAX, indicating that
     *                measurement is not available.
     */
    virtual ::android::hardware::Return<void> executeSynchronously(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, executeSynchronously_cb _hidl_cb) = 0;

    /**
     * Return callback for configureExecutionBurst
     */
    using configureExecutionBurst_cb = std::function<void(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IBurstContext>& context)>;
    /**
     * Configure a Burst object used to execute multiple inferences on a
     * prepared model in rapid succession.
     * 
     * @param callback A callback object used to retrieve memory resources
     *                 corresponding to a unique identifiers ("slots").
     * @param requestChannel Used by the client to send a serialized Request to
     *                       the Burst for execution. requestChannel must not be
     *                       used to pass a second Request object until a result
     *                       has been received from resultChannel.
     * @param resultChannel Used by the service to return the results of an
     *                      execution to the client: the status of the execution
     *                      and OutputShape of all output tensors. resultChannel
     *                      must be used to return the results if a Request was
     *                      sent through the requestChannel.
     * @return status Error status of configuring the execution burst, must be:
     *                - NONE if the burst is successfully configured
     *                - DEVICE_UNAVAILABLE if driver is offline or busy
     *                - GENERAL_FAILURE if there is an unspecified error
     *                - INVALID_ARGUMENT if one of the input arguments is
     *                  invalid
     * @return context Object containing all resources (such as cached
     *                 hidl_memory) related to a Burst if successful, otherwise
     *                 nullptr.
     */
    virtual ::android::hardware::Return<void> configureExecutionBurst(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IBurstCallback>& callback, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqRequestDatum>& requestChannel, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqResultDatum>& resultChannel, configureExecutionBurst_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>> castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>> castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModel>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IPreparedModel> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPreparedModel> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPreparedModel> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPreparedModel> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IPreparedModel> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPreparedModel> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPreparedModel> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPreparedModel> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& o);

//
// type header definitions for package
//

//static inline std::string toString(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& o) {
//    std::string os = "[class or subclass of ";
//    os += ::android::hardware::neuralnetworks::V1_2::IPreparedModel::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_NEURALNETWORKS_V1_2_IPREPAREDMODEL_H
