EESchema Schematic File Version 2
LIBS:voltmeterClockKiCad-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:VoltmeterDisplayComponentLibrary
LIBS:voltmeterClockKiCad-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Voltmeter Clock"
Date "2017-04-01"
Rev "3"
Comp "By Megasaturnv"
Comment1 "For Veroboard / Stripboard"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 10350 1500 1    60   ~ 0
RAW
Text Label 9550 1000 1    60   ~ 0
DTR
Text Label 9750 1000 1    60   ~ 0
0(Rx)
Text Label 9000 1600 0    60   ~ 0
1(Tx)
Text Label 9000 1700 0    60   ~ 0
0(Rx)
Text Label 9000 1800 0    60   ~ 0
Reset
Text Label 10500 1800 0    60   ~ 0
Reset
Text Label 9000 2000 0    60   ~ 0
2
Text Label 9000 2100 0    60   ~ 0
3(**)
Text Label 9000 2200 0    60   ~ 0
4
Text Label 9000 2300 0    60   ~ 0
5(**)
Text Label 9000 2400 0    60   ~ 0
6(**)
Text Label 9000 2500 0    60   ~ 0
7
Text Label 9000 2600 0    60   ~ 0
8
Text Label 9000 2700 0    60   ~ 0
9(**)
Text Label 10500 2700 0    60   ~ 0
10(**/SS)
Text Label 10500 2600 0    60   ~ 0
11(**/MOSI)
Text Label 10500 2500 0    60   ~ 0
12(MISO)
Text Label 10500 2400 0    60   ~ 0
13(SCK)
Text Label 10500 2300 0    60   ~ 0
A0
Text Label 10500 2200 0    60   ~ 0
A1
Text Label 10500 2100 0    60   ~ 0
A2
Text Label 10500 2000 0    60   ~ 0
A3
Text Label 9650 3200 3    60   ~ 0
A4
Text Label 9550 3200 3    60   ~ 0
A5
Text Label 9950 3200 3    60   ~ 0
A7
Text Label 10050 3200 3    60   ~ 0
A6
$Comp
L CONN_01X02 P3
U 1 1 56D74FB3
P 9600 3000
F 0 "P3" H 9600 3150 50  0000 C CNN
F 1 "ADC" V 9700 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 9600 3000 50  0001 C CNN
F 3 "" H 9600 3000 50  0000 C CNN
	1    9600 3000
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X02 P5
U 1 1 56D7505C
P 10000 3000
F 0 "P5" H 10000 3150 50  0000 C CNN
F 1 "ADC" V 10100 3000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 10000 3000 50  0001 C CNN
F 3 "" H 10000 3000 50  0000 C CNN
	1    10000 3000
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X06 P2
U 1 1 56D75238
P 9800 1200
F 0 "P2" H 9800 1550 50  0000 C CNN
F 1 "COM" V 9900 1200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 9800 1200 50  0001 C CNN
F 3 "" H 9800 1200 50  0000 C CNN
	1    9800 1200
	0    -1   1    0   
$EndComp
Text Label 9650 1000 1    60   ~ 0
1(Tx)
$Comp
L VCC #PWR01
U 1 1 56D753B8
P 9850 1000
F 0 "#PWR01" H 9850 850 50  0001 C CNN
F 1 "VCC" H 9850 1150 50  0000 C CNN
F 2 "" H 9850 1000 50  0000 C CNN
F 3 "" H 9850 1000 50  0000 C CNN
	1    9850 1000
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X12 P1
U 1 1 56D754D1
P 9550 2150
F 0 "P1" H 9550 2800 50  0000 C CNN
F 1 "Digital" V 9650 2150 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x12_Pitch2.54mm" H 9550 2150 50  0001 C CNN
F 3 "" H 9550 2150 50  0000 C CNN
	1    9550 2150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X12 P4
U 1 1 56D755F3
P 10050 2150
F 0 "P4" H 10050 2800 50  0000 C CNN
F 1 "Analog" V 10150 2150 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x12_Pitch2.54mm" H 10050 2150 50  0001 C CNN
F 3 "" H 10050 2150 50  0000 C CNN
	1    10050 2150
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 56D756B8
P 9250 2800
F 0 "#PWR02" H 9250 2550 50  0001 C CNN
F 1 "GND" H 9250 2650 50  0000 C CNN
F 2 "" H 9250 2800 50  0000 C CNN
F 3 "" H 9250 2800 50  0000 C CNN
	1    9250 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 56D75A03
