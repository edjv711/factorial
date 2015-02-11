project(factorial CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-std=c++1y -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb")

add_executable(${PROJECT_NAME} main.cpp factorial.cpp)
