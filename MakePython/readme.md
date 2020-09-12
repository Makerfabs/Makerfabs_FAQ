# MakePython Usage

```c++
/*
Version:		V1.0
Author:			Vincent
Create Date:	2020/9/12
Update Date:	2020/9/12
Note：
*/
```

[toc]

# Overview

Described how to develop ESP32 under the uPyCraft IDE. For MakePython and ESP32 serial.

Includes: 

- How to use uPyCraft
- Upload codes



# uPyCraft IDE 

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



# UPyCraft Upload

- Connect MakePython ESP32 to your PC, open uPyCraft, and select connect to the serial port.

![upy2](md_pic/upy5.png)

- If there is no port to display, you need to download the USB driver. [CP210x driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
- Get a MicroPython fireware from [micropython.org](http://www.micropython.org/download/esp32/)
- Firmware will be prompted if it has not been burned before or for other reasons.Board selects ESP32, BURN_addr selects 0x1000, Erase_Flash selects Yes, com selects the port number. Firmware Choose Users, click Choose to Choose ESP32-IDF3-20190125-v1.10.bin.（Or other esp32 micropython bin）

![burn_esp32](md_pic/burn_firmware.png)

- If you burn the firmware, you need to click connect again.

- Download all python programs in workSpace to ESP32.

![upy7](md_pic/upy7.png)

- You can also hold down the left mouse button and drag files from the workSpace into Device.

![upy2](md_pic/upy6.png)

- Press the RST button on ESP32 to reset the development board.

- Some projects do not provide main.py and need to set the main program entry manually. Right-click to select the file in Device that needs to be started up and select "Default Run".

![default_run](md_pic/default_run.jpg)