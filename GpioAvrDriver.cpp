
#include "GpioAvrDriver.h"

namespace gpio_avr_driver {

GpioAvr::GpioAvr(
        volatile uint8_t *pddr,
        volatile uint8_t *pport,
        uint8_t           pin)
        :
        pddr_(pddr),
        pport_(pport),
        pin_(pin)
{
    *pddr_ |= (1 << pin_);
}


void GpioAvr::Set(void) {
    *pport_ |= (1 << pin_);
}

void GpioAvr::Clear(void) {
    *pport_ &= ~(1 << pin_);
}

void GpioAvr::Toggle(void) {

}

uint8_t GpioAvr::GetState(void) {
    return 0;
}

} /*namespace gpio_driver*/
