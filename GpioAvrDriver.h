
#pragma once

#include "IGpioDriver.h"

namespace gpio_avr_driver {

class GpioAvr : public gpio_driver::IGpio {

public:
    GpioAvr(
        volatile uint8_t&                   ddr,
        volatile uint8_t&                   port,
        volatile uint8_t&                   pin,
        uint8_t                             pad_num,
        const gpio_driver::GpioDirection    direction,
        const gpio_driver::GpioPull         pull);

    virtual void    SetDirection(const gpio_driver::GpioDirection direction);
    virtual void    SetPull(const gpio_driver::GpioPull pull);
    virtual void    Set(void);
    virtual void    Clear(void);
    virtual void    Toggle(void);
    virtual uint8_t GetState(void);

private:

    volatile uint8_t&           ddr_;
    volatile uint8_t&           port_;
    volatile uint8_t&           pin_;
    uint8_t                     pad_num_;
    gpio_driver::GpioDirection  direction_;
    gpio_driver::GpioPull       pull_;
};

} /*namespace gpio_avr_driver*/
