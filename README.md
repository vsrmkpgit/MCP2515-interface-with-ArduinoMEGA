# MCP2515-interface-with-ArduinoMEGA
The MCP2515 CAN Bus Controller is a simple Module that supports CAN Protocol version 2.0B and can be used for communication at 1Mbps. This particular module is based on MCP2515 CAN Controller IC and TJA1050 CAN Transceiver IC. The MCP2515 IC is a standalone CAN Controller and has integrated SPI Interface for communication with microcontrollers.

In order to setup a complete communication system, you will need two CAN Bus Module. One acts as a transmitter and the other as a receiver. Now for the communication between this transmitter and receiver, connect CANH and CANL pins of each MCP2515 Module.

The CAN Controller IC facilitates SPI Communication Protocol for interfacing with any Microcontroller. Hence, connect the SPI Pin i.e. SCK, MOSI (SI), MISO (SO) and CS of the MCP2515 Module to corresponding SPI Pins of Arduino. In Arduino MEGA, Pin 50- MISO, 51- MOSI, 52- SCK, 53- CS. We can also use ICSP(In-circuit serial programming) pins on the MEGA board for SPI communication.

To the Transmitter side, Connect a Variable pot to Analog Pin A0 whose values are to be transmitted via CAN. Read the Pot values in a loop and send these values to another controller via CAN as a message and also print the values on the serial monitor to know the pot value which has been sent.

To the Receiver side, if the received CAN message ID matches with the transmitted Message ID, the CAN message is stored in a variable and that variable is printed on the connected liquid crystal I2C 16x2 LCD using SDA, SCL pins on the MEGA board as well as Serial Monitor.