P 10350 2800
F 0 "#PWR03" H 10350 2550 50  0001 C CNN
F 1 "GND" H 10350 2650 50  0000 C CNN
F 2 "" H 10350 2800 50  0000 C CNN
F 3 "" H 10350 2800 50  0000 C CNN
	1    10350 2800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 56D75A9D
P 10450 1500
F 0 "#PWR04" H 10450 1350 50  0001 C CNN
F 1 "VCC" H 10450 1650 50  0000 C CNN
F 2 "" H 10450 1500 50  0000 C CNN
F 3 "" H 10450 1500 50  0000 C CNN
	1    10450 1500
	1    0    0    -1  
$EndComp
Text Notes 9650 1600 0    60   ~ 0
1
Text Notes 8550 575  0    60   ~ 0
Shield Arduino Pro Mini \n
$Comp
L 2004_LCD_DISPLAY DS6
U 1 1 58CE0833
P 2950 2000
F 0 "DS6" H 2950 1550 60  0000 C CNN
F 1 "2004_LCD_DISPLAY" H 2950 1700 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12_Pitch2.54mm" H 2600 2000 60  0001 C CNN
F 3 "" H 2600 2000 60  0001 C CNN
	1    2950 2000
	0    1    1    0   
$EndComp
Text Label 3550 2200 0    60   ~ 0
A0
Text Label 3550 2300 0    60   ~ 0
A1
Text Label 3550 2400 0    60   ~ 0
A2
Text Label 3550 2500 0    60   ~ 0
A3
$Comp
L GND #PWR05
U 1 1 58CE111E
P 3550 1300
F 0 "#PWR05" H 3550 1050 50  0001 C CNN
F 1 "GND" H 3550 1150 50  0000 C CNN
F 2 "" H 3550 1300 50  0000 C CNN
F 3 "" H 3550 1300 50  0000 C CNN
	1    3550 1300
	0    -1   -1   0   
$EndComp
$Comp
L ANALOGUE_VU_DISPLAY DS1
U 1 1 58CE23C7
P 1000 1100
F 0 "DS1" H 1000 800 60  0000 C CNN
F 1 "VU_SECS" H 1000 1400 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 1200 60  0001 C CNN
F 3 "" H 1000 1200 60  0001 C CNN
	1    1000 1100
	0    -1   -1   0   
$EndComp
$Comp
L ANALOGUE_VU_DISPLAY DS2
U 1 1 58CE242C
P 1000 1800
F 0 "DS2" H 1000 1500 60  0000 C CNN
F 1 "VU_MINS" H 1000 2100 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 1900 60  0001 C CNN
F 3 "" H 1000 1900 60  0001 C CNN
	1    1000 1800
	0    -1   -1   0   
$EndComp
$Comp
L ANALOGUE_VU_DISPLAY DS3
U 1 1 58CE246B
P 1000 2500
F 0 "DS3" H 1000 2200 60  0000 C CNN
F 1 "VU_HOURS" H 1000 2800 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 2600 60  0001 C CNN
F 3 "" H 1000 2600 60  0001 C CNN
	1    1000 2500
	0    -1   -1   0   
$EndComp
$Comp
L ANALOGUE_VU_DISPLAY DS4
U 1 1 58CE250B
P 1000 3200
F 0 "DS4" H 1000 2900 60  0000 C CNN
F 1 "VU_DAY" H 1000 3500 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 3300 60  0001 C CNN
F 3 "" H 1000 3300 60  0001 C CNN
	1    1000 3200
	0    -1   -1   0   
$EndComp
$Comp
L ANALOGUE_VU_DISPLAY DS5
U 1 1 58CE25F2
P 1000 3900
F 0 "DS5" H 1000 3600 60  0000 C CNN
F 1 "VU_MONTH" H 1000 4200 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1000 4000 60  0001 C CNN
F 3 "" H 1000 4000 60  0001 C CNN
	1    1000 3900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR06
U 1 1 58CE3D4D
P 1600 3000
F 0 "#PWR06" H 1600 2750 50  0001 C CNN
F 1 "GND" H 1600 2850 50  0000 C CNN
F 2 "" H 1600 3000 50  0000 C CNN
F 3 "" H 1600 3000 50  0000 C CNN
	1    1600 3000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR07
