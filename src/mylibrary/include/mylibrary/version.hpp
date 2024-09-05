#pragma once

#include <string_view>

namespace mylibrary::version {

constexpr std::string_view VERSION_FULL{ "0.1.0.0" };
constexpr int VERSION_MAJOR { 0 };
constexpr int VERSION_MINOR { 1 };
constexpr int VERSION_PATCH { 0 };
constexpr int VERSION_TWEAK { 0 };

}  // namespace engine::version
