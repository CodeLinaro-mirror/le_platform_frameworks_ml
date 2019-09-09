/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2018 The Android Open Source Project
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

#ifndef ANDROID_HIDL_SHP_MEMORY_V1_0_MEMORY_H
#define ANDROID_HIDL_SHP_MEMORY_V1_0_MEMORY_H

#include <android/hidl/memory/1.0/IMemory.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hidl {
namespace memory {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hidl::memory::V1_0::IMemory;

struct ShpMemory : public IMemory {
  ShpMemory(const hidl_memory& memory);
  ~ShpMemory();

  // Methods from ::android::hidl::memory::V1_0::IMemory.
  Return<void> update() override;
  Return<void> updateRange(uint64_t start, uint64_t length) override;
  Return<void> read() override;
  Return<void> readRange(uint64_t start, uint64_t length) override;
  Return<void> commit() override;
  Return<void*> getPointer() override;
  Return<uint64_t> getSize() override;

 private:
  hidl_memory mMemory;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace memory
}  // namespace hidl
}  // namespace android

#endif  // ANDROID_HIDL_SHP_MEMORY_V1_0_MEMORY_H