U 1 1 58CE3E51
P 1600 2300
F 0 "#PWR07" H 1600 2050 50  0001 C CNN
F 1 "GND" H 1600 2150 50  0000 C CNN
F 2 "" H 1600 2300 50  0000 C CNN
F 3 "" H 1600 2300 50  0000 C CNN
	1    1600 2300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR08
U 1 1 58CE3E87
P 1600 1600
F 0 "#PWR08" H 1600 1350 50  0001 C CNN
F 1 "GND" H 1600 1450 50  0000 C CNN
F 2 "" H 1600 1600 50  0000 C CNN
F 3 "" H 1600 1600 50  0000 C CNN
	1    1600 1600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 58CE4216
P 1600 3700
F 0 "#PWR09" H 1600 3450 50  0001 C CNN
F 1 "GND" H 1600 3550 50  0000 C CNN
F 2 "" H 1600 3700 50  0000 C CNN
F 3 "" H 1600 3700 50  0000 C CNN
	1    1600 3700
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 58CE46C5
P 1600 900
F 0 "#PWR010" H 1600 650 50  0001 C CNN
F 1 "GND" H 1600 750 50  0000 C CNN
F 2 "" H 1600 900 50  0000 C CNN
F 3 "" H 1600 900 50  0000 C CNN
	1    1600 900 
	0    -1   -1   0   
$EndComp
Text Label 1900 1300 0    60   ~ 0
5(**)
Text Label 1900 2000 0    60   ~ 0
6(**)
Text Label 1900 2700 0    60   ~ 0
3(**)
Text Label 1900 3400 0    60   ~ 0
9(**)
$Comp
L CP C1
U 1 1 58CE5694
P 1500 1100
F 0 "C1" H 1525 1200 50  0000 L CNN
F 1 "47uF" H 1525 1000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1538 950 50  0001 C CNN
F 3 "" H 1500 1100 50  0000 C CNN
	1    1500 1100
	-1   0    0    1   
$EndComp
$Comp
L CP C2
U 1 1 58CE6BCA
P 1500 1800
F 0 "C2" H 1525 1900 50  0000 L CNN
F 1 "47uF" H 1525 1700 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1538 1650 50  0001 C CNN
F 3 "" H 1500 1800 50  0000 C CNN
	1    1500 1800
	-1   0    0    1   
$EndComp
$Comp
L CP C3
U 1 1 58CE6D22
P 1500 2500
F 0 "C3" H 1525 2600 50  0000 L CNN
F 1 "47uF" H 1525 2400 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1538 2350 50  0001 C CNN
F 3 "" H 1500 2500 50  0000 C CNN
	1    1500 2500
	-1   0    0    1   
$EndComp
$Comp
L CP C4
U 1 1 58CE6E69
P 1500 3200
F 0 "C4" H 1525 3300 50  0000 L CNN
F 1 "47uF" H 1525 3100 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1538 3050 50  0001 C CNN
F 3 "" H 1500 3200 50  0000 C CNN
	1    1500 3200
	-1   0    0    1   
$EndComp
$Comp
L CP C5
U 1 1 58CE6FCB
P 1500 3900
F 0 "C5" H 1525 4000 50  0000 L CNN
F 1 "47uF" H 1525 3800 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1538 3750 50  0001 C CNN
F 3 "" H 1500 3900 50  0000 C CNN
	1    1500 3900
	-1   0    0    1   
$EndComp
Text Label 4900 1100 0    60   ~ 0
7
$Comp
L PIR_SENSOR PIR1
U 1 1 58CEC32C
P 6200 2300
F 0 "PIR1" H 6200 2000 60  0000 C CNN
F 1 "PIR_SENSOR" H 6200 2200 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 6200 2300 60  0001 C CNN
F 3 "" H 6200 2300 60  0001 C CNN
	1    6200 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58CEC7A4
P 6100 1900
F 0 "#PWR011" H 6100 1650 50  0001 C CNN
F 1 "GND" H 6100 1750 50  0000 C CNN
F 2 "" H 6100 1900 50  0000 C CNN
F 3 "" H 6100 1900 50  0000 C CNN
	1    6100 1900
	-1   0    0    1   
$EndComp
Text Label 6000 1650 0    60   ~ 0
2
$Comp
L PUSH_BUTTON S1
U 1 1 58CEE107
P 7000 1600
F 0 "S1" H 7000 1350 60  0000 C CNN
F 1 "PUSH_BUTTON" H 7000 1450 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 7000 1600 60  0001 C CNN
F 3 "" H 7000 1600 60  0001 C CNN
	1    7000 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 58CEE4DE
