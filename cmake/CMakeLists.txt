cmake_minimum_required(VERSION 3.13)

project(cmakeProject) 

set(SOURCES main.cpp solver/solver.cpp)
set(HEADERS solver/solver.h)
add_subdirectory(stack)

add_executable(cmakeProject ${SOURCES} ${HEADERS})
 
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
