cmake_minimum_required(VERSION 3.10)
PROJECT(MarkdownReader)


option(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create an option to switch between a system sdl library and a vendored SDL library
option(MYGAME_VENDORED "Use vendored libraries" OFF)


if(MYGAME_VENDORED)
    # This assumes you have added SDL as a submodule in vendored/SDL
    add_subdirectory(SDL EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL3 package,
    # 2. look for the SDL3-shared component, and
    # 3. fail if the shared component cannot be found.
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# No shared libraries
# This is to ensure that we only build static libraries.
# option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

add_executable(MarkdownReader src/main.cpp)
set_target_properties(MarkdownReader PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(MarkdownReader PUBLIC SDL3::SDL3)