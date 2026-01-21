UART-Based RFID Access Control System

Description

This project implements an RFID-based access control system using UART communication on an ARM7 microcontroller. The RFID reader transmits a unique tag ID serially to the microcontroller. The received ID is validated against stored authorized IDs, and access is granted or denied accordingly.
The project demonstrates reliable serial communication, data parsing, and access control logic at the embedded firmware level.

Hardware Used
	•	LPC2129 (ARM7TDMI)
	•	RFID Reader (EM-18 Uart based)
	•	Keil µVision
	•	Embedded C

Key Features
	•	UART serial communication
	•	RFID tag ID reception and validation
	•	Access control logic (grant/deny)
	•	Bare-metal implementation (no OS)
	•	Register-level programming

Working

The RFID reader transmits the tag ID through the UART RX line. The microcontroller receives the data using UART registers and compares it with a predefined valid ID. If the ID matches, access is granted; otherwise, access is denied.

Skills Demonstrated

Embedded C, ARM7TDMI, UART, Bare-Metal Programming, Register-Level Programming, Debugging
