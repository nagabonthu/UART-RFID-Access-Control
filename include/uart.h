#ifndef UART_DRIVER_H
#define UART_DRIVER_H

/* UART function declarations */
/* Initialize UART0 */
void uart_init(void);

/* Transmit one character through UART */
void uart_txd(unsigned char txdbyte);

/* Receive one character through UART */
unsigned char uart_rxd(void);

#endif   // UART_DRIVER_H
