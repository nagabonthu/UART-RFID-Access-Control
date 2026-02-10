/* UART.c*/
#include "uart.h"

/* UART0 init: 8N1, 9600 baud (DLL=97 assumes PCLK ~ 15 MHz)
TXD0 -> P0.0, RXD0 -> P0.1 */
void uart_init(void)
{
	PINSEL0 |= 0x00000005; // Select UART0 function for P0.0 (TXD0) and P0.1 (RXD0)
	
	U0LCR=0x83;   // 8-bit, 1 stop, no parity, DLAB=1
	U0DLL=97;     // Baud rate divisor (LSB)
	U0DLM=0;      // Baud rate divisor (MSB)
	U0LCR=0x03;  // DLAB=0, lock baud rate, 8N1
}

/* Transmit 1 byte */
void uart_txd(unsigned char txdbyte)
{
	U0THR=txdbyte;             // Wait until THR empty (THRE=1)
	while(((U0LSR>>5)&1)==0); // Load data to transmit
}

/* Receive 1 byte */
unsigned char uart_rxd(void)
{
	while((U0LSR&1)==0);  // Wait until data ready (RDR=1)
	return U0RBR;         // Read received byte
}
