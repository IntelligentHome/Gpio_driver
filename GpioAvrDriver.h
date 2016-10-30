
#pragma once

#include "IGpioDriver.h"

namespace gpio_avr_driver {

class GpioAvr : public gpio_driver::IGpio {

public:
    GpioAvr(
        volatile uint8_t *pddr,
        volatile uint8_t *pport,
        uint8_t           pin);

    virtual void    Set(void);
    virtual void    Clear(void);
    virtual void    Toggle(void);
    virtual uint8_t GetState(void);

private:

    volatile uint8_t	*pddr_;
    volatile uint8_t	*pport_;
    uint8_t	            pin_;
};

} /*namespace gpio_avr_driver*/
