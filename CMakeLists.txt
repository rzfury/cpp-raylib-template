cmake_minimum_required(VERSION 3.24...3.30)

project(raylib_rzf)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(raylib 5.0 QUIET)

include(FetchContent)
if (NOT raylib_FOUND)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP True
  )
  FetchContent_MakeAvailable(raylib)
endif()

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(raylib_rzf game.cpp)

add_custom_command(
  TARGET raylib_rzf POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:raylib_rzf>/resources
)

target_link_libraries(raylib_rzf raylib)
target_include_directories(raylib_rzf PUBLIC ${raylib_SOURCE_DIR}/src)

target_include_directories(raylib_rzf PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(raylib_rzf PROPERTIES
  LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
  LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS"
)

target_compile_definitions(raylib_rzf PRIVATE $<$<CONFIG:Debug>:DEBUG_MODE>)
