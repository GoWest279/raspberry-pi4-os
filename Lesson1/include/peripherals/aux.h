#pragma once

#include "common.h"

#include "peripherals/base.h"

struct AuxRegs {
    reg32 irq_status;
    reg32 enables;
    reg32 reserved[14];
    reg32 mu_io;
    reg32 mu_ier;//Mini UART Interrupt Enable
    reg32 mu_iir;
    reg32 mu_lcr;//Mini UART Line Control
    reg32 mu_mcr;//Mini UART Modem Control
    reg32 mu_lsr;
    reg32 mu_msr;
    reg32 mu_scratch;
    reg32 mu_control;//Mini UART Extra Control
    reg32 mu_status;
    reg32 mu_baud_rate;
};

#define REGS_AUX ((struct AuxRegs *)(PBASE + 0x00215000))
