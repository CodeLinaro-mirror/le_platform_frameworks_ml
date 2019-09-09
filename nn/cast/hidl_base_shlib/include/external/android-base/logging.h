/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef ANDROID_BASE_LOGGING_H
#define ANDROID_BASE_LOGGING_H

#include <functional>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdarg.h>

#include "external/android-base/macros.h"

namespace android {
namespace base {

#define LOG_BUF_SIZE 4096

enum LogSeverity {
  VERBOSE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  FATAL,
};

// This class is used to explicitly ignore values in the conditional
// logging macros.  This avoids compiler warnings like "value computed
// is not used" and "statement has no effect".
class LogMessageVoidify {
 public:
  LogMessageVoidify() = default;
  // This has to be an operator with a precedence lower than << but
  // higher than ?:
  void operator&(std::ostream&) { }
};

// This is never instantiated. This is only used with LogMessageVoidify to have
// the correct type.
static std::ostream* local_swallow_stream;

// Logs a message to logcat on Android otherwise to stderr. If the severity is
// FATAL it also causes an abort. For example:
//
//     LOG(FATAL) << "We didn't expect to reach here";
#define LOG(severity)                                   \
  std::cout << std::endl                                \
            << "[" __FILE__ << "(" << __LINE__ << "):(" \
            << ::android::base::severity << ")]"

// TODO(bingxue): Differentiate ABORT_AFTER_LOG_FATAL for clang static analyzer
// when a LogMessage class is properly implemented.
#define ABORT_AFTER_LOG_FATAL for (;; abort())
struct LogAbortAfterFullExpr {
  ~LogAbortAfterFullExpr() __attribute__((noreturn)) { abort(); }
  explicit operator bool() const { return false; }
};
// Provides an expression that evaluates to the truthiness of `x`, automatically
// aborting if `c` is true.
#define ABORT_AFTER_LOG_EXPR_IF(c, x) (((c) && ::android::base::LogAbortAfterFullExpr()) || (x))
#define ABORT_AFTER_LOG_FATAL_EXPR(x) ABORT_AFTER_LOG_EXPR_IF(true, x)

// Check whether condition x holds and LOG(FATAL) if not. The value of the
// expression x is only evaluated once. Extra logging can be appended using <<
// after. For example:
//
//     CHECK(false == true) results in a log message of
//       "Check failed: false == true".
#define CHECK(x)                                      \
  LIKELY((x)) || ABORT_AFTER_LOG_FATAL_EXPR(false) || \
      LOG(FATAL) << "Check failed: " #x << " "

#define EAT_STREAM_PARAMETERS \
  true ? (void) 0 : ::android::base::LogMessageVoidify() & *::android::base::local_swallow_stream

#if defined(NDEBUG) && !defined(DCHECK_ALWAYS_ON)
#define DCHECK_IS_ON() 0
#else
#define DCHECK_IS_ON() 1
#endif

// TODO(bingxue): consider depend on platform specific logging utils instead.
#if !DCHECK_IS_ON()
#define DCHECK(condition) EAT_STREAM_PARAMETERS
#else
#define DCHECK(condition)  CHECK(condition)
#endif // !DCHECK_IS_ON()

#define DCHECK_EQ(v1, v2) DCHECK(v1 == v2)

// TODO(bingxue): We should implement a proper VLOG and proper log stream.
#if !DCHECK_IS_ON()
#define DLOG(severity) EAT_STREAM_PARAMETERS
#else // DCHECK_IS_ON()
#define DLOG(severity) LOG(severity)
#endif // DCHECK_IS_ON()

#define DLOG_IF(severity, condition) \
  !(condition) ? (void)0 : DLOG(severity)

// Thread unsafe ALOG macros for replacing utils/Log.h.
inline void nn_print_log(char* buf, int buf_size, const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(buf, buf_size, fmt, ap);
  va_end(ap);
}

#define ALOG(severity, fmt, ...)                                           \
  {                                                                        \
    char buffer[LOG_BUF_SIZE];                                             \
    android::base::nn_print_log(buffer, LOG_BUF_SIZE, fmt, ##__VA_ARGS__); \
    LOG(severity) << buffer;                                               \
  }

#define ALOGI(...) ALOG(INFO, ##__VA_ARGS__)

#define ALOGW(...) ALOG(WARNING, ##__VA_ARGS__)

#define ALOGE(...) ALOG(ERROR, ##__VA_ARGS__)

#if !DCHECK_IS_ON()
#define ALOGD(...) ((void)0)
#else
#define ALOGD(...) ALOG(DEBUG, __VA_ARGS__)
#endif // !DCHECK_IS_ON

// Log a fatal error. If the given condition fails, this stops program execution
// like a normal assertion but also generates the given message. This is NOT
// stripped from release builds. Not that the condition test is -inverted- from
// the normal assert() semantics.
#ifndef LOG_ALWAYS_FATAL_IF
#define LOG_ALWAYS_FATAL_IF(condition, fmt, ...)                           \
  if (UNLIKELY(condition)) {                                             \
    char buffer[LOG_BUF_SIZE];                                           \
    android::base::nn_print_log(buffer, LOG_BUF_SIZE, fmt, ##__VA_ARGS__); \
    ABORT_AFTER_LOG_FATAL LOG(FATAL) << buffer;                          \
  }
#endif  // LOG_ALWAYS_FATAL_IF
#ifndef LOG_FATAL_IF
#define LOG_FATAL_IF(cond, ...) LOG_ALWAYS_FATAL_IF(cond, __VA_ARGS__)
#endif  // LOG_FATAL_IF
#ifndef LOG_ALWAYS_FATAL
#define LOG_ALWAYS_FATAL(...) LOG_ALWAYS_FATAL_IF(true, __VA_ARGS__)
#endif  // LOG_ALWAYS_FATAL

// Assertion that generates a log message when the assertion fails.
// TODO(bingxue): ALOG_ASSERT should be stripped out of release builds.
#ifndef ALOG_ASSERT
#define ALOG_ASSERT(cond, fmt, ...) \
  LOG_ALWAYS_FATAL_IF(!(cond), fmt, ##__VA_ARGS__)
#endif
}  // namespace base
}  // namespace android

#endif  // ANDROID_BASE_LOGGING_H