P 7200 1000
F 0 "#PWR012" H 7200 750 50  0001 C CNN
F 1 "GND" H 7200 850 50  0000 C CNN
F 2 "" H 7200 1000 50  0000 C CNN
F 3 "" H 7200 1000 50  0000 C CNN
	1    7200 1000
	-1   0    0    1   
$EndComp
Text Label 6800 1000 0    60   ~ 0
8
$Comp
L POT RV1
U 1 1 58CEF03B
P 7850 2350
F 0 "RV1" V 7675 2350 50  0000 C CNN
F 1 "POT100kR" V 7750 2350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7850 2350 50  0001 C CNN
F 3 "" H 7850 2350 50  0000 C CNN
	1    7850 2350
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR013
U 1 1 58CEF57E
P 7600 2350
F 0 "#PWR013" H 7600 2200 50  0001 C CNN
F 1 "VCC" H 7600 2500 50  0000 C CNN
F 2 "" H 7600 2350 50  0000 C CNN
F 3 "" H 7600 2350 50  0000 C CNN
	1    7600 2350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 58CEF5D9
P 8100 2350
F 0 "#PWR014" H 8100 2100 50  0001 C CNN
F 1 "GND" H 8100 2200 50  0000 C CNN
F 2 "" H 8100 2350 50  0000 C CNN
F 3 "" H 8100 2350 50  0000 C CNN
	1    8100 2350
	0    -1   -1   0   
$EndComp
Text Label 7850 2600 0    60   ~ 0
A6
$Comp
L RTC_DS3231 RTC1
U 1 1 58CF039A
P 6000 4200
F 0 "RTC1" H 6000 3900 60  0000 C CNN
F 1 "RTC_DS3231" H 6000 4600 60  0000 C CNN
F 2 "VoltmeterDisplayFootprintLibrary:RTC_DS3231" H 5850 4200 60  0001 C CNN
F 3 "" H 5850 4200 60  0001 C CNN
	1    6000 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 58CF0B6F
P 6600 3900
F 0 "#PWR015" H 6600 3650 50  0001 C CNN
F 1 "GND" H 6600 3750 50  0000 C CNN
F 2 "" H 6600 3900 50  0000 C CNN
F 3 "" H 6600 3900 50  0000 C CNN
	1    6600 3900
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR016
U 1 1 58CF0BCE
P 6800 3900
F 0 "#PWR016" H 6800 3750 50  0001 C CNN
F 1 "VCC" H 6800 4050 50  0000 C CNN
F 2 "" H 6800 3900 50  0000 C CNN
F 3 "" H 6800 3900 50  0000 C CNN
	1    6800 3900
	1    0    0    -1  
$EndComp
Text Label 6700 4200 0    60   ~ 0
A4
Text Label 6700 4300 0    60   ~ 0
A5
$Comp
L USB_OTG-RESCUE-voltmeterClockKiCad P7
U 1 1 58CF3303
P 10300 3800
F 0 "P7" H 10625 3675 50  0000 C CNN
F 1 "USB_OTG" H 10300 4000 50  0000 C CNN
F 2 "Connectors:USB_Micro-B" V 10250 3700 50  0001 C CNN
F 3 "" V 10250 3700 50  0000 C CNN
	1    10300 3800
	1    0    0    -1  
$EndComp
NoConn ~ 10200 4100
NoConn ~ 10300 4100
NoConn ~ 10400 4100
$Comp
L GND #PWR017
U 1 1 58CF590E
P 10900 4100
F 0 "#PWR017" H 10900 3850 50  0001 C CNN
F 1 "GND" H 10900 3950 50  0000 C CNN
F 2 "" H 10900 4100 50  0000 C CNN
F 3 "" H 10900 4100 50  0000 C CNN
	1    10900 4100
	0    -1   -1   0   
$EndComp
$Comp
L Battery_Cell BT2
U 1 1 58CF65D2
P 10350 4750
F 0 "BT2" H 10100 4850 50  0000 L CNN
F 1 "1.2V_AAA_Battery" H 9700 4750 50  0000 L CNN
F 2 "" V 10350 4810 50  0001 C CNN
F 3 "" V 10350 4810 50  0000 C CNN
	1    10350 4750
	0    -1   -1   0   
