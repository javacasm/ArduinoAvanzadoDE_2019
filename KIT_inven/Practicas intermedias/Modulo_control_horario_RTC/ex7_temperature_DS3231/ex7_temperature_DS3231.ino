/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex7_temperature_DS3231.ino
 *  Date:      2014/10/15
 */


#include <Wire.h>
#include <RTC.h>

RTC rtc(DST_ON);


void setup()
{
    Serial.begin(9600);
    while(!Serial);
    delay(1000);
}



void loop()
{
    // GET TEMPERATURE DS3231 ONLY:
    Serial.print("Tem: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    delay(1000);
}