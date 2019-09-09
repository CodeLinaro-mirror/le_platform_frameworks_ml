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

#include "VtsHalTargetTestBase.h"

using namespace std;

namespace testing {

string VtsHalTargetTestBase::getTestCaseName() const {
  return UnitTest::GetInstance()->current_test_info()->test_case_name();
}

string VtsHalTargetTestBase::getTestSuiteName() const {
  return UnitTest::GetInstance()->current_test_info()->name();
}

}  // namespace testing
