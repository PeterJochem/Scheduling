cmake_minimum_required (VERSION 2.8.11)
project (Robot_Food_Scheduler)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-w)

find_package(GTest REQUIRED)

add_library(schedulingLibrary src/order.cpp include/order.hpp src/recipe.cpp include/recipe.hpp src/recipeStep.cpp include/recipeStep.hpp)

add_executable(createSchedule src/createSchedule.cpp)
add_executable(runUnitTests test/runUnitTests.cpp)

target_link_libraries(createSchedule schedulingLibrary)
target_link_libraries(runUnitTests gtest gtest_main pthread schedulingLibrary)
