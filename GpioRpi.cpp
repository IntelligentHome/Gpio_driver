#include "GpioRpi.h"

namespace gpio_rpi {

GpioRpi::GpioRpi(
        const uint8_t                       pad_num,
        const gpio_driver::GpioDirection    direction,
        const gpio_driver::GpioPull         pull)
    :
        pad_num_(pad_num),
        direction_(direction),
        pull_(pull)
{
}

void GpioRpi::SetDirection(const gpio_driver::GpioDirection direction) {

}

void GpioRpi::SetPull(const gpio_driver::GpioPull pull) {

}

void GpioRpi::Set(void) {

}

void GpioRpi::Clear(void) {

}

void GpioRpi::Toggle(void) {

}

uint8_t GpioRpi::GetState(void) {
    return 0;
}

} /*namespace gpio_rpi*/
