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

//#define MP_ESP32_COLOR OK
#define ESP32_TSC_9488 OK
//#define ESP32_ILI9341 ERR don't use

/*
update  :   2020/9/4
name    :   MakePython ESP32 COLOR LCD
sigillum:   MP_ESP32_COLOR
wiki    :   https://www.makerfabs.com/wiki/index.php?title=MakePython_ESP32_Color_LCD
module  :   
            (1) 1.3inch TFT ST7789 driver

*/
#ifdef MP_ESP32_COLOR

//I2C
#define MP_ESP32_COLOR_I2C_SDA 4
#define MP_ESP32_COLOR_I2C_SCL 5

//SPI
#define MP_ESP32_COLOR_HSPI_MOSI 13
#define MP_ESP32_COLOR_HSPI_MISO 12
#define MP_ESP32_COLOR_HSPI_SCK 14
#define MP_ESP32_COLOR_HSPI_CS 15

//ST7789
#define MP_ESP32_COLOR_LCD_MOSI MP_ESP32_COLOR_HSPI_MOSI
#define MP_ESP32_COLOR_LCD_MISO MP_ESP32_COLOR_HSPI_MISO
#define MP_ESP32_COLOR_LCD_SCK MP_ESP32_COLOR_HSPI_SCK

#define MP_ESP32_COLOR_LCD_CS 15

#define MP_ESP32_COLOR_LCD_RST 21
#define MP_ESP32_COLOR_LCD_DC 22
#define MP_ESP32_COLOR_LCD_BL -1 //5

#define MP_ESP32_COLOR_LCD_WIDTH 240
#define MP_ESP32_COLOR_LCD_HEIGHT 240
#define MP_ESP32_COLOR_LCD_SPI_HOST HSPI_HOST

#endif

/*
update  :   2020/9/4
name    :   ESP32 Touch Screen Camera With 9488
sigillum:   ESP32_TSC_9488 
wiki    :   
module  :   
            (1) 3.5inch TFT ILI9488 driver
            (2) SDcard Reader
            (3) I2C Touch Screen(NS2009 or Ft6236)
            (4) OV2640 Camera
*/

#ifdef ESP32_TSC_9488

//I2C
#define ESP32_TSC_9488_I2C_SDA 26
#define ESP32_TSC_9488_I2C_SCL 27

//SPI
#define ESP32_TSC_9488_HSPI_MOSI 13
#define ESP32_TSC_9488_HSPI_MISO 12
#define ESP32_TSC_9488_HSPI_SCK 14
#define ESP32_TSC_9488_HSPI_CS 15

//ILI9488
#define ESP32_TSC_9488_LCD_MOSI ESP32_TSC_9488_HSPI_MOSI
#define ESP32_TSC_9488_LCD_MISO ESP32_TSC_9488_HSPI_MISO
#define ESP32_TSC_9488_LCD_SCK ESP32_TSC_9488_HSPI_SCK

#define ESP32_TSC_9488_LCD_CS 15

#define ESP32_TSC_9488_LCD_RST 26
#define ESP32_TSC_9488_LCD_DC 33
#define ESP32_TSC_9488_LCD_BL -1

#define ESP32_TSC_9488_LCD_WIDTH 320
#define ESP32_TSC_9488_LCD_HEIGHT 480
#define ESP32_TSC_9488_LCD_SPI_HOST HSPI_HOST

//SDcard
#define ESP32_TSC_9488_SD_MOSI ESP32_TSC_9488_HSPI_MOSI
#define ESP32_TSC_9488_SD_MISO ESP32_TSC_9488_HSPI_MISO
#define ESP32_TSC_9488_SD_SCK ESP32_TSC_9488_HSPI_SCK

#define ESP32_TSC_9488_SD_CS 4

#endif

#ifdef ESP32_ILI9341

#define LCD_MOSI 13
#define LCD_MISO 12
#define LCD_SCK 14
#define LCD_CS 18
#define LCD_RST 21
#define LCD_DC 22
#define LCD_BL 19 //5

#define LCD_WIDTH 240
#define LCD_HEIGHT 240
#define LCD_SPI_HOST VSPI_HOST

#endif