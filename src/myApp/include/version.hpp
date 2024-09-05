#pragma once

#include <string_view>

namespace myapp::version {

constexpr std::string_view VERSION_FULL{ "0.2.0.0" };
constexpr int VERSION_MAJOR { 0 };
constexpr int VERSION_MINOR { 2 };
constexpr int VERSION_PATCH { 0 };
constexpr int VERSION_TWEAK { 0 };

}  // namespace engine::version
