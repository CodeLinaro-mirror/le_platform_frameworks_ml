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

#ifndef __VTS_HAL_TARGET_TEST_BASE_H
#define __VTS_HAL_TARGET_TEST_BASE_H

#include <VtsHalTargetTestEnvBase.h>
#include <gtest/gtest.h>
#include <utils/RefBase.h>
#include <android-base/logging.h>

#if !defined(__LE_NN__)
#include <hidl/HidlSupport.h>
#endif

#define VTS_HAL_HIDL_GET_STUB "VTS_HAL_GET_STUB"

using namespace std;

namespace testing {

using ::android::sp;

// VTS target side test template
class VtsHalTargetTestBase : public ::testing::Test {
 public:
  /*
   * Internal test class setup function.
   */
  virtual void SetUp() override {
    ALOGI("[Test Case] %s.%s BEGIN", getTestSuiteName().c_str(),
          getTestCaseName().c_str());
    string testCaseInfo = getTestCaseInfo();
    if (testCaseInfo.size()) {
      ALOGD("Test case info: %s", testCaseInfo.c_str());
    }

    HalSetUp();
  }

  /*
   * Internal test class tear-down function.
   */
  virtual void TearDown() override {
    HalTearDown();

    ALOGI("[Test Case] %s.%s END", getTestSuiteName().c_str(),
          getTestCaseName().c_str());
    string testCaseInfo = getTestCaseInfo();
    if (testCaseInfo.size()) {
      ALOGD("Test case info: %s", testCaseInfo.c_str());
    }
  }

  /*
   * HAL test class setup function.
   * Will be called in the end of SetUp() function.
   */
  virtual void HalSetUp() {}

  /*
   * HAL test class tear-down function.
   * Will be called in the beginning of TearDown() function.
   */
  virtual void HalTearDown() {}

  /*
   * Return test case info as string.
   */
  virtual string getTestCaseInfo() const { return ""; }

private:

  /*
   * Return test suite name as string.
   */
  string getTestSuiteName() const;

  /*
   * Return test case name as string.
   */
  string getTestCaseName() const;
};

}  // namespace testing

#endif  // __VTS_HAL_TARGET_TEST_BASE_H
