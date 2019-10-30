/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "neuralnetworks_hal_test"

#include "VtsHalNeuralnetworksLib.h"

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_2 {
namespace vts {
namespace functional {

// A class for test environment setup
NeuralnetworksEnvironment::NeuralnetworksEnvironment() {}

NeuralnetworksEnvironment::~NeuralnetworksEnvironment() {}

NeuralnetworksEnvironment* NeuralnetworksEnvironment::getInstance() {
    // This has to return a "new" object because it is freed inside
    // ::testing::AddGlobalTestEnvironment when the gtest is being torn down
    static NeuralnetworksEnvironment* instance = new NeuralnetworksEnvironment();
    return instance;
}

// The main test class for NEURALNETWORK HAL.
NeuralnetworksHidlTest::NeuralnetworksHidlTest() {}

NeuralnetworksHidlTest::~NeuralnetworksHidlTest() {}

void NeuralnetworksHidlTest::SetUp() {
    ::testing::VtsHalTargetTestBase::SetUp();
    NeuralnetworksEnvironment *env = NeuralnetworksEnvironment::getInstance();
    device_1_0 = env->getDevice();
    device = dynamic_cast<V1_2::IDevice*>(device_1_0.get());
    ASSERT_NE(nullptr, device.get());
}

void NeuralnetworksHidlTest::TearDown() {
    device_1_0 = nullptr;
    device = nullptr;
    ::testing::VtsHalTargetTestBase::TearDown();
}

sp<IPreparedModel> getPreparedModel_1_2(
    const sp<V1_2::implementation::PreparedModelCallback>& callback) {
    sp<V1_0::IPreparedModel> preparedModelV1_0 = callback->getPreparedModel();
    sp<IPreparedModel> preparedModelV1_2 = dynamic_cast<IPreparedModel*>(preparedModelV1_0.get());
    return preparedModelV1_2;
}

}  // namespace functional
}  // namespace vts
}  // namespace V1_2
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android

namespace android::hardware::neuralnetworks::V1_0 {

::std::ostream& operator<<(::std::ostream& os, ErrorStatus errorStatus) {
    return os << toString(errorStatus);
}

::std::ostream& operator<<(::std::ostream& os, DeviceStatus deviceStatus) {
    return os << toString(deviceStatus);
}

}  // namespace android::hardware::neuralnetworks::V1_0

using android::hardware::neuralnetworks::V1_2::vts::functional::NeuralnetworksEnvironment;

int main(int argc, char** argv) {
    ::testing::AddGlobalTestEnvironment(NeuralnetworksEnvironment::getInstance());
    ::testing::InitGoogleTest(&argc, argv);
    NeuralnetworksEnvironment::getInstance()->init(&argc, argv);

    int status = RUN_ALL_TESTS();
    return status;
}
