cmake_minimum_required(VERSION 3.13)

project(cmakeProject) 
add_subdirectory(stack)

add_executable(cmakeProject main.cpp solver/solver.cpp solver/solver.h)
 
set_target_properties(
       cmakeProject PROPERTIES
       CXX_STANDARD 17
       CXX_STANDARD_REQUIRED ON
)
target_include_directories( 
       cmakeProject
       PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}/../stack
)

target_link_libraries(cmakeProject lib)
