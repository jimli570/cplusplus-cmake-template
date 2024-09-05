SET(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
SET(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# -----------------------------------------------------------
# Generate the version-file 'version.hpp' from
# the template 'myLibraryVersion.hpp.in'
# -----------------------------------------------------------
message(STATUS "Generating ${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/myAppVersion.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp)

# -----------------------------------------------------------
# Add source & header files
# -----------------------------------------------------------
SET(APP_SOURCES
  ${SRC_DIR}/main.cpp
)
SET(APP_HEADERS
  ${INC_DIR}/main.hpp
)

# -----------------------------------------------------------
# MyApp application
# -----------------------------------------------------------
add_executable(${MAIN_APP_NAME})

target_compile_options(${MAIN_APP_NAME}
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
  INTERFACE
  PUBLIC
  $<$<CONFIG:Debug>:MYAPP_DEBUG_BUILD>
  $<$<CONFIG:Debug>:MYAPP_DEBUG_PRINT>

  $<$<CONFIG:RelWithDebInfo>:MYAPP_DEBUG_BUILD>
  $<$<CONFIG:RelWithDebInfo>:MYAPP_DEBUG_PRINT>

  $<$<CONFIG:Release>:MYAPP_RELEASE_BUILD>
  $<$<CONFIG:MinSizeRel>:MYAPP_RELEASE_BUILD>
)

target_include_directories(${MAIN_APP_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>

  # https://stackoverflow.com/questions/58729233/what-is-the-use-case-for-generator-expression-on-target-include-directories
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/engine>
)

target_sources(${MAIN_APP_NAME} PRIVATE ${APP_SOURCES} PRIVATE ${APP_HEADERS})

# -----------------------------------------------------------
# External libraries
# # -----------------------------------------------------------
target_link_libraries(${MAIN_APP_NAME}
  PRIVATE
  ${MY_LIBRARY_NAME}
)
