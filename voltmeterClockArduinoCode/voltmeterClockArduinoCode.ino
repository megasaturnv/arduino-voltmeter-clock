#include <Time.h>
#include <TimeLib.h>
#include <DS3232RTC.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

//Voltmeter Clock Version 0.4

//pwm pins at 490Hz are 3, 9, 10, and 11
//pwm pins at 980Hz are 5, 6
byte secondsVoltmeterScale[]    = {0, 10, 20, 30, 40,  50,  59};
byte secondsVoltmeterScalePWM[] = {9, 42, 68, 97, 136, 185, 255};
#define SECONDS_MIN_PWM 9
#define SECONDS_MAX_PWM 255
#define SECONDS_PWM_PIN 5

byte minutesVoltmeterScale[]    = {0,  10, 20, 30, 40,  50,  59};
byte minutesVoltmeterScalePWM[] = {21, 48, 70, 95, 132, 176, 250};
#define MINUTES_MIN_PWM 21
#define MINUTES_MAX_PWM 250
#define MINUTES_PWM_PIN 6

byte hoursVoltmeterScale[]    = {0, 3,  6,  9,  12, 15, 18,  21,  23};
byte hoursVoltmeterScalePWM[] = {3, 18, 37, 52, 69, 87, 111, 141, 183};
#define HOURS_MIN_PWM 3
#define HOURS_MAX_PWM 183
#define HOURS_PWM_PIN 3

byte dayVoltmeterScale[]    = {1,  5,  10, 15, 20,  25,  31};
byte dayVoltmeterScalePWM[] = {10, 38, 61, 87, 120, 164, 232};
#define DAY_MIN_PWM 10
#define DAY_MAX_PWM 232
#define DAY_PWM_PIN 9

byte monthVoltmeterScale[]    = {1, 2,  4,  6,  8,   10,  12};
byte monthVoltmeterScalePWM[] = {0, 23, 52, 82, 127, 188, 255};
#define MONTH_MIN_PWM 0
#define MONTH_MAX_PWM 255
#define MONTH_PWM_PIN 10

#define BUTTON1_PIN 8
#define LCD_AND_LIGHTS_POWER_PIN 7
#define PIR_PIN 2
#define POTENTIOMETER_PIN A6

byte xPosLCD = 0;
byte yPosLCD = 0;

float mapfloatReturnFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
}

bool digitalReadDebounce(int pin) {
  if (digitalRead(pin) == LOW) {
    delay(50);
    bool debounceRunning = true;
    while (debounceRunning) {
      if (digitalRead(pin) == HIGH) {
        debounceRunning = false;
      }
    }
    delay(50);
    return true;
  }
  return false;
}

void voltmeterAllSet(byte pwmValue) {
  analogWrite(SECONDS_PWM_PIN, pwmValue);
  analogWrite(MINUTES_PWM_PIN, pwmValue);
  analogWrite(HOURS_PWM_PIN, pwmValue);
  analogWrite(DAY_PWM_PIN, pwmValue);
  analogWrite(MONTH_PWM_PIN, pwmValue);
}

void voltmeterAllMax() {
  analogWrite(SECONDS_PWM_PIN, SECONDS_MAX_PWM);
  analogWrite(MINUTES_PWM_PIN, MINUTES_MAX_PWM);
  analogWrite(HOURS_PWM_PIN, HOURS_MAX_PWM);
  analogWrite(DAY_PWM_PIN, DAY_MAX_PWM);
  analogWrite(MONTH_PWM_PIN, MONTH_MAX_PWM);
}

void voltmeterAllMin() {
  analogWrite(SECONDS_PWM_PIN, SECONDS_MIN_PWM);
  analogWrite(MINUTES_PWM_PIN, MINUTES_MIN_PWM);
  analogWrite(HOURS_PWM_PIN, HOURS_MIN_PWM);
  analogWrite(DAY_PWM_PIN, DAY_MIN_PWM);
  analogWrite(MONTH_PWM_PIN, MONTH_MIN_PWM);
}

void voltmeterAllOff() {
  analogWrite(SECONDS_PWM_PIN, 0);
  //digitalWrite(SECONDS_PWM_PIN,LOW);
  analogWrite(MINUTES_PWM_PIN, 0);
  analogWrite(HOURS_PWM_PIN, 0);
  analogWrite(DAY_PWM_PIN, 0);
  analogWrite(MONTH_PWM_PIN, 0);
}

