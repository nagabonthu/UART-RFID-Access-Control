/* 
 * Project: UART Based Access Control System
 * Target : ARM7 LPC212 */
#include <lpc21xx.h>
#include <string.h>
#include "lcd.h"
#include "uart.h"

unsigned char arr[13];

int main()
{
    unsigned int i = 0;
    char ID[] = "0600672F612F";

    uart_init();     // Initialize UART for receiving data
    lcd_init();      // Initialize LCD hardware (done once)

    /* Clear LCD once at startup */
    lcd_cmd(0x01);               // Clear display
    lcd_cmd(0x80);               // Move cursor to first line
    lcd_string("Waiting...");    // Show system is ready

    while (1)
    {
        /* Receive 12 characters from UART (RFID ID) */
        while (i < 13)
        {
            if (i == 12)
            {
                arr[i] = '\0';   // End the received string
                i = 0;           // Reset index for next read
                break;
            }
            arr[i++] = uart_rxd();  // Read one byte from UART
        }

        /* Clear LCD before showing new message */
        lcd_cmd(0x01);           // Clear old message
        lcd_cmd(0x80);           // Set cursor to first line

        /* Compare received ID with stored ID */
        if (strcmp((char *)arr, ID) == 0)
        {
            lcd_string("Access Granted");  // Correct ID
        }
        else
        {
            lcd_string("Access Denied");   // Wrong ID
        }

        delay_millisec(2000);    // Keep message visible for 2 seconds

        /* Clear LCD and go back to waiting state */
        lcd_cmd(0x01);           // Clear display
        lcd_cmd(0x80);           // Cursor to first line
        lcd_string("Waiting...");// Ready for next ID
    }
}
