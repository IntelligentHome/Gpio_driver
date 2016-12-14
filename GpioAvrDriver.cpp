
#include "GpioAvrDriver.h"

namespace gpio_avr_driver {

GpioAvr::GpioAvr(
        volatile uint8_t&                   ddr,
        volatile uint8_t&                   port,
        volatile uint8_t&                   pin,
        uint8_t                             pad_num,
        const gpio_driver::GpioDirection    direction,
        const gpio_driver::GpioPull         pull)
        :
        ddr_(ddr),
        port_(port),
        pin_(pin),
        pad_num_(pad_num),
        direction_(direction),
        pull_(pull)
{

    if (gpio_driver::GPIO_INPUT == direction_)
        ddr_ &= ~(1 << pad_num_);
    else if (gpio_driver::GPIO_OUTPUT == direction_)
        ddr_ |= (1 << pad_num_);

    if (gpio_driver::GPIO_NO_PULL == pull_)
        port_ &= ~(1 << pad_num_);
    else if (gpio_driver::GPIO_PULL_UP == pull_)
        port_ |= (1 << pad_num_);
}


void GpioAvr::Set(void) {

    if (gpio_driver::GPIO_OUTPUT == direction_)
        port_ |= (1 << pad_num_);
    else if (gpio_driver::GPIO_INPUT == direction_)
        ddr_ &= ~(1 << pad_num_);
}

void GpioAvr::Clear(void) {
    if (gpio_driver::GPIO_OUTPUT == direction_)
        port_ &= ~(1 << pad_num_);
    else if (gpio_driver::GPIO_INPUT == direction_)
        ddr_ |= (1 << pad_num_);
}

void GpioAvr::SetDirection(const gpio_driver::GpioDirection direction) {

    direction_ = direction;

    if (gpio_driver::GPIO_OUTPUT == direction_)
        ddr_ |= (1 << pad_num_);
    else if (gpio_driver::GPIO_INPUT == direction_)
        ddr_ &= ~(1 << pad_num_);
}

void GpioAvr::SetPull(const gpio_driver::GpioPull pull) {

    pull_ = pull;

    if (gpio_driver::GPIO_NO_PULL == pull_)
        port_ &= ~(1 << pad_num_);
    else if (gpio_driver::GPIO_PULL_UP == pull_)
        port_ |= (1 << pad_num_);
}

void GpioAvr::Toggle(void) {

}

uint8_t GpioAvr::GetState(void) {
    return (pin_ & (1 << pad_num_)) != 0;
}

} /*namespace gpio_driver*/
