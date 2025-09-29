cmake_minimum_required(VERSION 3.10)
project(QuantFinance)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(quant_finance
    src/main.cpp
    src/black_scholes.cpp
    src/greeks.cpp
    src/monte_carlo.cpp
)
