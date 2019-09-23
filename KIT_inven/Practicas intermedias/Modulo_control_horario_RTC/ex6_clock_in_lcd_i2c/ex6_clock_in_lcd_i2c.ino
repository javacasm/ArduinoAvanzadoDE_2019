/*
 *  Author:    Alberto Gil Tesa
 *  Website:   http://giltesa.com
 *  License:   CC BY-NC-SA 3.0
 *
 *  Project:   RTC Dallas DS1307/DS3231
 *  File:      ex6_clock_in_lcd_i2c.ino
 *  Date:      2015/03/10
 */


#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#include <Wire.h>
#include <RTC.h>
RTC rtc(DST_ON);


void setup()
{
    lcd.begin(16, 2);
}


void loop()
{
    if( millis()%1000 == 0 )
    {
        Data d = rtc.getData();
        
        lcd.setCursor(3, 0);
        lcd.print( d.toString("Y/m/d") );         // Print it as a String.
        lcd.setCursor(4, 1);
        lcd.print( d.toString("H:i:s").c_str() ); // Print it as an array of characters.
    }
}


