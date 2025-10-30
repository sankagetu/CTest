cmake_minimum_required(VERSION 3.16)
project(c_sample C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(score src/score.c)
target_include_directories(score PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Debug のときだけ "score" を計装
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(score PRIVATE --coverage -O0 -g)
  target_link_options(score PRIVATE --coverage)
endif()

enable_testing()

add_executable(test_score tests/test_score.c)
target_link_libraries(test_score PRIVATE score criterion)

# ★ 実行ファイル側にも --coverage を付与（これで libgcov がリンクされる）
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_link_options(test_score PRIVATE --coverage)
endif()

add_test(NAME unit COMMAND test_score)
