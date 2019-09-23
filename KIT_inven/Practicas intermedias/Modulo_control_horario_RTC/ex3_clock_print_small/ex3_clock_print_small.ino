/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex3_clock_print_small.ino
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
    Data d = rtc.getData();

    // GET DATE:
    Serial.print(d.year);      Serial.print("/");
    Serial.print(d.month);     Serial.print("/");
    Serial.print(d.day);       Serial.print(" ");

    // GET TIME:
    Serial.print(d.hour24h);   Serial.print(":");
    Serial.print(d.minutes);   Serial.print(":");
    Serial.println(d.seconds);

    delay(1000);
}