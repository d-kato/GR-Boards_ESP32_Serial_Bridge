# GR-Boards_ESP32_Serial_Bridge
**Please see [here](README_JPN.md) for Japanese version.**  

This sample program shows how to bridge between ESP32(UART) and your PC(USB).  
You can utilize this sample program for Flash writing or ESP32 evaluation.  
GR-LYCHEE is equipped with ESP32 on the board.  
GR-PEACH can add ESP 32 by connecting ``GR-WIRELESS CAMERA Shield``.

# How to use
The following two items are stored in `docs\esp32-at_bin.zip`.  
- ``GR-LYCHEE_ESP32_Serial_Bridge.bin`` (for GR-LYCHEE)
- ``GR-PEACH_ESP32_Serial_Bridge.bin`` (for GR-PEACH)
- ``esp32-at`` (ESP32 F/W update data by AT command)

If you use the sample code as is, please unzip the file and copy ``GR-xxxxx_ESP32_Serial_Bridge.bin`` to your borad.  

### Serial setting
When you use ``GR-LYCHEE_ESP32_Serial_Bridge``, you need to connect your PC and ``MicroUSB Connector(RZ/A1 Ch.0)``.

![](docs/img/usb0_and_button.jpg)  

If your PC isn't Windows10, you need to install the specified driver from the below URL.  

https://os.mbed.com/handbook/USBSerial

Unfortunately, since that is "Unsigned driver", you cannot install as is depending on your Windows version. Since the setting method is different for each PC, please search with "Unsigned driver" keyword on the search site.

If you want to confirm the serial communication the terminal soft on your PC, please specify the below values.  

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
You can change ESP32 to the Flash writing mode by holding down `USER_BUTTON0` and push `RESET`. LED1 on the board lights during the write mode. In the flash writing mode, the LED1 lights up. To cancel the flash writing mode, please push `RESET` once more.  

###  How to Flash Download Tools
Using ``esp32-at(ESP32 F/W update data by AT command)`` as example, this section is shown how to the "Flash Download Tools V3.6.2.2" for Windows PC.  
Please download ``Flash Download Tools (ESP8266 & ESP32)`` in the below URL.

Espressif’s official Flash Download Tools:  
http://espressif.com/en/support/download/other-tools?keys=&field_type_tid%5B%5D=13


Please unzip `flash_download_tools_v3.6.2.2.zip`, and excute `ESPFlashDownloadTool_v3.6.2.2.exe`.

![](docs/img/esp32_tool_1.jpg)  
Note: Select *ESP32 DownloadTool*.

![](docs/img/esp32_tool_2.jpg)  

1. Specify the .bin files for writing.  
   Please specify the .bin files for writing as shown below if you change ESP32 F/W to ``esp32-at(ESP32 F/W update data by AT command)``.  
   - bootloader.bin (0x1000)    
   - partitions_at.bin (0x8000)    
   - phy_init_data.bin (0xF000)    
   - esp-at.bin (0x100000)    
   - at_customize.bin (0x20000)    
   - GattServiceExample.bin (0x21000)  

   Please don't forget the check on the left boxes.
2. Select *40MHz* in SPI SPEED column.  
3. Select *DIO* in SPI MODE column.  
4. Select *32Mbit* in FLASH SIZE column.  
5. Select COM port in COM column.  
   Please specify the port number that assigned to ``MicroUSB Connector(RZ/A1 Ch.0)`` .
6. Select *460800* in BAUD column.  
   please retry by the lower value if you faced the writing error.
7. Change to the Flash writing mode.  
   Please refer to the above section.   
   First, if you are running the terminal soft, please close the soft for release the COM port.  
   Second, please erase the unnecessary data on Flash by pushing "ERASE" button on tool. The green area that is displayed "IDLE" on tools will change "FINISH" when it finished.
8. Change to the Flash writing mode again.  
   Please start the writing by pushing "START" button on tool. The green area that is displayed "IDLE" on tools will change "FINISH" when it finished.
