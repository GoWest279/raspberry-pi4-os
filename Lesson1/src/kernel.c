#include "common.h"
#include "mini_uart.h"
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
int itoa(u32 res, char *msg){
    uart_send_string(msg);
    char digit[10] = "0123456789";
    char s_res[32];
    int len = 31;
    do{ //Move back, inserting digits as u go
         s_res[len] = digit[res%10];
         res = res/10;
         len--;
    }while(res);
    for(int jj = len+1; jj <32; jj++)
        uart_send(s_res[jj]);
    uart_send_string("\n"); 
    return 1;
}
void test_func(int run) {
    int n = 2056;
    u32 res = 0;
    u32 timer_h0 = get32(0xFe003008);
    u32 timer_l0 = get32(0xFe003004);
    for(int ii = 0 ; ii < n; ii++)
        res += ii; 
    u32 timer_l1 = get32(0xFe003004);
    u32 timer_h1 = get32(0xFe003008);


    itoa(res, "Results:");
    itoa(timer_l0, "Timer low start:");    
    itoa(timer_h0, "Timer high start:");    
    itoa(timer_l1, "Timer low end:");    
    itoa(timer_h1, "Timer high end:");  
    itoa(timer_l1 - timer_l0, "Execution time:");

}

void kernel_main() {
    uart_init();
    uart_send_string("Rasperry UART initialize done\n");
    //char s_res[32];
    //char s_time[32];
#if RPI_VERSION == 3
    uart_send_string("\tBoard: Raspberry PI 3\n");
#endif

#if RPI_VERSION == 4
    uart_send_string("\tBoard: Raspberry PI 4\n");
#endif

    //uart_send_string("\n\nDone1\n");
    for(int ii =0; ii < 20; ii++) {
        test_func(ii);
    } 
    
    //uart_send_string("\ttestcfvfdvdf\n");

    
    while(1) {
        uart_send(uart_recv());
    }
}
