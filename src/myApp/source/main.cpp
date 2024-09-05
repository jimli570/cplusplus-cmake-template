#include <iostream>
#include <string>

#include <glm/glm.hpp>
#include <mylibrary/MyLibrary.hpp>

#include "main.hpp"
#include "version.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[] ) {
  mylibrary::MyLibrary mylibrary;

  const glm::vec3 vectorA(1.0f, 0.0f, 0.0f);
  const glm::vec3 vectorB(1.0f, 1.0f, 0.0f);
  const float dotProduct = mylibrary.dotProduct(vectorA, vectorB);

  std::cout << "Hello, World!" << std::endl;

  std::cout << "vectorA = (" << vectorA.x << ", " << vectorA.y << ", " << vectorA.z << ")" << std::endl;
  std::cout << "vectorB = (" << vectorB.x << ", " << vectorB.y << ", " << vectorB.z << ")" << std::endl;
  std::cout << "Using external library for calucating dot product of two vectors: " << std::endl;
  std::cout << "mylibrary.dotProduct(vectorA, vectorB) = " << dotProduct << std::endl;
  
  std::cout << "Your as using version " << myapp::version::VERSION_FULL << " of my 'MyApp'" << std::endl;
  std::cout << "Your as using version " << mylibrary.getVersion() << " of my 'MyLibrary'" << std::endl;

  return 0;
}