#include "gtest/gtest.h"
#include "GpioAvrDriver.h"

TEST(GpioAvr, output_pull_up) {

    uint8_t port_c      = 0;
    uint8_t ddr_c       = 0;
    uint8_t pin_c       = 0;
    uint8_t pad_num1    = 4;
    uint8_t pad_num2    = 0;

    gpio_avr_driver::GpioAvr Gpio1(ddr_c, port_c, pin_c, pad_num1, gpio_driver::GPIO_OUTPUT, gpio_driver::GPIO_PULL_UP);
    EXPECT_TRUE(ddr_c == (1 << pad_num1));
    EXPECT_TRUE(port_c == (1 << pad_num1));
    EXPECT_TRUE(pin_c == 0);

    gpio_avr_driver::GpioAvr Gpio2(ddr_c, port_c, pin_c, pad_num2, gpio_driver::GPIO_OUTPUT, gpio_driver::GPIO_PULL_UP);
    EXPECT_TRUE(ddr_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(port_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(pin_c == 0);
}

TEST(GpioAvr, output_pull_up_change_pad) {

    uint8_t port_c      = 0;
    uint8_t ddr_c       = 0;
    uint8_t pin_c       = 0;
    uint8_t pad_num1    = 2;
    uint8_t pad_num2    = 3;

    gpio_avr_driver::GpioAvr Gpio1(ddr_c, port_c, pin_c, pad_num1, gpio_driver::GPIO_OUTPUT, gpio_driver::GPIO_PULL_UP);
    gpio_avr_driver::GpioAvr Gpio2(ddr_c, port_c, pin_c, pad_num2, gpio_driver::GPIO_OUTPUT, gpio_driver::GPIO_PULL_UP);

    Gpio1.Set();

    EXPECT_TRUE(ddr_c == ((1 << pad_num1 ) | (1 << pad_num2)));
    EXPECT_TRUE(port_c == ((1 << pad_num1 ) | (1 << pad_num2)));
    EXPECT_TRUE(pin_c == 0);

    Gpio2.Set();

    EXPECT_TRUE(ddr_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(port_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(pin_c == 0);

    Gpio1.Clear();

    EXPECT_TRUE(ddr_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(port_c == (1 << pad_num2));
    EXPECT_TRUE(pin_c == 0);

    Gpio2.Clear();

    EXPECT_TRUE(ddr_c == ((1 << pad_num1) | (1 << pad_num2)));
    EXPECT_TRUE(port_c == 0);
    EXPECT_TRUE(pin_c == 0);
}

TEST(GpioAvr, input_no_pullup_test_pad) {

    uint8_t ddr_c = 0xFF;
    uint8_t port_c = 0xFF;
    uint8_t pin_c = 0x00;
    uint8_t pad_num1 = 0;
    uint8_t pad_num2 = 5;


}

TEST(GpioAvr, input_no_pullup) {

    uint8_t ddr_c = 0xFF;
    uint8_t port_c = 0xFF;
    uint8_t pin_c = 0x00;
    uint8_t pad_num1 = 2;
    uint8_t pad_num2 = 6;

    gpio_avr_driver::GpioAvr gpio1(ddr_c, port_c, pin_c, pad_num1, gpio_driver::GPIO_INPUT, gpio_driver::GPIO_NO_PULL);
    gpio_avr_driver::GpioAvr gpio2(ddr_c, port_c, pin_c, pad_num2, gpio_driver::GPIO_INPUT, gpio_driver::GPIO_NO_PULL);

    EXPECT_TRUE((ddr_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE((port_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE(pin_c == 0);

    gpio1.Set();

    EXPECT_TRUE((ddr_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE((port_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE((pin_c & ((1 << pad_num1) | (1 << pad_num2))) == (1 << pad_num1));

    gpio2.Set();
    EXPECT_TRUE((ddr_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE((port_c & ((1 << pad_num1) | (1 << pad_num2))) == 0);
    EXPECT_TRUE((pin_c & ((1 << pad_num1) | (1 << pad_num2))) == ((1 << pad_num1) | (1 << pad_num2)));




}

