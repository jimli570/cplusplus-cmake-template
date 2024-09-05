#include "mylibrary/MyLibrary.hpp"
#include "mylibrary/version.hpp"

namespace mylibrary {

std::string_view MyLibrary::getVersion() const {
  return version::VERSION_FULL;
}

float MyLibrary::dotProduct(const glm::vec3& a, const glm::vec3& b) const {
  return glm::dot(a, b);
}

}  // namespace mylibrary
