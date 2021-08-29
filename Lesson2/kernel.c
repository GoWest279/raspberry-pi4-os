#include "io.h"
#include "fb.h"
//#include "terminal.h"
int x_oft =0;
int y_oft = 0;
int FONT_HEIGHT=8;
int FONT_WIDTH=8;
extern int extern_AUX_MU_IO_REG;
void main()
{
    uart_init();
    fb_init();

    // drawRect(150,150,400,400,0x03,0);
    // drawRect(300,300,350,350,0x2e,1);

    // drawCircle(960,540,250,0x0e,0);
    // drawCircle(960,540,50,0x13,1);

    // drawPixel(250,250,0x0e);

    // drawChar('O',500,500,0x05);
//    drawString(x_oft, y_oft,"Hello world!",0x0f);
    //y_oft += FONT_HEIGHT; 
    //uart_writeText("Hello Word!\n");
    char msg0 = 't';
    mmio_write(extern_AUX_MU_IO_REG, (unsigned int)msg0);
    //while(1) uart_update();

    //char msg0 = 't';
    //uart_send(extern_AUX_MU_IO_REG, msg0);
    // drawLine(100,500,350,700,0x0c);
    // char msg;
    // while (1){
    //     if(x_oft >= 1920) {
    //         x_oft = 0;
    //         y_oft += FONT_HEIGHT;
    //     }
    //     if(y_oft >= 1080) {
    //         y_oft = 0;
    //         x_oft = 0;
    //     }
    //     msg = uart_readByte();
    //     drawChar(msg,x_oft, y_oft, 0x0f);
    //     //uart_writeText(&msg);
    //     //uart_send(extern_AUX_MU_IO_REG, msg);
    //     if(msg=='\n' || msg == '\r') {
    //         x_oft = 0;
    //         y_oft += (FONT_HEIGHT + 2);

    //     }
    //     else{
    //         x_oft += (FONT_WIDTH + 1);
    //     }

    // }
}
