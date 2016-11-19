#!/bin/bash

build=0
run_tests=0
clean=0

exit_code=0

readonly BUILD_DIR=bin
readonly TEST_DIR=bin_tests

function build_Gpio_driver {
    local retval=0

    mkdir -p ${BUILD_DIR}
    cd ${BUILD_DIR}
    cmake ..
    make
    retval=$?
    cd ..

    return ${retval}
}

function run_tests {
    local retval=0

    mkdir -p ${TEST_DIR}
    cd ${TEST_DIR}
    cmake ../tests
    make
    ./Gpio_driver_unit_tests
    retval=$?
    cd ..

    return ${retval}
}

function clean {
    rm -r ${BUILD_DIR}
    rm -r ${TEST_DIR}
}

while getopts ":btc" opt; do
    case ${opt} in
        b) build=1      ;;
        t) run_tests=1  ;;
        c) clean=1      ;;
        \?)
            echo "Invalid option: -${OPTARG}" >$2
            exit 1 ;;
    esac
done

if [ 1 == ${build} ]; then
    build_Gpio_driver
    if [ $? != 0 ]; then
        exit_code=1
    fi
fi

if [ 1 == ${run_tests} ]; then
    run_tests
    if [ $? != 0 ]; then
        exit_code=1
    fi
fi

if [ 1 == ${clean} ]; then
    clean
    if [ $? != 0 ]; then
        exit_code=1
    fi
fi

exit $exit_code

