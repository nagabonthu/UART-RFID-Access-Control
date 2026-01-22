# UART RFID Access Control System

## Description
A compact embedded access-control system that reads RFID tags over a UART interface and grants or denies access by driving a DC servo motor. 
Firmware parses UIDs from the RFID reader, checks them against an authorized list, and logs access attempts over serial.

## Software
- Keil uVision (C firmware)  
- Serial terminal for UART debugging (via RS-232)

## Hardware Components
- LPC2129 development board  
- EM-18 UART RFID reader (reads tag UIDs)  
- 16x2 alphanumeric LCD (displays "Access Granted"/"Access Denied")  
- DC servo motor (rotates when access granted)  
- RS-232 cable (used to verify UART via a serial terminal)  
- Power supply, connectors, and passive components

## Working Principle
On power-up, the LPC2129 microcontroller initializes the UART interface, LCD display, and servo motor control, while loading the list of authorized UIDs into memory.
When an RFID tag is presented, the EM-18 reader transmits its UID over UART. The firmware parses the incoming UID, filters out duplicate reads, and compares it against the stored authorization list. 

If the UID is valid, the servo motor rotates to unlock and the LCD displays **"Access Granted"**. If the UID is not recognized, the LCD shows **"Access Denied"**. Each access attempt is logged through the serial interface or persistent storage for monitoring. After a short timeout, the servo automatically returns to the locked position, and the system resumes listening for new tags, ensuring continuous and reliable operation.

## Skills Demonstrated

- Embedded C programming (bare-metal firmware)
- UART protocol implementation
- LCD and servo motor interfacing
- UID parsing and authorization logic
- Debugging and validation using Keil µVision