$EndComp
$Comp
L Battery_Cell BT1
U 1 1 58CF6D36
P 10000 4750
F 0 "BT1" H 9750 4850 50  0000 L CNN
F 1 "1.2V_AAA_Battery" H 9350 4750 50  0000 L CNN
F 2 "" V 10000 4810 50  0001 C CNN
F 3 "" V 10000 4810 50  0000 C CNN
	1    10000 4750
	0    -1   -1   0   
$EndComp
$Comp
L Battery_Cell BT3
U 1 1 58CF6D9A
P 10700 4750
F 0 "BT3" H 10450 4850 50  0000 L CNN
F 1 "1.2V_AAA_Battery" H 10050 4750 50  0000 L CNN
F 2 "" V 10700 4810 50  0001 C CNN
F 3 "" V 10700 4810 50  0000 C CNN
	1    10700 4750
	0    -1   -1   0   
$EndComp
$Comp
L R R10
U 1 1 58CF81BA
P 9400 4300
F 0 "R10" V 9480 4300 50  0000 C CNN
F 1 "56R" V 9400 4300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9330 4300 50  0001 C CNN
F 3 "" H 9400 4300 50  0000 C CNN
	1    9400 4300
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 58CFD909
P 3350 3500
F 0 "D1" H 3350 3600 50  0000 C CNN
F 1 "LED" H 3350 3400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3350 3500 50  0001 C CNN
F 3 "" H 3350 3500 50  0000 C CNN
	1    3350 3500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR018
U 1 1 58CFE72C
P 3600 3500
F 0 "#PWR018" H 3600 3250 50  0001 C CNN
F 1 "GND" H 3600 3350 50  0000 C CNN
F 2 "" H 3600 3500 50  0000 C CNN
F 3 "" H 3600 3500 50  0000 C CNN
	1    3600 3500
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 58CFE847
P 2950 3500
F 0 "R9" V 3030 3500 50  0000 C CNN
F 1 "1000R" V 2950 3500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2880 3500 50  0001 C CNN
F 3 "" H 2950 3500 50  0000 C CNN
	1    2950 3500
	0    1    1    0   
$EndComp
Text Notes 5450 600  0    60   ~ 0
Inputs
Text Notes 550  600  0    60   ~ 0
Outputs
Text Notes 7750 3500 0    60   ~ 0
Power\n
$Comp
L CONN_01X06 P6
U 1 1 58D0B4E0
P 7050 4200
F 0 "P6" H 7050 4550 50  0000 C CNN
F 1 "Serial_Conn" V 7150 4200 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Angled_1x06_Pitch2.54mm" H 7050 4200 50  0001 C CNN
F 3 "" H 7050 4200 50  0000 C CNN
	1    7050 4200
	-1   0    0    -1  
$EndComp
Text Label 7350 3950 0    60   ~ 0
DTR
Text Label 7350 4050 0    60   ~ 0
1(Tx)
Text Label 7350 4150 0    60   ~ 0
0(Rx)
$Comp
L VCC #PWR019
U 1 1 58D0CAE9
P 7350 4250
F 0 "#PWR019" H 7350 4100 50  0001 C CNN
F 1 "VCC" H 7350 4400 50  0000 C CNN
F 2 "" H 7350 4250 50  0000 C CNN
F 3 "" H 7350 4250 50  0000 C CNN
	1    7350 4250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR020
U 1 1 56D7539A
P 10200 1000
F 0 "#PWR020" H 10200 750 50  0001 C CNN
F 1 "GND" H 10200 850 50  0000 C CNN
F 2 "" H 10200 1000 50  0000 C CNN
F 3 "" H 10200 1000 50  0000 C CNN
	1    10200 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 58D0E592
