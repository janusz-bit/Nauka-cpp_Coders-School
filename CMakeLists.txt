cmake_minimum_required(VERSION 3.10)
PROJECT(MarkdownReader)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# No shared libraries
# This is to ensure that we only build static libraries.
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

add_executable(MarkdownReader src/main.cpp)
set_target_properties(MarkdownReader PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

target_link_libraries(MarkdownReader PUBLIC SDL3::SDL3)