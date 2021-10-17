#include "mm.h" 
#define LOCAL_CONTROL   0xff800000
#define LOCAL_PRESCALER 0xff800008
#define OSC_FREQ        0x337f980//54000000
#define MAIN_STACK      0x400000
.section ".text.boot"

.globl _start
_start:
    //Setup
    ldr     x0, =LOCAL_CONTROL   // Sort out the timer
    str     wzr, [x0]
    mov     w1, 0x80000000
    str     w1, [x0, #(LOCAL_PRESCALER - LOCAL_CONTROL)]
    msr    sctlr_el1, x0  
    ldr     x0, =OSC_FREQ
    msr     cntfrq_el0, x0
    msr     cntvoff_el2, xzr

    mrs x1, mpidr_el1
    and x1, x1, #0xFF
    cbz x1, master
    b proc_hang

master:
    adr x0, bss_begin
    adr x1, bss_end
    sub x1, x1, x0
    bl memzero

    mov sp, #LOW_MEMORY
    bl kernel_main
    b  proc_hang

proc_hang:
    wfe
    b proc_hang