P 7450 4450
F 0 "#PWR021" H 7450 4200 50  0001 C CNN
F 1 "GND" H 7450 4300 50  0000 C CNN
F 2 "" H 7450 4450 50  0000 C CNN
F 3 "" H 7450 4450 50  0000 C CNN
	1    7450 4450
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 58CEDF33
P 1700 1300
F 0 "R1" V 1780 1300 50  0000 C CNN
F 1 "470R" V 1700 1300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1630 1300 50  0001 C CNN
F 3 "" H 1700 1300 50  0000 C CNN
	1    1700 1300
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 58CEECB4
P 1700 2000
F 0 "R2" V 1780 2000 50  0000 C CNN
F 1 "470R" V 1700 2000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1630 2000 50  0001 C CNN
F 3 "" H 1700 2000 50  0000 C CNN
	1    1700 2000
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 58CF0B76
P 1700 2700
F 0 "R3" V 1780 2700 50  0000 C CNN
F 1 "470R" V 1700 2700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1630 2700 50  0001 C CNN
F 3 "" H 1700 2700 50  0000 C CNN
	1    1700 2700
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 58CF0EB0
P 1700 3400
F 0 "R4" V 1780 3400 50  0000 C CNN
F 1 "470R" V 1700 3400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1630 3400 50  0001 C CNN
F 3 "" H 1700 3400 50  0000 C CNN
	1    1700 3400
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 58CF158A
P 1750 4100
F 0 "R5" V 1830 4100 50  0000 C CNN
F 1 "470R" V 1750 4100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1680 4100 50  0001 C CNN
F 3 "" H 1750 4100 50  0000 C CNN
	1    1750 4100
	0    1    1    0   
$EndComp
Text Label 3550 1800 0    60   ~ 0
12(MISO)
Text Label 2700 3500 1    60   ~ 0
13(SCK)
Text Label 3550 1600 0    60   ~ 0
11(**/MOSI)
Text Label 1950 4100 0    60   ~ 0
10(**/SS)
NoConn ~ 9000 2200
NoConn ~ 9950 3200
$Comp
L VCC #PWR022
U 1 1 58D16C0B
P 5900 1900
F 0 "#PWR022" H 5900 1750 50  0001 C CNN
F 1 "VCC" H 5900 2050 50  0000 C CNN
F 2 "" H 5900 1900 50  0000 C CNN
F 3 "" H 5900 1900 50  0000 C CNN
	1    5900 1900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR023
U 1 1 58D1B7D7
P 9400 4000
F 0 "#PWR023" H 9400 3850 50  0001 C CNN
F 1 "+5V" H 9400 4140 50  0000 C CNN
F 2 "" H 9400 4000 50  0000 C CNN
F 3 "" H 9400 4000 50  0000 C CNN
	1    9400 4000
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR024
U 1 1 58D1DBE9
P 10550 1600
F 0 "#PWR024" H 10550 1450 50  0001 C CNN
F 1 "+3.3V" H 10550 1740 50  0000 C CNN
F 2 "" H 10550 1600 50  0000 C CNN
F 3 "" H 10550 1600 50  0000 C CNN
	1    10550 1600
	0    1    1    0   
$EndComp
$Comp
L Q_PNP_CBE Q1
U 1 1 58D2312A
P 4300 1100
F 0 "Q1" H 4500 1150 50  0000 L CNN
F 1 "Q_PNP_CBE" H 4500 1050 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4500 1200 50  0001 C CNN
F 3 "" H 4300 1100 50  0000 C CNN
	1    4300 1100
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 58D26B54
P 4700 1100
F 0 "R8" V 4780 1100 50  0000 C CNN
F 1 "10000R" V 4700 1100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4630 1100 50  0001 C CNN
F 3 "" H 4700 1100 50  0000 C CNN
	1    4700 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 3900 6600 4000
Wire Wire Line
	7600 2350 7700 2350
Wire Wire Line
	1400 3700 1600 3700
Wire Wire Line
	1400 2700 1550 2700
Wire Wire Line
	1400 3000 1600 3000
Wire Wire Line
	1400 2300 1600 2300
Wire Wire Line
	1400 1600 1600 1600
Connection ~ 1500 900 
Wire Wire Line
	1400 900  1600 900 
Wire Wire Line
	7200 1000 7200 1100
Wire Wire Line
	1850 2000 1900 2000
Wire Wire Line
	1950 4100 1900 4100
Wire Wire Line
	1850 2700 1900 2700
Wire Wire Line
	1850 3400 1900 3400
Wire Wire Line
	1850 1300 1900 1300
Wire Wire Line
	7350 4350 7350 4450
Connection ~ 7350 4450
Wire Wire Line
	7250 4350 7350 4350
Wire Wire Line
	7250 4250 7350 4250
Wire Wire Line
	7250 4150 7350 4150
Wire Wire Line
	7250 4050 7350 4050
Wire Wire Line
	7250 3950 7350 3950
Wire Notes Line
	8050 3550 8050 3400
Wire Notes Line
	7700 3550 8050 3550
Wire Notes Line
	950  650  950  500 
