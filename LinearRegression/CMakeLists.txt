cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(LinearRegression)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})

add_executable(${PROJECT_NAME}
        main.cpp
        LinearRegression.h
        LinearRegression.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Common")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/Utilities")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Utilities")

target_link_libraries(${PROJECT_NAME}
        utils
        pthread
        ${EXTRA_LIBS}
)