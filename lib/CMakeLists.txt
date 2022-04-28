set(LIBRARY_TARGET_NAME LibWaveFunctionCollapse)

find_package(fmt CONFIG)
find_package(spdlog CONFIG)

set(SOURCE_FILES "WaveFunctionCollapse.cpp")

add_library(${LIBRARY_TARGET_NAME} ${SOURCE_FILES})

add_library(${PROJECT_NAME}::${LIBRARY_TARGET_NAME} ALIAS ${LIBRARY_TARGET_NAME})

target_include_directories(${LIBRARY_TARGET_NAME} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")

target_link_libraries(
  ${LIBRARY_TARGET_NAME}
  PUBLIC  fmt::fmt
          spdlog::spdlog
  PRIVATE project_options
          project_warnings)

message(STATUS "Created target ${LIBRARY_TARGET_NAME} for export ${PROJECT_NAME}.")
