#pragma once

//==================================================================================================
// READ THIS BEFORE UPDATING THIS FILE
//==================================================================================================
// Keep the code here (including the includes) as simple as possible given that this file will be
// directly included by Swift and the Swift/C++ interop is far from complete. Including headers or
// having code that is not supported by Swift may lead into weird compilation errors that can be
// difficult to debug.
// For more information, see
// https://github.com/apple/swift/blob/swift-5.7.3-RELEASE/docs/CppInteroperability/CppInteroperabilityStatus.md

#include <functional>
#include <string>

#include "source/common/common/base_logger.h"

namespace Envoy {

/** The callbacks for the Envoy Engine. */
struct EngineCallbacks {
  std::function<void()> on_engine_running = [] {};
  std::function<void()> on_exit = [] {};
};

/** The callbacks for Envoy Logger. */
struct EnvoyLogger {
  std::function<void(Logger::Logger::Levels, const std::string&)> on_log =
      [](Logger::Logger::Levels, const std::string&) {};
  std::function<void()> on_exit = [] {};
};

} // namespace Envoy
