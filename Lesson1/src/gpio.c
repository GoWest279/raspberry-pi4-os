#include "gpio.h"
#include "utils.h"

void gpio_pin_set_func(u8 pinNumber, GpioFunc func) {
    u8 bitStart = (pinNumber * 3) % 30;
    u8 reg = pinNumber / 10;
///////////////////////////////////////////////////////////////////////////////
    // get the function of gpio pin
    u32 selector = REGS_GPIO->func_select[reg]; //get the function of the pin
    selector &= ~(7 << bitStart);   // clear the function first
    selector |= (func << bitStart); // set the function bit in local variable
    // write the function to gpio
    REGS_GPIO->func_select[reg] = selector;
}

void gpio_pin_enable(u8 pinNumber) {
    REGS_GPIO->pupd_enable = 0;
    delay(150);
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 1 << (pinNumber % 32);
    delay(150);
    REGS_GPIO->pupd_enable = 0;
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 0;
}
