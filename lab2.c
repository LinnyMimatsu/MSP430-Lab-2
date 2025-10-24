/*
Name: Dom
Description: Software switch debouncer using the MSP430 Micro-controller
*/

#include <msp430.h>

int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL &= 0b10110111; // Set select registers
  P1SEL2 &= 0b10110111;
  P1DIR |= BIT0; // Set P1.0 as OUTPUT
  P1DIR &= ~BIT3; // Set P1.3 as INPUT                           // Set P1.0 to output direction

    while(1)
    {
        if(!(P1IN & BIT3)) {

            __delay_cycles(10000); // prevents the code from being ran twice (debouncer)

            if(!(P1IN & BIT3)) { //if the button is still pressed turn on the led

              P1OUT ^= BIT0;

              while(!(P1IN & BIT3)) {  //the led remains on until the button is pressed again

              }

            }
        }
  }
}


