//#include "mbed.h"

//DigitalOut led1(LED1);

#include "LPC17xx.h"



int main() {

  SystemInit();  


  LPC_PINCON->PINSEL3 = 0x000000;
  LPC_GPIO1->FIODIR = 0xffffffff;


  LPC_GPIO1->FIOSET = 0xffffffff;
  
    return 0;
}

