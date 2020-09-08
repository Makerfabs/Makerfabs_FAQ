/*
标题    : ESP32 样例
作者    : Vincent
创建    : 2020/9/8
修改    : 2020/9/8
笔记    : 
    1，创建一个包含所有常用协议初始化的demo，包含I2C，SPI等，便于快速开发。
    2，I2C屏幕的开机画面和简单显示。
    3，WiFi连接，并get请求一个简单的天气数据。
    完成4，板载按键控制。

备注    : 用于快速开发，仅包含板载功能。

*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "makerfabs_pin.h"

// SSD1306连接到的是硬件I2C上，在setup()部分初始化
Adafruit_SSD1306 display(MP_ESP32_SSD1306_WIDTH, MP_ESP32_SSD1306_HEIGHT, &Wire, MP_ESP32_SSD1306_RST);
Adafruit_SSD1306 *p_display = &display;

bool button_status = true;

void setup()
{
    //乐鑫ESP32均有一个RST和FLASH按键，FLASH为IO0
    pinMode(MP_ESP32_FLASH_BUTTON, INPUT);

    Serial.begin(115200);
    //I2C初始化，用于二次配置引脚。
    Wire.begin(MP_ESP32_I2C_SDA, MP_ESP32_I2C_SCL);
    //SSD1306初始化
    if (SSD1306_init(p_display))
        Serial.println("ERROR CODE:SSD1306 WRONG");
}

void loop()
{
    if (digitalRead(MP_ESP32_FLASH_BUTTON) == 0)
    {
        delay(40);
        if (digitalRead(MP_ESP32_FLASH_BUTTON) == 0)
        {
            button_status = !button_status;
            Serial.println(button_status);
            if (button_status)
            {
                display.fillScreen(SSD1306_BLACK);
            }
            else
            {
                display.fillScreen(SSD1306_WHITE);
            }
            display.display();
            while (digitalRead(MP_ESP32_FLASH_BUTTON) == 0)
                ;
        }
    }
    delay(200);
}

/*
    模块初始化函数：
        1，SSD1306
        2，WiFi
*/

//SSD1306初始化，电压选项,I2C地址设置
int SSD1306_init(Adafruit_SSD1306 * oled)
{
    //地址为0x3C，adafruit的驱动中为0x3D，可能因芯片厂家不同导致的。
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!oled->begin(SSD1306_SWITCHCAPVCC, MP_ESP32_SSD1306_I2C_ADDR))
    {
        return -1;
    }

    oled->clearDisplay();
    oled->display();
    return 0;
}