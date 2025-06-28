#include <xc.h>

#pragma config IOSCFS = 4MHZ
#pragma config MCPU = OFF
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config MCLRE = ON

#define LED GPIObits.GP2
#define OFF 0
#define ON  1

void main(void) {
    
    unsigned char count = 0;
    
    OPTION = 0xD7;
    TMR0 = 0x0;
    ADCON0bits.ANS0 = 0;
    ADCON0bits.ANS1 = 0;
    TRISGPIO = 0x0;
    
    while (1) {
        if (TMR0 < 156) {
            continue;
        }
        TMR0 = 0;
        
        if (count++ < 10) {
            continue;
        }
        count = 0;
        
        LED = (LED == ON) ? OFF : ON;
    }
    
    return;
}
