#include "gtest/gtest.h"
#include "GpioAvrDriver.h"

TEST(GpioAvr, Set_pin_value) {

    uint8_t port_c = 0x00;
    uint8_t ddr_c  = 0x00;
    uint8_t pin    = 0x02;

    gpio_avr_driver::GpioAvr Gpio(&ddr_c, &port_c, pin);
    Gpio.Set();

//    EXPECT_TRUE(ddr_c == (1 << pin ));
//    EXPECT_TRUE(port_c == (1 << pin ));
}
