
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 2.8)

project(Gpio_driver)

include (../External/PlatformDependency.cmake)

if (${_TARGET_PLATFORM} STREQUAL "AVR")

    set(SOURCES
        GpioAvrDriver.cpp
        )

elseif (${_TARGET_PLATFORM} STREQUAL "RASPBERRYPI")

    set (SOURCES
        GpioRpi.cpp
        )
endif()

include_directories(
    ../External/include/
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
