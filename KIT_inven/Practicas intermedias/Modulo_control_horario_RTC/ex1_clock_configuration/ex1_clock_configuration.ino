/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex1_clock_configuration.ino
 *  Date:      2014/10/15
 */


#include <Wire.h>
#include <RTC.h>

RTC rtc(DST_ON); // OR DST_OFF


void setup()
{
    Serial.begin(9600);
    while(!Serial);
    delay(1000);

    // IMPORTANT!
    // It allows to set the time and date of the clock.
    // Once configured, delete (or comment) the code and rewrite the code in the Arduino.
    // Otherwise whenever you turn on the Arduino will modify the time.


    //////////////
    // SET DATE //
    //////////////

    //rtc.setYear(2014);
    //rtc.setMonth(10);
    //rtc.setDay(13);
    //rtc.setDate( 2014, 10, 13 ); // Year, Month and Day



    //////////////
    // SET TIME //
    //////////////

    //rtc.setHour(18);
    //rtc.setMinutes(42);
    //rtc.setSeconds(0);
    //rtc.setTime( 18, 42, 00 ); // Hour24H, Minutes and Seconds



    ///////////////////////
    // SET DATE AND TIME //
    ///////////////////////

    rtc.setDateTime( 2014, 10, 13, 18, 42, 00 ); // Year, Month, Day, Hour24H, Minutes and Seconds
}



void loop()
{
    Data d = rtc.getData();
    Serial.println( d.toString() );
    delay(1000);
}