find_package(docopt CONFIG)

# Generic test that uses conan libs
add_executable(intro main.cpp)

target_link_libraries(
  intro
  PRIVATE project_options
          project_warnings
          WaveFunctionCollapseCpp::LibWaveFunctionCollapseCpp
          docopt::docopt)

target_include_directories(intro PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")