int selectTimeValueDisplayOnLcdAndVoltmeter(String valueName, int pin, int minPWM, int maxPWM, int value, int valueMin, int valueMax) {
  bool runningVar = true;
  lcd.clear();
  lcd.print("Set date & time");
  lcd.setCursor(0, 1);
  lcd.print(valueName + ": ");

  while (runningVar) {
    lcd.setCursor(12, 1);
    lcd.print("    ");
    lcd.setCursor(12, 1);
    lcd.print(map(analogRead(POTENTIOMETER_PIN), 0, 1023, valueMin, valueMax), DEC);

    byte mappedPwmVal = map(analogRead(POTENTIOMETER_PIN), 0, 1023, minPWM, maxPWM);
    analogWrite(pin, (mappedPwmVal)); //TODO: Replace with function to display value on voltmeter displays accurately
    if (digitalReadDebounce(BUTTON1_PIN)) {
      runningVar = false;
    }
    delay(25);
  }
  value = map(analogRead(POTENTIOMETER_PIN), 0, 1023, valueMin, valueMax);
  voltmeterAllOff();
  blinkLED();
  lcd.setCursor(0, 2);
  lcd.print("Value set:");
  lcd.setCursor(12, 2);
  lcd.print(value);
  lcd.setCursor(0, 3);
  lcd.print("Press button...");
  while (!digitalReadDebounce(BUTTON1_PIN));
  return value;
}

void setDateTime(unsigned int setYear, byte setMonth, byte setDay, byte setHour, byte setMin, byte setSec) {
  //arguments are selectTimeValueDisplayOnLcdAndVoltmeter(valueName, pin, minPWM, maxPWM, value, valueMin, valueMax)
  voltmeterAllOff();
  lcdCustomXYClear();
  setYear = selectTimeValueDisplayOnLcdAndVoltmeter("Year",   MONTH_PWM_PIN,   MONTH_MIN_PWM,   MONTH_MAX_PWM,   setYear,  2010, 2040);
  setMonth = selectTimeValueDisplayOnLcdAndVoltmeter("Month", MONTH_PWM_PIN,   MONTH_MIN_PWM,   MONTH_MAX_PWM,   setMonth, 1,    12);
  setDay = selectTimeValueDisplayOnLcdAndVoltmeter("Day",     DAY_PWM_PIN,     DAY_MIN_PWM,     DAY_MAX_PWM,     setDay,   1,    31);
  setHour = selectTimeValueDisplayOnLcdAndVoltmeter("Hour",   HOURS_PWM_PIN,   HOURS_MIN_PWM,   HOURS_MAX_PWM,   setHour,  0,    23);
  setMin = selectTimeValueDisplayOnLcdAndVoltmeter("Minute",  MINUTES_PWM_PIN, MINUTES_MIN_PWM, MINUTES_MAX_PWM, setMin,   0,    59);
  setSec = selectTimeValueDisplayOnLcdAndVoltmeter("Second",  SECONDS_PWM_PIN, SECONDS_MIN_PWM, SECONDS_MAX_PWM, setSec,   0,    59);
  lcdCustomXYClear();
  lcd.print("Y " + String(setYear));
  lcd.setCursor(10, 0);
  lcd.print("M " + String(setMonth));
  lcd.setCursor(0, 1);
  lcd.print("D " + String(setDay));
  lcd.setCursor(10, 1);
  lcd.print("h" + String(setHour));
  lcd.setCursor(0, 2);
  lcd.print("m" + String(setMin));
  lcd.setCursor(10, 2);
  lcd.print("s" + String(setSec));

  lcd.setCursor(0, 3);
  lcd.print("Press button to set");
  delay(500);

  bool runningVar = true;
  unsigned long targetMillis = 0;
  while (runningVar) {
    if (millis() > targetMillis) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      targetMillis = millis() + 1000;
    }
    if (digitalReadDebounce(BUTTON1_PIN)) {
      runningVar = false;
    }
  }
  digitalWrite(LED_BUILTIN, LOW);
  lcdCustomXYClear();
  setTime(setHour, setMin, setSec, setDay, setMonth, setYear);
  RTC.set(now());
  setSyncProvider(RTC.get);
}

void turnOnLCD() {
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, HIGH);
  delay(100);
  lcd.begin(20, 4);
  lcdCustomXYClear();
}

