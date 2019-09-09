/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2016 The Android Open Source Project
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

#include "ShpAllocator.h"

#include <memory>

#include "external/android-base/logging.h"

namespace android {


namespace hidl {
namespace allocator {
namespace V1_0 {

#if defined(_LE_NN_)
::android::sp<IAllocator> IAllocator::getService(const std::string& /*type*/) {
  return new implementation::ShpAllocator;
}

#endif  // _LE_NN_

namespace implementation {

// static
hidl_memory ShpAllocator::allocateOne(uint64_t size) {
  void* data = nullptr;

  // NOTE: over-align to 8 byte for shared memory to avoid unaligned access for
  // arbitrary value types.
  int ret = posix_memalign(&data, 8, size);

  if (data == nullptr) {
    LOG(INFO) << "posix_memalgin failed with: " << ret << std::endl;
    return hidl_memory("shpmem", std::shared_ptr<uint8_t>(nullptr), 0);
  }

  return hidl_memory("shpmem",
                     std::shared_ptr<uint8_t>(static_cast<uint8_t*>(data), free),
                     size);
}

Return<void> ShpAllocator::allocate(uint64_t size, allocate_cb _hidl_cb) {
  hidl_memory memory = allocateOne(size);
  _hidl_cb(memory.shpmem().get() != nullptr /*success */,
           std::move(memory));
  return Void();
}

Return<void> ShpAllocator::batchAllocate(uint64_t size,
                                            uint64_t count,
                                            batchAllocate_cb _hidl_cb) {
  // resize fails if count > 2^32
  if (count > UINT32_MAX) {
    _hidl_cb(false /* success */, {});
    return Void();
  }

  hidl_vec<hidl_memory> batch;
  batch.resize(count);

  uint64_t allocated;
  bool is_successful = true;
  for (allocated = 0; allocated < count; ++allocated) {
    batch[allocated] = allocateOne(size);
    is_successful &= (batch[allocated].shpmem().get() != nullptr);
  }

  if (!is_successful) {
    // Delete all allocated hidl_memory.
    batch.resize(0);
  }

  _hidl_cb(is_successful /* success */, batch);

  return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace allocator
}  // namespace hidl
}  // namespace android
