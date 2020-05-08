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
#include <sstream>
#include <memory>
#include <stdio.h>
#include <stdarg.h>
#include <log/log.h>

#include "android-base/macros.h"

enum LogSeverity
{
  VERBOSE, DEBUG, INFO, WARNING, ERROR, FATAL,
};

class LogStream : public std::stringstream {
public:
    LogStream(LogSeverity severity) : severity_(severity) {}
    ~LogStream() {
        switch(severity_) {
            case VERBOSE:
                ALOGV("%s", this->str().c_str());
                break;
            case DEBUG:
                ALOGD("%s", this->str().c_str());
                break;
            case INFO:
                ALOGI("%s", this->str().c_str());
                break;
            case WARNING:
                ALOGW("%s", this->str().c_str());
                break;
            case ERROR:
            case FATAL:
                ALOGE("%s", this->str().c_str());
                break;
        }
    }
private:
    LogSeverity severity_;
};

#define LOG(sevirity) LogStream(sevirity) << std::endl                                \
                                          << "[" __FILE__ << "(" << __LINE__ << "):(" \
                                          << #sevirity << ")]"

namespace android
{

namespace base
{

#define LOG_BUF_SIZE 4096

// This class is used to explicitly ignore values in the conditional
// logging macros.  This avoids compiler warnings like "value computed
// is not used" and "statement has no effect".
class LogMessageVoidify
{
 public:
  LogMessageVoidify() = default;
  // This has to be an operator with a precedence lower than << but
  // higher than ?:
  void operator&(std::ostream&) {}
};

// This is never instantiated. This is only used with LogMessageVoidify to have
// the correct type.
static std::ostream* local_swallow_stream;

// TODO(bingxue): Differentiate ABORT_AFTER_LOG_FATAL for clang static analyzer
// when a LogMessage class is properly implemented.
#define ABORT_AFTER_LOG_FATAL for (;; abort())
struct LogAbortAfterFullExpr
{
  ~LogAbortAfterFullExpr() __attribute__((noreturn))
  {
    abort();
  }
  explicit operator bool() const
  {
    return false;
  }
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

// clang-format off
// Helper for CHECK_xx(x,y) macros.
#define CHECK_OP(LHS, RHS, OP)                                                 \
  for (auto _values = ::android::base::MakeEagerEvaluator(LHS, RHS);           \
       UNLIKELY(!(_values.lhs OP _values.rhs));                                \
       /* empty */)                                                            \
  ABORT_AFTER_LOG_FATAL_EXPR(false) ||                                         \
  LOG(FATAL)  << "Check failed: " << #LHS << " " << #OP << " " << #RHS << " (" #LHS "=" << _values.lhs \
              << ", " #RHS "=" << _values.rhs << ") "
// clang-format on

// Check whether a condition holds between x and y, LOG(FATAL) if not. The value
// of the expressions x and y is evaluated once. Extra logging can be appended
// using << after. For example:
//
//     CHECK_NE(0 == 1, false) results in
//       "Check failed: false != false (0==1=false, false=false) ".
#define CHECK_EQ(x, y) CHECK_OP(x, y, == )
#define CHECK_NE(x, y) CHECK_OP(x, y, != )
#define CHECK_LE(x, y) CHECK_OP(x, y, <= )
#define CHECK_LT(x, y) CHECK_OP(x, y, < )
#define CHECK_GE(x, y) CHECK_OP(x, y, >= )
#define CHECK_GT(x, y) CHECK_OP(x, y, > )

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

// Temporary class created to evaluate the LHS and RHS, used with
// MakeEagerEvaluator to infer the types of LHS and RHS.
template<typename LHS, typename RHS>
struct EagerEvaluator
{
  constexpr EagerEvaluator(LHS l, RHS r) :
    lhs(l), rhs(r)
  {
  }
  LHS lhs;
  RHS rhs;
};

// Helper function for CHECK_xx.
template <typename LHS, typename RHS>
constexpr EagerEvaluator<LHS, RHS> MakeEagerEvaluator(LHS lhs, RHS rhs) {
  return EagerEvaluator<LHS, RHS>(lhs, rhs);
}

// Explicitly instantiate EagerEvalue for pointers so that char*s aren't treated
// as strings. To compare strings use CHECK_STREQ and CHECK_STRNE. We rely on
// signed/unsigned warnings to protect you against combinations not explicitly
// listed below.
#define EAGER_PTR_EVALUATOR(T1, T2)               \
  template <>                                     \
  struct EagerEvaluator<T1, T2> {                 \
    EagerEvaluator(T1 l, T2 r)                    \
        : lhs(reinterpret_cast<const void*>(l)),  \
          rhs(reinterpret_cast<const void*>(r)) { \
    }                                             \
    const void* lhs;                              \
    const void* rhs;                              \
  }
EAGER_PTR_EVALUATOR(const char*, const char*);
EAGER_PTR_EVALUATOR(const char*, char*);
EAGER_PTR_EVALUATOR(char*, const char*);
EAGER_PTR_EVALUATOR(char*, char*);
EAGER_PTR_EVALUATOR(const unsigned char*, const unsigned char*);
EAGER_PTR_EVALUATOR(const unsigned char*, unsigned char*);
EAGER_PTR_EVALUATOR(unsigned char*, const unsigned char*);
EAGER_PTR_EVALUATOR(unsigned char*, unsigned char*);
EAGER_PTR_EVALUATOR(const signed char*, const signed char*);
EAGER_PTR_EVALUATOR(const signed char*, signed char*);
EAGER_PTR_EVALUATOR(signed char*, const signed char*);
EAGER_PTR_EVALUATOR(signed char*, signed char*);

// Thread unsafe ALOG macros for replacing utils/Log.h.
inline void nn_print_log(char* buf, int buf_size, const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(buf, buf_size, fmt, ap);
  va_end(ap);
}

}  // namespace base
}  // namespace android

#endif  // ANDROID_BASE_LOGGING_H
