/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex2_clock_configuration_serial.ino
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

    // To set the clock from the IDE, enter the
    // date and the time following this format: 2014 10 14 22 49 18
    // Year, Month, Day, Hour24H, Minutes and Seconds

    if( Serial.available() > 0 )
    {
        int year    = Serial.parseInt();
        int month   = Serial.parseInt();
        int day     = Serial.parseInt();
        int hour24h = Serial.parseInt();
        int minutes = Serial.parseInt();
        int seconds = Serial.parseInt();
        rtc.setDateTime( year, month, day, hour24h, minutes, seconds );

        while( Serial.available() > 0 && Serial.read() != -1 );
    }


    Data d = rtc.getData();
    Serial.println( d.toString() );
    delay(1000);
}
