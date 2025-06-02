cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Common)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

add_executable(${PROJECT_NAME}
        main.cpp
        Point.h
        VectorUtilities.h
)

target_link_libraries(${PROJECT_NAME}
        ${EXTRA_LIBS}
)