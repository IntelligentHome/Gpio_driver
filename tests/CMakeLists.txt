cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Gpio_driver_tests)

enable_language(C CXX)

set(GOOGLETEST_ROOT ../../External/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    ../
    ../../External/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
    Gpio_driver_unit_tests
    main.cc
    GpioAvrTests.cc
    ../GpioAvrDriver.cpp
    )

add_dependencies(Gpio_driver_unit_tests googletest)

target_link_libraries(
    Gpio_driver_unit_tests
    googletest
    pthread
    )

