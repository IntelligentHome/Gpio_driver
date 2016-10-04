
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
}


void GpioAvr::Set(void) {

}

void GpioAvr::Clear(void) {

}

void GpioAvr::Toggle(void) {

}

uint8_t GpioAvr::GetState(void) {
    return 0;
}

} /*namespace gpio_driver*/
