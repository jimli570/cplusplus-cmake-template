SET(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/mylibrary)
SET(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/mylibrary)

# -----------------------------------------------------------
# Generate the version-file 'version.hpp' from
# the template 'myLibraryVersion.hpp.in'
# -----------------------------------------------------------
message(STATUS "Generating ${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/myLibraryVersion.hpp.in ${INC_DIR}/version.hpp)

# -----------------------------------------------------------
# Add source & header files
# -----------------------------------------------------------
SET(MYLIBRARY_SOURCES
  ${SRC_DIR}/myLibrary.cpp
)
SET(MYLIBRARY_HEADERS
  ${INC_DIR}/myLibrary.hpp
)

# -----------------------------------------------------------
# MyLibrary library
# -----------------------------------------------------------
add_library(${MY_LIBRARY_NAME} STATIC)

target_compile_options(${MY_LIBRARY_NAME}
  PUBLIC
  ${DEFAULT_COMPILE_OPTIONS}
  INTERFACE
  ${DEFAULT_COMPILE_OPTIONS}
  PRIVATE
  ${DEFAULT_COMPILE_OPTIONS}
)

# Set some compile definitions depending on the build type
target_compile_definitions(
  ${MAIN_APP_NAME}

  PRIVATE
  GLM_ENABLE_EXPERIMENTAL

  INTERFACE
  PUBLIC
  $<$<CONFIG:Debug>:MYLIBRARY_DEBUG_BUILD>
  $<$<CONFIG:Debug>:MYLIBRARY_DEBUG_PRINT>

  $<$<CONFIG:RelWithDebInfo>:MYLIBRARY_DEBUG_BUILD>
  $<$<CONFIG:RelWithDebInfo>:MYLIBRARY_DEBUG_PRINT>

  $<$<CONFIG:Release>:MYLIBRARY_RELEASE_BUILD>
  $<$<CONFIG:MinSizeRel>:MYLIBRARY_RELEASE_BUILD>
)

target_include_directories(${MY_LIBRARY_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>

  # https://stackoverflow.com/questions/58729233/what-is-the-use-case-for-generator-expression-on-target-include-directories
  # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
)

target_sources(${MY_LIBRARY_NAME} PRIVATE ${MYLIBRARY_SOURCES} PRIVATE ${MYLIBRARY_HEADERS})

# -----------------------------------------------------------
# External libraries
# # -----------------------------------------------------------
target_link_libraries(${MY_LIBRARY_NAME}
  PUBLIC
  glm::glm
)

target_include_directories(${MY_LIBRARY_NAME}
  PRIVATE
  ${GLM_INCLUDE_DIR}
)