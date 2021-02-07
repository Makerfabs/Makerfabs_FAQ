# Makerfabs FAQ

```c++
/*
Version:		V4.0
Author:			Vincent
Create Date:	2020/7/21
Update Date:	2020/9/12
Note：
2021/2/7 V4.0 : Change Arduino ESP 32 :Add a general WIFI set funtion.
2020/9/12 v3.0: Split the original documentation into different folders.
2020/9/8  V2.1: Add ESP32 example.
2020/9/4  V2.0: Add pins define for easy use.
2020/7/23 V1.1: Added maduino and Makepython methods for downloading programs.

*/
```

[toc]

# Overview

This document shows how to use Makerfabs products.

Answer frequently asked questions.

Provide fast - developing sample and pin library maintenance.

# How To Use?

Makerfabs has three  main product lines :
- ESP32-based "MakePython" serial.
- ESP32 serial.
- Arduino-based "Maduino" serial.

**It is used in different ways according to different serial products.** The use of the development board is described in detail in three folders :

- **/Arduino_Maduino** : Based on traditional Arduino board like Arduino Pro Mini or Arduino Zero.
- **/Arduino_ESP32** : Develop ESP32 with the Arduino IDE.
- **/MakePython** : Develop ESP32 with MakePython .

These folders explain how to do code burning for different modules, the simple configuration of the IDE. 

It also explains some development points caused by hardware inconsistencies, such as Pin-Settings.



# GPIO/PINS

Some modules have modified the default IO port due to wiring or onboard components. For example, I2C and SPI interfaces are different from standard Arduino and ESP32.

In file "/Makerfabs_FAQ/pins_define/makerfabs_pin.h" support pins define. Use a copy of the project file under the reference file. And uncomment the board you are using.

```c++
//BOARD

#define MP_ESP32 OK
//#define MP_ESP32_COLOR OK
//#define ESP32_TSC_9488 OK
//#define ESP32_ILI9341 ERR don't use

//SHIELD
#define MP_AUDIO OK

//******************************************************************************

/*
update  :   2020/9/8
name    :   MakePython ESP32 SSD1306
sigillum:   MP_ESP32_COLOR
wiki    :   https://www.makerfabs.com/wiki/index.php?title=MakePython_ESP32
module  :   
            (1) 1.3inch OLED SSD1306

*/
#ifdef MP_ESP32

#define MP_ESP32_FLASH_BUTTON 0

//I2C
#define MP_ESP32_I2C_SDA 4
#define MP_ESP32_I2C_SCL 5
```
