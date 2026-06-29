cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  0003_GraphTests

  0001_bfs_test.cc

)

target_link_libraries(
  0003_GraphTests
  GTest::gtest_main
  0003_Graph
)

# Add .clang-tidy configuration to this library.
if(CLANG_TIDY_EXE)
  set_target_properties(0003_Graph PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
endif()

include(GoogleTest)
gtest_discover_tests(0003_GraphTests DISCOVERY_TIMEOUT 30)