#pragma once

#include <glm/glm.hpp>

#include <string_view>

namespace mylibrary {

class MyLibrary final {
 public:
  MyLibrary() = default;
  ~MyLibrary() = default;
  MyLibrary& operator=( const MyLibrary& ) = default;
  MyLibrary& operator=( MyLibrary&& ) = default;
  MyLibrary( const MyLibrary& ) = default;
  MyLibrary( MyLibrary&& ) = default;

  [[nodiscard]] std::string_view getVersion() const;
  [[nodiscard]] float dotProduct(const glm::vec3& a, const glm::vec3& b) const;
  

 protected:
 private:
};

}  
