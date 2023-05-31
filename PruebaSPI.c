#include<xc.h>
#define _XTAL_FREQ 1000000

#pragma config FOSC=INTOSC_EC
#pragma config WDT=OFF
#pragma config PBADEN=OFF

void main(void){
  TRISC7=0;
  TRISB1=0;
  TRISA5=0;
  LATA5=1;
  SSPSTAT=0b01000000;
  SSPCON1=0b00100000;
  __delay_ms(10);
  LATA5=0;
  SSPBUF=0b00000110;
  while(BF==0);
  LATA5=1;
  __delay_ms(4);
  while(1){
    LATA5=0;
    SSPBUF=0b00000010;
    while(BF==0);
    SSPBUF=0x1;
    while(BF==0);
    SSPBUF=0xAA;
    while(BF==0);
    LATA5=1;
    __delay_ms(1000);
  }
}

