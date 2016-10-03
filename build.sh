
function build_Gpio_driver {
    local retval=0

    mkdir -p bin
    cd bin
    cmake ..
    make
    retval=$?
    cd ..

    return $retval
}

function run_tests {
    local retval=0

    mkdir -p bin_tests
    cd bin_tests
    cmake ../tests
    make
    ./Gpio_driver_unit_tests
    retval=$?
    cd ..

    return $retval
}

function clean {
    rm -r -f bin
    rm -r -f bin_tests
}

if [ "$1" == "build" ]; then
    build_Gpio_driver
fi

if [ "$1" == "tests" ]; then
    run_tests
fi

if [ "$1" == "clean" ]; then
    clean
fi

if [ "$1" == "travis" ]; then
    build_Gpio_driver
    if [ $? != 0 ]; then
        exit 1
    fi

    run_tests
    if [ $? != 0 ]; then
        exit 1
    fi
fi

