cmake_minimum_required(VERSION 3.10)
project(StringCalculatorApp)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(StringCalculator)
add_executable(StringCalculatorApp source.cpp)
target_link_libraries(StringCalculatorApp PUBLIC StringCalculator)
target_include_directories(StringCalculatorApp PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/StringCalculator"
                          )