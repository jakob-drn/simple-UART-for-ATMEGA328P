/* U A R R T   D R I V E R   F O R   ATMEGA328P
 * 
 * Configured as follows:
 *      9600 BAUD (F_CPU=16MHz)
 *      8 Data-bits
 *      1 Stop-bit 
 *      no Parity
 *      RX+Interrupt & TX
 *
 *      null terminated string
 * */

#pragma once

void UART_init();
char UART_getc();
char UART_getce();
char UART_putc(char c);
void UART_puts(char* s);


