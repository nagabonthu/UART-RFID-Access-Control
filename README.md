# UART RFID Access Control System
## Overview
A compact embedded access-control system that reads RFID tags over a UART interface and grants or denies access by driving a DC servo motor. 
Firmware parses UIDs from the RFID reader, checks them against an authorized list, and logs access attempts over serial.
## Software Components
- Embedded C – bare-metal firmware development
- Keil µVision IDE – for compilation, debugging, and simulation
- Flash Magic – for programming LPC2129 via UART bootloader
- Serial terminal (via RS-232) – for UART debugging and monitoring
- GitHub – for version control and documentation
## Hardware Components
- LPC2129 ARM7TDMI development board (with inbuilt 12 MHz crystal oscillator)
- EM-18 RFID reader (UART interface, reads tag UIDs)
- 16x2 alphanumeric LCD (displays access status)
- DC servo motor (rotates to unlock when access granted)
- RS-232 cable (for UART debugging with serial terminal)
- Power supply, connectors, and passive components 
## Skills Demonstrated
- Embedded C programming (bare-metal firmware)
- UART protocol implementation
- LCD and servo motor interfacing
- UID parsing and authorization logic
- Debugging and validation using Keil µVision
## Working Principle
1. On power-up, the LPC2129 microcontroller initializes the UART interface, LCD display, and servo motor, and loads the list of authorized UIDs into memory.  
2. When an RFID tag is presented, the EM-18 reader transmits its UID over UART.  
3. The firmware parses the UID and compares it against the stored authorization list.  
4. If the UID is valid:  
   - Servo motor rotates to unlock  
   - LCD displays **"Access Granted"**  
5. If the UID is invalid:  
   - LCD displays **"Access Denied"**  
6. After a short timeout, the servo returns to the locked position and the system resumes listening for new tags.  
 