void turnOffLCD() {
  lcdCustomXYClear();
  delay(100);
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, LOW);
}

void lcdCustomXYClear() {
  xPosLCD = 0;
  yPosLCD = 0;
  lcd.clear();
}

void lcdSetCursor(byte x, byte y) {
  xPosLCD = x;
  yPosLCD = y;
  lcd.setCursor(x, y);
}

void lcdDigit(byte digit) {
  digit = constrain(digit, 0, 9);
  switch (digit) {
    case 0:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("# #");
      lcd.setCursor(xPosLCD, 2); lcd.print("# #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 1:
      lcd.setCursor(xPosLCD, 0); lcd.print("  #");
      lcd.setCursor(xPosLCD, 1); lcd.print("  #");
      lcd.setCursor(xPosLCD, 2); lcd.print("  #");
      lcd.setCursor(xPosLCD, 3); lcd.print("  #");
      break;
    case 2:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print(" _#");
      lcd.setCursor(xPosLCD, 2); lcd.print("#");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 3:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("__#");
      lcd.setCursor(xPosLCD, 2); lcd.print("  #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 4:
      lcd.setCursor(xPosLCD, 0); lcd.print("# #");
      lcd.setCursor(xPosLCD, 1); lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2); lcd.print("  #");
      lcd.setCursor(xPosLCD, 3); lcd.print("  #");
      break;
    case 5:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("#_");
      lcd.setCursor(xPosLCD, 2); lcd.print("  #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 6:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("#_");
      lcd.setCursor(xPosLCD, 2); lcd.print("# #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 7:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("  #");
      lcd.setCursor(xPosLCD, 2); lcd.print(" #");
      lcd.setCursor(xPosLCD, 3); lcd.print(" #");
      break;
    case 8:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2); lcd.print("# #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
    case 9:
      lcd.setCursor(xPosLCD, 0); lcd.print("###");
      lcd.setCursor(xPosLCD, 1); lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2); lcd.print("  #");
      lcd.setCursor(xPosLCD, 3); lcd.print("###");
      break;
  }
  lcdSetCursor(xPosLCD + 5, 0);
}

void lcdNumber(word num) {
  num = constrain(num, 0, 9999);
  lcdCustomXYClear();
  lcdDigit((num / 1000) % 10);
  lcdDigit((num / 100) % 10);
  lcdDigit((num / 10) % 10);
  lcdDigit(num % 10);
}

float getPositionOnScale(float scaleMin, float scaleMax, float valueOnScale) {
  //Return the position of the number on the scale (0.0-1.0)
  //This is scales valueOnScale from scaleMin-scaleMax to 0.0-1.0
  //The line: map(valueOnScale, scaleMin, scaleMax, 0, 1) could have been used but it returns an integer, not a float
  //I could have used mapfloatReturnFloat(valueOnScale, scaleMin, scaleMax, 0, 1) which is a function I created that has the same task as map(), but it takes and returns float values
  //However, this wasn't used here because the standard mapping equation can be simplified from:
  //  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
  //by replacing out_min with 0 and out_max with 1
  //which gets you:
  //  (x - in_min) * (1 - 0) / (in_max - in_min) + 0
  //which simplifies to:
  //  (valueOnScale - scaleMin) / (scaleMax - scaleMin)
  return (valueOnScale - scaleMin) / (scaleMax - scaleMin);
}

void displayMonth(float timeValue) {
  //Using pointers here to make the code more readable and similar between displayMonth, displayDay etc functions
  //Array of the scale which appears on the voltmeter display
  byte *voltmeterScale    = &monthVoltmeterScale[0];
  //Array of the corresponding PWM values needed for each scale marker on the voltmeter display
  byte *voltmeterScalePWM = &monthVoltmeterScalePWM[0];

  //Start at second position in voltmeterScale array and find the index of the first value in the voltmeterScale array which is larger than the monthValue argument
  //A for loop could have been used here, but this method is faster
  int i = 1;
  while (timeValue > voltmeterScale[i]) {
    i++;
  }

  //Get the position of monthValue between the larger and smaller corresponding values in the voltmeterScale array. The position will be between 0 and 1.
  //For example, if month value is 1,  its position is 0   between 1 and 2 in voltmeterScale.
  //For example, if month value is 2,  its position is 1   between 1 and 2 in voltmeterScale.
  //For example, if month value is 3,  its position is 0.5 between 2 and 4 in voltmeterScale.
  //For example, if month value is 4,  its position is 1   between 2 and 4 in voltmeterScale.
  //For example, if month value is 5,  its position is 0.5 between 4 and 6 in voltmeterScale.
  //...
  //For example, if month value is 12, its position is 1   between 10 and 12 in voltmeterScale.
  //old: float positionOnScale = 1 - ((voltmeterScale[i] - monthValue)/(voltmeterScale[i] - voltmeterScale[i-1]))
  float positionOnScale = getPositionOnScale(voltmeterScale[i - 1], voltmeterScale[i], timeValue);

  //Set PWMValue to a number between two values in the voltmeterScalePWM when scaled with positionOnScale
  //For example, if positionOnScale was 0,   PWMValue becomes voltmeterScalePWM[i - 1] (the lower pwm value in the array)
  //For example, if positionOnScale was 0.5, PWMValue becomes half way between voltmeterScalePWM[i - 1] and voltmeterScalePWM[i]
  //For example, if positionOnScale was 1,   PWMValue becomes voltmeterScalePWM[i] (the higher pwm value in the array)
  //In simplified terms the equation is:
  //PWMValue = ((1 - positionOnScale) * firstPointOnScale) + (positionOnScale * secondPointOnScale)
  int PWMValue = ((1.0 - positionOnScale) * float(voltmeterScalePWM[i - 1])) + (positionOnScale * float(voltmeterScalePWM[i]));
  analogWrite(MONTH_PWM_PIN, PWMValue);
}

void displayDay(float timeValue) {
  byte *voltmeterScale    = &dayVoltmeterScale[0];
  byte *voltmeterScalePWM = &dayVoltmeterScalePWM[0];
  int i = 1;
  while (timeValue > voltmeterScale[i]) {
    i++;
  }
  float positionOnScale = getPositionOnScale(voltmeterScale[i - 1], voltmeterScale[i], timeValue);
  int PWMValue = ((1.0 - positionOnScale) * float(voltmeterScalePWM[i - 1])) + (positionOnScale * float(voltmeterScalePWM[i]));
  analogWrite(DAY_PWM_PIN, PWMValue);
}

void displayHours(float timeValue) {
  byte *voltmeterScale    = &hoursVoltmeterScale[0];
  byte *voltmeterScalePWM = &hoursVoltmeterScalePWM[0];
  int i = 1;
  while (timeValue > voltmeterScale[i]) {
    i++;
  }
  float positionOnScale = getPositionOnScale(voltmeterScale[i - 1], voltmeterScale[i], timeValue);
  int PWMValue = ((1.0 - positionOnScale) * float(voltmeterScalePWM[i - 1])) + (positionOnScale * float(voltmeterScalePWM[i]));
  analogWrite(HOURS_PWM_PIN, PWMValue);
}

void displayMinutes(float timeValue) {
  byte *voltmeterScale    = &minutesVoltmeterScale[0];
  byte *voltmeterScalePWM = &minutesVoltmeterScalePWM[0];
  int i = 1;
  while (timeValue > voltmeterScale[i]) {
    i++;
  }
  float positionOnScale = getPositionOnScale(voltmeterScale[i - 1], voltmeterScale[i], timeValue);
  int PWMValue = ((1.0 - positionOnScale) * float(voltmeterScalePWM[i - 1])) + (positionOnScale * float(voltmeterScalePWM[i]));
  analogWrite(MINUTES_PWM_PIN, PWMValue);
}

void displaySeconds(float timeValue) {
  byte *voltmeterScale    = &secondsVoltmeterScale[0];
  byte *voltmeterScalePWM = &secondsVoltmeterScalePWM[0];
  int i = 1;
  while (timeValue > voltmeterScale[i]) {
    i++;
  }
  float positionOnScale = getPositionOnScale(voltmeterScale[i - 1], voltmeterScale[i], timeValue);
  int PWMValue = ((1.0 - positionOnScale) * float(voltmeterScalePWM[i - 1])) + (positionOnScale * float(voltmeterScalePWM[i]));
  analogWrite(SECONDS_PWM_PIN, PWMValue);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  //Serial.begin(9600); //For debugging
  pinMode(SECONDS_PWM_PIN,          OUTPUT);
  pinMode(MINUTES_PWM_PIN,          OUTPUT);
  pinMode(HOURS_PWM_PIN,            OUTPUT);
  pinMode(DAY_PWM_PIN,              OUTPUT);
  pinMode(MONTH_PWM_PIN,            OUTPUT);
  pinMode(LED_BUILTIN,              OUTPUT);
  pinMode(LCD_AND_LIGHTS_POWER_PIN, OUTPUT);
  pinMode(PIR_PIN,                  INPUT);
  pinMode(BUTTON1_PIN,              INPUT_PULLUP);
  pinMode(POTENTIOMETER_PIN,        INPUT);

  //setSyncProvider to the RTC clock. Sync interval is 5 mins by default
  setSyncProvider(RTC.get);
  //setSyncInterval(interval); // Set the number of seconds between re-syncs
  if (timeStatus() != timeSet) {
    turnOnLCD();
    lcd.setCursor(0, 0);
    lcd.print("Unable to sync");
    lcd.setCursor(0, 1);
    lcd.print("with the RTC :(");
    lcd.setCursor(0, 2);
    lcd.print(timeStatus());
    lcd.setCursor(0, 3);
    lcd.print(timeSet);
    while (true) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      delay(500);
    }
  }

  //Breifly show current date and time
  turnOnLCD();
  lcd.print(String(year()) + "-" + String(month()) + "-" + String(day()));
  lcd.setCursor(0, 1);
  lcd.print(String(hour()));
  lcd.setCursor(2, 1);
  lcd.print(":" + String(minute()));
  lcd.setCursor(5, 1);
  lcd.print(":" + String(second()));
  delay(4000);
  turnOffLCD();
  delay(1000);

  //Year is temporarily wrote to LCD only on startup
  turnOnLCD();
  lcdNumber(year());

  //testing assigning a veriable as a time_t type
  /*
    Serial.println(now());
    Serial.println(second());
    time_t test = now();
    Serial.println();
    Serial.println(test);
    Serial.println(second(test));
  */
  blinkLED();
}

void loop() {
  //time_t t = now();

  if (digitalRead(BUTTON1_PIN) == LOW) {
    //modify date and time
    if (digitalReadDebounce(BUTTON1_PIN)) {
      setDateTime(year(), month(), day(), hour(), minute(), second());
      delay(100);
      //t = now();
    }
  }

  //Now = secondsSince2000(year(t), month(t), day(t), hour(t), minute(t), second(t));

  //now(); // Returns the current time as seconds since Jan 1 1970 (Test if since 1970 etc)

  //year(t)   vs year()   vs
  //month(t)  vs month()  vs
  //day(t)    vs day()    vs
  //hour(t)   vs hour()   vs DateTime.Hour
  //minute(t) vs minute() vs DateTime.Minute
  //second(t) vs second() vs DateTime.Second

  //method of finding the amount of days in a month, if it is ever needed
  byte daysInMonth;
  if (month() == 4 or month() == 6 or month() == 9 or month() == 11) {
    //30 days in month
    daysInMonth = 30;
  } else if (month() == 2) {
	//Gregorian calendar rules:
    //Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100, but these centurial years are leap years if they are exactly divisible by 400
    if ((year() % 4) == 0) { //If the year is divisible by four
      if ((year() % 100) == 0) { //If the year is divisible by 100
        if ((year() % 400) == 0) { //If the year is divisible by 400
          //leap year
          daysInMonth = 29;
        } else {
          //not leap year
          daysInMonth = 28;
        }
      } else {
        //leap year
        daysInMonth = 29;
      }
    } else {
      //not leap year
      daysInMonth = 28;
    }
  } else {
    //month is no. 1,3,5,7,8,10 or 12 therefore 31 days in these month
    daysInMonth = 31;
  }

  //This was used, but didn't feel right on the clock and it gave weird numbers like saying it is month 12.5 (but the scale on the month voltmeter is 1-12)
  //float exactMonth  = month() + (day() / daysInMonth);
  //Same goes for days
  //float exactDay    = day() + (float(hour()) / 24);
  //Will re-add this feature in a later version once it has been tweaked
  float exactHour   = hour() + (float(minute()) / 60);
  float exactMinute = minute() + (float(second()) / 60);
  float exactSecond = second(); // TODO: Make seconds smoother

  displayMonth(month());
  displayDay(day());
  displayHours(hour());
  displayMinutes(minute());
  displaySeconds(second());
  delay(250);

  digitalWrite(LED_BUILTIN,digitalRead(PIR_PIN));
}
