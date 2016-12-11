
#include "GpioAvrDriver.h"

namespace gpio_avr_driver {

GpioAvr::GpioAvr(
        volatile uint8_t& ddr,
        volatile uint8_t& port,
        uint8_t           pin)
        :
        ddr_(ddr),
        port_(port),
        pin_(pin)
{
    ddr_ |= (1 << pin_);
}


void GpioAvr::Set(void) {
    port_ |= (1 << pin_);
}

void GpioAvr::Clear(void) {
    port_ &= ~(1 << pin_);
}

void GpioAvr::Toggle(void) {

}

uint8_t GpioAvr::GetState(void) {
    return 0;
}

} /*namespace gpio_driver*/
