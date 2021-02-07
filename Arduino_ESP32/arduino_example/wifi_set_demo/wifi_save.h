/*

Author  : Vincent
Create  : 2021/2/5

if ESP32开机检测SSID == NULL：
    ESP32通过AP模式，访问192.168.4.1进行修改，获得SSID和PASSWORD
    通过NVS存储到FLASH中
    重启
else：
    根据FLASH的SSID和PASSWORD连接wifi
    
while 重启五秒内 && 重置按键被按下 ：
    将NVS设置为NULL
    重启

用户程序()

*/


#include <Arduino.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"


#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define SSID_LENGTH 40

#define WIFI_SET_PIN 21

int record_rst_time();
void nvs_test();
void record_wifi(char *ssid, char *password);
void check_wifi(char *ssid, char *password);

void ap_init();
int wifi_config_server();
void set_wifi_from_url(String get_url);
int wifi_set_main();