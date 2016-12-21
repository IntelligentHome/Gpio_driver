#include "GpioRpi.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define BCM2708_PERI_BASE        0x20000000
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000)

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)

#define INP_GPIO(gpio_map, g) *((gpio_map)+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(gpio_map, g) *((gpio_map)+((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(gpio_map ,a) *((gpio_map)+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET(gpio_map) *((gpio_map)+7)
#define GPIO_CLR(gpio_map) *((gpio_map)+10)

#define GET_GPIO(gpio_map, g) (*((gpio_map)+13)&(1<<g))

#define GPIO_FULL(gpio_map) *((gpio_map)+37)
#define GPIO_PULLCLK0(gpio_map) *((gpio_map)+38)

namespace gpio_rpi {

volatile unsigned *GpioRpi::gpio_ = 0;
uint8_t  GpioRpi::is_memory_mapped_ = 0;

GpioRpi::GpioRpi(
        const uint8_t                       pad_num,
        const gpio_driver::GpioDirection    direction,
        const gpio_driver::GpioPull         pull)
    :
        pad_num_(pad_num),
        direction_(direction),
        pull_(pull)
{
    if (!is_memory_mapped_)
        MapGpioMemory();

    INP_GPIO(this->gpio_, this->pad_num_);

    if (gpio_driver::GPIO_OUTPUT == this->direction_)
        OUT_GPIO(this->gpio_, this->pad_num_);

    this->Set();
}

void GpioRpi::SetDirection(const gpio_driver::GpioDirection direction) {

    this->direction_ = direction;

    if (gpio_driver::GPIO_OUTPUT == this->direction_)
        OUT_GPIO(this->gpio_, this->pad_num_);
    else if (gpio_driver::GPIO_INPUT == this->direction_)
        INP_GPIO(this->gpio_, this->pad_num_);
}

void GpioRpi::SetPull(const gpio_driver::GpioPull pull) {

}

void GpioRpi::Set(void) {

    if (gpio_driver::GPIO_OUTPUT == this->direction_)
        GPIO_SET(this->gpio_) = 1 << this->pad_num_;
    else if (gpio_driver::GPIO_INPUT == this->direction_)
        INP_GPIO(this->gpio_, this->pad_num_);
}

void GpioRpi::Clear(void) {

    if (gpio_driver::GPIO_OUTPUT == this->direction_)
        GPIO_CLR(this->gpio_) = 1 << this->pad_num_;
    else if (gpio_driver::GPIO_INPUT == this->direction_)
        OUT_GPIO(this->gpio_, this->pad_num_);
}

void GpioRpi::Toggle(void) {

}

uint8_t GpioRpi::GetState(void) {
    return GET_GPIO(this->gpio_, this->pad_num_) != 0;
}

void GpioRpi::MapGpioMemory(void) {

    int mem_fd;
    void *gpio_map;

    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC) ) < 0) {
        printf("can't open /dev/mem \n");
        return;
    }

    gpio_map = mmap(
            NULL,
            BLOCK_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            mem_fd,
            GPIO_BASE);

    close(mem_fd);

    if (gpio_map == MAP_FAILED) {
        printf("mmap error %d\n", (int)gpio_map);
        return;
    }

    this->gpio_ = (volatile unsigned *)gpio_map;
    this->is_memory_mapped_ = 1;
}

} /*namespace gpio_rpi*/
