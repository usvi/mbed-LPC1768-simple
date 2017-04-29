#include "LPC17xx.h"
#include "delay.h"

int main() {

  SystemInit();  

  // Pins to control the LEDs are in this order:
  // 

  LPC_PINCON->PINSEL3 = 0x000000;
  LPC_GPIO1->FIODIR = 0xffffffff;


  LPC_GPIO1->FIOSET = 0xffffffff;
  
    return 0;
}

