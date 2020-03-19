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

#define LOG_TAG "VtsHalTargetTestEnvBase"

#include "VtsHalTargetTestEnvBase.h"

#include <iostream>
#include <string>
#include <dirent.h>
#include <dlfcn.h>
#include <android-base/logging.h>

static constexpr const char* kListFlag = "--list_hal_drivers";
static constexpr const char* kInstanceFlag = "--hal_instance";

static constexpr const char* kNnhalPath = INSTALL_LIB_DIR"/nn/";
static constexpr const char* kDefaultDevice = "libunifiedhal-driver.so";

using namespace std;
using namespace android;
using namespace android::hardware::neuralnetworks::V1_0;

namespace testing {

void VtsHalTargetTestEnvBase::SetUp() {
  if (!inited_) {
    ALOGE("Environment not inited, did you forget to call init()?");
    exit(-1);
  }

  if (listAvailableDevices_) {
    listAvailableDevices();
    exit(0);
  }

  if (halInstances_.size() == 0) {
    addHalInstance(kDefaultDevice);
  }

  for (auto &name : halInstances_) {
    try {
      void *lib_handle;
      dlerror();
      printf("Name: %s\n", name.c_str());
      std::string library = kNnhalPath + name;
      lib_handle = dlopen(library.c_str(), RTLD_NOW);

      const char *dlsym_error = dlerror();
      if (!lib_handle || dlsym_error) {
        ALOGE("%s\n", dlsym_error);
        continue;
      }
      device_handles_.push_back(lib_handle);
      std::vector<sp<IDevice>> (*NNHalDeviceNewFunc)();
      NNHalDeviceNewFunc =
        (std::vector<sp<IDevice>> (*)()) dlsym(lib_handle, "NNHalDeviceNew");
      if (dlsym_error) {
        ALOGE("%s\n", dlsym_error);
        continue;
      }
      std::vector<sp<IDevice>> devices(NNHalDeviceNewFunc());
      for (auto device : devices) {
        devices_.push_back(device);
      }
    } catch (const std::exception &e) {
      ALOGE("%s\n", e.what());
    }
  }
  // Call the customized setup process.
  TestSetUp();
}

void VtsHalTargetTestEnvBase::TearDown() {
  // Call the customized teardown process.
  TestTearDown();

  devices_.clear();
  for (auto handle : device_handles_) {
    try {
      if (nullptr != handle) {
        dlclose(handle);
      }
    } catch (const std::exception &e) {
      ALOGE("%s\n", e.what());
    }
  }
  device_handles_.clear();
}

void VtsHalTargetTestEnvBase::init(int* argc, char** argv) {
  if (inited_) return;
  FindAvailableDevices();
  for (int i = 1; i < *argc; i++) {
    if (parseVtsTestOption(argv[i])) {
      // Shift the remainder of the argv list left by one.
      for (int j = i; j != *argc; j++) {
        argv[j] = argv[j + 1];
      }

      // Decrements the argument count.
      (*argc)--;

      // We also need to decrement the iterator as we just removed an element.
      i--;
    }
  }
  inited_ = true;
}

bool VtsHalTargetTestEnvBase::parseVtsTestOption(const char* arg) {
  // arg must not be NULL.
  if (arg == NULL) return false;

  if (strncmp(arg, kListFlag, strlen(kListFlag)) == 0) {
    listAvailableDevices_ = true;
    return true;
  }

  std::string halName(kDefaultDevice);
  std::string instanceName("0");

  if (strncmp(arg, kInstanceFlag, strlen(kInstanceFlag)) == 0) {
    std::string halInstance(arg);
    halInstance = halInstance.substr(halInstance.find(kInstanceFlag) + strlen(kInstanceFlag) + 1);
    halName = halInstance.substr(0, halInstance.find('/'));
    if (halInstance.find('/') != string::npos) {
        instanceName = halInstance.substr(halInstance.find('/') + 1);
    }
    // value is the part after "--hal_instance=<hal name>/<device name>"
    addHalInstance(halName);
    device_index_ = std::stoi(instanceName);
    return true;
  }
  return false;
}

void VtsHalTargetTestEnvBase::addHalInstance(
    const string& halInstance) {

  auto it = std::find(halInstances_.begin(), halInstances_.end(), halInstance);
  if (it == halInstances_.end()) {
    auto itr = std::find(halAvailableDevices_.begin(), halAvailableDevices_.end(), halInstance);
    if (itr != halInstances_.end()) {
      halInstances_.push_back(halInstance);
    }
  } else {
    ALOGE("Existing instance %s\n", halInstance.c_str());
    exit(-1);
  }
}

void VtsHalTargetTestEnvBase::listAvailableDevices() {
  for (string device : halAvailableDevices_) {
    printf("hal_device: %s\n", device.c_str());
  }
  printf("comb_mode: %d\n", mode_);
}

void VtsHalTargetTestEnvBase::FindAvailableDevices() {
  std::string path(kNnhalPath);
  DIR *dir = opendir(path.c_str());
  if (nullptr == dir) {
    ALOGE("Failed to open nn drivers folder: %s\n", strerror(errno))
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != nullptr) {
    if (std::string(entry->d_name).compare(".") == 0 ||
        std::string(entry->d_name).compare("..") == 0) {
        continue;
    }
    halAvailableDevices_.push_back(std::string(entry->d_name));
    printf("Device found: %s\n", entry->d_name);
  }
}

sp<IDevice> VtsHalTargetTestEnvBase::getDevice() {
  if (devices_.size() > device_index_) {
    return devices_[device_index_];
  }
  return nullptr;
}

}  // namespace testing
