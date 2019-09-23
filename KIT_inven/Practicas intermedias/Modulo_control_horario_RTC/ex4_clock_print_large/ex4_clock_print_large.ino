/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex4_clock_print_large.ino
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


    // TIME:
    Serial.print("It's ");
    Serial.print(d.hour24h);
    Serial.print(":");

    if( d.minutes < 10 )
        Serial.print("0");
    Serial.print(d.minutes);
    Serial.print(":");

    if( d.seconds < 10 )
        Serial.print("0");
    Serial.print(d.seconds);
    Serial.print(" ");


    // DATE:
    switch( d.dayWeek )
    {
        case 1:  Serial.print("Monday");    break;
        case 2:  Serial.print("Tuesday");   break;
        case 3:  Serial.print("Wednesday"); break;
        case 4:  Serial.print("Thursday");  break;
        case 5:  Serial.print("Friday");    break;
        case 6:  Serial.print("Saturday");  break;
        case 7:  Serial.print("Sunday");    break;
    }

    Serial.print(" of ");

    switch( d.month )
    {
        case 1:  Serial.print("January");   break;
        case 2:  Serial.print("February");  break;
        case 3:  Serial.print("March");     break;
        case 4:  Serial.print("April");     break;
        case 5:  Serial.print("May");       break;
        case 6:  Serial.print("June");      break;
        case 7:  Serial.print("July");      break;
        case 8:  Serial.print("August");    break;
        case 9:  Serial.print("September"); break;
        case 10: Serial.print("October");   break;
        case 11: Serial.print("November");  break;
        case 12: Serial.print("December");  break;
    }

    Serial.print(" ");
    Serial.print(d.day);
    Serial.print(", ");
    Serial.println(d.year);

    delay(1000);
}
