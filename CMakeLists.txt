cmake_minimum_required (VERSION 2.8.11)
project (Robot_Food_Scheduler)

find_package(GTest REQUIRED)

add_library(schedulingLibrary src/order.cpp include/order.hpp src/recipe.cpp include/recipe.hpp src/recipeStep.cpp include/recipeStep.hpp)

add_executable(helloWorld src/helloWorld.cpp)
add_executable(runUnitTests test/runUnitTests.cpp)

target_link_libraries(helloWorld schedulingLibrary)
target_link_libraries(runUnitTests gtest gtest_main pthread schedulingLibrary)
