#include "LPC17xx.h"
#include "delay.h"

int main() {

  SystemInit();  

  // Pins to control the LEDs are in this order from PCB led end to right and up:
  // 7, 9, 10, 12
  // These map to following LQFP100 pins: 32, 34, 35, 37
  // And in datasheets these pins are P1[18], P1[20], P1[21], P1[23]
  // Remember to watch specificly from section describin LPC1768 pins!
  
  // Pin operation mode needs to be set next. Operation should be DIO,
  // which means writing control bit sequence 00 to corresponding control
  // registry value positions.
  // In datasheets the mode of all these pins is controlled by PINSEL3
  // Control bits are: 5:4, 9:8, 11:10 and 15:14

  // Pin 32/P1[18] mode with bits 5:4 to zero
  LPC_PINCON->PINSEL3 &= ~((1 << 5) | (1 << 4));
  // Pin 34/P1[20] mode with bits 9:8 to zero
  LPC_PINCON->PINSEL3 &= ~((1 << 9) | (1 << 8));
  // Pin 35/P1[21] mode with bits 11:10 to zero
  LPC_PINCON->PINSEL3 &= ~((1 << 11) | (1 << 10));
  // Pin 37/P1[23] mode with bits 15:14 to zero
  LPC_PINCON->PINSEL3 &= ~((1 << 15) | (1 << 14));

  // Next we set DIO ping directions to output.
  // As all pins start with P1, they are controlled by LPC_GPIO1 register

  // In datasheets pin 32/P1[18] direction is controlled with FIOxDIR2 bit 2
  LPC_GPIO1->FIODIR2 |= (1 << 2);
  // In datasheets pin 34/P1[20] direction is controlled with FIOxDIR2 bit 4
  LPC_GPIO1->FIODIR2 |= (1 << 4);
  // In datasheets pin 35/P1[21] direction is controlled with FIOxDIR2 bit 5
  LPC_GPIO1->FIODIR2 |= (1 << 5);
  // In datasheets pin 37/P1[23] direction is controlled with FIOxDIR2 bit 7
  LPC_GPIO1->FIODIR2 |= (1 << 7);

  


  //LPC_GPIO1->FIODIR = 0xffffffff;

  LPC_GPIO1->FIOSET = 0xffffffff;
  
    return 0;
}