Wire Notes Line
	500  650  950  650 
Wire Notes Line
	5750 650  5750 500 
Wire Notes Line
	5400 650  5750 650 
Wire Notes Line
	7700 5450 11200 5450
Wire Notes Line
	5400 4300 5400 500 
Wire Notes Line
	500  4300 5400 4300
Wire Wire Line
	10700 3700 10800 3700
Wire Wire Line
	2800 3500 2700 3500
Wire Wire Line
	3500 3500 3600 3500
Wire Wire Line
	3200 3500 3100 3500
Wire Wire Line
	10450 4750 10500 4750
Wire Wire Line
	10100 4750 10150 4750
Wire Wire Line
	10800 3700 10800 4750
Wire Wire Line
	9400 4100 10100 4100
Wire Wire Line
	6600 4300 6700 4300
Wire Wire Line
	6600 4200 6700 4200
Wire Wire Line
	7850 2500 7850 2600
Wire Wire Line
	8000 2350 8100 2350
Wire Wire Line
	6800 1100 6800 1000
Wire Wire Line
	6000 2000 6000 1650
Wire Wire Line
	6100 2000 6100 1900
Connection ~ 1500 3700
Wire Wire Line
	1500 3750 1500 3700
Connection ~ 1500 4100
Wire Wire Line
	1500 4100 1500 4050
Connection ~ 1500 3400
Wire Wire Line
	1500 3350 1500 3400
Connection ~ 1500 3000
Wire Wire Line
	1500 3050 1500 3000
Connection ~ 1500 2700
Wire Wire Line
	1500 2650 1500 2700
Connection ~ 1500 2300
Wire Wire Line
	1500 2350 1500 2300
Connection ~ 1500 2000
Wire Wire Line
	1500 2000 1500 1950
Connection ~ 1500 1600
Wire Wire Line
	1500 1650 1500 1600
Connection ~ 1500 1300
Wire Wire Line
	1500 1250 1500 1300
Wire Wire Line
	1500 900  1500 950 
Wire Wire Line
	1400 1300 1550 1300
Wire Wire Line
	1400 4100 1600 4100
Wire Wire Line
	1400 3400 1550 3400
Wire Wire Line
	1400 2000 1550 2000
Wire Wire Line
	3350 2200 3550 2200
Wire Wire Line
	3350 2300 3550 2300
Wire Wire Line
	3350 2400 3550 2400
Wire Wire Line
	3350 2500 3550 2500
Wire Wire Line
	3350 1800 3550 1800
Wire Wire Line
	3350 1600 3550 1600
Wire Wire Line
	3350 1300 3550 1300
Wire Notes Line
	8525 650  9700 650 
Wire Notes Line
	9700 650  9700 475 
Wire Notes Line
	5400 3400 11200 3400
Wire Wire Line
	10250 2700 10500 2700
Wire Wire Line
	10500 2600 10250 2600
Wire Wire Line
	10250 2500 10500 2500
Wire Wire Line
	10500 2400 10250 2400
Wire Wire Line
	10250 2300 10500 2300
Wire Wire Line
	10500 2200 10250 2200
Wire Wire Line
	10250 2100 10500 2100
Wire Wire Line
	10500 2000 10250 2000
Wire Wire Line
	10250 1800 10500 1800
Wire Wire Line
	10450 1500 10450 1900
Wire Wire Line
	10450 1900 10250 1900
Wire Wire Line
	10350 1700 10350 2800
Wire Wire Line
	10250 1700 10350 1700
Wire Wire Line
	10350 1600 10250 1600
Wire Wire Line
	10350 1500 10350 1600
Wire Wire Line
	9350 2700 9000 2700
Wire Wire Line
	9350 2600 9000 2600
Wire Wire Line
	9000 2500 9350 2500
Wire Wire Line
	9350 2400 9000 2400
Wire Wire Line
	9000 2300 9350 2300
Wire Wire Line
	9350 2200 9000 2200
Wire Wire Line
	9350 2100 9000 2100
Wire Wire Line
	9000 2000 9350 2000
Wire Wire Line
	9350 1800 9000 1800
Wire Wire Line
	9000 1700 9350 1700
Wire Wire Line
	9350 1600 9000 1600
Wire Wire Line
	9250 1900 9250 2800
Wire Wire Line
	9350 1900 9250 1900
Connection ~ 10050 1000
Wire Wire Line
	9950 1000 10200 1000
