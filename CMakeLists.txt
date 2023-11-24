cmake_minimum_required(VERSION 3.10.0)

project(student_data)

add_subdirectory(src)

add_executable(student_data app/main.cpp)

target_link_libraries(student_data PRIVATE student_lib)
