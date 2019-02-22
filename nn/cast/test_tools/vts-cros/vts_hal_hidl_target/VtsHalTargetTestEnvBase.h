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

#ifndef __VTS_HAL_TARGET_TEST_ENV_BASE_H
#define __VTS_HAL_TARGET_TEST_ENV_BASE_H

#include <gtest/gtest.h>

#include <android/hardware/neuralnetworks/1.0/IDevice.h>
#include <android/hardware/neuralnetworks/1.0/types.h>

using namespace std;

namespace testing {

// Enum class indicates the required combination mode for registered services.
enum HalCombMode {
  // Get the full permutation of all the registered service instances.
  // E.g. Hal service s1 with instances (n1, n2) and s2 with instances (n3, n4),
  // Return combination (s1/n1, s2/n3), (s1/n1, s2/n4), (s1/n2, s2/n3),
  // (s1/n2, s2/n4).
  FULL_PERMUTATION = 0,
  // Get the registered service instances with the same service name.
  // E.g. Hal service s1 with instances (n1, n2) and s2 with instances (n1, n2),
  // Return combination (s1/n1, s2/n1), (s1/n2, s2/n2).
  NAME_MATCH,
  // Do not return the service instance combinations. This is used in cases when
  // the test logic specifically handles the testing instances. E.g. drm tests.
  NO_COMBINATION,
};

// A class for test environment setup
class VtsHalTargetTestEnvBase : public ::testing::Environment {
 public:
  VtsHalTargetTestEnvBase() {}

  /*
   * SetUp process, should not be overridden by the test.
   */
  void SetUp() final;

  /*
   * TearDown process, should not be overridden by the test.
   */
  void TearDown() final;

  /*
   * Test should override this method for any custom setup process.
   */
  virtual void TestSetUp() {}

  /*
   * Test should override this method for any custom teardown process.
   */
  virtual void TestTearDown() {}

  /* Parses the command line argument, extracts the vts reserved flags and
   * leaves other options untouched.
   * Must be called when the test environment is created is registered.
   */
  void init(int* argc, char** argv);

  void setCombMode(HalCombMode mode) { mode_ = mode; }

  android::sp<android::hardware::neuralnetworks::V1_0::IDevice> getDevice();

 private:
  /*
   * Parses VTS specific flags, currently support two flags:
   * --list_hal_drivers to print all registered service.
   * --hal_instance to pass a HAL driver instance. e.g.
   * --hal_instance=libvendor_driver.so
   * It is possible to have multiple --hal_instance options passed if
   * multiple hal drivers are used in the test.
   * Returns true if successfully passed the given arg, false if arg is null or
   * unknown flag.
   */
  bool parseVtsTestOption(const char* arg);

  /*
   * Prints all registered sercives.
   */
  void listAvailableDevices();

  /*
   * Internal method to add a hal service instance.
   */
  void addHalInstance(const string& halInstance);

  /*
   * Find available devices.
   */
  void FindAvailableDevices();

  std::vector<std::string> halInstances_;
  std::vector<std::string> halAvailableDevices_;

  bool listAvailableDevices_ = false;
  bool inited_ = false;

  // Required combination mode for hal instances.
  HalCombMode mode_ = HalCombMode::FULL_PERMUTATION;

  std::vector<android::sp<android::hardware::neuralnetworks::V1_0::IDevice>> devices_;
  std::vector<void*> device_handles_;
};

}  // namespace testing


#endif  // __VTS_HAL_TARGET_TEST_ENV_BASE_H
