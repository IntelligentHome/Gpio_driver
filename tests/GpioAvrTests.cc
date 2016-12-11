#include "gtest/gtest.h"
#include "GpioAvrDriver.h"

TEST(GpioAvr, set_ddr_output) {

    uint8_t port_c = 0;
    uint8_t ddr_c  = 0;
    uint8_t pin1   = 4;
    uint8_t pin2   = 0;

    gpio_avr_driver::GpioAvr Gpio1(ddr_c, port_c, pin1);
    EXPECT_TRUE(ddr_c == (1 << pin1));

    gpio_avr_driver::GpioAvr Gpio2(ddr_c, port_c, pin2);
    EXPECT_TRUE(ddr_c == ((1 << pin1) | (1 << pin2)));
}

TEST(GpioAvr, set_pin) {

    uint8_t port_c = 0;
    uint8_t ddr_c  = 0;
    uint8_t pin1   = 2;
    uint8_t pin2   = 3;

    gpio_avr_driver::GpioAvr Gpio1(ddr_c, port_c, pin1);
    gpio_avr_driver::GpioAvr Gpio2(ddr_c, port_c, pin2);

    Gpio1.Set();

    EXPECT_TRUE(ddr_c == ((1 << pin1 ) | (1 << pin2)));
    EXPECT_TRUE(port_c == (1 << pin1 ));

    Gpio2.Set();

    EXPECT_TRUE(ddr_c == ((1 << pin1) | (1 << pin2)));
    EXPECT_TRUE(port_c == ((1 << pin1) | (1 << pin2)));
}

TEST(GpioAvr, clear_pin) {

    uint8_t pin1 = 5;
    uint8_t pin2 = 3;
    uint8_t port_c = (1 << pin1) | (1 << pin2);
    uint8_t ddr_c  = (1 << pin1) | (1 << pin2);

    gpio_avr_driver::GpioAvr Gpio1(ddr_c, port_c, pin1);
    gpio_avr_driver::GpioAvr Gpio2(ddr_c, port_c, pin2);

    Gpio1.Clear();
    EXPECT_TRUE(ddr_c == ((1 << pin1) | (1 << pin2)));
    EXPECT_TRUE(port_c == (1 << pin2));

    Gpio2.Clear();
    EXPECT_TRUE(ddr_c == ((1 << pin1) | (1 << pin2)));
    EXPECT_TRUE(port_c == 0);
}
