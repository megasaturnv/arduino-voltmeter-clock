# To do list
## To do in next version
* Remove temporary code on 2nd to last line: digitalWrite(LED_BUILTIN,digitalRead(PIR_PIN));
* Make LED flash if RTC hasn't been set or if date and time isn't sane (I.e. year is before 2000)
* Make the year update (Instead of setting it once on startup)

## Other features to add
* Make voltmeters accurate when setting the time
* Make LED flash if RTC hasn't been set or if date and time isn't sane (I.e. year is before 2000)
* Make the year update (Instead of setting it once on startup)
* Perhaps play a special animation for the new year...
* Create custom 'block' character for LCD. This will replace the '#' character used for displaying the year
* Comment code better.
* Make seconds voltmeter nice and smooth (No ticking)
* Add easy setting in Arduino code to switch between smooth or traditional seconds.
* Add another setting for smooth months, days, hours and minutes.
* Investigate further which alt-code chars the LCD can produce.
* Make Arduino sleep if no PIR for a configurable amount of settings and add an interrupt on the PIR pin to wake up the Arduino.
* Add / check support for daylight savings time.
* Add ability to calibrate voltmeters outside of the Arduino code (on the clock) and save calibration data to Arduino EEPROM.
* Research possibility of calculating the phase of the moon and displaying it on the LCD.
* Add basic alarm/timer function which makes the LED flash.
* In addition to the current year, make LCD screen show the weekday and events.
```
DOW and Events example layout: (Events have room for a 14-char message)

  12345678901234567890
1 ===<Day of week>===
2 Upcoming events:
3 ##-## abcdefghijklmn
4 ##-## abcdefghijklmn

example:
  12345678901234567890
1 == Wednesday 15th ==
2 Upcoming events:
3 01-01 New years day
4 12-25 Christmas
```
* Make clock toggle between years or events every 10 ~seconds or after single button push (push + hold or a double push would then be used for changing the date and time etc).
* Events will be hard coded in Arduino code. This could be replaced with a text file on an SD card in the future. SD card could also support voltmeter calibration data etc...
* Add menu on LCD screen to change the time, calibration, alarm/timer etc. Will be controlled by long / short button presses and potentiometer
