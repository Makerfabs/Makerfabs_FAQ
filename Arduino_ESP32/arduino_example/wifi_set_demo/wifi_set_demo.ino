#include "wifi_save.h"

void setup()
{
    Serial.begin(115200);
    if(wifi_set_main())
    {
        Serial.println("Connect WIFI SUCCESS");
    }
    else
    {
            Serial.println("Connect WIFI FAULT");
    }

}

void loop()
{
    Serial.println("loop");
    delay(3000);
}

