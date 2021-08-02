cmake_minimum_required(VERSION 2.8)
add_compile_options(-Wall -g)
project(l9hw6)
add_executable(l9hw6 src/l9hw6.c)
target_include_directories(l9hw6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(l9hw6 PRIVATE m)

