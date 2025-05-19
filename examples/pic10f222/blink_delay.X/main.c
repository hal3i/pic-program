#include <xc.h>

#pragma config IOSCFS = 4MHZ
#pragma config MCPU = OFF
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config MCLRE = ON

#define _XTAL_FREQ 4000000

void main(void)
{
    ADCON0 = 0x0C;
    TRISGPIO = 0x00;
    OPTION = 0xDF;
    
    while (1) {
        GP2 = !GP2;
        __delay_ms(500);
    }
}
