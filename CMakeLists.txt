
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 2.8)

project(Gpio_driver)

include (../External/PlatformDependency.cmake)

set(SOURCES
    GpioAvrDriver.cpp
    )

include_directories(
    ../External/include/
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
