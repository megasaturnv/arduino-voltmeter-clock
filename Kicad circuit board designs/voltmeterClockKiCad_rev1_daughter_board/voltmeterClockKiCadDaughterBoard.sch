EESchema Schematic File Version 2
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
LIBS:voltmeterClockKiCadDaughterBoard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Voltmeter clock daughter board"
Date "2017-04-02"
Rev "1"
Comp "By Megasaturnv"
Comment1 "For Veroboard / Stripboard"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3100 1700 2800 1700
Wire Wire Line
	3100 1900 2800 1900
Text Label 3100 1700 0    60   ~ 0
7
$Comp
L R R1
U 1 1 58E04BA3
P 2650 1700
F 0 "R1" V 2730 1700 50  0000 C CNN
F 1 "100kR-500kR" V 2550 1700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2580 1700 50  0001 C CNN
F 3 "" H 2650 1700 50  0001 C CNN
	1    2650 1700
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 58E04BBE
P 2650 1900
F 0 "R2" V 2730 1900 50  0000 C CNN
F 1 "1kR-22kR" V 2800 1900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2580 1900 50  0001 C CNN
F 3 "" H 2650 1900 50  0001 C CNN
	1    2650 1900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 58E04BD9
P 3100 1900
F 0 "#PWR01" H 3100 1650 50  0001 C CNN
F 1 "GND" H 3100 1750 50  0000 C CNN
F 2 "" H 3100 1900 50  0001 C CNN
F 3 "" H 3100 1900 50  0001 C CNN
	1    3100 1900
	0    -1   -1   0   
$EndComp
$Comp
L Q_NPN_EBC Q2
U 1 1 58E04BFB
P 2300 1700
F 0 "Q2" H 2500 1750 50  0000 L CNN
F 1 "Q_NPN_EBC_2N3904" H 2500 1650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2500 1800 50  0001 C CNN
F 3 "" H 2300 1700 50  0001 C CNN
	1    2300 1700
	-1   0    0    -1  
$EndComp
$Comp
L Q_PNP_EBC Q1
U 1 1 58E04C38
P 2000 1500
F 0 "Q1" H 2200 1550 50  0000 L CNN
F 1 "Q_PNP_EBC" H 2200 1450 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2200 1600 50  0001 C CNN
F 3 "" H 2000 1500 50  0001 C CNN
	1    2000 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1900 1300 1900 1100
Text Label 1900 1100 0    60   ~ 0
RAW
Wire Wire Line
	2500 1900 2200 1900
Text Label 1250 1700 0    60   ~ 0
OUT
$Comp
L CONN_01X02 J5
U 1 1 58E04EBE
P 1200 1350
F 0 "J5" H 1200 1500 50  0000 C CNN
F 1 "CONN_01X02" V 1300 1350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 1200 1350 50  0001 C CNN
F 3 "" H 1200 1350 50  0001 C CNN
	1    1200 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  1550 950  1650
Wire Wire Line
	950  1550 1150 1550
Connection ~ 950  1550
Wire Wire Line
	1250 1550 1250 1900
$Comp
L GND #PWR02
U 1 1 58E050D4
P 950 1650
F 0 "#PWR02" H 950 1400 50  0001 C CNN
F 1 "GND" H 950 1500 50  0000 C CNN
F 2 "" H 950 1650 50  0001 C CNN
F 3 "" H 950 1650 50  0001 C CNN
	1    950  1650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 J4
U 1 1 58E05167
P 1250 2100
F 0 "J4" H 1250 2200 50  0000 C CNN
F 1 "CONN_OUT" V 1350 2100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1250 2100 50  0001 C CNN
F 3 "" H 1250 2100 50  0001 C CNN
	1    1250 2100
	0    1    1    0   
$EndComp
$Comp
L CONN_01X01 J2
U 1 1 58E05254
P 1700 1100
F 0 "J2" H 1700 1200 50  0000 C CNN
F 1 "CONN_RAW" V 1800 1100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1700 1100 50  0001 C CNN
F 3 "" H 1700 1100 50  0001 C CNN
	1    1700 1100
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J3
U 1 1 58E0536A
P 3100 1500
F 0 "J3" H 3100 1600 50  0000 C CNN
F 1 "CONN_PIN7" V 3200 1500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3100 1500 50  0001 C CNN
F 3 "" H 3100 1500 50  0001 C CNN
	1    3100 1500
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X01 J1
U 1 1 58E053F8
P 3100 2100
F 0 "J1" H 3100 2200 50  0000 C CNN
F 1 "CONN_GND" V 3200 2100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3100 2100 50  0001 C CNN
F 3 "" H 3100 2100 50  0001 C CNN
	1    3100 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 1700 1250 1700
Connection ~ 1250 1700
$EndSCHEMATC
