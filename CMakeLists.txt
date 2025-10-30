cmake_minimum_required(VERSION 3.16)
project(c_sample C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Debug 時はカバレッジ計測用フラグを付与
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(--coverage -O0 -g)
  link_libraries(gcov)
endif()

add_library(score src/score.c)
target_include_directories(score PUBLIC ${CMAKE_SOURCE_DIR}/include)

enable_testing()

# テスト実行ファイル
add_executable(test_score tests/test_score.c)
target_link_libraries(test_score PRIVATE score criterion)

add_test(NAME unit COMMAND test_score)
