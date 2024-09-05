cmake_minimum_required(VERSION 3.15)

# -----------------------------------------------------------
# Because the toolchain file is evaluated during the project()
# call, all CMake-level variables that modify a vcpkg setting
# must be set before the first call to project()
# -----------------------------------------------------------
set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg") # vcpkg root directory
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake") # Link vcpkg with CMake

# -----------------------------------------------------------
# Project / Version
# -----------------------------------------------------------
set(VERSION_PROJECT_MAJOR 0)
set(VERSION_PROJECT_MINOR 1)
set(VERSION_PROJECT_PATCH 0)
set(VERSION_PROJECT_TWEAK 0)
set(VERSION_PROJECT_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.${VERSION_TWEAK}")
project(MyProject
  VERSION "${VERSION_PROJECT_MAJOR}.${VERSION_PROJECT_MINOR}.${VERSION_PROJECT_PATCH}"
  LANGUAGES CXX C
  DESCRIPTION "My project description")

# -----------------------------------------------------------
# Project options
# -----------------------------------------------------------
set(CMAKE_CXX_STANDARD 20) # C++20
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# The directory from which the test executable will be called.
set(WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# -----------------------------------------------------------
# Default compile options used by targets
# -----------------------------------------------------------
set(DEFAULT_COMPILE_OPTIONS
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
  $<$<CXX_COMPILER_ID:MSVC>:/WX>
  $<$<CXX_COMPILER_ID:MSVC>:/MP>

  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wall>
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wextra>
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wpedantic>
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Werror>

  # $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-O3>
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Ofast>
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-fms-extensions>)

# -----------------------------------------------------------
# Application name / Version
# Note: Version used for generating version.hpp
# -----------------------------------------------------------
set(MAIN_APP_NAME "MyApp")
set(VERSION_MYAPP_MAJOR 0)
set(VERSION_MYAPP_MINOR 2)
set(VERSION_MYAPP_PATCH 0)
set(VERSION_MYAPP_TWEAK 0)
set(VERSION_MYAPP_FULL "${VERSION_MYAPP_MAJOR}.${VERSION_MYAPP_MINOR}.${VERSION_MYAPP_PATCH}.${VERSION_MYAPP_TWEAK}")

# -----------------------------------------------------------
# Library name / Version
# Note: Version used for generating version.hpp
# -----------------------------------------------------------
SET(MY_LIBRARY_NAME "MyLibrary")
set(VERSION_MYLIBRARY_MAJOR 0)
set(VERSION_MYLIBRARY_MINOR 1)
set(VERSION_MYLIBRARY_PATCH 0)
set(VERSION_MYLIBRARY_TWEAK 0)
set(VERSION_MYLIBRARY_FULL "${VERSION_MYLIBRARY_MAJOR}.${VERSION_MYLIBRARY_MINOR}.${VERSION_MYLIBRARY_PATCH}.${VERSION_MYLIBRARY_TWEAK}")

# -----------------------------------------------------------
# Add external libraries fetched through VCPKG, so they can be found
# -----------------------------------------------------------
find_package(glm CONFIG REQUIRED QUIET) # -------- Math

# -----------------------------------------------------------
# Add source directories
# -----------------------------------------------------------
add_subdirectory(src)
