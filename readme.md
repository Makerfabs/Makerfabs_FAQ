# Makerfabs FAQ

```c++
/*
Version:		V2.1
Author:			Vincent
Create Date:	2020/7/21
Note：
2020/7/23 V1.1: Added maduino and Makepython methods for downloading programs.
2020/9/4  V2.0: Add pins define for easy use.
2020/9/8  V2.1: Add ESP32 example.
*/
```

[toc]


# Overview

Makerfabs has two main product lines, the Makepython series based on ESP32 and the Arduino-based Maduino series.This FAQ mainly explains how to do code burning for different modules, the simple configuration of the IDE.It also explains some development points caused by hardware inconsistencies, such as pin Settings.



# Maduino

![maduino](md_pic/Maduino.jpg)

Maduino is arduino based modification, including Zero, Pro Mini, etc., most of which are 3.3V. See the Wiki for more information. Support for Arduino IDE.

## 1. Type

| Name                           | Type             | Connect Type |
| ------------------------------ | ---------------- | ------------ |
| Maduino Lora Radio (433M/868M) | Arduino Pro Mini | MicroUSB     |
| Lora Soil Moisture Sensor      | Arduino Pro Mini | UART         |
| Maduino Zero A9G               | Arduino Zero     | MicroUSB     |
|                                |                  |              |



### 1.1 With Micro USB

USB integrated CP2104 or other types of serial port chips, no additional converter, directly through the USB cable to connect the serial port.It is used in the same way as the standard Arduino.

![usb](md_pic/usb.png)

### 1.2 With UART

There is no USB socket or integrated serial port chip on some modules.But there are serial ports: VCC, GND, RX, TX, DTR.There are two ways to connect a serial port.

#### Makerfabs CP2104 USB2UART

