cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Eigen)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pthread")
set(PROJECT_VERSION 1.0.0.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

include_directories(${THIRD_PARTY_DIR}/eigen/Eigen)

add_executable(${PROJECT_NAME}
        main.cpp
        EigenLinearRegression.cpp
        PolynomialFitting.cpp
)

target_link_libraries(${PROJECT_NAME}
        ${EXTRA_LIBS}
)