# Makerfabs FAQ(unfinished)

```c++
/*
Version:		V1.0
Author:			Vincent
Create Date:	2020/7/21
Note：
*/
```

[toc]

# *Unfinished*

# Please have a look at [makerfabs](https://www.makerfabs.com/wiki/index.php?title=Main_Page)



# Overview

Makerfabs has two main product lines, the Makepython series based on ESP32 and the Arduino-based Maduino series.This FAQ mainly explains how to do code burning for different modules, the simple configuration of the IDE.It also explains some development points caused by hardware inconsistencies, such as pin Settings.



# Maduino

Maduino is arduino based modification, including Zero, Pro Mini, etc., most of which are 3.3V.Details are based on the Wiki interface.Support for Arduino IDE.

## Type

### Arduino Pro Mini

#### With Micro USB

Maduino Lora Radio (433M/868M)





#### Without micro USB

Lora Soil Moisture Sensor



### Arduino Zero

Maduino Zero A9G



## Connect

### With Micro USB

USB integrated CP2104 or other types of serial port chips, no additional converter, directly through the USB cable to connect the serial port.It is used in the same way as the standard Arduino.

![usb](md_pic/usb.png)

### Without Micro USB

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



## IDE Set





## Upload







# MakePython

MakePython主要为ESP32和ESP8266，支持用arduino IDE以c++开发，支持用 uPyCraft以micropython语言开发。



## Type

MakePython ESP32







## IDE Set





## Upload