Product link : [CP2104 USB2UART](https://www.makerfabs.com/cp2104-usb-to-serial-converter.html)

![cp2104](md_pic/cp2104.png)

This CP2104 USB to Serial Converter is super tiny, a highly-integrated USB-to-UART Bridge Controller providing a simple solution for updating and programming.

The serial port module has the same pin position as the makerfabs module with no USB port.So just plug it into the hole.

![cp2104](md_pic/cp2104-2.png)

The usage of usb cable is the same after that.

#### CP2102 MODULES USB TO TTL

There are many common usb serial port modules on the market, which are basically connected in a common way.

| Makerfabs | USB To TTL |
| --------- | ---------- |
| VCC       | 3.3V       |
| GND       | GND        |
| RX        | TXD        |
| TX        | RXD        |

![ttl](md_pic/ttl.png)



## 2.Arduino IDE

### 2.1 Arduino Pro Mini

Arduino Pro Mini is an Arduino IDE supported by default.

- Select "Tools", select "Board" Arduino Pro or Pro min, select processor ATmega328p 3.3V 8MHz, and select corresponding serial port.

![pro](md_pic/pro.png)

- If there is no port to display, you need to download the USB driver. [CP210x driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

### 2.2 Arduino Zero

Arduino Zero is the development board of Arduino ARM series.Additional installation is required.

- Open Boards Manager as the screen snap below. And search “arduino zero” and install it.

![zero](md_pic/zero.png)

- Select "Tools", select board -> Arduino/Genuino Zero(Native USB Port).



![zero-2](md_pic/zero-2.png)

- If there is no port to display, you need to download the USB driver. [CP210x driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

## 3.Arduino Upload

Just like normal arduino. 

- Push Upload.

![arduino_upload](md_pic/arduino_upload.png)



## 4.Install the library

### 4.1 Arduino Manager

Arduino has its own library manager, and for some authenticated third-party libraries, it can be searched in the library manager.Click install.Common libraries such as SSD1306.

- Select "Tools", select "Manage Libraries"

- Search libraries which you nedd.

![manage_library](md_pic/library.png)

### 4.2 Zip Library

Some of the libraries downloaded manually or provided with the project will come with a ZIP archive.You can add it through the capabilities of the Arduino IDE's import ZIP library.

- Select "Skecth", select "Include Library", select "Add ZIP library..."

![zip](md_pic/zip_lib.png)

Or you can just unzip and copy the folder to the Arduino library folder.Usually the location is "C:\Users\yourname\Documents\Arduino\libraries".

![zip](md_pic/zip_lib-2.png)

# MakePython

![makepython](md_pic/makepython.png)

MakePython is mainly for ESP32 and ESP8266, which supports development in c++ with arduino IDE, and development in micropython with uPyCraft.

ESP32 also supports the Arduino IDE, please refer to ESP32 development environment setup under Arduino.



## 1. Type

| Name                       | Type         | Module  |
| -------------------------- | ------------ | ------- |
| MakePython ESP32           | ESP32        | SSD1306 |
| MakePython ESP32 Color LCD | ESP32        | ST7789  |
| MakePython ESP8266         | ESP8266      | SSD1306 |
| MakePython Lora            | ESP32 Shield | SX1278  |





## 2. Arduino IDE

Arduino is supported in Espressif products like ESP32.Manual installation is required.The use method is basically the same as that of Arduino. Please refer to the setting of Maduino for details.

- Select "File", select "preferences".

![arduino_esp32](md_pic/arduino_esp32.png)

- Add  url : 

```c++
https://dl.espressif.com/dl/package_esp32_index.json
```

- Open Boards Manager as the screen snap below. And search “esp32” and install it.Just like arudino zero.



## 3. uPyCraft IDE 

- Click this link to download uPyCraft IDE for Windows: : [uPyCraft_win](https://randomnerdtutorials.com/uPyCraftWindows)
- Double-click to open uPyCraft. 

![uPyCraft](md_pic/upy.png)

- Select "Tools",select "board", select "esp32" or "esp8266".It depends on the model you're using.

![upy1](md_pic/upy1.png)

- Select "Tools",select "InitConfig" to reset workspace address.
- Click workSpace, and select the project folder.

![upy2](md_pic/upy2.png)

- The program files must be placed in the workSpace folder of the project folder.
- Select "File", select "Reflush Directroy".

![upy2](md_pic/upy3.png)



- The Python files in the folder will be displayed on the left.

![upy2](md_pic/upy4.png)



## 4. UPyCraft Upload

- Connect MakePython ESP32 to your PC, open uPyCraft, and select connect to the serial port.

![upy2](md_pic/upy5.png)

- If there is no port to display, you need to download the USB driver. [CP210x driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
- Get a MicroPython fireware from [micropython.org](http://www.micropython.org/download/esp32/)
- Firmware will be prompted if it has not been burned before or for other reasons.Board selects ESP32, BURN_addr selects 0x1000, Erase_Flash selects Yes, com selects the port number.Firmware Choose Users, click Choose to Choose ESP32-IDF3-20190125-v1.10.bin.（Or other esp32 micropython bin）

![burn_esp32](md_pic/burn_firmware.png)

- If you burn the firmware, you need to click connect again.

- Download all python programs in workSpace to ESP32.

![upy7](md_pic/upy7.png)

- You can also hold down the left mouse button and drag files from the workSpace into Device.

![upy2](md_pic/upy6.png)

- Press the RST button on ESP32 to reset the development board.

# Fast Devolop

## GPIO/PINS

Some modules have modified the default IO port due to wiring or onboard components.For example, I2C and SPI interfaces are different from standard Arduino and ESP32.

In file "/Makerfabs_FAQ/pins_define/makerfabs_pin.h" support pins define.

```c++
/*
-------------------------------------------------
titile  :   Makerfabs IO define
author  :   Vincent
create  :   2020/9/4
version :   1.0
update  :   2020/9/4

Note:

1.
For easy use ESP32 GPIO,define SPI, I2C, and LCD, SDcard pins.
And define some parameters, such as screen size.

2.
Sigillum:
MP = MakePython
MP_ESP32_COLOR = MakePython ESP32 Color LCD (ST7789)

TSC = Touch Screen Camera
ESP32_TSC_9488 = ESP32 Touch Screen Camera With ILI9488

3.
//#define ESP32_COLOR_7789 OK
"Ok" means tested and ready to use
Don't use "ERR" or "TEST"

4.
For the motherboard combination expansion board.
This is to be determined and may be modified.
A more prudent approach is to copy the pin value directly.

-------------------------------------------------
Support List:

    (1)MakePython:
        MakePython ESP32 COLOR LCD

    (2)Touch Screen Camera:
        ESP32 Touch Screen Camera With 9488

-------------------------------------------------
*/
```

## Example

In file "/Makerfabs_FAQ/arduino_example/" support fast develop example.