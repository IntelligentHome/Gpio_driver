#pragma once

#include "IGpioDriver.h"

namespace gpio_rpi {

class GpioRpi : public gpio_driver::IGpio {

public:
    GpioRpi(
        const uint8_t                       pad_num,
        const gpio_driver::GpioDirection    direction,
        const gpio_driver::GpioPull         pull);

    virtual void    SetDirection(const gpio_driver::GpioDirection direction);
    virtual void    SetPull(const gpio_driver::GpioPull pull);
    virtual void    Set(void);
    virtual void    Clear(void);
    virtual void    Toggle(void);
    virtual uint8_t GetState(void);

private:

    static volatile unsigned    *gpio_;
    static uint8_t              is_memory_mapped_;
    uint8_t                     pad_num_;
    gpio_driver::GpioDirection  direction_;
    gpio_driver::GpioPull       pull_;

    void MapGpioMemory(void);
};

} /*namespace gpio_rpi*/
