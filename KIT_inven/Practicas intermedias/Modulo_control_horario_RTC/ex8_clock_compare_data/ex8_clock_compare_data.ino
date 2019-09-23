/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   Compare dates and times
 *  File:      ex8_clock_compare_data.ino
 *  Date:      2016/01/20
 */


#include <Wire.h>
#include <RTC.h>

#define pLED 13

RTC rtc(DST_ON);
Data alarm1, alarm2;
boolean state;


void setup()
{
    Serial.begin(9600);
    while(!Serial);
    delay(1000);

    pinMode(pLED, OUTPUT);

    alarm1.year    = 2016;
    alarm1.month   = 1;
    alarm1.day     = 9;
    alarm1.hour24h = 23;
    alarm1.minutes = 59;
    alarm1.seconds = 55;

    alarm2 = Data( 2016, 1, 10, 0, 0, 5 );
}


void loop()
{
    Data d = rtc.getData();
    Serial.println( d.toString("Y/m/d H:i:s") );


  //////////////////////////////////  IMPORTANT!  /////////////////////////////////////////
  // IF THE DATE IS NOT INDICATED, THEN ONLY YOU CAN COMPARE THE HOURS OF THE SAME DAY.  //
  // INDICATING THE DATE THERE ARE NO LIMITATIONS.                                       //
  /////////////////////////////////////////////////////////////////////////////////////////


  //state = d.isAfter(22);                   // Hour24h
  //state = d.isAfter(22,50);                // Hour24h, Minutes
  //state = d.isAfter(22,50,51);             // Hour24h, Minutes, Seconds
  //state = d.isAfter(2015,01,31,22,50,51);  // Year, Month, Day, Hour24h, Minutes, Seconds
    state = d.isAfter(alarm1);               // Data Object

  //state = d.isBefore(22);                   // Hour24h
  //state = d.isBefore(22,50);                // Hour24h, Minutes
  //state = d.isBefore(22,50,51);             // Hour24h, Minutes, Seconds
  //state = d.isBefore(2015,01,31,22,50,51);  // Year, Month, Day, Hour24h, Minutes, Seconds
  //state = d.isBefore(alarm1);               // Data Object

  //                                                              AFTER:                                       | BEFORE:
  //state = d.isBetween(22,23);                                // Hour24h,                                     | Hour24h
  //state = d.isBetween(22,50, 23,50);                         // Hour24h, Minutes,                            | Hour24h, Minutes
  //state = d.isBetween(22,50,51, 23,50,51);                   // Hour24h, Minutes, Seconds,                   | Hour24h, Minutes, Seconds
  //state = d.isBetween(2015,01,31,22,50,51, 2015,02,1,0,0,5); // Year, Month, Day, Hour24h, Minutes, Seconds, | Year, Month, Day, Hour24h, Minutes, Seconds
  //state = d.isBetween(alarm1, alarm2);                       // Data Object,                                 | Data Object

    digitalWrite(pLED, state);
    delay(1000);
}