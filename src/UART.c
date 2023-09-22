#include "UART.h"

#include <avr/io.h>
#include <avr/interrupt.h> 

ISR(USART_RX_vect)
{
    UART_getce();
}

void UART_init()
{
    //UBRR0H=0;
    UBRR0L=103;                                 // 9600 BAUD
    UCSR0B|=(1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);  // RX+I & TX 
    UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);            // 8n1
}
char UART_getc()
{
    while(!(UCSR0A&(1<<RXC0)));
    return UDR0;
}
char UART_getce()
{
    UART_putc(UART_getc());
    return 0;
}
char UART_putc(char c)
{
    while(!(UCSR0A&(1<<UDRE0)));
    UDR0=c;
    return c;
}
void UART_puts(char* s)
{
    while(*s) UART_putc(*s++);
}
