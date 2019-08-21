# GR-Boards_ESP32_Serial_Bridge
**Please see [here](README_JPN.md) for Japanese version.**  

This sample program shows how to bridge between ESP32(UART) and your PC(USB).  
You can utilize this sample program for Flash writing or ESP32 evaluation.  
GR-LYCHEE is equipped with ESP32 on the board.  
GR-PEACH can add ESP 32 by connecting ``GR-WIRELESS CAMERA Shield``.

# How to use
The following two items are stored in `docs\ESP32_firmware.zip`.  
- ``GR-LYCHEE_ESP32_Serial_Bridge.bin`` (for GR-LYCHEE)
- ``GR-PEACH_ESP32_Serial_Bridge.bin`` (for GR-PEACH)
- ``ESP32_firmware`` (ESP32 F/W update data by AT command)

If you use the sample code as is, please unzip the file and copy ``GR-xxxxx_ESP32_Serial_Bridge.bin`` to your borad.  

### Serial setting
When you use ``GR-LYCHEE_ESP32_Serial_Bridge``, you need to connect your PC and ``MicroUSB Connector(RZ/A1 Ch.0)``.

![](docs/img/usb0_and_button.jpg)  

If your PC isn't Windows10, you need to install the specified driver from the below URL.  

https://os.mbed.com/handbook/USBSerial

Unfortunately, since that is "Unsigned driver", you cannot install as is depending on your Windows version. Since the setting method is different for each PC, please search with "Unsigned driver" keyword on the search site.

If you want to confirm the serial communication the terminal software on your PC, please specify the below values.  

|            |        |
|:-----------|:-------|
| Baud rate | 115200 |
| Data     | 8bit   |
| Parity   | none   |
| Stop   | 1bit   |
| Flow control | none   |

### button
Pressing `USER_BUTTON0` resets ESP32.

### Change to the Flash writing mode
You can change ESP32 to the Flash writing mode by holding down `USER_BUTTON0` and connecting the USB cable. LED1 on the board lights during the write mode. In the flash writing mode, the LED1 lights up. To cancel the flash writing mode, please reconnect the USB cable again.  

### How to update ESP32 firmware
Write the following firmware in the ``docs/ESP32_firmware`` to your board:
- ``GR-LYCHEE_ESP32_Serial_Bridge.bin`` (for GR-LYCHEE)
- ``GR-PEACH_ESP32_Serial_Bridge.bin`` (for GR-PEACH)

Espressif’s official Flash Download Tools:  
http://espressif.com/en/support/download/other-tools?keys=&field_type_tid%5B%5D=13

![](docs/img/esp32_tool_1.jpg)  

![](docs/img/esp32_tool_2.png)  

The settings are as follows. If the COM port is already open in the terminal software, please close the terminal software.
* SPI SPEED : ``40MHz``
* SPI MODE : ``DIO``
* FLASH SIZE : ``32Mbit``
* COM : Set your board COM.
* BAUD : ``460800`` (If a write error occurs, try again with the smaller value.)  

The update file is in the ``docs\ESP32_firmware.zip``.

|Path                                       |offset  |
|:------------------------------------------|:-------|
|0x1000_bootloader.bin                      |0x1000  |
|0x20000_at_customize.bin                   |0x20000 |
|0x21000_ble_data.bin                       |0x21000 |
|0x24000_server_cert.bin                    |0x24000 |
|0x26000_server_key.bin                     |0x26000 |
|0x28000_server_ca.bin                      |0x28000 |
|0x2a000_client_cert.bin                    |0x2a000 |
|0x2c000_client_key.bin                     |0x2c000 |
|0x2e000_client_ca.bin                      |0x2e000 |
|0x30000_factory_param_lychee_and_peach.bin |0x30000 |
|0xf000_phy_init_data.bin                   |0xf000  |
|0x100000_esp-at.bin                        |0x100000|
|0x8000_partitions_at.bin                   |0x8000  |

Procedure:  
1. While holding down ``USER_BUTTON0``, connect the PC with ``MicroUSB connector Ch.0`` using a USB cable.  
2. Press the ``Erase`` button on the tool to erase the unwanted data on the flash. The green area labeled ``IDLE`` in the tool changes to ``FINISH`` when finished.  
3. Disconnect the USB cable and connect the USB cable while pressing ``USER_BUTTON0`` again.
4. Press the ``START`` button on the tool to start writing. The green area labeled ``IDLE`` in the tool changes to ``FINISH`` when finished.  
