# arduino-voltmeter-clock change log
## v0.1 2017-03-30
* Reads time from RTC module and displays it with the voltmeters.
* If RTC is not found, the LED flashes.
* Smooth months, days, hours and minutes. For example voltmeter will show month as 4.7 and gradually increase throughout the month. It will not 'tick over' when the month (or other time unit) changes.
* LCD screen shows year, but is temporarily only set on startup. =

	```
	LCD year numerals:
	1  #   ###  ###  # #  ###  ###  ###  ###  ###
	2 ##    _#  __#  #_#  #_   #_     #  #_#  #_#
	3  #   #      #    #    #  # #   #   # #    #
	4 ###  ###  ###    #  ###  ###   #   ###  ###

    Year example:
      12345678901234567890

    1 ###  ###   #   ###
    2  _|  # #  ##   #_#
    3 |    # #   #   # #
    4 ###  ###  ###  ###
	```

* Pushing the button and turning the potentiometer should have the ability to set the time, but this code is completely UNTESTED. This will be cleaned up in the next version.
* Note PIR sensor input is ignored. Arduino, LCD screen and volmeters are always on.

## v0.2 2017-04-03
* Time can now by set by pushing the button and twisting the potentiometer
* The set time is displayed on the 20 x 4 LCD screen
* Modified turning on and off LCD code and circuit board. Circuit board is now Rev. 4.

## v0.3 2017-04-08
* Massively improved accuracy of the voltmeters. Program now requires calibration data. Previously the code assumed the voltmeter is at 50% if the PWM value is half of the maximum
* Removed unused variables and functions

## v0.4 2018-xx-xx
* 