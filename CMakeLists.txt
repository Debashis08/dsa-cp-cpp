cmake_minimum_required (VERSION 3.10)
project ("dsa-cp-cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# .clang-tidy setup
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CLANG_TIDY_COMMAND
        "${CLANG_TIDY_EXE}"
        "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
        "--extra-arg-before=-Wno-unknown-warning-option"
        "--extra-arg-before=-Wno-c++98-compat-pedantic"
        "--quiet"
    )
endif()

add_subdirectory(src)

cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()
add_subdirectory(tests)