Wire Wire Line
	3450 1300 3450 2700
Wire Wire Line
	3450 2700 3350 2700
Connection ~ 3450 1300
Wire Wire Line
	6800 3900 6800 4100
Wire Wire Line
	6800 4100 6600 4100
Wire Wire Line
	5900 1900 5900 2000
Wire Wire Line
	7250 4450 7450 4450
Wire Wire Line
	9400 4000 9400 4150
Connection ~ 9400 4100
Wire Wire Line
	10450 1600 10550 1600
Connection ~ 10450 1600
Wire Wire Line
	4200 800  4200 900 
Wire Wire Line
	4850 1100 4900 1100
Wire Wire Line
	4200 1300 4200 2600
Wire Wire Line
	4000 1400 4400 1400
Connection ~ 4200 1400
Wire Wire Line
	4500 1100 4550 1100
Wire Wire Line
	3350 1500 3450 1500
Connection ~ 3450 1500
Wire Wire Line
	3350 1700 3450 1700
Connection ~ 3450 1700
Wire Wire Line
	3350 2600 3700 2600
$Comp
L R R7
U 1 1 58D28ACA
P 3850 2600
F 0 "R7" V 3930 2600 50  0000 C CNN
F 1 "1000R" V 3850 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3780 2600 50  0001 C CNN
F 3 "" H 3850 2600 50  0000 C CNN
	1    3850 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 1400 3700 1400
$Comp
L R R6
U 1 1 58D2A037
P 3850 1400
F 0 "R6" V 3930 1400 50  0000 C CNN
F 1 "300R" V 3850 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3780 1400 50  0001 C CNN
F 3 "" H 3850 1400 50  0000 C CNN
	1    3850 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 2600 4000 2600
Wire Wire Line
	9400 4450 9400 4600
Wire Wire Line
	9150 4600 10250 4600
Wire Wire Line
	10500 4100 10900 4100
Connection ~ 9800 4600
Connection ~ 10800 4600
Connection ~ 10800 4100
$Comp
L CONN_01X02 P8
U 1 1 58D410E8
P 10300 4400
F 0 "P8" H 10300 4550 50  0000 C CNN
F 1 "Battery_Conn" V 10400 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 10300 4400 50  0001 C CNN
F 3 "" H 10300 4400 50  0000 C CNN
	1    10300 4400
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X02 P9
U 1 1 58CFEA4B
P 4450 1850
F 0 "P9" H 4450 2000 50  0000 C CNN
F 1 "Backlight_Conn" V 4550 1850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 4450 1850 50  0001 C CNN
F 3 "" H 4450 1850 50  0000 C CNN
	1    4450 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 1400 4400 1650
Wire Wire Line
	4500 1650 4500 1400
Wire Wire Line
	4500 1400 4600 1400
$Comp
L GND #PWR025
U 1 1 58CFF089
P 4600 1400
F 0 "#PWR025" H 4600 1150 50  0001 C CNN
F 1 "GND" H 4600 1250 50  0000 C CNN
F 2 "" H 4600 1400 50  0000 C CNN
F 3 "" H 4600 1400 50  0000 C CNN
	1    4600 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9800 4750 9800 4600
Wire Notes Line
	8500 500  8500 3400
Wire Notes Line
	7700 3400 7700 5450
$Comp
L PUSH_BUTTON S2
U 1 1 58D09ED1
P 8200 4800
F 0 "S2" H 8200 4550 60  0000 C CNN
F 1 "ON/OFF_SWITCH" H 8200 4650 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 8200 4800 60  0001 C CNN
F 3 "" H 8200 4800 60  0001 C CNN
	1    8200 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 5000 9000 5000
Text Label 9000 5000 0    60   ~ 0
RAW
Wire Wire Line
	10350 4600 10800 4600
Wire Wire Line
	9500 4550 9500 4600
Connection ~ 9500 4600
Text Label 4200 800  0    60   ~ 0
RAW
Text Label 9500 4550 0    60   ~ 0
ONOFF_RAW
Connection ~ 9400 4600
$Comp
L R R11
U 1 1 58DE46AD
P 9000 4600
F 0 "R11" V 9080 4600 50  0000 C CNN
F 1 "56R" V 9000 4600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 4600 50  0001 C CNN
F 3 "" H 9000 4600 50  0001 C CNN
	1    9000 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 4600 8850 4600
$EndSCHEMATC
