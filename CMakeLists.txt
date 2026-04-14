cmake_minimum_required(VERSION 3.10)
project(UniversitySystem)

set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(UniversitySystem ${SRC_FILES})