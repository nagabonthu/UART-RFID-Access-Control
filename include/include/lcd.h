#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include <lpc21xx.h>

/* LCD pin configuration */
#define LCD  0x0000FF00   // LCD data pins (P0.8 – P0.15)
#define RS   (1 << 6)     // Register Select pin (P0.6)
#define E    (1 << 7)     // Enable pin (P0.7)

/* LCD function declarations */
void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_string(unsigned char *str);
void delay_millisec(unsigned int ms);

#endif   // LCD_DRIVER_H
